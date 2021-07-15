#include "cabinlighting_9.h"

void cabinlighting_int::cabinlighting_9()
{
    pvpmfi[0] = false;
    pvpmfi[1] = false;
    pvppui[0] = false;
    pvvomfi[0] = false;
    pvvomfi[1] = false;
    pvvopui[0] = false;

    if(s_11710[0])
    {
        if(exchange::ush1l >= 18.0 || exchange::ush1p >= 18.0)
        {
            pvpmfi[0] = true;

            if(pk11lspdvo  || pk12lspdvo) pvvomfi[0] = true;
        }

        if(exchange::ush2dpp >= 18.0 || exchange::ush1p >= 18.0)
        {
            pvppui[0] = true;

            if(pk21spvo  || pk22spvo) pvvopui[0] = true;
        }
    }

    if(s_11710[1])
    {
        if(exchange::ush2l >= 18.0 || exchange::ush2p >= 18.0)
        {
            pvpmfi[1] = true;

            if(pk21lspdvo  || pk22lspdvo) pvvomfi[1] = true;
        }

        if(exchange::ush2dpp >= 18.0)
        {
            pvppui[0] = true;

            if(pk21spvo  || pk22spvo) pvvopui[0] = true;
        }
    }

    pvpmfi[2] = false;
    pvpmfpu[0] = false;

    pvvomfi[2] = false;
    pvvomfpu[0] = false;

    if(s_11710[4])
    {
        if(exchange::ush2dpl >= 18.0)
        {
            pvpmfi[2] = true;
            if(pk21lspdvo || pk22lspdvo) pvvomfi[2] = true;
        }

        if(exchange::ush2l >= 18.0)
        {
            pvpmfpu[0] = true;
            if(pk21spvo || pk22spvo) pvvomfpu[0] = true;
        }
    }


    if(s_11710[5])
    {
        if(exchange::ush2dpp >= 18.0)
        {
            pvpmfi[2] = true;

            if(pk21lspdvo  || pk22lspdvo) pvvomfi[2] = true;
        }

        if(exchange::ush2p >= 18.0)
        {
            pvpmfpu[0] = true;

            if(pk21spvo  || pk22spvo) pvvomfpu[0] = true;
        }
    }

    pvpmfi[3] = false;
    pvpmfi[4] = false;
    pvppui[1] = false;
    pvvomfi[3] = false;
    pvvomfi[4] = false;
    pvvopui[1] = false;

    if(s_11710[2])
    {
        if(exchange::ush1l >= 18.0)
        {
            pvpmfi[3] = true;

            if(pk11ppdvo  || pk12ppdvo) pvvomfi[3] = true;
        }

        if(exchange::ush2p >= 18.0)
        {
            pvppui[1] = true;

            if(pk11pblvo  || pk22pblvo) pvvopui[1] = true;
        }
    }

    if(s_11710[3])
    {
        if(exchange::ush1l >= 18.0)
        {
            pvpmfi[4] = true;

            if(pk11ppdvo  || pk12ppdvo) pvvomfi[4] = true;
        }

        if(exchange::ush2l >= 18.0)
        {
            pvppui[1] = true;

            if(pk11pblvo  || pk22pblvo) pvvopui[1] = true;
        }
    }

    pvvolspd = false;
    pvvolspdav = false;
    pvvoppd = false;
    pvvoppdav = false;
    pvvolbl = false;
    pvvolblav = false;
    pvvopbl = false;
    pvvopblav = false;
    pvvosp = false;
    pvvospav = false;

    if(pk11lspdvo || pk12lspdvo) pvvolspd = true;
    if(pk21lspdvo || pk22lspdvo) pvvolspdav = true;
    if(pk11ppdvo || pk12ppdvo) pvvoppd = true;
    if(pk21ppdvo || pk22ppdvo) pvvoppdav = true;
    if(pk11spvo || pk12spvo) pvvosp = true;
    if(pk21spvo || pk22spvo) pvvospav = true;
    if(pk11lblvo || pk12lblvo) pvvolbl = true;
    if(pk21lblvo || pk22lblvo) pvvolblav = true;
    if(pk11pblvo || pk12pblvo) pvvopbl = true;
    if(pk21pblvo || pk22pblvo) pvvopblav = true;
}
