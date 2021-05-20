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

#pragma once
#include "externStruct/Struct_ISU.h"

#include "sourceApp/mainwindow.h"
//class MainWindow w;
extern  QSharedMemory SHARE_ADVANTECH;
extern  SH_DEVICE_CONNECT *pDev;

extern  QSharedMemory SHARE_RMI_PILOT;
extern  SH_FROMRMI_PILOT *pFromP;

extern  QSharedMemory SHARE_ISU;
extern  SH_ISU *pISU;

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
      pFromP = static_cast<SH_FROMRMI_PILOT*>(SHARE_RMI_PILOT.data());
      pISU = static_cast<SH_ISU*>(SHARE_ISU.data());

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
    antifire.S3_2610 = pDev->IN_MAT[289];
    antifire.S4_2610 = pDev->IN_MAT[291];
    //s5_2610l
    antifire.S5_2610 = pDev->IN_MAT[377];
    antifire.S6_2610 = pDev->IN_MAT[660];
    antifire.S7_2610 = pDev->IN_MAT[293];
    antifire.S8_2610 = pDev->IN_MAT[295];
    antifire.S9_2610 = pDev->IN_MAT[383];
    if(pDev->IN_MAT[864])antifire.S1_2610 = antifire.s1_2610::otkl;
    if(pDev->IN_MAT[865])antifire.S1_2610 = antifire.s1_2610::mg1dv;
    if(pDev->IN_MAT[866])antifire.S1_2610 = antifire.s1_2610::mg2dv;
    if(pDev->IN_MAT[867])antifire.S1_2610 = antifire.s1_2610::mg3dv;
    if(pDev->IN_MAT[868])antifire.S1_2610 = antifire.s1_2610::mg4dv;
    if(pDev->IN_MAT[869])antifire.S1_2610 = antifire.s1_2610::vsu;
    if(pDev->IN_MAT[870])antifire.S2_2610 = antifire.s2_2610::gr1;
    if(pDev->IN_MAT[871])antifire.S2_2610 = antifire.s2_2610::otk;
    if(pDev->IN_MAT[872])antifire.S2_2610 = antifire.s2_2610::gr2;
    if(pDev->IN_MAT[873])antifire.S2_2610 = antifire.s2_2610::gr3;
    if(pDev->IN_MAT[874])antifire.S2_2610 = antifire.s2_2610::gr4;
    if(pDev->IN_MAT[875])antifire.S2_2610 = antifire.s2_2610::gr5;
    if(pDev->IN_MAT[876])antifire.S2_2610 = antifire.s2_2610::gr6;
    if(pDev->IN_MAT[877])antifire.S2_2610 = antifire.s2_2610::pozhar;
    antifire.S10_2610 = pDev->IN_MAT[878];
    antifire.S11_2610 = pDev->IN_MAT[299];
    //s13_2610l
    antifire.S13_2610 = pDev->IN_MAT[297];
    antifire.S14_2610 = pDev->IN_MAT[664];
    //s15_2610l
    antifire.S15_2610 = pDev->IN_MAT[301];

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
{
    exchange::s1_2430 = pDev->IN_MAT[556];
    exchange::s4_2430 = pDev->IN_MAT[531];
    exchange::s5_2430 = pDev->IN_MAT[535];
    exchange::s8_2430 = pDev->IN_MAT[543];
    exchange::s11_2430 = pDev->IN_MAT[547];
    exchange::s2_2430 = pDev->IN_MAT[529];
    exchange::s9_2430 = pDev->IN_MAT[541];
    exchange::s14_2430 = pDev->IN_MAT[537];
    exchange::s15_2430 = pDev->IN_MAT[539];
    exchange::s7_2430 = pDev->IN_MAT[549];
    exchange::s13_2430 = pDev->IN_MAT[523];
    exchange::s10_2430 = pDev->IN_MAT[545];
    exchange::s3_2430 = pDev->IN_MAT[533];
    if(pDev->IN_MAT[576]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::akk1);
    if(pDev->IN_MAT[577]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::akk2);
    if(pDev->IN_MAT[578]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::avar1);
    if(pDev->IN_MAT[579]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::avar2);
    if(pDev->IN_MAT[580]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::sh1lev);
    if(pDev->IN_MAT[581]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::sh2lev);
    if(pDev->IN_MAT[582]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::sh1prav);
    if(pDev->IN_MAT[583]) exchange::s16_2430 = static_cast<int>(exchange::s16_2430::sh2prav);
    if(pDev->IN_MAT[525]) exchange::s17_2430 = static_cast<int>(exchange::s17_2430::akk1_rap1);
    if(pDev->IN_MAT[526]) exchange::s17_2430 = static_cast<int>(exchange::s17_2430::akk2_rap2);
    if(pDev->IN_MAT[527]) exchange::s17_2430 = static_cast<int>(exchange::s17_2430::vsu);
    powerdc.glviklvsu = pDev->IN_MAT[748];
    exchange::s1_7710 = pDev->IN_MAT[196];
    exchange::s2_7710 = pDev->IN_MAT[197];
    exchange::s3_7710 = pDev->IN_MAT[198];
    exchange::s4_7710 = pDev->IN_MAT[199];
    exchange::s1_2420 = pDev->IN_MAT[520];
    exchange::s5_2420 = pDev->IN_MAT[565];
    exchange::s10_2420 = pDev->IN_MAT[568];
    exchange::s13_2420 = pDev->IN_MAT[575];
    exchange::s4_2420 = pDev->IN_MAT[522];
    exchange::s12_2420 = pDev->IN_MAT[567];
    exchange::s8_2420 = pDev->IN_MAT[549];
    exchange::s2_2420 = pDev->IN_MAT[557];
    exchange::s9_2420 = pDev->IN_MAT[555];
    exchange::s15_2420 = pDev->IN_MAT[592];
    exchange::s21_2420 = pDev->IN_MAT[594];
    powerdc.s3_2420 = pDev->IN_MAT[561];
    powerdc.s6_2420 = pDev->IN_MAT[563];
    powerdc.s11_2420 = pDev->IN_MAT[571];
    powerdc.s14_2420 = pDev->IN_MAT[573];

    powerdc.OtkazGen1PostT = pFromP->Otkaz[20];
    powerdc.OtkazGen2PostT = pFromP->Otkaz[21];
    powerdc.OtkazGen3PostT = pFromP->Otkaz[22];
    powerdc.OtkazGen4PostT = pFromP->Otkaz[23];
    powerdc.otk_pereg_gen1 = pFromP->Otkaz[24];
    powerdc.otk_pereg_gen2 = pFromP->Otkaz[25];
    powerdc.otk_pereg_gen3 = pFromP->Otkaz[26];
    powerdc.otk_pereg_gen4 = pFromP->Otkaz[27];
    powerdc.otkPadDavlMaslPpo1G = pFromP->Otkaz[10];
    powerdc.otkPadDavlMaslPpo2G = pFromP->Otkaz[11];
    powerdc.otkPadDavlMaslPpo3G = pFromP->Otkaz[12];
    powerdc.otkPadDavlMaslPpo4G = pFromP->Otkaz[13];
    powerdc.otkGenPerT1 = pFromP->Otkaz[5];
    powerdc.otkGenPerT2 = pFromP->Otkaz[6];
    powerdc.otkGenPerT3 = pFromP->Otkaz[7];
    powerdc.otkGenPerT4 = pFromP->Otkaz[8];
    powerdc.OtkazGenVsu = pFromP->Otkaz[9];
    powerdc.otk_preobr_pts1 = pFromP->Otkaz[14];
    powerdc.otk_pos1000 = pFromP->Otkaz[15];
    powerdc.overload_gen1 = pFromP->Otkaz[16];
    powerdc.overload_gen2 = pFromP->Otkaz[17];
    powerdc.overload_gen3 = pFromP->Otkaz[18];
    powerdc.overload_gen4 = pFromP->Otkaz[19];
    powerdc.otk_pereg_akk1 = pFromP->Otkaz[28];
    powerdc.otk_pereg_akk2 = pFromP->Otkaz[29];

    exchange::eng1_spd = pISU->nvd1;
    exchange::eng2_spd = pISU->nvd2;
    exchange::eng3_spd = pISU->nvd3;
    exchange::eng4_spd = pISU->nvd4;

}
void IN_presure_int        ()
{}
void IN_wingsmech_int      ()
{}


