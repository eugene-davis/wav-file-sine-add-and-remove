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

bool nextSample(short* sample, unsigned short numChannels, FILE *wavIn, unsigned short sampleSize);

bool saveSample(short* sample, unsigned short numChannels, FILE *wavOut);

/*
 * 
 */
int main(int argc, char** argv)
{
    // Create struct for header
    header wavHeader;
    // Create the short array for the samples
    short *sample;
    // Input file to use - opened in readHeader
    FILE *wavIn;
    // Output file to use - opened in writeHeader
    FILE *wavOut;
    
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
    
    // If cannot read in, return 1 as program has failed
    if (!readHeader(&wavHeader, wavIn))
    {
        return 1;
    }
    
    // Now that we have the number of channels, make the array for sample
    sample = new short[wavHeader.numChannels];
    
    // Setup header for the output file
    writeHeader(&wavHeader, wavOut);
    
    // Iterate through the number of samples
    // The calculation for how many to take in is the size of the data (in bytes)
    // divided by the number of channels, divided by the bits per sample divided by 8 
    // to get bytes per sample. This gives the total number of samples
    for (int i = 0; i < wavHeader.subchunk2Size/wavHeader.numChannels/(wavHeader.bitsPerSample/8); i++)
    {
        // Get the next sample (includes all the channels for this sample)
        nextSample(sample, wavHeader.numChannels, wavIn, wavHeader.bitsPerSample/8);

        // Add sinewave to the samples

        // Save the samples to the output
        saveSample(sample, wavHeader.numChannels, wavOut);
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
        cout << "File appears to be empty, please use a valid file." << endl;
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

bool nextSample(short* sample, unsigned short numChannels, FILE *wavIn, unsigned short sampleSize)
{
    // Supports an arbitrary number of channels, with each channel pulling in
    // the sample size of bits and storing them in the next portion of the 
    // sample array. These will either be 8 or 16 bits  
    for (short i = 0; i < numChannels; i++)
    {
        fread(sample + i, sampleSize, 1, wavIn);
    }
}

bool saveSample(short* sample, unsigned short numChannels, FILE *wavOut)
{
    // TODO - Support 8 bit samples
    fwrite(sample, sizeof(*sample) * numChannels, 1, wavOut);
}