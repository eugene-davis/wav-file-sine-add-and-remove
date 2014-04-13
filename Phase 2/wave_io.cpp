/**
 * Author: Eugene Davis
 * Class: CPE 381
 * 
 * Provides reading and writing from a WAV file for both phases of the CPE 381
 * project.
 */

#include "wave_io.h"

#include <iostream>

using namespace std;

/**
* Reads in the header from a WAV file and returns by reference a structure
* containing the data from the header.
* Returns a boolean to indicate whether it was successful or not.
* 
* @param wavHeader Structure for WAV headers
* @param wavIn     File handle for input file
* @return bool to indicate success or failure
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


/**
* writeHeader writes out a header from a header struct into a WAV file.
* Returns bool to indicate success.
* @param wavHeader Structure for WAV headers
* @param wavOut    File handle for output file
* @return bool to indicate if it was successful
*/
bool writeHeader(header *wavHeader, FILE *wavOut)
{    
    // Copy the header into the header struct
    fwrite(wavHeader, sizeof(*wavHeader), 1, wavOut);
 
    // Check if there were errors
    if (ferror(wavOut))
    {
        cerr << "Errors have occurred in writing to the output file." << endl;
        return false;
    }
    return true;
}

/**
 * Retrieves the next sample in the file. Requires that the file currently
 * be set valid sample (they should start at offset 44)
 * @param sample Array to store the sample in (either short or char), uses
 *               a void pointer to abstract away the difference between
 *               8 and 16 bit samples from the top level view
 * @param size   The total size of sample (all elements in the array) in bytes
 * @param wavIn  A file handle for the input file
 * @return bool Indicates if it was successful
 */
bool nextSample(short* sample, unsigned int size, FILE *wavIn)
{
    fread(sample, size, 1, wavIn);
    
    // Check if there were errors
    if (ferror(wavIn))
    {
        cerr << "Errors have occurred in reading from the input file." << endl;
        return false;
    }
    return true;
}

/**
 * Retrieves the next sample in the file. Requires that the file currently
 * be set valid sample (they should start at offset 44)
 * @param sample Array storing the sample (either short or char), uses
 *               a void pointer to abstract away the difference between
 *               8 and 16 bit samples from the top level view
 * @param size   The total size of sample (all elements in the array) in bytes
 * @param wavOut  A file handle for the output file
 * @return bool Indicates if it was successful
 */
bool saveSample(short* sample, unsigned int size, FILE *wavOut)
{
    fwrite(sample, size, 1, wavOut);
    
    // Check if there were errors
    if (ferror(wavOut))
    {
        cerr << "Errors have occurred in writing to the output file." << endl;
        return false;
    }
    return true;
}
