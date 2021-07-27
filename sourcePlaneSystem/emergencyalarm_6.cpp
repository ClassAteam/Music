#include "emergencyalarm_6.h"

void emergencyalarm_int::emergencyalarm_6()
{
        //White lights_1 2
        static int BSS825X6E{};
        lamp_blink(bss_inst.BSS825X7A, bss_inst.BSS825X6E, BSS825X6E);

        //White lights_1 17

        static int BSS825X6Y{};
        lamp_blink(bss_inst.BSS825X5BB, bss_inst.BSS825X6Y, BSS825X6Y);

        //White lights_1 18

        static int BSS825X6a{};
        lamp_blink(bss_inst.BSS825X5DD, bss_inst.BSS825X6a, BSS825X6a);
}

