#include "landinggear_123.h"
#include "switches.h"

void landinggear_int::landinggear_123()
{
    setVelocity();

    if(s2_3230::instance().pos == s2_3230::position::release)
    {
        release();
    }

    if(s2_3230::instance().pos == s2_3230::position::intake)
    {
        intake();
    }

}
