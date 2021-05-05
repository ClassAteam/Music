#include "aircondition_4_5.h"

void aircondition_int::aircondition_4_5()
{

    k1_2120 = false;

    if(exchange::ushal >= 18.0 && exchange::s4_2120)
    {
        k1_2120 = true;
    }

    pruukl = false;
    k3_2120 = false;
    k7_2120 = false;

    if(exchange::ush2dpl >= 18.0 && !exchange::s3_2120)
    {
        if(exchange::s1_2120)
        {
            pruukl = true;

            if(!k9_2110 && !k1_2110) k3_2120 = true;
        }
        else
        {
            pzpe1 = true;
            pzpvvt1 = false;
            k5_2120 = true;
            k6_2120 = true;
            k7_2120 = false;
        }
    }

    if(otkaz_povishTemprVozd) tvvt1 = 355.0;
    else tvvt1 = 70.0;

    if(otkaz_povishDavlVozMag1) Potb1_2 = 8.2;

    pom1 = false;

    if(pruukl)
    {
        if(tvvt1 >= 350.0 || Potb1_2 >= 8.0)
        {
            pom1 = true;
            k3_2120 = false;
        }

        if(exchange::PRD1dv) k5_2120 = true;
        else k5_2120 = false;
        if(exchange::PRD2dv) k6_2120 = true;
        else k6_2120 = false;

        if(!k5_2120)
        {
            if(!k6_2120)
            {
//                pom1 = true;
//                k3_2120 = false;
            }
            else
                k7_2120 = true;
        }
        else
            if(!k6_2120) k7_2120 = true;

        if(pom1)
        {
            if(!exchange::s3_2120) bss_inst.BSS926X1d = true;
            if(alphazm1 <= 0.0) bss_inst.BSS926X1d = false;
        }
        else bss_inst.BSS926X1d = false;
    }
    else
    {
            pzpe1 = true;
            pzpvvt1 = false;
            k5_2120 = true;
            k6_2120 = true;
            k7_2120 = false;
    }

    if(!k7_2120 && exchange::ush1dpp >= 18.0 && exchange::s6_2120)
        k7_2120 = true;

    if(exchange::ushal >= 18.0)
    {
        if(!k7_2120)
        {
            alphazktvt12 = alphazktvt12 - 0.25 * tS;
            if(alphazktvt12 < 0.0) alphazktvt12 = 0.0;
        }
        else
        {
            alphazktvt12 = alphazktvt12 + 0.25 * tS;
            if(alphazktvt12 > 1.0) alphazktvt12 = 1.0;
        }
    }

    if(exchange::ushal >= 18.0)
    {
        if(!k3_2120)
        {
            alphazm1 = alphazm1 - 0.25 * tS;
            if(alphazm1 < 0.0)
            {
                alphazm1 = 0.0;
                pzpe1 = true;
                pzpvvt1 = false;
            }
        }
        else
        {
            alphazm1 = alphazm1 + 0.25 * tS;
            if(alphazm1 > 1.0) alphazm1 = 1.0;
        }
    }

    if(exchange::ushal >= 18.0)
    {
        if(!k5_2120)
        {
            alphaztvt1 = alphaztvt1 - 0.25 * tS;
            if(alphaztvt1 < 0.0) alphaztvt1 = 0.0;
        }
        else
        {
            alphaztvt1 = alphaztvt1 + 0.25 * tS;
            if(alphaztvt1 > 1.0) alphaztvt1 = 1.0;
        }

        if(!k6_2120)
        {
            alphaztvt2 = alphaztvt2 - 0.25 * tS;
            if(alphaztvt2 < 0.0) alphaztvt2 = 0.0;
        }
        else
        {
            alphaztvt2 = alphaztvt2 + 0.25 * tS;
            if(alphaztvt2 > 1.0) alphaztvt2 = 1.0;
        }
    }

    if(exchange::ush2dpl >= 18.0)
    {
        if(!pzpe1)
        {
            alphazpe1 = alphazpe1 - 0.25 * tS;
            if(alphazpe1 < 0.0) alphazpe1 = 0.0;
        }
        else
        {
            alphazpe1 = alphazpe1 + 0.25 * tS;
            if(alphazpe1 > 1.0) alphazpe1 = 1.0;
        }
    }

    if(exchange::ush2dpl >= 18.0)
    {
        if(!pzpvvt1)
        {
            alphazpvvt1 = alphazpvvt1 - 0.25 * tS;
            if(alphazpvvt1 < 0.0) alphazpvvt1 = 0.0;
        }
        else
        {
            alphazpvvt1 = alphazpvvt1 + 0.25 * tS;
            if(alphazpvvt1 > 1.0) alphazpvvt1 = 1.0;
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////2nd list
    k2_2120 = false;

    if(exchange::ushap >= 18.0 && exchange::s4_2120)
    {
        k2_2120 = true;
    }

    pruukp = false;
    k4_2120 = false;
    k10_2120 = false;

    if(exchange::ush2dpp >= 18.0 && !exchange::s4_2120)
    {
        if(exchange::s2_2120)
        {
            pruukp = true;

            if(!k13_2110 && !k2_2120) k4_2120 = true;
        }
        else
        {
            pzpe2 = true;
            pzpvvt2 = false;
            k8_2120 = true;
            k9_2120 = true;
            k10_2120 = false;
        }
    }
    if(otkaz_povishTemprVozd) tvvt2 = 355.0;
    else tvvt2 = 70.0;

    if(otkaz_povishDavlVozMag2) Potb3_4 = 8.2;

    pom2 = false;

    if(pruukp)
    {
        if(tvvt2 >= 350.0 || Potb3_4 >= 8.0)
        {
            pom2 = true;
            k4_2120 = false;
        }

        if(exchange::PRD3dv) k8_2120 = true;
        else k8_2120 = false;
        if(exchange::PRD4dv) k9_2120 = true;
        else k9_2120 = false;

        if(!k8_2120)
        {
            if(!k9_2120)
            {
//                pom2 = true;
//                k4_2120 = false;
            }
            else
                k10_2120 = true;
        }
        else
            if(!k9_2120) k10_2120 = true;

        if(pom2)
        {
            if(!exchange::s4_2120) bss_inst.zakr_m1 = true;
            if(alphazm1 <= 0.0) bss_inst.zakr_m1 = false;
        }
        else bss_inst.zakr_m1 = false;
    }
    else
    {
        pzpe2 = true;
        pzpvvt2 = false;
        k8_2120 = true;
        k9_2120 = true;
        k10_2120 = false;
    }

    if(!k10_2120 && exchange::ush1dpp >= 18.0 && exchange::s6_2120)
        k10_2120 = true;

    if(exchange::ushap >= 18.0)
    {
        if(!k10_2120)
        {
            alphazkm12 = alphazkm12 - 0.25 * tS;
            if(alphazkm12 < 0.0) alphazkm12 = 0.0;
        }
        else
        {
            alphazkm12 = alphazkm12 + 0.25 * tS;
            if(alphazkm12 > 1.0) alphazkm12 = 1.0;
        }
    }

    if(exchange::ushap >= 18.0)
    {
        if(!k4_2120)
        {
            alphazm2 = alphazm2 - 0.25 * tS;
            if(alphazm2 < 0.0)
            {
                alphazm2 = 0.0;
                pzpe2 = true;
                pzpvvt2 = false;
            }
        }
        else
        {
            alphazm2 = alphazm2 + 0.25 * tS;
            if(alphazm2 > 1.0) alphazm2 = 1.0;
        }
    }

    if(exchange::ushap >= 18.0)
    {
        if(!k8_2120)
        {
            alphaztvt3 = alphaztvt3 - 0.25 * tS;
            if(alphaztvt3 < 0.0) alphaztvt3 = 0.0;
        }
        else
        {
            alphaztvt3 = alphaztvt3 + 0.25 * tS;
            if(alphaztvt3 > 1.0) alphaztvt3 = 1.0;
        }

        if(!k9_2120)
        {
            alphaztvt4 = alphaztvt4 - 0.25 * tS;
            if(alphaztvt4 < 0.0) alphaztvt4 = 0.0;
        }
        else
        {
            alphaztvt4 = alphaztvt4 + 0.25 * tS;
            if(alphaztvt4 > 1.0) alphaztvt4 = 1.0;
        }
    }

    if(exchange::ush2dpp >= 18.0)
    {
        if(!pzpe2)
        {
            alphazpe2 = alphazpe2 - 0.25 * tS;
            if(alphazpe2 < 0.0) alphazpe2 = 0.0;
        }
        else
        {
            alphazpe2 = alphazpe2 + 0.25 * tS;
            if(alphazpe2 > 1.0) alphazpe2 = 1.0;
        }
    }

    if(exchange::ush2dpp >= 18.0)
    {
        if(!pzpvvt2)
        {
            alphazpvvt2 = alphazpvvt2 - 0.25 * tS;
            if(alphazpvvt2 < 0.0) alphazpvvt2 = 0.0;
        }
        else
        {
            alphazpvvt2 = alphazpvvt2 + 0.25 * tS;
            if(alphazpvvt2 > 1.0) alphazpvvt2 = 1.0;
        }
    }

    sd_sm_fltL = false;
    sd_sm_fltP = false;

    if(exchange::usho1p >= 18.0 && exchange::s5_2120)
    {
        if(pruukl) sd_sm_fltL = true;
        if(pruukp) sd_sm_fltP = true;
    }

}
