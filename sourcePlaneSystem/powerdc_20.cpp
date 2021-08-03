#include "powerdc_20.h"


void Y_f(bool &f92, bool &psgp1, bool &pvksku, bool &BSS838X5G, bool &BSS838X5E,
         bool &BSS838X5C, double &ushal, bool &otkaz, bool &BSS837X1BB,
         bool &pvkgen, bool &BSS838X5A, bool &prgen);
void Z_f(bool &prg1, bool &prg2, bool &pchrl, bool &BSS926XN, bool &k31_2420,
         bool &BSS837X1N, bool &K13, bool &BSS837X1J);
void X_f(bool &prgen1, bool &uks2x343, bool &popg1, bool &uks2x348);

void powerdc_int::powerdc_20()
{

    Y_f(f92_2420, psgp1, pvksku[0], bss_inst.BSS838X5G, bss_inst.BSS838X5E,
        bss_inst.BSS838X5C, exchange::ushal, overload_gen1, bss_inst.BSS837X1BB,
        pvkgen[0], bss_inst.otklyuchiGen1, prgen[0]);

    Y_f(f142_2420, psgp2, pvksku[1], bss_inst.BSS838X5R, bss_inst.BSS838X5N,
        bss_inst.BSS838X5L, exchange::ushal, overload_gen2, bss_inst.BSS837X1DD,
        pvkgen[1], bss_inst.otklyuchiGen2, prgen[1]);

    Y_f(f242_2420, psgp3, pvksku[2], bss_inst.ppo3Otkl, bss_inst.BSS837X3N,
        bss_inst.BSS837X3L, exchange::ushap, overload_gen3, bss_inst.BSS837X3G,
        pvkgen[2], bss_inst.otklyuchiGen3, prgen[2]);

    Y_f(f282_2420, psgp4, pvksku[3], bss_inst.BSS837X3E, bss_inst.BSS837X3C,
        bss_inst.BSS837X3A, exchange::ushap, overload_gen4, bss_inst.BSS837X1KK,
        pvkgen[3], bss_inst.otklyuchiGen4, prgen[3]);

 Z_f(prgen[0], prgen[1], pchrl, bss_inst.BSS926X3N, k31_2420, bss_inst.BSS837X1N, k13_2420, bss_inst.BSS837X1J);

 Z_f(prgen[2], prgen[3], pchrp, bss_inst.BSS837X1HH, k34_2420, bss_inst.BSS837X1V, k16_2420, bss_inst.BSS837X1R);

 X_f(prgen[0], uks_inst.UKS2X343, popg1, uks_inst.UKS2X348);
 X_f(prgen[1], uks_inst.UKS2X344, popg2, uks_inst.UKS2X349);
 X_f(prgen[2], uks_inst.UKS4X343, popg3, uks_inst.UKS4X347);
 X_f(prgen[3], uks_inst.UKS4X344, popg4, uks_inst.UKS4X348);

 bss_inst.BSS837X1L = (k14_2420) ? true : false;
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
        else
        {
            BSS926XN = false;
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
void Y_f(bool &f92, bool &psgp1, bool &pvksku, bool &BSS838X5G, bool &BSS838X5E, bool &BSS838X5C,
         double &ushal, bool &otkaz, bool &BSS837X1BB, bool &pvkgen,
         bool &BSS838X5A, bool &prgen)
{
    if(pvksku) psgp1 = true;
    else psgp1 = false;

    if(f92 && psgp1)
    {
        BSS838X5G = true;
    }
    else
    {
        BSS838X5G = false;
    }

    if(ushal >= 18.0)
    {
        if(prgen)
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
            if(!pvkgen)
                BSS838X5A = false;
            else
                BSS838X5A = true;
        }
        else
        {
            BSS838X5A = false;
        }
    }
    else
        BSS838X5A = false;

    if(prgen)
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
void X_f(bool &prgen1, bool &uks2x343, bool &popg1, bool &uks2x348)
{
    if(prgen1) uks2x343 = true;
    else uks2x343 = false;

    if(popg1) uks2x348 = true;
    else uks2x348 = false;
}
