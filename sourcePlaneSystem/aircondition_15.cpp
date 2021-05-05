#include "aircondition_15.h"

void alpha_toggle(bool& Y, double& alpha, double& Kskzsl);

void aircondition_int::aircondition_15()
{
    k12_2110 = false;
    k1_2110 = false;

    if(exchange::ush1l)
    {
        if(exchange::s1_2112)
        {
            if(exchange::K25_3230) k12_2110 = true;

            if(!pvklgvdv && (exchange::PRD1dv || exchange::PRD2dv))
                k1_2112 = true;
        }

        alpha_toggle(k1_2112, alphazszl, Kskzsl);

        if(alphazszl >= 1.0) bss_inst.BSS824X3E = true;
        else bss_inst.BSS824X3E = false;
    }

    k18_2110 = false;
    k20_2110 = false;

    if(exchange::ush1p)
    {
        if(exchange::s4_2112)
        {
            if(exchange::K27_3230) k18_2110 = true;

            if(!pvklgvdv && (exchange::PRD3dv || exchange::PRD4dv))
                k20_2112 = true;
        }

        alpha_toggle(k20_2112, alphazszp, Kskzsl);

        if(alphazszp >= 1.0) bss_inst.BSS825X7R = true;
        else bss_inst.BSS825X7R = false;
    }


    if(exchange::ushak1 >= 18.0)
    {
        if(totvsu >= 27.0) k1_2143 = false;

        if(totvsu >= 15.0) k1_2143 = true;

        alpha_toggle(k1_2143, alphazovsu, Kskzsl);
    }

    poovsu = false;
}
