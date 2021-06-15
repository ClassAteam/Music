#include "emergencyalarm_6.h"

void emergencyalarm_int::emergencyalarm_6()
{
    static bool
        //yellow input clue
        PZH825_X5A,
        PZH825_X5C,
        PZH825_X5E,
        PZH825_X5G,
        PZH_alpha_py_fi_ogrnch,
        PZH_kren_velik_1,
        PZH_p_bakov_veliko,
        PZH_razrezh_veliko,

        //yellow block clue
        PZH825_X5A_b,
        PZH825_X5C_b,
        PZH825_X5E_b,
        PZH825_X5G_b,
        PZH_alpha_py_fi_ogrnch_b,
        PZH_kren_velik_b_1,
        PZH_p_bakov_veliko_b,
        PZH_razrezh_veliko_b,

        //red input clue
        PK825_X5L,
        PK825_X5f,
        PK825_X5N,
        PK825_X5h,
        PK825_X5R,
        PK825_X5j,
        PK825_X5T,
        PK825_X5n,
        PK_V_velika_PL,
        PK_V_mala_PL,
        PK_alpha_py_predel_PL,

        //red block clue
        PK825_X5f_b,
        PK825_X5h_b,
        PK825_X5j_b,
        PK825_X5n_b,
        PK_V_velika_PL_b,
        PK_V_mala_PL_b,
        PK_alpha_py_predel_PL_b;

    static int
        X5L_blink,
        X5N_blink,
        X5R_blink,
        X5T_blink;

    if(PRBSS825)
    {
        ///////////////Yellow lights
        //////////////1
        if(bss_inst.BSS825X5A)
        {
            bss_inst.BSS825X6A = true;
            if(PZH825_X5A_b)
            {
                PZH825_X5A = false;
            }
            else
            {
                PZH825_X5A = true;
            }
        }
        else
        {
            bss_inst.BSS825X6A = false;
            PZH825_X5A_b = false;
            PZH825_X5A = false;
        }

        if(exchange::s2_3364) PZH825_X5A_b = true;

        ///////////////Yellow lights
        //////////////2
        if (bss_inst.BSS825X5C)
        {
            bss_inst.BSS825X6B = true;
            if(PZH825_X5C_b)
            {
                PZH825_X5C = false;
            }
            else
            {
                PZH825_X5C = true;
            }
        }
        else
        {
            bss_inst.BSS825X6B = false;
            PZH825_X5C_b = false;
            PZH825_X5C = false;
        }

        if(exchange::s2_3364) PZH825_X5C_b = true;

        ///////////////Yellow lights
        //////////////3
        if(bss_inst.BSS825X5E)
        {
            bss_inst.BSS825X6C = true;
            if(PZH825_X5E_b)
            {
                PZH825_X5E = false;
            }
            else
            {
                PZH825_X5E = true;
            }
        }
        else
        {
            bss_inst.BSS825X6C = false;
            PZH825_X5E_b = false;
            PZH825_X5E = false;
        }

        if(exchange::s2_3364) PZH825_X5E_b = true;

        ///////////////Yellow lights
        //////////////4
        if(bss_inst.BSS825X5G)
        {
            bss_inst.BSS825X6D = true;
            if(PZH825_X5G_b)
            {
                PZH825_X5G = false;
            }
            else
            {
                PZH825_X5G = true;
            }
        }
        else
        {
            bss_inst.BSS825X6D = false;
            PZH825_X5G_b = false;
            PZH825_X5G = false;
        }

        if(exchange::s2_3364) PZH825_X5G_b = true;

        ///////////////Yellow lights
        //////////////5
        if(bss_inst.alpha_py_fi_ogrnch)
        {
            bss_inst.BSS825X6r = true;
            if(PZH_alpha_py_fi_ogrnch_b)
            {
                PZH_alpha_py_fi_ogrnch = false;
            }
            else
            {
                PZH_alpha_py_fi_ogrnch = true;
            }
        }
        else
        {
            bss_inst.BSS825X6r = false;
            PZH_alpha_py_fi_ogrnch_b = false;
            PZH_alpha_py_fi_ogrnch = false;
        }

        if(exchange::s2_3364) PZH_alpha_py_fi_ogrnch_b = true;

        ///////////////Yellow lights
        //////////////6
        if(bss_inst.kren_velik)
        {
            bss_inst.BSS825X6m = true;
            if(PZH_kren_velik_b_1)
            {
                PZH_kren_velik_1 = false;
            }
            else
            {
                PZH_kren_velik_1 = true;
            }
        }
        else
        {
            bss_inst.BSS825X6m = false;
            PZH_kren_velik_b_1 = false;
            PZH_kren_velik_1 = false;
        }

        if(exchange::s2_3364) PZH_kren_velik_b_1 = true;

        ///////////////Yellow lights
        //////////////7
        if(bss_inst.p_bakov_veliko)
        {
            bss_inst.BSS825X6n = true;
            if(PZH_p_bakov_veliko_b)
            {
                PZH_p_bakov_veliko = false;
            }
            else
            {
                PZH_p_bakov_veliko = true;
            }
        }
        else
        {
            bss_inst.BSS825X6n = false;
            PZH_p_bakov_veliko_b = false;
            PZH_p_bakov_veliko = false;
        }

        if(exchange::s2_3364) PZH_p_bakov_veliko_b = true;

        ///////////////Yellow lights
        //////////////8
        if(bss_inst.razrezh_veliko)
        {
            bss_inst.BSS825X6p = true;
            if(PZH_razrezh_veliko_b)
            {
                PZH_razrezh_veliko = false;
            }
            else
            {
                PZH_razrezh_veliko = true;
            }
        }
        else
        {
            bss_inst.BSS825X6p = false;
            PZH_razrezh_veliko_b = false;
            PZH_razrezh_veliko = false;
        }

        if(exchange::s2_3364) PZH_razrezh_veliko_b = true;

        //PCSOZHLL toggle
        if( PZH825_X5A  ||
            PZH825_X5C  ||
            PZH825_X5E  ||
            PZH825_X5G  ||
            PZH_alpha_py_fi_ogrnch  ||
            PZH_kren_velik_1  ||
            PZH_p_bakov_veliko  ||
            PZH_razrezh_veliko)
        {

            PCSOZHPL_2 = true;
        }
        else
        {

            PCSOZHPL_2 = false;
        }

        ///////////////Red lights_1
        //////////////1
        if(bss_inst.BSS825X5L)
        {
            X5L_blink++;
            if((X5L_blink * TICK) < 400)
            {
                bss_inst.BSS825X6F = false;
            }
            if(((X5L_blink * TICK)) >= 400)
            {
                bss_inst.BSS825X6F = true;
                X5L_blink = 0;
            }
        }
        else
        {
            bss_inst.BSS825X6F = false;
        }

        ///////////////Red lights_1
        //////////////2
        if(bss_inst.BSS825X5f)
        {
            bss_inst.BSS825X6R = true;
            if(PK825_X5f_b)
            {
                PK825_X5f = false;
            }
            else
            {
                PK825_X5f = true;
            }
        }
        else
        {
            bss_inst.BSS825X6R = false;
            PK825_X5f_b = false;
            PK825_X5f = false;
        }


        if(exchange::s2_3364) PK825_X5f_b = true;

        ///////////////Red lights_1
        //////////////3
        if(bss_inst.BSS825X5N)
        {
            X5N_blink++;
            if((X5N_blink * TICK) < 400)
            {
                bss_inst.BSS825X6G = false;
            }
            if(((X5N_blink * TICK)) >= 400)
            {
                bss_inst.BSS825X6G = true;
                X5N_blink = 0;
            }
        }
        else
        {
            bss_inst.BSS825X6G = false;
        }

        ///////////////Red lights_1
        //////////////4
        if(bss_inst.BSS825X5h)
        {
            bss_inst.BSS825X6S = true;
            if(PK825_X5h_b)
            {
                PK825_X5h = false;
            }
            else
            {
                PK825_X5h = true;
            }
        }
        else
        {
            bss_inst.BSS825X6S = false;
            PK825_X5h_b = false;
            PK825_X5h = false;
        }


        if(exchange::s2_3364) PK825_X5h_b = true;

        ///////////////Red lights_1
        //////////////5
        if(bss_inst.BSS825X5R)
        {
            X5R_blink++;
            if((X5R_blink * TICK) < 400)
            {
                bss_inst.BSS825X6H = false;
            }
            if(((X5R_blink * TICK)) >= 400)
            {
                bss_inst.BSS825X6H = true;
                X5R_blink = 0;
            }
        }
        else
        {
            bss_inst.BSS825X6H = false;
        }

        ///////////////Red lights_1
        //////////////6
        if(bss_inst.BSS825X5j)
        {
            bss_inst.BSS825X6T = true;
            if(PK825_X5j_b)
            {
                PK825_X5j = false;
            }
            else
            {
                PK825_X5j = true;
            }
        }
        else
        {
            bss_inst.BSS825X6T = false;
            PK825_X5j_b = false;
            PK825_X5j = false;
        }


        if(exchange::s2_3364) PK825_X5j_b = true;

        ///////////////Red lights_1
        //////////////7
        if(bss_inst.BSS825X5T)
        {
            X5T_blink++;
            if((X5T_blink * TICK) < 400)
            {
                bss_inst.BSS825X6J = false;
            }
            if(((X5T_blink * TICK)) >= 400)
            {
                bss_inst.BSS825X6J = true;
                X5T_blink = 0;
            }
        }
        else
        {
            bss_inst.BSS825X6J = false;
        }

        ///////////////Red lights_1
        //////////////8
        if(bss_inst.BSS825X5n)
        {
            bss_inst.BSS825X6U = true;
            if(PK825_X5n_b)
            {
                PK825_X5n = false;
            }
            else
            {
                PK825_X5n = true;
            }
        }
        else
        {
            bss_inst.BSS825X6U = false;
            PK825_X5n_b = false;
            PK825_X5n = false;
        }


        if(exchange::s2_3364) PK825_X5n_b = true;

        ///////////////Red lights_1
        //////////////9
        if(bss_inst.V_velika)
        {
            bss_inst.BSS825X6i = true;
            if(PK_V_velika_PL_b)
            {
                PK_V_velika_PL = false;
            }
            else
            {
                PK_V_velika_PL = true;
            }
        }
        else
        {
            bss_inst.BSS825X6i = false;
            PK_V_velika_PL_b = false;
            PK_V_velika_PL = false;
        }


        if(exchange::s2_3364) PK_V_velika_PL_b = true;

        ///////////////Red lights_1
        //////////////10
        if(bss_inst.V_mala)
        {
            bss_inst.BSS825X6j = true;
            if(PK_V_mala_PL_b)
            {
                PK_V_mala_PL = false;
            }
            else
            {
                PK_V_mala_PL = true;
            }
        }
        else
        {
            bss_inst.BSS825X6j = false;
            PK_V_mala_PL_b = false;
            PK_V_mala_PL = false;
        }


        if(exchange::s2_3364) PK_V_mala_PL_b = true;

        ///////////////Red lights_1
        //////////////11
        if (bss_inst.alpha_py_predel)
        {
            bss_inst.BSS825X6k = true;
            if(PK_alpha_py_predel_PL_b)
            {
                PK_alpha_py_predel_PL = false;
            }
            else
            {
                PK_alpha_py_predel_PL = true;
            }
        }
        else
        {
            bss_inst.BSS825X6k = false;
            PK_alpha_py_predel_PL_b = false;
            PK_alpha_py_predel_PL = false;
        }


        if(exchange::s2_3364) PK_alpha_py_predel_PL_b = true;


        // PCSOKLL toggle
        if(PK825_X5L  ||
            PK825_X5f  ||
            PK825_X5N  ||
            PK825_X5h  ||
            PK825_X5R  ||
            PK825_X5j  ||
            PK825_X5T  ||
            PK825_X5n  ||
            PK_V_velika_PL  ||
            PK_V_mala_PL  ||
            PK_alpha_py_predel_PL)
        {
            PCSOKPL_2 = true;
        }
        else
        {
            PCSOKPL_2 = false;
        }

        ///////////////White lights_1
        //////////////1
        if (bss_inst.BSS825X5J)
            bss_inst.BSS825X6E = true;
        else
            bss_inst.BSS825X6E = false;

        //White lights_1 2
        static int BSS825X6E{};
        lamp_blink(bss_inst.BSS825X7A, bss_inst.BSS825X6E, BSS825X6E);

        ///////////////White lights_1
        //////////////3
        if(bss_inst.BSS825X5V)
            bss_inst.BSS825X6K = true;
        else
            bss_inst.BSS825X6K = false;

        ///////////////White lights_1
        //////////////4
        if(bss_inst.BSS825X5FF)
            bss_inst.BSS825X6d = true;
        else
            bss_inst.BSS825X6d = false;

        ///////////////White lights_1
        //////////////5
        if(bss_inst.BSS825X5FF)
            bss_inst.BSS825X6d = true;
        else
            bss_inst.BSS825X6d = false;

        ///////////////White lights_1
        //////////////6
        if(bss_inst.BSS825X5HH)
            bss_inst.BSS825X6e = true;
        else
            bss_inst.BSS825X6e = false;

        ///////////////White lights_1
        //////////////7
        if(bss_inst.BSS825X5X)
            bss_inst.BSS825X6L = true;
        else
            bss_inst.BSS825X6L = false;

        ///////////////White lights_1
        //////////////8
        if(bss_inst.BSS825X5Z)
            bss_inst.BSS825X6M = true;
        else
            bss_inst.BSS825X6M = false;

        ///////////////White lights_1
        //////////////9
        if (bss_inst.BSS825X5b)
            bss_inst.BSS825X6N = true;
        else
            bss_inst.BSS825X6N = false;

        ///////////////White lights_1
        //////////////10
        if(bss_inst.BSS825X5d)
            bss_inst.BSS825X6P = true;
        else
            bss_inst.BSS825X6P = false;

        ///////////////White lights_1
        //////////////11
        if(bss_inst.BSS825X5r)
            bss_inst.BSS825X6W = true;
        else
            bss_inst.BSS825X6W = false;

        ///////////////White lights_1
        //////////////12
        if(bss_inst.BSS825X5t)
            bss_inst.BSS825X6X = true;
        else
            bss_inst.BSS825X6X = false;

        ///////////////White lights_1
        //////////////13
        if(bss_inst.BSS825X7R)
            bss_inst.BSS825X6q = true;
        else
            bss_inst.BSS825X6q = false;

        ///////////////White lights_1
        //////////////14
        if(bss_inst.BSS825X5v)
            bss_inst.BSS825X6Y = true;
        else
            bss_inst.BSS825X6Y = false;

        ///////////////White lights_1
        //////////////15
        if(bss_inst.BSS825X5x)
            bss_inst.BSS825X6Z = true;
        else
            bss_inst.BSS825X6Z = false;

        ///////////////White lights_1
        //////////////16
        if(bss_inst.BSS825X5z)
            bss_inst.BSS825X6a = true;
        else
            bss_inst.BSS825X6a = false;

        ///////////////White lights_1 17

        static int BSS825X6Y{};
        lamp_blink(bss_inst.BSS825X5BB, bss_inst.BSS825X6Y, BSS825X6Y);

        ///////////////White lights_1 18

        static int BSS825X6a{};
        lamp_blink(bss_inst.BSS825X5DD, bss_inst.BSS825X6a, BSS825X6a);

        ///////////////White lights_1
        //////////////18
        if(bss_inst.BSS825X5KK)
            bss_inst.BSS825X6f = true;
        else
            bss_inst.BSS825X6f = false;

        ///////////////White lights_1
        //////////////19
        if(bss_inst.BSS825X5MM)
            bss_inst.BSS825X6g = true;
        else
            bss_inst.BSS825X6g = false;

        if(bss_inst.BSS825PR)
            bss_inst.BSS825PROG = true;
        else
            bss_inst.BSS825PROG = false;

        ///////////////White lights_1
        //////////////19
        if(bss_inst.BSS825PR)
            bss_inst.BSS825_prog = true;
        else
            bss_inst.BSS825_prog = false;

        if(PKLPL)
        {
            PCSOZHPL_2 = true;
            PCSOKPL_2 = true;
            bss_inst.BSS825X6A = true;
            bss_inst.BSS825X6B = true;
            bss_inst.BSS825X6C = true;
            bss_inst.BSS825X6D = true;
            bss_inst.BSS825X6r = true;
            bss_inst.BSS825X6m = true;
            bss_inst.BSS825X6n = true;
            bss_inst.BSS825X6p = true;
            bss_inst.BSS825X6F = true;
            bss_inst.BSS825X6R = true;
            bss_inst.BSS825X6G = true;
            bss_inst.BSS825X6S = true;
            bss_inst.BSS825X6H = true;
            bss_inst.BSS825X6T = true;
            bss_inst.BSS825X6J = true;
            bss_inst.BSS825X6U = true;
            bss_inst.BSS825X6i = true;
            bss_inst.BSS825X6j = true;
            bss_inst.BSS825X6k = true;
            bss_inst.BSS825X6E = true;
            bss_inst.BSS825X6K = true;
            bss_inst.BSS825X6d = true;
            bss_inst.BSS825X6e = true;
            bss_inst.BSS825X6L = true;
            bss_inst.BSS825X6M = true;
            bss_inst.BSS825X6N = true;
            bss_inst.BSS825X6P = true;
            bss_inst.BSS825X6W = true;
            bss_inst.BSS825X6X = true;
            bss_inst.BSS825X6q = true;
            bss_inst.BSS825X6Y = true;
            bss_inst.BSS825X6Z = true;
            bss_inst.BSS825X6a = true;
            bss_inst.BSS825X6f = true;
            bss_inst.BSS825X6g = true;
            bss_inst.BSS825_prog = true;
        }

        if(PCSOZHPL_1 || PCSOZHPL_2)
            PCSOZHPL = true;
        else
            PCSOZHPL = false;

        if(PCSOKPL_1 || PCSOKPL_2)
            PCSOKPL = true;
        else
            PCSOKPL = false;
    }
    else
    {
        PCSOZHPL = false;
        PCSOKPL = false;
        bss_inst.BSS825X6A = false;
        bss_inst.BSS825X6B = false;
        bss_inst.BSS825X6C = false;
        bss_inst.BSS825X6D = false;
        bss_inst.BSS825X6r = false;
        bss_inst.BSS825X6m = false;
        bss_inst.BSS825X6n = false;
        bss_inst.BSS825X6p = false;
        bss_inst.BSS825X6F = false;
        bss_inst.BSS825X6R = false;
        bss_inst.BSS825X6G = false;
        bss_inst.BSS825X6S = false;
        bss_inst.BSS825X6H = false;
        bss_inst.BSS825X6T = false;
        bss_inst.BSS825X6J = false;
        bss_inst.BSS825X6U = false;
        bss_inst.BSS825X6i = false;
        bss_inst.BSS825X6j = false;
        bss_inst.BSS825X6k = false;
        bss_inst.BSS825X6E = false;
        bss_inst.BSS825X6K = false;
        bss_inst.BSS825X6d = false;
        bss_inst.BSS825X6e = false;
        bss_inst.BSS825X6L = false;
        bss_inst.BSS825X6M = false;
        bss_inst.BSS825X6N = false;
        bss_inst.BSS825X6P = false;
        bss_inst.BSS825X6W = false;
        bss_inst.BSS825X6X = false;
        bss_inst.BSS825X6q = false;
        bss_inst.BSS825X6Y = false;
        bss_inst.BSS825X6Z = false;
        bss_inst.BSS825X6a = false;
        bss_inst.BSS825X6f = false;
        bss_inst.BSS825X6g = false;
        PZH825_X5A = false;
        PZH825_X5C = false;
        PZH825_X5E = false;
        PZH825_X5G = false;
        PZH_alpha_py_fi_ogrnch = false;
        PZH_kren_velik_1 = false;
        PZH_p_bakov_veliko = false;
        PZH_razrezh_veliko = false;
        PZH825_X5A_b = false;
        PZH825_X5C_b = false;
        PZH825_X5E_b = false;
        PZH825_X5G_b = false;
        PZH_alpha_py_fi_ogrnch_b = false;
        PZH_kren_velik_b_1 = false;
        PZH_p_bakov_veliko_b = false;
        PZH_razrezh_veliko_b = false;
        PK825_X5L = false;
        PK825_X5f = false;
        PK825_X5N = false;
        PK825_X5h = false;
        PK825_X5R = false;
        PK825_X5j = false;
        PK825_X5T = false;
        PK825_X5n = false;
        PK_V_velika_PL = false;
        PK_V_mala_PL = false;
        PK_alpha_py_predel_PL = false;
        PK825_X5f_b = false;
        PK825_X5h_b = false;
        PK825_X5j_b = false;
        PK825_X5n_b = false;
        PK_V_velika_PL_b = false;
        PK_V_mala_PL_b = false;
        PK_alpha_py_predel_PL_b = false;
    }
}

