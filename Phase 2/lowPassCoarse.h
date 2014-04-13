/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 *
 * Generated by MATLAB(R) 7.5 and the Signal Processing Toolbox 6.8.
 *
 * Generated on: 13-Apr-2014 12:42:23
 *
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 175
 * Stable            : Yes
 * Linear Phase      : Yes (Type 1)
 */

/* General type conversion for MATLAB generated C-code  */

/* 
 * Expected path to tmwtypes.h 
 * C:\Program Files\MATLAB\R2007b\extern\include\tmwtypes.h 
 */
int bLowPassCoarseLength = 175;
double bLowPassCoarse[175] = {
  0.0005612467093414,-0.0001955003660825,-0.0002357283428312,-0.0003133857215241,
  -0.0004237482277734,-0.0005636945314685,-0.0007309520693022,-0.0009231426894698,
  -0.001137839120856,-0.001371814434397,-0.001621347308818,-0.001881628367181,
  -0.002147297507811,-0.002411947424911,-0.002668746343997,-0.002909989955807,
  -0.003127839905204,-0.003313946806696,-0.003460266635779,-0.003558702413852,
  -0.003601986391573,-0.003583337188086,-0.003497381001101,-0.003339763566714,
  -0.003108071916931,-0.002801369933252,-0.002421093830564,-0.001970453634124,
  -0.001455276539046,-0.0008832527074286,-0.0002647253691151,0.0003882767073924,
   0.001061318105112, 0.001738754112444, 0.002403021807707, 0.003036119819709,
   0.003618900504363,   0.0041328723284, 0.004559270073465, 0.004881197448742,
   0.005082297526917, 0.005149709218157, 0.005071552079668, 0.004841285379693,
   0.004453802136319, 0.003908427113931, 0.003211295310119, 0.002369859885208,
    0.00139776405791,0.0003124694031657,-0.0008632665523053,-0.002103310912265,
  -0.003377287566469,-0.004652092516276,-0.005891588787947,-0.007058134768139,
  -0.008112732544825,-0.009016521112312,-0.009731143897112,  -0.0102201900462,
   -0.01044970979923,  -0.0103895544654, -0.01001388231114,-0.009302305211228,
  -0.008240295644016,-0.006820082090959, -0.00504084667384,-0.002909285220525,
  -0.000439528116561, 0.002346664201361, 0.005420303902291, 0.008745369290247,
    0.01227952554485,  0.01597466254658,  0.01977790350227,  0.02363245745612,
    0.02747885153998,  0.03125597976454,  0.03490244749702,  0.03835775654399,
    0.04156368780714,  0.04446546247511,  0.04701291908066,  0.04916154748761,
    0.05087346458954,  0.05211854416458,  0.05287457063681,  0.05312833536153,
    0.05287457063681,  0.05211854416458,  0.05087346458954,  0.04916154748761,
    0.04701291908066,  0.04446546247511,  0.04156368780714,  0.03835775654399,
    0.03490244749702,  0.03125597976454,  0.02747885153998,  0.02363245745612,
    0.01977790350227,  0.01597466254658,  0.01227952554485, 0.008745369290247,
   0.005420303902291, 0.002346664201361,-0.000439528116561,-0.002909285220525,
   -0.00504084667384,-0.006820082090959,-0.008240295644016,-0.009302305211228,
   -0.01001388231114,  -0.0103895544654, -0.01044970979923,  -0.0102201900462,
  -0.009731143897112,-0.009016521112312,-0.008112732544825,-0.007058134768139,
  -0.005891588787947,-0.004652092516276,-0.003377287566469,-0.002103310912265,
  -0.0008632665523053,0.0003124694031657,  0.00139776405791, 0.002369859885208,
   0.003211295310119, 0.003908427113931, 0.004453802136319, 0.004841285379693,
   0.005071552079668, 0.005149709218157, 0.005082297526917, 0.004881197448742,
   0.004559270073465,   0.0041328723284, 0.003618900504363, 0.003036119819709,
   0.002403021807707, 0.001738754112444, 0.001061318105112,0.0003882767073924,
  -0.0002647253691151,-0.0008832527074286,-0.001455276539046,-0.001970453634124,
  -0.002421093830564,-0.002801369933252,-0.003108071916931,-0.003339763566714,
  -0.003497381001101,-0.003583337188086,-0.003601986391573,-0.003558702413852,
  -0.003460266635779,-0.003313946806696,-0.003127839905204,-0.002909989955807,
  -0.002668746343997,-0.002411947424911,-0.002147297507811,-0.001881628367181,
  -0.001621347308818,-0.001371814434397,-0.001137839120856,-0.0009231426894698,
  -0.0007309520693022,-0.0005636945314685,-0.0004237482277734,-0.0003133857215241,
  -0.0002357283428312,-0.0001955003660825,0.0005612467093414
};
