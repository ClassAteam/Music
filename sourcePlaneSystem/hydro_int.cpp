#include "hydro_int.h"

void hydro_int::updateLogic()
{
    hydro_1();
    hydro_2();
    hydro_3();
    hydro_4();
    hydro_5();
    hydro_6();
    hydro_7();
    hydro_8();
    hydro_9();
    hydro_10();
}
QVector<double> hydro_int::nVDfirst2{0.0, 0.0};
QVector<double> hydro_int::nVDsecond2{0.0, 0.0};
double hydro_int::pgs1{};
double hydro_int::pgs2{};
double hydro_int::pgs3{};
double hydro_int::pgs4{};
