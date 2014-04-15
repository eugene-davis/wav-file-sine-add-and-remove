/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 *
 * Generated by MATLAB(R) 7.5 and the Signal Processing Toolbox 6.8.
 *
 * Generated on: 14-Apr-2014 22:21:45
 *
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 219
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 * Type              : Lowpass
 * Fs                : 22050
 * Fpass             : 2300
 * Fstop             : 2500
 */

int bLowPassCoarseLength22k = 219;
double bLowPassCoarse22k[219] = {
  0.0006315535619057,-2.060388792281e-005,-0.0006923662620402,-0.001866061006859,
   -0.00340688018731,-0.005007871132203,-0.006248203834422,-0.006714267833816,
  -0.006146907976149,-0.004559653541978,-0.002276845612575,0.0001369606552593,
    0.00204381003141, 0.002944174794398, 0.002656100518694, 0.001391058372311,
  -0.000311912353415,-0.001776520467832,-0.002439361576471,-0.002063599511922,
  -0.0008309358070758, 0.000731264103919,   0.0019624572143, 0.002340042946158,
   0.001698424658122,0.0003053724118694,-0.001244008430384,-0.002275175572833,
  -0.002323704090659, -0.00134123217655,0.0002692534936317,  0.00181467817851,
   0.002606493647898, 0.002265120032755, 0.000896161629922,-0.0009312572410418,
  -0.002421925188645,-0.002894694776807,-0.002091657814829,-0.0003129613677984,
   0.001691838034708, 0.003035538363763, 0.003083705504742, 0.001749849070589,
  -0.0004376360410784,  -0.0025413092633, -0.00361279817581,-0.003117462740898,
   -0.00119489990434, 0.001367398528347, 0.003452962707955, 0.004098853131138,
   0.002936449036699,0.0003888995559697,-0.002475024606508,-0.004385004869046,
  -0.004427927069249,-0.002478671474123,0.0006993093366131, 0.003745987658561,
    0.00528166572317, 0.004525515886824, 0.001682402330872,-0.002091164894911,
  -0.005149957980915,-0.006070459260398,-0.004304635868527,-0.0004813699110309,
   0.003803892331703, 0.006644766261426, 0.006663043836924, 0.003663465201138,
   -0.00120036857041,-0.005854579199934,-0.008177097896694,-0.006949895263074,
  -0.002472257370129, 0.003465286479372, 0.008278281607747,  0.00969432512445,
   0.006801089479634, 0.000564720680804,-0.006455191536777, -0.01112806227543,
   -0.01111611237999,-0.005997435720254, 0.002371396850734,  0.01048064221594,
     0.0145904244026,  0.01239290553315, 0.004199581087902,-0.006916442867813,
   -0.01619132408943, -0.01910996796684, -0.01346017299927,-0.0006211394404633,
    0.01455738440354,    0.025401260097,  0.02607249338748,  0.01425998389852,
   -0.00719788770892, -0.03053901123517, -0.04527723688361, -0.04174162131835,
   -0.01475387795663,  0.03390607976434,  0.09524364467265,   0.1552506101532,
     0.1989418460493,   0.2149208280712,   0.1989418460493,   0.1552506101532,
    0.09524364467265,  0.03390607976434, -0.01475387795663, -0.04174162131835,
   -0.04527723688361, -0.03053901123517, -0.00719788770892,  0.01425998389852,
    0.02607249338748,    0.025401260097,  0.01455738440354,-0.0006211394404633,
   -0.01346017299927, -0.01910996796684, -0.01619132408943,-0.006916442867813,
   0.004199581087902,  0.01239290553315,   0.0145904244026,  0.01048064221594,
   0.002371396850734,-0.005997435720254, -0.01111611237999, -0.01112806227543,
  -0.006455191536777, 0.000564720680804, 0.006801089479634,  0.00969432512445,
   0.008278281607747, 0.003465286479372,-0.002472257370129,-0.006949895263074,
  -0.008177097896694,-0.005854579199934, -0.00120036857041, 0.003663465201138,
   0.006663043836924, 0.006644766261426, 0.003803892331703,-0.0004813699110309,
  -0.004304635868527,-0.006070459260398,-0.005149957980915,-0.002091164894911,
   0.001682402330872, 0.004525515886824,  0.00528166572317, 0.003745987658561,
  0.0006993093366131,-0.002478671474123,-0.004427927069249,-0.004385004869046,
  -0.002475024606508,0.0003888995559697, 0.002936449036699, 0.004098853131138,
   0.003452962707955, 0.001367398528347, -0.00119489990434,-0.003117462740898,
   -0.00361279817581,  -0.0025413092633,-0.0004376360410784, 0.001749849070589,
   0.003083705504742, 0.003035538363763, 0.001691838034708,-0.0003129613677984,
  -0.002091657814829,-0.002894694776807,-0.002421925188645,-0.0009312572410418,
   0.000896161629922, 0.002265120032755, 0.002606493647898,  0.00181467817851,
  0.0002692534936317, -0.00134123217655,-0.002323704090659,-0.002275175572833,
  -0.001244008430384,0.0003053724118694, 0.001698424658122, 0.002340042946158,
     0.0019624572143, 0.000731264103919,-0.0008309358070758,-0.002063599511922,
  -0.002439361576471,-0.001776520467832,-0.000311912353415, 0.001391058372311,
   0.002656100518694, 0.002944174794398,  0.00204381003141,0.0001369606552593,
  -0.002276845612575,-0.004559653541978,-0.006146907976149,-0.006714267833816,
  -0.006248203834422,-0.005007871132203, -0.00340688018731,-0.001866061006859,
  -0.0006923662620402,-2.060388792281e-005,0.0006315535619057
};
