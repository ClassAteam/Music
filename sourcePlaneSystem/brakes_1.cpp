#include "algorithms.h"
#include "brakes_1.h"



void brakes_int::brakes_1()
{
//    timing.start();
pgat = exchange::pgat;
    //start logic
    double
        X_ped11_buf{exchange::X_ped11 / 100},
        X_ped12_buf{exchange::X_ped12 / 100},
        X_ped21_buf{exchange::X_ped21 / 100},
        X_ped22_buf{exchange::X_ped22 / 100};

    if(X_ped11_buf >= X_ped21_buf)
        X_tp_lev = X_ped11_buf;
    else
        X_tp_lev = X_ped21_buf;

    if(X_ped12_buf >= X_ped22_buf)
        X_tp_prav = X_ped12_buf;
    else
        X_tp_prav = X_ped22_buf;

    P_ped_11 = m_3_L_intervals(X_ped11_buf, 0, 0.1, 0.1, 1.0, 0, 0, 0.25, 1.0);
    P_ped_12 = m_3_L_intervals(X_ped12_buf, 0, 0.1, 0.1, 1.0, 0, 0, 0.25, 1.0);
    P_ped_21 = m_3_L_intervals(X_ped21_buf, 0, 0.1, 0.1, 1.0, 0, 0, 0.25, 1.0);
    P_ped_22 = m_3_L_intervals(X_ped22_buf, 0, 0.1, 0.1, 1.0, 0, 0, 0.25, 1.0);

    if(P_ped_11 >= P_ped_21)
        P_t_lev = P_ped_11 * 120;
    else
        P_t_lev = P_ped_21 * 120;

    if(P_ped_12 >= P_ped_22)
        P_t_prav = P_ped_12 * 120;
    else
        P_t_prav = P_ped_22 * 120;

    if(exchange::alpha_rud_1dv < 45 && exchange::alpha_rud_2dv < 45 &&
        exchange::alpha_rud_3dv < 45 && exchange::alpha_rud_4dv < 45)
        PRR = false;
    else
        PRR = true;

    if(exchange::ush1dpl >= 18 && exchange::K35_3230 &&
        exchange::K27_3230 && exchange::K26_3230 )
        POSH2 = true;
    else
        POSH2 = false;

    PstartT = false;
    PstoyanT = false;
    POOST = false;
    PFT = false;
    PvkFT = false;

    PAVT_N = false;
    PAVT_P = false;
    PAVT_S = false;
    pavtt = false;

    if(exchange::ushal >= 18 && exchange::ush1dpl >= 18)
    {
        if(otkaz_osn_sis_torm)
        {
            pbutzo = false;
            POOST = true;
            paft = false;
        }
        else
        {
            pbutzo = true;
            if(exchange::s1_3240 == 1)
            {
                pavtt = true;
                PAVT_N = true;
            }
            else
            {
                if(exchange::s1_3240 == 2)
                {
                    pavtt = true;
                    PAVT_P = true;
                }
                else
                {
                    if(exchange::s1_3240 == 3)
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

            if(X_tp_lev >= 0.12 || X_tp_prav >= 0.12 )
            {
                PBAVTT = true;
                pavtt = false;
            }

            if(exchange::s2_3240)
            {
                PstoyanT = true;

                if(!X1_45_7620 && !X2_45_7620 && !X3_45_7620 && !X4_45_7620)
                {
                    PstartT = true;
                }
            }

            if(POSH2)
            {
                if(exchange::s3_3240)
                {
                    PvkFT = true;
                    PFT = true;
                }

                if(exchange::delta_z >= 23 && exchange::delta_z <= 28)
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
            else
                paft = false;
        }
    }
    else
    {
        pavtt = false;
        pbutzo = false;
        paft = false;

    }

    if(!pavtt)
    {
        PAVT_N = false;
        PAVT_P = false;
        PAVT_S = false;
    }
}
//end logic
