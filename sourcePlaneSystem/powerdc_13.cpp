#include "powerdc_13.h"

void powerdc_int::powerdc_13()
{
    if(pvrap && exchange::speed < 0.1)
    {
        pprap = true;
        exchange::urapP[0] = 117.0;
        exchange::urapP[1] = 115.0;
        exchange::urapP[2] = 116.0;
        exchange::frap = 401.0;
    }
    else
    {
        pprap = false;
        exchange::urapP[0] = 0;
        exchange::urapP[1] = 0;
        exchange::urapP[2] = 0;
        exchange::frap = 0;
    }

    if(exchange::ushap >= 18.0 && pprap && s9_2420)
        purgpk3 = true;
    else
        purgpk3 = false;

    if(prgen[4])
        purglk2 = true;
    else
        purglk2 = false;

    purglk7 = false;
    purgpk7 = false;
    purglk8 = false;
    pss400 = false;

    for(int x = 0; x < 2; x++)
    {
        if(x == 0)
        {
            if(pog[0] && pog[1])
                pp400[0] = false;
            else
            {
                pp400[0] = true;
                purglk7 = false;
            }
        }
        else
        {
            if(pog[2] && pog[3])
                pp400[1] = false;
            else
            {
                pp400[1] = true;
                purgpk7 = false;
            }
        }
    }

    if(pp400[0])
    {
        if(pp400[1])
        {
        }
        else
        {
            if(s2_2420)
            {
                purglk7 = true;
                purgpk7 = true;
                purglk8 = true;
                pss400 = true;
            }
            else
            {
                if(purglk2)
                {
                    if(pp400[0])
                    {
                        purgpk7 = true;
                        purglk8 = true;
                    }
                    else
                    {
                        purglk7 = true;
                        purgpk7 = true;
                    }
                }
                else
                {
                    if(purgpk3)
                    {
                        if(pp400[1])
                        {
                            purglk7 = true;
                            purglk8 = true;
                        }
                        else
                        {
                            purglk7 = true;
                            purgpk7 = true;
                        }
                    }
                }
            }
        }
    }
    else
    {
        if(pp400[1])
        {
            if(s2_2420)
            {
                purglk7 = true;
                purgpk7 = true;
                purglk8 = true;
                pss400 = true;
            }
            else
            {
                if(purglk2)
                {
                    if(pp400[0])
                    {
                        purgpk7 = true;
                        purglk8 = true;
                    }
                    else
                    {
                        purglk7 = true;
                        purgpk7 = true;
                    }
                }
                else
                {
                    if(purgpk3)
                    {
                        if(pp400[1])
                        {
                            purglk7 = true;
                            purglk8 = true;
                        }
                        else
                        {
                            purglk7 = true;
                            purgpk7 = true;
                        }
                    }
                }
            }
        }
        else
        {
            if(purglk2)
            {
                purglk7 = true;
                purgpk7 = true;

                if(!purgpk3)
                {
                    purglk8 = true;
                    pss400 = true;
                }
            }
            else
            {
                if(purgpk3)
                {
                    purglk7 = true;
                    purgpk7 = true;
                    purglk8 = true;
                    pss400 = true;
                }
            }
        }
    }
}
