#include "emergencyalarm_9.h"
#include "algorithms.h"

void yellow(bool* input, bool* output, bool* clue, bool* block_clue, bool* button);
void white(bool* input, bool* output);

void emergencyalarm_int::emergencyalarm_9()
{
    static int bss838X6g{};
    lamp_blink(bss_inst.BSS838X5MM, bss_inst.BSS838X6g, bss838X6g);
    //4
    static int bss838X6h{};
    lamp_blink(bss_inst.BSS838X7A, bss_inst.BSS838X6h, bss838X6h);

}
