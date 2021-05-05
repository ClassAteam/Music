#include "exchange.h"


bool exchange::s14_2430{};//perekl knopochn vkluch AKK1
bool exchange::s15_2430{};//perekl knopochn vkluch AKK2
bool exchange::s1_2430{};//perekl gen vsu(27)
bool exchange::s4_2430{};//perekl g1 (27)
bool exchange::s5_2430{};//perekl g2(27)
bool exchange::s8_2430{};//perekl g3(27)
bool exchange::s11_2430{};//perekl g4(27)
bool exchange::s2_2430{};//perekl knopochn vkluch rap1
bool exchange::s9_2430{};//perekl knopochn vkluch rap2
bool exchange::s7_2430{};//perekl knopochn SOED SETEY
bool exchange::s3_2430{};//perekl knopochn vklucheniya CHASTICHNIY REZHIM(27 LEV)
bool exchange::s10_2430{};//perekl knopochn vklucheniya CHASTICHNIY REZHIM(27 PRAV)
bool exchange::s17_2420{};//knopka FAZI A
bool exchange::s18_2420{};//knopka FAZI B
bool exchange::s19_2420{};//knopka FAZI C
bool exchange::s21_2420{};//vikl preobrazovatelya #3(POS1000)
bool exchange::s15_2420{};//vikluch PTS PREOBR 1
bool exchange::s1_7710{};//vikluchatel ESUD SKU1
bool exchange::s2_7710{};//vikluchatel ESUD SKU2
bool exchange::s3_7710{};//vikluchatel ESUD SKU3
bool exchange::s4_7710{};//vikluchatel ESUD SKU4
bool exchange::s2_2420{};//perekluch SET' 115/200V SOED SETEY
bool exchange::s9_2420{};//perekl SET' 115/200 RAP
bool exchange::s1_2420{};//perekl vkluch generatora peremnnogo toka GEN1
bool exchange::s5_2420{};//perekl vkluch generatora peremnnogo toka GEN2
bool exchange::s10_2420{};//perekl vkluch generatora peremnnogo toka GEN3
bool exchange::s13_2420{};//perekl vkluch generatora peremnnogo toka GEN4
bool exchange::s4_2420{};//perekluch vkluch chastichnogo rezhima levoy seti perem toka CHASTICHNIY REZHIM SET LEVAYA
bool exchange::s12_2420{};//perekl vkl chastichn rezhima pravoy seti perem toka CHASTICHNIY REZHIM SET PRAVAYA
bool exchange::s8_2420{};//knopochniy perekl vkluch gener perem toka VSU GEN VSU
bool exchange::s1_3030{};//knopka KONTROL' PPD
bool exchange::s1_3080{};//viklyuchatel' SIGNAL OBLED LEVIY
bool exchange::s2_3030{};//viklyuchatel' OBOGREV PPD
bool exchange::s2_3040{};//viklyuchatel' OBOGREV STEKL LEVOE
bool exchange::s2_3080{};//viklyuchatel' SIGNAL OBLED PRAVIY
bool exchange::s3_3080{};//knopka CO-121VM KONTR
bool exchange::s4_3040{};//viklyuchatel' OBOGREV STEKL LOBOVOE
bool exchange::s6_3020{};//viklyuchatel' OBOGREV V/3 PODKLYUCHENIE NA ZEMLE
bool exchange::s6_3040{};//viklyuchatel' OBOGREV STEKL PRAVOE
bool exchange::s8_3040{};//knopka OBOGREV STEKOL KONTROL'
bool exchange::s2_3020{};//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 1
bool exchange::s3_3020{};//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 2
bool exchange::s4_3020{};//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 3
bool exchange::s5_3020{};//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 4
bool exchange::POSK1dv{};//priznak otkritiya stop-krana 1 dvigatelya
bool exchange::POSK2dv{};//priznak otkritiya stop-krana 1 dvigatelya
bool exchange::POSK3dv{};//priznak otkritiya stop-krana 1 dvigatelya
bool exchange::POSK4dv{};//priznak otkritiya stop-krana 1 dvigatelya
bool exchange::s10_2920{};//pereklyuchatel' TNU GS2
bool exchange::s10_7322{};//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'4
bool exchange::s11_2920{};//
bool exchange::s12_2920{};//
bool exchange::s1_12360{};//
bool exchange::s1_2110{};//pereklyuchatel' "OTBOR DV1"
bool exchange::s1_2120{};//pereklyuchatel' "MAGISTRAL'1"
bool exchange::s1_3241{};//
bool exchange::s1_3364{};
bool exchange::s1_9921{};//
bool exchange::s2_12360{};//
bool exchange::s2_2110{};//pereklyuchatel' "OTBOR DV2"
bool exchange::s2_2120{};//pereklyuchatel' "MAGISTRAL'21"
bool exchange::s2_3240{};//
bool exchange::s2_3364{};
bool exchange::s2_9921{};//
bool exchange::s3_12360{};//
bool exchange::s3_2110{};//pereklyuchatel' "OTBOR DV3"
bool exchange::s3_2120{};//pereklyuchatel' otkaz "MAGISTRAL'1"
bool exchange::s3_3240{};//
bool exchange::s3_3364{};
bool exchange::s3_9921{};//
bool exchange::s4_2110{};//pereklyuchatel' "OTBOR DV4"
bool exchange::s4_2120{};//pereklyuchatel "OTKAZ MAGISTRAL'2:
bool exchange::s4_3364{};
bool exchange::s5_2110{};//
bool exchange::s5_2120{};//pereklyuchatel' "KONTROL' FILTRA"
bool exchange::s5_3364{};
bool exchange::s6_2120{};//pereklyuchatel' :KOLTSEVANIE MAGISTRALI"
bool exchange::s6_3364{};
bool exchange::s7_3364{};
bool exchange::s7_7322{};//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'1
bool exchange::s7_pp73{};//pereklyuchatel' ZASLONKA OTBORA PP-73
bool exchange::s8_3364{};
bool exchange::s8_7322{};//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'2
bool exchange::s9_2920{};//pereklyuchatel' TNU GS1
bool exchange::s9_7322{};//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'3
double exchange::X_ped11{};//engine1 speed
double exchange::X_ped12{};//engine1 speed
double exchange::X_ped21{};//engine1 speed
double exchange::X_ped22{};//engine1 speed
double exchange::alpha_rud_1dv{};//RUD position 1st engine
double exchange::alpha_rud_2dv{};//RUD position 2nd engine
double exchange::alpha_rud_3dv{};//RUD position 3rd engine
double exchange::alpha_rud_4dv{};//RUD position 4th engine
double exchange::eng1_spd{};//engine1 speed
double exchange::eng2_spd{};//engine2 speed
double exchange::eng3_spd{};//engine3 speed
double exchange::eng4_spd{};//engine4 speed
double exchange::pgat{};//davlenie gidroakkumulyatora tormozov
double exchange::speed{};

