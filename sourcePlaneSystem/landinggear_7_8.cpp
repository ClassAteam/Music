//#include "landinggear_7_8.h"
//#include "algorithms.h"

//void landinggear_int::landinggear_7_8() //actually 7th and 8th
//{// Presure definition

//    static int
//        tick_vu1{},
//        relay_tick_sec_vu1{},
//        relay_tick_sec_vu{};

//    if(tick_vu1 * TICK >= 1000)
//        relay_tick_sec_vu++;

//    if (exchange::pgs2 >= 130.0)
//    {
//        if(gk_oovsh)
//        {
//            Plv = 30.0;
//            Plu = 30.0;
//        }
//        else
//        {
//            if(gk_vsh)
//            {
//                Plv= exchange::pgs2;
//                Plu= 30.0;
//            }
//            else
//            {
//                if(gk_ush)
//                {
//                    Plv = 30.0;
//                    Plu = exchange::pgs2;
//                }
//                else
//                {
//                    Plv = 30.0;
//                    Plu = 30.0;
//                }
//            }
//        }
//    }
//    else
//    {
//        Plv = 30.0;
//        Plu = 30.0;
//    }

//    // Presure signals
//    PSDVV = false;
//    S46_3230 = false;
//    PSDVU = false;
//    S47_3230 = false;
//    K28_3230 = false;
//    K29_3230 = false;

//    // Presure signal intake
//    if(gk_vsh)
//    {
//        if (Plv >= 130.0)
//        {
//            PSDVV = true;
//            S46_3230 = true;
//        }
//    }

//    // Presure signal release
//    if(gk_ush)
//    {
//        if(Plu >= 130.0)
//        {
//            PSDVU = true;
//            S47_3230 = true;
//        }
//    }

//    if(exchange::ush2dpl >= 19.0)
//    {
//        F16_3230 = true;
//        F13_3230 = true;
//        F113_3230 = true;

//        K2_3230 = false;
//        K3_3230 = false;
//        K22_3230 = false;

//        // clocks definition

//        switch(exchange::s2_3230)
//        {
//        case static_cast<int>(exchange::s2_3230::release):
//        {
//            if ((!PSDVV && !S3_3230))
//            {
//                tick_vu1 = 0;
//                K1_3230 = false;

//            }
//            else
//            {
//                tick_vu1++;

//                if(relay_tick_sec_vu >= 60)
//                {
//                    K1_3230 = true;
//                    relay_tick_sec_vu = 0;
//                }
//                else
//                {
//                    K1_3230 = false;
//                }
//            }
//        }
//        break;
//        case static_cast<int>(exchange::s2_3230::intake):
//        {
//            if (PSDVU || S3_3230)
//            {
//                tick_vu1++;

//                if(relay_tick_sec_vu >= 60)
//                {
//                    K1_3230 = true;
//                    relay_tick_sec_vu = 0;
//                }
//                else
//                {
//                    K1_3230 = false;
//                }
//            }
//            else
//            {
//                relay_tick_sec_vu = 0;
//                K1_3230 = false;
//            }
//        }
//        break;
//        }

//        // Landing is on
//        if (relay_tick_sec_vu >= 60.0)
//            K1_3230 = true;
//        else
//            K1_3230 = false;

//        // landing common managing if off
//        if (exchange::S1_3230 == false)
//        {
//            //release = true
//            if (exchange::s2_3230 == static_cast<int>(exchange::s2_3230::release))
//            {
//                F113_3230 = false;
//                F13_3230 = true;
//            }
//            //intake = true
//            else
//            {
//                F113_3230 = true;
//                F13_3230 = false;
//            }

//            //toggling release clue
//            if(F13_3230)
//            {
//                if(K4_3230_1211 || otkaz_ne_vikl_avt_pos_vip_shas)
//                    K22_3230 = true;
//            }

