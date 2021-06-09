#include "powerdc_7.h"

void powerdc_int::powerdc_7() //7
{
    //start logic
    if(exchange::s17_2430 == static_cast<int>(exchange::s17_2430::akk1_rap1))
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
        if(exchange::s17_2430 == static_cast<int>(exchange::s17_2430::akk2_rap2))
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
            if(exchange::s17_2430 == static_cast<int>(exchange::s17_2430::vsu))
            {
                ipr = ingvsu_27;
            }
            else
            {
                ipr = 0;
            }
        }
    }

    switch(exchange::s16_2430)
    {
    case static_cast<int>(exchange::s16_2430::akk1):
        powerdc_int::upr = uak1;
        break;
    case static_cast<int>(exchange::s16_2430::akk2):
        powerdc_int::upr = uak2;
        break;
    case static_cast<int>(exchange::s16_2430::avar1):
        powerdc_int::upr = exchange::ushal;
        break;
    case static_cast<int>(exchange::s16_2430::avar2):
        powerdc_int::upr = exchange::ushap;
        break;
    case static_cast<int>(exchange::s16_2430::sh1lev):
        powerdc_int::upr = exchange::ush1l;
        break;
    case static_cast<int>(exchange::s16_2430::sh2lev):
        powerdc_int::upr = exchange::ush2l;
        break;
    case static_cast<int>(exchange::s16_2430::sh1prav):
        powerdc_int::upr = exchange::ush1p;
        break;
    case static_cast<int>(exchange::s16_2430::sh2prav):
        powerdc_int::upr = exchange::ush2p;
        break;
    default:
        powerdc_int::upr = 0.0;
    }
}


    //end logic
