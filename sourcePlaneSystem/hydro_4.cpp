#include "math.h"
#include "algorithms.h"
#include "hydro_4.h" //actually 5th



void hydro_int::hydro_4()
{
    bool* pntnugs_pool[] = {&pntnugs1, &pntnugs2, &pntnugs3, &pntnugs4};
    double* qtnugs_pool[] = {&qtnugs1, &qtnugs2, &qtnugs3, &qtnugs4};
    double* Pgs_pool[] = {&pgs1, &pgs2, &pgs3, &pgs4};
    double* qntnugs_pool[] = {&qntnugs1, &qntnugs2, &qntnugs3, &qntnugs4};
    bool* otkaz_pool[] = {&otkaz_gs1, &otkaz_gs2, &otkaz_gs3, &otkaz_gs4};

    for(int i = 0; i < 4; i++)
    {
        kutgs[i] = 1.0;
        if(*otkaz_pool[i] == false && PTNUGS[i] == true && Pv_vsu >= 1.5)
        {
            *pntnugs_pool[i] = true;
//            *qtnugs_pool[i] = m_2_L_intervals(*Pgs_pool[i], 0, 200, 282,
//                                              1, 0.7, 0);
            *qntnugs_pool[i] =
                m_2_L_intervals(*Pgs_pool[i], 0, 200, 286, 1, 0.7, 0)
                *
                m_3_L_intervals(Pv_vsu, 0, 1, 2, 3, 0, 0, 0.7, 1);
        }
        else
        {
            if(*otkaz_pool[i]) kutgs[i] = 20.0;
            *pntnugs_pool[i] = false;
            *qtnugs_pool[i] = 0;
            *qntnugs_pool[i] = 0;
        }
    }

    qngs1 = Qngngs1[0] + Qngngs1[1] + qntnugs1;
    qngs2 = Qngngs2[0] + Qngngs2[1] + qntnugs2;
    qngs3 = Qngngs3[0] + Qngngs3[1] + qntnugs3;
    qngs4 = Qngngs4[0] + Qngngs4[1] + qntnugs4;

    if(pnngs3[0] || pnngs3[1] || pntnugs3)
    {
        qpgs3 = (qp3sum) * 0.01;
        delta_wpgs3 = qngs3 - qpgs3;
        wpgs3 = wpgs3 + delta_wpgs3;

        if(KKGS[2])
        {
            if(wpgs3 >= 1.325)
            {
                wpgs3 = 1.325;
            }
            else
            {
                if(wpgs3 <= (-600))
                {
                    wpgs3 = (-600);
                }
            }
        }
        else
        {
            if(wpgs3 >= 1.395)
            {
                wpgs3 = 1.395;
            }
            else
            {
                if(wpgs3 <= (-600))
                {
                    wpgs3 = (-600);
                }
            }
        }
    }
    else
    {
        //instead 0.01 should be utechki first
        static double qugs3;
        qugs3 = m_2_L_intervals(pgs3, 0, 115, 290, 0.05, 0.01, 0);
        qpgs3 = (qp3sum + qugs3) * 0.01 * kutgs[2];
        delta_wpgs3 = qngs3 - qpgs3;
        wpgs3 = wpgs3 + delta_wpgs3;
        //        wpgs3 = wpgs3 + ((-100 - wpgs3) * 0.01);
    }

    pgs3_z = p0gs3 * (w0gs3 / (w0gs3 - wpgs3));
    pgs3 = pgs3 + ((pgs3_z - pgs3) * kgs);
}
