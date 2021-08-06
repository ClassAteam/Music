#include "landinggear_123.h"
#include "switches.h"

void landinggear_int::eventUpd()
{
    checkMode();
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
