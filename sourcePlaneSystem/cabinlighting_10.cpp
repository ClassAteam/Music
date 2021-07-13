#include "cabinlighting_10.h"

void cabinlighting_int::cabinlighting_10()
{
    pvpmfpu[1] = false;
    pvpmfpu[2] = false;

    pvvomfpu[1] = false;
    pvvomfpu[2] = false;

    pvpmfi[5] = false;
    pvpmfi[6] = false;
    pvpmfi[7] = false;
    pvpmfi[8] = false;
    pvpmfi[9] = false;
    pvpmfi[10] = false;

    pvvomfi[5] = false;
    pvvomfi[6] = false;
    pvvomfi[7] = false;
    pvvomfi[8] = false;
    pvvomfi[9] = false;
    pvvomfi[10] = false;

    if(s_11710[6])
    {
        if(exchange::ush2dpl >= 18.0)
        {
            pvpmfi[7] = true;
            if(pk31pdshnvo || pk32pdshnvo) pvvomfi[7] = true;
        }

        if(exchange::ush2l >= 18.0)
        {
            pvpmfi[5] = true;
            pvpmfi[8] = true;

            if(pk31pdshnvo || pk32pdshnvo) pvvomfi[5] = true;
            if(pk31pdshovo || pk32pdshovo) pvvomfi[8] = true;
        }
        if(exchange::ush1l >= 18.0)
        {
            pvpmfi[6] = true;
            pvpmfi[0] = true;
            pvpmfi[10] = true;
            if(pk31pdshovo || pk32pdshovo)
            {
                pvvomfi[9] = true;
                pvvomfi[10] = true;
            }

            if(pk31pdshnvo || pk32pdshnvo) pvvomfi[6] = true;
        }
    }

    if(s_11710[7])
    {
        if(exchange::ush2dpp >= 18.0)
        {
            pvpmfi[7] = true;
            if(pk31pdshnvo || pk32pdshnvo) pvvomfi[7] = true;
        }

        if(exchange::ush2p >= 18.0)
        {
            pvpmfi[5] = true;
            pvpmfi[8] = true;

            if(pk31pdshnvo || pk32pdshnvo) pvvomfi[5] = true;
            if(pk31pdshovo || pk32pdshovo) pvvomfi[8] = true;
        }
        if(exchange::ush1p >= 18.0)
        {
            pvpmfi[6] = true;
            pvpmfi[0] = true;
            pvpmfi[10] = true;
            if(pk31pdshovo || pk32pdshovo)
            {
                pvvomfi[9] = true;
                pvvomfi[10] = true;
            }

            if(pk31pdshnvo || pk32pdshnvo) pvvomfi[6] = true;
        }
    }

    if(s_11710[10])
    {
        if(exchange::ush2dpl >= 18.0) pvpmfpu[1] = true;

        if(pk31pdshovo || pk32pdshovo) pvvomfpu[1] = true;
    }

    if(s_11710[13])
    {
        if(exchange::ush2dpp >= 18.0) pvpmfpu[1] = true;

        if(pk31pdshovo || pk32pdshovo) pvvomfpu[1] = true;
    }

    if(s_11710[11])
    {
        if(exchange::ush1p >= 18.0) pvpmfpu[2] = true;

        if(pk31pdshovo || pk32pdshovo) pvvomfpu[2] = true;
    }

    if(s_11710[12])
    {
        if(exchange::ush2dpl >= 18.0) pvpmfpu[2] = true;

        if(pk31pdshovo || pk32pdshovo) pvvomfpu[2] = true;
    }

    if(bgs2)
    {
        if(exchange::ush2l >= 18.0)
        {
            pvpbgs112 = true;
            pvpbgs212 = true;
        }
        if(exchange::ush2p >= 18.0)
        {
            pvpbgs122 = true;
            pvpbgs222 = true;
        }
    }

    if(pk31pdshovo || pk32pdshovo) pvvopdsho = true;
    if(pk41pdshovo || pk42pdshovo) pvvopdshoav = true;
    if(pk31pdshnvo || pk32pdshnvo) pvvopdshn = true;
    if(pk41pdshnvo || pk42pdshnvo) pvvopdshnav = true;
    if(pk41lbshvo || pk42lbshvo) pvvolbshav = true;
    if(pk31pbshvo || pk32pbshvo) pvvopbsh = true;
    if(pk41pbshvo || pk42pbshvo) pvvopbshav = true;
}
