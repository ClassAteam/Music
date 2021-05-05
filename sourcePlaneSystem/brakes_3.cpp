#include "algorithms.h"
#include "brakes_3.h"

void brakes_int::brakes_3()
{
    static int
        tick_alg_3,
        tick_alg_2,
        tick_alg_1;


    PTavtN = false;
    PTavtP = false;
    PTavtS = false;
    PTfors = false;
    PTstart = false;
    ptstoyan = false;
    PPDGAKT = false;

    if((exchange::pgs2 >= 200 || exchange::pgs3 >= 220 || pgat >= 130) && vkh <= 72.0)
    {
        if(exchange::K35_3230 && (exchange::K27_3230  || exchange::K26_3230))
        {
            if(POSH1)
            {

            }
            else
            {
                if(tick_alg_1 * TICK < 5000 )
                {
                    tick_alg_1++;
                }
                else
                {
                    POSH1 = true;
                    tick_alg_1 = 0;
                }
            }
        }
        else
        {
            POSH1 = false;
            tick_alg_1 = 0;
        }

        if(POSH1)
        {
            if(PstartT)
            {
                PTstart = true;
                if(vkh <= 8.1)
                {
                    P_t_lev = 150;
                    P_t_prav = 150;
                }
                else
                {
                    P_t_lev = 0;
                    P_t_prav = 0;
                }
            }

            if(PstoyanT)
            {
                P_t_lev = 120;
                P_t_prav = 120;
                ptstoyan = true;
            }

            if(vkh <= 8.1)
            {
                if(PAVT_N)
                {
                    P_t_lev = 100;
                    P_t_prav = 100;
                    ax_ts = 0;
                    PTavtN = true;
                }
                else
                {
                    if(PAVT_P)
                    {
                        P_t_lev = 80;
                        P_t_prav = 80;
                        ax_ts = 0;
                        PTavtP = true;
                    }
                    else
                    {
                        if(PAVT_S)
                        {
                            P_t_lev = 60;
                            P_t_prav = 60;
                            ax_ts = 0;
                            PTavtS = true;
                        }
                        else
                        {
                            if(PFT)
                            {
                                P_t_lev = 150;
                                P_t_prav = 150;
                                ax_ts = 0;
                                PTfors = true;
                            }
                        }
                    }
                }
            }
            else
            {
                if(PAVT_N)
                {
                    P_t_lev = 120;
                    P_t_prav = 120;
                    ax_ts = 3;
                    PTavtN = true;
                }
                else
                {
                    if(PAVT_P)
                    {
                        P_t_lev = 100;
                        P_t_prav = 100;
                        ax_ts = 2.4;
                        PTavtP = true;
                    }
                    else
                    {
                        if(PAVT_S)
                        {
                            P_t_lev = 70;
                            P_t_prav = 70;
                            ax_ts = 1.8;
                            PTavtS = true;
                        }
                        else
                        {
                            if(PFT)
                            {
                                P_t_lev = 150;
                                P_t_prav = 150;
                                ax_ts = 3.9;
                                PTfors = true;
                            }
                            else
                                ax_ts = (3 * ((P_tp_prav + P_tp_lev)/ (2 * 120)));
                        }
                    }
                }
            }

            if(pavtt && PFT)
            {
                P_t_lev = P_t_lev + 25.0;
                P_t_prav = P_t_prav + 25.0;
            }

            if(PAVART)
            {
                if(pavtt)
                {
                    if(PRR)
                        tick_alg_2 = 0;
                    else
                    {
                        if(pgat < 130 || vkh <= 13.5)
                        {
                            P_t_lev = 120;
                            P_t_prav = 120;
                            tick_alg_2 = 0;
                            Pavart = 0;
                        }
                        else
                        {
                            if((tick_alg_2 * TICK) >= 500)
                            {
                                if((tick_alg_2 * TICK) >= 1500)
                                {
                                    tick_alg_2 = 0;
                                    Pavart = 15;
                                }
                                else
                                {
                                    tick_alg_2++;
                                    P_t_lev = (P_t_lev * (((tick_alg_2 * TICK) / 1000) - 0.5));
                                    P_t_prav = (P_t_prav * (((tick_alg_2 * TICK) / 1000) - 0.5));
                                }
                            }
                            else
                            {
                                tick_alg_2++;
                                P_t_lev = ((P_t_lev * (1 - (2 * ((tick_alg_2 * TICK) / 1000)))) + 5);
                                P_t_prav = ((P_t_prav * (1 - (2 * ((tick_alg_2 * TICK) / 1000)))) + 5);
                            }
                        }
                    }
                }
                else
                {
                    P_t_lev = 20;
                    P_t_prav = 20;
                }
            }
            else
            {
                Pavart = 0;

                if(PORST && exchange::s2_3240 && exchange::K35_3230 &&
                    exchange::K27_3230 && exchange::K26_3230)
                    PstoyanT = true;
            }
        }
        else
        {
            P_t_lev = 0;
            P_t_prav = 0;
            if(pbutzo && exchange::S1_3230 && PRR &&
                !exchange::K27_3230 && !exchange::K26_3230)
            {
                if((tick_alg_3 * TICK) >= 5000)
                {
                    P_t_lev = 0;
                    P_t_prav = 0;
                    tick_alg_3 = 0;
                }
                else
                {
                    P_t_lev = 50;
                    P_t_prav = 50;
                    tick_alg_3++;
                }
            }
            else
            {
                tick_alg_3 = 0;
            }
        }
    }
    else
    {
        tick_alg_1 = 0;
        tick_alg_3 = 0;
    }

    if(PstoyanT)
    {
        if(pgat >= 130.0)
        {

        }
        else
        {
            PPDGAKT = true;
            P_t_lev = 120;
            P_t_prav = 120;
        }
    }
}
