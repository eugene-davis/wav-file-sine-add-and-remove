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
bool readHeader(char* fileName, header *wavHeader, FILE *wavIn);

bool writeHeader(char* fileName, header *wavHeader, FILE *wavOut);

bool nextSample(unsigned short* sample, unsigned short numChannels, FILE *wavIn);

bool saveSample(unsigned short* sample, unsigned short numChannels, FILE *wavOut);

/*
 * 
 */
int main(int argc, char** argv)
{
    // Create struct for header
    header wavHeader;
    // Create the short array for the samples
    unsigned short *sample;
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
    // If cannot read in, return 1 as program has failed
    if (!readHeader(argv[1], &wavHeader, wavIn))
    {
        return 1;
    }
    
    // Now that we have the number of channels, make the array for sample
    sample = new unsigned short[wavHeader.numChannels];
    
    // Setup header for the output file
    writeHeader(argv[1], &wavHeader, wavOut);
    
    // Get the next sample (includes all the channels for this sample)
    nextSample(sample, wavHeader.numChannels, wavIn);
    
    // Add sinewave to the samples
    
    
    // Save the samples to the output
    saveSample(sample, wavHeader.numChannels, wavOut);
    
    return 0;
}

/**
 * Reads in the header of the wav file
 * @param fileName Name of the file to be read in
 * @param wavHeader Header structure to return
 * @return 
 */
bool readHeader(char* fileName, header *wavHeader, FILE *wavIn) 
{  
    wavIn = fopen(fileName, "rb");
    // Check to see if the file actually opened
    if (wavIn == NULL) 
    {
        cout << "File cannot be opened, please enter a valid file name." << endl;
        return false;
    }
    
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

bool writeHeader(char* fileName, header *wavHeader, FILE *wavOut)
{
    
}

bool nextSample(unsigned short* sample, unsigned short numChannels, FILE *wavIn)
{
    
}

bool saveSample(unsigned short* sample, unsigned short numChannels, FILE *wavOut)
{
    
}