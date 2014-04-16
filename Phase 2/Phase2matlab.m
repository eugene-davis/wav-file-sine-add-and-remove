%Import Orginal file
[orig, Fs] = wavread('Davis_E_orig.WAV');

%Import noisy file
[noise, Fs] = wavread('Davis_E_noise.WAV');
sptool
% sptool and filter tool used to devlop filter graphically

%Import filtered files
[lp, Fs] = wavread('Davis_E_lp.WAV');
[bs, Fs] = wavread('Davis_E_bs.WAV');

sptool
% Sptool used to find spectrums