//////////////////////////////////////////////////////////Output
///

bool exchange::F32_3250{};
bool exchange::s1_2112{};
bool exchange::s4_2112{};
bool exchange::s1_2830{};//vikluchatel AVAR SLIV TOPLIVA BAKI PEREDNIE
bool exchange::s2_2830{};//vikluchatel AVAR SLIV TOPLIVA BAKI ZADNIE
bool exchange::s1_3650{};//vikluchatel' NADDUV BLOKOV PEREDN
bool exchange::s2_3650{};//vikluchatel' NADDUV BLOKOV ZADNIE
bool exchange::K24_3230{};
bool exchange::K25_3230{};
bool exchange::K26_3230{};
bool exchange::K27_3230{};
bool exchange::K32_3230{};
bool exchange::K34_3230{};
bool exchange::K35_3230{};
bool exchange::P1OBLOP{};
bool exchange::P1OBPOP{};
bool exchange::P2OBLOP{};//priznak 2 obzhatiya levoy opori shassi
bool exchange::P2OBPOP{};//priznak 2 obzhatiya pravoy opori shassi
bool exchange::PRD1dv{};//engine1 work sign
bool exchange::PRD2dv{};//engine2 work sign
bool exchange::PRD3dv{};//engine3 work sign
bool exchange::PRD4dv{};//engine4 work sign
bool exchange::S18_2930{};
bool exchange::S1_3230{};
bool exchange::S34_3230{};
bool exchange::S35_3230{};
bool exchange::S36_3230{};
bool exchange::S38_3230{};
bool exchange::S39_3230{};
bool exchange::S55_3230{};
bool exchange::S56_3230{};
bool exchange::S57_3230{};
bool exchange::S58_3230{};
bool exchange::pk70_kontrt{};
bool exchange::pk70_pgo{};
bool exchange::pk70_vkl{};
bool exchange::pk70_zgo{};
bool exchange::prvsu{};
bool exchange::ptstoyan{};
bool exchange::puvzl{};
bool exchange::puvzp{};
bool exchange::s1_2152{};//
bool exchange::s1_2153{};//
bool exchange::s1_2158{};//
bool exchange::s1_2159{};//
bool exchange::s1_3250{};//
bool exchange::s2_2151{};//
bool exchange::s2_2153{};//
bool exchange::s2_2159{};//
bool exchange::s3_2151{};//
bool exchange::s4_2151{};//
bool exchange::s4_3250{};//
bool exchange::s5_2151{};//
bool exchange::s6_2151{};//
double exchange::delta_z{};//flaps position
double exchange::fpos{};
double exchange::fpts{};
double exchange::frap{};
double exchange::fshav[4]{};//frequency of emergency buses
double exchange::fshg[5]{};//frequency of 4 generators and vsu bases
double exchange::fshp[2]{};//frequency of switching buses
double exchange::fshpos[2]{};//frequency of convreter3's buses
double exchange::fshpts{};
double exchange::pgs1{};//presure in hydrosystem1
double exchange::pgs2{};//presure in hydrosystem2
double exchange::pgs3{};//presure in hydrosystem3
double exchange::pgs4{};//presure in hydrosystem4
double exchange::tke_vh{};//regulyator temperaturi v kabine ekipazha
double exchange::tnv{};
double exchange::ugvsuP[3]{};//vsu generator voltage by phases
double exchange::upos{};
double exchange::uptsP[3];
double exchange::upts{};//pts own voltage
double exchange::urapP[3]{};//rap bus voltahe by phases
double exchange::urap{};
double exchange::ush1dpl{};//voltage at extra power bus1 left one
double exchange::ush1dpp{};//voltage at extra power bus1 right one
double exchange::ush1l{};//bus1 left voltage
double exchange::ush1p{};//bus1 right voltage
double exchange::ush2dpl{};//voltage at extra power bus2 left one
double exchange::ush2dpp{};//voltage at extra power bus2 right one
double exchange::ush2l{};//bus2 left voltage
double exchange::ush2p{};//bus1 right voltage
double exchange::ushak1{};//accumulator1 bus voltage
double exchange::ushak2{};//accumulator2 bus voltage
double exchange::ushal{};
double exchange::ushap{};
double exchange::ushavP[4][3]{};//emergency buses voltages by phases
double exchange::ushgP[4][3]{};//a generator bus voltages by phases
double exchange::usho1l{};//switching off bus1 left
double exchange::usho1p{};//switching off bus1 right
double exchange::usho2l{};//switching off bus2 left
double exchange::usho2p{};//switching off bus2 right
double exchange::ushpP[2][3]{};//switching bus voltages by phases
double exchange::ushpos[2]{};// voltage of converter3's buses
double exchange::ushpp{};//switching bus right voltage
double exchange::ushpts[3]{};// voltage of converter1's bus by phases
double exchange::ushzvsu{}; //vsu starting bus
int exchange::s20_2430{};
int exchange::s17_2430{};//perekl amppermetra
int exchange::s16_2430{};//perekl voltmetra
int exchange::s13_2430{};//perekl ZEMLYA-VOZDUH
int exchange::s1_3240{};//pereklyuchatel' "TORMOZA AVT NORM-PONIZH-SLABO"
int exchange::s1_2151{};
int exchange::s1_3020{};
int exchange::s7_3040{};
int exchange::s2_3230{};
int exchange::S31_3230{};
