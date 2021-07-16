#include "cabinlighting_4.h"

void cabinlighting_int::cabinlighting_4()
{
    static bool k15_3340{};

    bss_inst.BSS825X5V = false;

    k15_3340 = (exchange::usho2p >= 18.0 && s1_2860) ? true : false;

    if(exchange::usho1p >= 18.0 && k15_3340)
    {
        switch(S3_3340)
        {
        case static_cast<int>(S3_3340::uborka):
        {
            alpha_fazl = alpha_fazl - dalpha_faz * ts;
            if(alpha_fazl <= 0.0) alpha_fazl = 0.0;
            break;
        }
        case static_cast<int>(S3_3340::vipusk):
        {
            alpha_fazl = alpha_fazl + dalpha_faz * ts;
            if(alpha_fazl >= 125.0) alpha_fazl = 125.0;
            break;
        }
        }
        PFSV_02L = (S2_3340) ? true : false;
    }

    if(exchange::usho2p >= 18.0 && k15_3340)
    {
        switch(S4_3340)
        {
        case static_cast<int>(S4_3340::uborka):
        {
            alpha_fazp = alpha_fazp - dalpha_faz * ts;
            if(alpha_fazp <= 0.0) alpha_fazp = 0.0;
            break;
        }
        case static_cast<int>(S4_3340::vipusk):
        {
            alpha_fazp = alpha_fazp + dalpha_faz * ts;
            if(alpha_fazp >= 125.0) alpha_fazp = 125.0;
            break;
        }
        }
        PFSV_02P = (S5_3340) ? true : false;
    }

    if((exchange::usho2p >= 18.0 && alpha_fazp == 125.0)
        ||
        (exchange::usho1p >= 18.0 && alpha_fazl == 125.0))
    {
        bss_inst.BSS825X5V = true;
    }
    else
    {
        bss_inst.BSS825X5V = false;
    }

    if((exchange::ush1l >= 18.0 && alpha_fsv_ol == 1.0)
        ||
        (exchange::ush1p >= 18.0 && alpha_fsv_op == 1.0))
    {
        bss_inst.BSS824X1E = true;
    }
    else
    {
        bss_inst.BSS824X1E = false;
    }

    if((exchange::ush1l >= 18.0 && (PFPRLP || PFSV_01LP))
    ||
        ((exchange::ush1l >= 18.0 && (PFPRPP || PFSV_01PP))))
    {
        bss_inst.BSS824X1A = true;
    }
    else
    {
        bss_inst.BSS824X1A = false;
    }








}
