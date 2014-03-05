/* 
 * File:   main.cpp
 * Author: eugene
 *
 * Created on March 4, 2014, 1:44 AM
 */

#include <iostream>

#include "wave_io.h"
#include "phase1_sig_proc.h"

#define PI 3.14159265 // Define a value of PI as a macro rather than access memory when used

using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
    // Create struct for header
    header wavHeader;
    // Create pointer for arrays, it is void so it can be either character or
    // short depending on the size of the sample
    void *sample;
    
    // Stores the maximum amplitude
    short amplitude;

    // Input file to use - opened in readHeader
    FILE *wavIn;
    // Output file to use - opened in writeHeader
    FILE *wavOut;
    
    // Function pointer to use for adding the signal
    void (*addSignal)(void*, unsigned short, unsigned short, unsigned int, unsigned int);
    
    // Function pointer to use for finding the max amplitude of a signal
    short (*maxChannelAmp)(void*, unsigned short);
    
    // <editor-fold desc="Check input and file setup" defaultstate="collapsed">
    // Command as called as:
    // 381-project <inputfilename> <outputfilename>
    // therefore argc should be 3
    if (argc != 3)
    {
        cerr << "Invalid arguments. Command should be of the format"
                << "381-project <input filename> <output filename>" << endl;
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
    // </editor-fold>
    
    // If cannot read in, return 1 as program has failed
    if (!readHeader(&wavHeader, wavIn))
    {
        return 1;
    }
    
    // <editor-fold desc="Setup pointers" defaultstate="collapsed">
    // Now that we have the number of channels, make the array for sample
    // If 8 bit, use the character sample, if 16 bit use the short sample
    if (wavHeader.bitsPerSample == 8)
    {
        sample = new char[wavHeader.numChannels];
        addSignal = &addSignal8Bit;
        maxChannelAmp = &maxChanAmp8Bit;
    }
    // If 16 bit, use shorts
    else if (wavHeader.bitsPerSample == 16)
    {
        sample = new short[wavHeader.numChannels];
        addSignal = &addSignal16Bit;
        maxChannelAmp = &maxChanAmp16Bit;
    }
    // If neither 8 nor 16, invalid sample size, exit with error
    else
    {
        cerr << "Invalid sample size." << endl;
        return 1;
    }
    // </editor-fold>
    
    // Setup header for the output file
    writeHeader(&wavHeader, wavOut);
    
    // The calculation for how many samples to take in is the size of the data (in bytes)
    // divided by the number of channels times the bytes per sample
    int numSamples = wavHeader.subchunk2Size/ (wavHeader.numChannels * (wavHeader.bitsPerSample / 8));
    
    // Iterate through the number of samples
   for (int i = 0; i < numSamples; i++)
    {
        // Get the next sample (includes all the channels for this sample)
        nextSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn);
        
        // Get the maximum amplitude of the sound
        short tempAmp = (*maxChannelAmp)(sample, wavHeader.numChannels);
        if (tempAmp > amplitude)
        {
            amplitude = tempAmp;
        }
   }
    
    // Reset the file back to an offset of 44 (the start of the data)
    fseek(wavIn, 44, SEEK_SET);
    
    // Add the sine wave
    // Iterate through the number of samples
   for (unsigned int i = 0; i < numSamples; i++)
    {
        // Get the next sample (includes all the channels for this sample)
        nextSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn);
        
        // Add signal
        (*addSignal)(sample, wavHeader.numChannels, amplitude, i, wavHeader.sampleRate);

        // Save the samples to the output
        saveSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavOut);
    }
    
    return 0;
}