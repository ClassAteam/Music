#include "landinggear_123.h"
#include "switches.h"

void landinggear_int::eventUpd()
{
    checkForMode();
    if(curMode == mode::usualRel)
    {
        release();
    }
    if(curMode == mode::usualIntake)
    {
        intake();
    }
    if(curMode == mode::emergRel)
    {
        release();
    }

    alarmUpd();
}
