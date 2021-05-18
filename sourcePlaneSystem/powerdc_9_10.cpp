#include "powerdc_9_10.h"


void powerdc_int::powerdc_9_10()
{
    if(bss_inst.BSS837X1b)
        uks_inst.UKS1X36 = true;
    else
        uks_inst.UKS1X36 = false;

    if(bss_inst.BSS837X1f)
        uks_inst.UKS1X37 = true;
    else
        uks_inst.UKS1X37 = false;

    if(bss_inst.BSS837X1r)
        uks_inst.UKS3X325 = true;
    else
        uks_inst.UKS3X325 = false;

    if(bss_inst.BSS837X1h)
        uks_inst.UKS3X326 = true;
    else
        uks_inst.UKS3X326 = false;

    if(bss_inst.BSS926X1x)
        uks_inst.UKS1X38 = true;
    else
        uks_inst.UKS1X38 = false;

    if(bss_inst.BSS926X1BB)
        uks_inst.UKS1X39 = true;
    else
        uks_inst.UKS1X39 = false;

    if(bss_inst.BSS837X1t)
        uks_inst.UKS3X327 = true;
    else
        uks_inst.UKS3X327 = false;

    if(bss_inst.BSS837X1j)
        uks_inst.UKS3X328 = true;
    else
        uks_inst.UKS3X328 = false;

    if(bss_inst.BSS926X1MM)
        uks_inst.UKS1X311 = true;
    else
        uks_inst.UKS1X311 = false;

    if(bss_inst.BSS926X3J)
        uks_inst.UKS3X329 = true;
    else
        uks_inst.UKS3X329 = false;

    if(bss_inst.BSS926X3C)
        uks_inst.UKS1X310 = true;
    else
        uks_inst.UKS1X310 = false;

    if(purg27lk7)
    {
        uks_inst.UKS1X343 = true;
        uks_inst.UKS1X344 = true;
    }
    else
    {
        uks_inst.UKS1X343 = false;
        uks_inst.UKS1X344 = false;
    }

    if(purg27pk7)
    {
        uks_inst.UKS3X343 = true;
        uks_inst.UKS3X344 = true;
    }
    else
    {
        uks_inst.UKS3X343 = false;
        uks_inst.UKS3X344 = false;
    }

    if(prg1)
        uks_inst.UKS2X353 = true;
    else
        uks_inst.UKS2X353 = false;

    if(prg2)
        uks_inst.UKS2X354 = true;
    else
        uks_inst.UKS2X354 = false;

    if(prg3)
        uks_inst.UKS4X351 = true;
    else
        uks_inst.UKS4X351 = false;

    if(prg4)
        uks_inst.UKS4X357 = true;
    else
        uks_inst.UKS4X357 = false;

    if(bss_inst.BSS926X3A)
        uks_inst.UKS2X314 = true;
    else
        uks_inst.UKS2X314 = false;

    if(bss_inst.BSS926X3L)
        uks_inst.UKS4X339 = true;
    else
        uks_inst.UKS4X339 = false;

    if(bss_inst.BSS837X1d)
        uks_inst.UKS2X313 = true;
    else
        uks_inst.UKS2X313 = false;

    if(bss_inst.BSS837X1p)
        uks_inst.UKS4X338 = true;
    else
        uks_inst.UKS4X338 = false;

//    if(uak1 >= 18.0 && s14_2430)
//    {
//        UKS2X355 = true;

//        if(otk_pereg_akk1)
//            UKS2X312 = true;
//        else
//            UKS2X312 = false;
//    }
//    else
//    {
//        UKS2X355 = false;
//        UKS2X312 = false;

//    }

//    if(uak2 >= 18.0 && s15_2430)
//    {
//        UKS4X352 = true;

//        if(otk_pereg_akk2)
//            UKS4X337 = true;
//        else
//            UKS4X337 = false;
//    }
//    else
//    {
//        UKS4X352 = false;
//        UKS4X337 = false;
//    }

    if(purg27pk3)
        uks_inst.UKS4X340 = true;
    else
        uks_inst.UKS4X340 = false;

    if(bss_inst.BSS926X1z)
        uks_inst.UKS2X310 = true;
    else
        uks_inst.UKS2X310 = false;

    if(bss_inst.BSS926X1DD)
        uks_inst.UKS2X311 = true;
    else
        uks_inst.UKS2X311 = false;

    if(bss_inst.BSS837X1v)
        uks_inst.UKS4X335 = true;
    else
        uks_inst.UKS4X335 = false;

    if(bss_inst.BSS837X1n)
        uks_inst.UKS4X336 = true;
    else
        uks_inst.UKS4X336 = false;

    if(bss_inst.BSS926X3E)
        uks_inst.UKS2X315 = true;
    else
        uks_inst.UKS2X315 = false;

    if(prgvsu27)

    uks_inst.UKS2X356 = true;
    else
        uks_inst.UKS2X356 = false;

    uks_inst.UKS1X2105_106 = ingvsu_27;
    uks_inst.UKS1X3106 = ingvsu_27;

    uks_inst.UKS1X394 = exchange::ush1l;
    uks_inst.UKS1X395 = exchange::ush2l;

    uks_inst.UKS3X394 = exchange::ush1p;
    uks_inst.UKS3X395 = exchange::ush2p;

    if(purg27lk5)
    {
        uks_inst.UKS2X2105 = iak1;
    }
    else
    {
        if(purg27lk4)
        {
            uks_inst.UKS2X2105 = irap1;
            uks_inst.UKS2X2106 = irap1;
        }
        else
        {
            uks_inst.UKS2X2105 = 0;
            uks_inst.UKS2X2106 = 0;
        }
    }

    if(purg27pk5)
    {
        uks_inst.UKS4X2105 = iak2;
        uks_inst.UKS4X2106 = iak2;
    }
    else
    {
        if(purg27pk4)
        {
            uks_inst.UKS2X2105 = irap2;
            uks_inst.UKS2X2106 = irap2;
        }
        else
        {
            uks_inst.UKS4X2105 = 0;
            uks_inst.UKS4X2106 = 0;
        }
    }

    if(OtkazGen1PostT) uks_inst.UKS2X359 = true;
    else uks_inst.UKS2X359 = false;

    if(OtkazGen2PostT) uks_inst.UKS2X360 = true;
    else uks_inst.UKS2X360 = false;

    if(OtkazGen3PostT) uks_inst.UKS2X355 = true;
    else uks_inst.UKS4X355 = false;

    if(OtkazGen4PostT) uks_inst.UKS2X356 = true;
    else uks_inst.UKS4X356 = false;


    uks_inst.UKS2X394 = uak1;
    uks_inst.UKS4X394 = uak2;
    uks_inst.UKS2X395 = exchange::ushal;
    uks_inst.UKS4X395 = exchange::ushap;
}
