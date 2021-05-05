#include "emergencyalarm_2.h"

void emergencyalarm_int::emergencyalarm_2()
{
static bool
    //yellow input
    upor_dz_tang_lev_l,
    zakrilk_pariruy,
    dz_otkl,

    //yellow input clue
    PZH811_X1B,
    PZH811_X1D,
    PZH811_X1N,
    PZH811_X1R,
    PZH811_X1T,
    PZH811_X1V,
    PZH811_X1Z,
    PZH811_X1b,
    PZH811_X1d,
    PZH811_X1f,
    PZH811_X1DD,
    PZH_upor_dz_tang_lev_l,
    PZH_zakrilk_pariruy,
    PZH811_X1Y,
    PZH_dz_otkl,
    PZH811_X1h,
    PZH811_X1j,
    PZH811_X1p,
    PZH811_X1t,
    PZH811_X1v,
    PZH811_X1x,
    PZH811_X1z,
    PZH_sur_gs1_otkl,
    PZH_sur_gs2_otkl,
    PZH_sur_gs3_otkl,
    PZH_sur_gs4_otkl,

    //yellow block clue
    PZH811_X1B_b,
    PZH811_X1D_b,
    PZH811_X1N_b,
    PZH811_X1R_b,
    PZH811_X1T_b,
    PZH811_X1V_b,
    PZH811_X1Z_b,
    PZH811_X1b_b,
    PZH811_X1d_b,
    PZH811_X1f_b,
    PZH811_X1DD_b,
    PZH_upor_dz_tang_lev_l_b,
    PZH_zakrilk_pariruy_b,
    PZH811_X1Y_b,
    PZH_dz_otkl_b,
    PZH811_X1h_b,
    PZH811_X1j_b,
    PZH811_X1p_b,
    PZH811_X1t_b,
    PZH811_X1v_b,
    PZH811_X1x_b,
    PZH811_X1z_b,
    PZH_sur_gs1_otkl_b,
    PZH_sur_gs2_otkl_b,
    PZH_sur_gs3_otkl_b,
    PZH_sur_gs4_otkl_b,

    //red input clue
    PK811_X1E,
    PK811_X1G,
    PK811_X1J,
    PK811_X1L,
    PK811_X1n,
    PK811_X1r,
    PK811_X1BB,

    //red block clue
    PK811_X1E_b,
    PK811_X1G_b,
    PK811_X1J_b,
    PK811_X1L_b,
    PK811_X1n_b,
    PK811_X1r_b,
    PK811_X1BB_b,

    //white input clue
    PB811_X3A,
    PB811_X3C,
    PB811_X3D,
    PB811_X3E,
    PB_neytral_kren,
    PB_neytral_kurs,

    //white block clue
    PB811_X3A_b,
    PB811_X3C_b,
    PB811_X3D_b,
    PB811_X3E_b,
    PB_neytral_kren_b,
    PB_neytral_kurs_b;

    if (exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS_811 = true;
    else
        PRBSS_811 = false;

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_812 = true;
    else
        PRBSS_812 = false;

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && (exchange::s5_3364))
        PKLLL = true;
    else
        PKLLL = false;

//    if ((exchange::ush1dpl >= 18.0) && (exchange::ush1dpp >= 18.0))
//        USASLL = two_points_to_Y(alpha_rra7ll, 0, 1, 0.75, 1);

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_913 = true;
    else
        PRBSS_913 = false;

    if (PRBSS_811)
    {
        ///////////////Yellow lights
        //////////////1
        if(bss_inst.BSS811X1B)
        {
            bss_inst.BSS811X2A = true;
            if(PZH811_X1B_b)
                PZH811_X1B = false;
            else
                PZH811_X1B = true;
        }
        else
        {
            bss_inst.BSS811X2A = false;
            PZH811_X1B_b = false;
            PZH811_X1B = false;
        }


        if(exchange::s1_3364)
            PZH811_X1B_b = true;

        ///////////////Yellow lights
        //////////////2
        if (bss_inst.BSS811X1D)
        {
            bss_inst.BSS811X2B = true;
            if(PZH811_X1D_b)
                PZH811_X1D = false;
            else
                PZH811_X1D = true;
        }
        else
        {
            bss_inst.BSS811X2B = false;
            PZH811_X1D_b = false;
            PZH811_X1D = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1D_b = true;
        }
        ///////////////Yellow lights
        //////////////3
        if (bss_inst.BSS811X1N)
        {
            bss_inst.BSS811X2G = true;
            if(PZH811_X1N_b)
            {
                PZH811_X1N = false;
            }
            else
            {
                PZH811_X1N = true;
            }
        }
        else
        {
            bss_inst.BSS811X2G = false;
            PZH811_X1N_b = false;
            PZH811_X1N = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1N_b = true;
        }

        ///////////////Yellow lights
        //////////////4
        if (bss_inst.BSS811X1R)
        {
            bss_inst.BSS811X2H = true;
            if(PZH811_X1R_b)
            {
                PZH811_X1R = false;
            }
            else
            {
                PZH811_X1R = true;
            }
        }
        else
        {
            bss_inst.BSS811X2H = false;
            PZH811_X1R_b = false;
            PZH811_X1R = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1R_b = true;
        }

        ///////////////Yellow lights
        //////////////5
        if (bss_inst.BSS811X1T)
        {
            bss_inst.BSS811X2J = true;
            if(PZH811_X1T_b)
            {
                PZH811_X1T = false;
            }
            else
            {
                PZH811_X1T = true;
            }
        }
        else
        {
            bss_inst.BSS811X2J = false;
            PZH811_X1T_b = false;
            PZH811_X1T = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1T_b = true;
        }

        ///////////////Yellow lights
        //////////////6
        if (bss_inst.BSS811X1V)
        {
            bss_inst.BSS811X2K = true;
            if(PZH811_X1V_b)
            {
                PZH811_X1V = false;
            }
            else
            {
                PZH811_X1V = true;
            }
        }
        else
        {
            bss_inst.BSS811X2K = false;
            PZH811_X1V_b = false;
            PZH811_X1V = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1V_b = true;
        }

        ///////////////Yellow lights
        //////////////7
        if (bss_inst.BSS811X1Z)
        {
            bss_inst.BSS811X2M = true;
            if(PZH811_X1Z_b)
            {
                PZH811_X1Z = false;
            }
            else
            {
                PZH811_X1Z = true;
            }
        }
        else
        {
            bss_inst.BSS811X2M = false;
            PZH811_X1Z_b = false;
            PZH811_X1Z = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1Z_b = true;
        }

        ///////////////Yellow lights
        //////////////8
        if (bss_inst.BSS811X1b)
        {
            bss_inst.BSS811X2N = true;
            if(PZH811_X1b_b)
            {
                PZH811_X1b = false;
            }
            else
            {
                PZH811_X1b = true;
            }
        }
        else
        {
            bss_inst.BSS811X2N = false;
            PZH811_X1b_b = false;
            PZH811_X1b = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1b_b = true;
        }

        ///////////////Yellow lights
        //////////////9
        if (bss_inst.BSS811X1d)
        {
            bss_inst.BSS811X2P = true;
            if(PZH811_X1d_b)
            {
                PZH811_X1d = false;
            }
            else
            {
                PZH811_X1d = true;
            }
        }
        else
        {
            bss_inst.BSS811X2P = false;
            PZH811_X1d_b = false;
            PZH811_X1d = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1d_b = true;
        }

        ///////////////Yellow lights
        //////////////10
        if (bss_inst.BSS811X1f)
        {
            bss_inst.BSS811X2R = true;
            if(PZH811_X1f_b)
            {
                PZH811_X1f = false;
            }
            else
            {
                PZH811_X1f = true;
            }
        }
        else
        {
            bss_inst.BSS811X2R = false;
            PZH811_X1f_b = false;
            PZH811_X1f = false;
        }


        if(exchange::s1_3364)
        {
            PZH811_X1f_b = true;
        }

        ///////////////Yellow lights
        //////////////11
        if (bss_inst.BSS811X1DD)
        {
            bss_inst.BSS811X2c = true;
            if(PZH811_X1DD_b)
            {
                PZH811_X1DD = false;
            }
            else
            {
                PZH811_X1DD = true;
            }
        }
        else
        {
            bss_inst.BSS811X2c = false;
            PZH811_X1DD_b = false;
            PZH811_X1DD = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1DD_b = true;
        }

        ///////////////Yellow lights
        //////////////12
        if (upor_dz_tang_lev_l)
        {
            bss_inst.BSS811X2n = true;
            if(PZH_upor_dz_tang_lev_l_b)
            {
                PZH_upor_dz_tang_lev_l = false;
            }
            else
            {
                PZH_upor_dz_tang_lev_l = true;
            }
        }
        else
        {
            bss_inst.BSS811X2n = false;
            PZH_upor_dz_tang_lev_l_b = false;
            PZH_upor_dz_tang_lev_l = false;
        }


        if(exchange::s1_3364)
        {
            PZH_upor_dz_tang_lev_l_b = true;
        }

        ///////////////Yellow lights
        //////////////13
        if (zakrilk_pariruy)
        {
            bss_inst.BSS811X2m = true;
            if(PZH_zakrilk_pariruy_b)
            {
                PZH_zakrilk_pariruy = false;
            }
            else
            {
                PZH_zakrilk_pariruy = true;
            }
        }
        else
        {
            bss_inst.BSS811X2m = false;
            PZH_zakrilk_pariruy_b = false;
            PZH_zakrilk_pariruy = false;
        }


        if(exchange::s1_3364)
        {
            PZH_zakrilk_pariruy_b = true;
        }

        ///////////////Yellow lights
        //////////////14
        if (bss_inst.BSS811X1Y)
        {
            bss_inst.BSS811X2L = true;
            if(PZH811_X1Y_b)
            {
                PZH811_X1Y = false;
            }
            else
            {
                PZH811_X1Y = true;
            }
        }
        else
        {
            bss_inst.BSS811X2L = false;
            PZH811_X1Y_b = false;
            PZH811_X1Y = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1Y_b = true;
        }

        ///////////////Yellow lights
        //////////////15
        if (dz_otkl)
        {
            bss_inst.BSS811X2r = true;
            if(PZH_dz_otkl_b)
            {
                PZH_dz_otkl = false;
            }
            else
            {
                PZH_dz_otkl = true;
            }
        }
        else
        {
            bss_inst.BSS811X2r = false;
            PZH_dz_otkl_b = false;
            PZH_dz_otkl = false;
        }

        if(exchange::s1_3364)
        {
            PZH_dz_otkl_b = true;
        }

        ///////////////Yellow lights
        //////////////16
        if (bss_inst.BSS811X1h)
        {
            bss_inst.BSS811X2S = true;
            if(PZH811_X1h_b)
            {
                PZH811_X1h = false;
            }
            else
            {
                PZH811_X1h = true;
            }
        }
        else
        {
            bss_inst.BSS811X2S = false;
            PZH811_X1h_b = false;
            PZH811_X1h = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1h_b = true;
        }

        ///////////////Yellow lights
        //////////////17
        if (bss_inst.BSS811X1j)
        {
            bss_inst.BSS811X2T = true;
            if(PZH811_X1j_b)
            {
                PZH811_X1j = false;
            }
            else
            {
                PZH811_X1j = true;
            }
        }
        else
        {
            bss_inst.BSS811X2T = false;
            PZH811_X1j_b = false;
            PZH811_X1j = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1j_b = true;
        }

        ///////////////Yellow lights
        //////////////18
        if (bss_inst.BSS811X1p)
        {
            bss_inst.BSS811X2V = true;
            if(PZH811_X1p_b)
            {
                PZH811_X1p = false;
            }
            else
            {
                PZH811_X1p = true;
            }
        }
        else
        {
            bss_inst.BSS811X2V = false;
            PZH811_X1p_b = false;
            PZH811_X1p = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1p_b = true;
        }

        ///////////////Yellow lights
        //////////////19
        if (bss_inst.BSS811X1t)
        {
            bss_inst.BSS811X2X = true;
            if(PZH811_X1t_b)
            {
                PZH811_X1t = false;
            }
            else
            {
                PZH811_X1t = true;
            }
        }
        else
        {
            bss_inst.BSS811X2X = false;
            PZH811_X1t_b = false;
            PZH811_X1t = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1t_b = true;
        }

        ///////////////Yellow lights
        //////////////20
        if (bss_inst.BSS811X1v)
        {
            bss_inst.BSS811X2Y = true;
            if(PZH811_X1v_b)
            {
                PZH811_X1v = false;
            }
            else
            {
                PZH811_X1v = true;
            }
        }
        else
        {
            bss_inst.BSS811X2Y = false;
            PZH811_X1v_b = false;
            PZH811_X1v = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1v_b = true;
        }

        ///////////////Yellow lights
        //////////////21
        if (bss_inst.BSS811X1x)
        {
            bss_inst.BSS811X2Z = true;
            if(PZH811_X1x_b)
            {
                PZH811_X1x = false;
            }
            else
            {
                PZH811_X1x = true;
            }
        }
        else
        {
            bss_inst.BSS811X2Z = false;
            PZH811_X1x_b = false;
            PZH811_X1x = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1x_b = true;
        }

        ///////////////Yellow lights
        //////////////22
        if (bss_inst.BSS811X1z)
        {
            bss_inst.BSS811X2a = true;
            if(PZH811_X1z_b)
            {
                PZH811_X1z = false;
            }
            else
            {
                PZH811_X1z = true;
            }
        }
        else
        {
            bss_inst.BSS811X2a = false;
            PZH811_X1z_b = false;
            PZH811_X1z = false;
        }

        if(exchange::s1_3364)
        {
            PZH811_X1z_b = true;
        }

        ///////////////Yellow lights
        //////////////23
        if (bss_inst.surGs1Otkl)
        {
            bss_inst.BSS811X2d = true;
            if(PZH_sur_gs1_otkl_b)
            {
                PZH_sur_gs1_otkl = false;
            }
            else
            {
                PZH_sur_gs1_otkl = true;
            }
        }
        else
        {
            bss_inst.BSS811X2d = false;
            PZH_sur_gs1_otkl_b = false;
            PZH_sur_gs1_otkl = false;
        }

        if(exchange::s1_3364)
        {
            PZH_sur_gs1_otkl_b = true;
        }

        ///////////////Yellow lights
        //////////////24
        if (bss_inst.surGs2Otkl)
        {
            bss_inst.BSS811X2e = true;
            if(PZH_sur_gs2_otkl_b)
            {
                PZH_sur_gs2_otkl = false;
            }
            else
            {
                PZH_sur_gs2_otkl = true;
            }
        }
        else
        {
            bss_inst.BSS811X2e = false;
            PZH_sur_gs2_otkl_b = false;
            PZH_sur_gs2_otkl = false;
        }

        if(exchange::s1_3364)
        {
            PZH_sur_gs2_otkl_b = true;
        }

        ///////////////Yellow lights
        //////////////25
        if (bss_inst.surGs3Otkl)
        {
            bss_inst.BSS811X2f = true;
            if(PZH_sur_gs3_otkl_b)
            {
                PZH_sur_gs3_otkl = false;
            }
            else
            {
                PZH_sur_gs3_otkl = true;
            }
        }
        else
        {
            bss_inst.BSS811X2f = false;
            PZH_sur_gs3_otkl_b = false;
            PZH_sur_gs3_otkl = false;
        }

        if(exchange::s1_3364)
        {
            PZH_sur_gs3_otkl_b = true;
        }

        ///////////////Yellow lights
        //////////////26
        if (bss_inst.surGs4Otkl)
        {
            bss_inst.BSS811X2g = true;
            if(PZH_sur_gs4_otkl_b)
            {
                PZH_sur_gs4_otkl = false;
            }
            else
            {
                PZH_sur_gs4_otkl = true;
            }
        }
        else
        {
            bss_inst.BSS811X2g = false;
            PZH_sur_gs4_otkl_b = false;
            PZH_sur_gs4_otkl = false;
        }

        if(exchange::s1_3364)
        {
            PZH_sur_gs4_otkl_b = true;
        }

        if(PZH811_X1B ||
            PZH811_X1D ||
            PZH811_X1N ||
            PZH811_X1R ||
            PZH811_X1T ||
            PZH811_X1V ||
            PZH811_X1Z ||
            PZH811_X1b ||
            PZH811_X1d ||
            PZH811_X1f ||
            PZH811_X1DD ||
            PZH_upor_dz_tang_lev_l ||
            PZH_zakrilk_pariruy ||
            PZH811_X1Y ||
            PZH_dz_otkl ||
            PZH811_X1h ||
            PZH811_X1j ||
            PZH811_X1p ||
            PZH811_X1t ||
            PZH811_X1v ||
            PZH811_X1x ||
            PZH811_X1z ||
            PZH_sur_gs1_otkl ||
            PZH_sur_gs2_otkl ||
            PZH_sur_gs3_otkl ||
            PZH_sur_gs4_otkl)
        {

            PCSOZHLL_1 = true;
        }
        else
        {

            PCSOZHLL_1 = false;
        }

        ///////////////Red lights_1
        //////////////1
        if (bss_inst.BSS811X1E)
        {
            bss_inst.BSS811X2C = true;
            if(PK811_X1E_b)
            {
                PK811_X1E = false;
            }
            else
            {
                PK811_X1E = true;
            }
        }
        else
        {
            bss_inst.BSS811X2C = false;
            PK811_X1E_b = false;
            PK811_X1E = false;
        }


        if(exchange::s1_3364)
        {
            PK811_X1E_b = true;
        }

        ///////////////Red lights_1
        //////////////2
        if (bss_inst.BSS811X1G)
        {
            bss_inst.BSS811X2D = true;
            if(PK811_X1G_b)
            {
                PK811_X1G = false;
            }
            else
            {
                PK811_X1G = true;
            }
        }
        else
        {
            bss_inst.BSS811X2D = false;
            PK811_X1G_b = false;
            PK811_X1G = false;
        }


        if(exchange::s1_3364)
        {
            PK811_X1G_b = true;
        }

        ///////////////Red lights_1
        //////////////3
        if (bss_inst.BSS811X1J)
        {
            bss_inst.BSS811X2E = true;
            if(PK811_X1J_b)
            {
                PK811_X1J = false;
            }
            else
            {
                PK811_X1J = true;
            }
        }
        else
        {
            bss_inst.BSS811X2E = false;
            PK811_X1J_b = false;
            PK811_X1J = false;
        }


        if(exchange::s1_3364)
        {
            PK811_X1J_b = true;
        }

        ///////////////Red lights_1
        //////////////4
        if (bss_inst.BSS811X1L)
        {
            bss_inst.BSS811X2F = true;
            if(PK811_X1L_b)
            {
                PK811_X1L = false;
            }
            else
            {
                PK811_X1L = true;
            }
        }
        else
        {
            bss_inst.BSS811X2F = false;
            PK811_X1L_b = false;
            PK811_X1L = false;
        }


        if(exchange::s1_3364)
        {
            PK811_X1L_b = true;
        }

        ///////////////Red lights_1
        //////////////5
        if (bss_inst.BSS811X1n)
        {
            bss_inst.BSS811X2U = true;
            if(PK811_X1n_b)
            {
                PK811_X1n = false;
            }
            else
            {
                PK811_X1n = true;
            }
        }
        else
        {
            bss_inst.BSS811X2U = false;
            PK811_X1n_b = false;
            PK811_X1n = false;
        }


        if(exchange::s1_3364)
        {
            PK811_X1n_b = true;
        }

        ///////////////Red lights_1
        //////////////6
        if (bss_inst.BSS811X1r)
        {
            bss_inst.BSS811X2W = true;
            if(PK811_X1r_b)
            {
                PK811_X1r = false;
            }
            else
            {
                PK811_X1r = true;
            }
        }
        else
        {
            bss_inst.BSS811X2W = false;
            PK811_X1r_b = false;
            PK811_X1r = false;
        }


        if(exchange::s1_3364)
        {
            PK811_X1r_b = true;
        }

        ///////////////Red lights_1
        //////////////7
        if (bss_inst.BSS811X1BB)
        {
            bss_inst.BSS811X2b = true;
            if(PK811_X1BB_b)
            {
                PK811_X1BB = false;
            }
            else
            {
                PK811_X1BB = true;
            }
        }
        else
        {
            bss_inst.BSS811X2b = false;
            PK811_X1BB_b = false;
            PK811_X1BB = false;
        }


        if(exchange::s1_3364)
        {
            PK811_X1BB_b = true;
        }

        // PCSOKLL toggle

        if( PK811_X1E ||
            PK811_X1G ||
            PK811_X1J ||
            PK811_X1L ||
            PK811_X1n ||
            PK811_X1r ||
            PK811_X1BB)
        {
            PCSOKLL_1 = true;
        }
        else
        {
            PCSOKLL_1 = false;
        }

        ///////////////White lights_1
        //////////////1
        if (bss_inst.BSS811X3A)
        {
            bss_inst.BSS811X2h = true;
        }
        else
        {
            bss_inst.BSS811X2h = false;
        }


        ///////////////White lights_1
        //////////////2
        if (bss_inst.BSS811X3C)
        {
            bss_inst.BSS811X2l = true;
        }
        else
        {
            bss_inst.BSS811X2l = false;
        }

        ///////////////White lights_1
        //////////////3
        if (bss_inst.BSS811X3D)
        {
            bss_inst.BSS811X2j = true;
        }
        else
        {
            bss_inst.BSS811X2j = false;
        }

        ///////////////White lights_1
        //////////////4
        if (bss_inst.BSS811X3E)
        {
            bss_inst.BSS811X2k = true;
        }
        else
        {
            bss_inst.BSS811X2k = false;
        }

        ///////////////White lights_1
        //////////////5
        if (bss_inst.neytral_kren)
        {
            bss_inst.BSS811X2p = true;
        }
        else
        {
            bss_inst.BSS811X2p = false;
        }



        ///////////////White lights_1
        //////////////6
        if (bss_inst.neytral_kurs)
        {
            bss_inst.BSS811X2q = true;
        }
        else
        {
            bss_inst.BSS811X2q = false;
        }

        if(PKLLL)
        {
            PCSOKLL_1 = true;
            PCSOZHLL_1 = true;
            bss_inst.BSS811X2A = true;
            bss_inst.BSS811X2B = true;
            bss_inst.BSS811X2G = true;
            bss_inst.BSS811X2H = true;
            bss_inst.BSS811X2J = true;
            bss_inst.BSS811X2K = true;
            bss_inst.BSS811X2M = true;
            bss_inst.BSS811X2N = true;
            bss_inst.BSS811X2P = true;
            bss_inst.BSS811X2R = true;
            bss_inst.BSS811X2c = true;
            bss_inst.BSS811X2n = true;
            bss_inst.BSS811X2m = true;
            bss_inst.BSS811X2L = true;
            bss_inst.BSS811X2r = true;
            bss_inst.BSS811X2S = true;
            bss_inst.BSS811X2T = true;
            bss_inst.BSS811X2V = true;
            bss_inst.BSS811X2X = true;
            bss_inst.BSS811X2Y = true;
            bss_inst.BSS811X2Z = true;
            bss_inst.BSS811X2a = true;
            bss_inst.BSS811X2d = true;
            bss_inst.BSS811X2e = true;
            bss_inst.BSS811X2f = true;
            bss_inst.BSS811X2g = true;
            //red output
            bss_inst.BSS811X2C = true;
            bss_inst.BSS811X2D = true;
            bss_inst.BSS811X2E = true;
            bss_inst.BSS811X2F = true;
            bss_inst.BSS811X2U = true;
            bss_inst.BSS811X2W = true;
            bss_inst.BSS811X2b = true;
            //white output
            bss_inst.BSS811X2h = true;
            bss_inst.BSS811X2l = true;
            bss_inst.BSS811X2j = true;
            bss_inst.BSS811X2k = true;
            bss_inst.BSS811X2p = true;
            bss_inst.BSS811X2q = true;
            //white output
            bss_inst.BSS811X2h = true;
            bss_inst.BSS811X2l = true;
            bss_inst.BSS811X2j = true;
            bss_inst.BSS811X2k = true;
            bss_inst.BSS811X2p = true;
            bss_inst.BSS811X2q = true;
        }
    }
    else
    {
        //yellow output
        bss_inst.BSS811X2A = false;
        bss_inst.BSS811X2B = false;
        bss_inst.BSS811X2G = false;
        bss_inst.BSS811X2H = false;
        bss_inst.BSS811X2J = false;
        bss_inst.BSS811X2K = false;
        bss_inst.BSS811X2M = false;
        bss_inst.BSS811X2N = false;
        bss_inst.BSS811X2P = false;
        bss_inst.BSS811X2R = false;
        bss_inst.BSS811X2c = false;
        bss_inst.BSS811X2n = false;
        bss_inst.BSS811X2m = false;
        bss_inst.BSS811X2L = false;
        bss_inst.BSS811X2r = false;
        bss_inst.BSS811X2S = false;
        bss_inst.BSS811X2T = false;
        bss_inst.BSS811X2V = false;
        bss_inst.BSS811X2X = false;
        bss_inst.BSS811X2Y = false;
        bss_inst.BSS811X2Z = false;
        bss_inst.BSS811X2a = false;
        bss_inst.BSS811X2d = false;
        bss_inst.BSS811X2e = false;
        bss_inst.BSS811X2f = false;
        bss_inst.BSS811X2g = false;
        //red output
        bss_inst.BSS811X2C = false;
        bss_inst.BSS811X2D = false;
        bss_inst.BSS811X2E = false;
        bss_inst.BSS811X2F = false;
        bss_inst.BSS811X2U = false;
        bss_inst.BSS811X2W = false;
        bss_inst.BSS811X2b = false;
        //white output
        bss_inst.BSS811X2h = false;
        bss_inst.BSS811X2l = false;
        bss_inst.BSS811X2j = false;
        bss_inst.BSS811X2k = false;
        bss_inst.BSS811X2p = false;
        bss_inst.BSS811X2q = false;
        //yellow input clue
        PZH811_X1B = false;
        PZH811_X1D = false;
        PZH811_X1N = false;
        PZH811_X1R = false;
        PZH811_X1T = false;
        PZH811_X1V = false;
        PZH811_X1Z = false;
        PZH811_X1b = false;
        PZH811_X1d = false;
        PZH811_X1f = false;
        PZH811_X1DD = false;
        PZH_upor_dz_tang_lev_l = false;
        PZH_zakrilk_pariruy = false;
        PZH811_X1Y = false;
        PZH_dz_otkl = false;
        PZH811_X1h = false;
        PZH811_X1j = false;
        PZH811_X1p = false;
        PZH811_X1t = false;
        PZH811_X1v = false;
        PZH811_X1x = false;
        PZH811_X1z = false;
        PZH_sur_gs1_otkl = false;
        PZH_sur_gs2_otkl = false;
        PZH_sur_gs3_otkl = false;
        PZH_sur_gs4_otkl = false;

        //yellow block clue
        PZH811_X1B_b = false;
        PZH811_X1D_b = false;
        PZH811_X1N_b = false;
        PZH811_X1R_b = false;
        PZH811_X1T_b = false;
        PZH811_X1V_b = false;
        PZH811_X1Z_b = false;
        PZH811_X1b_b = false;
        PZH811_X1d_b = false;
        PZH811_X1f_b = false;
        PZH811_X1DD_b = false;
        PZH_upor_dz_tang_lev_l_b = false;
        PZH_zakrilk_pariruy_b = false;
        PZH811_X1Y_b = false;
        PZH_dz_otkl_b = false;
        PZH811_X1h_b = false;
        PZH811_X1j_b = false;
        PZH811_X1p_b = false;
        PZH811_X1t_b = false;
        PZH811_X1v_b = false;
        PZH811_X1x_b = false;
        PZH811_X1z_b = false;
        PZH_sur_gs1_otkl_b = false;
        PZH_sur_gs2_otkl_b = false;
        PZH_sur_gs3_otkl_b = false;
        PZH_sur_gs4_otkl_b = false;

        //red input clue
        PK811_X1E = false;
        PK811_X1G = false;
        PK811_X1J = false;
        PK811_X1L = false;
        PK811_X1n = false;
        PK811_X1r = false;
        PK811_X1BB = false;

        //red block clue
        PK811_X1E_b = false;
        PK811_X1G_b = false;
        PK811_X1J_b = false;
        PK811_X1L_b = false;
        PK811_X1n_b = false;
        PK811_X1r_b = false;
        PK811_X1BB_b = false;

        //white input clue
        PB811_X3A = false;
        PB811_X3C = false;
        PB811_X3D = false;
        PB811_X3E = false;
        PB_neytral_kren = false;
        PB_neytral_kurs = false;

        //white block clue
        PB811_X3A_b = false;
        PB811_X3C_b = false;
        PB811_X3D_b = false;
        PB811_X3E_b = false;
        PB_neytral_kren_b = false;
        PB_neytral_kurs_b = false;

    }
}
