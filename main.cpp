/* 
 * File:   main.cpp
 * Author: eugene
 *
 * Created on March 4, 2014, 1:44 AM
 */

#include <iostream>
#include <stdio.h>

using namespace std;

// Names are as they are found at https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
struct header
{
    char chunkID[4];
    unsigned int chunkSize;
    char format[4];
    char subchunk1ID[4];
    unsigned int subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned int sampleRate;
    unsigned int byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    // Heads up the data sub chunk
    char subchunk2ID[4];
    unsigned int subchunk2Size;
};

/**
 * Reads in the header of the wav file
 * @param fileName Name of the file to be read in
 * @param wavHeader Header structure to return
 * @param wavIn File handle
 * @return 
 */
bool readHeader(header *wavHeader, FILE *wavIn);

bool writeHeader(header *wavHeader, FILE *wavOut);

bool nextSample(void* sample, unsigned int size, FILE *wavIn);

bool saveSample(void* sample, unsigned int size, FILE *wavOut);

short maxChanAmp8Bit(void* sample, unsigned short numChannels);

short maxChanAmp16Bit(void* sample, unsigned short numChannels);

void addSignal8Bit(void* sample);

void addSignal16Bit(void* sample);

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
    void (*addSignal)(void*);
    
    // Function pointer to use for finding the max amplitude of a signal
    short (*maxChannelAmp)(void*, unsigned short);
    
    // <editor-fold desc="Check input and file setup" defaultstate="collapsed">
    // Command as called as:
    // 381-project <inputfilename> <outputfilename>
    // therefore argc should be 3
    if (argc != 3)
    {
        cout << "Invalid arguments. Command should be of the format"
                << "381-project <input filename> <output filename>" << endl;
        return 1;
    }
    
    // Open input file
    wavIn = fopen(argv[1], "rb");
    // Check to see if the file actually opened
    if (wavIn == NULL) 
    {
        cout << "File cannot be opened, please enter a valid file name." << endl;
        return 1;
    }
    
    // Open output file
    wavOut = fopen(argv[2], "wb");
    // Check to see if the file actually opened
    if (wavOut == NULL) 
    {
        cout << "File cannot be opened, please enter a valid file name." << endl;
        return false;
    }
    // </editor-fold>
    
    // If cannot read in, return 1 as program has failed
    if (!readHeader(&wavHeader, wavIn))
    {
        return 1;
    }
    
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
    
    // Setup header for the output file
    writeHeader(&wavHeader, wavOut);
    
    // The calculation for how many samples to take in is the size of the data (in bytes)
    // divided by the number of channels, divided by the bits per sample divided by 8 
    // to get bytes per sample. This gives the total number of samples
    // divided by the number of channels, divided by the bits per sample divided by 8 
    // to get bytes per sample. This gives the total number of samples
    int numSamples = wavHeader.subchunk2Size/(wavHeader.numChannels/(wavHeader.bitsPerSample/8));
    
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
   for (int i = 0; i < numSamples; i++)
    {
        // Get the next sample (includes all the channels for this sample)
        nextSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavIn);
        
        // Add signal
        (*addSignal)(sample);

        // Save the samples to the output
        saveSample(sample, wavHeader.numChannels * (wavHeader.bitsPerSample/8), wavOut);
    }
    
    return 0;
}

/**
 * Reads in the header of the wav file
 * @param fileName Name of the file to be read in
 * @param wavHeader Header structure to return
 * @return 
 */
bool readHeader(header *wavHeader, FILE *wavIn) 
{   
    // Copy the header into the header struct
    fread(wavHeader, sizeof(*wavHeader), 1, wavIn);
    
    // Check that the structure now has data
    if (wavHeader == NULL)
    {
        cerr << "File appears to be empty, please use a valid file." << endl;
        return false;
    }
    
    return true;
}

bool writeHeader(header *wavHeader, FILE *wavOut)
{    
    // Copy the header into the header struct
    fwrite(wavHeader, sizeof(*wavHeader), 1, wavOut);
 
    return true;
}

bool nextSample(void* sample, unsigned int size, FILE *wavIn)
{
    fread(sample, size, 1, wavIn);
}

bool saveSample(void* sample, unsigned int size, FILE *wavOut)
{
    fwrite(sample, size, 1, wavOut);
}

short maxChanAmp8Bit(void* sample, unsigned short numChannels)
{
    // Cast the sample input into a character array (8 bit not 16)
    char* cSamp = static_cast<char*>(sample);
    // Temp variable to figure out which channel has the maximum amplitude
    unsigned short tempAmp = 0;
    for (unsigned short i = 0; i < numChannels; i++)
    {
        if (tempAmp < cSamp[i])
        {
            tempAmp = cSamp[i];
        }
    }
    return tempAmp;
}

short maxChanAmp16Bit(void* sample, unsigned short numChannels)
{
   // Cast the sample input into a unsigned short array (16 bit not 8)
    unsigned short* sSamp = static_cast<unsigned short*>(sample);
    // Temp variable to figure out which channel has the maximum amplitude
    unsigned short tempAmp = 0;
    for (unsigned short i = 0; i < numChannels; i++)
    {
        if (tempAmp < sSamp[i])
        {
            tempAmp = sSamp[i];
        }
    }
    return tempAmp;
}

void addSignal8Bit(void* sample)
{
    
}

void addSignal16Bit(void* sample)
{
    
}