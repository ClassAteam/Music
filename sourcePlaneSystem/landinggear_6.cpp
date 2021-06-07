#include "landinggear_6.h"
#include "algorithms.h"


void landinggear_int::landinggear_6() //actually 6th
{
    // Left card are open
    if (delta_tel_l == 1.0)
    {
        S42_3230 = true;
        S43_3230 = true;
    }
    else
    {
        S42_3230 = false;
        S43_3230 = false;
    }

    // Right card are open
    if (delta_tel_p == 1.0)
    {
        S44_3230 = true;
        S45_3230 = true;
    }
    else
    {
        S44_3230 = false;
        S45_3230 = false;
    }

    // left card are closed
    if (delta_tel_l == 0.0)
    {
        S14_3230 = true;
        S13_3230 = true;
    }
    else
    {
        S14_3230 = false;
        S13_3230 = false;
    }

    if (delta_tel_p == 0.0)
    {
        S15_3230 = true;
        S16_3230 = true;
    }
    else
    {
        S15_3230 = false;
        S16_3230 = false;
    }

    // Left rack is not straight
    if (delta_sh_l == 1.0)
    {
        S4_3230 = true;
        S5_3230 = true;
        S33_3230 = true;
        S17_3230 = true;
        S51_3230 = true;
        S52_3230 = true;
    }
    else
    {
        S4_3230 = false;
        S5_3230 = false;
        S33_3230 = false;
        S17_3230 = false;
        S51_3230 = false;
        S52_3230 = false;
    }

    // right rack is not straight
    if (delta_sh_p == 1.0)
    {
        S6_3230 = true;
        S7_3230 = true;
        S37_3230 = true;
        S25_3230 = true;
        S53_3230 = true;
        S54_3230 = true;
    }
    else
    {
        S6_3230 = false;
        S7_3230 = false;
        S37_3230 = false;
        S25_3230 = false;
        S53_3230 = false;
        S54_3230 = false;
    }

    // left rack is shifted
    if (delta_shift_l == 1.0)
    {
        S8_3230 = true;
        S18_3230 = true;
        S49_3230 = true;
    }
    else
    {
        S8_3230 = false;
        S18_3230 = false;
        S49_3230 = false;
    }

    // right rack is shifted
    if (delta_shift_p == 1.0)
    {
        S9_3230 = true;
        S26_3230 = true;
        S48_3230 = true;
    }
    else
    {
        S9_3230 = false;
        S26_3230 = false;
        S48_3230 = false;
    }

    // Sashes of left rack's low ground are open
    if (delta_stv_l == 0.0)
    {
        S10_3230 = true;
        S20_3230 = true;
        S21_3230 = true;
    }
    else
    {
        S10_3230 = false;
        S20_3230 = false;
        S21_3230 = false;
    }

    // Sashes of right rack's low ground are open
    if (delta_stv_p == 0.0)
    {
        S11_3230 = true;
        S28_3230 = true;
        S29_3230 = true;
    }
    else
    {
        S11_3230 = false;
        S28_3230 = false;
        S29_3230 = false;
    }

    // Sashes of front rack's low ground are open
    if (delta_stv_n == 0.0)
    {
        S24_3230 = true;
        S12_3230 = true;
    }
    else
    {
        S24_3230 = false;
        S12_3230 = false;
    }

    // Front rack is released
    if (delta_sh_n == 1.0)
    {
        S22_3230 = true;
        S40_3230 = true;
    }
    else
    {
        S22_3230 = false;
        S40_3230 = false;
    }

    // Front rack is taked in
    if (delta_sh_n == 0.0)
    {
        S23_3230 = true;
        S41_3230 = true;
    }
    else
    {
        S23_3230 = false;
        S41_3230 = false;
    }

    // left rack is taked in
    if (delta_sh_l == 0.0)
    {
        S19_3230 = true;
        S35_3230 = true;
    }
    else
    {
        S19_3230 = false;
        S35_3230 = false;
    }

    // right rack is taked in
    if (delta_sh_p == 0.0)
    {
        S27_3230 = true;
        S39_3230 = true;
    }
    else
    {
        S27_3230 = false;
        S39_3230 = false;
    }

    exchange::P1OBLOP = false;
    S32_3230 = false;
    K9_3230 = false;
    exchange::K25_3230 = false;

    exchange::P2OBLOP = false;
    S34_3230 = false;
    exchange::K26_3230 = false;

    PUPLOP = false;
    PVPLOP = false;

    if (exchange::ushal >= 19.0)
    {
        if (Sl >= 0.1)
        {
            exchange::P1OBLOP = true;
            S32_3230 = true;
            K9_3230 = true;
            exchange::K25_3230 = true;
        }
        if (Sl >= 0.15)
        {
            exchange::P2OBLOP = true;
            S34_3230 = true;
            exchange::K26_3230 = true;
        }

        if(S33_3230) PVPLOP = true;

        if(S35_3230) PUPLOP = true;
    }
    else
    {
        exchange::P1OBLOP = false;
        S32_3230 = 0.0;
        K9_3230 = 0.0;
        exchange::K25_3230 = false;

        exchange::P2OBLOP = false;
        S34_3230 = 0.0;
        exchange::K26_3230 = false;

    }

    exchange::P2OBPOP = false;
    S36_3230 = false;
    exchange::K27_3230 = false;

    exchange::P1OBPOP = false;
    S38_3230 = false;
    K10_3230 = false;
    exchange::K24_3230 = false;

    PUPPOP = false;
    PVPPOP = false;

    if (exchange::ushap >= 19.0)
    {
        if (Sp >= 0.1)
        {
            exchange::P1OBPOP = true;
            S38_3230 = true;
            K10_3230 = true;
            exchange::K24_3230 = true;
        }

        if (Sp >= 0.15)
        {
            exchange::P2OBPOP = true;
            S36_3230 = true;
            exchange::K27_3230 = true;
        }

        if (S37_3230 == true)
        {
            PVPPOP = true;
        }

        if (S39_3230 == true)
        {
            PUPPOP = true;
        }
    }

    if (exchange::ush1dpp >= 19.0 && delta_sh_n == 1.0)
    {
        PVPPEROP = true;
        K6_3230 = true;
        K19_3230 = true;
        S40_3230 = 1.0;
    }
    else
    {
        PVPPEROP = false;
        K6_3230 = false;
        K19_3230 = false;
        S40_3230 = 0.0;
    }

    if (delta_sh_n == 0.0)
    {
        PUPPEROP = true;
        S41_3230 = 1.0;
    }
    else
    {
        PUPPEROP = false;
        S41_3230 = 0.0;
    }
}
