/* 
 * File:   phase1_sig_proc.h
 * Author: Eugene Davis
 * Class: CPE 381
 * CPE 381 Project Phase 1
 * 
 * Contains functions specific to Phase 1 of the project other than the main
 * function, specifically functions to find the maximum amplitude of all the
 * channels in a given sample and functions to add a sine wave to the original
 * signal. Both functions include an 8 bit and a 16 bit version.
 * 
 * Created on March 4, 2014, 11:09 PM
 */

#ifndef PHASE1_SIG_PROC_H
#define	PHASE1_SIG_PROC_H

#ifdef	__cplusplus
extern "C" {
#endif

	void filterSignal(short* currentSample, short* bufferSample, short* coArray, int length);

#ifdef	__cplusplus
}
#endif

#endif	/* PHASE1_SIG_PROC_H */

