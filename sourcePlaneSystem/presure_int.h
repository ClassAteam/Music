#pragma once
#include "bss.h"
#include "uks.h"
#include "exchange.h"
#include "algorithms.h"
#include "math.h"

extern double TICK;
extern bss bss_inst;
extern uks uks_inst;

extern double a1;
extern double a2;
extern double b1;
extern double b2;


class presure_int
{
public:
    double
        H{},//visota poleta
        Ph{},//atmosfernoe davlenie na dannoy visote, mm rt st vhodnoe
        Pkab_ind_delta{};//perepad davleniy v germokabine, indikatornoe znachenie, kgs/sm^2

    bool
        PNU{},//priznak nachalnih usloviy
        K1_2131{},
        K2_2131{},
        K4_2131{},
        PAVARR{},
        PRTHU1{},
        PPP{},
        PGK{},
        SKD_D300{},
        SKD_D301{},
        otkaz_razgermetizatsiya{},
        lyukizagermetizirovany{},
        otkaz_perenadduv{},
        S2_2131{};
    int
        S1_2131{};

    double
        H_k{},
        Ph_msa{},
        Ph_{},//atmosfernoe davlenie na dannoy visote, kgs/sm^2
        Pk_h{},
        Pkab{},
        Pkab_delta{},
        Hkab{},
        Hkab_ind{},
        Vkab{},
        Pkab_zad{};

public:
    virtual void updateLogic();

    void presure();
};
