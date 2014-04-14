/* 
 * This function drives the functions to read in a wave file, add a sinewave to
 * it and then write it all out to a drive.
 * 
 * Although it requires reading everything from the file twice, this program
 * simulates a real time signal by not storing samples in memory other than
 * the currently being processed sample.
 * 
 * void pointers were used for the data type of the array storing samples so as
 * to reduce the amount of conditionals required to handle the difference between
 * 8 and 16 bit samples. This allows this top level code to be more abstract and
 * maintainable/extensible for the different sample sizes.
 * 
 * function pointers were used for the 8 and 16 byte specific functions, again
 * to allow this top level code to be more abstract, and thus make it more easily
 * maintainable/extensible.
 * 
 * Run with:
 * 381-project <inputfilename> <outputfilename>
 * 
 * File:   main.cpp
 * Author: Eugene Davis
 * Class: CPE 381
 * Project Phase 1
 *
 * Created on March 4, 2014, 1:44 AM
 */

#include <iostream>
#include <fstream> // Used to rapidly create summary file
#include <iomanip> // Allows for setting precision on output
#include <string.h> // memcopy
#include <complex>
#include <vector>

#include "wave_io.h"
#include "bonus_fourier.h"

// Pick a power of 2 for the FFT length (since the FFT has a power of 2 limitation)
#define FFT_LEN 2048

using namespace std;

/*
 * Main function drives the functions required to read/write a WAV file, and
 * to add a sine wave signal to the WAV file's audio.
 */
int main(int argc, char** argv)
{

    // Windows (non-POSIX) friendly timing from http://www.cplusplus.com/reference/ctime/clock/
	clock_t t;
	t = clock();
    
    // Create new struct for header
    header wavHeader;
   /*
    * Create pointers for arrays, only 16-bit supported it is a short
    */
	vector< complex<double> > sampleBuffer;
	double *coeffecients;

	/*
	* Create a pointer to the co-efficient array size
	*/
	int *length;

    // Input file handle to use - opened in readHeader
    FILE *wavIn;
    // Output file handle to use - opened in writeHeader
    FILE *wavOut;
    
    // Command as called as:
    // 381-project <inputfilename> <outputfilename> [fine/coarse] [lowpass/band]
    // it defaults to coarse lowpass filter, for other filters use both options
	// must be specified
    if (argc != 3 && (argc != 4 && *argv[3] != 'h'))
    {
        cerr << "Invalid arguments. Command should be of the format"
             << "381-project <input filename> <output filename> [h]" << endl
			<< "Defaults to coarse lowpass filter, for high quality (bandpass, fine grain) filter add h at end." << endl;
        return 1;
    }


    
    // Open input file
    wavIn = fopen(argv[1], "rb");
    // Check to see if the file actually opened
    if (wavIn == NULL) 
    {
        cerr << "File cannot be opened, please enter a valid file name." << endl;
        return 1;
    }
    
    // Open output file
    wavOut = fopen(argv[2], "wb");
    // Check to see if the file actually opened
    if (wavOut == NULL) 
    {
        cerr << "File cannot be opened, please enter a valid file name." << endl;
        return false;
    }
    
    // If cannot read in header, return 1 as program has failed
    if (!readHeader(&wavHeader, wavIn))
    {
        return 1;
    }
    
    /*
     *  Check sample size
     */
	if (!wavHeader.bitsPerSample == 16)
    {
        cerr << "Invalid sample size." << endl;
        return 1;
    }

	// Handle options
	// First check sample rate
	if (!(wavHeader.sampleRate == 44100 || wavHeader.sampleRate == 22050))
	{
		cerr << "Invalid sample rate, must be 441000 or 22050" << endl;
		return 1; 
	}	
    
    // Setup header in the output file
    if (!writeHeader(&wavHeader, wavOut))
    {
        return 1;
    }
   /*
    * The calculation for how many samples to take in is the size of the data (in bytes)
    * divided by the number of channels times the bytes per sample
    */
    unsigned int numSamples = wavHeader.subchunk2Size/ (wavHeader.numChannels * (wavHeader.bitsPerSample / 8));

	

    // Get samples for FFT
    // Iterate through the samples until FFT_LEN hit
   for (unsigned int i = 0; i < FFT_LEN; i++)
    {
		// Variable to get all channels in (to be split up)
		short *currentSample;
		currentSample = new short[wavHeader.numChannels];		

        // Get the next sample (includes all the channels for this sample)
        if (!nextSample(&currentSample[0], wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn))
        {
            return 1;
        }

		// Get first channel
		sampleBuffer.push_back(currentSample[0]);		
    }

	// Perform FFT
	fft(1, sampleBuffer);
    
    // Now that actual processing is complete but before writing the summary file, stop timer
    t = clock() - t;
    
    // Write to summary text file
    ofstream summaryFile;
    summaryFile.open("Summary.txt");
    
    summaryFile << "Input File Name: " << argv[1] << endl;
    summaryFile << "Output File Name: " << argv[2] << endl;
    summaryFile << "Sampling Frequency (samp/s): " << wavHeader.sampleRate << endl;
    summaryFile << "Recording Length (s): " 
            /*(Dimensional Analysis): (bytes / (bytes/samp)) / samp/s = samp * s/samp = s*/
            << (wavHeader.subchunk2Size / (wavHeader.numChannels * (wavHeader.bitsPerSample/8))) / wavHeader.sampleRate
            << endl;
    summaryFile << "Processing Time (s): " << setprecision(8) <<  ((float)t)/CLOCKS_PER_SEC << endl;
    
    return 0;
}
