#include "brakes_6.h"

void brakes_int::brakes_6()
{
    //start logic
    K5_3650 = false;

    if(exchange::ush1dpp >= 18.0)
    {
        if(S1_9921 || S2_9921)
            K1_9921 = true;

        if(K2_9921)
            K1_9921 = false;

        if(S4_9921)
        {
            if(S3_9921)
                K2_9921 = true;
            else
            {
                if(K1_9921)
                {

                }
                else
                {
                    if(exchange::S34_3230 && exchange::S36_3230)
                    {

                    }
                    else
                        K2_9921 = true;
                }
            }
        }
        else
            K2_9921 = false;

        if(Patp >= 60.0)
            K5_3650 = true;
    }
    else
    {
        K1_9921 = false;
        K2_9921 = false;
    }

    bss_inst.BSS824X1f = false;
    uks_inst.UKS3X311 = false;

    if(exchange::ush1dpp >= 18.0 && Patp < 60)
    {
        bss_inst.BSS824X1f = true;
        uks_inst.UKS3X311 = true;
    }

    if(exchange::ushal >= 18.0 && K1_9921 && Patp >= 60.0)
    {
        PVTP = true;
        if(K2_9921)
        {
            PSTP = true;
            PVTP = false;
        }
    }

    if(PVTP)
    {
        S4_9921 = true;
        S5_9921 = true;
        S7_9921 = true;
    }

    if(PSTP)
        S6_9921 = true;
    else
        S6_9921 = false;

    K5_9921 = false;
    K6_9921 = false;
    uks_inst.UKS3X39 = false;
    bss_inst.BSS824X1N = false;
    uks_inst.UKS3X310 = false;
    bss_inst.BSS824X1R = false;

    if(exchange::ushap >= 18.0)
    {
        if(S6_9921)
        {
            if(S7_9921)
            {
                K5_9921 = true;
                bss_inst.BSS824X1N = true;
                uks_inst.UKS3X39 = true;
            }
        }
        else
        {
            if(S5_9921)
            {
                K6_9921 = true;
                bss_inst.BSS824X1R = true;
                uks_inst.UKS3X310 = true;
            }
        }
    }
}

    //end logic
