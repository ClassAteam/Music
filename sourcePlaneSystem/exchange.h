#pragma once

struct exchange
{
    static bool F32_3250;
    static bool s1_2112;//vilkuchatel' "STRUYANAYA ZASHITA DVIG LEV"
    static bool s4_2112;//vilkuchatel' "STRUYANAYA ZASHITA DVIG PRAV"
    static bool s1_2830;//vikluchatel AVAR SLIV TOPLIVA BAKI PEREDNIE
    static bool s2_2830;//vikluchatel AVAR SLIV TOPLIVA BAKI ZADNIE
    static bool s1_3650;//vikluchatel' NADDUV BLOKOV PEREDN
    static bool s2_3650;//vikluchatel' NADDUV BLOKOV ZADNIE
    static bool K24_3230;//priznak rele obzhatogo polozheniya pravoy stoyki shassi
    static bool K25_3230;//priznak rele signalizatsii obzhatogo polozheniya levoy opori shassi kanal 2
    static bool K26_3230;//priznak rele signalizatsii obzhatogo polozheniya levoy opori shassi kanal 2
    static bool K27_3230;//priznak rele obzhatiya stoyki shassi pravogo
    static bool K32_3230;//priznak rele signalizatsii ubrannogo polozheniya levoy opori shassi
    static bool K34_3230;//priznak rele signalizatsii ubrannogo polozheniya pravoy opori shassi
    static bool K35_3230;//priznak rele signalizattsii vipushennogo polozheniya peredney opori shassi
    static bool P1OBLOP;//priznak 1 obzhatiya levoy opori shassi
    static bool P1OBPOP;//priznak 1 obzhatiya pravoy opori shassi
    static bool P2OBLOP;//priznak 2 obzhatiya levoy opori shassi
    static bool P2OBPOP;//priznak 2 obzhatiya pravoy opori shassi
    static bool PRD1dv;//engine1 work sign
    static bool PRD2dv;//engine2 work sign
    static bool PRD3dv;//engine3 work sign
    static bool PRD4dv;//engine4 work sign
    static bool S18_2930;//knopka proverki lamp na shitke nazemnoy proverki
    static bool S1_3230;//viklyuchatel' "OTKLYUCHENIE OSNOVN UPRAVLENIYA SHASSI"
    static bool ptstoyan;
    static bool pvvll;//priznak vklyucheniya ventilyatora levogo letchika,
    static bool pvvpl;//priznak vklyucheniya ventilyatora pravogo letchika,
    static bool pvvshn;//priznak vklyucheniya ventilyatora shturmana navigatora
    static bool pvvsho;//priznak vklyucheniya ventilyatora shturmana operatora
    static bool zakr_m1;//priznak vklyucheniya tablo "ZAKR"(magistral'1)
    static bool zakr_om1;//priznak vklyucheniya tablo "ZAKR"(otkaz magistrali1)
    static bool s1_3030;//knopka KONTROL' PPD
    static bool s1_3080;//viklyuchatel' SIGNAL OBLED LEVIY
    static bool s2_3030;//viklyuchatel' OBOGREV PPD
    static bool s2_3040;//viklyuchatel' OBOGREV STEKL LEVOE
    static bool s2_3080;//viklyuchatel' SIGNAL OBLED PRAVIY
    static bool s3_3080;//knopka CO-121VM KONTR
    static bool s4_3040;//viklyuchatel' OBOGREV STEKL LOBOVOE
    static bool s6_3020;//viklyuchatel' OBOGREV V/3 PODKLYUCHENIE NA ZEMLE
    static bool s6_3040;//viklyuchatel' OBOGREV STEKL PRAVOE
    static bool s8_3040;//knopka OBOGREV STEKOL KONTROL'
    static bool s2_3020;//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 1
    static bool s3_3020;//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 2
    static bool s4_3020;//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 3
    static bool s5_3020;//vikluchateli OTKLUCHENIE OBOGREVA VOZUHOZABORNIKOV 4
    static bool POSK1dv;//priznak otkritiya stop-krana 1 dvigatelya
    static bool POSK2dv;//priznak otkritiya stop-krana 1 dvigatelya
    static bool POSK3dv;//priznak otkritiya stop-krana 1 dvigatelya
    static bool POSK4dv;//priznak otkritiya stop-krana 1 dvigatelya
    static bool S55_3230;//pereklyuchatel' "IMITAZIYA" "SHASSI NE OBZHATO OPORA LEVAYA 1"
    static bool S56_3230;//pereklyuchatel' "IMITAZIYA" "SHASSI NE OBZHATO OPORA PRAVAYA 1"
    static bool S57_3230;//pereklyuchatel' "IMITAZIYA" "SHASSI NE OBZHATO OPORA LEVAYA 2"
    static bool S58_3230;//pereklyuchatel' "IMITAZIYA" "SHASSI NE OBZHATO OPORA PRAVAYA 2"
    static bool pk70_kontrt;//priznak signala "Kontrol' T"
    static bool pk70_pgo;//priznak ispravnosti BUVK #2(zadniy gruzovoy otsek)
    static bool pk70_vkl;//priznak vklyucheniya apparaturi K-70M
    static bool pk70_zgo;//priznak ispravnosti BUVK #2(zadniy gruzovoy otsek)
    static bool prvsu;//priznak raboti VSU
    static bool puvzl;//priznak podklyucheniya ustraoystva vozdushnogo zapuska levogo
    static bool puvzp;//priznak podklyucheniya ustraoystva vozdushnogo zapuska pravogo
    static bool s10_2420;//perekl vkluch generatora peremnnogo toka GEN3
    static bool s10_2430;//perekl knopochn vklucheniya CHASTICHNIY REZHIM(27 PRAV)
    static bool s10_2920;//pereklyuchatel' TNU GS2
    static bool s10_7322;//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'4
    static bool s11_2430;//perekl g4(27)
    static bool s11_2920;//pereklyuchatel' TNU GS3
    static bool s12_2420;//perekl vkl chastichn rezhima pravoy seti perem toka CHASTICHNIY REZHIM SET PRAVAYA
    static bool s12_2920;//pereklyuchatel' TNU GS4
    static bool s13_2420;//perekl vkluch generatora peremnnogo toka GEN4
    static bool s14_2430;//perekl knopochn vkluch AKK1
    static bool s15_2420;//vikluch PTS PREOBR 1
    static bool s15_2430;//perekl knopochn vkluch AKK2
    static bool s17_2420;//knopka FAZI A
    static bool s18_2420;//knopka FAZI B
    static bool s19_2420;//knopka FAZI C
    static bool s1_12360;//pereklyuchatel' "MPU #1 RUCHNOY"
    static bool s1_2110;//pereklyuchatel' "OTBOR DV1"
    static bool s1_2120;//pereklyuchatel' "MAGISTRAL'1"
    static bool s1_2142;//pereklyuchatel' "ZASHITNOE SNARYAZHENIE"
    static bool s1_2152;//pereeklyuchatel' "ZASHITNOE SNARYAZHENIE"
    static bool s1_2153;//pereeklyuchatel' "GO PEREDN"
    static bool s1_2158;//pereeklyuchatel' "TO PEREDNIY I NOSOVOY"
    static bool s1_2159;//pereeklyuchatel' vklyucheniya THU3
    static bool s1_2420;//perekl vkluch generatora peremnnogo toka GEN1
    static bool s1_2430;//perekl gen vsu(27)
    static bool s1_3241;//viklyuchatel "TORMOZA REZERV"
    static bool s1_3250;//viklyuchatel' "POVOROT KOLES PITANIE"
    static bool s1_3364;//knopka-tablo ZSO levogo letchika
    static bool s1_7710;//vikluchatel ESUD SKU1
    static bool s1_9921;//knopka "VIPUSK PARASHYUTA" levogo letchika
    static bool s21_2420;//vikl preobrazovatelya #3(POS1000)
    static bool s2_12360;//pereklyuchatel' "MPU #2 RUCHNOY"
    static bool s2_2110;//pereklyuchatel' "OTBOR DV2"
    static bool s2_2120;//pereklyuchatel' "MAGISTRAL'21"
    static bool s2_2151;//pereklyuchatel' :KABINA EKIPAZHA"
    static bool s2_2153;//pereeklyuchatel' "GO ZADNIY"
    static bool s2_2158;//pereeklyuchatel' "GO ZADNIY"
    static bool s2_2159;//pereeklyuchatel' vklyucheniya THU4
    static bool s2_2420;//perekluch SET' 115/200V SOED SETEY
    static bool s2_2430;//perekl knopochn vkluch rap1
    static bool s2_3240;//pereklyuchatel' "TORMOZA STOYAN-START"
    static bool s2_3364;//knopka-tablo ZSO pravogo letchika
    static bool s2_7710;//vikluchatel ESUD SKU2
    static bool s2_9921;//knopka "VIPUSK PARASHYUTA" pravogo letchika
    static bool s3_12360;//pereklyuchatel' "MPU #3 RUCHNOY"
    static bool s3_2110;//pereklyuchatel' "OTBOR DV3"
    static bool s3_2120;//pereklyuchatel' otkaz "MAGISTRAL'1"
    static bool s3_2151;//vikluichatel' "VENITILYATOR" levogo letchika
    static bool s3_2430;//perekl knopochn vklucheniya CHASTICHNIY REZHIM(27 LEV)
    static bool s3_3240;//pereklyuchatel "TORMOZA FORSIR"
    static bool s3_3364;//knopka-tablo ZSO shturmana-operatora
    static bool s3_7710;//vikluchatel ESUD SKU3
    static bool s3_9921;//knopka "SBROS PARASHYUTA"
    static bool s4_2110;//pereklyuchatel' "OTBOR DV4"
    static bool s4_2120;//pereklyuchatel "OTKAZ MAGISTRAL'2:
    static bool s4_2151;//vikluichatel' "VENITILYATOR" pravogo letchika
    static bool s4_2420;//perekluch vkluch chastichnogo rezhima levoy seti perem toka CHASTICHNIY REZHIM SET LEVAYA
    static bool s4_2430;//perekl g1 (27)
    static bool s4_3250;//viklyuchatel' "POVOROT KOLES RULENIE"
    static bool s4_3364;//knopka-tablo ZSO shturmana-navigatora
    static bool s4_7710;//vikluchatel ESUD SKU4
    static bool s5_2110;//pereklyuchatel' "KOL'TSEVANIE OTBOROV"
    static bool s5_2120;//pereklyuchatel' "KONTROL' FILTRA"
    static bool s5_2151;//vikluichatel' "VENITILYATOR" shturmana operatora
    static bool s5_2420;//perekl vkluch generatora peremnnogo toka GEN2
    static bool s5_2430;//perekl g2(27)
    static bool s5_3364;//knopka KONTR SIGNAL lev letchika
    static bool s6_2120;//pereklyuchatel' :KOLTSEVANIE MAGISTRALI"
    static bool s6_2151;//vikluichatel' "VENITILYATOR" shturmana navigatora
    static bool s6_3364;//knopka KONTR SIGNAL prav letchika
    static bool s7_2430;//perekl knopochn SOED SETEY
    static bool s7_3364;//knopka KONTR SIGNAL shturmana-operatora
    static bool s7_7322;//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'1
    static bool s7_pp73;//pereklyuchatel' ZASLONKA OTBORA PP-73
    static bool s8_2420;//knopochniy perekl vkluch gener perem toka VSU GEN VSU
    static bool s8_2430;//perekl g3(27)
    static bool s8_3364;//knopka KONTR SIGNAL shturmana-navigatora
    static bool s8_7322;//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'2
    static bool s9_2420;//perekl SET' 115/200 RAP
    static bool s9_2430;//perekl knopochn vkluch rap2
    static bool s9_7322;//Vikl. GLAVNIY VIKLYUCHATEL' DVIGATEL'3

