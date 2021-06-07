#include "powerdc_1.h"

void powerdc_int::powerdc_1() //1
{
    allElConsDir_inst.makeCorresCurr();
static int
    tickg1, tickg2, tickg3, tickg4, tickvsu;
    //start logic
    bool* otkaz_pool[] = {&OtkazGen1PostT, &OtkazGen2PostT, &OtkazGen3PostT,
                          &OtkazGen4PostT, &OtkazGenVsu};
    double* ng_pool[] = {&ng1_27, &ng2_27, &ng3_27, &ng4_27, &ngvsu_27};
    double* ug_pool[] = {&ug1_27, &ug2_27, &ug3_27, &ug4_27, &ugvsu27};
    double* uzg_pool[] = {&uzg1_27, &uzg2_27, &uzg3_27, &uzg4_27, &uzgvsu_27};
    double* divg_pool[] = {&divg1_27, &divg2_27, &divg3_27, &divg4_27, &divgvsu27};
    double* ivg_pool[] = {&ivg1_27, &ivg2_27, &ivg3_27, &ivg4_27, &ivgvsu27};
    double* ing_pool[] = {&ing1_27, &ing2_27, &ing3_27, &ing4_27, &ingvsu_27};
//    double* ugrr_pool[] = {&ugrr, &ugrr, &ugrr, &ugrr, &ugrrvsu};
    double* ugr_pool[] = {&ug1r_27, &ug2r_27, &ug3r_27, &ug4r_27, &ugrvsu27};

    double* nvd_pool[] = {&hydro_int::nVDfirst2[0], &hydro_int::nVDfirst2[1],
                          &hydro_int::nVDsecond2[0], &hydro_int::nVDsecond2[1], &nvsu};

    double* krg_pool[] = {&krg, &krg, &krg, &krg, &krgvsu};
    double* kg_pool[] = {&kg1, &kg1, &kg1, &kg1, &kgvsu};
    bool* s4_pool[] = {&exchange::s4_2430, &exchange::s5_2430, &exchange::s8_2430, &exchange::s11_2430};
    bool* pvkg_pool[] = {&pvkg1, &pvkg2, &pvkg3, &pvkg4, &pvkgvsu27};
    bool* pbg_pool[] = {&pbg1, &pbg2, &pbg3, &pbg4, &pbgvsu27};
    bool* prg_pool[] = {&prg1, &prg2, &prg3, &prg4, &prgvsu27};
    int * tick_pool[] = {&tickg1, &tickg2, &tickg3, &tickg4, &tickvsu};
    double* ushal_pool[] = {&exchange::ushal, &exchange::ushal,
                            &exchange::ushap, &exchange::ushap};

    for(int i = 0; i < 5; i++)
    {
        if(*otkaz_pool[i])
        {
            *ng_pool[i] = (*ng_pool[i] + (0 - *ng_pool[i]) / kn1);
        }
        else
        {
            if(abs(*ugr_pool[i] - *uzg_pool[i]) >= 0.05)
            {
                *divg_pool[i] = m_3_L_intervals((*ugr_pool[i] - *uzg_pool[i]),
                                                -50, -10, 10, 50,
                                                0.1, 0.1, -0.1, -0.1);
            }
            else
            {
                *divg_pool[i] = 0.0;
            }

            *ivg_pool[i] = *ivg_pool[i] + *divg_pool[i];

            if(*ivg_pool[i] >= 0.5)
            {
                *ivg_pool[i] = 0.5;
            }

            if(*ivg_pool[i] <= 0.1)
            {
                *ivg_pool[i] = 0.1;
            }

            *ng_pool[i] = (*ng_pool[i] + (*nvd_pool[i] - *ng_pool[i]) / kn1);

//            *ugrr_pool[i] = m_2_L_intervals(*ng_pool[i], 0, 50, 110,
//                                            0, 28.5, 28.5);

//            *ugr_pool[i] = *ugrr_pool[i] * (*kg_pool[i] * (*ivg_pool[i])
//                                         - (*ing_pool[i] * (*krg_pool[i])));

            *ugr_pool[i] = *ng_pool[i] * (*kg_pool[i] * (*ivg_pool[i])
                                         - (*ing_pool[i] * (*krg_pool[i])));

            *ug_pool[i] = *ug_pool[i] + ((*ugr_pool[i] - (*ug_pool[i])) * kg10);
        }
    }

    if(exchange::ushal >= 18.0 && exchange::s1_2430 == true && bss_inst.BSS812X5t == true)
    {
        pvkgvsu27 = true;
    }
    else
    {
        pbgvsu27 = false;
        pvkgvsu27 = false;
    }

    for(int i = 0; i < 4; i++)
    {
        if(*ushal_pool[i] >= 18.0 && (*s4_pool[i]) == true)
        {
            *pvkg_pool[i] = true;
        }
        else
        {
            *pvkg_pool[i] = false;
            *pbg_pool[i] = false;
        }
    }
    for(int i = 0; i < 5; i++)
    {
        if(*pbg_pool[i])
        {
            *prg_pool[i] = false;
        }
        else
        {
            if(*ug_pool[i] > 22.0 && *ug_pool[i] < 32.0 && ((TICK * (*tick_pool[i])) < 6000))
            {
                if(*pvkg_pool[i])
                {
                    *prg_pool[i] = true;
                }
                else
                {
                    *prg_pool[i] = false;
                }
            }
            else
            {
                (*tick_pool[i])++;
                if(TICK * (*tick_pool[i]) >= 6000)
                {
                    *tick_pool[i] = 0;
                    *pbg_pool[i] = true;
                }
            }
        }
    }

    bool* pa_pool[] = {&pa1, &pa2};
    double* qa_pool[] = {&qa1, &qa2};
    double* ea_pool[] = {&ea1, &ea2};
    double* iak_pool[] = {&iak1, &iak2};
    double* uzak_pool[] = {&uz1ak, &uz2ak};
    double* urak_pool[] = {&ur1ak, &ur2ak};
    double* uoak_pool[] = {&uo1ak, &uo2ak};
    double* uak_pool[] = {&uak1, &uak2};
    double* ra_pool[] = {&ra1, &ra2};
    double* ush_pool[] = {&exchange::ushal, &exchange::ushap};
    bool* purg27lk_pool[] = {&purg27lk4, &purg27pk4};

    for(int i = 0; i < 2; i++)
    {

        if(*ea_pool[i] > 18.0)
        {
            *pa_pool[i] = true;

            *uzak_pool[i] = *ush_pool[i];
//            *uzak_pool[i] = *uak_pool[i] + 2.5;

            if(*iak_pool[i] >= 0)
            {
                *qa_pool[i] = *qa_pool[i] - (*iak_pool[i] / 3600) * (TICK / 1000);
            }
            else
            {
                *qa_pool[i] = *qa_pool[i] - 0.857 * (*uzak_pool[i] / *uak_pool[i])
                                                * ((*iak_pool[i] / 3600) * (TICK / 1000));
            }

            *uoak_pool[i] = m_5_L_intervals((*qa_pool[i]),
                                            0, 5, 10, 20, 30, 40,
                                            0, 23.9, 24.0, 24.4, 24.8, 25.54);

            if(*pa_pool[i] == true && (*uzak_pool[i] > *ea_pool[i]))
            {
                if(!(*purg27lk_pool[i]))
                {
                    if((*uzak_pool[i] - *uoak_pool[i]) >= 2.5)
                    {
                        *urak_pool[i] = *urak_pool[i] + 0.001 *
                                                            ((25 - *urak_pool[i]) * (TICK / 1000));
                    }
                    else
                    {
                        *urak_pool[i] =
                            *urak_pool[i] + 0.01 * ((*uzak_pool[i] - *uoak_pool[i] - *urak_pool[i])
                                                    * (TICK / 1000));
                    }
                }
                else
                {
                    *qa_pool[i] = m_5_L_intervals((*uak_pool[i]),
                                               0, 23.9, 24.0, 24.4, 24.8, 25.54,
                                               0.0, 5.0, 10.0, 20.0, 30.0, 40.0 );
                    *urak_pool[i] =
                        *urak_pool[i] + 0.001 * (((-(*uzak_pool[i])) + *uoak_pool[i] - *urak_pool[i])
                                                * (TICK / 1000));
                }
            }
            else
            {
                *urak_pool[i] = *urak_pool[i] * (1 - ((TICK / 1000) / 30));
            }

            *ea_pool[i] = *uoak_pool[i] + *urak_pool[i];
            if(*ea_pool[i] >= 25.54) *ea_pool[i] = 25.54;

            if(*qa_pool[i] >= 40.0)
            {
                *qa_pool[i] = 40.0;
            }
            if(*qa_pool[i] <= 0.5)
            {
                *qa_pool[i] = 0.5;
            }

        }
        else
        {
            if(*pa_pool[i] == true)
            {
                if(*ea_pool[i] > 10.0)
                {
                    *pa_pool[i] = true;
                }
                else
                {
                    *pa_pool[i] = false;
                }
            }
        }

        *ra_pool[i] = m_4_L_intervals((*qa_pool[i]),
                                        5, 10, 20, 30, 40,
                                        0.5, 0.035, 0.0175, 0.0116, 0.009);

        *uak_pool[i] = *ea_pool[i] - (*iak_pool[i] * (*ra_pool[i]));

    }
}
