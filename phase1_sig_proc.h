/* 
 * File:   phase1_sig_proc.h
 * Author: eugene
 *
 * Created on March 4, 2014, 11:09 PM
 */

#ifndef PHASE1_SIG_PROC_H
#define	PHASE1_SIG_PROC_H

#ifdef	__cplusplus
extern "C" {
#endif


short maxChanAmp8Bit(void* sample, unsigned short numChannels);

short maxChanAmp16Bit(void* sample, unsigned short numChannels);

void addSignal8Bit(void* sample, unsigned short numChannels, 
        unsigned short amplitude, unsigned int sampleNum, unsigned int sampleRate);

void addSignal16Bit(void* sample, unsigned short numChannels, 
        unsigned short amplitude, unsigned int sampleNum, unsigned int sampleRate);


#ifdef	__cplusplus
}
#endif

#endif	/* PHASE1_SIG_PROC_H */