    static double X_ped11;//otklonenie levoy pedali levogo letchika
    static double X_ped12;//otklonenie pravoy pedali levogo letchika
    static double X_ped21;//otklonenie levoy pedali pravogo letchika
    static double X_ped22;//otklonenie pravoy pedali pravogo letchika
    static double alpha_rud_1dv;//RUD position 1st engine
    static double alpha_rud_2dv;//RUD position 2nd engine
    static double alpha_rud_3dv;//RUD position 3rd engine
    static double alpha_rud_4dv;//RUD position 4th engine
    static double eng1_spd;//engine1 speed
    static double eng2_spd;//engine2 speed
    static double eng3_spd;//engine3 speed
    static double eng4_spd;//engine4 speed
    static double pgat;//davlenie v gidroakkumulyatore tormoznoy sistemi
    static double speed;
    static double delta_z;//flaps position
    static double fpos;//chastota POS
    static double fpts;//chastota PTS
    static double frap;//chastota RAP
    static double fshav[4];//frequency of emergency buses
    static double fshg[5];//frequency of 4 generators and vsu buses
    static double fshp[2];//frequency of switching buses
    static double fshpos[2];//frequency of convreter3's buses
    static double fshpts;//chastota na shine pts
    static double pgs1;//presure in hydrosystem1
    static double pgs2;//presure in hydrosystem2
    static double pgs3;//presure in hydrosystem3
    static double pgs4;//presure in hydrosystem4
    static double tke_vh;//polozhenie zadatchika temperaturi v kabine ekipazha
    static double tnv;//temperatura naruzhnogo vozduha v C
    static double ugvsuP[3];//vsu generator voltage by phases
    static double upos;//napryazhenie POS
    static double upts;//pts own voltage
    static double uptsP[3];//napryazhenie na PTS po fazam
    static double urap;//chastota RAP
    static double urapP[3];//rap bus voltage by phases
    static double ush1dpl;//voltage at extra power bus1 left one
    static double ush1dpp;//voltage at extra power bus1 right one
    static double ush1l;//bus1 left voltage
    static double ush1p;//bus1 right voltage
    static double ush2dpl;//voltage at extra power bus2 left one
    static double ush2dpp;//voltage at extra power bus2 right one
    static double ush2l;//bus2 left voltage
    static double ush2p;//bus1 right voltage
    static double ushak1;//accumulator1 bus voltage
    static double ushak2;//accumulator2 bus voltage
    static double ushal;//napryazhenie na shine avariynoy levoy
    static double ushap;//napryazhenie na shine avariynoy pravloy
    static double ushavP[4][3];//emergency buses voltages by phases
    static double ushgP[4][3];//a generator bus voltages by phases
    static double usho1l;//switching off bus1 left
    static double usho1p;//switching off bus1 right
    static double usho2l;//switching off bus2 left
    static double usho2p;//switching off bus2 right
    static double ushpP[2][3];//switching bus voltages by phases
    static double ushpos[2];// voltage of converter3's buses
    static double ushpp;//switching bus right voltage
    static double ushpts[3];// voltage of converter1's bus by phases
    static double ushzvsu; //vsu starting bus

