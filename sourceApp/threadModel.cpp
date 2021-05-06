//#define __WIN__

//#ifndef __WIN__   //============================
//#include < unistd.h >
//#else
//#include <windows.h>
////void usleep(__int64 usec)
////{
////    HANDLE timer;
////    LARGE_INTEGER ft;

////    ft.QuadPart = -(10*usec); // Convert to 100 nanosecond interval, negative value indicates relative time

////    timer = CreateWaitableTimer(NULL, TRUE, NULL);
////    SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
////    WaitForSingleObject(timer, INFINITE);
////    CloseHandle(timer);
////}

//#endif//===================


//#include <chrono>
#include <QSharedMemory>
#include "threadModel.h"

#include "externStruct/Struct_FromRmiPilot.h"
#include "externStruct/Struct_DeviceConnect.h"
#include "externStruct/Struct_FromRmiOper.h"
#include "externStruct/Struct_FromRmiPilot.h"
#include "sourceApp/utilTimeClassQt.h"

#include "sourceApp/mainwindow.h"
//class MainWindow w;
extern  QSharedMemory SHARE_ADVANTECH;
extern  SH_DEVICE_CONNECT *pDev;

bool exitThreadModel=0;
extern TimeClass* pFramePlanSys;
extern TimeClass* pFrameModel;
extern double TICK;

////////////////////////////////////////////////#include "sourcePlaneSystem/brakes_1.h"
antifire_int       antifire      ;
antiicing_int      antiicing     ;
brakes_int         brakes        ;
cabinlighting_int  cabinlighting ;
emergencyalarm_int emergencyalarm;
hydro_int          hydro         ;
landinggear_int    landinggea    ;
pneumatic_int      pneumatic     ;
powerdc_int        powerdc       ;
presure_int        presure       ;
wingsmech_int      wingsmech     ;

void IN_antifire_int       ();
void IN_antiicing_int      ();
void IN_brakes_int         ();
void IN_cabinlighting_int  ();
void IN_emergencyalarm_int ();
void IN_hydro_int          ();
void IN_landinggear_int    ();
void IN_pneumatic_int      ();
void IN_powerdc_int        ();
void IN_presure_int        ();
void IN_wingsmech_int      ();

void OUT_antifire_int       ();
void OUT_antiicing_int      ();
void OUT_brakes_int         ();
void OUT_cabinlighting_int  ();
void OUT_emergencyalarm_int ();
void OUT_hydro_int          ();
void OUT_landinggear_int    ();
void OUT_pneumatic_int      ();
void OUT_powerdc_int        ();
void OUT_presure_int        ();
void OUT_wingsmech_int      ();



void dispPlanSystem()
{
      pFramePlanSys->StartNow();

//      if (SHARE_ADVANTECH.isAttached())
//      {
//           SHARE_ADVANTECH.lock();
//           memcpy(pDev ,SHARE_ADVANTECH.data(), sizeof(SH_DEVICE_CONNECT));
//           SHARE_ADVANTECH.unlock();
//      }

      pDev = static_cast<SH_DEVICE_CONNECT*>(SHARE_ADVANTECH.data());
      IN_antifire_int       ();
      antifire.updateLogic();
      OUT_antifire_int       ();

      IN_antiicing_int      ();
      antiicing.updateLogic();
      OUT_antiicing_int      ();


      IN_brakes_int         ();
      brakes.updateLogic();
      OUT_brakes_int         ();

      IN_cabinlighting_int  ();
      cabinlighting.updateLogic();
      OUT_cabinlighting_int  ();

      IN_emergencyalarm_int ();
      emergencyalarm.updateLogic();
      OUT_emergencyalarm_int ();

      IN_hydro_int          ();
      hydro.updateLogic();
      OUT_hydro_int          ();

      IN_landinggear_int    ();
      landinggea.updateLogic();
      OUT_landinggear_int    ();

      IN_pneumatic_int      ();
      pneumatic.updateLogic();
      OUT_pneumatic_int      ();

      IN_powerdc_int        ();
      powerdc.updateLogic();
      OUT_powerdc_int        ();

      IN_presure_int        ();
      presure.updateLogic();
      OUT_presure_int        ();

      IN_wingsmech_int      ();
      wingsmech.updateLogic();
      OUT_wingsmech_int      ();

//      if (SHARE_ADVANTECH.isAttached())
//      {
//           SHARE_ADVANTECH.lock();
//           memcpy(SHARE_ADVANTECH.data(), pDev , sizeof(SH_DEVICE_CONNECT));
//           SHARE_ADVANTECH.unlock();
//      }
      pFramePlanSys->StartThen();
}//

