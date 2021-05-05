#include "antiicing_5.h"


void antiicing_int::antiicing_5()
{
    //K1_3040 toggle
    K1_3040 = false;

    if(exchange::ush1l >= 18.0 && exchange::s2_3040)
    {
        if(exchange::PRD1dv && exchange::PRD4dv &&
            (landinggear_int::K5_3250 || landinggear_int::K6_3250))
            K1_3040 = true;

        if(!K26_3230)
            K1_3040 = true;

        if(K26_3230 && F11_3040)
            K1_3040 = true;
    }

    if (exchange::ushavP[2][0] >= 106.0 && K1_3040)
        POLST = true;
    else
        POLST = false;

    //K2_3040 toggle
    K2_3040 = false;

    if(usho1p >= 18.0 && exchange::s4_3040)
    {
        if (exchange::PRD2dv == true &&  exchange::PRD3dv &&
            (landinggear_int::K5_3250 || landinggear_int::K6_3250))
            K2_3040 = true;

        if(!K24_3230)
            K2_3040 = true;

        if(K24_3230 && F12_3040)
            K2_3040 = true;
    }

    if(exchange::ushgP[2][0] >= 106.0 && K2_3040)
        POLOBST = true;
    else
        POLOBST = false;

    //K3_3040 toggle
    K3_3040 = false;

    if(exchange::usho2p >= 18.0 && exchange::s6_3040)
    {
        if (exchange::PRD2dv &&  exchange::PRD3dv &&
            (landinggear_int::K5_3250 || landinggear_int::K6_3250))
            K3_3040 = true;

        if(!K24_3230)
            K3_3040 = true;

        if(K24_3230 && F13_3040)
            K3_3040 = true;
    }

    if (exchange::ushgP[3][0] >= 106.0 && K3_3040)
        POPST = true;
    else
        POPST = false;

    //F11_3040, F12_3040, F13_3040 toggle
    F11_3040 = false;
    F12_3040 = false;
    F13_3040 = false;

    if(usho1p >= 18.0 && exchange::s8_3040)
    {
        if(!exchange::PRD1dv && !exchange::PRD2dv && !exchange::PRD3dv && !exchange::PRD4dv)
        {
            switch(exchange::s7_3040)
            {
            case(static_cast<int>(exchange::s7_3040::lev)):
                F11_3040 = true;
            break;
            case(static_cast<int>(exchange::s7_3040::lob)):
                F12_3040 = true;
            break;
            case(static_cast<int>(exchange::s7_3040::prav)):
                F13_3040 = true;
            break;
            }
        }

        obogrev_stekol_ispr = false;
        // F11_3040, F12_3040, F13_3040 toggle with matching K'es
        // and switch positions
        //1
        if(exchange::s7_3040 == static_cast<int>(exchange::s7_3040::lev))
        {
            if(K1_3040) F11_3040 = true;
            obogrev_stekol_ispr = true;
        }
        //2
        if(exchange::s7_3040 == static_cast<int>(exchange::s7_3040::lob))
        {
            if(K2_3040) F12_3040 = true;
            obogrev_stekol_ispr = true;
        }
        //3
        if(exchange::s7_3040 == static_cast<int>(exchange::s7_3040::prav))
        {
            if(K3_3040) F13_3040 = true;
            obogrev_stekol_ispr = true;
        }
    }
    else
        obogrev_stekol_ispr = false;
}