    static int s7_3040;//pereklyuchatel OTKL-LEV-BOL-PRAV
    enum class s7_3040{otkl, lev, lob, prav};
    static int s1_3020;//perekluchatel T NARUZH VOZDUH
    enum class s1_3020{neytr, minus6minus15, zerominus6, minus15};
    static int s1_2151;//pereklyuchatel' "REGULIR T KABINI EKIPAZHA"
    enum class s1_2151{neytr, hol, gor, avtomat};
    static int s1_3240;//pereklyuchatel' "TORMOZA AVT NORM-PONIZH-SLABO"
    enum class s1_3240{otkl, slabo, ponizh, norm};
    static int s13_2430;//perekl ZEMLYA-VOZDUH
    enum class s13_2430{ground, air};
    static int s16_2430;//perekl voltmetra
    enum class s16_2430{akk1, akk2, avar1, avar2, sh1lev, sh2lev, sh1prav, sh2prav};
    static int s17_2430;//perekl amppermetra
    enum class s17_2430{akk1_rap1, akk2_rap2, vsu};
    static int s20_2430;//??
    enum class s20_2430{apsh1, apsh2, apsh3, apsh5, apsh6};
    static int S31_3230;//??
    enum class s31_3230{opora_pered, opora_lev, opora_prav};
//    static int s2_3230;//pereklyuchatel' "SHASSI" "VIPUSK - UBORKA"
//    enum class s2_3230{release, intake};
};
