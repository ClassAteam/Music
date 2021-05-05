#include "powerdc_2_3.h"

void powerdc_int::powerdc_2_3() //2 //3
{
    static int
        tick_vsu27,
        tick_rap1,
        tick_rap11,
        tick_rap22,
        tick_rap2;

    //start logic
    if(abs(exchange::speed) < 0.1)
    {
        if(pvrap1 == true)
        {
            pprap1 = true;
            urap1 = 28.5;
        }
        else
        {
            pprap1 = false;
            urap1 = 0;
        }

        if(pvrap2 == true)
        {
            pprap2 = true;
            urap2 = 28.5;
        }
        else
        {
            pprap2 = false;
            urap2 = 0;
        }
    }
    else
    {
        pprap1 = false;
        pprap2 = false;
        urap1 = 0;
        urap2 = 0;
    }
    if(exchange::ushal >= 18.0 && pprap1 == true && s2_2430 == true)
    {
        purg27lk4 = true;
    }
    else
    {
        purg27lk4 = false;
    }

    if(exchange::ushap >= 18.0 && pprap2 == true && s9_2430 == true)
    {
        purg27pk4 = true;
    }
    else
    {
        purg27pk4 = false;
    }

    if(s13_2430 == s13_2430_pos::air)
    {
        purg27lk4 = false;
        purg27pk4 = false;
    }

    if(plp27)
    {
        if(!ppp27 && pss27)
        {
            purg27pk4 = false;
        }
    }
    else
    {
        if(ppp27 && pss27)
        {
            purg27lk4 = false;
        }
    }

    if(uak1 >= 18.0 && s14_2430 == true)
    {
        purg27lk5 = true;
    }
    else
    {
        purg27lk5 = false;
    }

    if(uak2 >= 18.0 && s15_2430 == true)
    {
        purg27pk5 = true;
    }
    else
    {
        purg27pk5 = false;
    }

    if(purg27lk4)
    {
        tick_rap1++;
        if((tick_rap1 * TICK) >= 3000)//too long timer for 2 ms
        {
            purg27lk5 = false;
        }
    }
    else
    {
        tick_rap1 = 0;
    }
    if(purg27pk4)
    {
        tick_rap2++;
        if((tick_rap2 * TICK) >= 3000)
        {
            purg27pk5 = false;
        }
    }
    else
    {
            tick_rap2 = 0;
    }
    purg27pk3 = false;
    pss27 = false;

    if(purg27lk5 == true || purg27pk5 == true)
    {
        if(!plp27 && !ppp27)
        {
            if(s7_2430)
            {
                purg27pk3 = true;
            }
            else
            {
                if(s13_2430 == s13_2430_pos::air)
                    purg27pk3 = true;
            }
        }
    }

    purg27lk1 = false;
    purg27lk7 = false;
    purg27lk9 = false;

    purg27pk1 = false;
    purg27pk7 = false;
    purg27pk9 = false;

    purg27lk6 = false;
    pshzvsu = false;

//    plp27 = false;
//    ppp27 = false;

    if(purg27lk4)
    {
        purg27lk1 = true;
        purg27lk7 = true;
        purg27lk9 = true;
//        plp27 = true;

        if(purg27pk4 == true)
        {
            tick_rap22 =0;
            purg27pk1 = true;
            purg27pk7 = true;
            purg27pk9 = true;
//            ppp27 = true;
        }
        else
        {
            if(exchange::ush1dpl >= 18.0 && s7_2430 == true)
            {
                purg27pk1 = true;
                purg27pk7 = true;
                purg27pk9 = true;
                pss27 = true;
//                ppp27 = true;

                if((tick_rap22 * TICK) >= 3000)
                {
                    purg27pk5 = false;
                }
                else
                {
                    tick_rap22++;
                }
            }
        }
    }
    else
    {
        if(purg27pk4)
        {
            purg27pk1 = true;
            purg27pk7 = true;
            purg27pk9 = true;
//            ppp27 = true;

            if(exchange::ush1dpp >= 18.0 && s7_2430 == true)
            {
                purg27lk1 = true;
                purg27lk7 = true;
                purg27lk9 = true;
                pss27 = true;
//                plp27 = true;

                if((tick_rap11 * TICK) >= 3000)
                {
                    purg27lk5 = false;
                }
                else
                {
                    tick_rap11++;
                }
            }
        }
        else
        {
            tick_rap11 = 0;
            tick_rap22 = 0;
        }
    }

    if(plp27 == true)
    {
        purg27lk1 = true;
        purg27lk7 = true;
        purg27lk9 = true;
        purg27lk5 = false;
//        purg27lk4 = false;
//        plp27 = true;

        if(ppp27)
        {
            purg27pk5 = false;
            purg27pk1 = true;
            purg27pk7 = true;
            purg27pk9 = true;
//            purg27pk4 = false;
//            ppp27 = true;
        }
        else
        {
            if(exchange::ush1dpl >= 18.0 && s7_2430)
            {
                purg27pk1 = true;
                purg27pk7 = true;
                purg27pk9 = true;
                purg27pk4 = false;
                purg27pk5 = false;
                pss27 = true;
//                ppp27 = true;
            }
        }
    }
    else
    {
        if(ppp27)
        {
            purg27pk1 = true;
            purg27pk7 = true;
            purg27pk9 = true;
            purg27pk5 = false;
//            purg27pk4 = false;
//            ppp27 = true;

            if(exchange::ush1dpp >= 18.0 && s7_2430)
            {
                purg27lk1 = true;
                purg27lk7 = true;
                purg27lk9 = true;
                purg27lk4 = false;
                purg27lk5 = false;

                pss27 = true;
//                plp27 = true;
            }


        }
    }
//    if(s13_2430 == ground)
//    {
//        if(purg27lk4 == true)
//        {
////            purg27lk5 = false;
//            purg27lk6 = false;
//            pshzvsu = true;
//        }
//        else
//        {
//            if((!purg27pk4 || !pss27))
//            {
//                if(uak1 >= 18.0 && glviklvsu && !BSS812X5t)
//                {
//                    purg27lk5 = false;
//                    purg27lk6 = true;
//                    pshzvsu = true;
//                }
//            }
//            else
//            {
////                purg27lk5 = false;
//                purg27lk6 = true;
//                pshzvsu = true;
//            }
//        }
//    }
//    else
//    {
//        if(plp27 == true)
//        {
////            purg27lk5 = false;
//            purg27lk6 = false;
//            pshzvsu = true;
//        }
//        else
//        {
//            if((!ppp27 || !pss27) )
//            {
//                if(uak1 >= 18.0 && glviklvsu && !BSS812X5t)
//                {
//                    purg27lk5 = false;
//                    purg27lk6 = true;
//                    pshzvsu = true;
//                }
//            }
//            else
//            {
////                purg27lk5 = false;
//                purg27lk6 = true;
//                pshzvsu = true;
//            }
//        }
//    }

    if(uak1 >= 18.0 && glviklvsu && !bss_inst.BSS812X5t)
    {
        purg27lk5 = false;
        purg27lk6 = true;
        pshzvsu = true;
    }

    if(plp27 == true)
    {
        ppgvsu27 = false;
        tick_vsu27 = 0;
    }
    else
    {
        if(!ppp27 || !pss27)
        {
            if(prgvsu27)
            {
                ppgvsu27 = true;

                if((tick_vsu27 * TICK) >= 3000)
                {
//                    purg27lk5 = false;
                    purg27lk1 = true;
                    purg27lk4 = false;
                    purg27lk7 = false;
                    purg27lk9 = false;

                    plp27 = true;

                    if(s7_2430 == true)
                    {
//                        purg27pk5 = false;
                        purg27pk3 = true;
                        purg27pk1 = true;
                        purg27pk4 = false;
                        purg27pk7 = false;
                        purg27pk9 = false;
                        pss27 = true;
                        ppp27 = true;
                    }
                }
                else
                {
                    tick_vsu27++;
                }
            }
            else
            {
                ppgvsu27 = false;
                tick_vsu27 = 0;
            }

        }
    }

    if(ppgvsu27 && purg27pk4)
    {
        pss27 = false;
    }

    if(prg1 || prg2)
    {
        purg27lk4 = false;
        ppgvsu27 = false;
        plp27 = true;

        purg27lk1 = true;
        purg27lk7 = true;
        purg27lk9 = true;
        plp27 = true;
    }
    else
    {
        plp27 = false;
    }

    if(prg3 || prg4)
    {
        purg27pk1 = true;
        purg27pk7 = true;
        purg27pk9 = true;
        purg27pk4 = false;

        ppp27 = true;
    }
    else
    {
        ppp27 = false;
    }

    pvkchrl = false;
    pvkchrp = false;

    if(prg1 && prg2 && s3_2430)
    {
        purg27lk7 = false;
        pvkchrl = true;
    }

    if(prg3 && prg4 && s10_2430)
    {
        purg27pk7 = false;
        pvkchrp = true;
    }
}