//=================================
//    antifire_1();
//    antifire_2();
//    antifire_3();

//    antiicing_1();
//    antiicing_2();
//    antiicing_3();
//    antiicing_4();
//    antiicing_5();
//    antiicing_6();

//    brakes_1();
//    brakes_2();
//    brakes_3();
//    brakes_4();
//    brakes_5();
//    brakes_6();

//    cabinlighting_1();
//    cabinlighting_2();
//    cabinlighting_3();
//    cabinlighting_4();
//    cabinlighting_5();

//    emergencyalarm_1();
//    emergencyalarm_2();
//    emergencyalarm_3();
//    emergencyalarm_4();
//    emergencyalarm_5();
//    emergencyalarm_6();
//    emergencyalarm_7();
//    emergencyalarm_8();
//    emergencyalarm_9();

//    hydro_1();
//    hydro_2();
//    hydro_3();
//    hydro_4();
//    hydro_5();
//    hydro_7();
//    hydro_8();
//    hydro_9();

//    landinggear_1();
//    landinggear_2();
//    landinggear_3();
//    landinggear_4();
//    landinggear_5();
//    landinggear_6();
//    landinggear_7();
//    landinggear_8();
//    landinggear_9();

//    powerdc_1();
//    powerdc_2_3();
//    powerdc_4();
//    powerdc_5_6();
//    powerdc_7();
//    powerdc_8();
//    powerdc_9_10();
//    powerdc_11();
//    powerdc_12();
//    powerdc_13();
//    powerdc_14();
//    powerdc_15();
//    powerdc_16();

//    presure();

//    wingsmech_1();
//    wingsmech_2();
//    wingsmech_3();
//    wingsmech_4();


//=================  ThreadModel
void ThreadModel::run ()
{

    //while(!exitThreadModel)
    while(1)
    {
        pFrameModel->StartFrame();
//        pFramePlanSys->StartNow();
        dispPlanSystem() ;
//        pFramePlanSys->StartThen();
        //useconds_t usec=1000;//(unsigned int)(TICK-pFramePlanSys->_FrameOne)*1000.0;
        //usleep (usec);
        this->usleep(3990);
        //Sleep();
    }

//int a=1+0;
//int b =a;
}//

//===============  INPUT Data
void IN_antifire_int       ()
{
    antifire.pnu=antiicing.PBSO1;
    antifire.PPBI= pDev->IN_D[0][1];
    qDebug() << "raw struct value IN_D_0_1 " << antifire.PPBI;

}
void IN_antiicing_int      ()
{
    antiicing.POLST=pDev->IN_MAT [15];
}
void IN_brakes_int         ()
{}
void IN_cabinlighting_int  ()
{}
void IN_emergencyalarm_int ()
{}
void IN_hydro_int          ()
{}
void IN_landinggear_int    ()
{}
void IN_pneumatic_int      ()
{}
void IN_powerdc_int        ()
{}
void IN_presure_int        ()
{}
void IN_wingsmech_int      ()
{}


//================== OUT Data
void OUT_antifire_int       ()
{
    pDev->OUT_D[0][1]=antiicing.PONdv4;
}

void OUT_antiicing_int      ()
{}

void OUT_brakes_int         ()
{}

void OUT_cabinlighting_int  ()
{}

void OUT_emergencyalarm_int ()
{}

void OUT_hydro_int          ()
{}

void OUT_landinggear_int    ()
{}

void OUT_pneumatic_int      ()
{}

void OUT_powerdc_int        ()
{}

void OUT_presure_int        ()
{}

void OUT_wingsmech_int      ()
{}

