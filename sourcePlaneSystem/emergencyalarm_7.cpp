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
        PRBSS926 = true;
    else
        PRBSS926 = false;

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS837 = true;
    else
        PRBSS837 = false;

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS838 = true;
    else
        PRBSS838 = false;

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && exchange::s7_3364)
        PKLSHO = true;
    else
        PKLSHO = false;


    if(PRBSS926)
    {
        ///////////////Yellow lights
        //////////////1
        if(bss_inst.BSS926X1C)
        {
            bss_inst.BSS926X2B = true;
            if(PZH926_X1C_b )
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

        if(exchange::s3_3364 ) PZH926_X1C_b = true;

        ///////////////Yellow lights
        //////////////2
        if (bss_inst.BSS926X1G)
        {
            bss_inst.BSS926X2D = true;
            if(PZH926_X1G_b)
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


        if(exchange::s3_3364 ) PZH926_X1G_b = true;

        ///////////////Yellow lights
        //////////////3
        if(bss_inst.BSS926X1d)
        {
            bss_inst.BSS926X2p = true;
            if(PZH926_X1d_b )
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


        if(exchange::s3_3364 ) PZH926_X1d_b = true;

        ///////////////Yellow lights
        //////////////4
        if(bss_inst.BSS926X3V)
        {
            bss_inst.BSS926X2s = true;
            if(PZH926_X3V_b )
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


        if(exchange::s3_3364) PZH926_X3V_b = true;

        ///////////////Yellow lights
        //////////////5
        if(bss_inst.BSS926X1x)
        {
            bss_inst.BSS926X2z = true;
            if(PZH926_X1x_b )
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


        if(exchange::s3_3364) PZH926_X1x_b = true;

        ///////////////Yellow lights
        //////////////6
        if(bss_inst.BSS926X1BB)
        {
            bss_inst.BSS926X2b = true;
            if(PZH926_X1BB_b )
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

        if(exchange::s3_3364 ) PZH926_X1BB_b = true;

        ///////////////Yellow lights
        //////////////7
        if(bss_inst.BSS926X1FF)
        {
            bss_inst.BSS926X2d = true;
            if(PZH926_X1FF_b)
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


        if(exchange::s3_3364) PZH926_X1FF_b = true;

        if(PZH926_X1C  ||
            PZH926_X1G  ||
            PZH926_X1d  ||
            PZH926_X3V  ||
            PZH926_X1x  ||
            PZH926_X1BB  ||
            PZH926_X1FF)
        {
            PCSOZHSHO_1 = true;
        }
        else
        {
            PCSOZHSHO_1 = false;
        }

        ///////////////White lights_1
        bss_inst.BSS926X2A = (bss_inst.BSS926X1A) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2C = (bss_inst.BSS926X1E) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2E = (bss_inst.BSS926X1J) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2F = (bss_inst.BSS926X1L) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2G = (bss_inst.BSS926X1N) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2H = (bss_inst.BSS926X1R) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2J = (bss_inst.zakr_om1) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2K = (bss_inst.zakr_m1) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2L = (bss_inst.BSS926X1X) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2M = (bss_inst.BSS926X1Z) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2N = (bss_inst.BSS926X1b) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2R = (bss_inst.BSS926X1f) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2S = (bss_inst.BSS926X1h) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2T = (bss_inst.BSS926X1j) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2U = (bss_inst.BSS926X1n) ? true : false;

        ///////////////White lights_1
        if(bss_inst.BSS926X1t )
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
        bss_inst.BSS926X2V = (bss_inst.BSS926X1p) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2W = (bss_inst.BSS926X1r) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2a = (bss_inst.BSS926X1z) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2c = (bss_inst.BSS926X1DD) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2e = (bss_inst.BSS926X1HH) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2f = (bss_inst.BSS926X1KK) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2g = (bss_inst.BSS926X1MM) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2h = (bss_inst.BSS926X3A) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2i = (bss_inst.BSS926X3C) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2j = (bss_inst.BSS926X3E) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2k = (bss_inst.BSS926X3H) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2m = (bss_inst.BSS926X3J) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2n = (bss_inst.BSS926X3L) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2P = (bss_inst.BSS926X3N) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2q = (bss_inst.BSS926X3R) ? true : false;

        ///////////////White lights_1
        bss_inst.BSS926X2r = (bss_inst.BSS926X3T) ? true : false;

        if(PKLSHO )
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
