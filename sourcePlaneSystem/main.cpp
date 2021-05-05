#include <presure.h>
#include "antiicing_int.h"
#include "powerdc_int.h"
#include "hydro_int.h"
#include "brakes_int.h"
#include "wingsmech_int.h"
#include "emergencyalarm_int.h"
#include "cabinlighting_int.h"
#include "antiicing_int.h"
#include "presure_int.h"
#include "antifire_int.h"
#include "landinggear_int.h"
#include "pneumatic_int.h"
#include "bailout_int.h"
#include "aircondition_int.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    antifire_int antifire;
    antifire.show();
    brakes_int brakes;
    brakes.show();
    wingsmech_int wingsmech;
    wingsmech.show();
    emergencyalarm_int emergencyalarm;
    emergencyalarm.show();
    cabinlighting_int cabinlighting;
    cabinlighting.show();
    presure_int presure;
    presure.show();
    antiicing_int antiicing;
    antiicing.show();
    pneumatic_int pneumatic;
    pneumatic.show();
    bailout_int bailout;
    bailout.show();
    aircondition_int aircondition;
    aircondition.show();
    landinggear_int landinggear;
    landinggear.show();
    hydro_int hydro;
    hydro.show();
    powerdc_int powerdc;
    powerdc.show();

    return a.exec();
}
