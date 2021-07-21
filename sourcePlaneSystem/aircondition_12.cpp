#include "aircondition_12.h"

void aircondition_int::aircondition_12()
{
    bss_inst.BSS838X5j = false;
    bss_inst.BSS838X5h = false;

    y5_2159 = false;
    y7_2159 = false;
    k3_2159 = false;
    prthu4 = false;
    pothu4 = false;
    k2_2159 = false;
    tzto_zad = exchange::tnv;
    bss_inst.BSS838X5p = false;

    if(pruuk592)
    {
        tzto_zad = 40.0;
        if(!exchange::s2_2159 || Ptvt34 < 1.2)
        {
            bss_inst.BSS838X5j = true;
            tzto_zad = exchange::tnv;
            k3_2159 = true;

            if(alpha359y7 > 0.05) alpha359y7 = alpha359y7 - 0.2 * ts;
            else alpha359y7 = 0.0;
        }
        else
        {
            y5_2159 = true;

            if(otkaz_thu4)
            {
                pothu4 = true;
                k2_2159 = false;
                tthu4_zad = 21.0;
                prthu4 = false;
                tzto_zad = 55.0;
                bss_inst.BSS838X5h = true;
                y5_2159 = false;
                k3_2159 = true;
            }
            else
            {
                k2_2159 = true;
                prthu4 = true;
                tthu4_zad = 5.0;

                if(otkaz_per_to_zad) tzto_zad = 71.0;

                if(prthu4)
                {
                    if(abs(tthu4 - tthu4_zad) > 0.2)
                    {
                        if(tthu4 > tthu4_zad)
                        {
                            if(alpha359y7 > 0.05) alpha359y7 = alpha359y7 - 0.2 * ts;
                            else alpha359y7 = 0.0;

                            tthu4 = tthu4 - 1 * ts;
                        }
                        else
                        {
                            if(alpha359y7 > 0.95) alpha359y7 = 1.0;
                            else alpha359y7 = alpha359y7 + 0.2 * ts;

                            tthu4 = tthu4 + 1.0 * ts;
                        }
                    }
                    else tthu4 = tthu4_zad;
                }
            }
        }

        if(abs(tzto - tzto_zad) <= 0.2) tzto = tzto_zad;
        else
        {
            if(tzto > tzto_zad) tzto = tzto - 1.0 * ts;
            else tzto = tzto + 1.0 * ts;
        }

        if(tzto > 70.0)
        {
            pb_ptoz = true;
            bss_inst.BSS838X5p = true;
        }
        else
        {
            if(tzto > 67.0)
            {
                if(pb_ptoz) bss_inst.BSS838X5p = true;
            }
            else pb_ptoz = false;
        }
    }
}
