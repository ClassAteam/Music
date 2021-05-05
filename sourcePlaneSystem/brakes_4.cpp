#include "brakes_4.h"

void brakes_int::brakes_4()
{
    //    delta_Ptr = (two_points_to_Y(V_kh, 0, 89, 100, 30) * (TICK / 1000));
    delta_Ptr = (two_points_to_Y(vkh, 0, 89, 100, 30));

    for(int i = 0; i <= 5; i++)
    {
        if(i < 3)
            brakes_Ptr[i] = P_t_lev;
        if(i >= 3)
            brakes_Ptr[i] = P_t_prav;
    }

    brakes_Vsvk[0] = *std::max_element(brakes_Vk.begin(), brakes_Vk.begin() + 2);
    brakes_Vsvk[1] = *std::max_element(brakes_Vk.begin() + 2, brakes_Vk.end());

    brakes_DVsvk[0] = brakes_Vsvk[0] - brakes_Vsvk_p[0];
    brakes_DVsvk[1] = brakes_Vsvk[1] - brakes_Vsvk_p[1];

    int j = 0;
    for(int i = 0; i <= 5; i++)
    {
        if(i == 3) j++;

        if(otkaz_ots_dav_v1k_levt)
            brakes_Pt[0] = 0;

        if(otkaz_ots_dav_v1k_pravt)
            brakes_Pt[3] = 0;

        if(brakes_DVsvk[j] >= 0.0)
            brakes_Vsvk_p[j] = brakes_Vsvk[j];
        else
        {
            if(abs(brakes_DVsvk[j]) >= 11.0)
            {
                brakes_Vsvk[j] = brakes_Vsvk_p[j] - 11;
                brakes_Vsvk_p[j] = brakes_Vsvk[j];
            }
            else
                brakes_Vsvk_p[j] = brakes_Vsvk[j];
        }

        if(brakes_PRAT[i])
            brakes_Pt[i] = brakes_Pt[i] - brakes_DPavt[i] * (TICK / 1000);
        else
        {
            brakes_DPavt[i] = 0;
            brakes_DPt[i] = (brakes_Ptr[i] - brakes_Pt[i]) ;

            if(abs(brakes_DPt[i]) >= (delta_Ptr * 0.3))
            {
                if(brakes_DPt[i] >= 0 && (exchange::pgs2 >= 130.0 || exchange::pgs3 >= 130.0))
                    brakes_Pt[i] = brakes_Pt[i] + delta_Ptr * (TICK / 1000);
                else
                    brakes_Pt[i] = brakes_Pt[i] - delta_Ptr * (TICK / 1000);
            }
            else
                brakes_Pt[i] = brakes_Ptr[i];
        }

        if(brakes_Pt[i] >= 0)
        {
            if(POSH1)
                brakes_Vkr[i] = vkh - (brakes_K1[i] * brakes_Pt[i]);
            else
                brakes_Vkr[i] = brakes_Vk_p[i] - brakes_K1[i] * brakes_Pt[i] - (50 * (TICK / 1000));
        }
        else
            brakes_Pt[i] = 0;

        if(brakes_Vkr[i] <= 0.01)
            brakes_Vkr[i] = 0;

        brakes_DVk[i] = ((brakes_Vkr[i] - brakes_Vk_p[i]) * K2);

        if(brakes_DVk[i] > (-0.01) && brakes_DVk[i] < 0.01)
            brakes_DVk[i] = 0;

        brakes_Vk[i] = brakes_Vk_p[i] + brakes_DVk[i];
        brakes_Wk[i] = K3 * brakes_Vk[i];

        brakes_Vk_p[i] = brakes_Vk[i];
        brakes_Wk_p[i] = brakes_Wk[i];

        brakes_Wsvk[j] = K3 * brakes_Vsvk[j];
        brakes_Wsvk_p[j] = brakes_Wsvk[j];

        if(brakes_Vsvk[j] >= 8.3 && brakes_Vsvk[j] <= 83)
        {
            brakes_Sk[i] = ((brakes_Wsvk[j] - brakes_Wk[i]) / brakes_Wsvk[j]);

            S_ogr1 = 0.22 - (0.001 * brakes_Vsvk[j]);

            if(brakes_Sk[i] > S_ogr1)
                brakes_PK1[i] = true;
            else
            {
                if((brakes_DVk[i] - brakes_DVsvk[j]) > 2.7)
                    brakes_PK1[i] = true;
                else
                    brakes_PK1[i] = false;
            }

            S_ogr3 = 0.3 - (0.001 * brakes_Vsvk[j]);

            if(brakes_Sk[i] > S_ogr3)
                brakes_PK2[i] = true;
            else
            {
                if(brakes_Sk[i] < ((0.1 * brakes_DVk[i]) / brakes_DVsvk[j]))
                    brakes_PK2[i] = false;
            }

            if(brakes_Sk[i] > 0.5)
            {
                brakes_PRAT[i] = true;
                brakes_DPavt[i] = brakes_Pt[i];
            }
            else
            {
                if(brakes_PK1[i] || brakes_PK2[i])
                {
                    brakes_PK5[i] = true;

                    if(PAVT_N)
                        brakes_DPavt[i] = 10;
                    else
                    {
                        if(PAVT_P == true)
                            brakes_DPavt[i] = 8;
                        else
                        {
                            if(PAVT_S == true)
                                brakes_DPavt[i] = 6;
                            else
                            {
                                if(PFT)
                                    brakes_DPavt[i] = 15;
                                else
                                {
                                    if(PAVART)
                                        brakes_DPavt[i] = 0;
                                    else
                                        brakes_DPavt[i] = 12;
                                }
                            }
                        }
                    }

                    if(brakes_PK5[i])
                    {
                        brakes_Pkv[i] = brakes_Pt[i];
                        brakes_DPavt[i] = 0.1 * brakes_Pkv[i];
                    }
                    else
                        brakes_Pkv[i] = brakes_Pkv[i] - brakes_DPavt[i];

                    if(brakes_PK2[i] || brakes_PK5[i])
                    {
                        brakes_DPavt[i] = brakes_Pt[i];
                        brakes_PRAT[i] = true;

                    }
                }
                else
                {
                    if(brakes_PRAT[i])
                    {
                        brakes_DPavt[i] = brakes_Pt[i] - brakes_Pkv[i];
                        brakes_PRAT[i] = false;
                        brakes_PK5[i] = false;
                    }
                }
            }
        }
        else
        {
            brakes_PK1[i] = false;
            brakes_PK2[i] = false;
            brakes_PRAT[i] = false;
            brakes_PK5[i] = false;
            brakes_Sk[i] = false;
        }
    }
}

    //end logic
