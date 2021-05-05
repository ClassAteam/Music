#include "powerdc_5_6.h"


void powerdc_int::powerdc_5_6() //5 6
{
    allElConsDir_inst.makeCorresCurr();

    // start logic
//    inshal = k1_2420 * 15 + k2_2420 * 15
//             + (por1kz || prr1kz || psr1kz) * 10
//             + (por1kpr || prr1kpr || psr1kpr) * 10
//             + (por1kpchk || prr1kpchk) * 10 + k4_4940 * 30
//             + s1_4940 * 30 + prn1gs1 * 3 + prn2gs1 * 3
//             + prn1gs2 * 3 + prn2gs2 * 3 + pbutzo * 8;

//    insh1dpl = poppd1 * 10 + landinggear_inst.gk_avn * 8 + k1_17723 * 20 + s1_11028 * 5
//               + s1_11313 * 5;

//    insh2dpl = k1_2250 * 10 + s1_11052 * 5 + (k14_2420 && k15_2420) * 70;

//    insh1l = k2_7322 * 15 + k9_7322 * 15 + k1_11038 * 5 + s1_11081 * 7;

//    insh2l = k3_2250 * 10 + poppd3 * 10 + k3_3650 * 7 + k4_7322 * 15
//             + k11_7322 * 15 + r865gd * 15;

//    insho1l = k5_2250 * 10 + y1_3650 * 7 + y2_3650 * 7;

//    insho2l = k1_17723 * 7;

//    inshap = k7_2420 * 15 + k8_2420 * 15 + (por2kz || prr2kz || psr2kz) * 10
//             + (por2kpr || prr2kpr || psr2kpr) * 10
//             + (por2kpchk || prr2kpchk) * 10 + prn1gs3 * 3
//             + prn2gs3 * 3 + prn1gs4 * 3 + prn2gs4 * 3
//             + landinggear_inst.gk_avl * 12 + landinggear_inst.gk_avp * 12 + k18_7322 * 10;

//    insh1dpp = k11_2250 * 10 + poppd2 * 9 + pbutzr * 8 + s1_11028 * 5;

//    insh2dpp = s1_11081 * 7 + s2_11052 * 5 + (k30_2420 && k31_2420) * 70;

//    insh1p = k3_7322 * 15 + k8_7322 * 15 + k2_11038 * 5;

//    insh2p = k8_2250 * 10 + prsop * 15 + k5_7322 * 15 + k10_7322 * 15
//             + k2_17723 * 20;

//    insho1p = f32_3020 * 2 + f319_3020 * 2 + f356_3020 * 2 + f353_3020 * 2;

//    insho2p = k1_17723 * 7;

//    if(exchange_inst.ushzvsu >= 18.0)
//    {
//        if(apdvsu_35)
//        {
//            inshzvsu = 600 - 0.14 * nvsu;
//        }
//        else
//        {
//            if(apdvsu_49)
//            {
//                inshzvsu = 250.0;
//            }
//            else
//            {
//                inshzvsu = 0;
//            }
//        }
//    }
//    else
//    {
//        inshzvsu = 0;
//    }

//    if(!purg27lk9)
//    {
//        inshal = (inshal + insh1dpl + insh2dpl);
//    }
//    if(!purg27pk9)
//    {
//        inshap = (inshap + insh1dpp + insh2dpp);
//    }

//    if(purg27lk6)
//    {
//        iak1 = inshzvsu;
//    }
//    else
//    {
//        if(!s14_2430)
//            iak1 = 0;
//        else
//        {
//            if(pvkgvsu27)
//            {
//                iak1 = 0.013 * (ea1 - exchange_inst.ushal) /ra1;
//            }
//            else
//            {
//                if(purg27lk4)
//                    iak1 = 0;
//                else
//                {
//                    if(plp27)
//                    {
//                        iak1 = 0.013 * (ea1 - exchange_inst.ushal) / ra1; //what is the order
//                    }
//                    else
//                    {
//                        if(ppp27)
//                        {
//                            if(pss27)
//                                iak1 = 0.013 * (ea1 - exchange_inst.ushal) / ra1;
//                            else
//                            {
//                                iak1 = inshal;
//                            }
//                        }
//                        else
//                        {
//                            if(!purg27pk3)
//                                iak1 = inshal;
//                            else
//                            {
//                                if(purg27pk5)
//                                    iak1 = (inshal + inshap) / 2;
//                                else
//                                    iak1 = (inshal + inshap);
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }

//    if(!s15_2430)
//        iak2 = 0;
//    else
//    {
//        if(pvkgvsu27 && purg27pk3)
//        {
//            iak2 = 0.013 * (ea2 - exchange_inst.ushap) / ra2;
//        }
//        else
//        {
//            if(purg27pk4)
//                iak2 = 0;
//            else
//            {
//                if(ppp27)
//                    iak2 = 0.013 * (ea2 - exchange_inst.ushap) / ra2;
//                else
//                {
//                    if(plp27)
//                    {
//                        if(pss27)
//                            iak2 = 0.013 * (ea2 - exchange_inst.ushap) / ra2;
//                        else
//                        {
//                            iak2 = inshap;
//                        }
//                    }
//                    else
//                    {
//                        if(!purg27pk3)
//                            iak2 = inshap;
//                        else
//                        {
//                            if(!purg27lk5)
//                                iak2 = inshal + inshap;
//                            else
//                                iak2 = (inshal + inshap) / 2;
//                        }
//                    }
//                }
//            }
//        }
//    }

////    else
////    {
////        inshal = inshal + insh1dpl + insh2dpl;
////    }

//    if(purg27pk9)
//    {
//        insh1p = insh1p + insh1dpp + insh2dpp;
//    }
////    else
////    {
////        inshap = inshap + insh1dpp + insh2dpp;
////    }

//    insl27 = insh1l + insh2l;

//    insp27 = insh1p + insh2p;

//    if(plp27)
//    {
//        insl27 = insl27 + inshal;
//    }

//    if(ppp27)
//    {
//        insp27 = insp27 + inshap;
//    }

//    if(purg27lk1)
//    {
//        insl27 = insl27 + inshal;
//    }

//    if(purg27pk1)
//    {
//        insp27 = insp27 + inshap;
//    }

//    if(purg27lk7)
//    {
//        insl27 = insl27  + insho1l + insho2l;
//    }
//    if(purg27pk7)
//    {
//        insp27 = insp27 + insho1p + insho2p;
//    }

//    irap1 = 0;
//    irap2 = 0;

//    if(purg27lk4)
//    {
//        irap1 = (inshal + insh1l + insh2l);

//        if(!purg27pk4 && pss27)
//        {
//            irap1 = irap1 + insh1p + insh2p;
//        }
//    }

//    if(purg27pk4)
//    {
//        irap2 = inshap + insh1p + insh2p;

//        if(!purg27lk4 && pss27)
//        {
//            irap2 = irap2 + insh1l + insh2l;
//        }
//    }

//    urap1 = 28.5 - 0.003 * irap1;

//    urap2 = 28.5 - 0.003 * irap2;

//    ivsu_27 = 0;

//    if(ppgvsu27)
//    {
//        ivsu_27 = inshal + insl27;

//        if(pss27)
//        {
//            ivsu_27 = ivsu_27  + inshap + inpp27;
//        }
//    }

//    ing1_27 = 0;
//    ing2_27 = 0;
//    ing3_27 = 0;
//    ing4_27 = 0;

//    if(prg1)
//    {
//        if(pss27)
//        {
//            ing1_27 = ((insl27 + insp27) / (prg1 + prg2 + prg3 + prg4));
//        }
//        else
//        {
//            ing1_27 = insl27 / (prg1 + prg2);
//        }
//    }

//    if(prg2)
//    {
//        if(pss27)
//        {
//            ing2_27 = ((insl27 + insp27) / (prg1 + prg2 + prg3 + prg4));
//        }
//        else
//        {
//            ing2_27 = insl27 / (prg1 + prg2);
//        }
//    }

//    if(prg3)
//    {
//        if(pss27)
//        {
//            ing3_27 = ((insl27 + insp27) / (prg1 + prg2 + prg3 + prg4));
//        }
//        else
//        {
//            ing3_27 = insp27 / (prg3 + prg4);
//        }
//    }
//    if(prg4)
//    {
//        if(pss27)
//        {
//            ing4_27 = ((insl27 + insp27) / (prg1 + prg2 + prg3 + prg4));
//        }
//        else
//        {
//            ing4_27 = insp27 / (prg3 + prg4);
//        }
//    }
}
