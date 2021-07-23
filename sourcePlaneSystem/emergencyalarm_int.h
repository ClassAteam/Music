#pragma once
#include <QVector>
#include "algorithms.h"
#include "bss.h"
#include "allElCons.h"
#include "input_feed.h"
#include "exchange.h"
extern bss bss_inst;
extern bss bss_inst;
extern double TICK;

enum class type {yellow, red, white};


class emergencyalarm_int
{
public:
    emergencyalarm_int();

    bool dummy_array[2][2]{};

    class light
    {
    public:
        light(bool* in_clue, bool* out_clue, bool* is_checked,  type color);
        bool* inClue;
        bool* outClue;
        bool* isChecked;
        type color;
        bool* position;
    };

    QVector<light*> lights;

    bool
        PCSOKLL,//priznak centralnogo signalnogo ognya(CSO) krasnogo levogo letchika
        PCSOKPL,//priznak centralnogo signalnogo ognya(CSO) krasnogo pravogo letchika
        PCSOKSHN,//priznak centralnogo signalnogo ognya(CSO) krasnogo shturmana navigatora
        PCSOKSHO,//priznak centralnogo signalnogo ognya(CSO) krasnogo shturmana operatora
        PCSOZHLL,//priznak centralnogo signalnogo ognya(CSO) zheltogo levogo letchika
        PCSOZHPL,//priznak centralnogo signalnogo ognya(CSO) zheltogo pravogo letchika
        PCSOZHSHN,//priznak centralnogo signalnogo ognya(CSO) zheltogo shturmana navigatora
        PCSOZHSHO,//priznak centralnogo signalnogo ognya(CSO) zheltogo shturmana operatora
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



    void lamp_blink(bool &inpClue, bool &lamp, int &blink);

public:
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


