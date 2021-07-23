#include "aircondition_15.h"

void alpha_toggle(bool& Y, double& alpha, double& Kskzsl);

void aircondition_int::aircondition_15()
{
    k12_2110 = false;
    k1_2112 = false;

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
    k20_2112 = false;

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

    if(pruuk101 && landinggea.S35_3230)
    {
        k2_2143 = true;
        totvsu_zad = 27.0;
    }
    else
    {
        k2_2143 = false;
        totvsu_zad = exchange::tnv;

    }

    if(exchange::ush1l >= 18.0)
    {
        if(totvsu >= 27.0 && k2_2143) k1_2143 = false;

        if(totvsu >= 15.0) k1_2143 = true;

        alpha_toggle(k1_2143, alphazovsu, Kskzsl);
        if(k1_2143)
            totvsu = totvsu + 0.01 * ts;
        else
            totvsu = totvsu - 0.01 * ts;
    }
    else
    {
        k1_2143 = false;
    }

    poovsu = false;

    if(abs(totvsu_zad - totvsu) <= 0.2)
        totvsu = totvsu_zad;
    else
        poovsu = false;
}
