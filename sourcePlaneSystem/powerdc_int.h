#pragma once
//#include "interfacing.h"
#include "bss.h"
#include "allElCons.h"
#include "exchange.h"
#include "uks.h"
#include "hydro_int.h"

//extern allElConsAlt allElConsAlt_inst;
//extern allElConsDir allElConsDir_inst;
extern bss bss_inst;
extern uks uks_inst;

class powerdc_int //: public interfacing
{
    //Q_OBJECT

public:
    static allElConsAlt allElConsAlt_inst;
    static allElConsDir allElConsDir_inst;

    bool
        k4_4940,//priznak rele otkritogo polozheniya stvorki vozduhozabornika VSU
        pvrap,// priznak vkl RAP
        s7_2420{},//knopka RAZBLOKIROVKA
        s17_2420{},//knopka FAZI A
        s18_2420{},//knopka FAZI B
        s19_2420{},//knopka FAZI C
        s21_2420{},//vikl preobrazovatelya #3(POS1000)
        s15_2420{},//vikluch PTS PREOBR 1
        s1_7710{},//vikluchatel ESUD SKU1
        s2_7710{},//vikluchatel ESUD SKU2
        s3_7710{},//vikluchatel ESUD SKU3
        s4_7710{},//vikluchatel ESUD SKU4
        s2_2420{},//perekluch SET' 115/200V SOED SETEY
        s9_2420{},//perekl SET' 115/200 RAP
        s1_2420{},//perekl vkluch generatora peremnnogo toka GEN1
        s5_2420{},//perekl vkluch generatora peremnnogo toka GEN2
        s10_2420{},//perekl vkluch generatora peremnnogo toka GEN3
        s13_2420{},//perekl vkluch generatora peremnnogo toka GEN4
        s4_2420{},//perekluch vkluch chastichnogo rezhima levoy seti perem toka CHASTICHNIY REZHIM SET LEVAYA
        s12_2420{},//perekl vkl chastichn rezhima pravoy seti perem toka CHASTICHNIY REZHIM SET PRAVAYA
        s8_2420{},//knopochniy perekl vkluch gener perem toka VSU GEN VSU
        otkGenPerT1{},//otkaz generatora peremennogo toka#1
        otkGenPerT2{},//otkaz generatora peremennogo toka#2
        otkGenPerT3{},//otkaz generatora peremennogo toka#3
        otkGenPerT4{},//otkaz generatora peremennogo toka#4
        otkGenPerVsu{},//otkaz generatora peremennogo toka VSU
        otkPadDavlMaslPpo1G{},//otkaz padeniya davleniya masla privodov postoyannih oborotov#1
        otkPadDavlMaslPpo2G{},//otkaz padeniya davleniya masla privodov postoyannih oborotov#2
        otkPadDavlMaslPpo3G{},//otkaz padeniya davleniya masla privodov postoyannih oborotov#3
        otkPadDavlMaslPpo4G{},//otkaz padeniya davleniya masla privodov postoyannih oborotov#4
        otk_pereg_gen1{},//otkaz peregrev generatora 1
        otk_pereg_gen2{},//otkaz peregrev generatora 2
        otk_pereg_gen3{},//otkaz peregrev generatora 3
        otk_pereg_gen4{},//otkaz peregrev generatora 4
        otk_pereg_akk1{},//otkaz peregrev akkumulyatora1
        otk_pereg_akk2{},//otkaz peregrev akkumulyatora2
        OtkazGen1PostT{},//otkaz generatora 1 postoyannogo toka
        OtkazGen2PostT{},//otkaz generatora 2 postoyannogo toka
        OtkazGen3PostT{},//otkaz generatora 3 postoyannogo toka
        OtkazGen4PostT{},//otkaz generatora 4 postoyannogo toka
        OtkazGenVsu{},//otkaz generatora VSU postoyannogo toka
        s1_2430{},//perekl gen vsu(27)
        s4_2430{},//perekl g1 (27)
        s5_2430{},//perekl g2(27)
        s8_2430{},//perekl g3(27)
        s11_2430{},//perekl g4(27)
        s2_2430{},//perekl knopochn vkluch rap1
        s9_2430{},//perekl knopochn vkluch rap2
        s7_2430{},//perekl knopochn SOED SETEY
        s3_2430{},//perekl knopochn vklucheniya CHASTICHNIY REZHIM(27 LEV)
        s10_2430{},//perekl knopochn vklucheniya CHASTICHNIY REZHIM(27 PRAV)
        glviklvsu{false};//signal s pulta PP73(pult zapuska i upravl VSU)
    static bool
        s14_2430,//perekl knopochn vkluch AKK1
        s15_2430,//perekl knopochn vkluch AKK2
        prgen[5],//sign of working gener (1,2,3,4 and vsu)
        apdvsu_35,//priznaki signalov vklucheniya puskovogo soprotivleniya
        apdvsu_49;//priznaki signalov shuntirovaniya puskovogo soprotivleniya
    double
        qa1{40.0},//emkost' akkumulyatora 1
        qa2{40.0};//emkost' akkumulyatora 2
    static double
        ingvsu,//tok nagruzki generatora VSU
        irap1,//tok RAP #1
        irap2,//tok RAP #2
        upr,//pribornoe znachenie napryazheniya, V
        ipr,//pribornoe znachenie toka, A
        ea1,//EDS akkumulyatora 1
        ea2,//EDS akkumulyatora 2
        uak1,//napryazhenie akkumulyatora 1
        uak2,//napryazhenie akkumulyatora 2
        //ugrr, ugrrvsu,
        iak1,//tok akkumulyatora #1
        iak2;//tok akkumulyatora #2

