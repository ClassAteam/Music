#pragma once
//#include "interfacing.h"
#include "algorithms.h"
#include "bss.h"
#include "allElCons.h"
#include "input_feed.h"
#include "exchange.h"
extern  double TICK;


extern bss bss_inst;
extern bss bss_inst;



class emergencyalarm_int// : public interfacing
{
    //Q_OBJECT
public:
    bool
        PCSOKLL,//priznak centralnogo signalnogo ognya(CSO) krasnogo levogo letchika
        PCSOKPL,//priznak centralnogo signalnogo ognya(CSO) krasnogo pravogo letchika
        PCSOKSHN,//priznak centralnogo signalnogo ognya(CSO) krasnogo shturmana navigatora
        PCSOKSHO,//priznak centralnogo signalnogo ognya(CSO) krasnogo shturmana operatora
        PCSOZHLL,//priznak centralnogo signalnogo ognya(CSO) zheltogo levogo letchika
        PCSOZHPL,//priznak centralnogo signalnogo ognya(CSO) zheltogo pravogo letchika
        PCSOZHSHN,//priznak centralnogo signalnogo ognya(CSO) zheltogo shturmana navigatora
        PCSOZHSHO,//priznak centralnogo signalnogo ognya(CSO) zheltogo shturmana operatora
        S1_3364,//knopka-tablo ZSO levogo letchika
        S2_3364,//knopka-tablo ZSO pravogo letchika
        S3_3364,//knopka-tablo ZSO shturmana-operatora
        S4_3364,//knopka-tablo ZSO shturmana-navigatora
        S5_3364,//knopka KONTR SIGNAL lev letchika
        S6_3364,//knopka KONTR SIGNAL prav letchika
        S7_3364,//knopka KONTR SIGNAL shturmana-operatora
        S8_3364;//knopka KONTR SIGNAL shturmana-navigatora

    double
        USASLL,
        USASPL,
        USASSHN,
        USASSHO,
        alpha_rra7ll,
        alpha_rra7pl,
        alpha_rra7shn,
        alpha_rra7sho;
    bool
        PBVkCSOKSHNy2,
        PBVkCSOZHSHNx2,
        PCSOKLL_1,
        PCSOKLL_2,
        PCSOKLL_3,
        PCSOKPL_1,
        PCSOKPL_2,
        PCSOKSHO_2,
        PCSOZHLL_1,
        PCSOZHLL_2,
        PCSOZHLL_3,
        PCSOZHPL_1,
        PCSOZHPL_2,
        PCSOZHSHO_1,
        PCSOZHSHO_2,
        PKLLL,
        PKLPL,
        PKLSHN,
        PKLSHO,
        PRBSS824,
        PRBSS825,
        PRBSS837,
        PRBSS838,
        PRBSS913{1},
        PRBSS926,
        PRBSS_811,
        PRBSS_812,
        PRBSS_913,
        PRBSS_939,
        PVkCSOKSHNy2,
        PVkCSOZHSHNx2,
        PZH926_X1J_b,
        PZH926_X1L_b,
        PZH939_X1B_b,
        PZH939_X1D_b,
        PZH939_X1E_b,
        PZH_ins_net_rezerva,
        PZH_ins_net_rezerva_b,
        PZH_ins_otkaz,
        PZH_ins_otkaz_b,
        PZH_svs_net_rezerva,
        PZH_svs_net_rezerva_b,
        PZH_svs_otkaz,
        PZH_svs_otkaz_b,
        ins_net_rezerva,
        ins_otkaz,
        svs_net_rezerva,
        svs_otkaz;


public:
  //  emergencyalarm_int(QWidget *parent = nullptr);
        emergencyalarm_int(){};
    virtual void updateLogic();

    void emergencyalarm_1();
    void emergencyalarm_2();
    void emergencyalarm_3();
    void emergencyalarm_4();
    void emergencyalarm_5();
    void emergencyalarm_6();
    void emergencyalarm_7();
    void emergencyalarm_8();
    void emergencyalarm_9();
};

