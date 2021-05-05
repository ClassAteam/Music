#include "landinggear_1.h"
#include "algorithms.h"

static void releasing_loop(double* delta, double* Ddelta, int* tick);
static void intake_loop(double* delta, double* Ddelta, int* tick);

void landinggear_int::landinggear_1()	//sashes
{
    static QDeadlineTimer tsash(500);
    static bool firsttime_emerg{true};

    static int
        left_tick{},
        right_tick{},
        nose_tick{};

    static double
        Ddelta_stv{}, //changing state by seconds
        Ddelta_stv_l{},//speed of changing left sashe
        Ddelta_stv_p{},//speed of changing righ sashe
        Ddelta_stv_n{};//speed of changing nose sashe

    if (!gk_oovsh)
    {
        firsttime_emerg = true;
        //Ddelta_stv toggling
        if (exchange::pgs2 >= 130.0 && exchange::pgs2 < 280.0)
            Ddelta_stv = two_points_to_Y(exchange::pgs2, 130.0, 280.0, 0.0, 45.0);

        if (exchange::pgs2 >= 280.0)
            Ddelta_stv = 45.0;

        // release loop
        if (gk_vsh && !gk_ush)
        {
            if(delta_stv_l != 90.0)
            {
                left_tick++;
                //releasing left
                releasing_loop(&delta_stv_l, &Ddelta_stv, &left_tick);
            }
            if(delta_stv_p != 90.0)
            {
                right_tick++;
                //releasing right
                releasing_loop(&delta_stv_p, &Ddelta_stv, &right_tick);
            }
            if(delta_stv_n != 90.0)
            {
                nose_tick++;
                //releasing nose
                releasing_loop(&delta_stv_n, &Ddelta_stv, &nose_tick);
            }

        }

        // intake loop
        if (gk_ush && !gk_vsh)
        {
            if(delta_stv_l != 0.0 && delta_sh_l == 0.0)
            {
                left_tick++;
                //intake left
                intake_loop(&delta_stv_l, &Ddelta_stv, &left_tick);
            }
            if(delta_stv_p != 0.0 && delta_sh_p == 0.0)
            {
                right_tick++;
                //intake right
                intake_loop(&delta_stv_p, &Ddelta_stv, &right_tick);
            }
            if(delta_stv_n != 0.0 && delta_sh_n == 0.0)
            {
                nose_tick++;
                // intake nose
                intake_loop(&delta_stv_n, &Ddelta_stv, &nose_tick);
            }
        }
        else
        {

        }
    }
    else
    // Emergency release
    {
        if(firsttime_emerg)
        {
            tsash.setRemainingTime(500);
            firsttime_emerg = false;
        }
        if(tsash.hasExpired()){
            if (P_bal_l >= 60.0)
                Ddelta_stv_l = two_points_to_Y(P_bal_l, 60.0, 150.0, 0.0, 30.0);

            if (P_bal_p >= 60.0)
                Ddelta_stv_p = two_points_to_Y(P_bal_p, 60.0, 150.0, 0.0, 30.0);

            if (P_bal_per >= 60.0)
                Ddelta_stv_n = two_points_to_Y(P_bal_per, 60.0, 150.0, 0.0, 30.0);

            // emergency left release
            if(delta_stv_l != 90.0 && gk_avl)
            {
                left_tick++;
                //releasing left
                releasing_loop(&delta_stv_l, &Ddelta_stv_l, &left_tick);
            }

            if(delta_stv_p != 90.0 && gk_avp)
            {
                right_tick++;
                //releasing right
                releasing_loop(&delta_stv_p, &Ddelta_stv_p, &right_tick);
            }

            if(delta_stv_n != 90 && gk_avn)
            {
                nose_tick++;
                //releasing nose
                releasing_loop(&delta_stv_n, &Ddelta_stv_n, &nose_tick);
            }
        }

    }

    if(!gk_oovsh && !gk_vsh && !gk_ush)
    {
        left_tick = 0;
        right_tick = 0;
        nose_tick = 0;
    }

    //end logic

}
static void releasing_loop(double* delta, double* Ddelta, int* tick)
{
    if(*delta < 90)
    {
        *delta = (*delta + ((*Ddelta / (1000 / TICK))));

        if(*delta >= 90)
        {
            *delta = 90;
            *tick = 0;
        }
    }
}
static void intake_loop(double* delta, double* Ddelta, int* tick)
{
    if(*delta > 0)
    {
        *delta = (*delta - ((*Ddelta / (1000 / TICK))));

        if(*delta <= 0)
        {
            *delta = 0;
            *tick = 0;
        }
    }
}

