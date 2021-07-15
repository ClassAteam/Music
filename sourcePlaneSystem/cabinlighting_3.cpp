#include "cabinlighting_3.h"

void cabinlighting_int::cabinlighting_3()
{
    static bool K1_3340{};
    static bool K2_3340{};
    static bool K3_3340{};
    static bool K4_3340{};
    static bool K5_3340{};
    static bool K6_3340{};
    static bool K7_3340{};
    static bool K8_3340{};
    static bool K9_3340{};//otkl
    static bool K10_3340{};//otkl
    static bool K11_3340{};//vzlt-posadka
    static bool K12_3340{};//zlt-posadka
    static bool K13_3340{};
    static bool K14_3340{};
    // A left side toggling
    if(exchange::ush1l >= 18.0 && F1_3340)
    {
        if (F4_3340)
        {
            if(K1_3340) PFPRPLP = true;
            else
            {
                if(K2_3340) PFPRLR = true;
            }

            if(S1_3340 == 1)
            {
                PVFL = true;
                K1_3340 = false;
                K2_3340 = false;
                K13_3340 = false;
            }
            else
            {
                PVFL = false;
            }

            if(!K9_3340)
            {

                if(!K11_3340) K13_3340 = true;
                else
                {
                    if(!K3_3340) K1_3340 = true;
                }
            }

            if(K13_3340)
            {
                if(!K3_3340) K2_3340 = true;
            }

            K9_3340 = K11_3340 = false;

            if(S6_3340 == 2)
            {
                K9_3340 = true;
            }

            if (S6_3340 == 1)
            {
                K11_3340 = true;
            }
        }
        else
        {
            PVFL = false;
            K1_3340 = K2_3340 = false;
            K9_3340 = K11_3340 = K13_3340 = false;
        }

        PFSV_01LR = PFSV_01LP = false;

        //alpha_fsv_OL input / insert
        if(F2_3340 == true)
        {
            if(Vpr <= 115.0 && PVFL && alpha_fsv_ol < 1.0)
            {
                alpha_fsv_ol = alpha_fsv_ol + 0.01;
                if(alpha_fsv_ol >= 1) alpha_fsv_ol = 1.0;
            }

            if(Vpr <= 115.0 && !PVFL && alpha_fsv_ol > 0.0)
            {
                alpha_fsv_ol = alpha_fsv_ol - 0.01;
                if(alpha_fsv_ol <= 0) alpha_fsv_ol = 0;
            }
            //emergency insert
            if (Vpr > 115.0 && PVFL && alpha_fsv_ol > 0.0)
            {
                alpha_fsv_ol = alpha_fsv_ol - 0.01;
                if(alpha_fsv_ol <= 0.0) alpha_fsv_ol = 0;
            }
        }

        // PFSV_01 toggle
        if(K13_3340 && alpha_fsv_ol >= 1.0) PFSV_01LR = true;

        if (!K9_3340 && K11_3340) PFSV_01LP = true;

        PFPRPR = false;
        PFPRPP = false;
    }
    else
    {
        K1_3340 = false;
        K2_3340 = false;
        K9_3340 = false;
        K11_3340 = false;
        K13_3340 = false;
    }

    // B right side toggling
    if (exchange::ush1p >= 18.0 && F14_3340)
    {
        if(F12_3340)
        {
            if(K6_3340) PFPRPP = true;
            else
            {
                if(K7_3340) PFPRPR = true;
            }

            if(S1_3340)
            {
                PVFP = true;
                K6_3340 = false;
                K7_3340 = false;
                K14_3340 = false;
            }
            else
            {
                PVFP = false;
            }

            if(!K10_3340)
            {
                if(!K12_3340) K14_3340 = true;
                else
                {
                    if(!K8_3340) K6_3340 = true;
                }
            }

            if(K14_3340 && !K8_3340) K7_3340 = true;

            K10_3340 = K12_3340 = false;

            switch(S6_3340)
            {
            case(2):
                K10_3340 = true;
                break;
            case(1):
                K12_3340 = true;
                break;
            }
        }
        else
        {
            PVFP = false;
            K6_3340 = false;
            K7_3340 = false;
            K12_3340 = false;
            K10_3340 = false;
            K14_3340 = false;
        }

        PFSV_01PR = PFSV_01PP = false;

        //alpha_fsv_OL input / insert
        if(F13_3340)
        {
            if(Vpr <= 115.0 && PVFP && alpha_fsv_op < 1)
            {
                alpha_fsv_op = alpha_fsv_op + 0.01;
                if(alpha_fsv_op >= 1) alpha_fsv_op = 1.0;
            }

            if (Vpr <= 115.0 && !PVFP && alpha_fsv_op > 0)
            {
                alpha_fsv_op = alpha_fsv_op - 0.01;

                if(alpha_fsv_op <= 0) alpha_fsv_op = 0;
            }
            //emergency insert
            if(Vpr > 115.0 && PVFP && alpha_fsv_op > 0)
            {
                alpha_fsv_op = alpha_fsv_op - 0.01;
                if(alpha_fsv_op <= 0) alpha_fsv_op = 0;
            }
        }
    }
    else
    {
        K6_3340 = false;
        K7_3340 = false;
        K10_3340 = false;
        K12_3340 = false;
        K14_3340 = false;
    }

    // PFSV_01 toggle
    if (K14_3340 && alpha_fsv_op >= 1.0)
        PFSV_01PR = true;

    if (!K10_3340 && K12_3340)
        PFSV_01PP = true;

    K3_3340 = K8_3340 = false;
    // K3, K8 toggle

    if(exchange::ushal >= 18.0 && K32_3230)
        K3_3340 = true;

    if (exchange::ushap >= 18.0 && exchange::K34_3230)
        K8_3340 = true;
}
