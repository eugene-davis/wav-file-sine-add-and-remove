/* 
 * Author: Eugene Davis
 * Class: CPE 381
 * CPE 381 Project Phase 2
 * 
 * Contains functions specific to Phase 2 of the project other than the main
 * function.
*/

#ifndef PHASE1_SIG_PROC_H
#define	PHASE1_SIG_PROC_H

#ifdef	__cplusplus
extern "C" {
#endif

	/**
	* filterSample the buffer of input samples (bufferSample), the coeffecient array and the length of the window
	* and returns the filtered sample via currentSample
	*/
	void filterSample(short* currentSample, short* bufferSample, double* coArray, int length);

#ifdef	__cplusplus
}
#endif

#endif	/* PHASE1_SIG_PROC_H */

