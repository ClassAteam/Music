#include "landinggear_int.h"

void landinggear_int::updateLogic()
{
    landinggear_1();
    landinggear_2();
    landinggear_3();
    landinggear_4();
    landinggear_5();
    landinggear_6();
    landinggear_7_8();
    landinggear_9_10();
    landinggear_11_12();
}

void landinggear_int::balloon_presure( double* P_bal)
{
    double delta_V_bal;
    double V_bal;
    V_bal = 0;
    if((*P_bal) == P_bal_l)
    {
        V_bal = V_bal_l;
        delta_V_bal = (Ksho * (*P_bal));
        V_bal = V_bal + delta_V_bal;
        V_bal_l = V_bal;
        *P_bal = 6615000 / V_bal;
    }
    if((*P_bal) == P_bal_p)
    {
        V_bal = V_bal_p;
        delta_V_bal = (Ksho * (*P_bal));
        V_bal = V_bal + delta_V_bal;
        V_bal_p = V_bal;
        *P_bal = 6615000 / V_bal;
    }
    if((*P_bal) == P_bal_per)
    {
        V_bal = V_bal_n;
        delta_V_bal = (Ksho * (*P_bal));
        V_bal = V_bal + delta_V_bal;
        V_bal_n = V_bal;
        *P_bal = 5550000 / V_bal;
    }
}

bool landinggear_int::K5_3250{};
bool landinggear_int::K6_3250{};
bool landinggear_int::K9_3230{};
bool landinggear_int::S18_2930{};


