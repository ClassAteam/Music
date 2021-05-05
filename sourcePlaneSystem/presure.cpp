#include "presure.h"

void presure_int::presure()
{
    static int
    blink_tick1,
    blink_tick2,

    PAVARR = false;
    PPP = false;
    PGK = false;
    K1_2131 = false;
    K2_2131 = false;
    K4_2131 = false;
    Ph_ = (Ph * 0.00136);
    double H_buf = H / 1000;
    Ph_msa = yx_d(&a1, &b1, 12, H_buf);
    Ph_msa = (Ph_msa * 0.00136);

    if (exchange::ush2dpl >= 18.0)
    {
        if ((Pkab - Ph_msa) >= 0.7)
            K1_2131 = true;
        else
            K1_2131 = false;

        if (S1_2131 == 1)
            PPP = true;
        else
        {
            if (S1_2131 == 2)
            {
                PAVARR = true;
                K4_2131 = true;
            }
        }

        if (H < 8000.0 && S2_2131 == 1)
            PGK = true;

        if (K4_2131 == false && Pkab <= 0.34)
            K2_2131 = true;
    }

    if (K1_2131 && (blink_tick1 * TICK) >= 600)
    {
        SKD_D300 = true;
        bss_inst.BSS838X7A = true;
        blink_tick1 = 0;
    }
    else
    {
        bss_inst.BSS838X7A = false;
        SKD_D300 = false;
        if(K1_2131) blink_tick1++;
    }

    if(K2_2131 && (blink_tick2 * TICK) >= 600)
    {
        SKD_D301 = true;
        bss_inst.BSS838X5MM = true;
        blink_tick2 = 0;
    }
    else
    {
        bss_inst.BSS838X5MM = false;
        SKD_D300 = false;
        if(K2_2131) blink_tick2++;
    }

    if (!otkaz_razgermetizatsiya && PRTHU1 && lyukizagermetizirovany  && !otkaz_perenadduv)
    {

        if(PAVARR)
        {
            Pkab_zad = Ph_;

            if(Pkab_zad >= Pkab)
                Vkab = 0.0068;
            else
                Vkab = 0.00136;
        }
        else
        {
            if(PPP && H >= 7300)
                Pkab_zad = Ph_msa + 0.36;
            else
            {

                if(PGK)
                {
                    if((H >= -500) && (H <= 3700))
                        Pkab_zad = Ph_msa + 0.12;
                    else
                    {
                        if((H > 2400) && (H < 11500))
                            Pkab_zad = 0.77;
                        else
                        {
                            if((H > 11500) && (H < 15000))
                                Pkab_zad = (0.77 + (0.33 * (11.5 - H)));
                            else
                                Pkab_zad = (Ph_msa + 0.36);
                        }
                    }
                }
                else
                {
                    if((H >= -500) && (H <= 2400))
                        Pkab_zad = Ph_;
                    else
                    {
                        if((H > 2400) && (H < 11500))
                            Pkab_zad = 0.77;
                        else
                        {
                            if((H > 11500) && (H < 15000))
                                Pkab_zad = (0.77 + (0.33 * (11.5 - (H / 1000))));
                            else
                                Pkab_zad = (Ph_msa + 0.36);
                        }
                    }
                }
            }

            if(Pkab_zad >= Pkab)
                Vkab = 0.0068;
            else
                Vkab = 0.00136;
        }
    }
    else
    {
        Pkab_zad = Ph_;
        Vkab = 0.0068;
    }

    if (!otkaz_razgermetizatsiya && PRTHU1 && lyukizagermetizirovany && otkaz_perenadduv)
    {
        Pkab_zad = Ph_msa + 0.8;
        Vkab = 0.0068;
    }

    if ((fabs(Pkab_zad - Pkab)) >= 0.005)
    {
        if (Pkab < Pkab_zad)
            Pkab = (Pkab + (Vkab * (TICK / 1000)));
        else
            Pkab = (Pkab - (Vkab * (TICK / 1000)));
    }

    Pk_h = (Pkab / 0.00136);
    Hkab = yx_d(&b2, &a2, 12, Pk_h);
    Pkab_delta = Pkab - Ph_;

    if(Hkab > 20)
        Hkab_ind = 20;
    else
    {
        if (Hkab < 0.0)
            Hkab_ind = 0.0;
        else
            Hkab_ind = (Hkab);
    }

    if (Pkab_delta > 0.8)
        Pkab_ind_delta = 0.8;
    else
    {

        if(Pkab < (-0.06))
            Pkab_ind_delta = (-0.06);
        else
            Pkab_ind_delta = Pkab_delta;
    }

    ///////////////////////////end logic()
}
