#include "vim95.h"
#include "externStruct/Struct_ISU.h"
#include "algorithms.h"

extern SH_ISU ISU;
extern SH_ISU* pISU;

VIM95::VIM95()
{
    vor.setFreq(150.0);
}

VIM95 &VIM95::instance()
{
    static VIM95 singleton;
    return singleton;
}

void VIM95::vorSystem::updateParams()
{
    curBeacon = land_comstations::instance().tryVorCapture(freq, pISU->planePosX,
                                                           pISU->planePosY);
    if(curBeacon->checkName() == "none") return;

    northCourseToBeacon = curBeacon->northCourseToBeacon(pISU->planePosX,
                                                         pISU->planePosY);

    relativeCourseToBeacon = curBeacon->relativeCourseToBeacon(
        pISU->planePosX, pISU->planePosY, pISU->NorthAngle);

    to_from = curBeacon->to_from(pISU->planePosX, pISU->planePosY,
                                 pISU->NorthAngle);
}

void VIM95::vorSystem::setFreq(double freq_in)
{
    freq = freq_in;
}

void VIM95::ilsSystem::updateParams()
{
    currBeacon = land_comstations::instance().tryIlsCapture(pISU->planePosX,
                                                               pISU->planePosY);
    if(currBeacon->checkName() == "none") return;

    HorizonArrowValue = currBeacon->proceedValue();
    GlissadeArrowValue = currBeacon->proceedGlissadeValue();
}


