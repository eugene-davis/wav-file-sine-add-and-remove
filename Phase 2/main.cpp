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

#include "wave_io.h"
#include "phase2_sig_proc.h"

// Filters
#include "bandStopFine.h" // High quality (but large) band stop filter
#include "lowPassFine.h"  // High quality (but large) low pass filter

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
	short *sampleBuffer;
    short *sample;
	short *coeffecients;

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
    if (argc != 3 && argc != 5)
    {
        cerr << "Invalid arguments. Command should be of the format"
             << "381-project <input filename> <output filename> [fine/coarse] [lowpass/band]" << endl
			<< "Defaults to coarse lowpass filter, for other filters use both options." << endl;
        return 1;
    }

	if (argc == 3)
	{
		coeffecients = bLowPassFine;
		length = &bLowPassFineLength;
	}

	// Handle other options
    
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

	// Make sample buffer (number of channels times the size of the coefficient array
	sampleBuffer = new short[wavHeader.numChannels * *length];

	// Initialize sample buffer with zeros
	for (int i = 0; i < *length * wavHeader.numChannels; i++)
	{
		sampleBuffer[i] = 0;
	}
       
    // Filter
    // Iterate through the number of samples
   for (unsigned int i = 0; i < numSamples; i++)
    {
        // Get the next sample (includes all the channels for this sample)
        if (!nextSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn))
        {
            return 1;
        }
        
        // Do filtering
		filterSignal(sample, wavHeader.numChannels, sampleBuffer, coeffecients, *length);

        // Save the samples to the output file
        if (!saveSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavOut))
        {
            return 1;
        }
    }
    
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
