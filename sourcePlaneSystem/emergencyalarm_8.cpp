#include "emergencyalarm_8.h"


void emergencyalarm_int::emergencyalarm_8()
{
    //yellow input clue
    static bool
        PZH837_X1A,
        PZH837_X1C,
        PZH837_X1E,
        PZH837_X1G,
        PZH837_X1J,
        PZH837_X1N,
        PZH837_X1R,
        PZH837_X1V,
        PZH837_X1L,
        PZH837_X1X,
        PZH837_X1Z,
        PZH837_X1b,
        PZH837_X1d,
        PZH837_X1f,
        PZH837_X1h,
        PZH837_X1j,
        PZH837_X1r,
        PZH837_X1t,
        PZH837_X1x,
        PZH837_X1BB,
        PZH837_X1DD,
        PZH837_X1KK,
        PZH837_X1MM,
        PZH837_X3G,
        PZH837_X3J,

        //yellow block clue
        PZH837_X1A_b,
        PZH837_X1C_b,
        PZH837_X1E_b,
        PZH837_X1G_b,
        PZH837_X1J_b,
        PZH837_X1N_b,
        PZH837_X1R_b,
        PZH837_X1V_b,
        PZH837_X1L_b,
        PZH837_X1X_b,
        PZH837_X1Z_b,
        PZH837_X1b_b,
        PZH837_X1d_b,
        PZH837_X1f_b,
        PZH837_X1h_b,
        PZH837_X1j_b,
        PZH837_X1r_b,
        PZH837_X1t_b,
        PZH837_X1x_b,
        PZH837_X1BB_b,
        PZH837_X1DD_b,
        PZH837_X1KK_b,
        PZH837_X1MM_b,
        PZH837_X3G_b,
        PZH837_X3J_b,

        //red input clue
        PK837_X1p,
        PK837_X3C,
        PK837_X3N,

        //red input block clue
        PK837_X1p_b,
        PK837_X3C_b,
        PK837_X3N_b;

    if(PRBSS837 == true)
    {
        ///////////////Yellow lights
        //////////////1
        if (bss_inst.BSS837X1A == true)
        {
            bss_inst.BSS837X2A = true;
            if(PZH837_X1A_b == true)
            {
                PZH837_X1A = false;
            }
            else
            {
                PZH837_X1A = true;
            }
        }
        else
        {
            bss_inst.BSS837X2A = false;
            PZH837_X1A_b = false;
            PZH837_X1A = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1A_b = true;
        }

        ///////////////Yellow lights
        //////////////2
        if (bss_inst.BSS837X1C == true)
        {
            bss_inst.BSS837X2B = true;
            if(PZH837_X1C_b == true)
            {
                PZH837_X1C = false;
            }
            else
            {
                PZH837_X1C = true;
            }
        }
        else
        {
            bss_inst.BSS837X2B = false;
            PZH837_X1C_b = false;
            PZH837_X1C = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1C_b = true;
        }

        ///////////////Yellow lights
        //////////////3
        if (bss_inst.BSS837X1E == true)
        {
            bss_inst.BSS837X2C = true;
            if(PZH837_X1E_b == true)
            {
                PZH837_X1E = false;
            }
            else
            {
                PZH837_X1E = true;
            }
        }
        else
        {
            bss_inst.BSS837X2C = false;
            PZH837_X1E_b = false;
            PZH837_X1E = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1E_b = true;
        }

        ///////////////Yellow lights
        //////////////4
        if (bss_inst.BSS837X1G == true)
        {
            bss_inst.BSS837X2D = true;
            if(PZH837_X1G_b == true)
            {
                PZH837_X1G = false;
            }
            else
            {
                PZH837_X1G = true;
            }
        }
        else
        {
            bss_inst.BSS837X2D = false;
            PZH837_X1G_b = false;
            PZH837_X1G = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1G_b = true;
        }

        ///////////////Yellow lights
        //////////////5
        if (bss_inst.BSS837X1J == true)
        {
            bss_inst.BSS837X2E = true;
            if(PZH837_X1J_b == true)
            {
                PZH837_X1J = false;
            }
            else
            {
                PZH837_X1J = true;
            }
        }
        else
        {
            bss_inst.BSS837X2E = false;
            PZH837_X1J_b = false;
            PZH837_X1J = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1J_b = true;
        }

        ///////////////Yellow lights
        //////////////6
        if (bss_inst.BSS837X1N == true)
        {
            bss_inst.BSS837X2G = true;
            if(PZH837_X1N_b == true)
            {
                PZH837_X1N = false;
            }
            else
            {
                PZH837_X1N = true;
            }
        }
        else
        {
            bss_inst.BSS837X2G = false;
            PZH837_X1N_b = false;
            PZH837_X1N = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1N_b = true;
        }

        ///////////////Yellow lights
        //////////////7
        if (bss_inst.BSS837X1R == true)
        {
            bss_inst.BSS837X2H = true;
            if(PZH837_X1R_b == true)
            {
                PZH837_X1R = false;
            }
            else
            {
                PZH837_X1R = true;
            }
        }
        else
        {
            bss_inst.BSS837X2H = false;
            PZH837_X1R_b = false;
            PZH837_X1R = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1R_b = true;
        }

        ///////////////Yellow lights
        //////////////8
        if (bss_inst.BSS837X1V == true)
        {
            bss_inst.BSS837X2K = true;
            if(PZH837_X1V_b == true)
            {
                PZH837_X1V = false;
            }
            else
            {
                PZH837_X1V = true;
            }
        }
        else
        {
            bss_inst.BSS837X2K = false;
            PZH837_X1V_b = false;
            PZH837_X1V = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1V_b = true;
        }

        ///////////////Yellow lights
        //////////////9
        if (bss_inst.BSS837X1L == true)
        {
            bss_inst.BSS837X2F = true;
            if(PZH837_X1L_b == true)
            {
                PZH837_X1L = false;
            }
            else
            {
                PZH837_X1L = true;
            }
        }
        else
        {
            bss_inst.BSS837X2F = false;
            PZH837_X1L_b = false;
            PZH837_X1L = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1L_b = true;
        }

        ///////////////Yellow lights
        //////////////10
        if (bss_inst.BSS837X1X == true)
        {
            bss_inst.BSS837X2L = true;
            if(PZH837_X1X_b == true)
            {
                PZH837_X1X = false;
            }
            else
            {
                PZH837_X1X = true;
            }
        }
        else
        {
            bss_inst.BSS837X2L = false;
            PZH837_X1X_b = false;
            PZH837_X1X = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1X_b = true;
        }

        ///////////////Yellow lights
        //////////////11
        if (bss_inst.BSS837X1Z == true)
        {
            bss_inst.BSS837X2M = true;
            if(PZH837_X1Z_b == true)
            {
                PZH837_X1Z = false;
            }
            else
            {
                PZH837_X1Z = true;
            }
        }
        else
        {
            bss_inst.BSS837X2M = false;
            PZH837_X1Z_b = false;
            PZH837_X1Z = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1Z_b = true;
        }

        ///////////////Yellow lights
        //////////////12
        if (bss_inst.BSS837X1b == true)
        {
            bss_inst.BSS837X2N = true;
            if(PZH837_X1b_b == true)
            {
                PZH837_X1b = false;
            }
            else
            {
                PZH837_X1b = true;
            }
        }
        else
        {
            bss_inst.BSS837X2N = false;
            PZH837_X1b_b = false;
            PZH837_X1b = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1b_b = true;
        }

        ///////////////Yellow lights
        //////////////13
        if (bss_inst.BSS837X1d == true)
        {
            bss_inst.BSS837X2P = true;
            if(PZH837_X1d_b == true)
            {
                PZH837_X1d = false;
            }
            else
            {
                PZH837_X1d = true;
            }
        }
        else
        {
            bss_inst.BSS837X2P = false;
            PZH837_X1d_b = false;
            PZH837_X1d = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1d_b = true;
        }

        ///////////////Yellow lights
        //////////////14
        if (bss_inst.BSS837X1f == true)
        {
            bss_inst.BSS837X2R = true;
            if(PZH837_X1f_b == true)
            {
                PZH837_X1f = false;
            }
            else
            {
                PZH837_X1f = true;
            }
        }
        else
        {
            bss_inst.BSS837X2R = false;
            PZH837_X1f_b = false;
            PZH837_X1f = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1f_b = true;
        }

        ///////////////Yellow lights
        //////////////15
        if (bss_inst.BSS837X1h == true)
        {
            bss_inst.BSS837X2S = true;
            if(PZH837_X1h_b == true)
            {
                PZH837_X1h = false;
            }
            else
            {
                PZH837_X1h = true;
            }
        }
        else
        {
            bss_inst.BSS837X2S = false;
            PZH837_X1h_b = false;
            PZH837_X1h = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1h_b = true;
        }

        ///////////////Yellow lights
        //////////////16
        if (bss_inst.BSS837X1j == true)
        {
            bss_inst.BSS837X2T = true;
            if(PZH837_X1j_b == true)
            {
                PZH837_X1j = false;
            }
            else
            {
                PZH837_X1j = true;
            }
        }
        else
        {
            bss_inst.BSS837X2T = false;
            PZH837_X1j_b = false;
            PZH837_X1j = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1j_b = true;
        }

        ///////////////Yellow lights
        //////////////17
        if (bss_inst.BSS837X1r == true)
        {
            bss_inst.BSS837X2W = true;
            if(PZH837_X1r_b == true)
            {
                PZH837_X1r = false;
            }
            else
            {
                PZH837_X1r = true;
            }
        }
        else
        {
            bss_inst.BSS837X2W = false;
            PZH837_X1r_b = false;
            PZH837_X1r = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1r_b = true;
        }

        ///////////////Yellow lights
        //////////////18
        if (bss_inst.BSS837X1t == true)
        {
            bss_inst.BSS837X2X = true;
            if(PZH837_X1t_b == true)
            {
                PZH837_X1t = false;
            }
            else
            {
                PZH837_X1t = true;
            }
        }
        else
        {
            bss_inst.BSS837X2X = false;
            PZH837_X1t_b = false;
            PZH837_X1t = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1t_b = true;
        }

        ///////////////Yellow lights
        //////////////19
        if (bss_inst.BSS837X1x == true)
        {
            bss_inst.BSS837X2Z = true;
            if(PZH837_X1x_b == true)
            {
                PZH837_X1x = false;
            }
            else
            {
                PZH837_X1x = true;
            }
        }
        else
        {
            bss_inst.BSS837X2Z = false;
            PZH837_X1x_b = false;
            PZH837_X1x = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1x_b = true;
        }

        ///////////////Yellow lights
        //////////////20
        if (bss_inst.BSS837X1BB == true)
        {
            bss_inst.BSS837X2b = true;
            if(PZH837_X1BB_b == true)
            {
                PZH837_X1BB = false;
            }
            else
            {
                PZH837_X1BB = true;
            }
        }
        else
        {
            bss_inst.BSS837X2b = false;
            PZH837_X1BB_b = false;
            PZH837_X1BB = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1BB_b = true;
        }

        ///////////////Yellow lights
        //////////////21
        if (bss_inst.BSS837X1DD == true)
        {
            bss_inst.BSS837X2c = true;
            if(PZH837_X1DD_b == true)
            {
                PZH837_X1DD = false;
            }
            else
            {
                PZH837_X1DD = true;
            }
        }
        else
        {
            bss_inst.BSS837X2c = false;
            PZH837_X1DD_b = false;
            PZH837_X1DD = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1DD_b = true;
        }

        ///////////////Yellow lights
        //////////////22
        if (bss_inst.BSS837X1KK == true)
        {
            bss_inst.BSS837X2f = true;
            if(PZH837_X1KK_b == true)
            {
                PZH837_X1KK = false;
            }
            else
            {
                PZH837_X1KK = true;
            }
        }
        else
        {
            bss_inst.BSS837X2f = false;
            PZH837_X1KK_b = false;
            PZH837_X1KK = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1KK_b = true;
        }
        ///////////////Yellow lights
        //////////////23
        if (bss_inst.BSS837X1MM == true)
        {
            bss_inst.BSS837X2g = true;
            if(PZH837_X1MM_b == true)
            {
                PZH837_X1MM = false;
            }
            else
            {
                PZH837_X1MM = true;
            }
        }
        else
        {
            bss_inst.BSS837X2g = false;
            PZH837_X1MM_b = false;
            PZH837_X1MM = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X1MM_b = true;
        }

        ///////////////Yellow lights
        //////////////24
        if (bss_inst.BSS837X3G == true)
        {
            bss_inst.BSS837X2k = true;
            if(PZH837_X3G_b == true)
            {
                PZH837_X3G = false;
            }
            else
            {
                PZH837_X3G = true;
            }
        }
        else
        {
            bss_inst.BSS837X2k = false;
            PZH837_X3G_b = false;
            PZH837_X3G = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X3G_b = true;
        }

        ///////////////Yellow lights
        //////////////25
        if (bss_inst.BSS837X3J == true)
        {
            bss_inst.BSS837X2m = true;
            if(PZH837_X3J_b == true)
            {
                PZH837_X3J = false;
            }
            else
            {
                PZH837_X3J = true;
            }
        }
        else
        {
            bss_inst.BSS837X2m = false;
            PZH837_X3J_b = false;
            PZH837_X3J = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH837_X3J_b = true;
        }

        //PCSOZHLL toggle
        if(
            PZH837_X1A == true ||
            PZH837_X1C == true ||
            PZH837_X1E == true ||
            PZH837_X1G == true ||
            PZH837_X1J == true ||
            PZH837_X1N == true ||
            PZH837_X1R == true ||
            PZH837_X1V == true ||
            PZH837_X1L == true ||
            PZH837_X1X == true ||
            PZH837_X1Z == true ||
            PZH837_X1b == true ||
            PZH837_X1d == true ||
            PZH837_X1f == true ||
            PZH837_X1h == true ||
            PZH837_X1j == true ||
            PZH837_X1r == true ||
            PZH837_X1t == true ||
            PZH837_X1x == true ||
            PZH837_X1BB == true ||
            PZH837_X1DD == true ||
            PZH837_X1KK == true ||
            PZH837_X1MM == true ||
            PZH837_X3G == true ||
            PZH837_X3J == true)
        {

            PCSOZHSHO_2 = true;
        }
        else
        {

            PCSOZHSHO_2 = false;
        }

        ///////////////Red lights_1
        //////////////1
        if (bss_inst.BSS837X1p == true)
        {
            bss_inst.BSS837X2V = true;
            if(PK837_X1p_b == true)
            {
                PK837_X1p = false;
            }
            else
            {
                PK837_X1p = true;
            }
        }
        else
        {
            bss_inst.BSS837X2V = false;
            PK837_X1p_b = false;
            PK837_X1p = false;
        }


        if(exchange::s3_3364 == true)
        {
            PK837_X1p_b = true;
        }

        ///////////////Red lights_1
        //////////////2
        if (bss_inst.BSS837X3C == true)
        {
            bss_inst.BSS837X2i = true;
            if(PK837_X3C_b == true)
            {
                PK837_X3C = false;
            }
            else
            {
                PK837_X3C = true;
            }
        }
        else
        {
            bss_inst.BSS837X2i = false;
            PK837_X3C_b = false;
            PK837_X3C = false;
        }


        if(exchange::s3_3364 == true)
        {
            PK837_X3C_b = true;
        }

        ///////////////Red lights_1
        //////////////3
        if (bss_inst.BSS837X3N == true)
        {
            bss_inst.BSS837X2p = true;
            if(PK837_X3N_b == true)
            {
                PK837_X3N = false;
            }
            else
            {
                PK837_X3N = true;
            }
        }
        else
        {
            bss_inst.BSS837X2p = false;
            PK837_X3N_b = false;
            PK837_X3N = false;
        }


        if(exchange::s3_3364 == true)
        {
            PK837_X3N_b = true;
        }

        // PCSOKLL toggle
        if(
            PK837_X1p == true ||
            PK837_X3C == true ||
            PK837_X3N == true)
        {
            PCSOKSHO_2 = true;
        }
        else
        {
            PCSOKSHO_2 = false;
        }

        ///////////////White lights_1
        //////////////1
        if (bss_inst.BSS837X1T == true)
        {
            bss_inst.BSS837X2J = true;
        }
        else
        {
            bss_inst.BSS837X2J = false;
        }

        ///////////////White lights_1
        //////////////2
        if (bss_inst.BSS837X1n == true)
        {
            bss_inst.BSS837X2U = true;
        }
        else
        {
            bss_inst.BSS837X2U = false;
        }

        ///////////////White lights_1
        //////////////3
        if (bss_inst.BSS837X1v == true)
        {
            bss_inst.BSS837X2Y = true;
        }
        else
        {
            bss_inst.BSS837X2Y = false;
        }

        ///////////////White lights_1
        //////////////4
//        if (bss_inst.BSS837X1z == true)
//        {
//            bss_inst.BSS837X2a = true;
//        }
//        else
//        {
//            bss_inst.BSS837X2a = false;
//        }

        ///////////////White lights_1
        //////////////5
        if (bss_inst.BSS837X1FF == true)
        {
            bss_inst.BSS837X2d = true;
        }
        else
        {
            bss_inst.BSS837X2d = false;
        }

        ///////////////White lights_1
        //////////////6
        if (bss_inst.BSS837X1HH == true)
        {
            bss_inst.BSS837X2e = true;
        }
        else
        {
            bss_inst.BSS837X2e = false;
        }

        ///////////////White lights_1
        //////////////7
        if (bss_inst.BSS837X3A == true)
        {
            bss_inst.BSS837X2h = true;
        }
        else
        {
            bss_inst.BSS837X2h = false;
        }

        ///////////////White lights_1
        //////////////8
        if (bss_inst.BSS837X3E == true)
        {
            bss_inst.BSS837X2j = true;
        }
        else
        {
            bss_inst.BSS837X2j = false;
        }

        ///////////////White lights_1
        //////////////9
        if (bss_inst.BSS837X3L == true)
        {
            bss_inst.BSS837X2n = true;
        }
        else
        {
            bss_inst.BSS837X2n = false;
        }

        ///////////////White lights_1
        //////////////10
        if (bss_inst.BSS837X3R == true)
        {
            bss_inst.BSS837X2q = true;
        }
        else
        {
            bss_inst.BSS837X2q = false;
        }

        ///////////////White lights_1
        //////////////11
        if (bss_inst.BSS837X3T == true)
        {
            bss_inst.BSS837X2r = true;
        }
        else
        {
            bss_inst.BSS837X2r = false;
        }

        if(PKLSHO == true)
        {
            PCSOZHSHO = true;
            PCSOKSHO = true;
            bss_inst.BSS837X2A = true;
            bss_inst.BSS837X2B = true;
            bss_inst.BSS837X2C = true;
            bss_inst.BSS837X2D = true;
            bss_inst.BSS837X2E = true;
            bss_inst.BSS837X2G = true;
            bss_inst.BSS837X2H = true;
            bss_inst.BSS837X2K = true;
            bss_inst.BSS837X2F = true;
            bss_inst.BSS837X2L = true;
            bss_inst.BSS837X2M = true;
            bss_inst.BSS837X2N = true;
            bss_inst.BSS837X2P = true;
            bss_inst.BSS837X2R = true;
            bss_inst.BSS837X2S = true;
            bss_inst.BSS837X2T = true;
            bss_inst.BSS837X2W = true;
            bss_inst.BSS837X2X = true;
            bss_inst.BSS837X2Z = true;
            bss_inst.BSS837X2b = true;
            bss_inst.BSS837X2c = true;
            bss_inst.BSS837X2f = true;
            bss_inst.BSS837X2g = true;
            bss_inst.BSS837X2k = true;
            bss_inst.BSS837X2m = true;
            bss_inst.BSS837X2V = true;
            bss_inst.BSS837X2i = true;
            bss_inst.BSS837X2p = true;
            bss_inst.BSS837X2J = true;
            bss_inst.BSS837X2U = true;
            bss_inst.BSS837X2Y = true;
            bss_inst.BSS837X2a = true;
            bss_inst.BSS837X2d = true;
            bss_inst.BSS837X2e = true;
            bss_inst.BSS837X2h = true;
            bss_inst.BSS837X2j = true;
            bss_inst.BSS837X2n = true;
            bss_inst.BSS837X2q = true;
            bss_inst.BSS837X2r = true;
        }

   }
    else
    {
        PCSOZHSHO = false;
        PCSOKSHO = false;
        bss_inst.BSS837X2A = false;
        bss_inst.BSS837X2B = false;
        bss_inst.BSS837X2C = false;
        bss_inst.BSS837X2D = false;
        bss_inst.BSS837X2E = false;
        bss_inst.BSS837X2G = false;
        bss_inst.BSS837X2H = false;
        bss_inst.BSS837X2K = false;
        bss_inst.BSS837X2F = false;
        bss_inst.BSS837X2L = false;
        bss_inst.BSS837X2M = false;
        bss_inst.BSS837X2N = false;
        bss_inst.BSS837X2P = false;
        bss_inst.BSS837X2R = false;
        bss_inst.BSS837X2S = false;
        bss_inst.BSS837X2T = false;
        bss_inst.BSS837X2W = false;
        bss_inst.BSS837X2X = false;
        bss_inst.BSS837X2Z = false;
        bss_inst.BSS837X2b = false;
        bss_inst.BSS837X2c = false;
        bss_inst.BSS837X2f = false;
        bss_inst.BSS837X2g = false;
        bss_inst.BSS837X2k = false;
        bss_inst.BSS837X2m = false;
        bss_inst.BSS837X2V = false;
        bss_inst.BSS837X2i = false;
        bss_inst.BSS837X2p = false;
        bss_inst.BSS837X2J = false;
        bss_inst.BSS837X2U = false;
        bss_inst.BSS837X2Y = false;
        bss_inst.BSS837X2a = false;
        bss_inst.BSS837X2d = false;
        bss_inst.BSS837X2e = false;
        bss_inst.BSS837X2h = false;
        bss_inst.BSS837X2j = false;
        bss_inst.BSS837X2n = false;
        bss_inst.BSS837X2q = false;
        bss_inst.BSS837X2r = false;
        PZH837_X1A = false;
        PZH837_X1C = false;
        PZH837_X1E = false;
        PZH837_X1G = false;
        PZH837_X1J = false;
        PZH837_X1N = false;
        PZH837_X1R = false;
        PZH837_X1V = false;
        PZH837_X1L = false;
        PZH837_X1X = false;
        PZH837_X1Z = false;
        PZH837_X1b = false;
        PZH837_X1d = false;
        PZH837_X1f = false;
        PZH837_X1h = false;
        PZH837_X1j = false;
        PZH837_X1r = false;
        PZH837_X1t = false;
        PZH837_X1x = false;
        PZH837_X1BB = false;
        PZH837_X1DD = false;
        PZH837_X1KK = false;
        PZH837_X1MM = false;
        PZH837_X3G = false;
        PZH837_X3J = false;
        PZH837_X1A_b = false;
        PZH837_X1C_b = false;
        PZH837_X1E_b = false;
        PZH837_X1G_b = false;
        PZH837_X1J_b = false;
        PZH837_X1N_b = false;
        PZH837_X1R_b = false;
        PZH837_X1V_b = false;
        PZH837_X1L_b = false;
        PZH837_X1X_b = false;
        PZH837_X1Z_b = false;
        PZH837_X1b_b = false;
        PZH837_X1d_b = false;
        PZH837_X1f_b = false;
        PZH837_X1h_b = false;
        PZH837_X1j_b = false;
        PZH837_X1r_b = false;
        PZH837_X1t_b = false;
        PZH837_X1x_b = false;
        PZH837_X1BB_b = false;
        PZH837_X1DD_b = false;
        PZH837_X1KK_b = false;
        PZH837_X1MM_b = false;
        PZH837_X3G_b = false;
        PZH837_X3J_b = false;
        PK837_X1p = false;
        PK837_X3C = false;
        PK837_X3N = false;
        PK837_X1p_b = false;
        PK837_X3C_b = false;
        PK837_X3N_b = false;

    }
}
