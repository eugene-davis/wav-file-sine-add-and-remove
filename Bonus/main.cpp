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
#include <algorithm> // Used for nth_element
#include <complex>
#include <vector>

#include "wave_io.h"
#include "bonus_fourier.h"

// Pick a power of 2 for the FFT length (since the FFT has a power of 2 limitation)
#define FFT_LEN 4096 // 2^12
//#define FFT_LEN 8192 // 2^13

using namespace std;

/*
 * Main function drives the functions required to read/write a WAV file, and
 * to add a sine wave signal to the WAV file's audio.
 */
int main(int argc, char** argv)
{  
    // Create new struct for header
    header wavHeader;

    // Input file handle to use - opened in readHeader
    FILE *wavIn;
    // Output file handle to use - opened in writeHeader
    FILE *wavOut;
    
    // Command as called as:
    // 381-project <inputfilename> <outputfilename> [fine/coarse] [lowpass/band]
    // it defaults to coarse lowpass filter, for other filters use both options
	// must be specified
    if (argc != 2)
    {
        cerr << "Invalid arguments. Command should be of the format"
             << "381-project <input filename>" << endl;
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

    // Write to summary text file (opening parts)
	ofstream summaryFile;
	summaryFile.open("Summary.txt");
	
	summaryFile << "Input File Name: " << argv[1] << endl;

	// Windows (non-POSIX) friendly timing from http://www.cplusplus.com/reference/ctime/clock/
	clock_t t;
	t = clock();


	// Generate an array of proper size (FFT_LEN) to apply a Welch window
	double* window;
	window = new double[FFT_LEN];
	// To be certain, set the first value to zero rather than using the calculation
	window[0] = 0;
	
	// Use Welch window's equation ( https://en.wikipedia.org/wiki/Window_function#Welch_window )
	for (int i = 1; i < FFT_LEN - 1; i++)
	{
		// Much casting required to force this number into a double, otherwise it ends up always 1
		window[i] = 1.0 - pow(((double) i - ( ((double) FFT_LEN - 1.0)/2.0 )) / (((double) FFT_LEN + 1.0)/2.0), 2);
	}

	// To be certain, set the last value to 0 manually rather than with the calculation
	window[FFT_LEN - 1 ] = 0;

	/*
    * The calculation for how many samples to take in is the size of the data (in bytes)
    * divided by the number of channels times the bytes per sample
    */
    unsigned int numSamples = wavHeader.subchunk2Size / (2 * wavHeader.numChannels * (wavHeader.bitsPerSample / 8));
	
	// Variable to get all channels in (to be split up)
	short *currentSample;
	currentSample = new short[wavHeader.numChannels];	

	// Samples by channel to process
	vector< complex<double> > *sampleBuffer;
	sampleBuffer = new vector< complex<double> >[wavHeader.numChannels];

	// FFT Buffers
	vector<double> *maxIndices;
	maxIndices = new vector<double>[wavHeader.numChannels];


    // Get samples for FFT
    // Iterate through the samples until the entire thing has been sampled (padded to be divisible by the FFT_LEN)
   for (unsigned int windowNum = 0; windowNum < numSamples; windowNum += FFT_LEN/2)
    {
		for (int chan = 0; chan < wavHeader.numChannels; chan++)
		{
			sampleBuffer[chan].clear();
		}
		// Iterate through the size of the window, getting samples or if out, setting them to zero
		for (unsigned int sampNum = 0; sampNum < FFT_LEN; sampNum++)
		{	
			// Get the next sample (includes all the channels for this sample)
		    if (!nextSample(&currentSample[0], wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn))
		    {
				// If the last sample has been hit, will have to pad with zeros to get a power of 2 - this will dramatically add to spectral leakage,
				// but only for last sample and allows a simple alogrithm can be used
				if (feof(wavIn))
				{
		        	for (unsigned short chan = 0; chan < wavHeader.numChannels; chan++)
					{
						currentSample[chan] = 0;
					}
				}
				// Otherwise an error
				else
				{
					return 1;
				}
		    }

			for (int chan = 0; chan < wavHeader.numChannels; chan++)
			{
			// Save the channel, multiplying it by the current value for the window
				double chanSample = currentSample[chan] * window[sampNum];
				sampleBuffer[chan].push_back(chanSample);
			}	
		}	
		
		for (int chan = 0; chan < wavHeader.numChannels; chan++)
		{

			// Perform FFT for each time window
			fft(1, sampleBuffer[chan]);

			// FFT Variables
			double maxSpec;
			double temp;
			int maxIndex;

			// Analyse result of FFT
			maxSpec = (sampleBuffer[chan].at(0).real())*(sampleBuffer[chan].at(0).real()) + (sampleBuffer[chan].at(0).imag())*(sampleBuffer[chan].at(0).imag());
			temp = 0;
			maxIndex = 0;

			for (int i = 1; i < FFT_LEN; i++) 
			{
				temp = (sampleBuffer[chan].at(i).real())*(sampleBuffer[chan].at(i).real()) + (sampleBuffer[chan].at(i).imag())*(sampleBuffer[chan].at(i).imag());
				// Check if there is a new maximum value
				if (temp > maxSpec) 
				{
					maxSpec = temp;
					maxIndex = i;
				}
			}
			// Add to the buffer
			maxIndices[chan].push_back(maxIndex);
		}
    }

	// Processing to discover dominant frequency for each channel
	for (int chan = 0; chan < wavHeader.numChannels; chan++)
	{
		int i = 0;
		double avgMax = 0;
		// Calculate average
		for ( ; i < maxIndices[chan].size(); i++)
		{
			avgMax += maxIndices[chan].at(i);
		}
		avgMax = avgMax / i;

		// Calculate median - quick way (https://stackoverflow.com/questions/12243902/median-selection-algorithm)
		size_t middle = maxIndices[chan].size()/2;
		nth_element(maxIndices[chan].begin(), maxIndices[chan].begin() + middle, maxIndices[chan].end());

		// Output each channel's info to the summary text file
		summaryFile << "Channel " << chan << " average dominant frequency: " << avgMax * wavHeader.sampleRate / FFT_LEN << endl;
		summaryFile << "Channel " << chan << " median dominant frequency: " << maxIndices[chan][middle] * wavHeader.sampleRate / FFT_LEN << endl;
	}

   
    // Now that actual processing is complete but before writing the summary file, stop timer
    t = clock() - t;

	// Output remaining information
    summaryFile << "Sampling Frequency (samp/s): " << wavHeader.sampleRate << endl;
    summaryFile << "Recording Length (s): " 
            /*(Dimensional Analysis): (bytes / (bytes/samp)) / samp/s = samp * s/samp = s*/
            << (wavHeader.subchunk2Size / (wavHeader.numChannels * (wavHeader.bitsPerSample/8))) / wavHeader.sampleRate
            << endl;
    summaryFile << "Processing Time (s): " << setprecision(8) <<  ((float)t)/CLOCKS_PER_SEC << endl;
    
    return 0;
}