        static bool
        plp27,
        ppgvsu27,
        ppp27,
        prg1,
        prg2,
        prg3,
        prg4,
        prgvsu,
        pss27,
        purg27lk1,
        purg27lk4,
        purg27lk5,
        purg27lk6,
        purg27lk7,
        purg27lk9,
        purg27pk1,
        purg27pk3,
        purg27pk4,
        purg27pk5,
        purg27pk7,
        purg27pk9,
        pvkgvsu27;

    static double
        fg_27[5],
        ng1_27,
        ng2_27,
        ng3_27,
        ng4_27,
        ngvsu_27,
        ivg1_27,
        ivg2_27,
        ivg3_27,
        ivg4_27,
        ivgvsu_27,
        ing1_27,
        ing2_27,
        ing3_27,
        ing4_27,
        ingvsu_27,
        ingrap_27,
        divg1_27,
        divg2_27,
        divg3_27,
        divg4_27,
        divgvsu_27,
        ug1_27,
        ug2_27,
        ug3_27,
        ug4_27,
        ugvsu_27,
        ug1r_27,
        ug2r_27,
        ug3r_27,
        ug4r_27,
        ugvsur_27,
        ug1z_27,
        ug2z_27,
        ug3z_27,
        ug4z_27,
        ugvsuz_27,
        ingrap,
        ing1,
        ing2,
        ing3,
        ing4,
        ugP_27[5][3];
    static double
        ushpzl,
        ushpzp,
        inpp27,
        insh1dpl,
        insh2dpl,
        insh1dpp,
        insh2dpp,
        inshal,
        inshap,
        insh1l,
        insh1p,
        insh2l,
        insh2p,
        inshzvsu,
        insl27,
        insp27,
        insho1l,
        insho1p,
        insho2l,
        insho2p,
        kg1_27,
        kg2_27,
        kg3_27,
        kg4_27,
        nvsu,
        pbgvsu,
        ugrvsu,
        uo1ak,
        uo2ak,
        ur1ak,
        ur2ak,
        uz1ak,
        uz2ak,
        uls27,
        ups27,
        //ugrr, ugrrvsu,
        ugvsu27,
        ugrvsu27,
        ivgvsu27,
        divgvsu27,
        kak,
        urap1,
        urap2;
    int
        s20_2420;//perekl konrolya APSH
    static bool
        pvksku[4],
        purglk1,
        purglk2,
        purglk3,
        purglk4,
        purglk5,
        purglk6,
        purglk7,
        purglk8,
        purglk9,
        purgpk1,
        purgpk2,
        purgpk3,
        purgpk4,
        purgpk5,
        purgpk6,
        purgpk7,
        purgpk8,
        purgpk9,
        pp400[2],
        purgk31,
        purgk41,
        pss400,
        purgk1,
        purgk21;
    bool
        s1_11028,
        s1_4940,
        k1_11038,
        k2_11038,
        s1_11052,
        s2_11052,
        s1_11081,
        s1_11313,
        k1_17723,
        k2_17723,
        k11_2250,
        k1_2250,
        k30_2420,
        k31_2420,
        k3_2250,
        k5_2250,
        k8_2250,
        k3_3650,
        k2_7322,
        k3_7322,
        k4_7322,
        k5_7322,
        k8_7322,
        k9_7322,
        k10_7322,
        k11_7322,
        k18_7322,
        pvrap1,
        pvrap2,
        pnu,
        otk_pos1000{},
        k12_2420{},
        k13_2420{},
        k14_2420{},
        k15_2420{},
        k16_2420{},
        k18_2420{},
        k34_2420{},
        pbapsh[5]{},
        otk_preobr_pts1,
        overload_gen1{},
        overload_gen2{},
        overload_gen3{},
        overload_gen4{},
        pbapsh1{},
        pbapsh2{},
        pbapsh3{},
        pbapsh5{},
        pbapsh6{},
        purglk10{},
        k17_2420{},
        k19_2420{},
        k20_2420{},
        pprap{},
        pvkgen[5],
        pvkgen2{},
        pvkgen3{},
        pvkgen4{},
        pvkgenvsu{},
        pzvg[5],
        pzvgvsu,
        pog[4],
        pchrl,
        pchrp,
        k1_2430,
        s3_2420{},
        s6_2420{},
        s11_2420{},
        s14_2420{},
        f9_2420{},
        f14_2420{},
        f24_2420{},
        f28_2420{},
        popg1{},
        popg2{},
        popg3{},
        popg4{},
        popp01{},
        popp02{},
        popp03{},
        popp04{},
        f92_2420{},
        f142_2420{},
        f242_2420{},
        f282_2420{},
        k25_2420{},
        k26_2420{},
        k27_2420{},
        k28_2420{},
        k4_3650{},
        y1_3650{},
        y2_3650{},
        r865gd{},
        prgvsu27{},
        pa1{},
        pa2{},
        pbg1{},
        pbg2{},
        pbg3{},
        pbg4{},
        pbgvsu27{},
        pvkg1{},
        pvkg2{},
        pvkg3{},
        pvkg4{},
        pvkchrl{},
        pvkchrp{},
        pprap1{},
        pprap2{},
        pshzvsu{};

