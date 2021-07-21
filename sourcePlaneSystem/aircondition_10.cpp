#include "aircondition_10.h"

void alpha_toggle(bool& Y, double& alpha, double& Kskzsl);

void aircondition_int::aircondition_10()
{

    y1_2159 = false;
    y2_2159 = false;
    y3_2159 = false;
    bss_inst.BSS926X1L = false;
    pruuk591 = false;

    tpgo_zad = exchange::tnv;

    if(pnu)
    {
        tpgo = exchange::tnv;
        Dtpgo1 = 0.0;
        Dtpgo2 = 0.0;
    }

    if(exchange::ushal >= 18.0) pruuk591 = true;


    if(pruuk591)
    {
        if(exchange::s1_2153)
        {
            if(prthu1 || prthu2)
            {
                tpgo_zad = 40.0;

                if(alpha359y14 > 0.95)
                {
                    bss_inst.BSS926X1L = true;

                    if(abs(tpgo - 40.0) >= 0.2)
                    {
                        if(tpgo > 41.0 || tpgo >= 39.0) y3_2159 = true;
                    }
                    else tpgo = 40.0;
                }

                if(tpgo < -0.5)
                {
                    y1_2159 = true;
                    y2_2159 = true;
                }
            }
        }

        alpha_toggle(y3_2159, alpha359y3, Kskzsl);
        alpha_toggle(y1_2159, alpha359y1, Kskzsl);
        alpha_toggle(y2_2159, alpha359y2, Kskzsl);

        if(abs(tpgo_zad - tpgo) > 0.2)
        {
            if(tpgo > tpgo_zad) tpgo = tpgo - 0.5 * ts;
            else tpgo = tpgo + 0.5 * ts;
        }
        else tpgo = tpgo_zad;

        if(prthu1) Dtpgo1 = 1.0 * alpha359y1;
        if(prthu2) Dtpgo2 = 1.0 * alpha359y2;
        tpgo = tpgo + Dtpgo1 * ts + Dtpgo2 * ts;
    }
}
