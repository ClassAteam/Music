#pragma once
#include "bss.h"
#include "uks.h"
#include "allElCons.h"
#include "exchange.h"
#include "algorithms.h"

extern bss bss_inst;
extern uks uks_inst;

class wingsmech_int
{
public:
    static bool S1_2750;//kolpachek vikluchately "REZERVNOE UPRAVLENIE ZAKRILKI"

    double
        X_L{20},//polozhenie podvizhnoy chasti krila levoy
        X_P{20},//polozhenie podvizhnoy chasti krila pravoy
        delta_zr_vh{},//vhodnoe polozhenie ruchki upravleniya zakrilkami
        delta_z_l{},//tekushee polozhenie zakrilkov levih, grad
        delta_z_p{},//tekushee polozhenie zakrilkov pravih, grad
        delta_pr_l{},//polozhenie predkrilkov levih
        delta_pr_p{},//polozhenie predkrilkov pravih
        X_1_pk{},//znachenie signala s datchika polozheniya PCHK1 podkanala levogo(dlya ABSU)
        X_3_pk{},//znachenie signala s datchika polozheniya PCHK1 podkanala pravogo(dlya ABSU)
        delta_z_1_pk{},//znachenie signala s datchika polozheniya zakrilkov 1 podkanala levogo(dlya ABSU)
        delta_z_3_pk{};//znachenie signala s datchika polozheniya zakrilkov 3 podkanala levogo(dlya ABSU)
    int
        S2_2750{},//vikluchatel "REZERVNOE UPRAVLENIE ZAKRILKI
        s2_2780{},//vikluchatel "REZERVNOE UPRAVLENIE PREDKRILKI"
        s2_2790{};//perekluchatel "REZERVN UPRAVL STRELOV KRILA"
    bool
        s1_2790{},//kolpachek perekluchatelya REZERVN UPRAVL STRELOV KRILA"
        s1_2780{},//kolpachek vikluchatelya "REZERVNOE UPRAVLENIE PREDKRILKOV"
        S13_2750{},//vikluchatel "ZAKRILKI PREDKRILKI SLEDYASHIY"
        PGS1{},//priznak raboti gidrosistemi 1
        PGS2{},//priznak raboti gidrosistemi 2
        PGS3{},//priznak raboti gidrosistemi 3
        PGS4{},//priznak raboti gidrosistemi 4
        otkaz_osn_1k_zakr{},//otkaz osnovnogo 1 kanala zakrilkov
        otkaz_osn_2k_zakr{},//otkaz osnovnogo 2 kanala zakrilkov
        otkaz_1k_zakr{},//otkaz 1 kanala zakrilkov
        otkaz_2k_zakr{},//otkaz 2 kanala zakrilkov
        otkaz_rassgl_zakr{},//otkaz RASSOGLASOVANIE ZAKRILKI
        otkaz_osn_1k_prekr{},//otkaz osnovnogo 1 kanala predkrilkov
        otkaz_osn_2k_prekr{},//otkaz osnovnogo 2 kanala predkrilkov
        otkaz_rassgl_prekr{},//otkaz RASSOGLASOVANIE PREDKRILKI
        otkaz_osn_1k_PCHK{},//otkaz osnovnogo 1 kanala PCHK
        otkaz_osn_2k_PCHK{},//otkaz osnovnogo 2 kanala PCHK
        otkaz_RASSINHR_PCHK{};//otkaz rassinhronizatsiya PCHK

    bool
        prrkz{},
        prr1kz{},
        prr2kz{},
        psr1kz{},
        por1kz{},
        por2kz{},
        psr2kz{},
        por1kpr{},
        por2kpr{},
        prrkpchk{},
        prr1kpchk{},
        prr2kpchk{},
        por1kpchk{},
        por2kpchk{},
        otkaz_1k_prekr{},
        otkaz_2k_prekr{},
        prrkpr{},
        prr1kpr{},
        prr2kpr{},
        psr1kpr{},
        psr2kpr{};

    double
        Kz{1.0},
        delta_z_zad{},
        Ddelta_z_l,
        Ddelta_z_p,
        Kpr{1.0},
        delta_pr_zad,
        delta_pr_vh,
        Ddelta_pr_l,
        Ddelta_pr_p,
        X_PCHK,
        X_zad,
        D_X_l,
        D_X_p,
        Kgs{},
        Kgs1{},
        Kgs2{},
        Kgs3{},
        Kgs4{},
        Kpchk{},
        Kpchk1{},
        Kpchk2{},
        Kpchk3{},
        Kpchk4{},
        delta_ruk_vh,
        XL_120,
        XP_121,
        XTR_122,
        delta_pr,
        delta_pr_116,
        delta_pr_l_114,
        delta_pr_p_115,
        delta_ruk_123,
        delta_ruz_113,
        delta_z_112,
        delta_z_l_110{},
        delta_zr_vh_bf,
        delta_z_p_111{};

    enum s2_2790_pos{off, bolshe, menshe};

public:
    virtual void updateLogic();

    void wingsmech_1();
    void wingsmech_2();
    void wingsmech_3();
    void wingsmech_4();
};
