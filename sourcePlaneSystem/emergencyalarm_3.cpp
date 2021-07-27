#include "emergencyalarm_3.h"


void emergencyalarm_int::emergencyalarm_3()
{
    if (bss_inst.BSS812X5Z == true && bss_inst.BSS812X5b == true)
    {
        bss_inst.BSS812X6M = true;
    }
    else
    {
        bss_inst.BSS812X6M = false;
    }

    if (bss_inst.BSS812X5d == true && bss_inst.BSS812X5f == true)
    {
        bss_inst.BSS812X6N = true;
    }
    else
    {
        bss_inst.BSS812X6N = false;
    }
    if (bss_inst.BSS812X5v == true || bss_inst.BSS812X5x == true)
    {
        bss_inst.BSS812X6Y = true;
    }
    else
    {
        bss_inst.BSS812X6Y = false;
    }
}
