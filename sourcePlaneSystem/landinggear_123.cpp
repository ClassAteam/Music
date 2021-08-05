#include "landinggear_123.h"
#include "switches.h"

void landinggear_int::eventUpd()
{
    if(s2_3230::instance().pos == s2_3230::position::release)
    {
        release();
    }
    if(s2_3230::instance().pos == s2_3230::position::intake)
    {
        intake();
    }
//    if(s30_3230::instance().pos == s30_3230::position::intake)
//    {
//        release();
//    }
    alarmUpd();

}
