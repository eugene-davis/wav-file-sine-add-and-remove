/* 
 * Author: Eugene Davis
 * Class: CPE 381
 * CPE 381 Project Phase 2
 * 
 * Contains functions specific to Phase 2 of the project other than the main
 * function.
*/

#include "phase2_sig_proc.h"
#include "wave_io.h"
#include <string.h> // memcopy
#include <iostream>

using namespace std;

/**
* filterSample the buffer of input samples (bufferSample), the coeffecient array and the length of the window
* and returns the filtered sample via currentSample
*/
void filterSample(short* currentSample, short* bufferSample, double* coArray, int length)
{
	// Temp double variable to store result in
	double sample = 0;

	// Run through the entire window applying the coefficient array
	for (int i = 0; i < length; i++)
	{
		double xSample = bufferSample[i];
		// Multiply the coefficient for this point by each of the channels - treat as doubles
		sample += xSample * coArray[i];
	}

	// Shift samples right to prepare for the new one
	for (int j = length - 1; j > 0; j--)
	{
		bufferSample[j] = bufferSample[j-1];
	}
	
	// Cast to short
	*currentSample = (short) sample;
}
