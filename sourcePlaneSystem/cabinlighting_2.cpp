#include "cabinlighting_2.h"

void cabinlighting_int::cabinlighting_2()
{

    pbusto4[2][0] = (exchange::ush1l >= 18.0 && F5_3310 && !otk_pbusto4[2][0]);
    pbusto4[2][1] = (exchange::ush2p >= 18.0 && F6_3310 && !otk_pbusto4[2][1]);
    pbusto4[3][0] = (exchange::ush1dpl >= 18.0 && F7_3310 && !otk_pbusto4[3][0]);
    pbusto4[3][1] = (exchange::ush2dpp >= 18.0 && F8_3310 && !otk_pbusto4[3][1]);

    PK2PDSHOZO = (exchange::ush1l >= 18.0 && pbusto4[3][0]) ? true : false;
    PK1PDSHOZO = (exchange::ush1dpl >= 18.0 && pbusto4[2][0]) ? true : false;
    PK1LBSHOZO = (pbusto4[2][0]) ? true : false;
    PK2LBSHOZO = (pbusto4[3][0]) ? true : false;
    PK1PDSHNZO = (pbusto4[2][1] && exchange::ush1dpp >= 18.0) ? true : false;
    PK2PDSHNZO = (pbusto4[3][1] && exchange::ush1dpp >= 18.0) ? true : false;
    PK2PBSHNZO = (pbusto4[3][1]) ? true : false;
    PK1PBSHNZO = (pbusto4[2][1]) ? true : false;

    if(!powerdc_int::purg27lk4)
    {
        if(exchange::ush2l >= 18.0 && F1_3312)
        {
            PSSD37RKL = true;
            PSSD37RKSH = true;
        }
        else
        {
            PSSD37RKL = false;
            PSSD37RKSH = false;
        }
    }

    PSSD42L = (exchange::ush1dpl >= 18.0 && F2_3312) ? true : false;
    PSSD42P = (exchange::ush2dpp >= 18.0 && F3_3312) ? true : false;

}
