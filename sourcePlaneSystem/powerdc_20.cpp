#include "powerdc_20.h"


void Y_f(bool &f92, bool &pvksku, bool &BSS838X5G, bool &BSS838X5C,
         double &ushal, bool &otkaz, bool &BSS837X1BB, bool &pvkg,
         bool &BSS838X5A, bool &prg);
void Z_f(bool &prg1, bool &prg2, bool &pchrl, bool &BSS926XN, bool &k31_2420,
         bool &BSS837X1N, bool &K13, bool &BSS837X1J);

void powerdc_int::powerdc_20()
{

    Y_f(f92_2420, pvksku[0], bss_inst.BSS838X5G, bss_inst.BSS838X5C, exchange::ushal,
    overload_gen1, bss_inst.BSS837X1BB, pvkg1, bss_inst.BSS838X5A, prgen[0]);

    Y_f(f142_2420, pvksku[1], bss_inst.BSS838X5R, bss_inst.BSS838X5L, exchange::ushal,
    overload_gen2, bss_inst.BSS837X1DD, pvkg2, bss_inst.BSS838X5L, prgen[1]);

    Y_f(f242_2420, pvksku[2], bss_inst.BSS837X3R, bss_inst.BSS837X3L, exchange::ushap,
    overload_gen3, bss_inst.BSS837X3G, pvkg3, bss_inst.BSS837X3J, prgen[2]);

    Y_f(f282_2420, pvksku[3], bss_inst.BSS837X3E, bss_inst.BSS837X3A, exchange::ushap,
    overload_gen4, bss_inst.BSS837X1KK, pvkg4, bss_inst.BSS837X1MM, prgen[3]);

 Z_f(prgen[0], prgen[1], pchrl, bss_inst.BSS926X3N, k31_2420, bss_inst.BSS837X1N, k13_2420, bss_inst.BSS837X1J);

 Z_f(prgen[2], prgen[3], pchrp, bss_inst.BSS837X1HH, k34_2420, bss_inst.BSS837X1V, k16_2420, bss_inst.BSS837X1R);

 if(k14_2420)
     bss_inst.BSS837X1L = true;
 else
     bss_inst.BSS837X1L = false;
}

void Z_f(bool &prg1, bool &prg2, bool &pchrl, bool &BSS926XN, bool &k31_2420,
         bool &BSS837X1N, bool &k13, bool &BSS837X1J)
{
    if(prg1)
    {
        if(pchrl)
        {
            BSS926XN = true;
        }
        else
        {
            BSS926XN = false;
        }
    }
    else
    {
        if(prg2)
        {
            if(pchrl)
            {
                BSS926XN = true;
            }
            else
            {
                BSS926XN = false;
            }
        }
    }

    if(k31_2420)
        BSS837X1N = true;
    else
        BSS837X1N = false;

    if(k13)
        BSS837X1J = true;
    else
        BSS837X1J = false;

}
void Y_f(bool &f92, bool &pvksku, bool &BSS838X5G, bool &BSS838X5C,
         double &ushal, bool &otkaz, bool &BSS837X1BB, bool &pvkg,
         bool &BSS838X5A, bool &prg)
{
    if(f92 && pvksku)
        BSS838X5G = true;
    else
        BSS838X5G = false;

    if(ushal >= 18.0)
    {
        if(prg)
            BSS838X5C = false;
        else
            BSS838X5C = true;
    }
    else
        BSS838X5C = false;

    if(ushal >= 18.0)
    {
        if(f92)
        {
            if(pvkg)
                BSS838X5A = false;
            else
                BSS838X5A = true;
        }
    }
    else
        BSS838X5A = false;

    if(prg)
    {
        if(otkaz)
        {
            BSS837X1BB = true;
        }
        else
        {
            BSS837X1BB = false;
        }
    }
    else
    {
        BSS837X1BB = false;
    }
}
