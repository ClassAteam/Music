//#include "landinggear_4.h"
//#include "algorithms.h"
//#include <QDeadlineTimer>

//static void releasing_loop(double* delta, double* D_delta, int* tick, bool &otk);
//static void intake_loop(double* delta, double* Ddelta_racks, int* tick);

//void landinggear_int::landinggear_4() //actually 4th
//{
//    static QDeadlineTimer tsh(500);
//    static bool firsttime_emerg{true};

//    static int
//        left_tick{},
//        right_tick{},
//        nose_tick{};
//    static double
//        Ddelta_racks_rel_l,
//        Ddelta_racks_rel_p,
//        Ddelta_racks_rel_n,
//        Ddelta_racks{};

//        if (!gk_oovsh)
//        {
//            firsttime_emerg = true;
//            //Ddelta_stv toggling
//            if (exchange::pgs2 >= 130.0 && exchange::pgs2 < 280.0)
//                Ddelta_racks = two_points_to_Y(exchange::pgs2, 130.0, 280.0, 0.0, 0.125);

//            if (exchange::pgs2 >= 280.0)
//                Ddelta_racks = 0.125;

//            // release loop
//            if (gk_vsh && !gk_ush)
//            {
//                if(delta_sh_l != 1.0 && delta_stv_l == 90.0)
//                {
//                    left_tick++;
//                    //releasing left
//                    releasing_loop(&delta_sh_l, &Ddelta_racks, &left_tick, otkaz_nevip_l_opor);
//                }
//                if(delta_sh_p != 1.0 && delta_stv_p == 90.0)
//                {
//                    right_tick++;
//                    //releasing right
//                    releasing_loop(&delta_sh_p, &Ddelta_racks, &right_tick, otkaz_nevip_p_opor);
//                }
//                if(delta_sh_n != 1.0 && delta_stv_n == 90.0)
//                {
//                    nose_tick++;
//                    //releasing nose
//                    releasing_loop(&delta_sh_n, &Ddelta_racks, &nose_tick, otkaz_nevip_n_opor);
//                }

//            }

//            // intake loop
//            if(gk_ush && !gk_vsh)
//            {
//                if(delta_sh_l != 0.0 && !otkaz_nepoln_ubor_l && delta_shift_l == 0.0)
//                {
//                    left_tick++;
//                    //intake left
//                    intake_loop(&delta_sh_l, &Ddelta_racks, &left_tick);
//                }
//                if(delta_sh_p != 0.0 && !otkaz_nepoln_ubor_p && delta_shift_p == 0.0)
//                {
//                    right_tick++;
//                    //intake right
//                    intake_loop(&delta_sh_p, &Ddelta_racks, &right_tick);
//                }
//                if(delta_sh_n != 0.0 && !otkaz_nepoln_ubor_n)
//                {
//                    nose_tick++;
//                }
//                //intake nose
//                intake_loop(&delta_sh_n, &Ddelta_racks, &nose_tick);
//            }
//            else
//            {

//            }
//        }
//        else
//        // Emergency release
//        {
//            if(firsttime_emerg)
//            {
//                tsh.setRemainingTime(2000);
//                firsttime_emerg = false;
//            }

//            if(tsh.hasExpired()){
//                // emergency left release
//                if (P_bal_l >= 60.0)
//                    Ddelta_racks_rel_l = two_points_to_Y(P_bal_l, 60.0, 150.0, 0.0, 0.08);

//                if (P_bal_p >= 60.0)
//                    Ddelta_racks_rel_p = two_points_to_Y(P_bal_p, 60.0, 150.0, 0.0, 0.08);

//                if (P_bal_per >= 60.0)
//                    Ddelta_racks_rel_n = two_points_to_Y(P_bal_per, 60.0, 150.0, 0.0, 0.08);

//                // emergency left release
//                if(delta_sh_l != 1.0  && gk_avl)
//                {
//                    left_tick++;
//                    //releasing left
//                    releasing_loop(&delta_sh_l, &Ddelta_racks_rel_l, &left_tick, otkaz_nevip_l_opor);
//                }
//                if(delta_sh_p != 1.0  && gk_avp)
//                {
//                    right_tick++;
//                    //releasing right
//                    releasing_loop(&delta_sh_p, &Ddelta_racks_rel_p, &right_tick, otkaz_nevip_p_opor);
//                }
//                if(delta_sh_n != 1.0  && gk_avn)
//                {
//                    nose_tick++;
//                    //releasing nose
//                    releasing_loop(&delta_sh_n, &Ddelta_racks_rel_n, &nose_tick, otkaz_nevip_n_opor);
//                }
//            }
//        }

//    if(!gk_oovsh && !gk_vsh && !gk_ush)
//    {
//        left_tick = 0;
//        right_tick = 0;
//        nose_tick = 0;
//    }
//        //end logic
//}

//static void releasing_loop(double* delta, double* Ddelta, int* tick, bool &otk)
//{
//    if (*delta < 1 && !otk)
//    {
//        *delta = (*delta + ((*Ddelta / (1000 / TICK))));

//        if(*delta >= 1)
//        {
//            *delta = 1;
//            *tick = 0;
//        }
//    }
//}
//static void intake_loop(double* delta, double* Ddelta_racks, int* tick)
//{
//    if (*delta > 0)
//    {
//        *delta = (*delta - ((*Ddelta_racks / (1000 / TICK))));

//        if(*delta <= 0)
//        {
//            *delta = 0;
//            *tick = 0;
//        }
//    }
//}
