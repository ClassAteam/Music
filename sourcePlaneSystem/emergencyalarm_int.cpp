#include "emergencyalarm_int.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT *pDev;

emergencyalarm_int::light::light(bool* in_clue, bool* out_clue, bool* is_checked,  type color)
    : inClue{in_clue}, outClue{out_clue}, isChecked{is_checked}, color{color}
{

}

emergencyalarm_int::emergencyalarm_int()
{
    //but this doesnt
    lights.append(new light(&bss_inst.BSS926X1HH, (&bss_inst.BSS926X2e), new bool,
                            type::yellow));
    lights.append(new light(&bss_inst.BSS837X1z , (&bss_inst.BSS837X2a), new bool,
                            type::yellow));
    //why this shit is working
    lights.append(new light(&bss_inst.BSS926X1HH, &(dummy_array[0][1]), new bool,
                            type::yellow));
}
void emergencyalarm_int::updateLogic()
{
    emergencyalarm_1();
    emergencyalarm_2();
    emergencyalarm_3();
    emergencyalarm_4();
    emergencyalarm_5();
    emergencyalarm_6();
    emergencyalarm_7();
    emergencyalarm_8();
    emergencyalarm_9();
}


void emergencyalarm_int::lamp_blink(bool &inpClue, bool &lamp, int &blink)
{
    if(inpClue)
    {
        blink++;
        if((blink * TICK) < 100)
        {
            lamp = false;
        }
        if(((blink * TICK)) >= 100)
        {
            lamp = true;
            if(blink * TICK >= 200) blink = 0;
        }
    }
    else
    {
        blink = 0;
    }
}
