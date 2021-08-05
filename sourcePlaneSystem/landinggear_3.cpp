//#include "landinggear_3.h"
//#include "algorithms.h"

//static void releasing_loop(double* delta, double* D_delta, int* tick);
//static void intake_loop(double* delta, double* Ddelta_racks, int* tick);

//void landinggear_int::landinggear_3() //actually 3
//{
//    static int carts_left_tick{}, carts_right_tick{};
//    //Ddelta_stv toggling
//    //    if (Pgs2 >= 130.0 && Pgs2 < 280.0)
//    //    {
//    //        Ddelta_tel = two_points_to_Y(Pgs2, 130.0, 280.0, 0.0, 0.25);
//    //    }
//    //    if (Pgs2 >= 280.0)
//    //    {
//    //        Ddelta_tel = 0.25;
//    //    }
//    static double Ddelta_tel{0.25};

//    if(!gk_oovsh)
//    {
//        // release loop
//        if(gk_vsh && !gk_ush)
//        {
//            if(delta_tel_l != 1.0 && delta_stv_l == 90.0 && delta_sh_l > 0.4)
//            {
//                carts_left_tick++;
//                //releasing left
//                releasing_loop(&delta_tel_l, &Ddelta_tel, &carts_left_tick);
//            }
//            if(delta_tel_p != 1 && delta_stv_p == 90 && delta_sh_p > 0.4)
//            {
//                carts_right_tick++;
//                //releasing right
//                releasing_loop(&delta_tel_p, &Ddelta_tel, &carts_right_tick);
//            }


//        }

//        // intake loop
//        if (gk_ush && !gk_vsh)
//        {
//            if(delta_tel_l != 0.0 && delta_sh_l < 0.65)
//            {
//                carts_left_tick++;
//                //intake left
//                intake_loop(&delta_tel_l, &Ddelta_tel, &carts_left_tick);
//            }
//            if(delta_tel_p != 0.0 && delta_sh_p < 0.65)
//            {
//                carts_right_tick++;
//                //intake right
//                intake_loop(&delta_tel_p, &Ddelta_tel, &carts_right_tick);
//            }
//        }
//        else
//        {

//        }
//    }
//    else
//    // Emergency release
//    {
//        // emergency left release
//        if(delta_tel_l != 1  && delta_sh_l >= 0.4)
//        {
//            carts_left_tick++;
//            //releasing left
//            releasing_loop(&delta_tel_l, &Ddelta_tel, &carts_left_tick);
//        }

//        if(delta_tel_p != 1  && delta_sh_p >= 0.4)
//        {
//            carts_right_tick++;
//            //releasing right
//            releasing_loop(&delta_tel_p, &Ddelta_tel, &carts_right_tick);
//        }
//    }

//    //end logic
//}
//static void releasing_loop(double* delta, double* D_delta, int* tick)
//{
//    if (*delta < 1)
//    {

//        *delta = (*delta + ((*D_delta / (1000 / TICK))));

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

