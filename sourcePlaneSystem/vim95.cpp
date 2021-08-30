#include "vim95.h"
#include "externStruct/Struct_ISU.h"
#include "algorithms.h"

extern SH_ISU ISU;
extern SH_ISU* pISU;
const double MAXIMUM_HORIZON_ARROW_VALUE{1000};
const double MAXIMUM_VERT_ARROW_VALUE{10000};

VIM95::VIM95()
{

}

VIM95 &VIM95::instance()
{
    static VIM95 singleton;
    return singleton;
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

bool VIM95::ilsSystem::tryBeaconCapture()
{
    currLocalizer = land_comstations::instance().tryIlsCapture(pISU->planePosX,
                                                               pISU->planePosY);
    if(currLocalizer->checkName() != "none")
        return true;
    return false;
}

double VIM95::ilsSystem::proceedValue()
{
    if(tryBeaconCapture())
    {
        return currLocalizer->proceedValue();
    }
    return MAXIMUM_HORIZON_ARROW_VALUE;
}

double VIM95::ilsSystem::proceedGlissadeValue()
{
    if(tryBeaconCapture())
    {
        return currLocalizer->proceedGlissadeValue();
    }
    return MAXIMUM_VERT_ARROW_VALUE;
}

