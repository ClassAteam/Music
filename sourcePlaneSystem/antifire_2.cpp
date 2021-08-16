#include "antifire_2.h"
#include "brakes_int.h"

extern brakes_int brakes;
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
    else
        F101_2610 = false;

    //F181 toggle
    if(exchange::ush1dpl >= 16.0)
    {
        if(F18_2610)
            F181_2610 = true;
        else
            F181_2610 = false;
    }
    else
        F181_2610 = false;

    //F111 toggle
    if(exchange::ush2dpl >= 16.0)
    {
        if(F11_2610)
            F111_2610 = true;
        else
            F111_2610 = false;
    }
    else
        F111_2610 = false;

    //F121 toggle
    if (exchange::ush2dpl >= 16.0)
    {
        if (F12_2610)
            F121_2610 = true;
        else
            F121_2610 = false;
    }
    else
        F121_2610 = false;

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
    if(F92_2610 && S1_2610 == s1_2610::mg1dv)
        K1_2610 = true;
    else
        K1_2610 = false;

    //K3 toggle
    if(F92_2610 && S1_2610 == s1_2610::mg2dv)
        K3_2610 = true;
    else
        K3_2610 = false;

    //K6 toggle
    if(F92_2610 && S1_2610 == s1_2610::mg3dv)
        K6_2610 = true;
    else
        K6_2610 = false;

    //K9 toggle
    if(F92_2610 && S1_2610 == s1_2610::mg4dv)
        K9_2610 = true;
    else
        K9_2610 = false;

    //K12 toggle
    if(F92_2610 && S1_2610 == s1_2610::vsu)
        K12_2610 = true;
    else
        K12_2610 = false;

    //F911 toggle
    if (F92_2610 && S2_2610 == s2_2610::gr1)
        F911_2610 = true;
    else
        F911_2610 = false;

    //F912 toggle
    if(F92_2610 && S2_2610 == s2_2610::gr2)
        F912_2610 = true;
    else
        F912_2610 = false;

    //F913 toggle
    if (F92_2610 && S2_2610 == s2_2610::gr3)
        F913_2610 = true;
    else
        F913_2610 = false;

    //F914 toggle
    if (F92_2610 && S2_2610 == s2_2610::gr4)
        F914_2610 = true;
    else
        F914_2610 = false;

    //F915 toggle
    if (F92_2610 && S2_2610 == s2_2610::gr5)
        F915_2610 = true;
    else
        F915_2610 = false;

    //F916 toggle
    if(F92_2610 && S2_2610 == s2_2610::gr6)
        F916_2610 = true;
    else
        F916_2610 = false;

    //F917 toggle
    if(F92_2610 && S2_2610 == s2_2610::pozhar)
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
        K67_2610 = false;
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
        }
        else
            K49_2610 = false;

        if(F111_2610)
        {
            if(S11_2610) K42_2610 = true;
            else
            {
                if(S12_2610) K42_2610 = true;
                else K42_2610 = false;
            }
        }
        else K42_2610 = false;

        if(F101_2610)
        {
            if (S15_2610) K67_2610 = true;
            else K67_2610 = false;
        }
        else K67_2610 = false;
    }



    //K67 toggle

    //K31toggle
    if(F25_2610)
    {
        if(!K67_2610)
        {
            if(F135_2805)
            {
                if(otkaz_avtomatiki_SPZ) K31_2610 = false;
                else K31_2610 = true;
            }
            else K31_2610 = false;
        }
        else K31_2610 = true;
    }
    else K31_2610 = false;

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
        uks_inst.UKS3X18 = false;
        uks_inst.UKS4X37 = false;
    }
    else
    {
        uks_inst.UKS3X18 = false;
        uks_inst.UKS4X37 = false;
    }

    if(K31_2610  || K32_2610 || K34_2610 || K35_2610 || K33_2610)
    {
        if(F101_2610)
        {
            PW_1_och_l = false;
            uks_inst.UKS3X18 = true;

        }

        if(F181_2610)
        {
            PW_1_och_o = false;
            uks_inst.UKS4X37 = true;
        }
    }

    if(F111_2610 && K42_2610) PW_2_och = false;

    if(F121_2610 && K49_2610) PW_3_och = false;

    bss_inst.BSS913X1A = false;
    bss_inst.BSS913X1R = false;
    bss_inst.BSS913X1f = false;
    bss_inst.BSS913X1v = false;

    bss_inst.BSS825X5f_b = false;
    bss_inst.BSS825X5h_b = false;
    bss_inst.BSS825X5j_b = false;
    bss_inst.BSS825X5n_b = false;

    bss_inst.BSS825X5R = false;
    bss_inst.BSS825X5T = false;

    bss_inst.BSS825X5f = false;
    bss_inst.BSS825X5h = false;
    bss_inst.BSS825X5j = false;
    bss_inst.BSS825X5n = false;

    //1
    if(F25_2610)
    {
        if(exchange::ushal >= 18.0) bss_inst.BSS913X1A = true;

        if(exchange::ushap >= 18.0)
        {
            if(!brakes.X1_45_7620) bss_inst.BSS825X5f = true;
            else bss_inst.BSS825X5f_b = true;
        }

    }
    else
    {
        if(ezr_23sku1_vikl_dv1)
        {
            bss_inst.BSS913X1A = true;
            if(exchange::ushap >= 18.0 && brakes.X1_45_7620)
                bss_inst.BSS825X5f_b = true;
            else
                bss_inst.BSS825X5f = true;
        }
        else
        {
            if(exchange::ushap >= 18.0 && !brakes.X1_45_7620)
                bss_inst.BSS825X5f = true;
        }
    }

    //2
    if(F35_2610)
    {
        if(exchange::ushal >= 18.0) bss_inst.BSS913X1R = true;

        if(exchange::ushap >= 18.0)
        {
            if(!brakes.X2_45_7620) bss_inst.BSS825X5h = true;
            else bss_inst.BSS825X5h_b = true;
        }

    }
    else
    {
        if(ezr_23sku2_vikl_dv2)
        {
            bss_inst.BSS913X1R = true;
            if(exchange::ushap >= 18.0 && brakes.X2_45_7620)
                bss_inst.BSS825X5h_b = true;
            else
                bss_inst.BSS825X5h = true;
        }
        else
        {
            if(exchange::ushap >= 18.0 && !brakes.X2_45_7620)
                bss_inst.BSS825X5h = true;
        }
    }

    //3
    if(F55_2610)
    {
        if(exchange::ushap >= 18.0) bss_inst.BSS913X1f = true;

        if(exchange::ushal >= 18.0)
        {
            if(!brakes.X3_45_7620) bss_inst.BSS825X5j = true;
            else bss_inst.BSS825X5j_b = true;
        }

    }
    else
    {
        if(ezr_23sku3_vikl_dv3)
        {
            bss_inst.BSS913X1f = true;
            if(exchange::ushal >= 18.0 && brakes.X3_45_7620)
                bss_inst.BSS825X5j_b = true;
            else
                bss_inst.BSS825X5j = true;
        }
        else
        {
            if(exchange::ushal >= 18.0 && !brakes.X3_45_7620)
                bss_inst.BSS825X5j = true;
        }
    }
    //4
    if(F65_2610)
    {
        if(exchange::ushap >= 18.0) bss_inst.BSS913X1v = true;

        if(exchange::ushal >= 18.0)
        {
            if(!brakes.X4_45_7620) bss_inst.BSS825X5n = true;
            else bss_inst.BSS825X5n_b = true;
        }

    }
    else
    {
        if(ezr_23sku4_vikl_dv4)
        {
            bss_inst.BSS913X1v = true;
            if(exchange::ushal >= 18.0 && brakes.X4_45_7620)
                bss_inst.BSS825X5n_b = true;
            else
                bss_inst.BSS825X5n = true;
        }
        else
        {
            if(exchange::ushal >= 18.0 && !brakes.X4_45_7620)
                bss_inst.BSS825X5n = true;
        }
    }
}
