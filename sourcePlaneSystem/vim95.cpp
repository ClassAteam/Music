#include "vim95.h"
#include "externStruct/Struct_ISU.h"

extern SH_ISU ISU;



VIM95::VIM95(modeType mode_in) : mode{mode_in}
{

}

VIM95::vor::vor(int *course_in, double *freq_in) : course{course_in},
    freq{freq_in}
{

}

bool VIM95::vor::tryBeaconCapture()
{
    vorBeacon nullBeacon;
    currBeacon = land_comstations::instance().tryBeaconCapture(*freq);
    if(currBeacon != nullBeacon)
        return true;
    return false;
}

bool VIM95::vor::producePack()
{
    if(tryBeaconCapture())
    {
        pack.beaconCourse = beaconAzimuth();
        pack.shifting = shifting();
        pack.to_from = to_from();
        pack.courseAngle = courseAngle();
        pack.signalCaptured = true;
        pack.beaconName = currBeacon.name;
        return true;
    }
    else
    {
        pack.beaconCourse = 0;
        pack.shifting = 0;
        pack.to_from = false;
        pack.courseAngle = 0;
        pack.signalCaptured = false;
        pack.beaconName = "none";
        return false;
    }
}

int VIM95::vor::beaconAzimuth()
{
    return currBeacon.azimuth;
}

int VIM95::vor::shifting()
{
    return *course - ISU.NorthAngle;
}

bool VIM95::vor::to_from()
{
    if(ISU.NorthAngle == currBeacon.azimuth)
        return true;
    else
        return false;
}

int VIM95::vor::courseAngle()
{
    return (currBeacon.azimuth - ISU.NorthAngle);
}


bool VIM95::ils::takeIlsLocalizer()
{
    ilsLocalizer nullLocalizer;
    currLocalizer = land_comstations::instance().takeIlsLocalizer();
    if(currLocalizer != nullLocalizer)
        return true;
    return false;
}
