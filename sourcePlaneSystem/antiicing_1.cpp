#include "antiicing_1.h"

void antiicing_int::antiicing_1()
{

    M = M_buf / 100;
    usho1p = exchange::usho1p;
    alpha_rud_1dv = exchange::alpha_rud_1dv;
    alpha_rud_2dv = exchange::alpha_rud_2dv;
    alpha_rud_3dv = exchange::alpha_rud_3dv;
    alpha_rud_4dv = exchange::alpha_rud_4dv;


static int
    PZ1_tick,
    PZ2_tick,
    PZ3_tick,
    PZ1_sec,
    PZ2_sec,
    PZ3_sec,
    Counter_mkam;
    Counter_mkam++;

    F12_3020 = false;
    K51_3020 = false;

    if(usho1p >= 18.0)
    {
        if(M <= 1.25) F12_3020 = true;

        if (exchange::s6_3020) K51_3020 = true;
    }

    K2_3020 = false;

    if(exchange::ushap >= 18.0)
    {
        if (!K51_3020)
            if(K27_3230) K2_3020 = true;
    }

    PZ1 = false;
    PZ2 = false;
    PZ3 = false;
    F110_3020 = false;
    F19_3020 = false;
    F125_3020 = false;
    F134_3020 = false;

    if(!K2_3020 && F12_3020 && !otkaz_vozduhozabor)
    {
        switch(exchange::s1_3020)
        {
        case(static_cast<int>(exchange::s1_3020::neytr)):
            break;
        case(static_cast<int>(exchange::s1_3020::minus6minus15)):
            PZ2 = true;
            break;
        case(static_cast<int>(exchange::s1_3020::zerominus6)):
            PZ1 = true;
            break;
        case(static_cast<int>(exchange::s1_3020::minus15)):
            PZ3 = true;
        }
    }

    //S1_3020 switching = 2
    if(PZ1)
    {
        PZ1_tick++;
        if((PZ1_tick * TICK) > 1000)
        {
            PZ1_sec++;
            PZ1_tick = 0;
        }

        //F110 toggling
        if (((PZ1_sec) < 20) || (((PZ1_sec) >= 120) && ((PZ1_sec) < 140)) ||
            (((PZ1_sec) >= 240) && ((PZ1_sec) < 260)) || (((PZ1_sec) >= 360) &&
             ((PZ1_sec) < 380)))
            F110_3020 = true;
        else
            F110_3020 = false;

        //F125 toggling
        if ((PZ1_sec) > 400 && (PZ1_sec) < 420)
            F125_3020 = true;
        else
            F125_3020 = false;

        //F134 toggling
        if ((((PZ1_sec) > 160) && ((PZ1_sec) < 180)) ||
            (((PZ1_sec) > 440) && ((PZ1_sec) < 460)))
            F134_3020 = true;
        else
            F134_3020 = false;

        if(PZ1_sec > 480)
        {
            PZ1_sec = 0;
            PZ1_tick = 0;
        }
    }
    else
    {
        PZ1_sec = 0;
        PZ1_tick = 0;
    }

    //S1_3020 switching = 3
    if(PZ2)
    {
        PZ2_tick++;
        if((PZ2_tick * TICK) > 1000)
        {
            PZ2_sec++;
            PZ2_tick = 0;
        }

        //F110 toggling
        if (((PZ2_sec) < 20) || (((PZ2_sec) >= 120) && ((PZ2_sec) < 140)) ||
            (((PZ2_sec) >= 240) && ((PZ2_sec) < 260)) || (((PZ2_sec) >= 360) &&
             ((PZ2_sec) < 380)))
            F110_3020 = true;
        else
            F110_3020 = false;

        //F19 toggling
        if ((((PZ2_sec) >= 40) && ((PZ2_sec) < 60)) ||
            (((PZ2_sec) >= 280) && ((PZ2_sec) < 300)))
            F19_3020 = true;
        else
            F19_3020 = false;

        //F125 toggling
        if ((((PZ2_sec) >= 160) && ((PZ2_sec) < 180)) ||
            (((PZ2_sec) >= 400) && ((PZ2_sec) < 420)))
            F125_3020 = true;
        else
            F125_3020 = false;

        //F134 toggling
        if ((((PZ2_sec) >= 440) && ((PZ2_sec) < 460)))
            F134_3020 = true;
        else
            F134_3020 = false;

        if(PZ2_sec > 480)
        {
            PZ2_sec = 0;
            PZ2_tick = 0;
        }
    }
    else
    {
        PZ2_sec = 0;
        PZ2_tick = 0;
    }

    //S1_3020 switching = 1
    if (PZ3 == true)
    {
        PZ3_tick++;
        if((PZ3_tick * TICK) > 1000)
        {
            PZ3_sec++;
            PZ3_tick = 0;
        }

        //F110 toggling
        if (((PZ3_sec) < 60) || (((PZ3_sec) >= 240) && ((PZ3_sec) < 300)))
            F110_3020 = true;
        else
            F110_3020 = false;

        //F19 toggling
        if ((((PZ3_sec) >= 120) && ((PZ3_sec) < 180)) ||
            (((PZ3_sec) >= 360) && ((PZ3_sec) < 420)))
            F19_3020 = true;
        else
            F19_3020 = false;

        //F125 toggling
        if ((((PZ3_sec) >= 180) && ((PZ3_sec) < 240)) ||
            (((PZ3_sec) >= 420) && ((PZ3_sec) < 480)))
            F125_3020 = true;
        else
            F125_3020 = false;

        //F134 toggling
        if ((((PZ3_sec) >= 300) && ((PZ3_sec) < 360)))
            F134_3020 = true;
        else
            F134_3020 = false;

        if(PZ3_sec > 480)
        {
            PZ3_sec = 0;
            PZ3_tick = 0;
        }
    }
    else
    {
        PZ3_sec = 0;
        PZ3_tick = 0;
    }
}
