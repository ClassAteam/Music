#pragma once
#include "bss.h"
#include "uks.h"
#include "exchange.h"
#include "algorithms.h"

extern bss bss_inst;
extern uks uks_inst;

class wingsmech_int
{
public:
    //kolpachek vikluchately "REZERVNOE UPRAVLENIE ZAKRILKI"
    static bool S1_2750;

    //polozhenie podvizhnoy chasti krila levoy
    double X_L{20};
    //polozhenie podvizhnoy chasti krila pravoy
    double X_P{20};
    //polozhenie podvizhnoy chasti krila dlya signalizatsii
    double X_PCHK{};
    //vhodnoe polozhenie ruchki upravleniya zakrilkami
    double delta_zr_vh{};
    //tekushee polozhenie zakrilkov levih; grad
    double delta_z_l{};
    //tekushee polozhenie zakrilkov pravih; grad
    double delta_z_p{};
    //polozhenie predkrilkov levih
    double delta_pr_l{};
    //polozhenie predkrilkov pravih
    double delta_pr_p{};
    //znachenie signala s datchika polozheniya PCHK1 podkanala levogo
    //(dlya ABSU)
    double X_1_pk{};
    //znachenie signala s datchika polozheniya PCHK1 podkanala pravogo
    //(dlya ABSU)
    double X_3_pk{};
    //znachenie signala s datchika polozheniya zakrilkov 1 podkanala levogo
    //(dlya ABSU)
    double delta_z_1_pk{};
    //znachenie signala s datchika polozheniya zakrilkov 3 podkanala levogo
    //(dlya ABSU)
    double delta_z_3_pk{};
    //skorost' peremesheniya podvizhnoy chasti krila levoy
    double D_X_l{};
    //skorost' peremesheniya podvizhnoy chasti krila pravoy
    double D_X_p{};
    //znachenie izmeneniya dlya uks levogo
    double D_X_lUks{};
    //znachenie izmeneniya dlya uks pravogo
    double D_X_pUks{};
    //koeficient izmeneniya skorosti pri otkaze RASSINHRONIZATSIYA PCHK
    double koef_KrlPchk{1.0};
    //koeficient izmeneniya skorosti pri otkaze RASSINHRONIZATSIYA prekrilkov
    double koef_KrlPr{1.0};
    //koeficient izmeneniya skorosti pri otkaze RASSINHRONIZATSIYA zakrilkov
    double koef_KrlZk{1.0};

    //vikluchatel "REZERVNOE UPRAVLENIE ZAKRILKI
    int S2_2750{};
    //vikluchatel "REZERVNOE UPRAVLENIE PREDKRILKI"
    int s2_2780{};
    //perekluchatel "REZERVN UPRAVL STRELOV KRILA"
    int s2_2790{};

    //kolpachek perekluchatelya REZERVN UPRAVL STRELOV KRILA"
    bool s1_2790{};
    //kolpachek vikluchatelya "REZERVNOE UPRAVLENIE PREDKRILKOV"
    bool s1_2780{};
    //vikluchatel "ZAKRILKI PREDKRILKI SLEDYASHIY"
    bool S13_2750{};
    //priznak raboti gidrosistemi 1
    bool PGS1{};
    //priznak raboti gidrosistemi 2
    bool PGS2{};
    //priznak raboti gidrosistemi 3
    bool PGS3{};
    //priznak raboti gidrosistemi 4
    bool PGS4{};
    //otkaz osnovnogo 1 kanala zakrilkov
    bool otkaz_osn_1k_zakr{};
    //otkaz osnovnogo 2 kanala zakrilkov
    bool otkaz_osn_2k_zakr{};
    //otkaz 1 kanala zakrilkov
    bool otkaz_1k_zakr{};
    //otkaz 2 kanala zakrilkov
    bool otkaz_2k_zakr{};
    //otkaz RASSOGLASOVANIE ZAKRILKI
    bool otkaz_rassgl_zakr{};
    //otkaz osnovnogo 1 kanala predkrilkov
    bool otkaz_osn_1k_prekr{};
    //otkaz osnovnogo 2 kanala predkrilkov
    bool otkaz_osn_2k_prekr{};
    //otkaz RASSOGLASOVANIE PREDKRILKI
    bool otkaz_rassgl_prekr{};
    //otkaz osnovnogo 1 kanala PCHK
    bool otkaz_osn_1k_PCHK{};
    //otkaz osnovnogo 2 kanala PCHK
    bool otkaz_osn_2k_PCHK{};
    //otkaz rassinhronizatsiya PCHK
    bool otkaz_RASSINHR_PCHK{};

    bool psr1kz{};
    bool prrkz{};
    bool prr1kz{};
    bool prr2kz{};
    bool sr1kz{};
    bool por1kz{};
    bool por2kz{};
    bool psr2kz{};
    bool por1kpr{};
    bool por2kpr{};
    bool prrkpchk{};
    bool prr1kpchk{};
    bool prr2kpchk{};
    bool por1kpchk{};//priznak osnovnogo kanala upravleniya
    bool por2kpchk{};
    bool otkaz_1k_prekr{};
    bool otkaz_2k_prekr{};
    bool prrkpr{};//priznak rezervnogo rezhima
    bool prr1kpr{};
    bool prr2kpr{};
    bool psr1kpr{};
    bool psr2kpr{};

    double Kz{1.0};
    double delta_z_zad{};
    double Ddelta_z_l;
    double Ddelta_z_p;
    double Kpr{1.0};
    double delta_pr_zad;
    double delta_pr_vh;
    double Ddelta_pr_l;
    double Ddelta_pr_p;
    double X_zad;
    double Kgs{};
    double Kgs1{};
    double Kgs2{};
    double Kgs3{};
    double Kgs4{};
    double Kpchk{};
    double Kpchk1{};
    double Kpchk2{};
    double Kpchk3{};
    double Kpchk4{};
    double delta_ruk_vh;
    double XL_120;
    double XP_121;
    double XTR_122;
    double delta_pr;
    double delta_pr_116;
    double delta_pr_l_114;
    double delta_pr_p_115;
    double delta_ruk_123;
    double delta_ruz_113;
    double delta_z_112;
    double delta_z_l_110{};
    double delta_zr_vh_bf;
    double delta_z_p_111{};

    enum s2_2790_pos{off, bolshe, menshe};

private:
//tracking a position of curPos and changing uksPlusParam and uksMinusParam
//correspondly
void posChnged(double &prePos, double &curPos,
                 bool &uksPlusParam, bool &uksMinusParam);
public:
    virtual void updateLogic();

    void wingsmech_1();
    void wingsmech_2();
    void wingsmech_3();
    void wingsmech_4();
};
