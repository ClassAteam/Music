#include "aircondition_16.h"

void aircondition_int::aircondition_16()
{
    bss_inst.zakr_om1 = false;
    bss_inst.BSS926X1T = false;

    if(exchange::ush2dpl >= 18.0)
    {
        if(exchange::s3_2120 && alphazm1 <= 0.0)
            bss_inst.zakr_om1 = true;
        else
        {
            if(!exchange::s1_2120 && alphazm1 <= 0.0)
                bss_inst.BSS926X1T = true;
        }
    }

    bss_inst.zakr_om2 = false;
    bss_inst.BSS926X1V = false;

    if(exchange::ush2dpp >= 18.0)
    {
        if(exchange::s4_2120 && alphazm2 <= 0.0)
            bss_inst.zakr_om2 = true;
        else
        {
            if(!exchange::s2_2120 && alphazm2 <= 0.0)
                bss_inst.BSS926X1V = true;
        }
    }

    if(alphazm1 > 0.05) Pm1 = Potb1_2;
    else Pm1 = 0.0;

    if(alphazm2 > 0.05) Pm2 = Potb3_4;
    else Pm2 = 0.0;

    if(alphaztvt1 > 0.05) Ptvt1 = Potb1_2;
    else Ptvt1 = 0.0;

    if(alphaztvt2 > 0.05) Ptvt2 = Potb3_4;
    else Ptvt2 = 0.0;

    Ptvt12 = Ptvt1;
    Pke = Ptvt2;

    if(alphazktvt12 > 0.05)
    {
        if(Ptvt12 >= Pke) Pke = Ptvt12;
        else Ptvt12 = Pke;
    }

    if(alphaztvt3 > 0.05) Ptvt3 = Potb1_2;
    else Ptvt3 = 0.0;

    if(alphaztvt4 > 0.05) Ptvt4 = Potb3_4;
    else Ptvt4 = 0.0;

    if(Ptvt3 > Ptvt4) Ptvt34 = Ptvt3;
    else Ptvt34 = Ptvt4;

    if(alphazkm12 > 0.05)
    {
        if(Ptvt12 >= Ptvt34) Ptvt34 = Ptvt12;
        else Ptvt12 = Ptvt34;
    }

    if(prthu3) Pthu3 = 1.5;
    if(prthu4) Pthu4 = 1.5;

    if(alpha359y14 > 0.1)
    {
        if(Pthu3 >= Pthu4) Pthu4 = Pthu3;
        else Pthu3 = Pthu4;
    }

    if(pruuk102 && alphazkm12 >= 0.95)
        bss_inst.BSS926X1R = true;
    else
        bss_inst.BSS926X1R = false;

}
