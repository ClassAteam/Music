#include "cabinlighting_2.h"


void cabinlighting_int::cabinlighting_6()
{
static int
    S2_1_tick,
    S2_2_tick;

    if (exchange::ush1p >= 18.0)
    {
        // S2 100% mode
        if (S2_3341 == static_cast<int>(S2_3341::mayak100))
        {
            S2_1_tick++;

            if ((S2_1_tick * TICK) < 600)
            {
                PVMN100 = true;
                PVMV100 = false;
            }

            if((S2_1_tick * TICK) >= 600 &&
                (S2_1_tick * TICK) < 1200)
            {
                PVMN100 = false;
                PVMV100 = true;
            }

            if((S2_1_tick * TICK) >= 1200) S2_1_tick = 0;
        }
        else
        {
            S2_1_tick = 0;
            PVMN100 = false;
            PVMV100 = false;
        }

        // S2 low mode
        if (S2_3341 == static_cast<int>(S2_3341::ponizh))
        {
            if (exchange::P2OBLOP && (exchange::PRD1dv &&
                 exchange::PRD4dv && exchange::F32_3250))
            {
                S2_2_tick++;

                if ((S2_2_tick * TICK) < 600)
                {
                    PVMN10 = true;
                    PVMV10 = false;
                }

                if((S2_2_tick * TICK) >= 600 &&
                    (S2_2_tick * TICK) < 1200)
                {
                    PVMN10 = false;
                    PVMV10 = true;
                }

                if((S2_2_tick * TICK) >= 1200)
                {
                    S2_2_tick = 0;
                }
            }
        }
        else
        {
            S2_2_tick = 0;
            PVMN10 = false;
            PVMV10 = false;
        }
    }
}
