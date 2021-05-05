#include "wingsmech_2.h"


void wingsmech_int::wingsmech_2()
{
    //start logic
    prr1kpr = false;
    psr1kpr = false;
    por1kpr = false;
    delta_pr_zad = m_2_L_intervals(delta_zr_vh_bf, 0, 0.6, 1.0, 0, 21, 21);

    if(hydro_int::pgs2 >= 130)
    {
        if(exchange::ushal >= 18.0)
        {
            if(s1_2780 == true)
            {
                prr1kpr = true;
            }
            else
            {
                if(otkaz_1k_prekr == false)
                {
                    if(S13_2750 == true)
                    {
                        psr1kpr = true;
                    }
                    else
                    {
                        if(otkaz_osn_1k_prekr == false)
                        {
                            por1kpr = true;
                            if(exchange::P2OBLOP == false)
                            {
                                delta_pr_zad = delta_pr_zad * Kpr;
                            }
                        }
                    }
                }
            }
        }
    }
    prrkpr = false;
    prr2kpr = false;
    psr2kpr = false;
    por2kpr = false;

    if(hydro_int::pgs3 >= 130)
    {
        if(exchange::ushap >= 18.0)
        {
            if(s1_2780 == true)
            {
                prr2kpr = true;
            }
            else
            {
                if(otkaz_2k_prekr == false)
                {
                    if(S13_2750 == true)
                    {
                        psr2kpr = true;
                    }
                    else
                    {
                        if(otkaz_osn_2k_prekr == false)
                        {
                            por2kpr = true;
                            if(exchange::P2OBPOP == false)
                            {
                                delta_pr_zad = delta_pr_zad * Kpr;
                            }
                        }
                    }
                }
            }
        }
    }
    if(por1kpr == true || psr1kpr == true)
    {
        if(delta_pr_l < delta_pr_zad)
        {
            Ddelta_pr_l = 1.68;
        }
        else
        {
            if(delta_z_l > 0)
            {
                Ddelta_pr_l = 0;
            }
            else
            {
                Ddelta_pr_l = -1.68;
            }
        }
    }
    else
    {
        Ddelta_pr_l = 0;
    }

    if(por2kpr == true || psr2kpr == true)
    {
        if(delta_pr_p < delta_pr_zad)
        {
            Ddelta_pr_p = 1.68;
        }
        else
        {
            if(delta_z_p > 0)
            {
                Ddelta_pr_p = 0;
            }
            else
            {
                Ddelta_pr_p = -1.68;
            }
        }
    }
    else
    {
        Ddelta_pr_p = 0;
    }

    if(por1kpr == true)
    {
        if(por2kpr == false)
        {
            Ddelta_pr_p = 0.5 * Ddelta_pr_p;
            Ddelta_pr_l = 0.5 * Ddelta_pr_l;
        }
    }
    else
    {
        if(por2kpr == true)
        {
            Ddelta_pr_p = 0.5 * Ddelta_pr_p;
            Ddelta_pr_l = 0.5 * Ddelta_pr_l;
        }
    }

    if(prr1kpr == true)
    {
        if(s2_2780 == 2)
        {
            if(delta_pr_l >= 21)
            {
                Ddelta_pr_l = 0;
            }
            else
            {
                Ddelta_pr_l = 1.68;
            }
        }
        else
        {
            if(s2_2780 == 1)
            {
                if(delta_pr_l > 0)
                {
                    Ddelta_pr_l = -1.68;
                }
                else
                {
                    Ddelta_pr_l = 0;
                }
            }
            else
            {
                Ddelta_pr_l = 0;
            }
        }
    }

    if(prr2kpr == true)
    {
        if(s2_2780 == 2)
        {
            if(delta_pr_p >= 21)
            {
                Ddelta_pr_p = 0;
            }
            else
            {
                Ddelta_pr_p = 1.68;
            }
        }
        else
        {
            if(s2_2780 == 1)
            {
                if(delta_pr_p > 0)
                {
                    Ddelta_pr_p = -1.68;
                }
                else
                {
                    Ddelta_pr_p = 0;
                }
            }
            else
            {
                Ddelta_pr_p = 0;
            }
        }
        prrkpr = true;
    }
    else
    {
        if(prr1kpr == true)
        {
            Ddelta_pr_l = 0.5 * Ddelta_pr_l;
            Ddelta_pr_p = 0.5 * Ddelta_pr_p;
            prrkpr = true;
        }
    }
    if(abs(delta_pr_l - delta_pr_p) < 2.5)
    {
        if(prrkpr == true)
        {
            delta_pr_l = delta_pr_l + (Ddelta_pr_l * (TICK / 1000));
            delta_pr_p = delta_pr_p + (Ddelta_pr_p * (TICK / 1000));
        }
        else
        {
            if(abs(delta_pr_l - delta_pr_zad) >= 0.1)
            {
                delta_pr_l = delta_pr_l + (Ddelta_pr_l * (TICK / 1000));
            }
            if(otkaz_rassgl_prekr == true)
            {
                delta_pr_zad = delta_pr_zad - 2.7;
            }

            if(abs(delta_pr_p - delta_pr_zad) >= 0.1)
            {
                delta_pr_p = delta_pr_p + (Ddelta_pr_p * (TICK / 1000));
            }
        }
    }
    if(delta_pr_l <= 0)
    {
        delta_pr_l = 0;
    }
    if(delta_pr_l > 21)
    {
        delta_pr_l = 21;
    }
    if(delta_pr_p <= 0)
    {
        delta_pr_p = 0;
    }
    if(delta_pr_p > 21)
    {
        delta_pr_p = 21;
    }
    //end logic
}