//================== OUT Data
void OUT_antifire_int       ()
{
    pDev->OUT_D[0][1]=antiicing.PONdv4;

    pDev->OUT_D[0][98] = bss_inst.BSS811X2U;
    pDev->OUT_D[0][99] = bss_inst.BSS811X2W;
    pDev->OUT_D[0][100] = bss_inst.BSS812X6S;
    pDev->OUT_D[0][101] = bss_inst.BSS812X6U;
    pDev->OUT_D[0][106] = bss_inst.BSS811X2Z;
    pDev->OUT_D[0][107] = bss_inst.BSS811X2a;
    pDev->OUT_D[0][108] = bss_inst.BSS913X2j;
    pDev->OUT_D[0][109] = bss_inst.BSS913X2k;
    pDev->OUT_D[0][112] = bss_inst.BSS913X2m;
    pDev->OUT_D[0][111] = bss_inst.BSS913X2n;
    pDev->OUT_D[0][110] = bss_inst.BSS913X2p;
    pDev->OUT_D[0][97] = bss_inst.BSS811X2Y;
    pDev->OUT_D[0][102] = bss_inst.BSS811X2V;
    pDev->OUT_D[0][103] = bss_inst.BSS811X2X;
    pDev->OUT_D[0][104] = bss_inst.BSS812X6T;
    pDev->OUT_D[0][105] = bss_inst.BSS812X6V;
    pDev->OUT_D[0][96] = bss_inst.BSS811X2b;
    pDev->OUT_D[0][19] = bss_inst.BSS811X2D;
    pDev->OUT_D[2][69] = bss_inst.BSS838X6p;
    pDev->OUT_D[2][79] = bss_inst.BSS838X6i;
    pDev->OUT_D[2][80] = bss_inst.BSS926X2R;
    pDev->OUT_D[2][81] = bss_inst.BSS926X2S;
    pDev->OUT_D[2][82] = bss_inst.BSS926X2T;
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
{
    pDev->OUT_D[2][32] = bss_inst.BSS837X2P;
    pDev->OUT_D[2][33] = bss_inst.BSS837X2V;
    pDev->OUT_D[2][27] = bss_inst.BSS926X2i;
    pDev->OUT_D[2][11] = bss_inst.BSS926X2g;
    pDev->OUT_D[2][46] = bss_inst.BSS926X2m;
    pDev->OUT_D[2][14] = bss_inst.BSS926X2h;
    pDev->OUT_D[2][24] = bss_inst.BSS926X2n;
    pDev->OUT_D[2][12] = bss_inst.BSS926X2z;
    pDev->OUT_D[2][15] = bss_inst.BSS926X2b;
    pDev->OUT_D[2][22] = bss_inst.BSS837X2X;
    pDev->OUT_D[2][25] = bss_inst.BSS837X2T;
    pDev->OUT_D[2][13] = bss_inst.BSS926X2a;
    pDev->OUT_D[2][16] = bss_inst.BSS926X2c;
    pDev->OUT_D[2][23] = bss_inst.BSS837X2Y;
    pDev->OUT_D[2][26] = bss_inst.BSS837X2U;
    pDev->OUT_D[2][28] = bss_inst.BSS926X2j;
    pDev->OUT_D[2][30] = bss_inst.BSS837X2N;
    pDev->OUT_D[2][31] = bss_inst.BSS837X2R;
    pDev->OUT_D[2][34] = bss_inst.BSS837X2W;
    pDev->OUT_D[2][35] = bss_inst.BSS837X2S;
    pDev->OUT_D[2][17] = bss_inst.BSS926X2d;
    pDev->OUT_D[2][19] = bss_inst.BSS837X2Z;
    pDev->OUT_D[2][18] = bss_inst.BSS926X2e;
    pDev->OUT_D[2][20] = bss_inst.BSS837X2a;
    pDev->OUT_D[2][39] = bss_inst.BSS838X6C;
    pDev->OUT_D[2][41] = bss_inst.BSS838X6G;
    pDev->OUT_D[2][48] = bss_inst.BSS837X2p;
    pDev->OUT_D[2][50] = bss_inst.BSS837X2i;
    pDev->OUT_D[2][54] = bss_inst.BSS926X2q;
    pDev->OUT_D[2][55] = bss_inst.BSS926X2r;
    pDev->OUT_D[2][56] = bss_inst.BSS837X2d;
    pDev->OUT_D[2][40] = bss_inst.BSS838X6D;
    pDev->OUT_D[2][42] = bss_inst.BSS838X6H;
    pDev->OUT_D[2][22] = bss_inst.BSS837X2q;
    pDev->OUT_D[2][51] = bss_inst.BSS837X2j;
    pDev->OUT_D[2][38] = bss_inst.BSS838X6B;
    pDev->OUT_D[2][44] = bss_inst.BSS838X6F;
    pDev->OUT_D[2][47] = bss_inst.BSS837X2n;
    pDev->OUT_D[2][53] = bss_inst.BSS837X2h;
    pDev->OUT_D[2][37] = bss_inst.BSS838X6A;
    pDev->OUT_D[2][43] = bss_inst.BSS838X6E;
    pDev->OUT_D[2][22] = bss_inst.BSS837X2m;
    pDev->OUT_D[2][52] = bss_inst.BSS837X2g;
    pDev->OUT_D[2][57] = bss_inst.BSS837X2b;
    pDev->OUT_D[2][58] = bss_inst.BSS837X2c;
    pDev->OUT_D[2][59] = bss_inst.BSS837X2k;
    pDev->OUT_D[2][60] = bss_inst.BSS837X2f;
    pDev->OUT_D[2][36] = bss_inst.BSS926X2P;
    pDev->OUT_D[2][45] = bss_inst.BSS837X2e;
    pDev->OUT_D[2][5] = bss_inst.BSS837X2E;
    pDev->OUT_D[2][6] = bss_inst.BSS837X2H;
    pDev->OUT_D[2][9] = bss_inst.BSS837X2G;
    pDev->OUT_D[2][10] = bss_inst.BSS837X2K;
    pDev->OUT_D[2][7] = bss_inst.BSS837X2F;
}

void OUT_presure_int        ()
{}

void OUT_wingsmech_int      ()
{}

