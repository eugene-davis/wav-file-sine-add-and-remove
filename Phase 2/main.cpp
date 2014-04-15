/* 
 * This program reads in a wav file, and applies a filter to it (either a low pass filter
 * or a band stop, depending on user selection, then writes out the filtered wav file.
 * 
 * 
 * Run with:
 * 381-project <inputfilename> <outputfilename> [h]
 * The h flag uses a high quality band stop rather than a low quality low pass filter
 * 
 * File:   main.cpp
 * Author: Eugene Davis
 * Class: CPE 381
 * Project Phase 2
 */

#include <iostream>
#include <fstream> // Used to rapidly create summary file
#include <iomanip> // Allows for setting precision on output
#include <string.h> // memcopy

#include "wave_io.h"
#include "phase2_sig_proc.h"

// Filters 44800
// High Quality
#include "Filters/bandStopFine.h" // High quality (but large) band stop filter

// Low Quality
#include "Filters/lowPassCoarse.h"  // Low quality (but small) low pass filter

// Filters 22000
// High Quality
#include "Filters/bandStopFine22k.h" // High quality (but large) band stop filter

// Low Quality
#include "Filters/lowPassCoarse22k.h"  // Low quality (but small) low pass filter

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
	short **sampleBuffer;
	short *outputBuffer;
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
    // 381-project <inputfilename> <outputfilename> [h]
    // Defaults to a low pass filter, with h flag, uses a high quality band stop
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

	// Variable to store description of filter applied
	string filterType;

	// Default input (three arguments)
	if (argc == 3)
	{
		filterType = "Low Pass";
		
		if (wavHeader.sampleRate == 44100)
		{
			coeffecients = bLowPassCoarse;
			length = &bLowPassCoarseLength;
		}
		else
		{
			coeffecients = bLowPassCoarse22k;
			length = &bLowPassCoarseLength22k;
		}
	}
	// High quality (good band stop) filter
	else if (*argv[3] == 'h')
	{
		filterType = "Band Stop";

		if (wavHeader.sampleRate == 44100)
		{
			coeffecients = bBandStopFine;
			length = &bBandStopFineLength;
		}
		else
		{
			coeffecients = bBandStopFine22k;
			length = &bBandStopFineLength22k;
		}
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



	// Setup input buffers for each channel in the WAV in a pointer array
	sampleBuffer = new short*[wavHeader.numChannels];
	// Zero out sample buffer's contents
	for (int i = 0; i < wavHeader.numChannels; i++)
	{
		sampleBuffer[i] = new short[*length];
		for (int j = 0; j < *length; j++)
		{
			sampleBuffer[i][j] = 0;
		}
	}

    // Filter
    // Iterate through the number of samples
   for (unsigned int i = 0; i < numSamples; i++)
    {
		// Variable to get all channels in (to be split up) then recombine them back into for writing
		short *currentSample;
		currentSample = new short[wavHeader.numChannels];		

        // Get the next sample (includes all the channels for this sample)
        if (!nextSample(&currentSample[0], wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn))
        {
            return 1;
        }

        // Split channels and do filtering
		for (int j = 0; j < wavHeader.numChannels; j++)
		{
			// Split up the channels into separate arrays
			sampleBuffer[j][0] = currentSample[j];
			filterSample(&currentSample[j], sampleBuffer[j], coeffecients, *length);
		}

        // Save the result to the output file
        if (!saveSample(currentSample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavOut))
		//if (!saveSample(&sampleBuffer[0], wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavOut))
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
	summaryFile << "Filter type: " << filterType << endl;
    summaryFile << "Sampling Frequency (samp/s): " << wavHeader.sampleRate << endl;
    summaryFile << "Recording Length (s): " 
            /*(Dimensional Analysis): (bytes / (bytes/samp)) / samp/s = samp * s/samp = s*/
            << (wavHeader.subchunk2Size / (wavHeader.numChannels * (wavHeader.bitsPerSample/8))) / wavHeader.sampleRate
            << endl;
    summaryFile << "Processing Time (s): " << setprecision(8) <<  ((float)t)/CLOCKS_PER_SEC << endl;
    
    return 0;
}
