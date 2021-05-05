#include "antiicing_4.h"

void antiicing_int::antiicing_4()
{
    //K16_3030 toggle
    if (exchange::ush1dpl >= 18.0)
    {
        if(alpha_rud_1dv >= 65.0)
        {
            if((alpha_rud_2dv >= 65.0) || (alpha_rud_3dv >= 65.0))
                K16_3030 = true;
            else
            {
                if(K25_3230)
                {
                    if(S2_3030) K16_3030 = true;
                    else K16_3030 = false;
                }
                else
                {
                    if(K16_3030)
                        K16_3030 = true;
                    else
                    {
                        if(S2_3030)
                            K16_3030 = true;
                        else
                            K16_3030 = false;
                    }
                }
            }
        }
        else
        {
            if(K25_3230)
            {
                if(S2_3030)
                    K16_3030 = true;
                else
                    K16_3030 = false;
            }
            else
            {
                if(K16_3030)
                    K16_3030 = true;
                else
                {
                    if(S2_3030)
                        K16_3030 = true;
                    else
                        K16_3030 = false;
                }
            }
        }
    }
    else
        K16_3030 = false;

    //K18_3030 toggle
    if (exchange::ush1dpp >= 18.0)
    {
        if (alpha_rud_2dv >= 65.0)
        {
            if((alpha_rud_3dv >= 65.0) || (alpha_rud_4dv >= 65.0))
                K18_3030 = true;
            else
            {
                if(K24_3230)
                {
                    if(S2_3030)
                        K18_3030 = true;
                    else
                        K18_3030 = false;
                }
                else
                {
                    if(K18_3030)
                        K18_3030 = true;
                    else
                    {
                        if(S2_3030)
                            K18_3030 = true;
                        else
                            K18_3030 = false;
                    }
                }
            }
        }
        else
        {
            if(K24_3230)
            {
                if(S2_3030)
                    K18_3030 = true;
                else
                    K18_3030 = false;
            }
            else
            {
                if(K18_3030)
                    K18_3030 = true;
                else
                {
                    if(S2_3030)
                        K18_3030 = true;
                    else
                        K18_3030 = false;
                }
            }
        }
    }
    else
        K18_3030 = false;

    if (exchange::ushap >= 18.0 && K24_3230 && exchange::usho1p >= 18.0 && S1_3030)
        PKPPD = true;
    else
        PKPPD = false;

    // K2_3030 toggle
    if(PKPPD)
        K2_3030 = true;
    else
    {
        if(exchange::ush2p < 18.0 || M < 1.25)
            K2_3030 = false;
    }

    // K5_3030 toggle
    if(PKPPD)
        K5_3030 = true;
    else
    {
        if(exchange::ush2p < 18.0 || M < 1.25)
            K5_3030 = false;
    }

    // K8_3030 toggle
    if(PKPPD)
        K8_3030 = true;
    else
    {
        if(exchange::ush2p < 18.0 || M < 1.25)
            K8_3030 = false;
    }

    // K1_3030 toggle
    if(K18_3030 && !K2_3030) K1_3030 = true;
    else K1_3030 = false;

    // K4_3030 toggle
    if(K16_3030 && !K5_3030) K4_3030 = true;
    else K4_3030 = false;

    // K7_3030 toggle
    if(K16_3030 && !K8_3030)
        K7_3030 = true;
    else
        K7_3030 = false;

    // POPPD2 toggle
    if(exchange::ush2p > 18.0 && K1_3030)
        poppd2 = true;
    else
        poppd2 = false;

    // POPPD1 toggle
    if (exchange::ush1dpl  > 18.0 && K4_3030)
        poppd1 = true;
    else
        poppd1 = false;

    // POPPD3 toggle
    if(exchange::ush2l > 18.0 && K7_3030)
        poppd3 = true;
    else
        poppd3 = false;

    //lights toggle
    if(PKPPD)
    {
        obogrev_ppd1_ispr = true;
        obogrev_ppd2_ispr = true;
        obogrev_ppd3_ispr = true;
    }
    else
    {
        obogrev_ppd1_ispr = false;
        obogrev_ppd2_ispr = false;
        obogrev_ppd3_ispr = false;
    }

    if(exchange::ush1dpp >= 18)
    {
        if(K1_3030 && K4_3030 && K7_3030)
            bss_inst.BSS811X1Y = false;
        else
            bss_inst.BSS811X1Y = true;
    }
    else
        bss_inst.BSS811X1Y = false;

}
