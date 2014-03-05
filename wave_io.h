/* 
 * File:   wave_io.h
 * Author: eugene
 *
 * Created on March 4, 2014, 10:53 PM
 */

#ifndef WAVE_IO_H
#define	WAVE_IO_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    #include <stdio.h> // File writing

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


#ifdef	__cplusplus
}
#endif

#endif	/* WAVE_IO_H */

