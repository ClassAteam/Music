#include "cabinlighting_2.h"

static void blnkLights(bool& pvmn, bool& pvmv, int& tick);

void cabinlighting_int::cabinlighting_6()
{
    static int tick100{};
    static int tick10{};

    if (exchange::ush1p >= 18.0)
    {
        // S2 100% mode
        if (S2_3341 == static_cast<int>(S2_3341::mayak100))
        {
            blnkLights(PVMN100, PVMV100, tick100);
        }
        else
        {
            PVMN100 = false;
            PVMV100 = false;
            tick100 = 0;
        }

        // S2 low mode
        if (S2_3341 == static_cast<int>(S2_3341::ponizh))
        {
            if(exchange::P2OBLOP ||
                (exchange::PRD1dv && exchange::PRD4dv && exchange::F32_3250))
            blnkLights(PVMN10, PVMV10, tick10);
        }
        else
        {
            PVMN10 = false;
            PVMV10 = false;
            tick10 = 0;
        }
    }
}

static void blnkLights(bool& pvmn, bool& pvmv, int& tick)
{
    tick++;

    if ((tick * TICK) < 600)
    {
        pvmn = true;
        pvmv = false;
    }

    if((tick * TICK) >= 600 &&
        (tick * TICK) < 1200)
    {
        pvmn = false;
        pvmv = true;
    }

    if((tick * TICK) >= 1200)
    {
        pvmn = false;
        pvmv = false;
    }
    if((tick * TICK) >= 10000)
    {
        tick = 0;
    }
}
