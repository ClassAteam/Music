#include "bailout_1_2.h"

void bailout_int::bailout_1_2()
{

    H1_10010 = false;
    H2_10010 = false;
    H8_10010 = false;
    H9_10010 = false;
    H3_10010 = false;
    H4_10010 = false;
    H11_10010 = false;
    H10_10010 = false;

    if(exchange::ush1dpl >= 18.0)
    {
        if(s18_2910)
        {
            H1_10010 = true;
            H2_10010 = true;
            H8_10010 = true;
            H9_10010 = true;
            H3_10010 = true;
            H4_10010 = true;
            H11_10010 = true;
            H10_10010 = true;
        }
        else
        {
            if(s9_2910)
            {
                H3_10010 = true;
                H4_10010 = true;
                H11_10010 = true;
                H10_10010 = true;
            }

            if(s10_2910)
            {
                if(!KVRKLL) H1_10010 = true;
                if(!KVRKPL) H2_10010 = true;
                if(!KVRKSHO) H8_10010 = true;
                if(!KVRKSHN) H9_10010 = true;
            }
        }
    }

    if(exchange::ush2l >= 18.0)
        PSPKLL = true;
    else
        PSPKLL = false;

    if(exchange::ush2p >= 18.0)
        PSPKPL = true;
    else
        PSPKPL = false;

    if(exchange::ush1dpl >= 18.0)
        PSRKVLL = true;
    else
        PSRKVLL = false;

    if(exchange::ush2dpl >= 18.0)
        PSRKVPL = true;
    else
        PSRKVPL = false;

    if(exchange::ush2l >= 18.0)
        PSRKVSHO = true;
    else
        PSRKVSHO = false;

    if(exchange::ush2p >= 18.0)
        PSRKVSHN = true;
    else
        PSRKVSHN = false;

    bss_inst.BSS838X7G = false;
    bss_inst.BSS939X1N = false;
    bss_inst.BSS824X1d = false;
    bss_inst.BSS811X1R = false;
    bss_inst.BSS811X1T = false;

    if(exchange::ush1dpl >= 18.0)
    {
        if(s13_10010) bss_inst.BSS939X1N = true;
        if(s14_10010) bss_inst.BSS838X7G = true;
    }
    uks_inst.UKS3X312 = false;
    uks_inst.UKS3X313 = false;

    if(exchange::ush2l >= 18.0)
        if(s12_10020) uks_inst.UKS3X312 = true;

    if(exchange::ush2p >= 18.0)
        if(s13_10020) uks_inst.UKS3X313 = true;

    if(exchange::ush1dpl >= 18.0)
    {
        if(!s12_10020)
        {
            if(KVRKLL && KVZLL) PRM1 = true;
            else
            {
                if(PRM1)PRM1 = true;
                else PRM1 = false;
            }
        }

        if(!s13_10020)
        {
            if(KVRKPL && KVZPL) PRM2 = true;
            else
            {
                if(PRM2)PRM2 = true;
                else PRM2 = false;
            }
        }
        else PRM2 = false;

        if(KVRKSHO && KVZSHO) PRM3 = true;
        else
        {
            if(PRM3)PRM3 = true;
            else PRM3 = false;
        }

        if(KVRKSHN && KVZSHN) PRM4 = true;
        else
        {
            if(PRM4)PRM4 = true;
            else PRM4 = false;
        }

        if(!PRM1)
        {
            if(!PRM2)
            {
                if(PRM3 || PRM4)
                {
                    if(throw_tick * TICK >= 2000)
                    {
                        PPRM3 = true;
                        PPRM4 = true;
                        bss_inst.BSS811X1R = true;
                        bss_inst.BSS811X1T = true;
                    }
                    else throw_tick++;
                }
                else throw_tick = 0;
            }
            else
            {
                if(s15_10010)
                {
                    if(throw_tick * TICK >= 3000) PPRM2 = true;
                    else throw_tick++;

                    if(throw_tick * TICK >= 2000)
                    {
                        PPRM3 = true;
                        PPRM4 = true;
                        bss_inst.BSS811X1R = true;
                        bss_inst.BSS811X1T = true;
                    }
                }
                else
                {
                    bss_inst.BSS824X1d = true;
                    if(throw_tick * TICK >= 3000)
                    {
                        PPRM1 = true;
                        PPRM2 = true;
                    }
                    else throw_tick++;

                    if(throw_tick * TICK >= 2000)
                    {
                        PPRM3 = true;
                        PPRM4 = true;
                        bss_inst.BSS811X1R = true;
                        bss_inst.BSS811X1T = true;
                    }
                }
            }
        }
        else
        {
            bss_inst.BSS824X1d = true;
            if(throw_tick * TICK >= 3000)
            {
                PPRM1 = true;
                PPRM2 = true;
            }
            else throw_tick++;

            if(throw_tick * TICK >= 2000)
            {
                PPRM3 = true;
                PPRM4 = true;
                bss_inst.BSS811X1R = true;
                bss_inst.BSS811X1T = true;
            }
        }
    }
    else
    {
        if(KVRKLL)PPRM1 = true;
        if(KVRKPL)PPRM2 = true;
        if(KVRKSHO)PPRM3 = true;
        if(KVRKSHN)PPRM4 = true;
    }
}

