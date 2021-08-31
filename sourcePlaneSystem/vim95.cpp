#include "vim95.h"
#include "externStruct/Struct_ISU.h"
#include "algorithms.h"

extern SH_ISU ISU;
extern SH_ISU* pISU;
const double MAXIMUM_HORIZON_ARROW_VALUE{1000};
const double MAXIMUM_VERT_ARROW_VALUE{10000};

VIM95::VIM95()
{
    vor.setFreq(150.0);
}

VIM95 &VIM95::instance()
{
    static VIM95 singleton;
    return singleton;
}


bool VIM95::vorSystem::tryBeaconCapture()
{
    curBeacon = land_comstations::instance().tryVorCapture(freq, pISU->planePosX,
                                                           pISU->planePosY);
    if(curBeacon->checkName() != "none")
        return true;
    return false;
}

void VIM95::vorSystem::updateParams()
{
    if(tryBeaconCapture())
    {
        northCourseToBeacon = curBeacon->northCourseToBeacon(pISU->planePosX,
                                                             pISU->planePosY);

        relativeCourseToBeacon = curBeacon->relativeCourseToBeacon(
            pISU->planePosX, pISU->planePosY, pISU->NorthAngle);

        to_from = curBeacon->to_from(pISU->planePosX, pISU->planePosY,
                                     pISU->NorthAngle);
    }
    else
    {
        northCourseToBeacon = -999999.0;
        relativeCourseToBeacon = -999999.0;
    }
}

void VIM95::vorSystem::setFreq(double freq_in)
{
    freq = freq_in;
}

bool VIM95::ilsSystem::tryBeaconCapture()
{
    currBeacon = land_comstations::instance().tryIlsCapture(pISU->planePosX,
                                                               pISU->planePosY);
    if(currBeacon->checkName() != "none")
        return true;
    return false;
}

double VIM95::ilsSystem::proceedHorizonValue()
{
    if(tryBeaconCapture())
    {
        return currBeacon->proceedValue();
    }
    return MAXIMUM_HORIZON_ARROW_VALUE;
}

double VIM95::ilsSystem::proceedGlissadeValue()
{
    if(tryBeaconCapture())
    {
        return currBeacon->proceedGlissadeValue();
    }
    return MAXIMUM_VERT_ARROW_VALUE;
}

void VIM95::ilsSystem::updateParams()
{
    HorizonArrowValue = proceedHorizonValue();
    GlissadeArrowValue = proceedGlissadeValue();
}


