#include "vim95.h"
#include "externStruct/Struct_ISU.h"

extern SH_ISU ISU;
extern SH_ISU* pISU;

void VIM95::vorSystem::updateParams()
{
    double x = VIM95::instance().xJetPosition();
    double y = VIM95::instance().yJetPosition();
    double ang = VIM95::instance().PolarAngle();

    currBeacon = land_comstations::instance().tryVorCapture(freq, x, y);
    if(currBeacon->checkName() == "none")
    {
        northCourseToBeacon = -999.0;
        relativeCourseToBeacon = -999.0;
        to_from = false;
        capturedBeaconName = currBeacon->checkName();
        return;
    }

    northCourseToBeacon = currBeacon->northCourseToBeacon(x, y);
    relativeCourseToBeacon = currBeacon->relativeCourseToBeacon(x, y, ang);
    to_from = currBeacon->to_from(x, y, ang);
    capturedBeaconName = currBeacon->checkName();
}

void VIM95::ilsSystem::updateParams()
{
    double x = VIM95::instance().xJetPosition();
    double y = VIM95::instance().yJetPosition();
    double z = VIM95::instance().zJetPosition();

    currBeacon = land_comstations::instance().tryIlsCapture(x, y);
    if(currBeacon->checkName() == "none")
    {
        HorizonArrowValue = -999.0;
        GlissadeArrowValue = -999.0;
        capturedBeaconName = currBeacon->checkName();
        return;
    }

    HorizonArrowValue = currBeacon->distanceToGlissadeProj(x, y);
    GlissadeArrowValue = currBeacon->distnaceToGlissadePlane(x, y, z);
    capturedBeaconName = currBeacon->checkName();
}

VIM95::VIM95() : xJetPos{&pISU->planePosX}, yJetPos{&pISU->planePosY},
    zJetPos{&pISU->planePosZ}, JetPolarAngle{&pISU->NorthAngle}
{
    vor.setFreq(150.0);
}

VIM95 &VIM95::instance()
{
    static VIM95 singleton;
    return singleton;
}

void VIM95::vorSystem::setFreq(double freq_in)
{
    freq = freq_in;
}

double VIM95::xJetPosition()
{
    return *xJetPos;
}
double VIM95::yJetPosition()
{
    return *yJetPos;
}
double VIM95::zJetPosition()
{
    return *zJetPos;
}

double VIM95::PolarAngle()
{
    return *JetPolarAngle;

}
