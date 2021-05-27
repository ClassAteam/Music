#include "emergencyalarm_int.h"

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
