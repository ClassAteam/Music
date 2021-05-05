#include "landinggear_5.h"
#include "algorithms.h"


void landinggear_int::landinggear_5() //actually 5th
{
    GK_dvl = false;
    GK_duoop = false;

    // Force release left rack hydrovalve
    if ((exchange::ushal >= 19.0 && K2_3230) || K3_3230)
            GK_dvl = true;
    else
            GK_dvl = false;

    // Force intake racks hydrovalve
    if (K11_3230 == true || K12_3230 == true)
        GK_duoop = true;

    //	Release and intake racks hydrovalves
    if(!K22_3230)
    {
        if (K23_3230 == false)
        {
            gk_vsh = false;
            gk_ush = false;
        }
        else
        {
            gk_vsh = false;
            gk_ush = true;
        }
    }
    else
    {
            gk_vsh = true;
            gk_ush = false;
    }

    GK_dvp = false;

    // Force release right rack hydrovalve
    if ((exchange::ushap >= 19.0 && K28_3230) || K29_3230)
            GK_dvp = true;
    else
            GK_dvp = false;

    // Common release disabling hydrovalve
    if (exchange::ush1dpp >= 19.0 && S30_3230)
    {
        gk_oovsh = true;
        K13_3230 = true;
        K14_3230 = true;
    }
    else
    {
        gk_oovsh = false;
        K13_3230 = false;
        K14_3230 = false;
    }

    // Emergency nose release hydrovalve
    if (exchange::ush1dpp >= 19.0 && K13_3230)
        gk_avn = true;
    else
        gk_avn = false;

    // Emergency left and right racks release hydrovalve
    if (exchange::ush1dpp >= 19.0 && K14_3230)
    {
        gk_avl = true;
        gk_avp = true;
    }
    else
    {
        gk_avl = false;
        gk_avp = false;
    }
}
