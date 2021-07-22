#include "aircondition_14.h"

void alpha_toggle(bool& Y, double& alpha, double& Kskzsl);

void aircondition_int::aircondition_14()
{
    k1_12360 = false;
    k2_12360 = false;
    k3_12360 = false;
    a3_12360 = false;
    bss_inst.BSS838X5V = false;
    bss_inst.BSS838X5X = false;
    k4_12360 = false;
    a6_12360 = false;
    bss_inst.BSS838X5Z = false;
    bss_inst.BSS838X5b = false;
    bss_inst.BSS838X5r = false;

    if(exchange::ush1l >= 18.0 && exchange::ushgP[0][0] >= 110.0)
    {
        if(exchange::pk70_vkl)
        {
            if(exchange::pk70_pgo) k1_12360 = true;
            if(exchange::pk70_zgo) k2_12360 = true;
        }
    }

    if(exchange::usho2p >= 18.0)
    {
        if(!k1_12360) bss_inst.BSS838X5V = true;
        if(!k2_12360) bss_inst.BSS838X5Z = true;

        if(exchange::s2_12360)
        {
            a3_12360 = false;
            a6_12360 = false;
        }
        else
        {
            k3_12360 = true;

            if(exchange::s1_12360) a3_12360 = true;
            else
                if(k1_12360 && exchange::pk70_kontrt) a3_12360 = true;

            if(exchange::s3_12360) a6_12360 = true;
            else
                if(k2_12360 && exchange::pk70_kontrt) a6_12360 = true;

        }
            if(alpha312a3 == 1) bss_inst.BSS838X5X = true;
            if(alpha312a6 == 1) bss_inst.BSS838X5b = true;
            if(!k3_12360) bss_inst.BSS838X5r = true;

            if(a3_12360) bss_inst.BSS838X5V = false;
            if(a6_12360) bss_inst.BSS838X5Z = false;

            alpha_toggle(a3_12360, alpha312a3, Kskzsl);
            alpha_toggle(a6_12360, alpha312a6, Kskzsl);
    }
}
