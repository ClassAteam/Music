#include "aircondition_1_2_3.h"
#include "landinggear_int.h"

extern landinggear_int landinggea;

void X(bool& prid_dv, double& Kotbx, double& Potb_zad, double& Potbx, double& eng, double& Kotk);

void aircondition_int::aircondition_1_2_3()
{
    if(Potb1 >= Potb2) Potb1_2 = Potb1;
    else Potb1_2 = Potb2;

    if(Potb3 >= Potb4) Potb3_4 = Potb3;
    else Potb3_4 = Potb4;

    if(exchange::speed >= 0.01 || landinggea.leftRack.isIntaken())
    {
        Puvzl = 0.0;
        Puvzp = 0.0;
    }
    else
    {
        if(exchange::puvzl) Puvzl = 5.0;
        else Puvzl = 0.0;

        if(exchange::puvzp) Puvzp = 5.0;
        else Puvzp = 0.0;
    }

    if(exchange::prvsu) Potb_vsu = 5.0;
    else Potb_vsu = 0.0;

    if(exchange::ushap >= 18.0)
    {
        if(exchange::s7_pp73)
        {
            alpha_zot_vsu = alpha_zot_vsu + 0.5 * ts;

            if(alpha_zot_vsu >= 1.0) alpha_zot_vsu = 1.0;

            Ptnu = Potb_vsu;
        }
        else
        {
            alpha_zot_vsu = alpha_zot_vsu - 0.5 * ts;

            if(alpha_zot_vsu <= 0.0)
            {
                alpha_zot_vsu = 0.0;
                Potb_vsu = (Potb_vsu * alpha_zot_vsu);
                Ptnu = Potb_vsu;
            }
        }
    }
    Potb_vsu = (Potb_vsu * alpha_zot_vsu);

    if(Potb1_2 < Puvzl) Potb1_2 = Puvzl;
    if(Potb3_4 < Puvzp) Potb3_4 = Puvzp;

    if(pzkol)
    {
        if(Potb1_2 >= Potb_vsu) Ptnu = Potb1_2;
        else
        {
            Ptnu = Potb_vsu;
            Potb1_2 = Potb_vsu;
        }
    }

    if(pzkop)
    {
        if(Potb3_4 >= Potb_vsu) Ptnu = Potb3_4;
        else
        {
            Ptnu = Potb_vsu;
            Potb3_4 = Potb_vsu;
        }
    }

    if(pzkol)
    {
        if(Potb1_2 >= Potb3_4)
        {
            Ptnu = Potb1_2;
            Potb3_4 = Potb1_2;
        }
        else
        {
            Ptnu = Potb3_4;
            Potb1_2 = Potb3_4;
        }
    }

    ////////////////////////////////////////////////
    /////////////////////////////////////////////2nd list

    Potb1_zad = 5.0;
    Potb2_zad = 5.0;
    Potb3_zad = 5.0;
    Potb4_zad = 5.0;
    Kotk1 = 0.0;
    Kotk2 = 0.0;
    Kotk3 = 0.0;
    Kotk4 = 0.0;

    if(otkaz_lev_mag)
    {
        Potb1_zad = 8.6;
        Potb2_zad = 8.6;
        Kotk1 = 1.0;
        Kotk2 = 1.0;
    }
    else
    {
        if(otkaz_prav_mag)
        {
            Potb3_zad = 8.6;
            Potb4_zad = 8.6;
            Kotk3 = 1.0;
            Kotk4 = 1.0;
        }
        else
        {
            if(otkaz_RID_1dv)
            {
                Potb1_zad = 7.6;
                Kotk1 = 1.0;
            }
            if(otkaz_RID_2dv)
            {
                Potb2_zad = 7.6;
                Kotk2 = 1.0;
            }
            if(otkaz_RID_3dv)
            {
                Potb3_zad = 7.6;
                Kotk3 = 1.0;
            }
            if(otkaz_RID_4dv)
            {
                Potb4_zad = 7.6;
                Kotk4 = 1.0;
            }
        }
    }
    k21_2110 = false;
    k22_2110 = false;

    bss_inst.BSS838X5x = false;
    bss_inst.BSS838X5BB = false;

    if(exchange::ush1dpl >= 18.0)
    {
        if(exchange::s1_2110)
        {
            k21_2110 = true;
            bss_inst.BSS838X5x = true;
        }
        if(exchange::s2_2110)
        {
            k22_2110 = true;
            bss_inst.BSS838X5BB = true;
        }
    }

    prid_dv1 = true;
    prid_dv2 = true;

    if(exchange::ushal >= 18.0)
    {
        bss_inst.BSS838X5v = false;

        if(k21_2110)
        {
            prid_dv1 = false;
            pbrid1 = false;
            Potb1_zad = 0.0;
        }
        else
        {
            if(exchange::ush1dpl >= 18.0)
            {
                if(Potb1 >= 7.5 || pbrid1)
                {
                    prid_dv1 = false;
                    pbrid1 = true;
                    bss_inst.BSS838X5v = true;
                }
            }
        }
        bss_inst.BSS838X5z = false;



        if(k22_2110)
        {
            prid_dv2 = false;
            pbrid2 = false;
            Potb2_zad = 0.0;
        }
        else
        {
            if(exchange::ush1dpl >= 18.0)
            {
                if(Potb2 >= 7.5 || pbrid2)
                {
                    prid_dv2 = false;
                    pbrid2 = true;
                    bss_inst.BSS838X5z = true;
                }
            }
        }
    }

    bss_inst.BSS838X7R = false;

    if(bss_inst.BSS838X5z && bss_inst.BSS838X5v)
        bss_inst.BSS838X7R = true;

    bss_inst.BSS838X5FF = false;
    bss_inst.BSS838X5KK = false;
    k25_2110 = false;
    k26_2110 = false;

    if(exchange::ush1dpp >= 18.0)
    {
        if(exchange::s3_2110)
        {
            k25_2110 = true;
            bss_inst.BSS838X5FF = true;
        }
        if(exchange::s4_2110)
        {
            k26_2110 = true;
            bss_inst.BSS838X5KK = true;
        }
    }
    prid_dv3 = true;
    prid_dv4 = true;

    if(exchange::ushap >= 18.0)
    {
        bss_inst.BSS838X5DD = false;

        if(!k25_2110)
        {
            if(exchange::ush1dpp >= 18.0)
            {
                if(Potb3 >= 7.5 || pbrid3)
                {
                    prid_dv3 = false;
                    pbrid3 = true;
                    bss_inst.BSS838X5DD = true;
                }
            }
        }
        else
        {
            prid_dv3 = false;
            pbrid3 = false;
            Potb3_zad = 0.0;
        }
        bss_inst.BSS838X5HH = false;

        if(!k26_2110)
        {
            if(exchange::ush1dpp >= 18.0)
            {
                if(Potb4 >= 7.5 || pbrid4)
                {
                    prid_dv4 = false;
                    pbrid4 = true;
                    bss_inst.BSS838X5HH = true;
                }
            }
        }
        else
        {
            prid_dv4 = false;
            pbrid4 = false;
            Potb4_zad = 0.0;
        }
        bss_inst.BSS838X7T = false;
    }

    if(bss_inst.BSS838X5DD)
    {
        if(bss_inst.BSS838X5HH) bss_inst.BSS838X7T = true;
    }

//    if(prid_dv1) Potb1 = 0.1 * exchange::eng1_spd;
//    else Potb1 = 0.0;
//    if(Potb1 >= 5.0) Potb1 = 5.0;

//    if(prid_dv2) Potb2 = 0.1 * exchange::eng2_spd;
//    else Potb2 = 0.0;
//    if(Potb2 >= 5.0) Potb2 = 5.0;

//    if(prid_dv3) Potb3 = 0.1 * exchange::eng3_spd;
//    else Potb3 = 0.0;
//    if(Potb3 >= 5.0) Potb3 = 5.0;

//    if(prid_dv4) Potb4 = 0.1 * exchange::eng4_spd;
//    else Potb4 = 0.0;
//    if(Potb4 >= 5.0) Potb4 = 5.0;

    X(prid_dv1, Kotb1, Potb1_zad, Potb1, exchange::eng1_spd, Kotk1);
    X(prid_dv2, Kotb2, Potb2_zad, Potb2, exchange::eng2_spd, Kotk2);
    X(prid_dv3, Kotb3, Potb3_zad, Potb3, exchange::eng3_spd, Kotk3);
    X(prid_dv4, Kotb4, Potb4_zad, Potb4, exchange::eng4_spd, Kotk4);


    ////////////////////////////////////////////////
    /////////////////////////////////////////////3rd list


    k16_2110 = false;
    k17_2110 = false;

    if(exchange::ushap >= 18.0)
    {
        if(brakes.X3_45_7620) k16_2110 = true;
        if(brakes.X4_45_7620) k17_2110 = true;
    }

    k8_2110 = false;
    k9_2110 = false;
    k10_2110 = false;
    pvklgvdv = false;

    if(exchange::ushal >= 18.0)
    {
        if(brakes.X1_45_7620) k8_2110 = true;
        if(brakes.X2_45_7620) k10_2110 = true;

        if(exchange::s7_7322 || exchange::s8_7322 ||
            exchange::s9_7322 || exchange::s10_7322)
        {
            pvklgvdv = true;
            if(exchange::K25_3230 == true) k9_2110 = true;

        }
    }

    k13_2110 = false;

    if(exchange::ushap >= 18.0 && pvklgvdv && exchange::K27_3230)
        k13_2110 = true;

    pvkltnu = false;
    k7_2110 = false;
    k15_2110 = false;

    if(exchange::ush2l >= 18.0)
    {
        if(hydro.Sthird4_2920[0] || hydro.Sthird4_2920[1] ||
            hydro.Sthird4_2920[2] || hydro.Sthird4_2920[3])
        {
            pvkltnu = true;

            if(k8_2110 || k10_2110) k7_2110 = true;

            if(k16_2110 || k17_2110) k15_2110 = true;
        }
    }

    k5_2110 = false;
    k6_2110 = false;
    pzkol = false;
    bss_inst.BSS926X1X = false;

    if(exchange::ushal >= 18.0)
    {
        if(!k12_2110 && !k9_2110)
        {
            if(!k7_2110 && exchange::ush2l >= 18.0 && exchange::s5_2110)
            {
                k5_2110 = true;
                pzkol = true;
            }
        }
        else
        {
            k5_2110 = true;
            pzkol = true;
        }

        if(pzkol)
        {
            alphazkol = alphazkol + 0.25 * ts;
            if(alphazkol >= 0.95)
            {
                alphazkol = 1.0;
                bss_inst.BSS926X1X = true;
                k6_2110 = true;
            }
        }
        else
        {
            if(alphazkol > 0.05) alphazkol = alphazkol - 0.25 * ts;
            else alphazkol = 0.0;
        }
    }

    k19_2110 = false;
    k20_2110 = false;
    pzkop = false;
    bss_inst.BSS926X1Z = false;

    if(exchange::ushap >= 18.0)
    {
        if(!k18_2110 && !k13_2110)
        {
            if(!k15_2110 && exchange::ush2l >= 18.0 && exchange::s5_2110)
            {
                k20_2110 = true;
                pzkop = true;
            }
        }
        else
        {
            k20_2110 = true;
            pzkop = true;
        }

        if(pzkop)
        {
            alphazkop = alphazkop + 0.25 * ts;
            if(alphazkop >= 0.95)
            {
                alphazkop = 1.0;
                bss_inst.BSS926X1Z = true;
                k19_2110 = true;
            }
        }
        else
        {
            if(alphazkop > 0.05) alphazkop = alphazkop - 0.25 * ts;
            else alphazkop = 0.0;
        }
    }

    if(exchange::ush2l >= 18.0 && k6_2110 && k19_2110)
        bss_inst.BSS926X1b = true;
    else
        bss_inst.BSS926X1b = false;
}

void X(bool& prid_dv, double& Kotbx, double& Potb_zad, double& Potbx, double& eng, double& Kotk)
{
    if(prid_dv)
    {
        Kotbx = (Kotbx + 1 * ts) * Kotk;
        if(Potbx >= Potb_zad) Potbx = 0.1 * eng;
        else Potbx = 0.1 * eng + Kotbx;
        if(!Kotk && Potbx > 5.0) Potbx = 5.0;
    }
    else
    {
        Potbx = Potbx - 3.0 * ts;
        Kotbx = 0.0;
    }

    if(Potbx < 0.0) Potbx = 0.0;
}
