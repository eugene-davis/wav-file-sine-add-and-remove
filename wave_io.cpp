#include "wave_io.h"

#include <iostream>

using namespace std;

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
