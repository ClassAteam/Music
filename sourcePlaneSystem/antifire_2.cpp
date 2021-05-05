#include "antifire_2.h"

void antifire_int::antifire_2()
{
    //F91 toggle
    if(exchange::ush1dpl >= 16.0)
    {
        if (F9_2610)
            F91_2610 = true;
        else
            F91_2610 = false;
    }
    else
        F91_2610 = false;

    //F101 toggle
    if (exchange::ush1dpp >= 16.0)
    {
        if (F10_2610)
            F101_2610 = true;
        else
            F101_2610 = false;
    }

    //F181 toggle
    if(exchange::ush1dpl >= 16.0)
    {
        if(F18_2610)
            F181_2610 = true;
        else
            F181_2610 = false;
    }

    //F111 toggle
    if(exchange::ush2dpl >= 16.0)
    {
        if(F11_2610)
            F111_2610 = true;
        else
            F111_2610 = false;
    }

    //F121 toggle
    if (exchange::ush2dpl >= 16.0)
    {
        if (F12_2610)
            F121_2610 = true;
        else
            F121_2610 = false;
    }

    //F92 toggle
    if(F91_2610)
    {
        if(F101_2610)
        {
            F92_2610 = false;
        }
        else
        {
            if(F181_2610)
                F92_2610 = false;
            else
                F92_2610 = true;
        }
    }
    else
        F92_2610 = false;

    //K1 toggle
    if(F92_2610 && S1_2610)
        K1_2610 = true;
    else
        K1_2610 = false;

    //K3 toggle
    if(F92_2610 && S1_2610)
        K3_2610 = true;
    else
        K3_2610 = false;

    //K6 toggle
    if(F92_2610 && S1_2610)
        K6_2610 = true;
    else
        K6_2610 = false;

    //K9 toggle
    if(F92_2610 && S1_2610)
        K9_2610 = true;
    else
        K9_2610 = false;

    //K12 toggle
    if(F92_2610 && S1_2610)
        K12_2610 = true;
    else
        K12_2610 = false;

    //F911 toggle
    if (F92_2610 && S2_2610)
        F911_2610 = true;
    else
        F911_2610 = false;

    //F912 toggle
    if(F92_2610 && S2_2610)
        F912_2610 = true;
    else
        F912_2610 = false;

    //F913 toggle
    if (F92_2610 && S2_2610)
        F913_2610 = true;
    else
        F913_2610 = false;

    //F914 toggle
    if (F92_2610 && S2_2610)
        F914_2610 = true;
    else
        F914_2610 = false;

    //F915 toggle
    if (F92_2610 && S2_2610)
        F915_2610 = true;
    else
        F915_2610 = false;

    //F916 toggle
    if(F92_2610 && S2_2610)
        F916_2610 = true;
    else
        F916_2610 = false;

    //F917 toggle
    if(F92_2610 && S2_2610)
        F913_2610 = true;
    else
        F913_2610 = false;

    //PPBI toggle
    if(F82_2610)
    {
        if (F45_2610 || exchange::P2OBLOP || PAPDvh6)
            PPBI = true;
        else
            PPBI = false;
    }
    else
        PPBI = false;

    //K2 toggle
    if(PPBI)
    {
        if(K1_2610)
        {
            if(F911_2610 || F912_2610 || F913_2610 || F917_2610 || pozhar_vsu)
                K24_2610 = true;
        }
        else
        {
            if(pozhar_vsu)
                K24_2610 = true;
            else
                K24_2610 = false;
        }
    }
    else
        K24_2610 = false;

    //K42, K49toggle
    if (!F25_2610 && !F35_2610 && !F45_2610 && !F55_2610 && !F65_2610)
    {
        K49_2610 = false;
        K42_2610 = false;
    }
    else
    {
        if(F121_2610)
        {
            if(S13_2610)			//!!! non-defined switch, mb need enum type
                K49_2610 = true;
            else
            {
                if(S14_2610)
                    K49_2610 = true;
                else
                    K49_2610 = false;
            }

            if(S11_2610)			//!!! non-defined switch, mb need enum type
                K42_2610 = true;
            else
            {
                if(S12_2610)
                    K42_2610 = true;
                else
                    K42_2610 = false;
            }

        }
        else
            K49_2610 = false;
    }

    //K67 toggle
    if(F101_2610)
    {
        if (S15_2610)			//!!! the same here
            K67_2610 = true;
        else
            K67_2610 = false;
    }
    else
        K67_2610 = false;

    //K31toggle
    if(F25_2610)
    {
        if (!K67_2610)
        {
            if(F135_2805)
            {
                if(otkaz_avtomatiki_SPZ)
                    K31_2610 = false;
                else
                    K31_2610 = true;
            }
            else
                K31_2610 = false;
        }
        else
            K31_2610 = true;
    }
    else
        K31_2610 = false;

    //K32toggle
    if(F35_2610)
    {
        if(!K67_2610)
        {
            if(F145_2805)
            {
                if(otkaz_avtomatiki_SPZ)
                    K32_2610 = false;
                else
                    K32_2610 = true;
            }
            else
                K32_2610 = false;
        }
        else
            K32_2610 = true;
    }
    else
        K32_2610 = false;

    //K33toggle
    if(F45_2610)
    {
        if (K67_2610)
        {
            if(otkaz_avtomatiki_SPZ)
                K33_2610 = false;
            else
                K33_2610 = true;
        }
        else
            K33_2610 = true;
    }
    else
        K33_2610 = false;

    //K34toggle
    if(F55_2610)
    {
        if(!K67_2610)
        {
            if(F155_2805)
            {
                if(otkaz_avtomatiki_SPZ)
                    K34_2610 = false;
                else
                    K34_2610 = true;
            }
            else
                K34_2610 = false;
        }
        else
            K34_2610 = true;
    }
    else
        K34_2610 = false;

    //K35toggle
    if(F65_2610)
    {
        if(!K67_2610)
        {
            if(F165_2805)
            {
                if(otkaz_avtomatiki_SPZ) K35_2610 = false;
                else K35_2610 = true;
            }
            else K35_2610 = false;
        }
        else K35_2610 = true;
    }
    else K35_2610 = false;

    //K50 toggle
    if(F82_2610)
    {
        if(K3_2610)
        {
            if(F911_2610) K50_2610 = true;
            else
            {
                if(F912_2610) K50_2610 = true;
                else
                {
                    if(F917_2610) K50_2610 = true;
                    else
                    {
                        if(pozhar_1_dv) K50_2610 = true;
                        else K50_2610 = false;
                    }
                }
            }
        }
        else
        {
            if(pozhar_1_dv) K50_2610 = true;
            else K50_2610 = false;
        }
    }
    else K50_2610 = false;

    //K51 toggle
    if(!F72_2610) K51_2610 = false;
    else
    {
        if (K3_2610)
        {
            if(pozhar_1_dv) K51_2610 = true;
            else
            {
                if(peregrev_1_dv) K51_2610 = true;
                else K51_2610 = false;
            }
        }
        else
        {
            if (F914_2610 || F915_2610 || F916_2610 || F917_2610 ||  pozhar_1_dv || peregrev_1_dv)
                K51_2610 = true;
            else
                K51_2610 = false;
        }
    }

    //K53 toggle
    if(F82_2610)
    {
        if(K6_2610)
        {
            if(F911_2610) K53_2610 = true;
            else
            {
                if(F912_2610) K53_2610 = true;
                else
                {
                    if(F917_2610) K53_2610 = true;
                    else
                    {
                        if(pozhar_2_dv) K53_2610 = true;
                        else K53_2610 = false;
                    }
                }
            }
        }
        else
        {
            if(pozhar_2_dv) K53_2610 = true;
            else K53_2610 = false;
        }
    }
    else
        K50_2610 = false;

    //K54 toggle
    if(!F72_2610) K54_2610 = false;
    else
    {
        if(K6_2610)
        {
            if(pozhar_2_dv)
                K54_2610 = true;
            else
            {
                if(peregrev_2_dv) K54_2610 = true;
                else K54_2610 = false;
            }
        }
        else
        {
            if(F914_2610 || F915_2610 || F916_2610 || F917_2610 || pozhar_2_dv || peregrev_2_dv)
                K54_2610 = true;
            else
                K54_2610 = false;
        }
    }

    //K57 toggle
    if(F72_2610)
    {
        if(K9_2610)
        {
            if(F911_2610) K57_2610 = true;
            else
            {
                if(F912_2610) K57_2610 = true;
                else
                {
                    if(F917_2610) K57_2610 = true;
                    else
                    {
                        if(pozhar_3_dv) K57_2610 = true;
                        else K57_2610 = false;
                    }
                }
            }
        }
        else
        {
            if(pozhar_3_dv) K57_2610 = true;
            else K57_2610 = false;
        }
    }
    else
        K50_2610 = false;

    //K58 toggle
    if(!F72_2610) K58_2610 = false;
    else
    {
        if(K6_2610)
        {
            if(pozhar_2_dv) K58_2610 = true;
            else
            {
                if(peregrev_2_dv) K58_2610 = true;
                else K58_2610 = false;
            }
        }
        else
        {
            if(F914_2610 || F915_2610 || F916_2610 || F917_2610 || pozhar_3_dv || peregrev_3_dv)
                K58_2610 = true;
            else
                K58_2610 = false;
        }
    }

    //K60 toggle
    if(F72_2610)
    {
        if(K12_2610)
        {
            if(F911_2610) K60_2610 = true;
            else
            {
                if(F912_2610) K60_2610 = true;
                else
                {
                    if(F917_2610) K60_2610 = true;
                    else
                    {
                        if(pozhar_4_dv) K60_2610 = true;
                        else K60_2610 = false;
                    }
                }
            }
        }
        else
        {
            if(pozhar_4_dv) K60_2610 = true;
            else K60_2610 = false;
        }
    }
    else K60_2610 = false;

    //K61 toggle
    if(!F82_2610) K61_2610 = false;
    else
    {
        if(K6_2610)
        {
            if(pozhar_4_dv) K61_2610 = true;
            else
            {
                if(peregrev_4_dv) K61_2610 = true;
                else K61_2610 = false;
            }
        }
        else
        {
            if(F914_2610 || F915_2610 || F916_2610 || F917_2610 || pozhar_4_dv || peregrev_4_dv)
                K61_2610 = true;
            else
                K61_2610 = false;
        }
    }

    //PW toggles
    if(pnu)
    {
        PW_1_och_l = true;
        PW_1_och_o = true;
        PW_2_och = true;
        PW_3_och = true;
    }

    if(K31_2610  || K32_2610 || K34_2610 || K35_2610 || K33_2610)
    {
        if(F101_2610)
        {
            PW_1_och_l = false;
            if(F181_2610 == true) PW_1_och_o = false;
        }
    }

    if(F111_2610 && K42_2610) PW_2_och = false;

    if(F121_2610 && K49_2610) PW_3_och = false;
}
