#include "brakes_2.h"

//using namespace exchange;


void brakes_int::brakes_2()
{
    static int
        tick_block_rt;

    //start logic
    if(exchange::ushap >= 18.0 && exchange::ushal >= 18.0 && exchange::ush1dpp >= 18.0)
    {
        if(!exchange::s1_3241)
            PvklR = false;
        else
            PvklR = true;

        if(pbutzo)
        {
            PBRRT = false;
            pbutzr = false;
            PvklR = false;
            tick_block_rt = 0;
        }
        else
        {
            if(PvklR)
            {
                PBRRT = true;
                tick_block_rt = 0;
            }
            else
            {
                if(PBRRT)
                {
                    if(X_tp_lev <= 0.12 || X_tp_prav <= 0.12)
                    {
                        if(tick_block_rt * TICK <= 2000)
                            tick_block_rt++;
                        else
                            PBRRT = false;
                    }
                }
            }

            PAVART = false;
            PORST = false;
            PAVT_N = false;
            PAVT_P = false;
            PAVT_S = false;
            pavtt = false;
            pbutzr = false;

            if(otkaz_avt_per_na_rt)
            {
                if(exchange::s1_3241)
                {
                    if(otkaz_rt)
                    {
                        pbutzr = false;
                        PORST = true;
                    }
                    else
                    {
                        pbutzr = true;
                        if(exchange::s1_3240 == static_cast<int>(exchange::s1_3240::norm))
                        {
                            pavtt = true;
                            PAVT_N = true;
                        }
                        else
                        {
                            if(exchange::s1_3240 == static_cast<int>(exchange::s1_3240::ponizh))
                            {
                                pavtt = true;
                                PAVT_P = true;
                            }
                            else
                            {
                                if(exchange::s1_3240 == static_cast<int>(exchange::s1_3240::slabo))
                                {
                                    pavtt = true;
                                    PAVT_S = true;
                                }
                                else
                                {
                                    pavtt = false;
                                    PBAVTT = false;
                                }
                            }
                        }

                        if(X_tp_lev >= 0.12 || X_tp_prav >= 0.12)
                        {
                            PBAVTT = true;
                            pavtt = false;
                        }

                        if(POSH2)
                        {
                            if(exchange::delta_z >= 23.0 && exchange::delta_z <= 28.0)
                            {
                                if(paft || PRR)
                                {
                                    if(X_tp_lev >= 0.12 || X_tp_prav >= 0.12)
                                    {
                                        PFT = true;
                                        paft = true;
                                    }
                                }
                            }
                            else
                                paft = false;
                        }
                    }
                }
            }
            else
            {
                if(otkaz_rt)
                {
                    pbutzr = false;
                    PORST = true;
                }
                else
                {
                    pbutzr = true;
                    if(exchange::s1_3240 == static_cast<int>(exchange::s1_3240::norm))
                    {
                        pavtt = true;
                        PAVT_N = true;
                    }
                    else
                    {
                        if(exchange::s1_3240 == static_cast<int>(exchange::s1_3240::ponizh))
                        {
                            pavtt = true;
                            PAVT_P = true;
                        }
                        else
                        {
                            if(exchange::s1_3240 == static_cast<int>(exchange::s1_3240::slabo))
                            {
                                pavtt = true;
                                PAVT_S = true;
                            }
                            else
                            {
                                pavtt = false;
                                PBAVTT = false;
                            }
                        }
                    }

                    if(X_tp_lev >= 0.12 || X_tp_prav >= 0.12)
                    {
                        PBAVTT = true;
                        pavtt = false;
                    }

                    if(exchange::P2OBLOP)
                    {
                        if(exchange::delta_z >= 23.0 && exchange::delta_z <= 28.0)
                        {
                            if(paft || PRR)
                            {
                                if(X_tp_lev >= 0.12 && X_tp_prav >= 0.12)
                                {
                                    PFT = true;
                                    paft = true;
                                }
                            }
                        }
                        else
                            paft = false;
                    }
                }
            }
        }
    }
    else
    {
        pbutzr = false;
        PvklR = false;
        PBRRT = false;
    }

    if(hydro.otkaz_gs3 && !pbutzo)
        PAVART = true;
    else
    {
        if(exchange::s2_3240 && pbutzr)
        {
            PstoyanT = true;
            PstartT = false;
        }
    }

    if(!pavtt)
    {
        PAVT_N = false;
        PAVT_P = false;
        PAVT_S = false;
    }
}
//end logic