    double
        uzg1_27{28.5},
        uzg2_27{28.4},
        uzg3_27{28.6},
        uzg4_27{28.7},
        uzgvsu_27{28.5},
        kn1{25},
        krg{0.00025},
        krgvsu{0.00037},
        kg1{1.5},
        kgvsu{1.5},
        kg10{0.05};


    static double
        ra1,
        ra2;

    enum s13_2430_pos{ground, air};
    int s13_2430;//perekl ZEMLYA-VOZDUH
    enum s16_2430_pos{akk1, akk2, avar1, avar2, sh1lev, sh2lev, sh1prav, sh2prav};
    int s16_2430;//perekl voltmetra
    enum s17_2430_pos{akk1_rap1, akk2_rap2, vsu};
    int s17_2430;//perekl amppermetra
    enum s20_2430_pos{apsh1, apsh2, apsh3, apsh5, apsh6};
    int s20_2430;


    bool
        k1_2420{},
        k2_2420{},
        k7_2420{},
        k8_2420{},
        k21_2420{},
        k22_2420{},
        k23_2420{},
        k24_2420{};
    double
        fg[5] = {0},
        ng1, ng2, ng3, ng4, ngvsu,
        ivg1, ivg2, ivg3, ivg4, ivgvsu,
        divg1, divg2, divg3, divg4, divgvsu,
        ug1, ug2, ug3, ug4, ugvsu,
        ug1r, ug2r, ug3r, ug4r, ugvsur,
        ug1z{118}, ug2z{117}, ug3z{115}, ug4z{116}, ugvsuz{117},
        ugP[5][3]; //generator's phases

    bool
        purglk11,
        purgpk11;


public:
  //  powerdc_int(QWidget *parent = nullptr);

    powerdc_int(){};
    virtual void updateLogic();
    void apsh_switch(double &ushavla, bool &knumber, bool &pba, bool &purg);
    void powerdc_1();
    void powerdc_2_3();
    void powerdc_4();
    void powerdc_5_6();
    void powerdc_7();
    void powerdc_8();
    void powerdc_9_10();
    void powerdc_11();
    void powerdc_12();
    void powerdc_13();
    void powerdc_14();
    void powerdc_15();
    void powerdc_16();
    void powerdc_20();
    void powerdc_21();
};
