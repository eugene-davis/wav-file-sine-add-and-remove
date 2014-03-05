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
 * File:   main.cpp
 * Author: Eugene Davis
 * Class: CPE 381
 * Project Phase 1
 *
 * Created on March 4, 2014, 1:44 AM
 */

#include <iostream>

#include "wave_io.h"
#include "phase1_sig_proc.h"

using namespace std;

/*
 * Main function drives the functions required to read/write a WAV file, and
 * to add a sine wave signal to the WAV file's audio.
 */
int main(int argc, char** argv)
{
    // Create new struct for header
    header wavHeader;
   /*
    * Create pointer for arrays, it is void so it can be either character or
    * short depending on the size of the samples
    */
    void *sample;
    
    // Stores the maximum amplitude
    short amplitude;

    // Input file handle to use - opened in readHeader
    FILE *wavIn;
    // Output file handle to use - opened in writeHeader
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
    
    // If cannot read in header, return 1 as program has failed
    if (!readHeader(&wavHeader, wavIn))
    {
        return 1;
    }
    
    // <editor-fold desc="Setup pointers" defaultstate="collapsed">
    /*
     *  Now that we have the number of channels, make the array for samples
     * and setup function pointers
     */
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
    
    // Setup header in the output file
    if (!writeHeader(&wavHeader, wavOut))
    {
        return 1;
    }
   /*
    * The calculation for how many samples to take in is the size of the data (in bytes)
    * divided by the number of channels times the bytes per sample
    */
    int numSamples = wavHeader.subchunk2Size/ (wavHeader.numChannels * (wavHeader.bitsPerSample / 8));
    
    // Iterate through the samples to find the maximum amplitude
   for (int i = 0; i < numSamples; i++)
    {
        // Get the next sample (includes all the channels for this sample)
        if (!nextSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn))
        {
            return 1;
        }
        
        // Get the maximum amplitude of this sample
        short tempAmp = (*maxChannelAmp)(sample, wavHeader.numChannels);
        // Check if the maximum amplitude of this sample was the new biggest
        if (tempAmp > amplitude)
        {
            amplitude = tempAmp;
        }
   }
    
   /* 
    * Reset the file back to an offset of 44 (the start of the data)
    * This is done rather than storing the samples in order to treat it more
    * like real time
    */
    fseek(wavIn, 44, SEEK_SET);
    
    // Add the sine wave
    // Iterate through the number of samples
   for (unsigned int i = 0; i < numSamples; i++)
    {
        // Get the next sample (includes all the channels for this sample)
        if (!nextSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn))
        {
            return 1;
        }
        
        // Add signal - i.e. the sinewave
        (*addSignal)(sample, wavHeader.numChannels, amplitude, i, wavHeader.sampleRate);

        // Save the samples to the output file
        if (!saveSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavOut))
        {
            return 1;
        }
    }
    
    return 0;
}