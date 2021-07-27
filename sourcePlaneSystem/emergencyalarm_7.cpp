#include "emergencyalarm_7.h"

void emergencyalarm_int::emergencyalarm_7()
{
    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS926 = true;
    else
        PRBSS926 = false;

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS837 = true;
    else
        PRBSS837 = false;

    if(exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS838 = true;
    else
        PRBSS838 = false;

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && exchange::s7_3364)
        PKLSHO = true;
    else
        PKLSHO = false;

        ///////////////White lights_1
//        bss_inst.BSS926X2e = (bss_inst.BSS926X1HH) ? true : false;
}
