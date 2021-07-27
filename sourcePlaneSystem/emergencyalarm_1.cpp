#include "emergencyalarm_1.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT *pDev;


void emergencyalarm_int::emergencyalarm_1()
{

    for(auto & element : lights)
    {
        *(element->outClue) = *(element->inClue);
//        pDev->OUT_D[2][18] = *(element->inClue);
    }
    if(exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0)
        PRBSS_939 = true;
    else
        PRBSS_939 = false;

    if (exchange::ush2dpl >= 18.0 && exchange::ush2dpp >= 18.0 && exchange::s8_3364)
        PKLSHN = true;
    else
        PKLSHN = false;

}
//logic ends
