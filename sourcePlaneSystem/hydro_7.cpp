#include "algorithms.h"
#include "hydro_7.h" 		//actually 8th sheet



void hydro_int::hydro_7()
{
    double* U1_pool[] = {&exchange::ush1dpl, &exchange::ush1dpl,
                         &exchange::ush1dpp, &exchange::ush1dpp};
    double* U2_pool[] = {&exchange::ushavP[2][0], &exchange::ushavP[2][0],
                         &exchange::ushavP[2][0], &exchange::ushavP[2][0]};
    bool* F_pool[] = {&F1_2930, &F1_2930, &F15_2930, &F15_2930};
    double* ppr_pool[] = {&pprgs1, &pprgs2, &pprgs3, &pprgs4};
    double* ptnugs_pool[] = {&ptnugs1, &ptnugs2, &ptnugs3, &ptnugs4};
    double* pgs_pool[] = {&pgs1, &pgs2, &pgs3, &pgs4};
    double* puks_pool[] = {&puksgs1, &puksgs2, &puksgs3, &puksgs4};
    double* psurgs_pool[] = {&psurgs1, &psurgs2, &psurgs3, &psurgs4};

    double* uks_pool1[] = {&uks_inst.UKS1X259_60, &uks_inst.UKS1X262_63,
                           &uks_inst.UKS1X264_65, &uks_inst.UKS1X267_68};

    double* uks_pool2[] = {&uks_inst.UKS1X333, &uks_inst.UKS1X334,
                           &uks_inst.UKS1X335, &uks_inst.UKS1X336};

    double* uks_pool3[] = {&uks_inst.UKS2X316, &uks_inst.UKS2X317,
                           &uks_inst.UKS2X318, &uks_inst.UKS2X319};

    double* Ushal_pool[] = {&exchange::ushal, &exchange::ushal,
                            &exchange::ushap, &exchange::ushap};

    bool* H_pool[] = {&H2_2910, &H1_2910, &H4_2910, &H5_2910};
    bool* K1_pool[] = {&K1_2930, &K2_2930, &K3_2930, &K4_2930};
    bool* K2_pool[] = {&K7_2910, &K8_2910, &K15_2910, &K18_2910};

    bool* bss812_pool[] = {&bss_inst.BSS812X5E, &bss_inst.BSS812X5G,
                           &bss_inst.BSS812X5J, &bss_inst.BSS812X5L};

    bool* bss811_pool[] = {&bss_inst.BSS811X1Z, &bss_inst.BSS811X1b,
                           &bss_inst.BSS811X1d, &bss_inst.BSS811X1f };

    bool* bss811_pool1[] = {&bss_inst.surGs1Otkl, &bss_inst.surGs2Otkl,
                            &bss_inst.surGs3Otkl, &bss_inst.surGs4Otkl };

    for(int i = 0; i < 4; i++)
    {
        if(*U1_pool[i] >= 18.0 && *U2_pool[i] >= 107.0 && *F_pool[i] == true)
        {
            *ppr_pool[i] = *pgs_pool[i];
            *puks_pool[i] = *pgs_pool[i];
        }
        else
        {
            *ppr_pool[i] = -20;
            *puks_pool[i] = 0;
        }
        *uks_pool1[i] = *puks_pool[i];
    }

    if(exchange::usho1l >= 18.0 && F14_2930)
        PK = true;

    if(exchange::S18_2930 == true)
        PKL = true;
    else
        PKL = false;

    if(exchange::ushal >= 18.0 && !K7_2910 && !K8_2910 && !K15_2910 && !K18_2910)
        bss_inst.BSS812X5N = true;
    else
        bss_inst.BSS812X5N = false;

    for(int i = 0; i < 4; i++)
    {
        if(PKL)
            *H_pool[i] = true;
        else
        {
            if(*K2_pool[i] == false && *Ushal_pool[i] >= 18.0)
                *H_pool[i] = true;
            else
                *H_pool[i] = false;
        }
    }

    if(exchange::usho1l >= 18.0 && F14_2930 && S13_2920)
        PKL1 = true;
    else
        PKL1 = false;


    for(auto& s : KKGS)
    {
        if(s)
        {
            bss_inst.BSS824X1HH = true;
            uks_inst.UKS2X340 = true;
            break;
        }
        else
        {
            bss_inst.BSS824X1HH = false;
            uks_inst.UKS2X340 = false;
        }
    }

    pa1gak = m_3_L_intervals(pgs1, 0, 115, 285, 330, 115, 115, 285, 330);
    pa2gak = m_3_L_intervals(pgs2, 0, 115, 285, 330, 115, 115, 285, 330);
    pa3gak = m_3_L_intervals(pgs3, 0, 115, 285, 330, 115, 115, 285, 330);
    pa4gak = m_3_L_intervals(pgs4, 0, 115, 285, 330, 115, 115, 285, 330);


    uks_inst.UKS2X213_14 = pa2gak;
    uks_inst.UKS2X215_8 = pa3gak;
    uks_inst.UKS2X216_9 = pa4gak;
    uks_inst.UKS2X25_6 = pa1gak;

    K1_2930 = false;
    K2_2930 = false;
    K3_2930 = false;
    K4_2930 = false;

    bss_inst.BSS811X1Z = false;
    bss_inst.BSS811X1b = false;
    bss_inst.BSS811X1d = false;
    bss_inst.BSS811X1f = false;
    bss_inst.surGs1Otkl = false;
    bss_inst.surGs2Otkl = false;
    bss_inst.surGs3Otkl = false;
    bss_inst.surGs4Otkl = false;

    H10_2930 = false;
    H11_2930 = false;
    H12_2930 = false;
    H13_2930 = false;
    uks_inst.UKS2X316 = 0;
    uks_inst.UKS2X317 = 0;
    uks_inst.UKS2X318 = 0;
    uks_inst.UKS2X319 = 0;
    bss_inst.BSS812X5E = false;
    bss_inst.BSS812X5G = false;
    bss_inst.BSS812X5J = false;
    bss_inst.BSS812X5L = false;
    uks_inst.UKS1X333 = 0;
    uks_inst.UKS1X334 = 0;
    uks_inst.UKS1X335 = 0;
    uks_inst.UKS1X336 = 0;

    for(int i = 0; i < 4; i++)
    {
        if(*Ushal_pool[i] >= 18.0)
        {
            if(*ptnugs_pool[i] >= 130.0)
            {
                *uks_pool2[i] = 1;
                *bss812_pool[i] = true;
            }
            else
            {
                if(PKL1)
                {
                    *uks_pool2[i] = 0;
                    *bss812_pool[i] = true;
                }
            }
        }

        if(*Ushal_pool[i] >= 18.0 && *pgs_pool[i] < 130.0)
        {
            *K1_pool[i] = true;
            *bss811_pool[i] = true;
            *uks_pool3[i] = 1;
        }

        if(*Ushal_pool[i] >= 18.0 && *psurgs_pool[i] < 30)
        {
            *bss811_pool1[i] = true;
        }
    }
    if(PKL)
    {
        H10_2930 = true;
        H11_2930 = true;
        H12_2930 = true;
        H13_2930 = true;
    }
}
