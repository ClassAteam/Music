#include "vim95.h"


VIM95::VIM95(modeType mode_in) : mode{mode_in}
{

}

VIM95::vor::vor(int *course_in, double *freq_in,
                const QVector<SH_ISU::VorBeacon>& stations_in) : course{course_in},
    freq{freq_in}, beacons{&stations_in}
{

}

bool VIM95::vor::tryBeaconCapture()
{
    for(auto &beacon : *beacons)
    {
        if(beacon.freq == *freq && beacon.distance < VISUAL_DISTANCE)
        {
            currBeacon = beacon;
            return true;
        }
    }
    return false;
}

bool VIM95::vor::producePack()
{
    if(tryBeaconCapture())
    {
        pack.beaconCourse = currBeacon.angle;
    }

}

