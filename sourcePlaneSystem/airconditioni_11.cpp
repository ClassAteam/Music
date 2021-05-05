#include "airconditioni_11.h"

void alpha_toggle(bool& Y, double& alpha, double& Kskzsl);

void aircondition_int::aircondition_11()
{

    y4_2159 = false;
    y5_2159 = false;
    y6_2159 = false;
    bss_inst.BSS926X1N = false;
    pruuk592 = false;

    tzgo_zad = exchange::tnv;

    if(pnu)
    {
        tzgo = exchange::tnv;
        Dtzgo1 = 0.0;
        Dtzgo2 = 0.0;
    }

    if(exchange::ushap >= 18.0) pruuk592 = true;


    if(pruuk592)
    {
        if(exchange::s2_2153)
        {
            if(prthu1 || prthu2)
            {
                tzgo_zad = 40.0;

                if(alpha359y14 > 0.95)
                {
                    bss_inst.BSS926X1N = true;

                    if(abs(tzgo - 40.0) >= 0.2)
                    {
                        if(tzgo > 41.0 || tzgo >= 39.0) y6_2159 = true;
                    }
                    else tpgo = 40.0;
                }

                if(tzgo < -0.5)
                {
                    y4_2159 = true;
                    y5_2159 = true;
                }
            }
        }

        alpha_toggle(y6_2159, alpha359y6, Kskzsl);
        alpha_toggle(y4_2159, alpha359y4, Kskzsl);
        alpha_toggle(y5_2159, alpha359y5, Kskzsl);

        if(abs(tzgo_zad - tzgo) > 0.2)
        {
            if(tzgo > tzgo_zad) tzgo = tzgo - 0.5 * tS;
            else tzgo = tzgo + 0.5 * tS;
        }
        else tzgo = tzgo_zad;

        if(prthu1) Dtzgo1 = 1.0 * alpha359y4;
        if(prthu2) Dtzgo2 = 1.0 * alpha359y5;
        tzgo = tzgo + Dtzgo1 * tS + Dtzgo2 * tS;
    }
}
