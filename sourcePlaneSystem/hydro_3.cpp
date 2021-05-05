#include "algorithms.h"
#include "hydro_3.h"

void hydro_int::hydro_3()
{
    bool PRNgs1_pool[] = {prn1gs1, prn2gs1};
    bool PRNgs2_pool[] = {prn1gs2, prn2gs2};
    bool PRNgs3_pool[] = {prn1gs3, prn2gs3};
    bool PRNgs4_pool[] = {prn1gs4, prn2gs4};
    double* pngs1_pool[] = {&pn1gs1, &pn2gs1};
    double* pngs2_pool[] = {&pn1gs2, &pn2gs2};
    double* pngs3_pool[] = {&pn1gs3, &pn2gs3};
    double* pngs4_pool[] = {&pn1gs4, &pn2gs4};
    double* pgs1_pool[] = {&pgs1, &pgs1};
    double* pgs2_pool[] = {&pgs2, &pgs2};
    double* pgs3_pool[] = {&pgs3, &pgs3};
    double* pgs4_pool[] = {&pgs4, &pgs4};
    for(int i = 0; i < 2; i++)
    {
        //1
        if(pgs1 >= 90)
            Kngs1[i] = 1;
        else
            Kngs1[i] = 0.16;

        if(!otkaz_gs1 && !PRNgs1_pool[i] && nVDfirst2[i] >= 7)
        {
            pnngs1[i] = true;
            l_gs1[i] = m_2_L_intervals(pgs1, 0, 200, 285, 1, 0.7, 0);
            *pngs1_pool[i] = *pgs1_pool[i];
        }
        else
        {
            pnngs1[i] = false;
            l_gs1[i] = 0;
            *pngs1_pool[i] = 0;
        }

        Qngngs1[i] = Kngs1[i] * l_gs1[i];
        Qngngs1[i] = Qngngs1[i] * nVDfirst2[i];


        //2
        if(pgs2 >= 90)
            Kngs2[i] = 1;
        else
            Kngs2[i] = 0.16;

        if(!otkaz_gs2 && !PRNgs2_pool[i] && nVDfirst2[1 - i] >= 7)
        {
            pnngs2[i] = true;
            l_gs2[i] = m_2_L_intervals(pgs2, 0, 200, 285, 1, 0.7, 0);
            *pngs2_pool[i] = *pgs2_pool[i];
        }
        else
        {
            pnngs2[i] = false;
            l_gs2[i] = 0;
            *pngs2_pool[i] = 0;
        }

        Qngngs2[i] = Kngs2[i] * l_gs2[i] * nVDfirst2[1 - i];

        //3
        if(pgs3 >= 90)
            Kngs3[i] = 1;
        else
            Kngs3[i] = 0.16;

        if(!otkaz_gs3 && !PRNgs3_pool[i] && nVDsecond2[i] >= 7)
        {
            pnngs3[i] = true;
            l_gs3[i] = m_2_L_intervals(pgs3, 0, 200, 285, 1, 0.7, 0);
            *pngs3_pool[i] = *pgs3_pool[i];
        }
        else
        {
            pnngs3[i] = false;
            l_gs3[i] = 0;
            *pngs3_pool[i] = 0;
        }

        Qngngs3[i] = Kngs3[i] * l_gs3[i] * nVDsecond2[i];

        //4
        if(pgs4 >= 90)
            Kngs4[i] = 1;
        else
            Kngs4[i] = 0.16;

        if(!otkaz_gs4 && !PRNgs4_pool[i] && nVDsecond2[1 - i] >= 7)
        {
            pnngs4[i] = true;
            l_gs4[i] = m_2_L_intervals(pgs4, 0, 200, 285, 1, 0.7, 0);
            *pngs4_pool[i] = *pgs4_pool[i];
        }
        else
        {
            pnngs4[i] = false;
            l_gs4[i] = 0;
            *pngs4_pool[i] = 0;
        }

        Qngngs4[i] = Kngs4[i] * l_gs4[i] * nVDsecond2[1 - i];

        //end logic
    }
}
