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
    int chunkSize;
    char format[4];
    char subchunk1ID[4];
    int subchunk1Size;
    short audioFormat;
    short numChannels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    // Heads up the data sub chunk
    char subchunk2ID[4];
    int subchunk2Size;
};

/**
 * Reads in the header of the wav file
 * @param fileName Name of the file to be read in
 * @param wavHeader Header structure to return
 * @return 
 */
bool readHeader(char* fileName, header *wavHeader);

/*
 * 
 */
int
main(int argc, char** argv)
{
    // Create struct for header
    header wavHeader;
    
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
    if (!readHeader(argv[1], &wavHeader))
    {
        return 1;
    }
    return 0;
}

/**
 * Reads in the header of the wav file
 * @param fileName Name of the file to be read in
 * @param wavHeader Header structure to return
 * @return 
 */
bool readHeader(char* fileName, header *wavHeader) {
    FILE *wavIn = fopen(fileName, "rb");
    
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