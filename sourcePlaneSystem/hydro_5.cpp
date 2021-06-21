#include "algorithms.h"
#include "hydro_5.h"


void hydro_int::hydro_5() //hydro6th
{
    static double w0gat{4.07};

    wpgat = wpgatCalc(pgs3,
                     exchange::pgat,
                     qngs3,
                     brakes.X_tp_lev,
                     brakes.X_tp_prav,
                     brakes.Pavart,
                     brakes.PstoyanT);

    if(KKGS[2]) //mb (*) ?
    {
        if(exchange::pgat >= 262)
        {
            if(wpgat <= -600)
            {
                wpgat = (-600);
            }
        }
        else
        {
            if(wpgat >= 2.28)
            {
                wpgat = 2.28;
            }
            else
            {
                if(wpgat <= -600)
                {
                    wpgat = (-600);
                }
            }
        }

    }
    else
    {
        if(wpgat >= 2.4)
        {
            wpgat = 2.4;
        }
        else
        {
            if(wpgat <= -600)
            {
                wpgat = (-600);
            }
        }
    }

    if(w0gat - wpgat != 0.0) pgat_z = (p0gat * w0gat) / (w0gat - wpgat);

    exchange::pgat = exchange::pgat + ((pgat_z - exchange::pgat) * (kgat)) * ts;

    QVector<bool> pnn1gs_pool = {pnngs1[0], pnngs2[0], pnngs3[0], pnngs4[0]};
    QVector<bool> pnn2gs_pool = {pnngs1[1], pnngs2[1], pnngs3[1], pnngs4[1]};
    bool* pntnugs_pool[] = {&pntnugs1,&pntnugs2,&pntnugs3,&pntnugs4};
    double* d_wpgs_pool[] = {&d_wpgs1, &d_wpgs2, &d_wpgs3, &d_wpgs4};
    double* pgs_pool[] = {&pgs1, &pgs2, &pgs3, &pgs4};
    double* p0gs_pool[] = {&p0gs1, &p0gs2, &p0gs3, &p0gs4};
    double* pgs_z_pool[] = {&pgs1_z, &pgs2_z, &pgs3_z, &pgs4_z};
    double* psurgs_pool[] = {&psurgs1, &psurgs2, &psurgs3, &psurgs4 };
    double* ptnugs_pool[] = {&ptnugs1,&ptnugs2,&ptnugs3,&ptnugs4};
    double* qngs_pool[] = {&qngs1, &qngs2, &qngs3, &qngs4};
    double* qpgs_pool[] = {&qpgs1, &qpgs2, &qpgs3, &qpgs4};
    double* qpsum_pool[] = {&qp1sum, &qp2sum, &qp3sum, &qp4sum};
//    double* qutgs_pool[] = {&qutgs1, &qutgs2, &qutgs3, &qutgs4};
    double* wpgs_pool[] = {&wpgs1, &wpgs2, &wpgs3, &wpgs4};
    double* w0gs_pool[] = {&w0gs1, &w0gs2, &w0gs3, &w0gs4};

    for(int i = 0; i < 4; i++)
    {
       if(KSURGS[i])
       {
           *psurgs_pool[i] = *pgs_pool[i];
       }
       else
       {
           *psurgs_pool[i] = (*psurgs_pool[i] + ( 0 - *psurgs_pool[i]) * ksur);
       }

       if(*pntnugs_pool[i] == true)
       {
           *ptnugs_pool[i] = *pgs_pool[i];
       }
       else
       {
           *ptnugs_pool[i] = *ptnugs_pool[i] + (0 - *ptnugs_pool[i] * ktnu);
       }

    }

    static double qugs[4];
    for(int i = 0; i < 4; i++)
    {
        if(i != 2)
        {
            if(pnn1gs_pool[i] || pnn2gs_pool[i] || *pntnugs_pool[i])
            {
                *qpgs_pool[i] = ((*qpsum_pool[i]) * 0.01);
                *d_wpgs_pool[i] = *qngs_pool[i] - *qpgs_pool[i];
                *wpgs_pool[i] = *wpgs_pool[i] + *d_wpgs_pool[i];

                if(KKGS[i])
                {
                    if(*wpgs_pool[i] >= 1.325)
                    {
                        *wpgs_pool[i] = 1.325;
                    }
                    else
                    {
                        if(*wpgs_pool[i] <= (-600))
                        {
                            *wpgs_pool[i] = (-600);
                        }
                    }
                }
                else
                {
                    if(*wpgs_pool[i] >= 1.395)
                    {
                        *wpgs_pool[i] = 1.395;
                    }
                    else
                    {
                        if(*wpgs_pool[i] <= (-600))
                        {
                            *wpgs_pool[i] = (-600);
                        }
                    }
                }
            }
            else
            {
                //time of falling down gs
                qugs[i] = m_2_L_intervals(*pgs_pool[i], 0, 115, 290,
                                          0.05, 0.01, 0);
                *qpgs_pool[i] = ((*qpsum_pool[i] + qugs[i]) * 0.01 * kutgs[i]);
                *d_wpgs_pool[i] = *qngs_pool[i] - *qpgs_pool[i];
                *wpgs_pool[i] = *wpgs_pool[i] + *d_wpgs_pool[i];
//                *wpgs_pool[i] = *wpgs_pool[i] + ((-100 - *wpgs_pool[i]) * 0.01);
            }
        }

        if(i != 2)
        {
            *pgs_z_pool[i] = *p0gs_pool[i] * (*w0gs_pool[i] / ((*w0gs_pool[i]) - (*wpgs_pool[i])));

            *pgs_pool[i] = *pgs_pool[i] + ((*pgs_z_pool[i] - (*pgs_pool[i])) * kgs );
        }
    }
}

double hydro_int::wpgatCalc(const double& pgs3,
                 const double& pgat,
                 const double& qngs3,
                 const double& leftPpresure,
                 const double& rightPpresure,
                 const double& alarmBreakPresure,
                 const bool& parkingBreakClue)
{
    static double kavart{0.01}, wpgat_k{}, wpgat_n{}, qngat{}, d_wpgat{}, qpts{}, result{};
    result = wpgat;
    if(pgs3 >= pgat)
    {
        wpgat_k = 0.0;
        wpgat_n = 0.0;
        qngat = qngs3;
        d_wpgat = qngat - qpts;
        result = result + d_wpgat;
        return result;
    }
    else
    {
        qngat = 0.0;
    }

//    if(parkingBreakClue && (leftPpresure/120 + rightPpresure/120) > 0.12)
    if(!parkingBreakClue && ((leftPpresure > 0.12) || (rightPpresure > 0.12)))
    {
        result = (((leftPpresure + rightPpresure)/240 + alarmBreakPresure/15)
                  * 0.25);

        if(result > wpgat_n)
            wpgat_n = result;

        result = 2.4 - (wpgat_k + wpgat_n);
    }
    else
    {
        if(((leftPpresure/120 + rightPpresure/120) < 0.12))
        {
            wpgat_k = wpgat_k + wpgat_n;
            wpgat_n = 0.0;
        }


        qpts = 0.0;
        if(parkingBreakClue)
        {
            qpts = qpts + 0.000015 * ts;
        }
        d_wpgat = qngat - qpts;
        result = result + d_wpgat - alarmBreakPresure * ts * kavart;;
    }
    return result;
}
