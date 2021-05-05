#include "pneumatic_1.h"


void pneumatic_int::pneumatic_1()
{
    static QDeadlineTimer tsl1(5000);
    static QDeadlineTimer tsl2(5000);
    if(PNU_pneum)
    {
        Pzm = 150.0;
        Vzm = 3000.0;
        Pslt = 150.0;
        Vslt = 3000.0;
        Pnpb = 150.0;
        Vnpb = 50000.0;
        Pnzb = 150.0;
        Vnzb = 25000.0;
        DVslt1 = 0.0;
        DVslt2 = 0.0;
        pzsnpb = false;
        pzsnzb = false;
    }

    uks_inst.UKS3X34 = false;
    uks_inst.UKS3X35 = false;

    bss_inst.BSS811X1DD = false;
    bss_inst.BSS824X1J = false;

    k91_10010 = false;
    k98_10010 = false;
    psdzh_duo = false;
    psdz_duo = false;

    if(exchange::ush1dpp >= 18.0)
    {
        psdzh_duo = true;

        if(du_o)
        {
            psdz_duo = true;
            psdzh_duo = false;
            DVzm = Vzm * Kger;
            Kger = 0.0;
            Pzm = ((Pzm * Vzm) / (Vzm + DVzm));
        }
        else
        {
            Kger = 0.002;
            k98_10010 = true;
        }
    }
    else
    {
        DVzm = Vzm * Kger;
        Kger = 0.0;
        Pzm = ((Pzm * Vzm) / (Vzm + DVzm));

    }

    if(Pzm < 1.6 && (exchange::ush1dpp >= 18.0))
    {
        uks_inst.UKS3X35 = true;
        bss_inst.BSS811X1DD = true;
        bss_inst.BSS824X1J = true;

    }

    if(k98_10010)
        uks_inst.UKS3X34 = true;

    bss_inst.BSS824X1D = false;
    bss_inst.BSS811X1h = false;
    bss_inst.BSS811X1j = false;

    if(Pslt <= Pzm)
    {
        Pslt = Pzm;
    }

    static bool firstTimeY1{true};
    if(exchange::ush1l >= 18.0 && s1_2830)
    {
        DVslt1 = Vslt * Kslt1;
        Kslt1 = 0.0;
        Pslt = ((Pslt * Vslt) / (Vslt + DVslt1));
        if(firstTimeY1)
        {
            tsl1.setRemainingTime(30000);
            firstTimeY1 = false;
        }
        if(tsl1.hasExpired())
        {
            y1_2830 = true;
        }
    }
    else
    {
        Kslt1 = 0.0005;
        y1_2830 = false;
        firstTimeY1 = true;
    }

    static bool firstTimeY2{true};
    if(exchange::ush1p >= 18.0 && s2_2830)
    {
        DVslt2 = Vslt * Kslt2;
        Kslt2 = 0.0;
        Pslt = ((Pslt * Vslt) / (Vslt + DVslt2));
        if(firstTimeY2)
        {
            tsl2.setRemainingTime(30000);
            firstTimeY2 = false;
        }
        if(tsl2.hasExpired())
        {
            y4_2830 = true;
        }
    }
    else
    {
        Kslt2 = 0.0005;
        y4_2830 = false;
        firstTimeY2 = true;
    }

    if(Pslt <= Pzm)
    {
        Pzm = ((Pzm * Vzm) / (Vzm + DVslt1 + DVslt2));
    }

    if(exchange::ush2dpp >= 18.0 && (Pslt < 80.0))
        bss_inst.BSS824X1D = true;

    if(y1_2830 && Pslt < 25.0)
        bss_inst.BSS811X1h = true;

    if(y4_2830 && Pslt < 25.0)
        bss_inst.BSS811X1j = true;

    bss_inst.BSS837X1X = false;
    bss_inst.BSS837X1Z = false;
    uks_inst.UKS3X17 = false;
    uks_inst.UKS3X18 = false;

    if(exchange::ush1l >= 18.0 && s1_3650)
    {
        y1_3650 = true;
        pzsnpb = true;
    }
    else
        y1_3650 = false;

    if(pzsnpb)
        Pnpb = Pnpb - ((0.1 /3600) * (TICK / 1000));

    if(exchange::ush1l >= 18.0 && k26_3230 && Pnpb < 130.0)
    {
        bss_inst.BSS837X1X = true;
        uks_inst.UKS3X17 = true;
    }

    if(exchange::ush1l >= 18.0 && s2_3650)
    {
        y2_3650 = true;
        pzsnzb = true;
    }
    else
        y2_3650 = false;

    if(pzsnzb)
        Pnzb = Pnzb - ((0.1/3600) * (TICK / 1000));

    if(exchange::ush1l >= 18.0 && k26_3230 && bss_inst.BSS837X1Z)
        uks_inst.UKS3X18 = true;

    if(Pzm < 0.0) Pzm = 0.0;
    if(Pnpb < 0.0) Pnpb = 0.0;
    if(Pnzb < 0.0) Pnzb = 0.0;


}
