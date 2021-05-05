#include "aircondition_17.h"

void aircondition_int::aircondition_17()
{
    skv_d001 = false;
    skv_d002 = false;
    skv_d006 = false;
    skv_d008 = false;
    skv_d010 = false;

    if(exchange::ush1dpl >= 18.0)
    {

        if(k21_2110) skv_d001 = true;
        if(k22_2110) skv_d002 = true;
        if(alphazkol == 1.0) skv_d006 = true;
        if(alphazm1 == 0.0) skv_d008 = true;
        if(alphazktvt12 == 1.0) skv_d010 = true;
        if(alpha352y6 == 1.0) skv_d016 = false;
        else skv_d016 = true;

        if(prthu1) skv_d012 = false;
        else skv_d012 = true;
    }

    skv_d003 = false;
    skv_d004 = false;
    skv_d007 = false;
    skv_d009 = false;
    skv_d011 = false;

    if(exchange::ush1dpp >= 18.0)
    {

        if(k25_2110) skv_d003 = true;
        if(k26_2110) skv_d004 = true;
        if(alphazkop == 1.0) skv_d007 = true;
        if(alphazm2 == 0.0) skv_d009 = true;
        if(alphazkm12 == 1.0) skv_d011 = true;
    }

    if(exchange::ush2dpp >= 18.0)
    {
        if(prthu4) skv_d015 = false;
        else skv_d015 = true;

        if(alpha359y14 == 1.0) skv_d019 = true;
        else skv_d019 = false;
    }

    if(exchange::ush2dpl >= 18.0)
    {
        if(prthu3) skv_d014 = false;
        else skv_d014 = true;

        if(alpha357y1 == 0.0) skv_d017 = true;
        else skv_d017 = false;

        if(alpha357y2 == 0.0) skv_d018 = true;
        else skv_d018 = false;
    }

    if(prthu2) skv_d013 = false;
    else skv_d013 = true;

///////////////////////////////////////////////////aircondition_18
///

    if(exchange::ush1l >= 18.0)
    {
        if(alphazovsu == 1.0) skv_d020 = true;
        else skv_d020 = false;

        if(pom1) skv_d024 = true;
        else skv_d024 = false;

        if(pom2) skv_d025 = true;
        else skv_d025 = false;

        if(bss_inst.BSS838X7R) skv_d026 = true;
        else skv_d026 = false;

        if(bss_inst.BSS838X7T) skv_d027 = true;
        else skv_d027 = false;

        if(pothu1) skv_d028 = true;
        else skv_d028 = false;

        if(pothu2) skv_d029 = true;
        else skv_d029 = false;

        if(pothu3) skv_d030 = true;
        else skv_d030 = false;

        if(pothu4) skv_d031 = true;
        else skv_d031 = false;

        if(bss_inst.BSS838X5T) skv_d032 = true;
        else skv_d032 = false;

        if(bss_inst.BSS838X5n)
        {
            skv_d033 = true;
            skv_d035 = true;
        }
        else
        {
            skv_d033 = false;
            skv_d035 = false;
        }

        if(bss_inst.BSS838X5p)
        {
            skv_d037 = true;
        }

        skv_d034 = false;
        skv_d036 = false;
        skv_a001 = tke;
        skv_a002 = tpgo;
        skv_a003 = tzgo;
        skv_a004 = tzto;
    }
}
