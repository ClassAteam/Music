#include "antifire_1.h"

void antifire_int::antifire_1()
{
    if(S9_2610)
    {
        // Voltage check
        if((exchange::ush1dpl >= 16.0) && F8_2610)
            F82_2610 = true;
        else
            F82_2610 = false;

        if(exchange::ush1dpp >= 16.0 && F7_2610)
            F72_2610 = true;
        else
            F72_2610 = false;
    }
    else
    {
        F72_2610 = false;
        F82_2610 = false;
    }

    if(F82_2610 || F72_2610)					//009
    {
        if(exchange::ushal >= 16.0)
        {
            F132_2610 = true;
            F142_2610 = true;
        }
        else
        {
            F132_2610 = false;
            F142_2610 = false;
        }
    }
    else
    {
        F132_2610 = false;
        F142_2610 = false;
    }

    // Motogandol's rele flag 1nd engine
    if((K50_2610 && F82_2610 ) || (K51_2610 && F72_2610 ))
        K16_2610 = true;
    else
        K16_2610 = false;

    // Motogandol's rele flag 2nd engine
    if((K53_2610 && F82_2610) || (K54_2610 && F72_2610))
        K20_2610 = true;
    else
        K20_2610 = false;

    // Motogandol's rele flag 3nd engine
    if((K57_2610 && F82_2610) || (K58_2610 && F72_2610))
        K26_2610 = true;
    else
        K26_2610 = false;


    // Motogandol's rele flag 4nd engine
    if((K60_2610 && F82_2610) || (K61_2610 && F72_2610 ))
        K28_2610 = true;
    else
        K28_2610 = false;

    // motogandol's manual switching 1
    if (F72_2610)
    {
        if(!S3_2610 && !K15_2610)
            K15_2610 = false;
        else
            K15_2610 = true;
    }
    else
        K15_2610 = false;

    // motogandol's manual switching 2
    if (F72_2610)
    {
        if (!S4_2610 && !K19_2610)
            K19_2610 = false;
        else
            K19_2610 = true;

    }
    else
        K19_2610 = false;

    // motogandol's manual switching 3
    if(F82_2610)
    {
        if (!S7_2610 && K25_2610)
            K25_2610 = false;
        else
            K25_2610 = true;

    }
    else
        K25_2610 = false;

    // motogandol's manual switching 4
    if (F82_2610)
    {
        if (!S8_2610 && !K27_2610)
            K27_2610 = false;
        else
            K27_2610 = true;
    }
    else
        K27_2610 = false;


    // Check a manual switch of VSU's motogandol
    if(F72_2610)
    {
        if(S5_2610 || S6_2610 || K23_2610)
            K23_2610 = true;
    }
    else
        K23_2610 = false;

    // remaining voltage check
    //F2-5 contact
    if(F132_2610)
    {
        if (K16_2610 || K15_2610)
        {
            F25_2610 = true;
        }
        else
        {

            if(F142_2610)
            {
                if(K15_2610)
                    F25_2610 = true;
                else
                    F25_2610 = false;
            }
            else
                F25_2610 = false;
        }
    }
    //F3-5 contact
    if(F132_2610)
    {
        if(K20_2610 || K19_2610)
            F35_2610 = true;
        else
        {
            if(F142_2610)
            {
                if (K19_2610)
                    F35_2610 = true;
                else
                    F35_2610 = false;
            }
        }

    }
    else
    {
        if(F142_2610)
        {
            if(K19_2610)
                F35_2610 = true;
            else
                F35_2610 = false;
        }
        else
            F35_2610 = false;
    }

    //F4-5 contact
    if(F132_2610)
    {
        if(K24_2610 || K23_2610)
            F45_2610 = true;

    }
    else
    {
        if(F142_2610)
        {

            if(K23_2610)
                F45_2610 = true;
            else
                F45_2610 = false;
        }
        else
            F45_2610 = false;
    }

    //F5-5 contact
    if(F142_2610)
    {
        if (K26_2610 || K25_2610)
            F55_2610 = true;
        else
        {
            if(F132_2610)
            {
                if(K25_2610)
                    F55_2610 = true;
                else
                    F55_2610 = false;
            }
            else
                F55_2610 = false;
        }
    }
    else
    {
        if(F132_2610)
        {
            if(K25_2610)
                F55_2610 = true;
            else
                F55_2610 = false;
        }
        else
            F55_2610 = false;
    }

    //F6-5 contact
    if(F142_2610)
    {
        if (K28_2610 || K27_2610)
            F65_2610 = true;
        else
        {
            if(F132_2610)
            {
                if(K27_2610)
                    F65_2610 = true;
                else
                    F65_2610 = false;
            }
            else
                F65_2610 = false;
        }
    }
    else
    {
        if(F132_2610)
        {
            if(K27_2610)
                F65_2610 = true;
            else
                F65_2610 = false;
        }
        else
            F65_2610 = false;
    }
}
