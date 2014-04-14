/* 
 * File:   wave_io.h
 * Author: Eugene Davis
 * 
 * /**
 * Adds a sine wave of 2500 Hertz at half the amplitude passed to it to an
 * 16-bit signal.
 * @param sample        void pointer, stores the 16-bit (short array) signal's sample for all channels
 * @param numChannels   Number of channels in this sample
 * @param amplitude     Amplitude to be divided by 2 and multiplied by the sine wave
 * @param sampleNum     Current sample number (iteration of calling loop/location in arary)
 * @param sampleRate    Sample rate of the signal the sample is from
 *
 *
 * Created on March 4, 2014, 10:53 PM
 */

#ifndef WAVE_IO_H
#define	WAVE_IO_H

#include <stdio.h> // File writing

#ifdef	__cplusplus
extern "C" {
#endif
    
    

    /*
     * header provides a struct with all the data found in the header of a WAV
     * file.
     * Names are as they are found at https://ccrma.stanford.edu/courses/422/projects/WaveFormat/
     */
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
    * Reads in the header from a WAV file and returns by reference a structure
    * containing the data from the header.
    * Returns a boolean to indicate whether it was successful or not.
    * 
    * @param wavHeader Structure for WAV headers
    * @param wavIn     File handle for input file
    * @return bool to indicate success or failure
    */
    bool readHeader(header *wavHeader, FILE *wavIn);

    /**
    * writeHeader writes out a header from a header struct into a WAV file.
    * Returns bool to indicate success.
    * @param wavHeader Structure for WAV headers
    * @param wavOut    File handle for output file
    * @return bool to indicate if it was successful
    */
    bool writeHeader(header *wavHeader, FILE *wavOut);

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
    bool nextSample(void* sample, unsigned int size, FILE *wavIn);

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
    bool saveSample(void* sample, unsigned int size, FILE *wavOut);


#ifdef	__cplusplus
}
#endif

#endif	/* WAVE_IO_H */

