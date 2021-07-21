#include "aircondition_9.h"

void aircondition_int::aircondition_9()
{
    y6_2152 = false;
    y8_2152 = false;

    y7gk_2152 = false;
    y7hk_2152 = false;

    bss_inst.BSS926X1A = false;

    if(exchange::ushal >= 18.0)
    {
        if(exchange::s1_2152)
        {
            y6_2152 = true;

            if(alpha352y6 > 0.95)
            {
                alpha352y6 = 1.0;
                bss_inst.BSS926X1A = true;
            }
            else alpha352y6 = alpha352y6 + 0.2 * ts;

        }
        else
        {
            if(alpha352y6 > 0.05) alpha352y6 = alpha352y6 - 0.2 * ts;
            else alpha352y6 = 0.0;
        }
    }
}
