#pragma once
#include "wind_functions.h"
#include "algorithms.h"
#include "exchange.h"
#include "bss.h"
#include "uks.h"

constexpr auto amountOfHydroSys = 4;

extern bss bss_inst;
extern uks uks_inst;

extern double TICK;
extern const double ts;

class hydro_int
{
public:
    bool s1_2910{};//perekluchatel' PRINUD PODKL G/NASOSOV
    bool s2_2910{};//knopka KONTROL' RAZGRUZKI
    bool s3_2910{};//perekluchateli VIBOR NASOSA GS1,2
    bool s4_2910{};//perekluchateli VIBOR NASOSA GS3,4
    bool S5_2910{};//perekluchatel' EKSTRENNOE OTKL G/NASOSOV DV2 i 3
    bool S6_2910{};//perekluchatel' EKSTRENNOE OTKL G/NASOSOV DV1 i 4
    bool S7_2910{};//perekluchatel' OTKL G/NASOSOV DV2
    bool EZR1_34{};//priznak zapuska 1 dvigatelya
    bool EZR2_34{};//priznak zapuska 2 dvigatelya
    bool EZR3_34{};//priznak zapuska 3 dvigatelya
    bool EZR4_34{};//priznak zapuska 4 dvigatelya
    bool PBI4M_1{};//priznak signala polnogo zakritiya stvorok gruzovih otsekov
    bool PAPD_26{};
    bool PAPD_27{};
    bool PAPD_30{};
    bool PAPD_31{};
    bool otkaz_gs1{};//otkaz gs1
    bool otkaz_gs2{};//otkaz gs2
    bool otkaz_gs3{};//otkaz gs3
    bool otkaz_gs4{};//otkaz gs4
    bool pntnugs1{};
    bool pntnugs2{};
    bool pntnugs3{};
    bool pntnugs4{};
    bool PK{};
    bool F14_2930{true};
    bool F15_2930{true};
    bool F1_2930{true};
    bool H10_2930{};//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS1
    bool H11_2930{};//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS2
    bool H12_2930{};//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS3
    bool H13_2930{};//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS4
    bool H1_2910{};//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS2
    bool H2_2910{};//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS1
    bool H4_2910{};//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS3
    bool H5_2910{};//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS4
    bool PKL{};
    bool PKL1{};
    bool S13_2920{};//knopka kontrolya signalizatsii TNU SIGNAL
    bool S18_2920{};//knopka proverki lamp na shitke nazemnoy proverki
    bool H1_2935{};//priznak vihodnogo signala dlya svetodioda NASOS TZHT
    bool K1_2935{};
    bool K2_2935{};
    bool K3_2935{};
    bool K4_2935{};
    bool K5_2935{};
    bool K6_2935{};
    bool K7_2935{};
    bool K8_2935{};
    bool K9_2935{};
    bool K10_2935{};
    bool K11_2935{};
    bool K12_2935{};
    bool K13_2935{};
    bool F17_2805{true};
    bool F77_2805{true};
    bool F97_2805{true};
    bool F117_2805{true};
    bool F122_2845{true};
    bool F427_2845{true};
    bool F429_2845{true};
    bool F124_2845{true};

    double qpgs3{};
    double pgs3_z{0};
    double Pv_vsu{0.0};//davlenie vozduha, otbiraemoe ot vspomogatelnoy ustanovki
    double delta_wpgs3{};
    double kgs{0.05};
    double qngs1{};
    double qngs2{};
    double qngs3{};
    double qngs4{};
    double qntnugs1{};//nagnetaemoe kolichestvo gidrozhidkosti za TNU
    double qntnugs2{};//nagnetaemoe kolichestvo gidrozhidkosti za TNU
    double qntnugs3{};//nagnetaemoe kolichestvo gidrozhidkosti za TNU
    double qntnugs4{};//nagnetaemoe kolichestvo gidrozhidkosti za TNU
    double qtnugs1{};//kolichestvo zhidkosti za TNU
    double qtnugs2{};//kolichestvo zhidkosti za TNU
    double qtnugs3{};//kolichestvo zhidkosti za TNU
    double qtnugs4{};//kolichestvo zhidkosti za TNU
    double qutgs3{};
    double wpgs3{};
    double wpgat{};
    double d_wpgat{};
    double d_wpgs1{};
    double d_wpgs2{};
    double d_wpgs3{};
    double d_wpgs4{};
    double dxst_dt{};
    double kgat{1.0};
    double ksur{0.02};
    double ktnu{0.02};

    double p0gat{115};//davlenie zaryadki gazom gidroakkum tormozov
    double p0gs1{115};//davlenie zaryadki gidro/akkum gazom v GS1
    double p0gs2{115};//davlenie zaryadki gidro/akkum gazom v GS2
    double p0gs3{115};//davlenie zaryadki gidro/akkum gazom v GS3
    double p0gs4{115};//davlenie zaryadki gidro/akkum gazom v GS4

