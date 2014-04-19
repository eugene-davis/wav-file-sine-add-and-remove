/* 
 * Author: Eugene Davis
 * Class: CPE 381
 * CPE 381 Project Phase 2
 * 
 * Contains functions specific to Phase 2 of the project other than the main
 * function.
*/

#include "bonus_fourier.h"

// Define PI for fft function to use
double pi = 4 * atan(1.0);

/*
 * fft performs a simple fast fourier transform
 * adapted from Jon Harrop's post on stackoverflow.com
 * https://stackoverflow.com/questions/10121574/safe-and-fast-fft
*/
void fft(int sign, vector<complex<double>> &zs) 
{
	unsigned int j = 0;
	// Warning about signed vs unsigned comparison
	for (unsigned int i = 0; i<zs.size() - 1; ++i) 
	{
		if (i < j) 
		{
			auto t = zs.at(i);
			zs.at(i) = zs.at(j);
			zs.at(j) = t;
		}
		int m = zs.size() / 2;
		j ^= m;
		while ((j & m) == 0) 
		{ 
			m /= 2; 
			j ^= m; 
		}
	}
	for (unsigned int j = 1; j<zs.size(); j *= 2)
	{
		for (unsigned int m = 0; m<j; ++m) 
		{
			auto t = pi * sign * m / j;
			auto w = complex<double>(cos(t), sin(t));
			for (unsigned int i = m; i<zs.size(); i += 2 * j) 	
			{
				complex<double> zi = zs.at(i), t = w * zs.at(i + j);
				zs.at(i) = zi + t;
				zs.at(i + j) = zi - t;
			}
		}
	}
}
