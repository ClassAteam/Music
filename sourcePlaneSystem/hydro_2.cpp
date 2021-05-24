#include "hydro_2.h"	//actually 3rd

void hydro_int::hydro_2()
{
    static bool
        PAPD_26,
        PAPD_27,
        PAPD_30,
        PAPD_31;

    QVector<double> Ush_pool(4, false);
    Ush_pool[0] = exchange::ush1l;
    Ush_pool[1] = exchange::ush2l;
    Ush_pool[2] = exchange::ush1p;
    Ush_pool[3] = exchange::ush2p;
    QVector<double> Ushdp_pool(4, false);
    Ushdp_pool[0] = exchange::ush1dpl;
    Ushdp_pool[1] = exchange::ush2dpl;
    Ushdp_pool[2] = exchange::ush1dpp;
    Ushdp_pool[3] = exchange::ush2dpp;
    QVector<bool> PAPD_pool(4, false);
    PAPD_pool[0] = PAPD_26;
    PAPD_pool[1] = PAPD_27;
    PAPD_pool[2] = PAPD_30;
    PAPD_pool[3] = PAPD_31;
    QVector<bool> UKS_pool(4, false);
    UKS_pool[0] = uks_inst.UKS1X329;
    UKS_pool[1] = uks_inst.UKS1X330;
    UKS_pool[2] = uks_inst.UKS1X331;
    UKS_pool[3] = uks_inst.UKS1X332;
    for(int i = 0; i < 4; i++)
    {
        if(Ushdp_pool[i] >= 18.0 && Ffirst4_2920[i] && Sfirst4_2920[i])
            KSURGS[i] = true;
        else
            KSURGS[i] = false;

        if(Ush_pool[i] >= 18.0 && Ssecond4_2920[i])
            KKGS[i] = true;
        else
            KKGS[i] = false;

        if(Ushdp_pool[i] >= 18.0)
        {
            if(RVkTNUGS[i])
            {
                if(Sthird4_2920[i] == 2)
                {
                    RVkTNUGS[i] = false;
                    RVikTNUGS[i] = true;
                    PAPD_pool[i] = false;
                }
            }
            else
            {
                if(Sthird4_2920[i] == 1)
                {
                    RVkTNUGS[i] = true;
                    RVikTNUGS[i] = false;
                    PAPD_pool[i] = true;
                }
                else
                {
                    RVkTNUGS[i] = false;
                    RVikTNUGS[i] = false;
                    PAPD_pool[i] = false;
                }
            }
        }

        if(RVkTNUGS[i])
        {
            PTNUGS[i] = true;
            UKS_pool[i] = true;
        }
        else
        {
            PTNUGS[i] = false;
            UKS_pool[i] = false;
        }

        exchange::ush1l = Ush_pool[0];
        exchange::ush2l = Ush_pool[1];
        exchange::ush1p = Ush_pool[2];
        exchange::ush2p = Ush_pool[3];
        exchange::ush1dpl = Ushdp_pool[0];
        exchange::ush2dpl = Ushdp_pool[1];
        exchange::ush1dpp = Ushdp_pool[2];
        exchange::ush2dpp = Ushdp_pool[3];
        PAPD_26 = PAPD_pool[0];
        PAPD_27 = PAPD_pool[1];
        PAPD_30 = PAPD_pool[2];
        PAPD_31 = PAPD_pool[3];
        uks_inst.UKS1X329 =	UKS_pool[0];
        uks_inst.UKS1X330 =	UKS_pool[1];
        uks_inst.UKS1X331 =	UKS_pool[2];
        uks_inst.UKS1X332 =	UKS_pool[3];
    }
}
