#include "powerdc_8.h"


void powerdc_int::powerdc_8()
{
    if(purg27lk5)
        bss_inst.BSS837X1d = true;
    else
        bss_inst.BSS837X1d = false;
    if(purg27pk5)
        bss_inst.BSS837X1p = true;
    else
        bss_inst.BSS837X1p = false;
    if(purg27pk3 || pss27)
        bss_inst.BSS926X3C = true;
    else
        bss_inst.BSS926X3C = false;
    if(purg27lk4)
        bss_inst.BSS926X1MM = true;
    else
        bss_inst.BSS926X1MM = false;
    if(purg27pk4)
        bss_inst.BSS926X3J = true;
    else
        bss_inst.BSS926X3J = false;
    if(pvkchrl)
        bss_inst.BSS926X3A = true;
    else
        bss_inst.BSS926X3A = false;
    if(pvkchrp)
        bss_inst.BSS926X3L = true;
    else
        bss_inst.BSS926X3L = false;

    bss_inst.BSS926X1x = false;
    bss_inst.BSS926X1z = false;
    bss_inst.BSS837X1b=  false;

    if(pvkg1)
    {
        if(prg1)
        {
            if(otk_pereg_gen1)
            {
                bss_inst.BSS837X1b = true;
                bss_inst.BSS926X1x = true;
            }
        }
        else
        {
            bss_inst.BSS926X1x = true;
        }
    }
    else
    {
        if(exchange::ushal >= 18.0)
        {
            bss_inst.BSS926X1z = true;
        }
    }
    bss_inst.BSS837X1f = false;
    bss_inst.BSS926X1BB = false;
    bss_inst.BSS926X1DD = false;

    if(pvkg2)
    {
        if(prg2)
        {
            if(otk_pereg_gen2)
            {
                bss_inst.BSS837X1f = true;
                bss_inst.BSS926X1BB = true;
            }
        }
        else
        {
            bss_inst.BSS926X1BB = true;
        }
    }
    else
    {
        if(exchange::ushal >= 18.0)
        {
            bss_inst.BSS926X1DD = true;
        }
    }
    bss_inst.BSS837X1r = false;
    bss_inst.BSS837X1t = false;
    bss_inst.BSS837X1v = false;
    bss_inst.BSS837X1h = false;
    bss_inst.BSS837X1j = false;
    bss_inst.BSS837X1n = false;

    if(pvkg3)
    {
        if(prg3)
        {
            if(otk_pereg_gen3)
            {
                bss_inst.BSS837X1r = true;
                bss_inst.BSS837X1t = true;
            }
        }
        else
        {
            bss_inst.BSS837X1t = true;
        }
    }
    else
    {
        if(exchange::ushap >= 18.0)
        {
            bss_inst.BSS837X1v = true;
        }
    }

    if(pvkg4)
    {
        if(prg4)
        {
            if(otk_pereg_gen4)
            {
                bss_inst.BSS837X1h = true;
                bss_inst.BSS837X1j = true;
            }
        }
        else
        {
            bss_inst.BSS837X1j = true;
        }
    }
    else
    {
        if(exchange::ushap >= 18.0)
        {
            bss_inst.BSS837X1n = true;
        }
    }

    bss_inst.BSS926X1FF = false;
    bss_inst.BSS926X1HH = false;
    bss_inst.BSS837X1x = false;
    bss_inst.BSS837X1z = false;
    uks_inst.UKS2X355 = false;
    uks_inst.UKS4X352 = false;

    if(uak1 >= 18.0)
    {
        if(exchange::s14_2430)
        {
            if(purg27lk4)
            {
                bss_inst.BSS926X1HH = false;
            }
            else
            {
                bss_inst.BSS926X1HH = true;
                uks_inst.UKS2X355 = true;
            }

            if(otk_pereg_akk1)
            {
                bss_inst.BSS926X1FF = true;
            }
            else
            {
                bss_inst.BSS926X1FF = false;
            }
        }
        else
        {
            bss_inst.BSS926X1FF = false;
        }
    }

    if(uak2 >= 18.0)
    {
        if(exchange::s15_2430)
        {
            if(purg27pk4)
            {
                bss_inst.BSS837X1z = false;
            }
            else
            {
                bss_inst.BSS837X1z = true;
                uks_inst.UKS4X352 = true;
            }

            if(otk_pereg_akk2)
            {
                bss_inst.BSS837X1x = true;
            }
            else
            {
                bss_inst.BSS837X1x = false;
            }
        }
        else
        {
            bss_inst.BSS837X1x = false;
        }
    }

    if(ppgvsu27)
        bss_inst.BSS926X3E = true;
    else
        bss_inst.BSS926X3E = false;
}
