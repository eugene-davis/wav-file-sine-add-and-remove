/*
 * Filter Coefficients (C Source) generated by the Filter Design and Analysis Tool
 *
 * Generated by MATLAB(R) 7.5 and the Signal Processing Toolbox 6.8.
 *
 * Generated on: 13-Apr-2014 15:19:40
 *
 */

/*
 * Discrete-Time FIR Filter (real)
 * -------------------------------
 * Filter Structure  : Direct-Form FIR
 * Filter Length     : 1770
 * Stable            : Yes
 * Linear Phase      : Yes (Type 2)
 * Type              : Lowpass
 * Fs                : 48000
 * Fpass             : 2400
 * Fstop             : 2450
 */

int bLowPassFineLength = 1770;
double bLowPassFine[1770] = {
  -0.0007612526240555,-0.000599954756071,-0.0007969714041417,-0.001001103118564,
  -0.001199156024359,-0.001376377461198,-0.001516508677178,-0.001604362021221,
  -0.001626534048012,-0.001571996866145,-0.001433345510182,-0.001210497302095,
  -0.0009058633331502,-0.0005304116468735,-9.870104057612e-005,0.0003692853100522,
  0.0008499121523355, 0.001317790030862, 0.001747222553177, 0.002114143817666,
   0.002398079555398, 0.002583914178368, 0.002662359836389, 0.002632001634513,
   0.002498220322787, 0.002273797044343, 0.001977682211829, 0.001633309111382,
   0.001267200815596, 0.000906420003473,0.0005767303440273,0.0003002777090793,
  9.433742940151e-005,-3.069808013259e-005,-7.113396057954e-005,-3.101504924518e-005,
  7.910124832792e-005,0.0002428450071943,0.0004398367877383, 0.000647536990799,
  0.0008434979007928, 0.001007187470725, 0.001122023034862, 0.001176658983486,
   0.001165887188528, 0.001091044635132,0.0009596696672741,0.0007845247653491,
  0.0005824902299453,0.0003724200105849, 0.000173663755527,3.758454014849e-006,
  -0.0001228933954039,-0.0001967366004488,-0.0002134470238152,-0.0001747595991231,
  -8.759170501141e-005,3.624060606272e-005,0.0001817519637354,0.0003320536338166,
   0.000470366166444,0.0005814824062309,0.0006535640499629,0.0006789832656708,
  0.0006553067269399,0.0005851973790915,0.0004762262121627,0.0003398051025826,
  0.0001901371887091,4.237633677848e-005,-8.860682269264e-005,-0.0001901973055124,
  -0.0002529003799192,-0.0002716772395347,-0.0002460169027027,-0.0001803103113176,
  -8.28779936978e-005,3.451094620924e-005,0.0001584081980343,0.0002747257783376,
  0.0003706189751258,0.0004355398735289,0.0004626139503135,0.0004490362569301,
  0.0003966095342398,0.0003111704670994,0.0002021954749789,8.146153352585e-005,
  -3.801297843022e-005,-0.0001436441128523,-0.0002243591625441,-0.0002721132383516,
  -0.0002823591594886,-0.0002548832643051,-0.0001934057143242,-0.0001054831769369,
  -1.294282685551e-006,0.0001071468304469,0.0002076982214118,0.0002890436598547,
  0.0003422932504782,0.0003616078585158,0.0003450969088837,  0.00029473327336,
  0.0002163394345175,0.0001186583212605,1.26202505296e-005,-9.014384322336e-005,
  -0.0001783469569312,-0.0002425225516507,-0.0002758351560862,-0.0002750529450091,
  -0.0002406152549015,-0.0001768486060104,-9.114583661909e-005,6.566528162453e-006,
  0.0001052456288287,0.0001936843619856, 0.000262036498402,0.0003026237940001,
  0.0003110691453449,0.0002864835280864,0.0002318119594964,0.0001532475876939,
  5.972521649542e-005,-3.828444010916e-005,-0.0001297682511644,-0.000204603904318,
  -0.0002544828530912,-0.0002740364185025,-0.0002612261556932,-0.0002177480037301,
  -0.0001486353521634,-6.188876466135e-005,3.266222503737e-005,0.0001242217917037,
  0.0002024992964241,0.0002586164153517,0.0002863358729348,0.0002825318878458,
  0.0002477538384072,  0.00018593176766, 0.000104149767773,1.162255924704e-005,
  -8.114876898443e-005,-0.0001637431872397,-0.0002268326477234,-0.0002633907359186,
  -0.000269315817499, -0.00024406615413,-0.000190530703101,-0.0001148852330731,
  -2.570767617267e-005,6.681212450055e-005,0.0001522161569959,0.0002207586787457,
  0.0002647288871196,0.0002790910445566,0.0002622815623967,0.0002161618854874,
  0.0001460144480684,5.974206222874e-005,-3.282573143834e-005,-0.0001212486766655,
  -0.0001954539987557,-0.0002470750212103,-0.000270215286515,-0.0002622910230011,
  -0.0002241585360933,-0.000160190323507,-7.759894812583e-005,1.418452494642e-005,
   0.000104779448141,0.0001838304216829,0.0002423828625967,0.0002737001547542,
  0.0002742401049468, 0.000243841874425,0.0001859781273653,0.0001071323453577,
  1.629371783859e-005,-7.627826157228e-005,-0.0001600092756554,-0.0002254154169817,
  -0.000264976809984,-0.0002742047557118,-0.0002519483868729,-0.0002007357803705,
  -0.0001262978383697,-3.711304101597e-005,5.674064519087e-005,0.0001445304306394,
  0.0002162946604961,0.0002637614187387,0.0002815120930083, 0.000267389450895,
   0.000222965588642,0.0001531603335627,6.590858118389e-005,-2.895950856092e-005,
  -0.0001206037751487,-0.000198632128256,-0.0002540649525968,-0.0002805711985829,
  -0.0002749925695598,-0.0002379160503128,-0.0001734135645466,-8.879942317714e-005,
  6.399154230291e-006,0.0001013160397131,0.0001851761062887,0.0002483300151574,
  0.0002835524207055,0.0002866733247944,0.0002572708507888, 0.000198523432163,
  0.0001170680166212,2.205477123225e-005,-7.568871614675e-005,-0.0001650815757556,
  -0.0002358515525603,-0.0002799117651791,-0.0002920859098538,-0.0002709094488022,
  -0.0002186175145677,-0.0001410918388166,-4.702223498605e-005,5.288676369314e-005,
  0.0001473146351306,0.0002254230249727,0.0002782795571879,0.0002997034706766,
  0.0002871562924388,0.0002418757652055,0.0001689231964887,7.644837053384e-005,
  -2.504766105844e-005,-0.0001240749496613,-0.0002092877563914,-0.0002709449443338,
  -0.0003018650178766,-0.0002984211414293,-0.0002608037007731,-0.0001931875246921,
  -0.0001031027273393,-7.599066051793e-007,0.0001022644294688,0.0001941819487478,
  0.0002644935841403,0.0003050323312288,0.0003110679904769,0.0002817020323455,
  0.0002201458736814,0.0001332248871316,3.076213683359e-005,-7.566877322685e-005,
  -0.0001739120107952,-0.0002527580598275,-0.0003030799109317,-0.0003190294677225,
  -0.0002985789093771,-0.0002439110019889,-0.0001610514980345,-5.934599794905e-005,
  4.97385325581e-005, 0.000153756479744,0.0002408521034461,0.0003009626495761,
  0.0003271231066419,0.0003161313616438,0.0002690789153796,0.0001911028271206,
  9.096826229151e-005,-2.005577178237e-005,-0.0001293301372908,-0.0002244121861063,
  -0.0002943474870591,-0.000331055301506,-0.0003301338618952,-0.0002915176475724,
  -0.0002193704027585,-0.000121772693501,-9.683692382552e-006,0.0001041525089266,
   0.000206794358286,0.0002864283549772,0.0003338787181184,0.0003435108792195,
  0.0003140515477227,0.0002486049550812,0.0001544724218282,4.219654675268e-005,
  -7.547767669462e-005,-0.0001851898282363,-0.0002743409228786,-0.0003326753291863,
  -0.0003533285924813,-0.0003337613896264,-0.0002759423997186,-0.0001862838614078,
  -7.47952223611e-005,4.589196798963e-005, 0.000162099495797,0.0002605048561368,
  0.0003298160237405,0.0003619159519336,0.0003529664372477,0.0003037071498161,
  0.0002195642437645,0.0001098932997485,-1.290387017818e-005,-0.0001349308090936,
  -0.0002422234954173,-0.0003224886700395,-0.0003663718132505,-0.0003686854446668,
  -0.0003288839552489,-0.000251292487954,-0.0001445059104713,-2.05693356142e-005,
  0.0001065143378765,0.0002222258391362,0.0003133336505052,0.0003692547121292,
  0.0003834364491615, 0.000353969247364,0.0002839916247957,0.0001812033956004,
  5.717532947982e-005,-7.410845646464e-005,-0.0001976726610436,-0.0002994074918007,
  -0.0003675371422533,-0.0003941169453033,-0.0003758289675055,-0.0003145202859185,
  -0.000216892432723,-9.389794604558e-005,4.061451667878e-005,0.0001713322325669,
  0.0002833468355931, 0.000363725697746,0.0004031362194324,0.0003967906391151,
  0.0003451675504042,0.0002538404753622,0.0001330222095924,-3.717723507299e-006,
  -0.0001408380917578,-0.0002627275125113,-0.0003553474934083,-0.0004079795727772,
  -0.0004143379707352,-0.0003734387567641,-0.0002896271144263,-0.0001722271507263,
  -3.43990391261e-005,0.0001082278009455,0.0002394354925794,0.0003441493314275,
  0.0004102818153241,0.0004300135111815,0.0004008307033145,0.0003257245337168,
  0.0002130090535565,7.52777258245e-005,-7.187663332947e-005,-0.0002117505043104,
  -0.0003283040826605,-0.0004081150339362,-0.000441812095727,-0.000425281827685,
  -0.0003600625217363,-0.0002533114470951,-0.0001169209703938,3.37091288054e-005,
  0.0001815021450313,0.0003095477788675,0.0004031292547868, 0.000451316800775,
  0.0004483439278368,0.0003941912403708, 0.000294735064265,0.0001610050931041,
  8.069357637412e-006,-0.0001467711438479,-0.0002858288153378,-0.0003931598465669,
  -0.0004562818476559,-0.0004677302390464,-0.0004258381734175,-0.0003350642298956,
  -0.0002054264391807,-5.149098729561e-005,0.0001093566068782,0.0002587809190208,
  0.0003796783010425,0.0004580414225673, 0.000484672973117,0.0004561689993093,
  0.0003754468436888,0.0002513475610026,9.777598445785e-005,-6.796445054307e-005,
  -0.0002270127466763,-0.0003612028629728,-0.0004550323348573,-0.0004975579789689,
  -0.0004835654854152,-0.0004143103822085,-0.0002973108416889,-0.000145633686769,
  2.365992335979e-005,0.0001913374924914,0.0003382737774837,0.0004475337939527,
  0.0005064229132455,0.0005078583836068, 0.000451321057149,0.0003428510874536,
  0.0001945104068848,2.293563268079e-005,-0.0001524165966624,-0.0003115874267699,
  -0.0004362736014457,-0.0005120428661418,-0.0005298943570681,-0.0004874317318415,
  -0.000389072839115,-0.000245698255286,-7.334543851379e-005, 0.000108480044895,
  0.0002791131417514,0.0004189757385916,0.0005119219740896,0.0005469998467989,
  0.0005198432219937,0.0004331041612031,0.0002963107057782,0.0001247111305586,
  -6.231358948749e-005,-0.000243547239589,-0.0003982348525229,-0.0005085672100596,
  -0.0005616208861375,-0.0005509784391475,-0.0004773953998078,-0.0003488691111121,
  -0.0001796725221163,1.113232577099e-005,0.0002019367832466,0.0003709347375256,
  0.0004987116779174,0.0005703746570474,0.0005773856053754,0.0005184768854431,
  0.0003999486260215,0.0002348969474338,4.187227291972e-005,-0.0001573092432362,
  -0.0003399249053158,-0.0004850399340862,-0.0005758057103906,-0.0006015112235171,
  -0.0005587507115605,-0.0004519580601987,-0.0002928608784143,-9.928403486947e-005,
  0.0001069324995795,0.0003023123451696,0.0004644960683048,0.0005747166447764,
  0.0006200528655248,0.0005948557466364,0.0005015356433648,0.0003502500478117,
  0.0001578916920128,-5.388589660492e-005,-0.0002610142329029,-0.0004398337181113,
  -0.0005697047790401,-0.0006354773523087,-0.0006291699271389,-0.0005510159621345,
  -0.0004094148504297,-0.0002201064591229,-4.352368010742e-006,0.0002133799003923,
  0.0004082600114925,0.0005578547207429,0.0006447780906074,0.0006586402725818,
  0.0005973565012472,0.0004673687134921, 0.000283049859863,6.503700070674e-005,
  -0.0001619954205168,-0.0003722088883202,-0.0005414588226864,-0.000650145114741,
  -0.0006854028095578,-0.0006426973079275,-0.0005263256420681,-0.0003490628606927,
  -0.0001306943680996,0.0001041266151132,0.0003287214126283,0.0005173561559402,
  0.0006482485541194,0.0007060197437742,0.0006835633624083,0.0005828480103155,
  0.0004148295820856,0.0001981925712874,-4.265153343796e-005,-0.0002803886542288,
  -0.0004878182224684,-0.000641043619823,-0.0007221418798567,-0.0007213357292545,
  -0.0006380923316214,-0.0004813269641381,-0.0002683832132351,-2.318443651634e-005,
  0.0002265174625844,0.0004522166680501,0.0006279673458032,0.0007333027196499,
  0.0007556758126467,0.0006918864345851, 0.000548584946917,0.0003415135279201,
  9.385388255083e-005,-0.0001664441555119,-0.0004097362661512,-0.0006081392621109,
  -0.0007386435883963,-0.000785863113696,-0.0007437632667723,-0.0006165056866925,
  -0.0004179675575462,-0.0001703084808872,9.857154737007e-005,0.0003581042411321,
  0.0005785927355306,0.0007345413822382,0.0008076680249825, 0.000788978070457,
  0.0006799319062915,0.0004922876480979,0.0002469098811665,-2.861998481509e-005,
  -0.0003030216376266,-0.0005449451520566,-0.0007264645549918,-0.0008263824018526,
  -0.0008326167143333,-0.0007437380628039,-0.0005691319936297,-0.0003280945261133,
  -4.762517882524e-005,0.0002405186575585,0.0005034855133232,0.0007110038632293,
  0.0008389271845132,0.0008719755642469,0.0008056176593953,0.0006466068818741,
   0.000412369749487,0.0001290301412474,-0.0001714322671239,-0.0004548614697745,
  -0.0006887325144537,-0.0008459582240596,-0.0009079457685395,-0.0008668707086553,
  -0.0007265766923568,-0.0005023091428425,-0.0002189913935648,9.147207293015e-005,
   0.000393851710128,0.0006535233971813,0.0008404921680519,0.0009327945786139,
  0.0009191317742154,0.0008001906630205,0.0005887196767403,0.0003081144203387,
  -1.01079479251e-005,-0.0003299042669566,-0.0006147213270713,-0.0008317327999062,
  -0.000955554615273,-0.000971272837367,-0.0008761687026186,-0.0006801978528287,
  -0.0004048932691365,-8.106669250677e-005,0.0002546945577496,0.0005641020948369,
  0.0008115800504122, 0.000968302487336,  0.00101559338651,0.0009470989563667,
   0.000769666851468,0.0005026299315879,0.0001757515399894,-0.0001741320848778,
  -0.0005072113027828,-0.0007852765293372,-0.0009760449995638,-0.001056956426641,
  -0.001017780143258,-0.0008619475253463,-0.0006062262349516,-0.0002789743536129,
  8.304885810578e-005,0.0004387584302269,0.0007474487155687,0.0009734012200196,
   0.001090054328523, 0.001083078817856, 0.000952164542666,0.0007111421928723,
  0.0003865711881061,1.477753506973e-005,-0.0003621644128773,-0.0007012320756299,
  -0.0009633162376786,-0.001117772006685,-0.001145949692823,-0.001043485478653,
  -0.0008208799640765,-0.0005024863868335,-0.0001238052728314,0.0002724209505848,
  0.0006410710401375,0.0009397344742405, 0.001133626809817, 0.001199592625819,
   0.001128903742724,0.0009283499725761,0.0006196511030836,0.0002370742750768,
  -0.0001763208695659,-0.0005735645029173,-0.0009090602916808,-0.001143859687071,
  -0.001250126335007,-0.001214476489868,-0.001039597082978,-0.0007441460520211,
  -0.0003607235069961,6.766654928532e-005,  0.00049248156588,0.0008650845543159,
   0.001142351306884, 0.001291608600981, 0.001294517902983, 0.001149270444968,
  0.0008710048098541,0.0004902001396648,4.939414045981e-005,-0.0004016062785477,
  -0.0008112961683063,-0.001132393599031,-0.001327236610309,-0.001372241687521,
  -0.001260689542849,-0.001003724431325,-0.0006292098717137,-0.0001787718441969,
  0.0002968685713127,0.0007435476605948, 0.001109865179029, 0.001353041138531,
   0.001443946510268, 0.001370532472533, 0.001139435809722,0.0007753768576072,
  0.0003185723698776,-0.0001797401479118,-0.000662993229998,-0.001075748373493,
  -0.001369996130125,-0.001510778475422,-0.001480278470023,-0.001280099064767,
  -0.0009312439220447,-0.000471984664052,4.637334858482e-005,0.0005651608205255,
   0.001025017353202, 0.001372627252591, 0.001566926640255, 0.001583899832972,
   0.001419560513402, 0.001090600453375,0.0006327587535864,9.691918077088e-005,
  -0.0004564942272249, -0.00096435264276,-0.001367971098744,-0.001619913542807,
  -0.001689509081698,-0.001566604693695,-0.001262929173157,-0.0008110593792011,
  -0.0002609060267316,0.0003257431066229,0.0008821832081319,  0.00134432389443,
   0.001658087361999, 0.001785685734217, 0.001710176474864, 0.001437635553179,
  0.0009967783231693,0.0004359374758081,-0.0001821898336692,-0.0007875562771748,
  -0.001310654963897,-0.001690505588926,-0.001881712729505,-0.001859892682784,
  -0.001624708605651,-0.001200260177529,-0.0006326185503645,1.51168819153e-005,
  0.0006698394874253, 0.001256634615237, 0.001707352259361, 0.001968472205807,
   0.002007451692169, 0.001816717844524, 0.001414902007324,0.0008450573899064,
  0.0001700940346053,-0.0005341530617535,-0.001187399970697,-0.001714053852915,
  -0.002051909617759,-0.002159484463976,-0.002021043608063,-0.001648804395025,
  -0.001081927182552,-0.0003824620724144,0.0003714345354412, 0.001094172671625,
   0.001702436588166, 0.002124727977462, 0.002309752316706, 0.002232581375441,
   0.001897935242432,  0.00134009074322,0.0006194430553209,-0.0001840063818204,
  -0.000979473951791,-0.001675625098952,-0.002191000771575,-0.002463518940769,
  -0.002457878885174,-0.002170068537399,-0.001628321858935,-0.0008904581816678,
  -3.773966015683e-005,0.0008340000277607, 0.001625099807688, 0.002243383332699,
   0.002614866709965, 0.002692519955723, 0.002462154612768, 0.001944612468821,
   0.001194034758562,0.0002922523762571,-0.000660052254782,-0.001554538910167,
  -0.002287446146896,-0.002771575138006,-0.002946562439245,-0.002786326362931,
  -0.002302691057525,-0.001544798056625,-0.0005941884974068,0.0004438567559501,
   0.001451922653395, 0.002313622140896, 0.002926969138658, 0.003216319061479,
   0.003141603169386, 0.002703634939613, 0.001944911205203,0.0009456155989252,
  -0.0001847183920027,-0.001319124874242,-0.002327330517333,-0.003090610846652,
  -0.003515617631615,-0.003545662526209,-0.003168026059287,-0.002416461968723,
  -0.001368404270051,-0.0001371716835512, 0.001140160445051, 0.002317840255876,
   0.003257929854827, 0.003846255006043,  0.00400609523379, 0.003707891484908,
   0.002973871038772, 0.001876837878233,0.0005332056623183,-0.0009091671672611,
  -0.002287014327079, -0.00343992745477,-0.004228761879683,-0.004552164042191,
   -0.00435922791459,-0.003656795296557,-0.002510360250723,-0.001038353033575,
  0.0005998063404049, 0.002220645441763, 0.003636866843601, 0.004678605552373,
   0.005213406361471, 0.005162556154641,  0.00451187084659, 0.003315476637729,
   0.001691990508219,-0.0001867759418615,-0.002113516451952,-0.003867796192675,
  -0.005240690107181,-0.006059027908732,-0.006206474128277,-0.005638984568169,
  -0.004392668914004,-0.002582913733237,-0.0003945113445846, 0.001936432398866,
   0.004147129536519, 0.005976771167233, 0.007196207620221, 0.007635358710126,
   0.007205230009493, 0.005911837873081, 0.003860157346151,  0.00124719615218,
  -0.001655526795197,-0.004528672790104, -0.00703843908266,-0.008873251665833,
  -0.009779953241278, -0.00959551560668,-0.008270617597451,-0.005882109100561,
  -0.002632439720017, 0.001164595276387, 0.005111017582657, 0.008762589429182,
    0.01167411029299,  0.01344779473305,  0.01377990031793,  0.01250073822428,
   0.009603634579113,  0.00525932314164,-0.0001864611757581, -0.00623283832867,
    -0.0122600675864, -0.01757956876404, -0.02149356589519, -0.02335913215286,
   -0.02265081243792, -0.01901590664201, -0.01231700877686,-0.002657389749225,
    0.00961369718109,  0.02391695624862,  0.03947946145116,  0.05538888556758,
    0.07066120421405,  0.08431623668781,  0.09545457518048,   0.1033292478829,
     0.1074058499451,   0.1074058499451,   0.1033292478829,  0.09545457518048,
    0.08431623668781,  0.07066120421405,  0.05538888556758,  0.03947946145116,
    0.02391695624862,  0.00961369718109,-0.002657389749225, -0.01231700877686,
   -0.01901590664201, -0.02265081243792, -0.02335913215286, -0.02149356589519,
   -0.01757956876404,  -0.0122600675864, -0.00623283832867,-0.0001864611757581,
    0.00525932314164, 0.009603634579113,  0.01250073822428,  0.01377990031793,
    0.01344779473305,  0.01167411029299, 0.008762589429182, 0.005111017582657,
   0.001164595276387,-0.002632439720017,-0.005882109100561,-0.008270617597451,
   -0.00959551560668,-0.009779953241278,-0.008873251665833, -0.00703843908266,
  -0.004528672790104,-0.001655526795197,  0.00124719615218, 0.003860157346151,
   0.005911837873081, 0.007205230009493, 0.007635358710126, 0.007196207620221,
   0.005976771167233, 0.004147129536519, 0.001936432398866,-0.0003945113445846,
  -0.002582913733237,-0.004392668914004,-0.005638984568169,-0.006206474128277,
  -0.006059027908732,-0.005240690107181,-0.003867796192675,-0.002113516451952,
  -0.0001867759418615, 0.001691990508219, 0.003315476637729,  0.00451187084659,
   0.005162556154641, 0.005213406361471, 0.004678605552373, 0.003636866843601,
   0.002220645441763,0.0005998063404049,-0.001038353033575,-0.002510360250723,
  -0.003656795296557, -0.00435922791459,-0.004552164042191,-0.004228761879683,
   -0.00343992745477,-0.002287014327079,-0.0009091671672611,0.0005332056623183,
   0.001876837878233, 0.002973871038772, 0.003707891484908,  0.00400609523379,
   0.003846255006043, 0.003257929854827, 0.002317840255876, 0.001140160445051,
  -0.0001371716835512,-0.001368404270051,-0.002416461968723,-0.003168026059287,
  -0.003545662526209,-0.003515617631615,-0.003090610846652,-0.002327330517333,
  -0.001319124874242,-0.0001847183920027,0.0009456155989252, 0.001944911205203,
   0.002703634939613, 0.003141603169386, 0.003216319061479, 0.002926969138658,
   0.002313622140896, 0.001451922653395,0.0004438567559501,-0.0005941884974068,
  -0.001544798056625,-0.002302691057525,-0.002786326362931,-0.002946562439245,
  -0.002771575138006,-0.002287446146896,-0.001554538910167,-0.000660052254782,
  0.0002922523762571, 0.001194034758562, 0.001944612468821, 0.002462154612768,
   0.002692519955723, 0.002614866709965, 0.002243383332699, 0.001625099807688,
  0.0008340000277607,-3.773966015683e-005,-0.0008904581816678,-0.001628321858935,
  -0.002170068537399,-0.002457878885174,-0.002463518940769,-0.002191000771575,
  -0.001675625098952,-0.000979473951791,-0.0001840063818204,0.0006194430553209,
    0.00134009074322, 0.001897935242432, 0.002232581375441, 0.002309752316706,
   0.002124727977462, 0.001702436588166, 0.001094172671625,0.0003714345354412,
  -0.0003824620724144,-0.001081927182552,-0.001648804395025,-0.002021043608063,
  -0.002159484463976,-0.002051909617759,-0.001714053852915,-0.001187399970697,
  -0.0005341530617535,0.0001700940346053,0.0008450573899064, 0.001414902007324,
   0.001816717844524, 0.002007451692169, 0.001968472205807, 0.001707352259361,
   0.001256634615237,0.0006698394874253,1.51168819153e-005,-0.0006326185503645,
  -0.001200260177529,-0.001624708605651,-0.001859892682784,-0.001881712729505,
  -0.001690505588926,-0.001310654963897,-0.0007875562771748,-0.0001821898336692,
  0.0004359374758081,0.0009967783231693, 0.001437635553179, 0.001710176474864,
   0.001785685734217, 0.001658087361999,  0.00134432389443,0.0008821832081319,
  0.0003257431066229,-0.0002609060267316,-0.0008110593792011,-0.001262929173157,
  -0.001566604693695,-0.001689509081698,-0.001619913542807,-0.001367971098744,
   -0.00096435264276,-0.0004564942272249,9.691918077088e-005,0.0006327587535864,
   0.001090600453375, 0.001419560513402, 0.001583899832972, 0.001566926640255,
   0.001372627252591, 0.001025017353202,0.0005651608205255,4.637334858482e-005,
  -0.000471984664052,-0.0009312439220447,-0.001280099064767,-0.001480278470023,
  -0.001510778475422,-0.001369996130125,-0.001075748373493,-0.000662993229998,
  -0.0001797401479118,0.0003185723698776,0.0007753768576072, 0.001139435809722,
   0.001370532472533, 0.001443946510268, 0.001353041138531, 0.001109865179029,
  0.0007435476605948,0.0002968685713127,-0.0001787718441969,-0.0006292098717137,
  -0.001003724431325,-0.001260689542849,-0.001372241687521,-0.001327236610309,
  -0.001132393599031,-0.0008112961683063,-0.0004016062785477,4.939414045981e-005,
  0.0004902001396648,0.0008710048098541, 0.001149270444968, 0.001294517902983,
   0.001291608600981, 0.001142351306884,0.0008650845543159,  0.00049248156588,
  6.766654928532e-005,-0.0003607235069961,-0.0007441460520211,-0.001039597082978,
  -0.001214476489868,-0.001250126335007,-0.001143859687071,-0.0009090602916808,
  -0.0005735645029173,-0.0001763208695659,0.0002370742750768,0.0006196511030836,
  0.0009283499725761, 0.001128903742724, 0.001199592625819, 0.001133626809817,
  0.0009397344742405,0.0006410710401375,0.0002724209505848,-0.0001238052728314,
  -0.0005024863868335,-0.0008208799640765,-0.001043485478653,-0.001145949692823,
  -0.001117772006685,-0.0009633162376786,-0.0007012320756299,-0.0003621644128773,
  1.477753506973e-005,0.0003865711881061,0.0007111421928723, 0.000952164542666,
   0.001083078817856, 0.001090054328523,0.0009734012200196,0.0007474487155687,
  0.0004387584302269,8.304885810578e-005,-0.0002789743536129,-0.0006062262349516,
  -0.0008619475253463,-0.001017780143258,-0.001056956426641,-0.0009760449995638,
  -0.0007852765293372,-0.0005072113027828,-0.0001741320848778,0.0001757515399894,
  0.0005026299315879, 0.000769666851468,0.0009470989563667,  0.00101559338651,
   0.000968302487336,0.0008115800504122,0.0005641020948369,0.0002546945577496,
  -8.106669250677e-005,-0.0004048932691365,-0.0006801978528287,-0.0008761687026186,
  -0.000971272837367,-0.000955554615273,-0.0008317327999062,-0.0006147213270713,
  -0.0003299042669566,-1.01079479251e-005,0.0003081144203387,0.0005887196767403,
  0.0008001906630205,0.0009191317742154,0.0009327945786139,0.0008404921680519,
  0.0006535233971813, 0.000393851710128,9.147207293015e-005,-0.0002189913935648,
  -0.0005023091428425,-0.0007265766923568,-0.0008668707086553,-0.0009079457685395,
  -0.0008459582240596,-0.0006887325144537,-0.0004548614697745,-0.0001714322671239,
  0.0001290301412474, 0.000412369749487,0.0006466068818741,0.0008056176593953,
  0.0008719755642469,0.0008389271845132,0.0007110038632293,0.0005034855133232,
  0.0002405186575585,-4.762517882524e-005,-0.0003280945261133,-0.0005691319936297,
  -0.0007437380628039,-0.0008326167143333,-0.0008263824018526,-0.0007264645549918,
  -0.0005449451520566,-0.0003030216376266,-2.861998481509e-005,0.0002469098811665,
  0.0004922876480979,0.0006799319062915, 0.000788978070457,0.0008076680249825,
  0.0007345413822382,0.0005785927355306,0.0003581042411321,9.857154737007e-005,
  -0.0001703084808872,-0.0004179675575462,-0.0006165056866925,-0.0007437632667723,
  -0.000785863113696,-0.0007386435883963,-0.0006081392621109,-0.0004097362661512,
  -0.0001664441555119,9.385388255083e-005,0.0003415135279201, 0.000548584946917,
  0.0006918864345851,0.0007556758126467,0.0007333027196499,0.0006279673458032,
  0.0004522166680501,0.0002265174625844,-2.318443651634e-005,-0.0002683832132351,
  -0.0004813269641381,-0.0006380923316214,-0.0007213357292545,-0.0007221418798567,
  -0.000641043619823,-0.0004878182224684,-0.0002803886542288,-4.265153343796e-005,
  0.0001981925712874,0.0004148295820856,0.0005828480103155,0.0006835633624083,
  0.0007060197437742,0.0006482485541194,0.0005173561559402,0.0003287214126283,
  0.0001041266151132,-0.0001306943680996,-0.0003490628606927,-0.0005263256420681,
  -0.0006426973079275,-0.0006854028095578,-0.000650145114741,-0.0005414588226864,
  -0.0003722088883202,-0.0001619954205168,6.503700070674e-005, 0.000283049859863,
  0.0004673687134921,0.0005973565012472,0.0006586402725818,0.0006447780906074,
  0.0005578547207429,0.0004082600114925,0.0002133799003923,-4.352368010742e-006,
  -0.0002201064591229,-0.0004094148504297,-0.0005510159621345,-0.0006291699271389,
  -0.0006354773523087,-0.0005697047790401,-0.0004398337181113,-0.0002610142329029,
  -5.388589660492e-005,0.0001578916920128,0.0003502500478117,0.0005015356433648,
  0.0005948557466364,0.0006200528655248,0.0005747166447764,0.0004644960683048,
  0.0003023123451696,0.0001069324995795,-9.928403486947e-005,-0.0002928608784143,
  -0.0004519580601987,-0.0005587507115605,-0.0006015112235171,-0.0005758057103906,
  -0.0004850399340862,-0.0003399249053158,-0.0001573092432362,4.187227291972e-005,
  0.0002348969474338,0.0003999486260215,0.0005184768854431,0.0005773856053754,
  0.0005703746570474,0.0004987116779174,0.0003709347375256,0.0002019367832466,
  1.113232577099e-005,-0.0001796725221163,-0.0003488691111121,-0.0004773953998078,
  -0.0005509784391475,-0.0005616208861375,-0.0005085672100596,-0.0003982348525229,
  -0.000243547239589,-6.231358948749e-005,0.0001247111305586,0.0002963107057782,
  0.0004331041612031,0.0005198432219937,0.0005469998467989,0.0005119219740896,
  0.0004189757385916,0.0002791131417514, 0.000108480044895,-7.334543851379e-005,
  -0.000245698255286,-0.000389072839115,-0.0004874317318415,-0.0005298943570681,
  -0.0005120428661418,-0.0004362736014457,-0.0003115874267699,-0.0001524165966624,
  2.293563268079e-005,0.0001945104068848,0.0003428510874536, 0.000451321057149,
  0.0005078583836068,0.0005064229132455,0.0004475337939527,0.0003382737774837,
  0.0001913374924914,2.365992335979e-005,-0.000145633686769,-0.0002973108416889,
  -0.0004143103822085,-0.0004835654854152,-0.0004975579789689,-0.0004550323348573,
  -0.0003612028629728,-0.0002270127466763,-6.796445054307e-005,9.777598445785e-005,
  0.0002513475610026,0.0003754468436888,0.0004561689993093, 0.000484672973117,
  0.0004580414225673,0.0003796783010425,0.0002587809190208,0.0001093566068782,
  -5.149098729561e-005,-0.0002054264391807,-0.0003350642298956,-0.0004258381734175,
  -0.0004677302390464,-0.0004562818476559,-0.0003931598465669,-0.0002858288153378,
  -0.0001467711438479,8.069357637412e-006,0.0001610050931041, 0.000294735064265,
  0.0003941912403708,0.0004483439278368, 0.000451316800775,0.0004031292547868,
  0.0003095477788675,0.0001815021450313,3.37091288054e-005,-0.0001169209703938,
  -0.0002533114470951,-0.0003600625217363,-0.000425281827685,-0.000441812095727,
  -0.0004081150339362,-0.0003283040826605,-0.0002117505043104,-7.187663332947e-005,
  7.52777258245e-005,0.0002130090535565,0.0003257245337168,0.0004008307033145,
  0.0004300135111815,0.0004102818153241,0.0003441493314275,0.0002394354925794,
  0.0001082278009455,-3.43990391261e-005,-0.0001722271507263,-0.0002896271144263,
  -0.0003734387567641,-0.0004143379707352,-0.0004079795727772,-0.0003553474934083,
  -0.0002627275125113,-0.0001408380917578,-3.717723507299e-006,0.0001330222095924,
  0.0002538404753622,0.0003451675504042,0.0003967906391151,0.0004031362194324,
   0.000363725697746,0.0002833468355931,0.0001713322325669,4.061451667878e-005,
  -9.389794604558e-005,-0.000216892432723,-0.0003145202859185,-0.0003758289675055,
  -0.0003941169453033,-0.0003675371422533,-0.0002994074918007,-0.0001976726610436,
  -7.410845646464e-005,5.717532947982e-005,0.0001812033956004,0.0002839916247957,
   0.000353969247364,0.0003834364491615,0.0003692547121292,0.0003133336505052,
  0.0002222258391362,0.0001065143378765,-2.05693356142e-005,-0.0001445059104713,
  -0.000251292487954,-0.0003288839552489,-0.0003686854446668,-0.0003663718132505,
  -0.0003224886700395,-0.0002422234954173,-0.0001349308090936,-1.290387017818e-005,
  0.0001098932997485,0.0002195642437645,0.0003037071498161,0.0003529664372477,
  0.0003619159519336,0.0003298160237405,0.0002605048561368, 0.000162099495797,
  4.589196798963e-005,-7.47952223611e-005,-0.0001862838614078,-0.0002759423997186,
  -0.0003337613896264,-0.0003533285924813,-0.0003326753291863,-0.0002743409228786,
  -0.0001851898282363,-7.547767669462e-005,4.219654675268e-005,0.0001544724218282,
  0.0002486049550812,0.0003140515477227,0.0003435108792195,0.0003338787181184,
  0.0002864283549772, 0.000206794358286,0.0001041525089266,-9.683692382552e-006,
  -0.000121772693501,-0.0002193704027585,-0.0002915176475724,-0.0003301338618952,
  -0.000331055301506,-0.0002943474870591,-0.0002244121861063,-0.0001293301372908,
  -2.005577178237e-005,9.096826229151e-005,0.0001911028271206,0.0002690789153796,
  0.0003161313616438,0.0003271231066419,0.0003009626495761,0.0002408521034461,
   0.000153756479744,4.97385325581e-005,-5.934599794905e-005,-0.0001610514980345,
  -0.0002439110019889,-0.0002985789093771,-0.0003190294677225,-0.0003030799109317,
  -0.0002527580598275,-0.0001739120107952,-7.566877322685e-005,3.076213683359e-005,
  0.0001332248871316,0.0002201458736814,0.0002817020323455,0.0003110679904769,
  0.0003050323312288,0.0002644935841403,0.0001941819487478,0.0001022644294688,
  -7.599066051793e-007,-0.0001031027273393,-0.0001931875246921,-0.0002608037007731,
  -0.0002984211414293,-0.0003018650178766,-0.0002709449443338,-0.0002092877563914,
  -0.0001240749496613,-2.504766105844e-005,7.644837053384e-005,0.0001689231964887,
  0.0002418757652055,0.0002871562924388,0.0002997034706766,0.0002782795571879,
  0.0002254230249727,0.0001473146351306,5.288676369314e-005,-4.702223498605e-005,
  -0.0001410918388166,-0.0002186175145677,-0.0002709094488022,-0.0002920859098538,
  -0.0002799117651791,-0.0002358515525603,-0.0001650815757556,-7.568871614675e-005,
  2.205477123225e-005,0.0001170680166212, 0.000198523432163,0.0002572708507888,
  0.0002866733247944,0.0002835524207055,0.0002483300151574,0.0001851761062887,
  0.0001013160397131,6.399154230291e-006,-8.879942317714e-005,-0.0001734135645466,
  -0.0002379160503128,-0.0002749925695598,-0.0002805711985829,-0.0002540649525968,
  -0.000198632128256,-0.0001206037751487,-2.895950856092e-005,6.590858118389e-005,
  0.0001531603335627, 0.000222965588642, 0.000267389450895,0.0002815120930083,
  0.0002637614187387,0.0002162946604961,0.0001445304306394,5.674064519087e-005,
  -3.711304101597e-005,-0.0001262978383697,-0.0002007357803705,-0.0002519483868729,
  -0.0002742047557118,-0.000264976809984,-0.0002254154169817,-0.0001600092756554,
  -7.627826157228e-005,1.629371783859e-005,0.0001071323453577,0.0001859781273653,
   0.000243841874425,0.0002742401049468,0.0002737001547542,0.0002423828625967,
  0.0001838304216829, 0.000104779448141,1.418452494642e-005,-7.759894812583e-005,
  -0.000160190323507,-0.0002241585360933,-0.0002622910230011,-0.000270215286515,
  -0.0002470750212103,-0.0001954539987557,-0.0001212486766655,-3.282573143834e-005,
  5.974206222874e-005,0.0001460144480684,0.0002161618854874,0.0002622815623967,
  0.0002790910445566,0.0002647288871196,0.0002207586787457,0.0001522161569959,
  6.681212450055e-005,-2.570767617267e-005,-0.0001148852330731,-0.000190530703101,
   -0.00024406615413,-0.000269315817499,-0.0002633907359186,-0.0002268326477234,
  -0.0001637431872397,-8.114876898443e-005,1.162255924704e-005, 0.000104149767773,
    0.00018593176766,0.0002477538384072,0.0002825318878458,0.0002863358729348,
  0.0002586164153517,0.0002024992964241,0.0001242217917037,3.266222503737e-005,
  -6.188876466135e-005,-0.0001486353521634,-0.0002177480037301,-0.0002612261556932,
  -0.0002740364185025,-0.0002544828530912,-0.000204603904318,-0.0001297682511644,
  -3.828444010916e-005,5.972521649542e-005,0.0001532475876939,0.0002318119594964,
  0.0002864835280864,0.0003110691453449,0.0003026237940001, 0.000262036498402,
  0.0001936843619856,0.0001052456288287,6.566528162453e-006,-9.114583661909e-005,
  -0.0001768486060104,-0.0002406152549015,-0.0002750529450091,-0.0002758351560862,
  -0.0002425225516507,-0.0001783469569312,-9.014384322336e-005,1.26202505296e-005,
  0.0001186583212605,0.0002163394345175,  0.00029473327336,0.0003450969088837,
  0.0003616078585158,0.0003422932504782,0.0002890436598547,0.0002076982214118,
  0.0001071468304469,-1.294282685551e-006,-0.0001054831769369,-0.0001934057143242,
  -0.0002548832643051,-0.0002823591594886,-0.0002721132383516,-0.0002243591625441,
  -0.0001436441128523,-3.801297843022e-005,8.146153352585e-005,0.0002021954749789,
  0.0003111704670994,0.0003966095342398,0.0004490362569301,0.0004626139503135,
  0.0004355398735289,0.0003706189751258,0.0002747257783376,0.0001584081980343,
  3.451094620924e-005,-8.28779936978e-005,-0.0001803103113176,-0.0002460169027027,
  -0.0002716772395347,-0.0002529003799192,-0.0001901973055124,-8.860682269264e-005,
  4.237633677848e-005,0.0001901371887091,0.0003398051025826,0.0004762262121627,
  0.0005851973790915,0.0006553067269399,0.0006789832656708,0.0006535640499629,
  0.0005814824062309, 0.000470366166444,0.0003320536338166,0.0001817519637354,
  3.624060606272e-005,-8.759170501141e-005,-0.0001747595991231,-0.0002134470238152,
  -0.0001967366004488,-0.0001228933954039,3.758454014849e-006, 0.000173663755527,
  0.0003724200105849,0.0005824902299453,0.0007845247653491,0.0009596696672741,
   0.001091044635132, 0.001165887188528, 0.001176658983486, 0.001122023034862,
   0.001007187470725,0.0008434979007928, 0.000647536990799,0.0004398367877383,
  0.0002428450071943,7.910124832792e-005,-3.101504924518e-005,-7.113396057954e-005,
  -3.069808013259e-005,9.433742940151e-005,0.0003002777090793,0.0005767303440273,
   0.000906420003473, 0.001267200815596, 0.001633309111382, 0.001977682211829,
   0.002273797044343, 0.002498220322787, 0.002632001634513, 0.002662359836389,
   0.002583914178368, 0.002398079555398, 0.002114143817666, 0.001747222553177,
   0.001317790030862,0.0008499121523355,0.0003692853100522,-9.870104057612e-005,
  -0.0005304116468735,-0.0009058633331502,-0.001210497302095,-0.001433345510182,
  -0.001571996866145,-0.001626534048012,-0.001604362021221,-0.001516508677178,
  -0.001376377461198,-0.001199156024359,-0.001001103118564,-0.0007969714041417,
  -0.000599954756071,-0.0007612526240555
};
