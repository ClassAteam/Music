#include "antiicing_6.h"


void antiicing_int::antiicing_6()
{
static int
    PSOBLP_sec,
    PSOBLL_sec,
    PSOBLL_tick,
    PSOBLP_tick;

    //PRSOL toggle
    if(exchange::ush1dpl >= 18.0 && exchange::s1_3080 && M < 1.25 && !otkaz_l_so121 &&
        exchange::ush1l >= 18.0)
        PRSOL = true;
    else
        PRSOL = false;

    //PRSOP toggle
    if(exchange::ush2dpp >= 18.0 && exchange::s2_3080 && M < 1.25 && !otkaz_p_so121 &&
        exchange::ush2p >= 18.0)
        prsop = true;
    else
        prsop = false;

    K2_3080 = false;
    PSOLD = false;
    PSOPD = false;

    //K2_3080 toggle by left channel
    if(PRSOL)
    {
        if(signal_obled || PSOBLL || otkaz_lozhn_srab_lev_so121)
        {
            K2_3080 = true;
            PSOLD = true;
        }
    }

    //K2_3080 toggle by right channel
    if(prsop)
    {
        if (signal_obled || PSOBLP || otkaz_lozhn_srab_prav_so121)
        {
            K2_3080 = true;
            PSOPD = true;
        }
    }

    //Block check left channel
    if(PRSOL)
    {
        if(exchange::s3_3080 && PSOBLL_sec == 0)
            PBSO1 = true;

        if(PBSO1)
        {
            PSOBLL_tick++;

            if((PSOBLL_tick * TICK) > 1000)
            {
                PSOBLL_sec++;
                PSOBLL_tick = 0;
            }

            if(PSOBLL_sec < 8) PSOBLL = true;
            else PSOBLL = false;

            if (PSOBLL_sec > 41 && PSOBLL_sec < 77)
            {
                PSOBLL = false;
                bss_inst.BSS825X5KK = true;
            }

            if(PSOBLL_sec >= 77)
            {
                bss_inst.BSS825X5KK = false;
                PBSO1 = false;
                PSOBLL_sec = 0;
            }
        }
    }
    else
    {
        PBSO1 = false;
        PSOBLL = false;
        bss_inst.BSS825X5KK = false;
        PSOBLL = 0;
        PSOBLL_sec = 0;
    }

    //Block check right channel
    if(prsop)
    {
        if(exchange::s3_3080 && PSOBLP_sec == 0) PBSO2 = true;

        if(PBSO2)
        {
            PSOBLP_tick++;

            if((PSOBLP_tick * TICK) > 1000)
            {
                PSOBLP_sec++;
                PSOBLP_tick = 0;
            }

            if (PSOBLP_sec < 8) PSOBLP = true;
            else PSOBLP = false;

            if (PSOBLP_sec > 41 && PSOBLP_sec < 77)
            {
                PSOBLP = false;
                bss_inst.BSS825X5MM = true;
            }

            if(PSOBLP_sec >= 77)
            {
                bss_inst.BSS825X5MM = false;
                PBSO2 = false;
                PSOBLP_sec = 0;
            }
        }
    }
    else
    {
        PBSO2 = false;
        PSOBLP = false;
        bss_inst.BSS825X5MM = false;
        PSOBLP = 0;
        PSOBLP_sec = 0;
    }

    //UKS1X212, UKS1X112 toggle
    uks_inst.UKS1X212 = false;
    uks_inst.UKS1X112 = false;
    if(K2_3080)
    {

        obled_svs = true;
        bss_inst.BSS824X1T = false;
        bss_inst.BSS824X1V = false;

        if(PSOLD)
        {
            uks_inst.UKS1X112 = true;
            bss_inst.BSS824X1T = true;
        }
        if(PSOPD)
        {
            uks_inst.UKS1X212 = true;
            bss_inst.BSS824X1V = true;
        }
    }
    else
    {
        obled_svs = false;
        bss_inst.BSS824X1T = false;
    }
}
