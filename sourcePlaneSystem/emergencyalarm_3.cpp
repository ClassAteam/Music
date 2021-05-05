#include "emergencyalarm_3.h"


void emergencyalarm_int::emergencyalarm_3()
{
    static bool
    //yellow input clue
    PZH812_X5j,
    PZH812_X5p,
    PZH812_X5HH,
    PZH_kren_velik,
    PZH_alpha_fi_ogrnich,
    PZH_nazhmi_rzv_tormz,

    //yellow block clue
    PZH812_X5j_b,
    PZH812_X5p_b,
    PZH812_X5HH_b,
    PZH_kren_velik_b,
    PZH_alpha_fi_ogrnich_b,
    PZH_nazhmi_rzv_tormz_b,

    //red input clue
    PK812_X5h,
    PK812_X5n,
    PK_V_velika,
    PK_V_mala,
    PK_alpha_py_predel,

    //red block clue
    PK812_X5h_b,
    PK812_X5n_b,
    PK_V_velika_b,
    PK_V_mala_b,
    PK_alpha_py_predel_b;

    if(PRBSS_812 == true)
    {
        ///////////////Yellow lights
        //////////////1
        if (bss_inst.BSS812X5j == true)
        {
            bss_inst.BSS812X6T = true;
            if(PZH812_X5j_b == true)
            {
                PZH812_X5j = false;
            }
            else
            {
                PZH812_X5j = true;
            }
        }
        else
        {
            bss_inst.BSS812X6T = false;
            PZH812_X5j_b = false;
            PZH812_X5j = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH812_X5j_b = true;
        }

        ///////////////Yellow lights
        //////////////2
        if (bss_inst.BSS812X5p == true)
        {
            bss_inst.BSS812X6V = true;
            if(PZH812_X5p_b == true)
            {
                PZH812_X5p = false;
            }
            else
            {
                PZH812_X5p = true;
            }
        }
        else
        {
            bss_inst.BSS812X6V = false;
            PZH812_X5p_b = false;
            PZH812_X5p = false;
        }

        if(exchange::s1_3364 == true)
        {
            PZH812_X5p_b = true;
        }

        ///////////////Yellow lights
        //////////////3
        if (bss_inst.BSS812X5HH == true)
        {
            bss_inst.BSS812X6e = true;
            if(PZH812_X5HH_b == true)
            {
                PZH812_X5HH = false;
            }
            else
            {
                PZH812_X5HH = true;
            }
        }
        else
        {
            bss_inst.BSS812X6e = false;
            PZH812_X5HH_b = false;
            PZH812_X5HH = false;
        }

        if(exchange::s1_3364 == true)
        {
            PZH812_X5HH_b = true;
        }

        ///////////////Yellow lights
        //////////////4
        if (bss_inst.kren_velik == true)
        {
            bss_inst.BSS812X6j = true;
            if(PZH_kren_velik_b == true)
            {
                PZH_kren_velik = false;
            }
            else
            {
                PZH_kren_velik = true;
            }
        }
        else
        {
            bss_inst.BSS812X6j = false;
            PZH_kren_velik_b = false;
            PZH_kren_velik = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH_kren_velik_b = true;
        }

        ///////////////Yellow lights
        //////////////5
        if (svs_otkaz == true)
        {
            bss_inst.BSS812X6k = true;
            if(PZH_svs_otkaz_b == true)
            {
                PZH_svs_otkaz = false;
            }
            else
            {
                PZH_svs_otkaz = true;
            }
        }
        else
        {
            bss_inst.BSS812X6k = false;
            PZH_svs_otkaz_b = false;
            PZH_svs_otkaz = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH_svs_otkaz_b = true;
        }

        ///////////////Yellow lights
        //////////////6
        if (ins_otkaz == true)
        {
            bss_inst.BSS812X6m = true;
            if(PZH_ins_otkaz_b == true)
            {
                PZH_ins_otkaz = false;
            }
            else
            {
                PZH_ins_otkaz = true;
            }
        }
        else
        {
            bss_inst.BSS812X6m = false;
            PZH_ins_otkaz_b = false;
            PZH_ins_otkaz = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH_ins_otkaz_b = true;
        }

        ///////////////Yellow lights
        //////////////7
        if (bss_inst.alpha_fi_ogrnich == true)
        {
            bss_inst.BSS812X6q = true;
            if(PZH_alpha_fi_ogrnich_b == true)
            {
                PZH_alpha_fi_ogrnich = false;
            }
            else
            {
                PZH_alpha_fi_ogrnich = true;
            }
        }
        else
        {
            bss_inst.BSS812X6q = false;
            PZH_alpha_fi_ogrnich_b = false;
            PZH_alpha_fi_ogrnich = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH_alpha_fi_ogrnich_b = true;
        }

        ///////////////Yellow lights
        //////////////8
        if (bss_inst.nazhmi_rzv_tormz == true)
        {
            bss_inst.BSS812X6n = true;
            if(PZH_nazhmi_rzv_tormz_b == true)
            {
                PZH_nazhmi_rzv_tormz = false;
            }
            else
            {
                PZH_nazhmi_rzv_tormz = true;
            }
        }
        else
        {
            bss_inst.BSS812X6n = false;
            PZH_nazhmi_rzv_tormz_b = false;
            PZH_nazhmi_rzv_tormz = false;
        }


        if(exchange::s1_3364 == true)
        {
            PZH_nazhmi_rzv_tormz_b = true;
        }

        //PCSOZHLL toggle
        if( PZH812_X5j == true ||
            PZH812_X5p == true ||
            PZH812_X5HH == true ||
            PZH_kren_velik == true ||
            PZH_alpha_fi_ogrnich == true ||
            PZH_nazhmi_rzv_tormz == true)
        {

            PCSOZHLL_2 = true;
        }
        else
        {

            PCSOZHLL_2 = false;
        }


        ///////////////Red lights_1
        //////////////1
        if (bss_inst.BSS812X5h == true)
        {
            bss_inst.BSS812X6S = true;
            if(PK812_X5h_b == true)
            {
                PK812_X5h = false;
            }
            else
            {
                PK812_X5h = true;
            }
        }
        else
        {
            bss_inst.BSS812X6S = false;
            PK812_X5h_b = false;
            PK812_X5h = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK812_X5h_b = true;
        }
        ///////////////Red lights_1
        //////////////2
        if (bss_inst.BSS812X5n == true)
        {
            bss_inst.BSS812X6U = true;
            if(PK812_X5n_b == true)
            {
                PK812_X5n = false;
            }
            else
            {
                PK812_X5n = true;
            }
        }
        else
        {
            bss_inst.BSS812X6U = false;
            PK812_X5n_b = false;
            PK812_X5n = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK812_X5n_b = true;
        }
        ///////////////Red lights_1
        //////////////3
        if (bss_inst.V_velika == true)
        {
            bss_inst.BSS812X6g = true;
            if(PK_V_velika_b == true)
            {
                PK_V_velika = false;
            }
            else
            {
                PK_V_velika = true;
            }
        }
        else
        {
            bss_inst.BSS812X6g = false;
            PK_V_velika_b = false;
            PK_V_velika = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK_V_velika_b = true;
        }

        ///////////////Red lights_1
        //////////////4
        if (bss_inst.V_mala == true)
        {
            bss_inst.BSS812X6h = true;
            if(PK_V_mala_b == true)
            {
                PK_V_mala = false;
            }
            else
            {
                PK_V_mala = true;
            }
        }
        else
        {
            bss_inst.BSS812X6h = false;
            PK_V_mala_b = false;
            PK_V_mala = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK_V_mala_b = true;
        }

        ///////////////Red lights_1
        //////////////5
        if (bss_inst.alpha_py_predel == true)
        {
            bss_inst.BSS812X6i = true;
            if(PK_alpha_py_predel_b == true)
            {
                PK_alpha_py_predel = false;
            }
            else
            {
                PK_alpha_py_predel = true;
            }
        }
        else
        {
            bss_inst.BSS812X6i = false;
            PK_alpha_py_predel_b = false;
            PK_alpha_py_predel = false;
        }


        if(exchange::s1_3364 == true)
        {
            PK_alpha_py_predel_b = true;
        }

        // PCSOKLL toggle
        if( PK812_X5h == true ||
            PK812_X5n == true ||
            PK_V_velika == true ||
            PK_V_mala == true ||
            PK_alpha_py_predel == true)
        {
            PCSOKLL_2 = true;
        }
        else
        {
            PCSOKLL_2 = false;
        }

        ///////////////White lights_1
        //////////////1
        if (bss_inst.BSS812X5B == true)
        {
            bss_inst.BSS812X6A = true;
        }
        else
        {
            bss_inst.BSS812X6A = false;
        }

        ///////////////White lights_1
        //////////////2
        if (bss_inst.BSS812X5D == true)
        {
            bss_inst.BSS812X6B = true;
        }
        else
        {
            bss_inst.BSS812X6B = false;
        }

        ///////////////White lights_1
        //////////////3
        if (bss_inst.BSS812X5E == true)
        {
            bss_inst.BSS812X6C = true;
        }
        else
        {
            bss_inst.BSS812X6C = false;
        }

        ///////////////White lights_1
        //////////////4
        if (bss_inst.BSS812X5G == true)
        {
            bss_inst.BSS812X6D = true;
        }
        else
        {
            bss_inst.BSS812X6D = false;
        }

        ///////////////White lights_1
        //////////////5
        if (bss_inst.BSS812X5J == true)
        {
            bss_inst.BSS812X6E = true;
        }
        else
        {
            bss_inst.BSS812X6E = false;
        }

        ///////////////White lights_1
        //////////////6
        if (bss_inst.BSS812X5L == true)
        {
            bss_inst.BSS812X6F = true;
        }
        else
        {
            bss_inst.BSS812X6F = false;
        }

        ///////////////White lights_1
        //////////////7
        if (bss_inst.BSS812X5N == true)
        {
            bss_inst.BSS812X6G = true;
        }
        else
        {
            bss_inst.BSS812X6G = false;
        }

        ///////////////White lights_1
        //////////////8
        if (bss_inst.BSS812X5R == true)
        {
            bss_inst.BSS812X6H = true;
        }
        else
        {
            bss_inst.BSS812X6H = false;
        }

        ///////////////White lights_1
        //////////////9
        if (bss_inst.BSS812X5T == true)
        {
            bss_inst.BSS812X6J = true;
        }
        else
        {
            bss_inst.BSS812X6J = false;
        }

        ///////////////White lights_1
        //////////////10
        if (bss_inst.BSS812X5V == true)
        {
            bss_inst.BSS812X6K = true;
        }
        else
        {
            bss_inst.BSS812X6K = false;
        }

        ///////////////White lights_1
        //////////////11
        if (bss_inst.BSS812X5X == true)
        {
            bss_inst.BSS812X6L = true;
        }
        else
        {
            bss_inst.BSS812X6L = false;
        }

        ///////////////White lights_1
        //////////////12
        if (bss_inst.BSS812X5Z == true && bss_inst.BSS812X5b == true)
        {
            bss_inst.BSS812X6M = true;
        }
        else
        {
            bss_inst.BSS812X6M = false;
        }

        ///////////////White lights_1
        //////////////13
        if (bss_inst.BSS812X5d == true && bss_inst.BSS812X5f == true)
        {
            bss_inst.BSS812X6N = true;
        }
        else
        {
            bss_inst.BSS812X6N = false;
        }

        ///////////////White lights_1
        //////////////14
        if (bss_inst.BSS812X5t == true)
        {
            bss_inst.BSS812X6X = true;
        }
        else
        {
            bss_inst.BSS812X6X = false;
        }

        ///////////////White lights_1
        //////////////15
        if (bss_inst.BSS812X5r == true)
        {
            bss_inst.BSS812X6W = true;
        }
        else
        {
            bss_inst.BSS812X6W = false;
        }

        ///////////////White lights_1
        //////////////16
        if (bss_inst.BSS812X5v == true || bss_inst.BSS812X5x == true)
        {
            bss_inst.BSS812X6Y = true;
        }
        else
        {
            bss_inst.BSS812X6Y = false;
        }

        ///////////////White lights_1
        //////////////17
        if (bss_inst.BSS812X5z == true)
        {
            bss_inst.BSS812X6a = true;
        }
        else
        {
            bss_inst.BSS812X6a = false;
        }

        ///////////////White lights_1
        //////////////18
        if (bss_inst.BSS812X5BB == true)
        {
            bss_inst.BSS812X6b = true;
        }
        else
        {
            bss_inst.BSS812X6b = false;
        }

        ///////////////White lights_1
        //////////////19
        if (bss_inst.BSS812X5DD == true)
        {
            bss_inst.BSS812X6c = true;
        }
        else
        {
            bss_inst.BSS812X6c = false;
        }

        ///////////////White lights_1
        //////////////20
        if (bss_inst.BSS812X5FF == true)
        {
            bss_inst.BSS812X6d = true;
        }
        else
        {
            bss_inst.BSS812X6d = false;
        }

        ///////////////White lights_1
        //////////////21
        if (bss_inst.vkl_rezerv_torm == true)
        {
            bss_inst.BSS812X6p = true;
        }
        else
        {
            bss_inst.BSS812X6p = false;
        }

        ///////////////White lights_1
        //////////////22
        if (bss_inst.vkl_forsir_torm == true)
        {
            bss_inst.BSS812X6r = true;
        }
        else
        {
            bss_inst.BSS812X6r = false;
        }

        ///////////////White lights_1
        //////////////23
        if (bss_inst.BSS812X5KK == true)
        {
            bss_inst.BSS812X6f = true;
        }
        else
        {
            bss_inst.BSS812X6f = false;
        }

        if(PKLLL == true)
        {
            PCSOZHLL = true;
            PCSOKLL = true;
            bss_inst.BSS812X6T = true;
            bss_inst.BSS812X6V = true;
            bss_inst.BSS812X6e = true;
            bss_inst.BSS812X6j = true;
            bss_inst.BSS812X6k = true;
            bss_inst.BSS812X6m = true;
            bss_inst.BSS812X6q = true;
            bss_inst.BSS812X6n = true;
            bss_inst.BSS812X6S = true;
            bss_inst.BSS812X6U = true;
            bss_inst.BSS812X6g = true;
            bss_inst.BSS812X6h = true;
            bss_inst.BSS812X6i = true;
            bss_inst.BSS812X6A = true;
            bss_inst.BSS812X6B = true;
            bss_inst.BSS812X6C = true;
            bss_inst.BSS812X6D = true;
            bss_inst.BSS812X6E = true;
            bss_inst.BSS812X6F = true;
            bss_inst.BSS812X6G = true;
            bss_inst.BSS812X6H = true;
            bss_inst.BSS812X6J = true;
            bss_inst.BSS812X6K = true;
            bss_inst.BSS812X6L = true;
            bss_inst.BSS812X6M = true;
            bss_inst.BSS812X6N = true;
            bss_inst.BSS812X6X = true;
            bss_inst.BSS812X6W = true;
            bss_inst.BSS812X6Y = true;
            bss_inst.BSS812X6a = true;
            bss_inst.BSS812X6b = true;
            bss_inst.BSS812X6c = true;
            bss_inst.BSS812X6d = true;
            bss_inst.BSS812X6p = true;
            bss_inst.BSS812X6r = true;
            bss_inst.BSS812X6f = true;
        }
    }
    else
    {
        bss_inst.BSS812X6V = false;
        bss_inst.BSS812X6e = false;
        bss_inst.BSS812X6j = false;
        bss_inst.BSS812X6k = false;
        bss_inst.BSS812X6m = false;
        bss_inst.BSS812X6q = false;
        bss_inst.BSS812X6n = false;
        bss_inst.BSS812X6S = false;
        bss_inst.BSS812X6U = false;
        bss_inst.BSS812X6g = false;
        bss_inst.BSS812X6h = false;
        bss_inst.BSS812X6i = false;
        bss_inst.BSS812X6A = false;
        bss_inst.BSS812X6B = false;
        bss_inst.BSS812X6C = false;
        bss_inst.BSS812X6D = false;
        bss_inst.BSS812X6E = false;
        bss_inst.BSS812X6F = false;
        bss_inst.BSS812X6G = false;
        bss_inst.BSS812X6H = false;
        bss_inst.BSS812X6J = false;
        bss_inst.BSS812X6K = false;
        bss_inst.BSS812X6L = false;
        bss_inst.BSS812X6M = false;
        bss_inst.BSS812X6N = false;
        bss_inst.BSS812X6X = false;
        bss_inst.BSS812X6W = false;
        bss_inst.BSS812X6Y = false;
        bss_inst.BSS812X6a = false;
        bss_inst.BSS812X6b = false;
        bss_inst.BSS812X6c = false;
        bss_inst.BSS812X6d = false;
        bss_inst.BSS812X6p = false;
        bss_inst.BSS812X6r = false;
        bss_inst.BSS812X6f = false;
        PZH812_X5j = false;
        PZH812_X5p = false;
        PZH812_X5HH = false;
        PZH_kren_velik = false;
        PZH_alpha_fi_ogrnich = false;
        PZH_nazhmi_rzv_tormz = false;
        //yellow block clue
        PZH812_X5j_b = false;
        PZH812_X5p_b = false;
        PZH812_X5HH_b = false;
        PZH_kren_velik_b = false;
        PZH_alpha_fi_ogrnich_b = false;
        PZH_nazhmi_rzv_tormz_b = false;
        //red input clue
        PK812_X5h = false;
        PK812_X5n = false;
        PK_V_velika = false;
        PK_V_mala = false;
        PK_alpha_py_predel = false;
        //red block clue
        PK812_X5h_b = false;
        PK812_X5n_b = false;
        PK_V_velika_b = false;
        PK_V_mala_b = false;
        PK_alpha_py_predel_b = false;
    }
}
