#include "land_comstations.h"

extern SH_ISU ISU;


land_comstations::land_comstations()
{


}

land_comstations &land_comstations::instance()
{
    static land_comstations singleton;
    return singleton;
}

ilsLocalizer land_comstations::takeIlsLocalizer()
{
    ilsLocalizer nullLocalizer;
    for(auto &beacon: ilsBeacons)
    {
        if((positon.x - beacon.x) < 2000 && (positon.y - beacon.y) < 2000)
        {
            double azimuthSub;
            azimuthSub = ISU.NorthAngle - beacon.magneticAzimuth;
            if(azimuthSub <= 30.0)
            {
                beacon.value = azimuthSub / 100;
                return beacon;
            }
        }
    }
    return nullLocalizer;
}

vorBeacon land_comstations::tryBeaconCapture(const double freq)
{
    vorBeacon null;
    for(auto &beacon : beacons)
    {
        if(beacon.freq == freq && beacon.distance < VISUAL_DISTANCE)
        {
            return beacon;
        }
    }
    return null;
}

bool operator!=(const vorBeacon& beacon1, const vorBeacon& beacon2)
{
    if(beacon1.name != beacon2.name)
        return true;
    else
        return false;
}
bool operator!=(const ilsLocalizer& localizer1, const ilsLocalizer& localizer2)
{
    if(localizer1.name != localizer2.name)
        return true;
    else
        return false;
}
