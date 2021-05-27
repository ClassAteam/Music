#include "wingsmech_4.h"			//actually 5th sheet

void wingsmech_int::wingsmech_4()
{
    bss_inst.BSS824X1KK = false;
    bss_inst.BSS824X1MM = false;

    bss_inst.BSS824X3A = false;
    bss_inst.BSS824X3C = false;

    exchange::delta_z = ((delta_z_l + delta_z_p) / 2);

    if(exchange::ushap >= 18 && exchange::delta_z >= 0)
    {
        if(exchange::delta_z > 22)
        {
            bss_inst.BSS824X1KK = true;
            bss_inst.BSS824X1MM = false;
        }
        else
        {
            bss_inst.BSS824X1KK = false;
            bss_inst.BSS824X1MM = true;
        }
        if(exchange::delta_z > 28)
        {
            bss_inst.BSS824X3C = true;
            bss_inst.BSS824X1KK = false;
        }
        if(exchange::delta_z > 38)
        {
            bss_inst.BSS824X3A = true;
            bss_inst.BSS824X3C = false;
        }
        else
        {
            bss_inst.BSS824X1A = false;
        }
    }
    else
    {
        bss_inst.BSS824X1KK = false;
        bss_inst.BSS824X1MM = false;

        bss_inst.BSS824X1A = false;
        bss_inst.BSS824X3C = false;
    }

    bss_inst.BSS825X7A = false;
    bss_inst.BSS825X5J = false;

    if(exchange::ush1dpl > 18)
    {
        delta_pr = ((delta_pr_l + delta_pr_p) / 2);

        if(delta_pr >= 0)
        {
            bss_inst.BSS825X7A = true;
        }
        if(delta_pr >= 20.5)
        {
            bss_inst.BSS825X5J = true;
            bss_inst.BSS825X7A = false;
        }
    }
    delta_z_1_pk = delta_z_l;
    delta_z_3_pk = delta_z_p;
    X_1_pk = X_L;
    X_3_pk = X_P;

    if(exchange::ush1dpl >= 18)
    {
        XL_120 = X_L;
        XP_121 = X_P;
        XTR_122 = m_3_L_intervals(X_PCHK, 20, 30, 35, 65, 1, 54, 80, 208);
        delta_ruk_123 = 60 * delta_ruk_vh;

        uks_inst.P_140_11 = hydro_int::pgs1;
        uks_inst.P_140_12 = hydro_int::pgs2;
        uks_inst.P_140_13 = false;
        uks_inst.P_140_14 = false;
        if(D_X_l != 0)
        {
            if(D_X_l > 0)
            {
                uks_inst.P_140_13 = true;
            }
            else
            {
                uks_inst.P_140_14 = true;
            }
        }
        if(prr1kpchk)
        {
            uks_inst.P_140_15 = prr1kpchk;

            if(D_X_l != 0)
            {
                if(D_X_l > 0)
                {
                    uks_inst.P_140_16 = true;
                }
                else
                {
                    uks_inst.P_140_17 = true;
                }
            }
        }
        uks_inst.P_141_11 = false;
        uks_inst.P_141_12 = false;
        uks_inst.P_141_13 = false;

        uks_inst.P_141_14 = false;
        uks_inst.P_141_15 = false;
        uks_inst.P_141_16 = false;
        uks_inst.P_141_17 = false;


        if((abs(X_L - X_P)) >= 1)
        {
            uks_inst.P_140_18 = true;
            uks_inst.P_140_19 = true;

            uks_inst.P_141_17 = true;
        }
        uks_inst.P_141_11 = false;
        uks_inst.P_141_12 = false;

        if(otkaz_osn_1k_PCHK == true)
        {
            uks_inst.P_141_13 = true;
        }
    }
    if(exchange::ush1dpp > 18)
    {
        uks_inst.P_142_11 = hydro_int::pgs3;
        uks_inst.P_142_12 = hydro_int::pgs4;

        uks_inst.P_142_13 = false;

        uks_inst.P_142_14 = false;

        if(D_X_p != 0)
        {
            if(D_X_p > 0)
            {
                uks_inst.P_142_13 = true;
            }
            else
            {
                uks_inst.P_142_14 = true;
            }
        }

        uks_inst.P_142_16 = false;

        uks_inst.P_142_17 = false;

        if(prr2kpchk == true)
        {
            uks_inst.P_142_15 = prr2kpchk;
            if(D_X_p != 0)
            {
                if(D_X_p > 0)
                {
                    uks_inst.P_142_16 = true;
                }
                else
                {
                    uks_inst.P_142_17 = true;
                }
            }
        }
    }

    uks_inst.P_143_11 = false;
    uks_inst.P_143_12 = false;
    uks_inst.P_143_13 = false;
    uks_inst.P_143_14 = false;
    uks_inst.P_143_15 = false;
    uks_inst.P_143_16 = false;
    uks_inst.P_143_17 = false;


    uks_inst.P_143_16 = false;
    uks_inst.P_143_17 = false;

    if((abs(X_L - X_P)) >= 1)
    {
        uks_inst.P_142_18 = true;
        uks_inst.P_142_19 = true;

        uks_inst.P_143_17 = true;
    }
    uks_inst.P_143_11 = false;
    uks_inst.P_143_12 = false;

    if(otkaz_osn_2k_PCHK == true)
    {
        uks_inst.P_143_13 = true;
    }

    if(exchange::ush1dpl >= 18)
    {
        delta_z_l_110 = delta_z_l;
        delta_pr_l_114 = delta_pr_l;
    }
    else
    {
        delta_z_l_110 = 0;
        delta_pr_l_114 = 0;
    }

    if(exchange::ush1dpp >= 18)
    {
        delta_z_p_111 = delta_z_l;
        delta_pr_p_115 = delta_pr_l;
        delta_pr = ((delta_pr_l + delta_pr_p) / 2);
        delta_pr_116 = (0.8 + (200 * (delta_pr / 21)));
    }
    else
    {
        delta_z_p_111 = 0;
        delta_pr_p_115 = 0;
        delta_pr_116 = 0;
    }
    if(exchange::ushap >= 18)
    {
        exchange::delta_z = ((delta_z_l + delta_z_p) / 2);
        delta_z_112 = 0.35 + (5.266 * exchange::delta_z);
        delta_ruz_113 = 60 * delta_zr_vh;
    }

    uks_inst.P_130_11 = false;

    uks_inst.P_130_12 = false;

    uks_inst.P_130_13 = false;

    uks_inst.P_130_14 = false;

    uks_inst.P_130_15 = false;

    uks_inst.P_130_16 = false;

    uks_inst.P_130_17 = false;

    uks_inst.P_130_18 = false;

    uks_inst.P_130_19 = false;

    uks_inst.P_130_21 = false;

    uks_inst.P_130_23 = false;

    uks_inst.P_130_25 = false;

    if(exchange::ush1dpl >= 18)
    {
        uks_inst.P_130_11 = hydro_int::pgs1;
        uks_inst.P_130_12 = psr1kz;

        if(exchange::delta_z >= 28.1)
        {
            uks_inst.P_130_13 = true;
        }

        if(delta_pr > 0)
        {
            uks_inst.P_130_14 = true;
        }

        if(Ddelta_z_l != 0)
        {
            if(Ddelta_z_l > 0)
            {
                uks_inst.P_130_15 = true;
            }
            else
            {
                uks_inst.P_130_16 = true;
            }
        }

        if(Ddelta_pr_l != 0)
        {
            if(Ddelta_pr_l > 0)
            {
                uks_inst.P_130_17 = true;
            }
            else
            {
                uks_inst.P_130_18 = true;
            }
        }

        uks_inst.P_130_19 = prr1kz;

        if(prr1kz == true)
        {
            if(Ddelta_z_l != 0)
            {
                if(Ddelta_z_l > 0)
                {
                    uks_inst.P_130_20 = true;
                }
                else
                {
                    uks_inst.P_130_21 = true;
                }

            }

        }

        if(prr1kpr == true)
        {
            if(Ddelta_pr_l != 0)
            {
                if(Ddelta_pr_l > 0)
                {
                    uks_inst.P_130_22 = true;
                }
                else
                {
                    uks_inst.P_130_23 = true;
                }
            }

        }
    }

    if((abs(delta_z_l - delta_z_p)) >= 2.5)
    {
        uks_inst.P_130_24 = true;
        uks_inst.P_130_25 = true;
    }

    uks_inst.P_131_11 = false;
    uks_inst.P_131_12 = false;
    uks_inst.P_131_13 = false;
    uks_inst.P_131_14 = false;
    uks_inst.P_131_15 = false;
    uks_inst.P_131_16 = false;
    uks_inst.P_131_17 = false;
    uks_inst.P_131_18 = false;
    uks_inst.P_131_19 = false;
    uks_inst.P_131_20 = false;
    uks_inst.P_131_21 = false;
    uks_inst.P_131_22 = false;

    if(exchange::ush1dpl >= 18)
    {
        if(otkaz_1k_zakr == true)
        {
            uks_inst.P_131_14 = true;
        }
        if((abs(delta_z_l - delta_z_p)) >= 2.5)
        {
            uks_inst.P_131_20 = true;
        }
        if((abs(delta_pr_l - delta_pr_p)) >= 2.5)
        {
            uks_inst.P_131_21 = true;
        }
    }

    uks_inst.P_132_11 = false;
    uks_inst.P_132_12 = false;
    uks_inst.P_132_13 = false;
    uks_inst.P_132_14 = false;
    uks_inst.P_132_15 = false;
    uks_inst.P_132_16 = false;
    uks_inst.P_132_17 = false;
    uks_inst.P_132_18 = false;
    uks_inst.P_132_19 = false;
    uks_inst.P_132_20 = false;
    uks_inst.P_132_21 = false;
    uks_inst.P_132_22 = false;
    uks_inst.P_132_23 = false;
    uks_inst.P_132_24 = false;
    uks_inst.P_132_25 = false;

    if(exchange::ush1dpp >= 18)
    {
        uks_inst.P_132_11 = hydro_int::pgs4;
        uks_inst.P_132_12 = psr2kz;

        if(exchange::delta_z >= 28.1)
        {
            uks_inst.P_132_13 = true;
        }
        if(delta_pr > 0)
        {
            uks_inst.P_132_14 = true;
        }

        if(Ddelta_z_l != 0)
        {
            if(Ddelta_z_l > 0)
            {
                uks_inst.P_132_15 = true;
            }
            else
            {
                uks_inst.P_132_16 = true;
            }
        }
        if(Ddelta_pr_l != 0)
        {
            if(Ddelta_pr_l > 0)
            {
                uks_inst.P_132_17 = true;
            }
            else
            {
                uks_inst.P_132_18 = true;
            }
        }

        uks_inst.P_132_19 = prr2kz;

        if(prr2kz == true)
        {
            if(Ddelta_z_l != 0)
            {
                if(Ddelta_z_l > 0)
                {
                    uks_inst.P_132_20 = true;
                }
                else
                {
                    uks_inst.P_132_21 = true;
                }
            }
        }

        if(prr2kpr == true)
        {
            if(Ddelta_pr_l != 0)
            {
                if(Ddelta_pr_l > 0)
                {
                    uks_inst.P_132_22 = true;
                }
                else
                {
                    uks_inst.P_132_23 = true;
                }
            }
        }

        if((abs(delta_z_l - delta_z_p)) >= 2.5)
        {
            uks_inst.P_132_24 = true;
            uks_inst.P_132_25 = true;
        }
    }
    uks_inst.P_133_11 = false;
    uks_inst.P_133_12 = false;
    uks_inst.P_133_13 = false;
    uks_inst.P_133_14 = false;
    uks_inst.P_133_15 = false;
    uks_inst.P_133_16 = false;
    uks_inst.P_133_17 = false;
    uks_inst.P_133_18 = false;
    uks_inst.P_133_19 = false;
    uks_inst.P_133_20 = false;
    uks_inst.P_133_21 = false;
    uks_inst.P_133_22 = false;

    if(exchange::ush1dpp >= 18)
    {
        if(otkaz_2k_zakr == true)
        {
            uks_inst.P_133_14 = true;
        }
        if((abs(delta_z_l - delta_z_p)) >= 2.5)
        {
            uks_inst.P_133_20 = true;
        }
        if((abs(delta_pr_l - delta_pr_p)) >= 2.5)
        {
            uks_inst.P_133_21 = true;
        }
    }
}

    // end logic
