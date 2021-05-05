#pragma once
#include "bss.h"
#include "allElCons.h"
#include "exchange.h"
#include "uks.h"
#include "algorithms.h"

extern bss bss_inst;
extern uks uks_inst;


class antifire_int
{
public:

    bool
        PAPDvh6{},//priznak nalichiya napryazheniya na vhode paneli zapuska VSU
        S10_2610{},//knopka proverki ognetushiteley OGNETUSH
        S11_2610{},//pereklyuchatel' knopochniy 2-oy ocheredi ognetushiteley u letchika OCHER 2
        S12_2610{},
        S13_2610{},//pereklyuchatel' knopochniy 3-oy ocheredi ognetushiteley u letchika OCHER 3
        S14_2610{},//pereklyuchatel' knopochniy 3-oy ocheredi ognetushiteley u letchika OCHER 3
        S15_2610{},//pereklyuchatel' knopochniy 3-oy ocheredi ognetushiteley u letchika OCHER 3
        S3_2610{},//pereklyuchatel' knopochniy otkritogo polozheniya krana pozharotusheniya DV1
        S4_2610{},//pereklyuchatel' knopochniy otkritogo polozheniya krana pozharotusheniya DV1
        S5_2610{},//lampa-knopka otkritogo polozheniya krana pozharotusheniya vspomogatelnoy silovoy ustanovki KRAN VSU
        S6_2610{},//lampa-knopka otkritogo polozheniya krana pozharotusheniya vspomogatelnoy silovoy ustanovki KRAN VSU
        S7_2610{},//pereklyuchatel' knopochniy otkritogo polozheniya krana pozharotusheniya DV3
        S8_2610{},//pereklyuchatel' knopochniy otkritogo polozheniya krana pozharotusheniya DV4
        S9_2610{},//viklyuchatel' RABOTA
        lzh_srab_pereg_1_dv{},//lozhnoe srabativanie signalizatsii PEREGREV 1go DV.
        lzh_srab_pereg_2_dv{},//lozhnoe srabativanie signalizatsii PEREGREV 2go DV.
        lzh_srab_pereg_3_dv{},//lozhnoe srabativanie signalizatsii PEREGREV 3go DV.
        lzh_srab_pereg_4_dv{},//lozhnoe srabativanie signalizatsii PEREGREV 4go DV.
        peregrev_1_dv{},//peregrev 1go dvigatelya
        peregrev_2_dv{},//peregrev 2go dvigatelya
        peregrev_3_dv{},//peregrev 3go dvigatelya
        peregrev_4_dv{},//peregrev 4go dvigatelya
        pnu{},//priznak nachalnih usloviy
        pozhar_1_dv{},//pozhar 1go dvigatelya
        pozhar_2_dv{},//pozhar 2go dvigatelya
        pozhar_3_dv{},//pozhar 3go dvigatelya
        pozhar_4_dv{},//pozhar 4go dvigatelya
        pozhar_vsu{};//pozhar vsu

    int S1_2610{};//pereklyuchatel' vibora otseka dlya proverki OTKL-MG 1DV-MG2DV-MG 3DV-MG 4DV-VSU
    enum s1_2610{otkl, mg1dv, mg2dv, mg3dv, mg4dv, vsu};

    int S2_2610{};//pereklyuchatel' vibora gruppi datchikov OKTL-1 GR-2 GR-3 GR4 GR-5 GR-6 GR-POZHAR
    enum s2_2610{otk, gr1, gr2, gr3, gr4, gr5, gr6, pozhar};

    bool
        F101_2610{},
        F111_2610{},
        F121_2610{},
        F132_2610{},
        F135_2805{},
        F142_2610{},
        F145_2805{},
        F155_2805{},
        F165_2805{},
        F181_2610{},
        F25_2610{},
        F35_2610{},
        F45_2610{},
        F55_2610{},
        F65_2610{},
        F72_2610{},
        F7_2610{true},
        F82_2610{},
        F8_2610{true},
        F911_2610{},
        F912_2610{},
        F913_2610{},
        F914_2610{},
        F915_2610{},
        F916_2610{},
        F917_2610{},
        F91_2610{},
        F92_2610{},
        K12_2610{},
        K15_2610{},
        K16_2610{},
        K19_2610{},
        K1_2610{},
        K20_2610{},
        K23_2610{},
        K24_2610{},
        K25_2610{},
        K26_2610{},
        K27_2610{},
        K28_2610{},
        K31_2610{},
        K32_2610{},
        K33_2610{},
        K34_2610{},
        K35_2610{},
        K3_2610{},
        K42_2610{},
        K49_2610{},
        K50_2610{},
        K51_2610{},
        K53_2610{},
        K54_2610{},
        K57_2610{},
        K58_2610{},
        K60_2610{},
        K61_2610{},
        K67_2610{},
        K6_2610{},
        K80_2610{},
        K9_2610{},
        PKO{},
        PO1och{},
        PPBI{},
        PSA10_1{},
        PSA10_2{},
        PSA19_1{},
        PSA19_2{},
        PW_1_och_l{true},
        PW_1_och_o{true},
        PW_2_och{true},
        PW_3_och{true},
        otkaz_avtomatiki_SPZ{},
        F9_2610{true},
        F10_2610{true},
        F18_2610{true},
        F11_2610{true},
        F12_2610{true};


public:
    virtual void updateLogic();
    void antifire_1();
    void antifire_2();
    void antifire_3();

};
