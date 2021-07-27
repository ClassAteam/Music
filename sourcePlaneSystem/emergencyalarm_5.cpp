#include "emergencyalarm_5.h"

void emergencyalarm_int::emergencyalarm_5()
{

    if (exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
    {
        PRBSS824 = true;
    }
    else
    {
        PRBSS824 = false;
    }

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
    {
        PRBSS825 = true;
    }
    else
    {
        PRBSS825 = false;
    }

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && (exchange::s6_3364))
    {
        PKLPL = true;
    }
    else
    {
        PKLPL = false;
    }

        //Red lights_1
        static int bss824X2D{};
        lamp_blink(bss_inst.BSS824X1G, bss_inst.BSS824X2D, bss824X2D);


        //Red lights_1_4
        static int bss824X2P{};
        lamp_blink(bss_inst.BSS824X1d, bss_inst.BSS824X2P, bss824X2P);


        //White lights_1
        bss_inst.BSS824X2f = (bss_inst.BSS824X1KK) ? true : false;
        static int BSS824X2f{};
        lamp_blink(bss_inst.BSS824X1MM, bss_inst.BSS824X2f, BSS824X2f);

        //White lights_1
        bss_inst.BSS824X2h = (bss_inst.BSS824X3A) ? true : false;
        static int BSS824X2h{};
        lamp_blink(bss_inst.BSS824X3C, bss_inst.BSS824X2h, BSS824X2h);

}
