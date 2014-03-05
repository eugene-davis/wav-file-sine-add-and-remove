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

    /**
     * Returns the maximum amplitude signal amongst all the channels for an 8-bit 
     * signal.
     * 
     * @param sample        void pointer (in this case should be a char array) containing
     *                      the sample to look at
     * @param numChannels   Number of channels in the sample
     * @return short Maximum amplitude of the channels
     */
    short maxChanAmp8Bit(void* sample, unsigned short numChannels);

    /**
     * Returns the maximum amplitude signal amongst all the channels for an 16-bit 
     * signal.
     * 
     * @param sample        void pointer (in this case should be a short array) containing
     *                      the sample to look at
     * @param numChannels   Number of channels in the sample
     * @return short Maximum amplitude of the channels
     */
    short maxChanAmp16Bit(void* sample, unsigned short numChannels);

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
            unsigned short amplitude, unsigned int sampleNum, unsigned int sampleRate);

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
            unsigned short amplitude, unsigned int sampleNum, unsigned int sampleRate);


#ifdef	__cplusplus
}
#endif

#endif	/* PHASE1_SIG_PROC_H */

