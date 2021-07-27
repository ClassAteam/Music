#include "emergencyalarm_2.h"

void emergencyalarm_int::emergencyalarm_2()
{
    if (exchange::ush1dpl >= 18.0 && exchange::ush1dpp >= 18.0)
        PRBSS_811 = true;
    else
        PRBSS_811 = false;

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_812 = true;
    else
        PRBSS_812 = false;

    if ((exchange::ush2dpl >= 18.0) && (exchange::ush2dpp >= 18.0) && (exchange::s5_3364))
        PKLLL = true;
    else
        PKLLL = false;

//    if ((exchange::ush1dpl >= 18.0) && (exchange::ush1dpp >= 18.0))
//        USASLL = two_points_to_Y(alpha_rra7ll, 0, 1, 0.75, 1);

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_913 = true;
    else
        PRBSS_913 = false;

        //Red lights_1
        static int bss811X2C{};
        lamp_blink(bss_inst.BSS811X1E, bss_inst.BSS811X2C, bss811X2C);
}
