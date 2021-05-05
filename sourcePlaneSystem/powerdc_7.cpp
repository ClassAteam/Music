#include "powerdc_7.h"

void powerdc_int::powerdc_7() //7
{
    //start logic
    if(s17_2430 == s17_2430_pos::akk1_rap1)
    {
        if(purg27lk5)
        {
            ipr = iak1;
        }
        else
        {
            if(purg27lk4)
            {
                ipr = irap1;
            }
            else
            {
                ipr = 0;
            }
        }
    }
    else
    {
        if(s17_2430 == s17_2430_pos::akk2_rap2)
        {
            if(purg27pk5)
            {
                ipr = iak2;
            }
            else
            {
                if(purg27pk4)
                {
                    ipr = irap2;
                }
                else
                {
                    ipr = 0;
                }
            }
        }
        else
        {
            if(s17_2430 == s17_2430_pos::vsu)
            {
                ipr = ingvsu_27;
            }
            else
            {
                ipr = 0;
            }
        }
    }

    switch(s16_2430)
    {
    case s16_2430_pos::akk1:
        powerdc_int::ipr = uak1;
        break;
    case s16_2430_pos::akk2:
        powerdc_int::ipr = uak2;
        break;
    case s16_2430_pos::avar1:
        powerdc_int::ipr = exchange::ushal;
        break;
    case s16_2430_pos::avar2:
        powerdc_int::ipr = exchange::ushap;
        break;
    case s16_2430_pos::sh1lev:
        powerdc_int::ipr = exchange::ush1l;
        break;
    case s16_2430_pos::sh2lev:
        powerdc_int::ipr = exchange::ush2l;
        break;
    case s16_2430_pos::sh1prav:
        powerdc_int::ipr = exchange::ush1p;
        break;
    case s16_2430_pos::sh2prav:
        powerdc_int::ipr = exchange::ush2p;
        break;
    default:
        powerdc_int::ipr = 0.0;
    }
}


    //end logic
