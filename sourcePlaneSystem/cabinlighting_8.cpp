#include "cabinlighting_4.h"


void cabinlighting_int::cabinlighting_8()
{
    pbusto3[0][0] = (exchange::ush1l >= 18.0 && F1_3311 && !otk_pbusto3[0][0])
                        ? true : false;
    pbusto3[0][1] = (exchange::ush2p >= 18.0 && F2_3311 && !otk_pbusto3[0][1])
                        ? true : false;
    pbusto3[1][0] = (exchange::ush1dpp >= 18.0 && F3_3311 && !otk_pbusto3[1][0])
                        ? true : false;

    pk11lspdvo = false;
    pk12lspdvo = false;
    pk11spvo = false;
    pk12spvo = false;
    pk11lblvo = false;
    pk12lblvo = false;
    pk11pblvo = false;
    pk12pblvo = false;
    pk11ppdvo = false;
    pk12ppdvo = false;

    pbusto3[1][1] = (exchange::ush2dpp >= 18.0 && F4_3311 && !otk_pbusto3[1][1])
                        ? true : false;

    if(pbusto3[0][0])
    {
        pk11lspdvo = true;
        pk11spvo = true;
        pk11lblvo = true;
        pk11ppdvo = true;
        pk11pblvo = true;
    }

    if(!pbusto3[0][1])
    {
        pk12lspdvo = true;
        pk12spvo = true;
        pk12lblvo = true;
        pk12ppdvo = true;
        pk12pblvo = true;
    }

    pk21lspdvo = false;
    pk22lspdvo = false;
    pk21spvo = false;
    pk22spvo = false;
    pk21lblvo = false;
    pk22lblvo = false;
    pk21pblvo = false;
    pk22pblvo = false;
    pk21ppdvo = false;
    pk22ppdvo = false;

    if(!pbusto3[1][0])
    {
        pk21lspdvo = true;
        pk21spvo = true;
        pk21lblvo = true;
        pk21ppdvo = true;
        pk21pblvo = true;
    }

    if(!pbusto3[1][1])
    {
        pk22lspdvo = true;
        pk22spvo = true;
        pk22lblvo = true;
        pk22ppdvo = true;
        pk22pblvo = true;
    }

    pbusto3[2][0] = (exchange::ush1l >= 18.0 && F5_3311 && !otk_pbusto3[2][0])
                        ? true : false;
    pbusto3[2][1] = (exchange::ush2p >= 18.0 && F6_3311 && !otk_pbusto3[2][1])
                        ? true : false;
    pbusto3[3][0] = (exchange::ush1dpl >= 18.0 && F7_3311 && !otk_pbusto3[3][0])
                        ? true : false;

    pk31pdshovo = false;
    pk32pdshovo = false;
    pk31lbshvo = false;
    pk32lbshvo = false;
    pk31pbshvo = false;
    pk32pbshvo = false;
    pk31pdshnvo = false;
    pk32pdshnvo = false;

    pbusto3[3][1] = (exchange::ush1dpp >= 18.0 && F8_3311 && !otk_pbusto3[3][1])
                        ? true : false;
    pk41pdshovo = false;
    pk42pdshovo = false;pk41lbshvo = false;
    pk42lbshvo = false;
    pk41pbshvo = false;
    pk42pbshvo = false;
    pk41pdshnvo = false;
    pk42pdshnvo = false;

    if(pbusto3[2][0])
    {
        pk31pdshovo = true;
        pk31lbshvo = true;
        pk31pbshvo = true;
        pk31pdshnvo = true;
    }
    if(pbusto3[2][1])
    {
        pk32pdshovo = true;
        pk32lbshvo = true;
        pk32pbshvo = true;
        pk32pdshnvo = true;
    }

    if(pbusto3[3][0])
    {
        pk41pdshovo = true;
        pk41lbshvo = true;
        pk41pbshvo = true;
        pk41pdshnvo = true;
    }
    if(pbusto3[3][1])
    {
        pk42pdshovo = true;
        pk42lbshvo = true;
        pk42pbshvo = true;
        pk42pdshnvo = true;
    }
}
