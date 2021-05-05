#include "emergencyalarm_4.h"

void emergencyalarm_int::emergencyalarm_4()
{
    static bool
    //yellow input clue
    PZH913_X1C,
    PZH913_X1E,
    PZH913_X1G,
    PZH913_X1J,
    PZH913_X1L,
    PZH913_X1N,
    PZH913_X1T,
    PZH913_X1V,
    PZH913_X1X,
    PZH913_X1Z,
    PZH913_X1b,
    PZH913_X1d,
    PZH913_X1h,
    PZH913_X1j,
    PZH913_X1n,
    PZH913_X1p,
    PZH913_X1r,
    PZH913_X1t,
    PZH913_X1x,
    PZH913_X1z,
    PZH913_X1BB,
    PZH913_X1DD,
    PZH913_X1FF,
    PZH913_X1HH,
    PZH913_X3E,
    PZH913_X3G,

    //yellow block clue
    PZH913_X1C_b,
    PZH913_X1E_b,
    PZH913_X1G_b,
    PZH913_X1J_b,
    PZH913_X1L_b,
    PZH913_X1N_b,
    PZH913_X1T_b,
    PZH913_X1V_b,
    PZH913_X1X_b,
    PZH913_X1Z_b,
    PZH913_X1b_b,
    PZH913_X1d_b,
    PZH913_X1h_b,
    PZH913_X1j_b,
    PZH913_X1n_b,
    PZH913_X1p_b,
    PZH913_X1r_b,
    PZH913_X1t_b,
    PZH913_X1x_b,
    PZH913_X1z_b,
    PZH913_X1BB_b,
    PZH913_X1DD_b,
    PZH913_X1FF_b,
    PZH913_X1HH_b,
    PZH913_X3E_b,
    PZH913_X3G_b,

    //red input clue
    PK913_X1A,
    PK913_X1R,
    PK913_X1f,
    PK913_X1v,

    //red block clue
    PK913_X1A_b,
    PK913_X1R_b,
    PK913_X1f_b,
    PK913_X1v_b;

    if(PRBSS913 == true)
    {
        ///////////////Yellow lights
        //////////////1
        if (bss_inst.BSS913X1C == true)
        {
            bss_inst.BSS913X2B = true;
            if(PZH913_X1C_b == true)
            {
                PZH913_X1C = false;
            }
            else
            {
                PZH913_X1C = true;
            }
        }
        else
        {
            bss_inst.BSS913X2B = false;
            PZH913_X1C_b = false;
            PZH913_X1C = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1C_b = true;
        }

        ///////////////Yellow lights
        //////////////2
        if (bss_inst.BSS913X1E == true)
        {
            bss_inst.BSS913X2C = true;
            if(PZH913_X1E_b == true)
            {
                PZH913_X1E = false;
            }
            else
            {
                PZH913_X1E = true;
            }
        }
        else
        {
            bss_inst.BSS913X2C = false;
            PZH913_X1E_b = false;
            PZH913_X1E = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1E_b = true;
        }

        ///////////////Yellow lights
        //////////////3
        if (bss_inst.BSS913X1G == true)
        {
            bss_inst.BSS913X2D = true;
            if(PZH913_X1G_b == true)
            {
                PZH913_X1G = false;
            }
            else
            {
                PZH913_X1G = true;
            }
        }
        else
        {
            bss_inst.BSS913X2D = false;
            PZH913_X1G_b = false;
            PZH913_X1G = false;
        }

        if(exchange::s1_3364 == true)
        {
            PZH913_X1G_b = true;
        }


        ///////////////Yellow lights
        //////////////4
        if (bss_inst.BSS913X1J == true)
        {
            bss_inst.BSS913X2E = true;
            if(PZH913_X1J_b == true)
            {
                PZH913_X1J = false;
            }
            else
            {
                PZH913_X1J = true;
            }
        }
        else
        {
            bss_inst.BSS913X2E = false;
            PZH913_X1J_b = false;
            PZH913_X1J = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1J_b = true;
        }

        ///////////////Yellow lights
        //////////////5
        if (bss_inst.BSS913X1L == true)
        {
            bss_inst.BSS913X2F = true;
            if(PZH913_X1L_b == true)
            {
                PZH913_X1L = false;
            }
            else
            {
                PZH913_X1L = true;
            }
        }
        else
        {
            bss_inst.BSS913X2F = false;
            PZH913_X1L_b = false;
            PZH913_X1L = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1L_b = true;
        }

        ///////////////Yellow lights
        //////////////6
        if (bss_inst.BSS913X1N == true)
        {
            bss_inst.BSS913X2G = true;
            if(PZH913_X1N_b == true)
            {
                PZH913_X1N = false;
            }
            else
            {
                PZH913_X1N = true;
            }
        }
        else
        {
            bss_inst.BSS913X2G = false;
            PZH913_X1N_b = false;
            PZH913_X1N = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1N_b = true;
        }

        ///////////////Yellow lights
        //////////////7
        if (bss_inst.BSS913X1T == true)
        {
            bss_inst.BSS913X2J = true;
            if(PZH913_X1T_b == true)
            {
                PZH913_X1T = false;
            }
            else
            {
                PZH913_X1T = true;
            }
        }
        else
        {
            bss_inst.BSS913X2J = false;
            PZH913_X1T_b = false;
            PZH913_X1T = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1T_b = true;
        }

        ///////////////Yellow lights
        //////////////8
        if (bss_inst.BSS913X1V == true)
        {
            bss_inst.BSS913X2K = true;
            if(PZH913_X1V_b == true)
            {
                PZH913_X1V = false;
            }
            else
            {
                PZH913_X1V = true;
            }
        }
        else
        {
            bss_inst.BSS913X2K = false;
            PZH913_X1V_b = false;
            PZH913_X1V = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1V_b = true;
        }

        ///////////////Yellow lights
        //////////////9
        if (bss_inst.BSS913X1X == true)
        {
            bss_inst.BSS913X2L = true;
            if(PZH913_X1X_b == true)
            {
                PZH913_X1X = false;
            }
            else
            {
                PZH913_X1X = true;
            }
        }
        else
        {
            bss_inst.BSS913X2L = false;
            PZH913_X1X_b = false;
            PZH913_X1X = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1X_b = true;
        }

        ///////////////Yellow lights
        //////////////10
        if (bss_inst.BSS913X1Z == true)
        {
            bss_inst.BSS913X2M = true;
            if(PZH913_X1Z_b == true)
            {
                PZH913_X1Z = false;
            }
            else
            {
                PZH913_X1Z = true;
            }
        }
        else
        {
            bss_inst.BSS913X2M = false;
            PZH913_X1Z_b = false;
            PZH913_X1Z = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1Z_b = true;
        }

        ///////////////Yellow lights
        //////////////11
        if (bss_inst.BSS913X1b == true)
        {
            bss_inst.BSS913X2N = true;
            if(PZH913_X1b_b == true)
            {
                PZH913_X1b = false;
            }
            else
            {
                PZH913_X1b = true;
            }
        }
        else
        {
            bss_inst.BSS913X2N = false;
            PZH913_X1b_b = false;
            PZH913_X1b = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1b_b = true;
        }

        ///////////////Yellow lights
        //////////////12
        if (bss_inst.BSS913X1d == true)
        {
            bss_inst.BSS913X2P = true;
            if(PZH913_X1d_b == true)
            {
                PZH913_X1d = false;
            }
            else
            {
                PZH913_X1d = true;
            }
        }
        else
        {
            bss_inst.BSS913X2P = false;
            PZH913_X1d_b = false;
            PZH913_X1d = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1d_b = true;
        }

        ///////////////Yellow lights
        //////////////13
        if (bss_inst.BSS913X1h == true)
        {
            bss_inst.BSS913X2S = true;
            if(PZH913_X1h_b == true)
            {
                PZH913_X1h = false;
            }
            else
            {
                PZH913_X1h = true;
            }
        }
        else
        {
            bss_inst.BSS913X2S = false;
            PZH913_X1h_b = false;
            PZH913_X1h = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1h_b = true;
        }

        ///////////////Yellow lights
        //////////////14
        if (bss_inst.BSS913X1j == true)
        {
            bss_inst.BSS913X2T = true;
            if(PZH913_X1j_b == true)
            {
                PZH913_X1j = false;
            }
            else
            {
                PZH913_X1j = true;
            }
        }
        else
        {
            bss_inst.BSS913X2T = false;
            PZH913_X1j_b = false;
            PZH913_X1j = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1j_b = true;
        }

        ///////////////Yellow lights
        //////////////15
        if (bss_inst.BSS913X1n == true)
        {
            bss_inst.BSS913X2U = true;
            if(PZH913_X1n_b == true)
            {
                PZH913_X1n = false;
            }
            else
            {
                PZH913_X1n = true;
            }
        }
        else
        {
            bss_inst.BSS913X2U = false;
            PZH913_X1n_b = false;
            PZH913_X1n = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1n_b = true;
        }

        ///////////////Yellow lights
        //////////////16
        if (bss_inst.BSS913X1p == true)
        {
            bss_inst.BSS913X2V = true;
            if(PZH913_X1p_b == true)
            {
                PZH913_X1p = false;
            }
            else
            {
                PZH913_X1p = true;
            }
        }
        else
        {
            bss_inst.BSS913X2V = false;
            PZH913_X1p_b = false;
            PZH913_X1p = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1p_b = true;
        }

        ///////////////Yellow lights
        //////////////17
        if (bss_inst.BSS913X1r == true)
        {
            bss_inst.BSS913X2W = true;
            if(PZH913_X1r_b == true)
            {
                PZH913_X1r = false;
            }
            else
            {
                PZH913_X1r = true;
            }
        }
        else
        {
            bss_inst.BSS913X2W = false;
            PZH913_X1r_b = false;
            PZH913_X1r = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1r_b = true;
        }

        ///////////////Yellow lights
        //////////////18
        if (bss_inst.BSS913X1t == true)
        {
            bss_inst.BSS913X2X = true;
            if(PZH913_X1t_b == true)
            {
                PZH913_X1t = false;
            }
            else
            {
                PZH913_X1t = true;
            }
        }
        else
        {
            bss_inst.BSS913X2X = false;
            PZH913_X1t_b = false;
            PZH913_X1t = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1t_b = true;
        }

        ///////////////Yellow lights
        //////////////19
        if (bss_inst.BSS913X1x == true)
        {
            bss_inst.BSS913X2Z = true;
            if(PZH913_X1x_b == true)
            {
                PZH913_X1x = false;
            }
            else
            {
                PZH913_X1x = true;
            }
        }
        else
        {
            bss_inst.BSS913X2Z = false;
            PZH913_X1x_b = false;
            PZH913_X1x = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1x_b = true;
        }

        ///////////////Yellow lights
        //////////////20
        if (bss_inst.BSS913X1z == true)
        {
            bss_inst.BSS913X2a = true;
            if(PZH913_X1z_b == true)
            {
                PZH913_X1z = false;
            }
            else
            {
                PZH913_X1z = true;
            }
        }
        else
        {
            bss_inst.BSS913X2a = false;
            PZH913_X1z_b = false;
            PZH913_X1z = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1z_b = true;
        }

        ///////////////Yellow lights
        //////////////21
        if (bss_inst.BSS913X1BB == true)
        {
            bss_inst.BSS913X2b = true;
            if(PZH913_X1BB_b == true)
            {
                PZH913_X1BB = false;
            }
            else
            {
                PZH913_X1BB = true;
            }
        }
        else
        {
            bss_inst.BSS913X2b = false;
            PZH913_X1BB_b = false;
            PZH913_X1BB = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1BB_b = true;
        }

        ///////////////Yellow lights
        //////////////22
        if (bss_inst.BSS913X1DD == true)
        {
            bss_inst.BSS913X2c = true;
            if(PZH913_X1DD_b == true)
            {
                PZH913_X1DD = false;
            }
            else
            {
                PZH913_X1DD = true;
            }
        }
        else
        {
            bss_inst.BSS913X2c = false;
            PZH913_X1DD_b = false;
            PZH913_X1DD = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1DD_b = true;
        }

        ///////////////Yellow lights
        //////////////23
        if (bss_inst.BSS913X1FF == true)
        {
            bss_inst.BSS913X2d = true;
            if(PZH913_X1FF_b == true)
            {
                PZH913_X1FF = false;
            }
            else
            {
                PZH913_X1FF = true;
            }
        }
        else
        {
            bss_inst.BSS913X2d = false;
            PZH913_X1FF_b = false;
            PZH913_X1FF = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1FF_b = true;
        }

        ///////////////Yellow lights
        //////////////24
        if (bss_inst.BSS913X1HH == true)
        {
            bss_inst.BSS913X2e = true;
            if(PZH913_X1HH_b == true)
            {
                PZH913_X1HH = false;
            }
            else
            {
                PZH913_X1HH = true;
            }
        }
        else
        {
            bss_inst.BSS913X2e = false;
            PZH913_X1HH_b = false;
            PZH913_X1HH = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X1HH_b = true;
        }

        ///////////////Yellow lights
        //////////////25
        if (bss_inst.BSS913X3E == true)
        {
            bss_inst.BSS913X2j = true;
            if(PZH913_X3E_b == true)
            {
                PZH913_X3E = false;
            }
            else
            {
                PZH913_X3E = true;
            }
        }
        else
        {
            bss_inst.BSS913X2j = false;
            PZH913_X3E_b = false;
            PZH913_X3E = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X3E_b = true;
        }

        ///////////////Yellow lights
        //////////////26
        if (bss_inst.BSS913X3G == true)
        {
            bss_inst.BSS913X2k = true;
            if(PZH913_X3G_b == true)
            {
                PZH913_X3G = false;
            }
            else
            {
                PZH913_X3G = true;
            }
        }
        else
        {
            bss_inst.BSS913X2k = false;
            PZH913_X3G_b = false;
            PZH913_X3G = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH913_X3G_b = true;
        }
        //PCSOZHLL toggle
        if( PZH913_X1C == true ||
                PZH913_X1E == true ||
                PZH913_X1G == true ||
                PZH913_X1J == true ||
                PZH913_X1L == true ||
                PZH913_X1N == true ||
                PZH913_X1T == true ||
                PZH913_X1V == true ||
                PZH913_X1X == true ||
                PZH913_X1Z == true ||
                PZH913_X1b == true ||
                PZH913_X1d == true ||
                PZH913_X1h == true ||
                PZH913_X1j == true ||
                PZH913_X1n == true ||
                PZH913_X1p == true ||
                PZH913_X1r == true ||
                PZH913_X1t == true ||
                PZH913_X1x == true ||
                PZH913_X1z == true ||
                PZH913_X1BB == true ||
                PZH913_X1DD == true ||
                PZH913_X1FF == true ||
                PZH913_X1HH == true ||
                PZH913_X3E == true ||
                PZH913_X3G == true)
        {

            PCSOZHLL_3 = true;
        }
        else
        {

            PCSOZHLL_3 = false;
        }


        ///////////////Red lights_1
        //////////////1
        if (bss_inst.BSS913X1A == true)
        {
            bss_inst.BSS913X2A = true;
            if(PK913_X1A_b == true)
            {
                PK913_X1A = false;
            }
            else
            {
                PK913_X1A = true;
            }
        }
        else
        {
            bss_inst.BSS913X2A = false;
            PK913_X1A_b = false;
            PK913_X1A = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK913_X1A_b = true;
        }

        ///////////////Red lights_1
        //////////////2
        if (bss_inst.BSS913X1R == true)
        {
            bss_inst.BSS913X2H = true;
            if(PK913_X1R_b == true)
            {
                PK913_X1R = false;
            }
            else
            {
                PK913_X1R = true;
            }
        }
        else
        {
            bss_inst.BSS913X2H = false;
            PK913_X1R_b = false;
            PK913_X1R = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK913_X1R_b = true;
        }

        ///////////////Red lights_1
        //////////////3
        if (bss_inst.BSS913X1f == true)
        {
            bss_inst.BSS913X2R = true;
            if(PK913_X1f_b == true)
            {
                PK913_X1f = false;
            }
            else
            {
                PK913_X1f = true;
            }
        }
        else
        {
            bss_inst.BSS913X2R = false;
            PK913_X1f_b = false;
            PK913_X1f = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK913_X1f_b = true;
        }

        ///////////////Red lights_1
        //////////////4
        if (bss_inst.BSS913X1v == true)
        {
            bss_inst.BSS913X2Y = true;
            if(PK913_X1v_b == true)
            {
                PK913_X1v = false;
            }
            else
            {
                PK913_X1v = true;
            }
        }
        else
        {
            bss_inst.BSS913X2Y = false;
            PK913_X1v_b = false;
            PK913_X1v = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK913_X1v_b = true;
        }


        // PCSOKLL toggle
        if(
            PK913_X1A == true ||
            PK913_X1R == true ||
            PK913_X1f == true ||
            PK913_X1v == true)
        {
            PCSOKLL_3 = true;
        }
        else
        {
            PCSOKLL_3 = false;
        }

        ///////////////White lights_1
        //////////////1
        if (bss_inst.BSS913X3A == true)
        {
            bss_inst.BSS913X2h = true;
        }
        else
        {
            bss_inst.BSS913X2h = false;
        }

        ///////////////White lights_1
        //////////////2
        if (bss_inst.BSS913X3C == true)
        {
            bss_inst.BSS913X2i = true;
        }
        else
        {
            bss_inst.BSS913X2i = false;
        }

        ///////////////White lights_1
        //////////////3
        if (bss_inst.BSS913X3J == true)
        {
            bss_inst.BSS913X2m = true;
        }
        else
        {
            bss_inst.BSS913X2m = false;
        }

        ///////////////White lights_1
        //////////////4
        if (bss_inst.BSS913X3L == true)
        {
            bss_inst.BSS913X2n = true;
        }
        else
        {
            bss_inst.BSS913X2n = false;
        }

        ///////////////White lights_1
        //////////////5
        if (bss_inst.BSS913X3N == true)
        {
            bss_inst.BSS913X2p = true;
        }
        else
        {
            bss_inst.BSS913X2p = false;
        }


        if(PKLLL == true)
        {
            PCSOZHLL_3 = true;
            PCSOKLL_3 = true;
            bss_inst.BSS913X2B = true;
            bss_inst.BSS913X2C = true;
            bss_inst.BSS913X2D = true;
            bss_inst.BSS913X2E = true;
            bss_inst.BSS913X2F = true;
            bss_inst.BSS913X2G = true;
            bss_inst.BSS913X2J = true;
            bss_inst.BSS913X2K = true;
            bss_inst.BSS913X2L = true;
            bss_inst.BSS913X2M = true;
            bss_inst.BSS913X2N = true;
            bss_inst.BSS913X2P = true;
            bss_inst.BSS913X2S = true;
            bss_inst.BSS913X2T = true;
            bss_inst.BSS913X2U = true;
            bss_inst.BSS913X2V = true;
            bss_inst.BSS913X2W = true;
            bss_inst.BSS913X2X = true;
            bss_inst.BSS913X2Z = true;
            bss_inst.BSS913X2a = true;
            bss_inst.BSS913X2b = true;
            bss_inst.BSS913X2c = true;
            bss_inst.BSS913X2d = true;
            bss_inst.BSS913X2e = true;
            bss_inst.BSS913X2j = true;
            bss_inst.BSS913X2k = true;
            bss_inst.BSS913X2A = true;
            bss_inst.BSS913X2H = true;
            bss_inst.BSS913X2R = true;
            bss_inst.BSS913X2Y = true;
            bss_inst.BSS913X2h = true;
            bss_inst.BSS913X2i = true;
            bss_inst.BSS913X2m = true;
            bss_inst.BSS913X2n = true;
            bss_inst.BSS913X2p = true;
        }


        if(
                PCSOZHLL_1 == true ||
                PCSOZHLL_2 == true ||
                PCSOZHLL_3 == true  )
        {
            PCSOZHLL = true;
        }
        else
        {
            PCSOZHLL = false;
        }

        if(
                PCSOKLL_1 == true ||
                PCSOKLL_2 == true ||
                PCSOKLL_3 == true  )
        {
            PCSOKLL = true;
        }
        else
        {
            PCSOKLL = false;
        }

    }
    else
    {
        bss_inst.BSS913X2B = false;
        bss_inst.BSS913X2C = false;
        bss_inst.BSS913X2D = false;
        bss_inst.BSS913X2E = false;
        bss_inst.BSS913X2F = false;
        bss_inst.BSS913X2G = false;
        bss_inst.BSS913X2J = false;
        bss_inst.BSS913X2K = false;
        bss_inst.BSS913X2L = false;
        bss_inst.BSS913X2M = false;
        bss_inst.BSS913X2N = false;
        bss_inst.BSS913X2P = false;
        bss_inst.BSS913X2S = false;
        bss_inst.BSS913X2T = false;
        bss_inst.BSS913X2U = false;
        bss_inst.BSS913X2V = false;
        bss_inst.BSS913X2W = false;
        bss_inst.BSS913X2X = false;
        bss_inst.BSS913X2Z = false;
        bss_inst.BSS913X2a = false;
        bss_inst.BSS913X2b = false;
        bss_inst.BSS913X2c = false;
        bss_inst.BSS913X2d = false;
        bss_inst.BSS913X2e = false;
        bss_inst.BSS913X2j = false;
        bss_inst.BSS913X2k = false;
        bss_inst.BSS913X2A = false;
        bss_inst.BSS913X2H = false;
        bss_inst.BSS913X2R = false;
        bss_inst.BSS913X2Y = false;
        bss_inst.BSS913X2h = false;
        bss_inst.BSS913X2i = false;
        bss_inst.BSS913X2m = false;
        bss_inst.BSS913X2n = false;
        bss_inst.BSS913X2p = false;
        PZH913_X1C = false;
        PZH913_X1E = false;
        PZH913_X1G = false;
        PZH913_X1J = false;
        PZH913_X1L = false;
        PZH913_X1N = false;
        PZH913_X1T = false;
        PZH913_X1V = false;
        PZH913_X1X = false;
        PZH913_X1Z = false;
        PZH913_X1b = false;
        PZH913_X1d = false;
        PZH913_X1h = false;
        PZH913_X1j = false;
        PZH913_X1n = false;
        PZH913_X1p = false;
        PZH913_X1r = false;
        PZH913_X1t = false;
        PZH913_X1x = false;
        PZH913_X1z = false;
        PZH913_X1BB = false;
        PZH913_X1DD = false;
        PZH913_X1FF = false;
        PZH913_X1HH = false;
        PZH913_X3E = false;
        PZH913_X3G = false;
        PZH913_X1C_b = false;
        PZH913_X1E_b = false;
        PZH913_X1G_b = false;
        PZH913_X1J_b = false;
        PZH913_X1L_b = false;
        PZH913_X1N_b = false;
        PZH913_X1T_b = false;
        PZH913_X1V_b = false;
        PZH913_X1X_b = false;
        PZH913_X1Z_b = false;
        PZH913_X1b_b = false;
        PZH913_X1d_b = false;
        PZH913_X1h_b = false;
        PZH913_X1j_b = false;
        PZH913_X1n_b = false;
        PZH913_X1p_b = false;
        PZH913_X1r_b = false;
        PZH913_X1t_b = false;
        PZH913_X1x_b = false;
        PZH913_X1z_b = false;
        PZH913_X1BB_b = false;
        PZH913_X1DD_b = false;
        PZH913_X1FF_b = false;
        PZH913_X1HH_b = false;
        PZH913_X3E_b = false;
        PZH913_X3G_b = false;
        PK913_X1A = false;
        PK913_X1R = false;
        PK913_X1f = false;
        PK913_X1v = false;
        PK913_X1A_b = false;
        PK913_X1R_b = false;
        PK913_X1f_b = false;
        PK913_X1v_b = false;
    }
}
