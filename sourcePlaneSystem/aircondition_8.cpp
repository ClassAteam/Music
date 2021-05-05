#include "aircondition_8.h"

void alpha_toggle(bool& Y, double& alpha, double& Kskzsl);

void aircondition_int::aircondition_8()
{
    y5_2158 = false;
    y4_2158 = false;
    y6_2158 = false;
    bss_inst.BSS926X1J = false;
    bss_inst.BSS926X1G = false;
    bss_inst.BSS838X5T = false;
    pothu2 = false;
    k1_2158 = false;
    prthu2 = false;

    if(exchange::ushap >= 18.0) pruuk58 = true;

    if(pruuk58)
    {
        if(exchange::s1_2158)
        {
            if(Ptvt34 >= 1.2)
            {
                if(otkaz_thu2)
                {
                    pothu2 = true;
                    k1_2158 = true;
                    bss_inst.BSS926X1G = true;
                }
                else
                {
                    prthu2 = true;
                    y6_2158 = true;
                }
            }
            if(!k2_2131) y4_2158 = true;
        }
        else bss_inst.BSS926X1J = true;
    }

    alpha_toggle(y4_2158, alpha358y4, Kskzsl);
    alpha_toggle(y5_2158, alpha358y5, Kskzsl);

    y1_2157 = false;
    y2_2157 = false;

    if(exchange::ush2dpl >= 18.0 && exchange::s1_2158)
    {
        if(!pothu2) y1_2157 = true;
        else
        {
            if(!pothu1) y2_2157 = true;
        }
    }

    alpha_toggle(y1_2157, alpha357y1, Kskzsl);
    alpha_toggle(y2_2157, alpha357y2, Kskzsl);
}
