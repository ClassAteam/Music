#include "emergencyalarm_7.h"

void emergencyalarm_int::emergencyalarm_7()
{
    //yellow input clue
    static bool
    PZH926_X1C,
    PZH926_X1G,
    PZH926_X1d,
    PZH926_X3V,
    PZH926_X1x,
    PZH926_X1BB,
    PZH926_X1FF,

    //yellow block clue
    PZH926_X1C_b,
    PZH926_X1G_b,
    PZH926_X1d_b,
    PZH926_X3V_b,
    PZH926_X1x_b,
    PZH926_X1BB_b,
    PZH926_X1FF_b;

static int
    X1t_blink;

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
    {
        PRBSS926 = true;
    }
    else
    {
        PRBSS926 = false;
    }

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
    {
        PRBSS837 = true;
    }
    else
    {
        PRBSS837 = false;
    }

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
    {
        PRBSS838 = true;
    }
    else
    {
        PRBSS838 = false;
    }

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && exchange::s7_3364)
    {
        PKLSHO = true;
    }
    else
    {
        PKLSHO = false;
    }


    if (PRBSS926 == true)
    {
        ///////////////Yellow lights
        //////////////1
        if (bss_inst.BSS926X1C == true)
        {
            bss_inst.BSS926X2B = true;
            if(PZH926_X1C_b == true)
            {
                PZH926_X1C = false;
            }
            else
            {
                PZH926_X1C = true;
            }
        }
        else
        {
            bss_inst.BSS926X2B = false;
            PZH926_X1C_b = false;
            PZH926_X1C = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH926_X1C_b = true;
        }

        ///////////////Yellow lights
        //////////////2
        if (bss_inst.BSS926X1G == true)
        {
            bss_inst.BSS926X2D = true;
            if(PZH926_X1G_b == true)
            {
                PZH926_X1G = false;
            }
            else
            {
                PZH926_X1G = true;
            }
        }
        else
        {
            bss_inst.BSS926X2D = false;
            PZH926_X1G_b = false;
            PZH926_X1G = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH926_X1G_b = true;
        }

        ///////////////Yellow lights
        //////////////3
        if (bss_inst.BSS926X1d == true)
        {
            bss_inst.BSS926X2p = true;
            if(PZH926_X1d_b == true)
            {
                PZH926_X1d = false;
            }
            else
            {
                PZH926_X1d = true;
            }
        }
        else
        {
            bss_inst.BSS926X2p = false;
            PZH926_X1d_b = false;
            PZH926_X1d = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH926_X1d_b = true;
        }

        ///////////////Yellow lights
        //////////////4
        if (bss_inst.BSS926X3V == true)
        {
            bss_inst.BSS926X2s = true;
            if(PZH926_X3V_b == true)
            {
                PZH926_X3V = false;
            }
            else
            {
                PZH926_X3V = true;
            }
        }
        else
        {
            bss_inst.BSS926X2s = false;
            PZH926_X3V_b = false;
            PZH926_X3V = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH926_X3V_b = true;
        }

        ///////////////Yellow lights
        //////////////5
        if (bss_inst.BSS926X1x == true)
        {
            bss_inst.BSS926X2z = true;
            if(PZH926_X1x_b == true)
            {
                PZH926_X1x = false;
            }
            else
            {
                PZH926_X1x = true;
            }
        }
        else
        {
            bss_inst.BSS926X2z = false;
            PZH926_X1x_b = false;
            PZH926_X1x = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH926_X1x_b = true;
        }

        ///////////////Yellow lights
        //////////////6
        if (bss_inst.BSS926X1BB == true)
        {
            bss_inst.BSS926X2b = true;
            if(PZH926_X1BB_b == true)
            {
                PZH926_X1BB = false;
            }
            else
            {
                PZH926_X1BB = true;
            }
        }
        else
        {
            bss_inst.BSS926X2b = false;
            PZH926_X1BB_b = false;
            PZH926_X1BB = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH926_X1BB_b = true;
        }

        ///////////////Yellow lights
        //////////////7
        if (bss_inst.BSS926X1FF == true)
        {
            bss_inst.BSS926X2d = true;
            if(PZH926_X1FF_b == true)
            {
                PZH926_X1FF = false;
            }
            else
            {
                PZH926_X1FF = true;
            }
        }
        else
        {
            bss_inst.BSS926X2d = false;
            PZH926_X1FF_b = false;
            PZH926_X1FF = false;
        }


        if(exchange::s3_3364 == true)
        {
            PZH926_X1FF_b = true;
        }

        if(
            PZH926_X1C == true ||
            PZH926_X1G == true ||
            PZH926_X1d == true ||
            PZH926_X3V == true ||
            PZH926_X1x == true ||
            PZH926_X1BB == true ||
            PZH926_X1FF == true)
        {

            PCSOZHSHO_1 = true;
        }
        else
        {

            PCSOZHSHO_1 = false;
        }


        ///////////////White lights_1
        //////////////1
        if (bss_inst.BSS926X1A == true)
        {
            bss_inst.BSS926X2A = true;
        }
        else
        {
            bss_inst.BSS926X2A = false;
        }

        ///////////////White lights_1
        //////////////2
        if (bss_inst.BSS926X1E == true)
        {
            bss_inst.BSS926X2C = true;
        }
        else
        {
            bss_inst.BSS926X2C = false;
        }

        ///////////////White lights_1
        //////////////3
        if (bss_inst.BSS926X1J == true)
        {
            bss_inst.BSS926X2E = true;
        }
        else
        {
            bss_inst.BSS926X2E = false;
        }

        ///////////////White lights_1
        //////////////4
        if (bss_inst.BSS926X1L == true)
        {
            bss_inst.BSS926X2F = true;
        }
        else
        {
            bss_inst.BSS926X2F = false;
        }

        ///////////////White lights_1
        //////////////5
        if (bss_inst.BSS926X1N == true)
        {
            bss_inst.BSS926X2G = true;
        }
        else
        {
            bss_inst.BSS926X2G = false;
        }

        ///////////////White lights_1
        //////////////6
        if (bss_inst.BSS926X1R == true)
        {
            bss_inst.BSS926X2H = true;
        }
        else
        {
            bss_inst.BSS926X2H = false;
        }

        ///////////////White lights_1
        //////////////7
        if (bss_inst.zakr_om1 == true)
        {
            bss_inst.BSS926X2J = true;
        }
        else
        {
            bss_inst.BSS926X2J = false;
        }

        ///////////////White lights_1
        //////////////8
        if (bss_inst.zakr_m1 == true)
        {
            bss_inst.BSS926X2K = true;
        }
        else
        {
            bss_inst.BSS926X2K = false;
        }

        ///////////////White lights_1
        //////////////9
        if (bss_inst.BSS926X1X == true)
        {
            bss_inst.BSS926X2L = true;
        }
        else
        {
            bss_inst.BSS926X2L = false;
        }

        ///////////////White lights_1
        //////////////10
        if (bss_inst.BSS926X1Z == true)
        {
            bss_inst.BSS926X2M = true;
        }
        else
        {
            bss_inst.BSS926X2M = false;
        }

        ///////////////White lights_1
        //////////////11
        if (bss_inst.BSS926X1b == true)
        {
            bss_inst.BSS926X2N = true;
        }
        else
        {
            bss_inst.BSS926X2N = false;
        }

        ///////////////White lights_1
        //////////////12
        if (bss_inst.BSS926X1f == true)
        {
            bss_inst.BSS926X2R = true;
        }
        else
        {
            bss_inst.BSS926X2R = false;
        }

        ///////////////White lights_1
        //////////////13
        if (bss_inst.BSS926X1h == true)
        {
            bss_inst.BSS926X2S = true;
        }
        else
        {
            bss_inst.BSS926X2S = false;
        }

        ///////////////White lights_1
        //////////////14
        if (bss_inst.BSS926X1j == true)
        {
            bss_inst.BSS926X2T = true;
        }
        else
        {
            bss_inst.BSS926X2T = false;
        }

        ///////////////White lights_1
        //////////////15
        if (bss_inst.BSS926X1n == true)
        {
            bss_inst.BSS926X2U = true;
        }
        else
        {
            bss_inst.BSS926X2U = false;
        }

        ///////////////White lights_1
        //////////////16
        if (bss_inst.BSS926X1t == true)
        {
            X1t_blink++;
            if((X1t_blink * TICK) < 400)
            {
                bss_inst.BSS926X2U = false;
            }
            if(((X1t_blink * TICK)) >= 400)
            {
                bss_inst.BSS926X2U = true;
                X1t_blink = 0;
            }
        }
        else
        {
            X1t_blink = 0;
        }

        ///////////////White lights_1
        //////////////17
        if (bss_inst.BSS926X1p == true)
        {
            bss_inst.BSS926X2V = true;
        }
        else
        {
            bss_inst.BSS926X2V = false;
        }

        ///////////////White lights_1
        //////////////18
        if (bss_inst.BSS926X1r == true)
        {
            bss_inst.BSS926X2W = true;
        }
        else
        {
            bss_inst.BSS926X2W = false;
        }

        ///////////////White lights_1
        //////////////19
        if (bss_inst.BSS926X1z == true)
        {
            bss_inst.BSS926X2a = true;
        }
        else
        {
            bss_inst.BSS926X2a = false;
        }

        ///////////////White lights_1
        //////////////20
        if (bss_inst.BSS926X1DD == true)
        {
            bss_inst.BSS926X2c = true;
        }
        else
        {
            bss_inst.BSS926X2c = false;
        }

        ///////////////White lights_1
        //////////////21
        if (bss_inst.BSS926X1HH == true)
        {
            bss_inst.BSS926X2e = true;
        }
        else
        {
            bss_inst.BSS926X2e = false;
        }

        ///////////////White lights_1
        //////////////22
        if (bss_inst.BSS926X1KK == true)
        {
            bss_inst.BSS926X2f = true;
        }
        else
        {
            bss_inst.BSS926X2f = false;
        }

        ///////////////White lights_1
        //////////////23
        if (bss_inst.BSS926X1MM == true)
        {
            bss_inst.BSS926X2g = true;
        }
        else
        {
            bss_inst.BSS926X2g = false;
        }

        ///////////////White lights_1
        //////////////24
        if (bss_inst.BSS926X3A == true)
        {
            bss_inst.BSS926X2h = true;
        }
        else
        {
            bss_inst.BSS926X2h = false;
        }

        ///////////////White lights_1
        //////////////25
        if (bss_inst.BSS926X3C == true)
        {
            bss_inst.BSS926X2i = true;
        }
        else
        {
            bss_inst.BSS926X2i = false;
        }

        ///////////////White lights_1
        //////////////26
        if (bss_inst.BSS926X3E == true)
        {
            bss_inst.BSS926X2j = true;
        }
        else
        {
            bss_inst.BSS926X2j = false;
        }

        ///////////////White lights_1
        //////////////27
        if (bss_inst.BSS926X3H == true)
        {
            bss_inst.BSS926X2k = true;
        }
        else
        {
            bss_inst.BSS926X2k = false;
        }

        ///////////////White lights_1
        //////////////28
        if (bss_inst.BSS926X3J == true)
        {
            bss_inst.BSS926X2m = true;
        }
        else
        {
            bss_inst.BSS926X2m = false;
        }

        ///////////////White lights_1
        //////////////29
        if (bss_inst.BSS926X3L == true)
        {
            bss_inst.BSS926X2n = true;
        }
        else
        {
            bss_inst.BSS926X2n = false;
        }

        ///////////////White lights_1
        //////////////30
        if (bss_inst.BSS926X3N == true)
        {
            bss_inst.BSS926X2P = true;
        }
        else
        {
            bss_inst.BSS926X2P = false;
        }

        ///////////////White lights_1
        //////////////31
        if (bss_inst.BSS926X3R == true)
        {
            bss_inst.BSS926X2q = true;
        }
        else
        {
            bss_inst.BSS926X2q = false;
        }

        ///////////////White lights_1
        //////////////32
        if (bss_inst.BSS926X3T == true)
        {
            bss_inst.BSS926X2r = true;
        }
        else
        {
            bss_inst.BSS926X2r = false;
        }

        if(PKLSHO == true)
        {
            PCSOZHSHO_1 = true;
            bss_inst.BSS926X2A = true;
            bss_inst.BSS926X2C = true;
            bss_inst.BSS926X2E = true;
            bss_inst.BSS926X2F = true;
            bss_inst.BSS926X2G = true;
            bss_inst.BSS926X2H = true;
            bss_inst.BSS926X2J = true;
            bss_inst.BSS926X2K = true;
            bss_inst.BSS926X2L = true;
            bss_inst.BSS926X2M = true;
            bss_inst.BSS926X2N = true;
            bss_inst.BSS926X2R = true;
            bss_inst.BSS926X2S = true;
            bss_inst.BSS926X2T = true;
            bss_inst.BSS926X2U = true;
            bss_inst.BSS926X2V = true;
            bss_inst.BSS926X2W = true;
            bss_inst.BSS926X2a = true;
            bss_inst.BSS926X2c = true;
            bss_inst.BSS926X2e = true;
            bss_inst.BSS926X2f = true;
            bss_inst.BSS926X2g = true;
            bss_inst.BSS926X2h = true;
            bss_inst.BSS926X2i = true;
            bss_inst.BSS926X2j = true;
            bss_inst.BSS926X2k = true;
            bss_inst.BSS926X2m = true;
            bss_inst.BSS926X2n = true;
            bss_inst.BSS926X2P = true;
            bss_inst.BSS926X2q = true;
            bss_inst.BSS926X2r = true;
        }
    }
    else
    {
        PCSOZHSHO_1 = false;
        bss_inst.BSS926X2A = false;
        bss_inst.BSS926X2C = false;
        bss_inst.BSS926X2E = false;
        bss_inst.BSS926X2F = false;
        bss_inst.BSS926X2G = false;
        bss_inst.BSS926X2H = false;
        bss_inst.BSS926X2J = false;
        bss_inst.BSS926X2K = false;
        bss_inst.BSS926X2L = false;
        bss_inst.BSS926X2M = false;
        bss_inst.BSS926X2N = false;
        bss_inst.BSS926X2R = false;
        bss_inst.BSS926X2S = false;
        bss_inst.BSS926X2T = false;
        bss_inst.BSS926X2U = false;
        bss_inst.BSS926X2V = false;
        bss_inst.BSS926X2W = false;
        bss_inst.BSS926X2a = false;
        bss_inst.BSS926X2c = false;
        bss_inst.BSS926X2e = false;
        bss_inst.BSS926X2f = false;
        bss_inst.BSS926X2g = false;
        bss_inst.BSS926X2h = false;
        bss_inst.BSS926X2i = false;
        bss_inst.BSS926X2j = false;
        bss_inst.BSS926X2k = false;
        bss_inst.BSS926X2m = false;
        bss_inst.BSS926X2n = false;
        bss_inst.BSS926X2P = false;
        bss_inst.BSS926X2q = false;
        bss_inst.BSS926X2r = false;
        PZH926_X1C = false;
        PZH926_X1G = false;
        PZH926_X1d = false;
        PZH926_X3V = false;
        PZH926_X1x = false;
        PZH926_X1BB = false;
        PZH926_X1FF = false;
        PZH926_X1C_b = false;
        PZH926_X1G_b = false;
        PZH926_X1d_b = false;
        PZH926_X3V_b = false;
        PZH926_X1x_b = false;
        PZH926_X1BB_b = false;
        PZH926_X1FF_b = false;
    }

    //logic ends
}