    //kolichestvo potreblyaemoy gidrozhidkosti pri povorote krila levogo
    double qppchkl[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri povorote krila pravogo
    double qppchkp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote klina vozduha //zabornika
    double qpvkldv[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri rabote stvorki perepuska dvigatelya
    double qpfistv[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote kilya
    double qpk[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote interseptora levogo
    double qpintl[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote interseptora pravogo
    double qpintp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote flaperona levogo
    double qpfll[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote flaperona pravogo
    double qpflp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote stabilizatora
    double qpfist[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote prekrilkov levih
    double qpprl[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote prekrilkov pravih
    double qpprp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote zakrilkov levih
    double qpzl[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy zhidkosti pri rabote zakrilkov levih
    double qpzp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri smeshenii levoy stvorki
    double qpstvl[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri smeshenii pravoy stvorki
    double qpstvp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri smeshenii nosovoy stvorki
    double qpstvn[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri smeshenii osnovn stoyki levoy
    double qpshiftl[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri smeshenii //osnovn stoyki pravoy
    double qpshiftp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri vipuske levoy stoyki
    double qpshl[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri vipuske pravoy stoyki
    double qpshp[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri vipuske nosovoy stoyki
    double qpshn[amountOfHydroSys]{};
    //kolichestvo potreblyaemoy gidrozhidkosti pri povorote nosovogo kolesa
    double qpnk[amountOfHydroSys]{};

    double koef_sm{0.1};//smeshenie
    double koef_sz{50.0};//zakrilki
    double koef_spr{125.0};//prekrilki
    double koef_ssh{10.0};//shassi
    double koef_snk{10.0};//nosovoe koleso
    double koef_sk{1.0};//kil'
    double koef_sint{12.0};//interseptor
    double koef_sfl{3.8};//flapperoni
    double koef_sst{4.0};//stabilizator
    double koef_spchk{250.0};//strelovidnost'
    double koef_skl{5.0};//klin
    double koef_sstv{1.0};//stvorki perepuska vozduha
    double koef_sstvsh{0.1};//stvorki shassi


    double ddelta_k{};//keel speed
    double ddelta_int_l{};//skorost' peremesheniya interzeptora levih
    double ddelta_int_p{};//skorost' peremesheniya interzeptora pravogo
    double ddelta_fl_l{};//skorost' peremesheniya flaperonov levih
    double ddelta_fl_p{};//skorost' peremesheniya flaperonov pravih
    double ddelta_fi_st{};//skorost' peremesheniya stabilizatora

    double dqkldv1{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #1
    double dqkldv2{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #1
    double dqkldv3{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #1
    double dqkldv4{};//skorost' peremesheniya klina vozduhozabornika dvigatelya #1
    double dfistv1{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #1
    double dfistv2{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #2
    double dfistv3{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #3
    double dfistv4{};//skorost' peremesheniya stvorok perepuska vozduha dvigatelya #4
    double dXgrl1{};//skorost' otkritiya-zakritiya gruzovogo lyuka #1
    double dXgrl2{};//skorost' otkritiya-zakritiya gruzovogo lyuka #2

    double pgat_z{};
    double pgs1_z{};
    double pgs2_z{};
    double pgs4_z{};
    double psurgs1{};
    double psurgs2{};
    double psurgs3{};
    double psurgs4{};
    double ptnugs1{};
    double ptnugs2{};
    double ptnugs3{};
    double ptnugs4{};
    double qp1sum{};
    double qp2sum{};
    double qp3sum{};
    double qp4sum{};
    double qpgs1{};
    double qpgs2{};
    double qpgs4{};
    double qpts{};
    double qutgs1{};
    double qutgs2{};
    double qutgs4{};
    double s_st{};
    double w0gs1{2.36};
    double w0gs2{2.36};
    double w0gs3{2.36};
    double w0gs4{2.36};
    double wpgs1{};
    double wpgs2{};
    double wpgs4{};
    double pa1gak{};
    double pa2gak{};
    double pa3gak{};
    double pa4gak{};
    double pprgs1{};
    double pprgs2{};
    double pprgs3{};
    double pprgs4{};
    double pprgat{};
    double puksgs1{};
    double puksgs2{};
    double puksgs3{};
    double puksgs4{};
    double tb1{}, tb2{}, tb3{}, tb4{}; //temperature in the tank
    double tb1_z{}, tb2_z{}, tb3_z{}, tb4_z{};
    double air_temr_C{};//air tempreature in C
    double air_tempr_K{288};//tempretaure of air int the sky in K
    double dqg1p{}, dqg1t{}, dqg2p{}, dqg2t{}, dqgzat{}, dqg3p{},
        dqg3t{}, dqg4p{}, dqg4t{}, dqutg1{}, dqutg2{}, dqutg3{}, dqutg4{},
        q0g1{}, q0g2{}, q0g3{}, q0g4{}, qg1_z{}, qg2_z{}, qg3_z{}, qg4_z{},
        qgs1{0.0}, qgs2{0.0}, qgs3{0.0}, qgs4{0.0};

    QVector<bool> PTNUGS{false, false, false, false};
    QVector<bool> RVkTNUGS{false, false, false, false};
    QVector<bool> RVikTNUGS{false, false, false, false};
    QVector<bool> KSURGS{false, false, false, false};
    QVector<bool> KKGS{false, false, false, false};

    QVector<bool> Ffirst4_2920{true, true, true, true};
    //f1_2920 perekluchatel GIDROPITANIE SUR GS1,
    //f2_2920 perekluchatel GIDROPITANIE SUR GS2,
    //f3_2920 perekluchatel GIDROPITANIE SUR GS3,
    //f4_2920 perekluchatel GIDROPITANIE SUR GS4,

        QVector<bool> Sfirst4_2920{false, false, false, false};
        //S1_2920 perekluchatel TNU GS1
        //S2_2920 perekluchatel TNU GS2
        //S3_2920 perekluchatel TNU GS3
        //S4_2920 perekluchatel TNU GS4

        QVector<bool> Ssecond4_2920{false, false, false, false};
        //S5_2920 perekluchatel TNU GS1
        //S6_2920 perekluchatel TNU GS2
        //S7_2920 perekluchatel TNU GS3
        //S8_2920 perekluchatel TNU GS4
        QVector<int> Sthird4_2920{0 , 0 , 0 , 0 };
        //S9_2920 perekluchatel TNU GS1
        //S10_2920 perekluchatel TNU GS2
        //S11_2920 perekluchatel TNU GS3
        //S12_2920 perekluchatel TNU GS4

        bool
            K5_2910,
            K7_2910,
            K8_2910,
            K9_2910,
            F101_2910{true},
            F18_2910{true},
            F318_2910{true},
            F31_2910{true},
            F32_2910{true},
            F323_2910{true},
            F3_10010{true},
            F3_2910{true},
            F58_2910{true},
            F78_2910{true},
            F88_2910{true},
            F8_2910{true},
            F91_2910{true},
            F9_2910{true},
            F9_7322{true},
            K1_2930{},
            K2_2930{},
            K3_2930{},
            K4_2930{},
            K10_2910{},
            K11_2910{},
            K12_2910{},
            K13_2910{},
            K14_2910{},
            K15_2910{},
            K16_2910{},
            K17_2910{},
            K18_2910{},
            K19_2910{},
            K1_2910{},
            K20_2910{},
            K21_2910{},
            K22_2910{},
            K23_2910{},
            K25_2910{},
            K26_2910{},
            K27_2910{},
            K28_2910{},
            K29_2910{},
            K2_2910{},
            K30_2910{},
            K31_2910{},
            K32_2910{},
            K33_2910{},
            K34_2910{},
            K35_2910{},
            K36_2910{},
            K37_2910{},
            K38_2910{},
            K3_2910{},
            K4_2910{},
            prn1gs1{},
            prn1gs2{},
            prn1gs3{},
            prn1gs4{},
            prn2gs1{},
            prn2gs2{},
            prn2gs3{},
            prn2gs4{};
        double
            pn1gs1{},
            pn1gs2{},
            pn1gs3{},
            pn1gs4{},
            pn2gs1{},
            pn2gs2{},
            pn2gs3{},
            pn2gs4{};

        QVector<bool>pnngs1{false, false};
        QVector<bool>pnngs2{false, false};
        QVector<bool>pnngs3{false, false};
        QVector<bool>pnngs4{false, false};

        QVector<double>Qngngs1{0.0, 0.0};
        QVector<double>Qngngs2{0.0, 0.0};
        QVector<double>Qngngs3{0.0, 0.0};
        QVector<double>Qngngs4{0.0, 0.0};

        static QVector<double>nVDfirst2;
        //nvd1 chastota vrasheniya rotora visokogo davleniya 1 dvigatelya
        //nvd2 chastota vrasheniya rotora visokogo davleniya 2 dvigatelya
        static QVector<double>nVDsecond2;
        //nvd3 chastota vrasheniya rotora visokogo davleniya 3 dvigatelya
        //nvd4 chastota vrasheniya rotora visokogo davleniya 4 dvigatelya

        QVector<double>Kngs1{0.0, 0.0};
        QVector<double>Kngs2{0.0, 0.0};
        QVector<double>Kngs3{0.0, 0.0};
        QVector<double>Kngs4{0.0, 0.0};
        QVector<double>l_gs1{0.0, 0.0};
        QVector<double>l_gs2{0.0, 0.0};
        QVector<double>l_gs3{0.0, 0.0};
        QVector<double>l_gs4{0.0, 0.0};

        static double
            pgs1,//davlenie gidrozhidkosti v GS1
            pgs2,//davlenie gidrozhidkosti v GS2
            pgs3,//davlenie gidrozhidkosti v GS3
            pgs4;//davlenie gidrozhidkosti v GS4


    private:
        double qpsumF(int hydroID);
        double wpgatCalc(const double& pgs3,
                         const double& pgat,
                         const double& qngs3,
                         const double& leftPpresure,
                         const double& rightPpresure,
                         const double& alarmBreakPresure,
                         const bool& parkingBreakClue);
    public:
        virtual void updateLogic();

        void hydro_1();
        void hydro_2();
        void hydro_3();
        void hydro_4();
        void hydro_5();
        void hydro_6();
        void hydro_7();
        void hydro_8();
        void hydro_9();
        void hydro_10();

};


