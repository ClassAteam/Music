#include "cabinlighting_4.h"


void cabinlighting_int::cabinlighting_4()
{
static bool
    F1_3311,
    F2_3311,
    F3_3311,
    F4_3311,
    F5_3311,
    F6_3311,
    F7_3311,
    F8_3311,
    otkaz_vstrosv_busto3_1_k1_lev,
    otkaz_vstrosv_busto3_1_k1_prav,
    otkaz_vstrosv_busto3_2_k1_lev,
    otkaz_vstrosv_busto3_2_k2_prav,
    otkaz_vstrosv_busto3_1_k1_shto,
    otkaz_vstrosv_busto3_1_k1_shtn,
    otkaz_vstrosv_busto3_1_k2_shto,
    otkaz_vstrosv_busto3_1_k2_shtn;

//static double
//    alpha_ra_a5,
//    alpha_ra_a6,
//    alpha_ra_a7,
//    alpha_ra_a8,
//    alpha_ra_a10,
//    alpha_ra_a11,
//    alpha_ra_a12,
//    alpha_ra_a13,
//    alpha_ra_a14;
    // A1

    if (exchange::ush1l >= 18.0 && F1_3311 && !otkaz_vstrosv_busto3_1_k1_lev)
        PBUSTO3_1_1k = true;
    else
        PBUSTO3_1_1k = false;

    // A2

    if(exchange::ush2p >= 18.0 && F2_3311 && !otkaz_vstrosv_busto3_1_k1_prav)
        PBUSTO3_1_2k = true;
    else
        PBUSTO3_1_2k = false;

    // A3

    if(exchange::ush1dpl >= 18.0 && F3_3311 && !otkaz_vstrosv_busto3_2_k1_lev)
        PBUSTO3_2_1k = true;
    else
        PBUSTO3_2_1k = false;

    // A4

    if(exchange::ush2dpp >= 18.0 && F4_3311 && !otkaz_vstrosv_busto3_2_k2_prav)
        PBUSTO3_2_2k = true;
    else
        PBUSTO3_2_2k = false;

    // B1

    // C1


    // B2


    // C2

    // D1

//    if (PBUSTO3_1_1k)
//    {
//        UVOPPD11 = two_points_to_Y(alpha_ra_a8, 0, 1, 0, 1);   //Dummy
//        PK11PPDVO = true;
//        UVOPBL11 = two_points_to_Y(alpha_ra_a10, 0, 1, 0, 1);   //Dummy
//        PK11PBLVO = true;
//    }

//    else
//    {
//        UVOPPD11 = false;
//        PK11PPDVO = false;
//        UVOPBL11 = false;
//        PK11PBLVO = false;
//    }

//    // D2

//    if (PBUSTO3_2_1k)
//    {
//        UVOPPD21 = two_points_to_Y(alpha_ra_a8, 0 , 1, 0, 1);   //Dummy
//        PK21PPDVO = true;
//        UVOPBL21 = two_points_to_Y(alpha_ra_a10, 0 , 1, 0, 1);   //Dummy
//        PK21PBLVO = true;
//    }

//    else
//    {
//        UVOPPD21 = false;
//        PK21PPDVO = false;
//        UVOPBL21 = false;
//        PK21PBLVO = false;
//    }



    //////////////////////////////////////////////////////////////////////////////
    // A5

    if (exchange::ush1l >= 18.0 && F5_3311 && !otkaz_vstrosv_busto3_1_k1_shto)
        PBUSTO3_3_1k = true;
    else
        PBUSTO3_3_1k = false;

    // A6

    if(exchange::ush2p >= 18.0 && F6_3311 && !otkaz_vstrosv_busto3_1_k2_shto)
        PBUSTO3_3_2k = true;
    else
        PBUSTO3_3_2k = false;

    // A7

    if(exchange::ush1dpl >= 18.0 && F7_3311 && !otkaz_vstrosv_busto3_1_k1_shtn)
        PBUSTO3_4_1k = true;
    else
        PBUSTO3_4_1k = false;

    // A8
    if(exchange::ush2dpp >= 18.0 && F8_3311 && !otkaz_vstrosv_busto3_1_k2_shtn)
        PBUSTO3_4_2k = true;
    else
        PBUSTO3_4_2k = false;

    // B2

//    if (PBUSTO3_3_1k)
//    {
//        UVOPDSHO1 = two_points_to_Y(alpha_ra_a11, 0, 1, 0, 1); //Just dummy
//        PK1PDSHOVO = true;
//    }
//    else
//    {
//        UVOPDSHO1 = false;
//        PK1PDSHOVO = false;
//    }

//    // C3

//    if (PBUSTO3_3_1k && powerdc_inst.ush1l >= 18.0)
//    {
//        UVOLBSH1 = two_points_to_Y(alpha_ra_a12, 0, 1, 0, 1);   //Dummy
//        PK1LBSHVO = true;
//    }

//    else
//    {
//        UVOLBSH1 =false;
//        PK1LBSHVO = false;
//    }

//    // B3

//    if (PBUSTO3_4_1k)
//    {
//        UVOPDSHO2 = two_points_to_Y(alpha_ra_a11, 0, 1, 0, 1); //Just dummy
//        PK2PDSHOVO = true;
//    }
//    else
//    {
//        UVOPDSHO2 = false;
//        PK2PDSHOVO = false;
//    }

//    // B4

//    if (PBUSTO3_3_2k)
//    {
//        UVOPDSHN1 = two_points_to_Y(alpha_ra_a13, 0, 1, 0, 1); //Just dummy
//        PK1PDSHNVO = true;
//    }
//    else
//    {
//        UVOPDSHN1 = false;
//        PK1PDSHNVO = false;
//    }

//    // C4

//    if (PBUSTO3_4_1k && powerdc_inst.ush1dpl >= 18.0)
//    {
//        UVOLBSH2 = two_points_to_Y(alpha_ra_a12, 0, 1, 0, 1);   //Dummy
//        PK2LBSHVO = true;
//    }
//    else
//    {
//        UVOLBSH2 = false;   //Dummy
//        PK2LBSHVO = false;
//    }

//    // C5

//    if (PBUSTO3_3_2k && powerdc_inst.ush1l >= 18.0)
//    {
//        UVOPBSH1 = two_points_to_Y(alpha_ra_a14, 0, 1, 0, 1);   //Dummy
//        PK2PBSHVO = true;
//    }
//    else
//    {
//        UVOPBSH1 = false;
//        PK2PBSHVO = false;
//    }

//    // B5

//    if (PBUSTO3_4_2k)
//    {
//        UVOPDSHN2 = two_points_to_Y(alpha_ra_a13, 0, 1, 0, 1); //Just dummy
//        PK2PDSHNVO = true;
//    }
//    else
//    {
//        UVOPDSHN2 = false;
//        PK2PDSHNVO = false;
//    }

//    // C6

//    if (PBUSTO3_4_2k && powerdc_inst.ush1dpl >= 18.0)
//    {
//        UVOPBSH2 = two_points_to_Y(alpha_ra_a14, 0, 1, 0, 1);   //Dummy
//        PK2PBSHVO = true;
//    }
//    else
//    {
//        UVOPBSH2 = false;
//        PK2PBSHVO = false;
//    }
}
