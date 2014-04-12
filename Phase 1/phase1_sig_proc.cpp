/* 
 * Author: Eugene Davis
 * Class: CPE 381
 * CPE 381 Project Phase 1
 * 
 * Contains functions specific to Phase 1 of the project other than the main
 * function, specifically functions to find the maximum amplitude of all the
 * channels in a given sample and functions to add a sine wave to the original
 * signal. Both functions include an 8 bit and a 16 bit version.
 */

#include <math.h>  // Contains sin
#include <stdlib.h> // Contains abs
#include <climits> // Contains constants used to check for overflow

#include "phase1_sig_proc.h"
#include "wave_io.h"

#define PI 3.14159265 // Define a value of PI as a macro rather than access memory when used

using namespace std;

/**
 * Returns the maximum amplitude signal amongst all the channels for an 8-bit 
 * signal.
 * 
 * @param sample        void pointer (in this case should be a char array) containing
 *                      the sample to look at
 * @param numChannels   Number of channels in the sample
 * @return short Maximum amplitude of the channels
 */
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

/**
 * Returns the maximum amplitude signal amongst all the channels for an 16-bit 
 * signal.
 * 
 * @param sample        void pointer (in this case should be a short array) containing
 *                      the sample to look at
 * @param numChannels   Number of channels in the sample
 * @return short Maximum amplitude of the channels
 */
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
            tempAmp = abs(sSamp[i]);
        }
    }
    return tempAmp;
}

/**
 * Adds a sine wave of 2500 Hertz at half the amplitude passed to it to an
 * 8-bit signal.
 * @param sample        void pointer, stores the 8-bit (char array) signal's sample for all channels
 * @param numChannels   Number of channels in this sample
 * @param amplitude     Amplitude to be divided by 2 and multiplied by the sine wave
 * @param sampleNum     Current sample number (iteration of calling loop/location in arary)
 * @param sampleRate    Sample rate of the signal the sample is from
 */
void addSignal8Bit(void* sample, unsigned short numChannels, 
        unsigned short amplitude, unsigned int sampleNum, unsigned int sampleRate)
{
    // Cast the sample input into a char array (16 bit not 8)
    char* cSamp = static_cast<char*>(sample);
    
    // Calculate the time for the sineWave using the samplingRate and current sample number
    // Cast each bit to double to ensure the calculation uses doubles
     double time = (double) sampleNum / (double) sampleRate;
    
    // Sine wav calculation for this point in time - 2500 is the frequency
    // Truncated into short (sin outputs double normally)
    char sineWave = (char) ((amplitude/2) * sin(2*PI*2500*time));
    
    // Temp just add half of amplitude to see if it works
    for (short i = 0; i < numChannels; i++)
    {
        // Check that it doesn't overflow, if it does set to max instead
        if (sineWave > CHAR_MAX - cSamp[i])
        {
            cSamp[i] = CHAR_MAX;
        }
        else
        {
            cSamp[i] = cSamp[i] + sineWave;
        }
    }
}

/**
 * Adds a sine wave of 2500 Hertz at half the amplitude passed to it to an
 * 16-bit signal.
 * @param sample        void pointer, stores the 16-bit (short array) signal's sample for all channels
 * @param numChannels   Number of channels in this sample
 * @param amplitude     Amplitude to be divided by 2 and multiplied by the sine wave
 * @param sampleNum     Current sample number (iteration of calling loop/location in arary)
 * @param sampleRate    Sample rate of the signal the sample is from
 */
void addSignal16Bit(void* sample, unsigned short numChannels, 
        unsigned short amplitude, unsigned int sampleNum, unsigned int sampleRate)
{
    // Cast the sample input into a short array (16 bit not 8)
    short* sSamp = static_cast<short*>(sample);
    
    // Calculate the time for the sineWave using the samplingRate and current sample number
    // Cast each bit to double to ensure the calculation uses doubles
     double time = (double) sampleNum / (double) sampleRate;
    
    // Sine wav calculation for this point in time - 2500 is the frequency
    // Truncated into short (sin outputs double normally)
    short sineWave = (short) ((amplitude/2) * sin(2*PI*2500*time));
    
    // Temp just add half of amplitude to see if it works
    for (short i = 0; i < numChannels; i++)
    {
        // Check that it doesn't overflow, if it does set to max instead
        if (sineWave > SHRT_MAX - sSamp[i])
        {
            sSamp[i] = SHRT_MAX;
        }
        else
        {
                sSamp[i] = sSamp[i] + sineWave;
        }
    }
}
