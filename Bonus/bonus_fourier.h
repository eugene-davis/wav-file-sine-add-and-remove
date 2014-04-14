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

#include <complex>
#include <vector>

#ifdef	__cplusplus
extern "C" {
#endif



using namespace std;

	/*
	 * fft performs a simple fast fourier transform
	 * adapted from Jon Harrop's post on stackoverflow.com
	 * https://stackoverflow.com/questions/10121574/safe-and-fast-fft
	*/
	void fft(int sign, vector< complex<double> > &zs);

#ifdef	__cplusplus
}
#endif

#endif	/* PHASE1_SIG_PROC_H */

