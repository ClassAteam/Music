#include "landinggear_2.h"
#include "algorithms.h"

static void releasing_loop(double* delta, double* D_delta, int* tick);
static void intake_loop(double* delta, double* Ddelta_racks, int* tick);

void landinggear_int::landinggear_2() //actually 2
{
    static int
        shift_left_tick{},
        shift_right_tick{};
    static double
        Ddelta_racks{},
        Ddelta_racks_l{},
        Ddelta_racks_p{};

    if(!gk_oovsh)
    {

        //Ddelta_stv toggling
        if (exchange::pgs2 >= 130.0 && exchange::pgs2 < 280.0)
            Ddelta_racks = two_points_to_Y(exchange::pgs2, 130.0, 280.0, 0.0, 0.25);

        if (exchange::pgs2 >= 280.0)
            Ddelta_racks = 0.25;

        // release loop
        if (gk_vsh && !gk_ush)
        {
            if(delta_shift_l != 1.0 && delta_stv_l == 90.0 && delta_tel_l == 1.0 &&
                delta_sh_l == 1.0 && GK_dvl && !nedovip_osn_op_l)
            {
                shift_left_tick++;
                //releasing left
                releasing_loop(&delta_shift_l, &Ddelta_racks, &shift_left_tick);
            }
            if(delta_shift_p != 1 && delta_stv_p == 90 && delta_tel_p == 1 &&
                delta_sh_p == 1 && GK_dvp && !nedovip_osn_op_p)
            {
                shift_right_tick++;
                //releasing right
                releasing_loop(&delta_shift_p, &Ddelta_racks, &shift_right_tick);
            }
        }

        // intake loop
        if (gk_ush && !gk_vsh)
        {
            if(delta_shift_l != 0 && delta_sh_l == 1)
            {
                shift_left_tick++;
                //intake left
                intake_loop(&delta_shift_l, &Ddelta_racks, &shift_left_tick);
            }
            if(delta_shift_p != 0 && delta_sh_p == 1)
            {
                shift_right_tick++;
                //intake right
                intake_loop(&delta_shift_p, &Ddelta_racks, &shift_right_tick);
            }
        }
        else
        {

        }
    }
    else
    // Emergency release
    {

        // emergency left release
        if (P_bal_l >= 60.0)
            Ddelta_racks_l = two_points_to_Y(P_bal_l, 60.0, 150.0, 0.0, 0.3);

        if (P_bal_p >= 60.0)
            Ddelta_racks_p = two_points_to_Y(P_bal_p, 60.0, 150.0, 0.0, 0.3);


        // emergency left release
        if(delta_shift_l != 1.0 && delta_stv_l == 90.0 && delta_tel_l == 1.0 &&
            delta_sh_l == 1.0 && gk_avl)
        {
            shift_left_tick++;
            //releasing left
            releasing_loop(&delta_shift_l, &Ddelta_racks_l, &shift_left_tick);
        }

        if(delta_shift_p != 1.0 && delta_stv_p == 90.0 &&
            delta_tel_p == 1.0 && delta_sh_p == 1.0 && gk_avp)
        {
            shift_right_tick++;
            //releasing right
            releasing_loop(&delta_shift_p, &Ddelta_racks_p, &shift_right_tick);
        }


    }
    if(!gk_oovsh && !gk_vsh && !gk_ush)
    {
        shift_left_tick = 0;
        shift_right_tick = 0;
    }

    //end logic
}

static void releasing_loop(double* delta, double* D_delta, int* tick)
{
    if (*delta < 1)
    {
        *delta = (*delta + ((*D_delta / (1000 / TICK))));

        if(*delta >= 1)
        {
            *delta = 1;
            *tick = 0;
        }
    }
}
static void intake_loop(double* delta, double* Ddelta_racks, int* tick)
{
    if (*delta > 0)
    {
        *delta = (*delta - ((*Ddelta_racks / (1000 / TICK))));

        if(*delta <= 0)
        {
            *delta = 0;
            *tick = 0;
        }
    }
}
