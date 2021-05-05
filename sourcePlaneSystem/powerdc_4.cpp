#include "powerdc_4.h"

void powerdc_int::powerdc_4()
{
    //start logic
    if(purg27lk6)
    {
        exchange::ushzvsu = uak1;
    }
    else
    {
        exchange::ushzvsu = 0;
    }


    if(plp27 || (ppp27 && pss27))
    {
        exchange::ushal = exchange::ush1l;
    }
    else
    {
        if(ppgvsu27)
        {
            exchange::ushal = ugvsu27;
//            ush1l = ugvsu27;
//            ush2l = ugvsu27;
        }
        else
        {
            if(purg27lk5)
            {
                exchange::ushal = uak1;
            }
            else
            {
                if(purg27lk4)
                {
                    exchange::ushal = urap1;
                }
                else
                {
                    exchange::ushal = 0.0;
                }
            }
        }
    }

    if(ppp27 || (plp27 && pss27))
    {
        exchange::ushap = exchange::ush1p;
    }
    else
    {
        if(purg27pk5)
        {
            exchange::ushap = uak2;
        }
        else
        {
            if(purg27pk4)
            {
                exchange::ushap = urap2;
            }
            else
            {
                exchange::ushap = 0.0;
            }
        }
    }

    if(purg27lk4)
    {
        exchange::ushal = urap1;
    }

    if(purg27pk4)
    {
        exchange::ushap = urap2;
    }

    if(purg27pk3)
    {
        if(exchange::ushal >= exchange::ushap)
        {
            exchange::ushap = exchange::ushal;
        }
        else
        {
            exchange::ushal = exchange::ushap;
        }
    }

    if(prg1)
    {
        exchange::ush1l = ug1_27;
    }
    else
    {
        exchange::ush1l = 0;
    }

    if(prg2)
    {
        exchange::ush2l = ug2_27;
    }
    else
    {
        exchange::ush2l = 0;
    }

    if(ppgvsu27)
    {
        exchange::ush1l = ugvsu27;
        exchange::ush2l = ugvsu27;
    }

    if(exchange::ush1l >= exchange::ush2l)
    {
        exchange::ush2l = exchange::ush1l;
        uls27 = exchange::ush1l;
    }
    else
    {
        exchange::ush1l = exchange::ush2l;
        uls27 = exchange::ush2l;
    }

    if(prg3)
    {
        exchange::ush1p = ug3_27;
    }
    else
    {
        exchange::ush1p = 0;
    }

    if(prg4)
    {
        exchange::ush2p = ug4_27;
    }
    else
    {
        exchange::ush2p = 0;
    }

    if(purg27pk4)
    {
        exchange::ush1p = urap2;
        exchange::ush2p = urap2;
    }

    if(purg27lk4)
    {
        exchange::ush1l = urap1;
        exchange::ush2l = urap1;
    }

    if(exchange::ush1p >= exchange::ush2p)
    {
        exchange::ush2p = exchange::ush1p;
        ups27 = exchange::ush1p;
    }
    else
    {
        exchange::ush1p = exchange::ush2p;
        ups27 = exchange::ush2p;
    }

    if(pss27)
    {
        if(exchange::ush1l > exchange::ush1p)
        {
            exchange::ush1p = exchange::ush1l;
            exchange::ush2p = exchange::ush1l;
            exchange::ushap = exchange::ush1l;
            ups27 = exchange::ush1l;
        }
        else
        {
            exchange::ush1l = exchange::ush1p;
            exchange::ush2l = exchange::ush1p;
            exchange::ushal = exchange::ush1p;
            uls27 = exchange::ush1p;
        }
    }

    if(purg27pk9)
    {
        exchange::ush1dpp = exchange::ush1p;
        exchange::ush2dpp = exchange::ush2p;
    }
    else
    {
        exchange::ush1dpp = exchange::ushap;
        exchange::ush2dpp = exchange::ushap;
    }

    if(purg27lk9)
    {
        exchange::ush1dpl = exchange::ush1l;
        exchange::ush2dpl = exchange::ush2l;
    }
    else
    {
        exchange::ush1dpl = exchange::ushal;
        exchange::ush2dpl = exchange::ushal;
    }

    if(purg27lk7)
    {
        exchange::usho1l = exchange::ush1l;
        exchange::usho2l = exchange::ush2l;
    }
    else
    {
        exchange::usho1l = 0;
        exchange::usho2l = 0;
    }

    if(purg27pk7)
    {
        exchange::usho1p = exchange::ush1p;
        exchange::usho2p = exchange::ush2p;
    }
    else
    {
        exchange::usho1p = 0;
        exchange::usho2p = 0;
    }

    if(purg27lk1)
    {
        if(exchange::ushal > uls27)
        {
            uls27 = exchange::ushal;
        }
        else
        {
            exchange::ushal = uls27;
        }
    }

    if(purg27pk1)
    {
        if(exchange::ushak2 >= ups27)
        {
            ups27 = exchange::ushap;
        }
        else
        {
            exchange::ushap = ups27;
        }
    }
}
