#include "aircondition_13.h"

void aircondition_int::aircondition_13()
{
    bss_inst.BSS838X5f = false;
    bss_inst.otklyuchiToGo = false;
    y11_2159 = false;
    y13_2159 = false;
    k4_2159 = false;
    prthu3 = false;
    pothu3 = false;
    k1_2159 = false;
    tsto_zad = exchange::tnv;
    bss_inst.BSS838X5n = false;
    y14_2159 = false;

    if(pruuk591)
    {
        tsto_zad = 40.0;

        if(!exchange::s1_2159 || Ptvt12 < 1.2)
        {
            bss_inst.BSS838X5f = true;
            tsto_zad = exchange::tnv;
            k1_2159 = true;

            if(alpha359y13 > 0.05) alpha359y13 = alpha359y13 - 0.2 * ts;
            else alpha359y13 = 0.0;
        }
        else
        {
            y11_2159 = true;
            if(otkaz_thu3)
            {
                pothu3 = true;
                k1_2159 = true;
                tthu3_zad = 21.0;
                prthu3 = false;
                tsto_zad = 55.0;
                bss_inst.otklyuchiToGo = true;
                y11_2159 = false;
                k4_2159 = true;
            }
            else
            {
                k1_2159 = false;
                prthu3 = true;
                tthu3_zad = 5.0;
                if(prthu3)
                {
                    if(abs(tthu3 - tthu3_zad) > 0.2)
                    {
                        if(tthu3 > tthu3_zad)
                        {
                            if(alpha359y13 > 0.05) alpha359y13 = alpha359y13 - 0.2 * ts;
                            else alpha359y13 = 0.0;

                            tthu3 = tthu3 - 3 * ts;
                        }
                        else
                        {
                            if(alpha359y13 > 0.95) alpha359y13 = 1.0;
                            else alpha359y13 = alpha359y13 + 0.2 * ts;

                            tthu3 = tthu3 + 3 * ts;
                        }
                    }
                    else
                    {
                        tthu3 = tthu3_zad;
                    }
                }
            }
        }

        if(abs(tsto - tsto_zad) > 0.2)
        {
            if(tsto > tsto_zad) tsto = tsto - 3 * ts;
            else tsto = tsto + 3 * ts;
        }
        else tsto = tsto_zad;

        if(k3_2159 && k4_2159) bss_inst.BSS838X5n = true;
    }
    else tsto = 0.0;

//    if(k1_2159 && k2_2159) y14_2159 = true;

    if(k1_2159 != k2_2159)
        y14_2159 = true;
    else
        y14_2159 = false;

    if(exchange::ush2dpp >= 18.0)
    {
        if(!y14_2159)
        {
            if(alpha359y14 >= 0.05) alpha359y14 = alpha359y14 - 0.2 * ts;
            else alpha359y14 = 0.0;
        }
        else
        {
            if(alpha359y14 < 0.95) alpha359y14 = alpha359y14 + 0.2 * ts;
            else alpha359y14 = 1.0;
        }
    }
}
