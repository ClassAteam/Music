#include "emergencyalarm_9.h"
#include "algorithms.h"

void yellow(bool* input, bool* output, bool* clue, bool* block_clue, bool* button);
void white(bool* input, bool* output);

void emergencyalarm_int::emergencyalarm_9()
{
    static bool
        PCSOZHSHO_3,
        PCSOKSHO_3,

        //yellow input clue
        PZH838_X5A,
        PZH838_X5J,
        PZH838_X5T,
        PZH838_X5V,
        PZH838_X5Z,
        PZH838_X5d,
        PZH838_X5h,
        PZH838_X5n,
        PZH838_X5p,
        PZH838_X5v,
        PZH838_X5z,
        PZH838_X5DD,
        PZH838_X5HH,
        PZH838_X7E,
        PZH838_X7J,
        PZH838_X7R,
        PZH838_X7T,

        //yellow block clue
        PZH838_X5A_b,
        PZH838_X5J_b,
        PZH838_X5T_b,
        PZH838_X5V_b,
        PZH838_X5Z_b,
        PZH838_X5d_b,
        PZH838_X5h_b,
        PZH838_X5n_b,
        PZH838_X5p_b,
        PZH838_X5v_b,
        PZH838_X5z_b,
        PZH838_X5DD_b,
        PZH838_X5HH_b,
        PZH838_X7E_b,
        PZH838_X7J_b,
        PZH838_X7R_b,
        PZH838_X7T_b,

        //red input clue
        PK838_X5E,
        PK838_X5N,
        PK838_X5MM,
        PK838_X7A,
        PK838_X7C,
        PK838_X7G,
        PK838_X7L,
        PK838_X7N,

        //red block clue
        PK838_X5E_b,
        PK838_X5N_b,
        PK838_X5MM_b,
        PK838_X7A_b,
        PK838_X7C_b,
        PK838_X7G_b,
        PK838_X7L_b,
        PK838_X7N_b;

    if(PRBSS838 == true)
    {
        ///////////////Yellow lights
        //////////////1
        yellow(&bss_inst.BSS838X5A, &bss_inst.BSS838X6A, &PZH838_X5A, &PZH838_X5A_b, &exchange::s3_3364);
        //////////////2
        yellow(&bss_inst.BSS838X5J, &bss_inst.BSS838X6E, &PZH838_X5J, &PZH838_X5J_b, &exchange::s3_3364);
        //////////////3
        yellow(&bss_inst.BSS838X5T, &bss_inst.BSS838X6J, &PZH838_X5T, &PZH838_X5T_b, &exchange::s3_3364);
        //////////////4
        yellow(&bss_inst.BSS838X5V, &bss_inst.BSS838X6K, &PZH838_X5V, &PZH838_X5V_b, &exchange::s3_3364);
        //////////////5
        yellow(&bss_inst.BSS838X5Z, &bss_inst.BSS838X6M, &PZH838_X5Z, &PZH838_X5Z_b, &exchange::s3_3364);
        //////////////6
        yellow(&bss_inst.BSS838X5d, &bss_inst.BSS838X6P, &PZH838_X5d, &PZH838_X5d_b, &exchange::s3_3364);
        //////////////7
        yellow(&bss_inst.BSS838X5h, &bss_inst.BSS838X6S, &PZH838_X5h, &PZH838_X5h_b, &exchange::s3_3364);
        //////////////8
        yellow(&bss_inst.BSS838X5n, &bss_inst.BSS838X6U, &PZH838_X5n, &PZH838_X5n_b, &exchange::s3_3364);
        //////////////9
        yellow(&bss_inst.BSS838X5p, &bss_inst.BSS838X6V, &PZH838_X5p, &PZH838_X5p_b, &exchange::s3_3364);
        //////////////10
        yellow(&bss_inst.BSS838X5v, &bss_inst.BSS838X6Y, &PZH838_X5v, &PZH838_X5v_b, &exchange::s3_3364);
        //////////////11
        yellow(&bss_inst.BSS838X5z, &bss_inst.BSS838X6a, &PZH838_X5z, &PZH838_X5z_b, &exchange::s3_3364);
        //////////////12
        yellow(&bss_inst.BSS838X5DD, &bss_inst.BSS838X6c, &PZH838_X5DD, &PZH838_X5DD_b, &exchange::s3_3364);
        //////////////13
        yellow(&bss_inst.BSS838X5HH, &bss_inst.BSS838X6e, &PZH838_X5HH, &PZH838_X5HH_b, &exchange::s3_3364);
        //////////////14
        yellow(&bss_inst.BSS838X7E, &bss_inst.BSS838X6j, &PZH838_X7E, &PZH838_X7E_b, &exchange::s3_3364);
        //////////////15
        yellow(&bss_inst.BSS838X7J, &bss_inst.BSS838X6m, &PZH838_X7J, &PZH838_X7J_b, &exchange::s3_3364);
        //////////////16
        yellow(&bss_inst.BSS838X7R, &bss_inst.BSS838X6q, &PZH838_X7R, &PZH838_X7R_b, &exchange::s3_3364);
        //////////////17
        yellow(&bss_inst.BSS838X7T, &bss_inst.BSS838X6r, &PZH838_X7T, &PZH838_X7T_b, &exchange::s3_3364);

        //PCSOZHSHO toggle
        if(  PZH838_X5A == true  ||
            PZH838_X5J == true ||
            PZH838_X5T == true ||
            PZH838_X5V == true ||
            PZH838_X5Z == true ||
            PZH838_X5d == true ||
            PZH838_X5h == true ||
            PZH838_X5n == true ||
            PZH838_X5p == true ||
            PZH838_X5v == true ||
            PZH838_X5z == true ||
            PZH838_X5DD == true ||
            PZH838_X5HH == true ||
            PZH838_X7E == true ||
            PZH838_X7J == true ||
            PZH838_X7R == true ||
            PZH838_X7T == true)
        {

            PCSOZHSHO_3 = true;
        }
        else
        {

            PCSOZHSHO_3 = false;
        }

        ///////////////Red lights
        //////////////1
        yellow(&bss_inst.BSS838X5E, &bss_inst.BSS838X6C, &PK838_X5E, &PK838_X5E_b, &exchange::s3_3364);
        //////////////2
        yellow(&bss_inst.BSS838X5N, &bss_inst.BSS838X6G, &PK838_X5N, &PK838_X5N_b, &exchange::s3_3364);
        //////////////5
        yellow(&bss_inst.BSS838X7C, &bss_inst.BSS838X6i, &PK838_X7C, &PK838_X7C_b, &exchange::s3_3364);
        //////////////6
        yellow(&bss_inst.BSS838X7G, &bss_inst.BSS838X6k, &PK838_X7G, &PK838_X7G_b, &exchange::s3_3364);
        //////////////7
        yellow(&bss_inst.BSS838X7L, &bss_inst.BSS838X6n, &PK838_X7L, &PK838_X7L_b, &exchange::s3_3364);
        //////////////8
        yellow(&bss_inst.BSS838X7N, &bss_inst.BSS838X6p, &PK838_X7N, &PK838_X7N_b, &exchange::s3_3364);

        //3
        static int bss838X6g{};
        lamp_blink(bss_inst.BSS838X5MM, bss_inst.BSS838X6g, bss838X6g);
        //4
        static int bss838X6h{};
        lamp_blink(bss_inst.BSS838X7A, bss_inst.BSS838X6h, bss838X6h);

        //PCSOZHSHO toggle
        if(
            PK838_X5E == true ||
            PK838_X5N == true ||
            PK838_X5MM == true ||
            PK838_X7A == true ||
            PK838_X7C == true ||
            PK838_X7G == true ||
            PK838_X7L == true ||
            PK838_X7N == true)
        {
            PCSOKSHO_3 = true;
        }
        else
        {
            PCSOKSHO_3 = false;
        }

        //////////////White lights_1
        /// 1
        white(&bss_inst.BSS838X5C, &bss_inst.BSS838X6B);
        /// 2
        white(&bss_inst.BSS838X5C, &bss_inst.BSS838X6B);
        /// 3
        white(&bss_inst.BSS838X5G, &bss_inst.BSS838X6D);
        /// 4
        white(&bss_inst.BSS838X5L, &bss_inst.BSS838X6F);
        /// 5
        white(&bss_inst.BSS838X5R, &bss_inst.BSS838X6H);
        /// 6
        white(&bss_inst.BSS838X5X, &bss_inst.BSS838X6L);
        /// 7
        white(&bss_inst.BSS838X5b, &bss_inst.BSS838X6N);
        /// 8
        white(&bss_inst.BSS838X5f, &bss_inst.BSS838X6R);
        /// 9
        white(&bss_inst.BSS838X5j, &bss_inst.BSS838X6T);
        /// 10
        white(&bss_inst.BSS838X5x, &bss_inst.BSS838X6Z);
        /// 11
        white(&bss_inst.BSS838X5BB, &bss_inst.BSS838X6b);
        /// 12
        white(&bss_inst.BSS838X5FF, &bss_inst.BSS838X6d);
        /// 13
        white(&bss_inst.BSS838X5KK, &bss_inst.BSS838X6f);
        /// 14
        white(&bss_inst.BSS838X5r, &bss_inst.BSS838X6W);

        if(PKLSHO == true)
        {
            PCSOZHSHO = true;
            PCSOKSHO = true;
            bss_inst.BSS838X6A = true;
            bss_inst.BSS838X6E = true;
            bss_inst.BSS838X6J = true;
            bss_inst.BSS838X6K = true;
            bss_inst.BSS838X6M = true;
            bss_inst.BSS838X6P = true;
            bss_inst.BSS838X6S = true;
            bss_inst.BSS838X6U = true;
            bss_inst.BSS838X6V = true;
            bss_inst.BSS838X6Y = true;
            bss_inst.BSS838X6a = true;
            bss_inst.BSS838X6c = true;
            bss_inst.BSS838X6e = true;
            bss_inst.BSS838X6j = true;
            bss_inst.BSS838X6m = true;
            bss_inst.BSS838X6q = true;
            bss_inst.BSS838X6r = true;
            bss_inst.BSS838X6C = true;
            bss_inst.BSS838X6G = true;
            bss_inst.BSS838X6g = true;
            bss_inst.BSS838X6h = true;
            bss_inst.BSS838X6i = true;
            bss_inst.BSS838X6k = true;
            bss_inst.BSS838X6n = true;
            bss_inst.BSS838X6p = true;
            bss_inst.BSS838X6B = true;
            bss_inst.BSS838X6D = true;
            bss_inst.BSS838X6F = true;
            bss_inst.BSS838X6H = true;
            bss_inst.BSS838X6L = true;
            bss_inst.BSS838X6N = true;
            bss_inst.BSS838X6R = true;
            bss_inst.BSS838X6T = true;
            bss_inst.BSS838X6Z = true;
            bss_inst.BSS838X6b = true;
            bss_inst.BSS838X6d = true;
            bss_inst.BSS838X6f = true;
            bss_inst.BSS838X6W = true;
        }

        if(
            PCSOZHSHO_1 == true ||
            PCSOZHSHO_2 == true ||
            PCSOZHSHO_3 == true  )
        {
            PCSOZHSHO = true;
        }
        else
        {
            PCSOZHSHO = false;
        }

        if(
            PCSOKSHO_2 == true ||
            PCSOKSHO_3 == true  )
        {
            PCSOKSHO = true;
        }
        else
        {
            PCSOKSHO = false;
        }

    }
    else
    {
        PCSOZHSHO_3 = 0;
        PCSOKSHO_3 = 0;
        bss_inst.BSS838X6A = 0;
        bss_inst.BSS838X6E = 0;
        bss_inst.BSS838X6J = 0;
        bss_inst.BSS838X6K = 0;
        bss_inst.BSS838X6M = 0;
        bss_inst.BSS838X6P = 0;
        bss_inst.BSS838X6S = 0;
        bss_inst.BSS838X6U = 0;
        bss_inst.BSS838X6V = 0;
        bss_inst.BSS838X6Y = 0;
        bss_inst.BSS838X6a = 0;
        bss_inst.BSS838X6c = 0;
        bss_inst.BSS838X6e = 0;
        bss_inst.BSS838X6j = 0;
        bss_inst.BSS838X6m = 0;
        bss_inst.BSS838X6q = 0;
        bss_inst.BSS838X6r = 0;
        bss_inst.BSS838X6C = 0;
        bss_inst.BSS838X6G = 0;
        bss_inst.BSS838X6g = 0;
        bss_inst.BSS838X6h = 0;
        bss_inst.BSS838X6i = 0;
        bss_inst.BSS838X6k = 0;
        bss_inst.BSS838X6n = 0;
        bss_inst.BSS838X6p = 0;
        bss_inst.BSS838X6B = 0;
        bss_inst.BSS838X6D = 0;
        bss_inst.BSS838X6F = 0;
        bss_inst.BSS838X6H = 0;
        bss_inst.BSS838X6L = 0;
        bss_inst.BSS838X6N = 0;
        bss_inst.BSS838X6R = 0;
        bss_inst.BSS838X6T = 0;
        bss_inst.BSS838X6Z = 0;
        bss_inst.BSS838X6b = 0;
        bss_inst.BSS838X6d = 0;
        bss_inst.BSS838X6f = 0;
        bss_inst.BSS838X6W = 0;
        PZH838_X5A = 0;
        PZH838_X5J = 0;
        PZH838_X5T = 0;
        PZH838_X5V = 0;
        PZH838_X5Z = 0;
        PZH838_X5d = 0;
        PZH838_X5h = 0;
        PZH838_X5n = 0;
        PZH838_X5p = 0;
        PZH838_X5v = 0;
        PZH838_X5z = 0;
        PZH838_X5DD = 0;
        PZH838_X5HH = 0;
        PZH838_X7E = 0;
        PZH838_X7J = 0;
        PZH838_X7R = 0;
        PZH838_X7T = 0;
        PZH838_X5A_b = 0;
        PZH838_X5J_b = 0;
        PZH838_X5T_b = 0;
        PZH838_X5V_b = 0;
        PZH838_X5Z_b = 0;
        PZH838_X5d_b = 0;
        PZH838_X5h_b = 0;
        PZH838_X5n_b = 0;
        PZH838_X5p_b = 0;
        PZH838_X5v_b = 0;
        PZH838_X5z_b = 0;
        PZH838_X5DD_b = 0;
        PZH838_X5HH_b = 0;
        PZH838_X7E_b = 0;
        PZH838_X7J_b = 0;
        PZH838_X7R_b = 0;
        PZH838_X7T_b = 0;
        PK838_X5E = 0;
        PK838_X5N = 0;
        PK838_X5MM = 0;
        PK838_X7A = 0;
        PK838_X7C = 0;
        PK838_X7G = 0;
        PK838_X7L = 0;
        PK838_X7N = 0;
        PK838_X5E_b = 0;
        PK838_X5N_b = 0;
        PK838_X5MM_b = 0;
        PK838_X7A_b = 0;
        PK838_X7C_b = 0;
        PK838_X7G_b = 0;
        PK838_X7L_b = 0;
        PK838_X7N_b = 0;

    }
}

void yellow(bool* input, bool* output, bool* clue, bool* block_clue, bool* button)
{
    if(*input == true)
    {
        *output = true;
        if(*block_clue == true)
        {
            *clue = false;
        }
        else
        {
            *clue = true;
        }
    }
    else
    {
        *output  = false;
        *block_clue = false;
        *clue = false;
    }

    if(*button == true)
    {
        *block_clue = true;
    }
}

void white(bool* input, bool* output)
{
    if(*input == true)
    {
       *output = true;
    }
    else
    {
       *output = false;
    }
}
