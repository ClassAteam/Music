#pragma once
#include "wind_functions.h"
#include "algorithms.h"
#include "exchange.h"
#include "bss.h"
#include "uks.h"

extern bss bss_inst;
extern uks uks_inst;

extern double TICK;

class hydro_int
{
public:
    bool
        s1_2910{},//perekluchatel' PRINUD PODKL G/NASOSOV
        s2_2910{},//knopka KONTROL' RAZGRUZKI
        s3_2910{},//perekluchateli VIBOR NASOSA GS1,2
        s4_2910{},//perekluchateli VIBOR NASOSA GS3,4
        S5_2910{},//perekluchatel' EKSTRENNOE OTKL G/NASOSOV DV2 i 3
        S6_2910{},//perekluchatel' EKSTRENNOE OTKL G/NASOSOV DV1 i 4
        S7_2910{},//perekluchatel' OTKL G/NASOSOV DV2
        EZR1_34{},//priznak zapuska 1 dvigatelya
        EZR2_34{},//priznak zapuska 2 dvigatelya
        EZR3_34{},//priznak zapuska 3 dvigatelya
        EZR4_34{},//priznak zapuska 4 dvigatelya
        PBI4M_1{},
        PAPD_26{},
        PAPD_27{},
        PAPD_30{},
        PAPD_31{},
        otkaz_gs1{},//otkaz gs1
        otkaz_gs2{},//otkaz gs2
        otkaz_gs3{},//otkaz gs3
        otkaz_gs4{},//otkaz gs4
        pntnugs1{},
        pntnugs2{},
        pntnugs3{},
        pntnugs4{},
        PK{},
        F14_2930{true},
        F15_2930{true},
        F1_2930{true},
        H10_2930{},//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS1
        H11_2930{},//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS2
        H12_2930{},//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS3
        H13_2930{},//priznak vhodnogo signala dlya signalizatora REZERVNIY NADDUV GS4

        H1_2910{},//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS2
        H2_2910{},//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS1
        H4_2910{},//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS3
        H5_2910{},//priznak vhodnogo signala na svetodiod GIDRONASOSI PODKLUCHENI GS4

        PKL{},
        PKL1{},
        S13_2920{},//knopka kontrolya signalizatsii TNU SIGNAL
        S18_2920{},//knopka proverki lamp na shitke nazemnoy proverki
        H1_2935{},//priznak vihodnogo signala dlya svetodioda NASOS TZHT
        K1_2935{},
        K2_2935{},
        K3_2935{},
        K4_2935{},
        K5_2935{},
        K6_2935{},
        K7_2935{},
        K8_2935{},
        K9_2935{},
        K10_2935{},
        K11_2935{},
        K12_2935{},
        K13_2935{},
        F17_2805{true},
        F77_2805{true},
        F97_2805{true},
        F117_2805{true},
        F122_2845{true},
        F427_2845{true},
        F429_2845{true},
        F124_2845{true};

    double
        qpgs3, pgs3_z{0},
        Pv_vsu{0.0},//davlenie vozduha, otbiraemoe ot vspomogatelnoy ustanovki
        delta_wpgs3{}, kgs{0.05},
        qngat{}, qngs1{}, qngs2{}, qngs3{}, qngs4{}, qntnugs1{}, qntnugs2{},
        qntnugs3{}, qntnugs4{}, qtnugs1{}, qtnugs2{}, qtnugs3{}, qtnugs4{},
        qutgs3{}, wpgs3{}, d_wpgat{}, d_wpgs1{}, d_wpgs2{}, d_wpgs3{}, d_wpgs4{},
        dxst_dt{}, kgat{1.0}, ksur{0.02}, ktnu{0.02},

        p0gat{115},//davlenie zaryadki gazom gidroakkum tormozov
        p0gs1{115},//davlenie zaryadki gidro/akkum gazom v GS1
        p0gs2{115},//davlenie zaryadki gidro/akkum gazom v GS2
        p0gs3{115},//davlenie zaryadki gidro/akkum gazom v GS3
        p0gs4{115},//davlenie zaryadki gidro/akkum gazom v GS4

        pgat_z{},
        pgs1_z{},
        pgs2_z{},
        pgs4_z{},
        psurgs1{},
        psurgs2{},
        psurgs3{},
        psurgs4{},
        ptnugs1{},
        ptnugs2{},
        ptnugs3{},
        ptnugs4{},
        qp1sum{},
        qp2sum{},
        qp3sum{},
        qp4sum{},
        qpgs1{},
        qpgs2{},
        qpgs4{},
        qpts{},
        qutgs1{},
        qutgs2{},
        qutgs4{},
        s_st{},
        w0gat{4.07},
        w0gs1{2.36},
        w0gs2{2.36},
        w0gs3{2.36},
        w0gs4{2.36},
        wpgat{},
        wpgs1{},
        wpgs2{},
        wpgs4{},
        pa1gak{},
        pa2gak{},
        pa3gak{},
        pa4gak{},
        pprgs1{},
        pprgs2{},
        pprgs3{},
        pprgs4{},
        pprgat{},
        puksgs1{},
        puksgs2{},
        puksgs3{},
        puksgs4{},
        tb1{}, tb2{}, tb3{}, tb4{}, //tempreture in the tank
        tb1_z{}, tb2_z{},//
        tb3_z{}, tb4_z{},
        air_temr_C{},//air tempreature in C
        air_tempr_K{288},//tempretaure of air int the sky in K
        dqg1p{}, dqg1t{}, dqg2p{}, dqg2t{}, dqgzat{}, dqg3p{},
        dqg3t{}, dqg4p{}, dqg4t{}, dqutg1{}, dqutg2{}, dqutg3{}, dqutg4{}, q0g1{}, q0g2{},
        q0g3{}, q0g4{}, qg1_z{}, qg2_z{}, qg3_z{}, qg4_z{}, qgs1{0.0}, qgs2{0.0}, qgs3{0.0},
        qgs4{0.0} ;

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

};


