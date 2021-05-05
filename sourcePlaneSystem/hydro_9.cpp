#include "hydro_9.h"

void hydro_int::hydro_9()
{

    //start logic
    bool* prd_pool[] = {&exchange::PRD1dv, &exchange::PRD2dv,
                        &exchange::PRD3dv,&exchange::PRD4dv};
    bool* K1_pool[] = {&K1_2935, &K2_2935, &K10_2935, &K11_2935};
    bool* F17_pool[] = {&F17_2805, &F77_2805, &F97_2805, &F117_2805};
    bool* F122_pool[] = {&F122_2845, &F427_2845, &F429_2845, &F124_2845};
    bool* K4_pool[] = {&K4_2935, &K7_2935, &K9_2935, &K13_2935};
    double* Ush2l_pool[] = {&exchange::ush2l, &exchange::ush2l,
                            &exchange::ush2l, &exchange::ush2l};
    bool* K3_pool[] = {&K3_2935, &K6_2935, &K8_2935, &K12_2935};
    for(int i = 0; i < 4; i++)
    {
        m_switch(prd_pool[i], K1_pool[i]);
        m_DoubleTrueAnd(F17_pool[i], F122_pool[i], K4_pool[i]);

        if(*Ush2l_pool[i] >= 18.0 && *K4_pool[i] == true)
            *K3_pool[i] = true;
        else
            *K3_pool[i] = false;
    }

    if(exchange::ush2l >= 18.0)
    {
        if(exchange::K26_3230)
        {
            if(K5_2935)
                K5_2935 = true;
        }
        else
        {
            if((K1_2935 && !K4_2935) || (K2_2935 && !K7_2935) ||
                    (K10_2935 && !K9_2935) || (K11_2935 && !K13_2935))
                K5_2935 = true;
            else
            {
                if(K5_2935) K5_2935 = true;
            }
        }
    }
    else
        K5_2935 = false;

    m_DoubleTrue(&landinggear_int::S18_2930, &K5_2935, &H1_2935);

    if(exchange::ush2l >= 18.0)
    {
        if(K6_2935 || K3_2935 || (!K1_2935 && !K2_2935))
        {
            if(K8_2935 || K12_2935 || (!K10_2935 && !K12_2935))
            {
                bss_inst.BSS811X1N = false;
                bss_inst.BSS824X1b = false;
            }
            else
            {
                bss_inst.BSS811X1N = true;
                bss_inst.BSS824X1b = true;
            }
        }
        else
        {
            if(!K3_2935)
            {
                if(K1_2935 || K2_2935)
                {
                    bss_inst.BSS811X1N = true;
                    bss_inst.BSS824X1b = true;
                }
                else
                {
                    bss_inst.BSS811X1N = false;
                    bss_inst.BSS824X1b = false;
                }
            }
            else
            {
                bss_inst.BSS811X1N = false;
                bss_inst.BSS824X1b = false;
            }
        }
    }
}
    //end logic
