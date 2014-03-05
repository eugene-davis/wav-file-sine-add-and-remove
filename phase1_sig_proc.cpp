#include <math.h>  // Contains sin
#include <stdlib.h> // Contains abs
#include <climits> // Contains constants used to check for overflow

#include "phase1_sig_proc.h"
#include "wave_io.h"

#define PI 3.14159265 // Define a value of PI as a macro rather than access memory when used

using namespace std;

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
            tempAmp = abs(sSamp[i]);
        }
    }
    return tempAmp;
}

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
    char sineWave = (amplitude/2) * sin(2*PI*2500*time);
    
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
    short sineWave = (amplitude/2) * sin(2*PI*2500*time);
    
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
