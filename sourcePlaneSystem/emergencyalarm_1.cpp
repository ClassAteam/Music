#include "emergencyalarm_1.h"
#include "externStruct/Struct_DeviceConnect.h"

extern  SH_DEVICE_CONNECT *pDev;


void emergencyalarm_int::emergencyalarm_1()
{

//    for(auto & element : lights)
//    {
//        *(element->outClue) = element->inClue;
//        qDebug() << "out_clue:" << element->outClue <<"out_address:" << &element->outClue;
//        qDebug() << "in_clue:" << element->inClue <<"in_address:" << &element->inClue;
//        pDev->OUT_D[2][18] = (element->inClue);
//        pDev->OUT_D[2][20] = (element->inClue);
//    }

    for(int i = 0; i < lights.count(); ++i)
    {
        *(lights[i]->outClue) = (lights[i]->inClue);
        qDebug() << "out_clue:" << lights[i]->outClue <<"out_address:" << &lights[i]->outClue;
        qDebug() << "in_clue:" <<  lights[i]->inClue <<"in_address:" << &lights[i]->inClue;

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
