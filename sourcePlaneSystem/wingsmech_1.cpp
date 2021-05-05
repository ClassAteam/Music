#include "wingsmech_1.h"


void wingsmech_int::wingsmech_1()
{
    //start logic
    prr1kz = false;
    psr1kz = false;
    por1kz = false;
    delta_zr_vh_bf = delta_zr_vh / 100;
    delta_z_zad = m_3_L_intervals(delta_zr_vh_bf, 0, 0.3, 0.6, 1.0, 0, 15, 25, 40);

    if(hydro_int::pgs1 >= 130)
    {
        if(exchange::ushal >= 18.0)
        {
            if(S1_2750)
            {
                prr1kz = true;
            }
            else
            {
                if(otkaz_1k_zakr == false)
                {
                    if(S13_2750)
                    {
                        psr1kz = true;
                    }
                    else
                    {
                        if(otkaz_osn_1k_zakr == false)
                        {
                            por1kz = true;
                            if(exchange::P2OBLOP == false)
                            {
                                delta_z_zad = delta_z_zad * Kz;
                            }
                        }
                    }
                }
            }
        }
    }
    prrkz = false;
    prr2kz = false;
    psr2kz = false;
    por2kz = false;

    if(hydro_int::pgs4 >= 130)
    {
        if(exchange::ushap >= 18.0)
        {
            if(S1_2750)
            {
                prr2kz = true;
            }
            else
            {
                if(otkaz_2k_zakr == false)
                {
                    if(S13_2750)
                    {
                        psr2kz = true;
                    }
                    else
                    {
                        if(otkaz_osn_2k_zakr == false)
                        {
                            por2kz = true;
                            if(exchange::P2OBPOP == false)
                            {
                                delta_z_zad = delta_z_zad * Kz;
                            }
                        }
                    }
                }
            }
        }
    }
    if(por1kz == true || psr1kz == true)
    {
        if(delta_z_l < delta_z_zad)
        {
            if((delta_pr_l >= 20.5) && (X_L >= 20  && X_L <= 30))
            {
                Ddelta_z_l = 2.2;
            }
            else
            {
                Ddelta_z_l = 0;
            }
        }
        else
        {
            Ddelta_z_l = -2.2;
        }
    }
    else
    {
        Ddelta_z_l = 0;
    }

    if(por2kz == true || psr2kz == true)
    {
        if(delta_z_p < delta_z_zad)
        {
            if((delta_pr_p >= 20.5) && (X_P >= 20  && X_P <= 30))
            {
                Ddelta_z_p = 2.2;
            }
            else
            {
                Ddelta_z_p = 0;
            }
        }
        else
        {
            Ddelta_z_p = -2.2;
        }
    }
    else
    {
        Ddelta_z_p = 0;
    }
    if(por1kz == true)
    {
        if(por2kz == false)
        {
            Ddelta_z_p = 0.5 * Ddelta_z_p;
            Ddelta_z_l = 0.5 * Ddelta_z_l;
        }
    }
    else
    {
        if(por2kz == true)
        {
            Ddelta_z_p = 0.5 * Ddelta_z_p;
            Ddelta_z_l = 0.5 * Ddelta_z_l;
        }
    }

    if(prr1kz == true)
    {
        if(S2_2750 == 2)
        {
            if(delta_pr_l >= 21)
            {
                if(X_L >= 20 && X_L <= 35)
                {
                    Ddelta_z_l = 2.2;
                }
                else
                {
                    Ddelta_z_l = 0;
                }

            }
            else
            {
                Ddelta_z_l = 0;
            }
        }
        else
        {
            if(S2_2750 == 1)
            {
                Ddelta_z_l = -2.2;
            }
            else
            {
                Ddelta_z_l = 0;
            }
        }
    }

    if(prr2kz == true)
    {
        if(S2_2750 == 2)
        {
            if(delta_pr_p >= 21)
            {
                if(X_P >= 20 && X_P <= 35)
                {
                    Ddelta_z_p = 2.2;
                }
                else
                {
                    Ddelta_z_p = 0;
                }
            }
            else
            {
                Ddelta_z_p = 0;
            }
        }
        else
        {
            if(S2_2750 == 1)
            {
                Ddelta_z_p = -2.2;
            }
            else
            {
                Ddelta_z_p = 0;
            }
        }

        prrkz = true;

        if(prr1kz == false)
        {
            Ddelta_z_l = 0.5 * Ddelta_z_l;
            Ddelta_z_p = 0.5 * Ddelta_z_p;
        }
    }
    else
    {
        if(prr1kz == true)
        {
            prrkz = true;
            Ddelta_z_l = 0.5 * Ddelta_z_l;
            Ddelta_z_p = 0.5 * Ddelta_z_p;
        }
    }
    if(abs(delta_z_l - delta_z_p) < 2.5)
    {
        if(prrkz == true)
        {
            delta_z_l = delta_z_l + (Ddelta_z_l * (TICK / 1000));
            delta_z_p = delta_z_p + (Ddelta_z_p * (TICK / 1000));
        }
        if(abs(delta_z_l - delta_z_zad) >= 0.1)
        {
            delta_z_l = delta_z_l + (Ddelta_z_l * (TICK / 1000));
        }
        else
        {
            Ddelta_z_l = 0;
        }

        if(otkaz_rassgl_zakr == true)
        {
            delta_z_zad = delta_z_zad - 2.7;
        }

        if(abs(delta_z_p - delta_z_zad) >= 0.1)
        {
            delta_z_p = delta_z_p + (Ddelta_z_p * (TICK / 1000));
        }
        else
        {
            Ddelta_z_p = 0;
        }

    }
    if(delta_z_l <= 0)
    {
        delta_z_l = 0;
    }
    if(delta_z_l >= 40)
    {
        delta_z_l = 40;
    }
    if(delta_z_p <= 0)
    {
        delta_z_p = 0;
    }
    if(delta_z_p >= 40)
    {
        delta_z_p = 40;
    }
    //end logic
}