//            // additional release clues on each rack
//            if(K22_3230)
//            {
//                //left
//                if (S42_3230 && S51_3230) K2_3230 = true;
//                //left
//                if (S43_3230 && S52_3230) K3_3230 = true;
//                //right
//                if (S44_3230 && S53_3230) K28_3230 = true;
//                //right
//                if (S45_3230 && S54_3230) K29_3230 = true;
//            }
//        }

//        //voltage check 1
//        if (K22_3230 && K5_3230) F115_3230 = true;
//        else F115_3230 = false;

//        //voltage check 2
//        if (F113_3230 && K4_3230_2223) F114_3230 = true;
//        else F114_3230 = false;

//        //resolving forward voltage clues by 1st result
//        if (F115_3230)
//        {
//            K4_3230_VG = true;
//            K4_3230_1213 = true;
//            K4_3230_2223 = true;

//            K4_3230_AB = false;
//            K4_3230_1211 = false;
//            K4_3230_2221 = false;
//        }

//        //resolving forward voltage clues by 2st result
//        if (F114_3230)
//        {
//            K4_3230_VG = false;
//            K4_3230_1213 = false;
//            K4_3230_2223 = false;

//            K4_3230_AB = true;
//            K4_3230_1211 = true;
//            K4_3230_2221 = true;
//        }

//        //release mode are on or not
//        if (K22_3230 && K6_3230 && S9_3230 && S7_3230 && S5_3230 && S8_3230)
//        {
//            if(relay_tick_sec_vu1 <= 15)
//            {
//                tick_vu1++;
//                if((tick_vu1 * TICK) > 1000)
//                {
//                    relay_tick_sec_vu1++;
//                    tick_vu1 = 0;
//                }

//                if (relay_tick_sec_vu1 >= 15.0)
//                {
//                    K5_3230 = true;
//                }
//            }
//        }
//        else
//        {
//            relay_tick_sec_vu1 = 0;
//            tick_vu1 = 0;
//            K5_3230 = false;
//        }

//    }

//    // the locking resolving
//    if(F113_3230 && !K9_3230 && !K10_3230 && K8_3230_1112)
//    {
//        if(K30_3230 || (S4_3230 && S6_3230))
//        {
//            K30_3230 = true;
//            K23_3230 = true;
//        }
//        else
//        {
//            K23_3230 = false;
//        }
//    }
//    else
//    {
//        K30_3230 = false;
//        K23_3230 = false;
//    }

//    //additional intake primal racks
//    K7_3230 = false;
//    K11_3230 = false;
//    K12_3230 = false;

//    //resolving clue of additional intake
//    if(K23_3230)
//    {
//        if(S13_3230 && S15_3230)
//            K11_3230 = true;

//        if(S14_3230 && S16_3230)
//            K12_3230 = true;
//    }
//    else
//    {
//        if(F13_3230)
//        {
//            if(K8_3230_2223)
//            {
//                K8_3230_VG = true;
//                K8_3230_1112 = true;
//                K8_3230_2223 = false;
//            }
//        }
//    }

//    //clocking
//    if (K44_3230 && K45_3230 && K46_3230)
//    {
//        if(relay_tick_sec_vu1 <= 15)
//        {
//            relay_tick_sec_vu1++;
//            if((tick_vu1 * TICK) > 1000)
//            {
//                relay_tick_sec_vu1++;
//                tick_vu1 = 0;
//            }
//        }
//    }
//    else
//    {
//        relay_tick_sec_vu1 = 0;
//        tick_vu1 = 0;
//    }

//    //resolving intake mode clue
//    if (relay_tick_sec_vu1 >= 15)
//        K7_3230 = true;
//    else
//        K7_3230 = false;

//    //voltage clues by intake mode
//    if (K7_3230)
//    {
//        K8_3230_AB = true;
//        K8_3230_1112 = false;
//        K8_3230_2223 = true;
//    }


//    //voltage clues by other conditions
//    if(F13_3230 && K8_3230_2223)
//    {
//        K8_3230_VG = true;
//        K8_3230_1112 = true;
//        K8_3230_2223 = false;
//    }
//}
