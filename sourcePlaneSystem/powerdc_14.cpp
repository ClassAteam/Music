#include "powerdc_14.h"

void powerdc_int::powerdc_14()
{
    double kpts{2.5};
    static bool f46_2420{true};
    static int tick1, tick2, tick3 ;

    if(!pp400[0] && !pp400[1] && !purglk2 && !purgpk3)
        k17_2420 = false;
    else
        k17_2420 = true;

    if(exchange::ush2dpl >= 18.0 && f46_2420 && exchange::s15_2420)
        k15_2420 = true;
    else
        k15_2420 = false;

    if(k15_2420 && !otk_preobr_pts1)
    {
        exchange::upts = exchange::upts + (117 - exchange::upts) / kpts;
        exchange::fpts = exchange::fpts + (400 - exchange::fpts) / kpts;
    }
    else
    {
        if(exchange::upts > 1.0)
        {
            exchange::upts = exchange::upts + (0 - exchange::upts) / kpts;
        }
        else
            exchange::upts = 0.0;

        if(exchange::fpts > 1.0)
        {
            exchange::fpts = exchange::fpts + (0 - exchange::fpts) / kpts;
        }
        else
            exchange::fpts = 0.0;
    }


    if(k15_2420 && !k17_2420)
    {
        k14_2420 = true;
        purglk10 = true;
    }
    else
    {
        k14_2420 = false;
        purglk10 = false;
    }

    if(k17_2420)
    {
        if(exchange::ushpts[0] >= 65.0 && exchange::ushpts[1] >= 65.0 && exchange::ushpts[2] >= 65.0)
        {
            if(pbapsh3)
            {
                k14_2420 = true;
                purglk10 = true;
            }
        }
        else
        {
            if(tick3 * TICK >= 800)
            {
                pbapsh3 = true;
                k14_2420 = true;
                purglk10 = true;
            }
            else
                tick3++; //not seted to 0 anywhere
        }
    }
    else
    {
        pbapsh3 = false;
    }

    if(!pp400[0] && !purglk2)
        k19_2420 = false;
    else
        k19_2420 = true;

    k13_2420 = false;
    purglk9 = false;

    if(exchange::ush2dpl >= 18.0)
    {
        if(k19_2420)
        {
            if(exchange::ushavP[0][0] >= 65.0 && exchange::ushavP[0][1] >= 65.0 &&
                exchange::ushavP[0][2] >= 65.0)
            {
                if(pbapsh1)
                {
                    k13_2420 = true;
                    purglk9 = true;
                }
            }
            else
            {
                if(tick1 * TICK >= 300)
                {
                    pbapsh1 = true;
                    k13_2420 = true;
                    purglk9 = true;
                }
                else
                    tick1++;
            }
        }
        else
            pbapsh1 = false;
    }

    if(!pp400[1] && !purgpk3)
        k20_2420 = false;
    else
        k20_2420 = true;

    k16_2420 = false;
    purgpk9 = false;

    if(exchange::ush2dpp >= 18.0)
    {
        if(k20_2420)
        {
            if(exchange::ushavP[1][0] >= 65.0 && exchange::ushavP[1][1] >= 65.0
                && exchange::ushavP[1][2] >= 65.0)
            {
                if(pbapsh2)
                {
                    k16_2420 = true;
                    purgpk9 = true;
                }
            }
            else
            {
                if(tick2 * TICK >= 300)
                {
                    pbapsh2 = true;
                    k16_2420 = true;
                    purgpk9 = true;
                }
                else
                    tick2++;
            }
        }
        else
            pbapsh2 = false;
    }

    exchange::uptsP[0] = exchange::upts;
    exchange::uptsP[1] = exchange::upts - 1;
    exchange::uptsP[2] = exchange::upts - 2;
}
