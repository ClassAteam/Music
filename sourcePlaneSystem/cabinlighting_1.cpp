#include "cabinlighting_1.h"


void cabinlighting_int::cabinlighting_1()
{
    pbusto4[0][0] = (exchange::ush1l >= 18.0 && F1_3310 && !otk_pbusto4[0][0])
                        ? true : false;
    pbusto4[0][1] = (exchange::ush2p >= 18.0 && F2_3310 && !otk_pbusto4[0][1])
                        ? true : false;
    pbusto4[1][0] = (exchange::ush1dpl >= 18.0 && F3_3310 && !otk_pbusto4[1][0])
                        ? true : false;
    pbusto4[1][1] = (exchange::ush2dpp >= 18.0 && F4_3310 && !otk_pbusto4[1][1])
                        ? true : false;

    PK1PBLLZO = (pbusto4[0][0]) ? true : false;
    PK1LSPDZO = (pbusto4[0][0]) ? true : false;

    PK2PBLLZO = (pbusto4[1][0]) ? true : false;
    PK2LSPDZO = (pbusto4[1][0]) ? true : false;

    PK1PBPLZO = (pbusto4[0][1]) ? true : false;
    PK1PPDZO = (pbusto4[0][1]) ? true : false;

    PK2PBPLZO = (pbusto4[1][1]) ? true : false;
    PK2PPDZO = (pbusto4[1][1]) ? true : false;

    PK1SPLZO = (exchange::ush1dpl >= 18.0 && F3_3310) ? true : false;
    PK2SPLZO = (exchange::ush1dpp >= 18.0 && F4_3310) ? true : false;

//    if (exchange::ush1l >= 18.0 && PBUSTO4_2_1k)
//    {
//        UZOPBLL2 = two_points_to_Y(alpha_ra2a3, 0, 1, 0.75, 1);
//        PK12PBLLZO = true;
//    }
//    else
//    {
//        UZOPBLL1 = false;
//        PK12PBLLZO = false;
//    }

//    if (exchange::ush1dpl >= 18.0 && PBUSTO4_1_1k)
//    {
//        UZOPBLL1 = two_points_to_Y(alpha_ra2a3, 0, 1, 0.75, 1);
//        PK11PBLLZO = true;
//    }
//    else
//    {
//        UZOPBLL1 = false;
//        PK11PBLLZO = false;
//    }

//    if (PBUSTO4_1_2k)
//    {
//        UZOPBPL1 = two_points_to_Y(alpha_ra2a7, 0, 1, 0.75, 1);
//        PK12PBPLZO = true;
//    }
//    else
//    {
//        UZOPBPL1 = false;
//        PK12PBPLZO = false;
//    }

//    if (PBUSTO4_2_2k)
//    {
//        UZOPBPL2 = two_points_to_Y(alpha_ra2a7, 0, 1, 0.75, 1);
//        PK22PBPLZO = true;
//    }
//    else
//    {
//        UZOPBPL2 = false;
//        PK22PBPLZO = false;
//    }

//    if (exchange::ush1dpl >= 18.0 && PBUSTO4_1_1k)
//    {
//        UZOLSPD1 = two_points_to_Y(alpha_ra2a4, 0 , 1, 0.75, 1);
//        PK1LSPDZO = true;
//    }
//    else
//    {
//        UZOLSPD1 = false;
//        PK1LSPDZO = false;
//    }

//    if (exchange::ush1l >= 18.0 && PBUSTO4_2_1k)
//    {
//        UZOLSPD2 = two_points_to_Y(alpha_ra2a4, 0, 1, 0.75, 1);
//        PK2LSPDZO = true;
//    }
//    else
//    {
//        UZOLSPD2 = false;
//        PK2LSPDZO = false;
//    }

//    if(PBUSTO4_1_2k)
//    {
//        UZOPPD1 = two_points_to_Y(alpha_ra2a6, 0, 1, 0.75, 1 );
//        PK1PPDZO = true;
//    }
//    else
//    {
//        UZOPPD1 = false;
//        PK1PPDZO = false;
//    }

//    if (PBUSTO4_2_2k)
//    {
//        UZOPPD2 = two_points_to_Y(alpha_ra2a6, 0, 1, 0.75, 1 );
//        PK2PPDZO = true;
//    }
//    else
//    {
//        UZOPPD2 = false;
//        PK2PPDZO = false;
//    }

//    if (exchange::ush1dpl >= 18.0)
//    {
//        UZOSPLS1 = two_points_to_Y(alpha_ra50a8, 0, 1, 0.75, 1 );
//        PK1SPLZO = true;
//    }
//    else
//    {
//        UZOSPLS1 = false;
//        PK1SPLZO = false;
//    }

//    if (exchange::ush2dpp >= 18.0)
//    {
//        UZOSPPS1 = two_points_to_Y(alpha_ra50a8, 0, 1, 0.75, 1 );
//        PK1SPPSZO = true;
//    }
//    else
//    {
//        UZOSPPS1 = false;
//        PK1SPPSZO = false;
//    }

//    if (exchange::ush1l >= 18.0 && F5_3310 && !otkaz_zaliv_osvesh_sho_1)
//        PBUSTO4_3_1k = true;
//    else
//        PBUSTO4_3_1k = false;


//    if(powerdc_int::purg27lk4)
//    {
//        PSSD37RKL = false;
//        PSSD37RKSH = false;
//        PSSD37RKL_D = true;
//        PSSD37RKSH_D = true;
//    }
//    else
//    {
//        if(exchange::ush2l >= 18.0 && F1_3312)
//        {
//            PSSD37RKL = true;
//            PSSD37RKSH = true;
//            PSSD37RKL_D = false;
//            PSSD37RKSH_D = false;
//        }
//        else
//        {
//            PSSD37RKL = false;
//            PSSD37RKSH = false;
//            PSSD37RKL_D = false;
//            PSSD37RKSH_D = false;
//        }
//    }

//    if(exchange::ush1dpl >= 18.0 && F7_3310 && !otkaz_zaliv_osvesh_sho_2)
//        PBUSTO4_4_1k = true;
//    else
//        PBUSTO4_4_1k = false;

//    if(exchange::ush2dpp >= 18.0 && F8_3310 && !otkaz_zaliv_osvesh_shn_2)
//        PBUSTO4_4_2k = true;
//    else
//        PBUSTO4_4_2k = false;

//    if (exchange::ush1l >= 18.0 && PBUSTO4_4_1k)
//    {
//        UZOPDSHO1 = two_points_to_Y(alpha_ra2a11,0, 1, 0.75, 1 );
//        PK1PDSHOZO = true;
//    }
//    else
//    {
//        UZOPDSHO1 = false;
//        PK1PDSHOZO = false;
//    }

//    if (exchange::ush1dpl >= 18.0 && PBUSTO4_3_1k)
//    {
//        UZOPDSHO2 = two_points_to_Y(alpha_ra2a11, 0, 1, 0.75, 1);
//        PK2PDSHOZO = true;
//    }
//    else
//    {
//        UZOPDSHO2 = false;
//        PK2PDSHOZO = false;
//    }

//    if (PBUSTO4_3_1k)
//    {
//        UZOLBSHO1 = two_points_to_Y(alpha_ra2a12, 0, 1, 0.75, 1);
//        PK1LBSHOZO = true;
//    }
//    else
//    {
//        UZOLBSHO1  = false;
//        PK1LBSHOZO = true;
//    }

//    if (PBUSTO4_4_1k)
//    {
//        UZOLBSHO2 = two_points_to_Y(alpha_ra2a12, 0 , 1, 0.75, 1);
//        PK2LBSHOZO = true;
//    }
//    else
//    {
//        UZOLBSHO2 = false;
//        PK2LBSHOZO = false;
//    }

//    if (exchange::ush1dpp >= 18.0 && PBUSTO4_3_2k)
//    {
//        UZOPDSHN1 = two_points_to_Y(alpha_ra2a14, 0, 1, 0.75, 1);
//        PK1PDSHNZO = true;
//    }
//    else
//    {
//        UZOPDSHN1 = false;
//        PK1PDSHNZO = false;
//    }

//    if (exchange::ush2p >= 18.0 && PBUSTO4_4_2k)
//    {
//        UZOPDSHN2 = two_points_to_Y(alpha_ra2a14, 0 , 1, 0.75, 1);
//        PK2PDSHNZO = true;
//    }
//    else
//    {
//        UZOPDSHN2 = false;
//        PK2PDSHNZO = false;
//    }

//    if (PBUSTO4_4_2k)
//    {
//        UZOPBSHN1 = two_points_to_Y(alpha_ra2a13, 0 , 1, 0.75, 1);
//        PK1PBSHNZO = true;
//    }
//    else
//    {
//        UZOPBSHN1  = false;
//        PK1PBSHNZO = true;
//    }

//    if (PBUSTO4_3_2k)
//    {
//        UZOPBSHN2 = two_points_to_Y(alpha_ra2a13, 0 , 1, 0.75, 1);
//        PK2PBSHNZO = true;
//    }
//    else
//    {
//        UZOPBSHN2  = false;
//        PK2PBSHNZO = true;
//    }

//    if (exchange::ush2l >= 18.0 && F1_3312)
//    {
//        USOOKL = two_points_to_Y(alpha_ra50a1, 0, 1, 0.75, 1);
//        PSSD37RKL = true;
//        USOOKSH = two_points_to_Y(alpha_ra50a2, 0, 1, 0.75, 1);
//        PSSD37RKSH = true;
//    }
//    else
//    {
//        USOOKL = two_points_to_Y(alpha_ra50a1, 0, 1, 0.75, 1);
//        PSSD37RKL = false;
//        USOOKSH = two_points_to_Y(alpha_ra50a2, 0, 1, 0.75, 1);
//        PSSD37RKSH = false;
//    }

//    if (exchange::ush1dpl >= 18.0 && F2_3312)
//        PSSD42L = true;
//    else
//        PSSD42L = false;

//    if(exchange::ush2dpp >= 18.0 && F3_3312)
//        PSSD42P = true;
//    else
//        PSSD42P = false;
}
