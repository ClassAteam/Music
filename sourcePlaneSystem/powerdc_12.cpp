#include "powerdc_12.h"

void powerdc_int::powerdc_12()
{
    static bool
        k1_2430{};
    static int
        tickG[5]{0};
    double* ug_pool[] = {&ug1, &ug2, &ug3, &ug4, &ugvsu};
    double* ushal_pool[] = {&exchange::ushal, &exchange::ushal,
                            &exchange::ushap, &exchange::ushap};
    bool* s1_pool[] = { &exchange::s1_2420, &exchange::s5_2420, &exchange::s10_2420, &exchange::s13_2420};
    bool* otk_pool[] = {&otkGenPerT1, &otkGenPerT2, &otkGenPerT3, &otkGenPerT4};


    for(int y = 0; y < 5; y++)
    {
        if(pzvg[y])
        {
            tickG[y] = 0;
            prgen[y] = false;
        }
        else
        {
            if(fg[y] <= 407.0 && fg[y] >= 370.0)
            {
                if(*ug_pool[y] >= 104.0 && *ug_pool[y] <= 129.0)
                {
                    tickG[y] = 0;
                    if(pvkgen[y])
                        prgen[y] = true;
                    else
                        prgen[y] = false;
                }
                else
                {
                    if(tickG[y] * TICK >= 6500)
                    {
                        pzvg[y] = true;
                        prgen[y] = false;
                    }
                    else
                    {
                        tickG[y]++;
                        if(pvkgen[y])
                            prgen[y] = true;
                        else
                            prgen[y] = false;
                    }
                }
            }
            else
            {
                pzvg[y] = true;
                prgen[y] = false;
            }
        }
    }

    if(exchange::ushal >= 18.0)
    {
        if(exchange::s8_2420)
        {
            pvkgen[4] = true;
        }
        else
        {
            if(k1_2430)
                pvkgen[4] = true;
            else
            {
                pzvg[4] = false;
                pvkgen[4] = false;
            }
        }
    }
    else
    {
        pzvg[4] = false;
        pvkgen[4] = false;
    }

    for(int x = 0; x < 4; x++)
    {
        if(*ushal_pool[x] >= 18.0 && *s1_pool[x])
            pvkgen[x] = true;
        else
        {
            pvkgen[x] = false;
            pzvg[x] = false;
        }

        if(*ushal_pool[x] >= 18.0)
        {
            if(prgen[x] && (!(*otk_pool[x])))
                pog[x] = false;
            else
                pog[x] = true;
        }
        else
        {
            pog[x] = true;
        }
    }
    if(prgen[0])
        purgk1 = true;
    else
        purgk1 = false;

    if(prgen[1])
        purgk21 = true;
    else
        purgk21 = false;
    if(prgen[2])
        purgk31 = true;
    else
        purgk31 = false;

    if(prgen[3])
        purgk41 = true;
    else
        purgk41 = false;

    pchrl = false;
    pchrp = false;
    purglk4 = false;
    purglk5 = false;
    purgpk4 = false;
    purgpk5 = false;

    if(exchange::s4_2420)
    {
        purgk1 = false;
        purgk21 = false;

        if(prgen[1])
        {
            purglk5 = false;
            purglk4 = true;
            pchrl = true;
        }
        else
        {
            if(prgen[0])
            {
                purglk5 = true;
                purglk4 = true;
                pchrl = true;
            }
        }
    }

    if(exchange::s12_2420)
    {
        purgk31 = false;
        purgk41 = false;

        if(prgen[2])
        {
            purgpk5 = false;
            purgpk4 = true;
            pchrp = true;
        }
        else
        {
            if(prgen[3])
            {
                purgpk5 = true;
                purgpk4 = true;
                pchrp = true;
            }
        }
    }

    if(purgk1 && !purgk21)
        purglk6 = true;
    else
        purglk6 = false;

    if(!purgk31 && purgk41)
        purgpk6 = true;
    else
        purgpk6 = false;
}
