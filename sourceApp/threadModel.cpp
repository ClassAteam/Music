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
aircondition_int   aircondition  ;
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

void IN_aircondition_int   ();
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

void OUT_aircondition_int   ();
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

      IN_aircondition_int       ();
      aircondition.updateLogic();
      OUT_aircondition_int       ();

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
void IN_aircondition_int()
{
    if(pDev->IN_MAT[640])
        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::avtomat);else
    if(pDev->IN_MAT[641])
        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::hol);else
    if(pDev->IN_MAT[642])
        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::gor);else
        exchange::s1_2151 = static_cast<int>(exchange::s1_2151::neytr);

    exchange::s1_2110 = pDev->IN_MAT[637];
    exchange::s2_2110 = pDev->IN_MAT[639];
    exchange::s3_2110 = pDev->IN_MAT[619];
    exchange::s4_2110 = pDev->IN_MAT[621];
    exchange::s7_7322 = pDev->IN_MAT[354];
    exchange::s8_7322 = pDev->IN_MAT[355];
    exchange::s9_7322 = pDev->IN_MAT[356];
    exchange::s10_7322 = pDev->IN_MAT[357];
    exchange::s5_2110 = pDev->IN_MAT[622];
    exchange::s1_2120 = pDev->IN_MAT[630];
    exchange::s3_2120 = pDev->IN_MAT[635];
    exchange::s6_2120 = pDev->IN_MAT[631];
    exchange::s2_2120 = pDev->IN_MAT[614];
    exchange::s4_2120 = pDev->IN_MAT[616];
    exchange::s5_2120 = pDev->IN_MAT[623];
    exchange::s2_2151 = pDev->IN_MAT[289];
    exchange::s3_2151 = pDev->IN_MAT[36];
    exchange::s4_2151 = pDev->IN_MAT[88];
    exchange::s5_2151 = pDev->IN_MAT[600];
    exchange::s6_2151 = pDev->IN_MAT[778];
    exchange::s1_2158 = pDev->IN_MAT[647];
    exchange::s1_2152 = pDev->IN_MAT[644];
    exchange::s1_2153 = pDev->IN_MAT[608];
    exchange::s2_2153 = pDev->IN_MAT[610];
    exchange::s2_2159 = pDev->IN_MAT[628];
    exchange::s1_2159 = pDev->IN_MAT[626];
    exchange::s1_2112 = pDev->IN_MAT[174];
    exchange::s4_2112 = pDev->IN_MAT[175];
    exchange::s1_12360 = pDev->IN_MAT[649];
    exchange::s2_12360 = pDev->IN_MAT[624];
    exchange::s3_12360 = pDev->IN_MAT[612];

    exchange::tnv = pISU->tnv;
    exchange::tke_vh = pDev->IN_A[1][8];
    exchange::pk70_vkl = pISU->pk70_vkl;
    exchange::pk70_pgo = pISU->pk70_pgo;
    exchange::pk70_zgo = pISU->pk70_zgo;
    exchange::pk70_kontrt = pISU->pk70_kontrt;
    aircondition.puvzl = pISU->puvzl;
    aircondition.puvzp = pISU->puvzp;

    aircondition.otkaz_lev_mag = pFromP->Otkaz[53];
    aircondition.otkaz_prav_mag = pFromP->Otkaz[54];
    aircondition.otkaz_RID_1dv = pFromP->Otkaz[55];
    aircondition.otkaz_RID_2dv = pFromP->Otkaz[56];
    aircondition.otkaz_RID_3dv = pFromP->Otkaz[57];
    aircondition.otkaz_RID_4dv = pFromP->Otkaz[58];
    aircondition.otkaz_povishTemprVozd1 = pFromP->Otkaz[102];
    aircondition.otkaz_povishDavlVozMag1 = pFromP->Otkaz[103];
    aircondition.otkaz_povishTemprVozd2 = pFromP->Otkaz[104];
    aircondition.otkaz_povishDavlVozMag2 = pFromP->Otkaz[105];
    aircondition.otkaz_thu1 = pFromP->Otkaz[106];
    aircondition.otkaz_thu2 = pFromP->Otkaz[107];
    aircondition.otkaz_thu3 = pFromP->Otkaz[108];
    aircondition.otkaz_thu4 = pFromP->Otkaz[109];
    aircondition.otkaz_per_to_zad = pFromP->Otkaz[110];

}
void IN_antifire_int       ()
{
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
    antifire.F135_2805 = pDev->IN_MAT[337];
    antifire.F145_2805 = pDev->IN_MAT[339];
    antifire.F155_2805 = pDev->IN_MAT[341];
    antifire.F165_2805 = pDev->IN_MAT[343];

    antifire.pozhar_1_dv = pFromP->Otkaz[30];
    antifire.pozhar_2_dv = pFromP->Otkaz[31];
    antifire.pozhar_3_dv = pFromP->Otkaz[32];
    antifire.pozhar_4_dv = pFromP->Otkaz[33];
    antifire.pozhar_vsu = pFromP->Otkaz[34];
    antifire.peregrev_1_dv = pFromP->Otkaz[35];
    antifire.peregrev_2_dv = pFromP->Otkaz[36];
    antifire.peregrev_3_dv = pFromP->Otkaz[37];
    antifire.peregrev_4_dv = pFromP->Otkaz[38];
    antifire.otkaz_avtomatiki_SPZ = pFromP->Otkaz[39];
    antifire.lzh_srab_pereg_1_dv = pFromP->Otkaz[40];
    antifire.lzh_srab_pereg_2_dv = pFromP->Otkaz[41];
    antifire.lzh_srab_pereg_3_dv = pFromP->Otkaz[42];
    antifire.lzh_srab_pereg_4_dv = pFromP->Otkaz[43];

    if(pFromP->balAntifireToFull) antifire.pnu = true;
    else antifire.pnu = false;


}
void IN_antiicing_int      ()
{
    if(pDev->IN_MAT[169])
        exchange::s1_3020 = static_cast<int>(exchange::s1_3020::zerominus6);
    else if(pDev->IN_MAT[170])
        exchange::s1_3020 = static_cast<int>(exchange::s1_3020::minus6minus15);
    else if(pDev->IN_MAT[171])
        exchange::s1_3020 = static_cast<int>(exchange::s1_3020::minus15);
    else  exchange::s1_3020 = static_cast<int>(exchange::s1_3020::neytr);

    exchange::s4_3040 = pDev->IN_MAT[162];
    exchange::s6_3040 = pDev->IN_MAT[163];
    exchange::s2_3020 = pDev->IN_MAT[843];
    exchange::s3_3020 = pDev->IN_MAT[844];
    exchange::s4_3020 = pDev->IN_MAT[845];
    exchange::s5_3020 = pDev->IN_MAT[846];
    exchange::s6_3020 = pDev->IN_MAT[853];

    if(pDev->IN_MAT[849])
        exchange::s7_3040 = static_cast<int>(exchange::s7_3040::otkl);
    else if(pDev->IN_MAT[850])
        exchange::s7_3040 = static_cast<int>(exchange::s7_3040::lev);
    else if(pDev->IN_MAT[851])
        exchange::s7_3040 = static_cast<int>(exchange::s7_3040::lob);
    else if(pDev->IN_MAT[852])
        exchange::s7_3040 = static_cast<int>(exchange::s7_3040::prav);

    exchange::s1_3030 = pDev->IN_MAT[760];
    exchange::s2_3030 = pDev->IN_MAT[52];
    exchange::s2_3040 = pDev->IN_MAT[50];
    exchange::s8_3040 = pDev->IN_MAT[848];
    exchange::s1_3080 = pDev->IN_MAT[189];
    exchange::s2_3080 = pDev->IN_MAT[190];
    exchange::s3_3080 = pDev->IN_MAT[191];

    antiicing.otkaz_vozduhozabor = pFromP->Otkaz[44];
    antiicing.OTKAZ_vtsepiob_pos1dv = pFromP->Otkaz[45];
    antiicing.OTKAZ_vtsepiob_pos2dv = pFromP->Otkaz[46];
    antiicing.OTKAZ_vtsepiob_pos3dv = pFromP->Otkaz[47];
    antiicing.OTKAZ_vtsepiob_pos4dv = pFromP->Otkaz[48];
    antiicing.otkaz_l_so121 = pFromP->Otkaz[49];
    antiicing.otkaz_p_so121 = pFromP->Otkaz[50];
    antiicing.otkaz_lozhn_srab_lev_so121 = pFromP->Otkaz[51];
    antiicing.otkaz_lozhn_srab_prav_so121 = pFromP->Otkaz[52];

    antiicing.M_buf = pISU->M;
    antiicing.signal_obled = pFromP->icing;
}
void IN_brakes_int         ()
{
    brakes.s1_7620 = pDev->IN_MAT[336];
    brakes.s2_7620 = pDev->IN_MAT[338];
    brakes.s3_7620 = pDev->IN_MAT[340];
    brakes.s4_7620 = pDev->IN_MAT[342];

    exchange::s1_3240 = pDev->IN_MAT[12];
    if(pDev->IN_MAT[12])
        exchange::s1_3240 = static_cast<int>(exchange::s1_3240::slabo);
    else if(pDev->IN_MAT[13])
        exchange::s1_3240 = static_cast<int>(exchange::s1_3240::ponizh);
    else if(pDev->IN_MAT[14])
        exchange::s1_3240 = static_cast<int>(exchange::s1_3240::norm);

    if(pDev->IN_MAT[15]) exchange::s2_3240 = true;
    else exchange::s2_3240 = false;
    if(pDev->IN_MAT[11]) exchange::s3_3240 = true;
    else exchange::s3_3240 = false;
    if(pDev->IN_MAT[9]) exchange::s1_3241 = true;
    else exchange::s1_3241 = false;

    exchange::alpha_rud_1dv = pDev->IN_A[0][5];
    exchange::alpha_rud_2dv = pDev->IN_A[0][6];
    exchange::alpha_rud_3dv = pDev->IN_A[0][7];
    exchange::alpha_rud_4dv = pDev->IN_A[0][8];
    exchange::X_ped11 = pDev->IN_A[0][10];
    exchange::X_ped12 = pDev->IN_A[0][11];
    exchange::X_ped21 = pDev->IN_A[0][13];
    exchange::X_ped22 = pDev->IN_A[0][14];

    brakes.otkaz_osn_sis_torm = pFromP->Otkaz[82];
    brakes.otkaz_rt = pFromP->Otkaz[83];
    brakes.otkaz_avt_per_na_rt = pFromP->Otkaz[84];
    brakes.otkaz_ots_dav_v1k_levt = pFromP->Otkaz[85];
    brakes.otkaz_ots_dav_v1k_pravt = pFromP->Otkaz[102];
    brakes.vkx = pISU->vkx;

}
void IN_cabinlighting_int  ()
{
    cabinlighting.S1_3340 = pDev->IN_MAT[289];
    cabinlighting.S6_3340 = pDev->IN_MAT[129];
    if(pDev->IN_MAT[129])
        cabinlighting.S6_3340 = static_cast<int>(cabinlighting.s6_3340::vzlpos);
    if(pDev->IN_MAT[130])
        cabinlighting.S6_3340 = static_cast<int>(cabinlighting.s6_3340::otkl);
    if((!pDev->IN_MAT[129]) && (!pDev->IN_MAT[130]))
        cabinlighting.S6_3340 = static_cast<int>(cabinlighting.s6_3340::rulenie);
    //uniqness of toggling bit contracted by peg updSmth() method
    if(pDev->IN_MAT[133])
        cabinlighting.S1_3341 = static_cast<int>(cabinlighting.S1_3341::ANO10);
    if(pDev->IN_MAT[134])
        cabinlighting.S1_3341 = static_cast<int>(cabinlighting.S1_3341::ANO30);
    if(pDev->IN_MAT[135])
        cabinlighting.S1_3341 = static_cast<int>(cabinlighting.S1_3341::ANO100);
    if(pDev->IN_MAT[136])
        cabinlighting.S1_3341 = static_cast<int>(cabinlighting.S1_3341::MIGANIE);
    cabinlighting.s1_2860 = pDev->IN_MAT[144];
    cabinlighting.S2_3340 = pDev->IN_MAT[137];
    if(pDev->IN_MAT[138])
        cabinlighting.S3_3340 = static_cast<int>(cabinlighting.S3_3340::vipusk);
    if(pDev->IN_MAT[139])
        cabinlighting.S3_3340 = static_cast<int>(cabinlighting.S3_3340::uborka);
    if((!pDev->IN_MAT[138]) && (!pDev->IN_MAT[139]))
        cabinlighting.S3_3340 = static_cast<int>(cabinlighting.S3_3340::otkl);

    if(pDev->IN_MAT[140])
        cabinlighting.S4_3340 = static_cast<int>(cabinlighting.S4_3340::vipusk);
    if(pDev->IN_MAT[141])
        cabinlighting.S4_3340 = static_cast<int>(cabinlighting.S4_3340::uborka);
    if((!pDev->IN_MAT[140]) && (!pDev->IN_MAT[141]))
        cabinlighting.S4_3340 = static_cast<int>(cabinlighting.S4_3340::otkl);

    cabinlighting.S5_3340 = pDev->IN_MAT[142];
    cabinlighting.s_11710[0] = pDev->IN_MAT[0];
    cabinlighting.s_11710[1] = pDev->IN_MAT[1];
    cabinlighting.s_11710[2] = pDev->IN_MAT[212];
    cabinlighting.s_11710[3] = pDev->IN_MAT[215];
    cabinlighting.s_11710[4] = pDev->IN_MAT[2];
    cabinlighting.s_11710[5] = pDev->IN_MAT[211];
    cabinlighting.s_11710[6] = pDev->IN_MAT[595];
    cabinlighting.s_11710[7] = pDev->IN_MAT[774];
    cabinlighting.s_11710[10] = pDev->IN_MAT[768];
    cabinlighting.s_11710[11] = pDev->IN_MAT[769];
    cabinlighting.s_11710[12] = pDev->IN_MAT[770];
    cabinlighting.s_11710[13] = pDev->IN_MAT[771];
    cabinlighting.bgs1 = pDev->IN_MAT[772];
    cabinlighting.bgs2 = pDev->IN_MAT[773];

    if(pDev->IN_MAT[131])
        cabinlighting.S2_3341 = static_cast<int>(cabinlighting.S2_3341::mayak100);
    if(pDev->IN_MAT[132])
        cabinlighting.S2_3341 = static_cast<int>(cabinlighting.S2_3341::ponizh);

    cabinlighting.otk_pbusto4[0][0] = pFromP->Otkaz[86];
    cabinlighting.otk_pbusto4[0][1] = pFromP->Otkaz[87];
    cabinlighting.otk_pbusto4[1][0] = pFromP->Otkaz[88];
    cabinlighting.otk_pbusto4[1][1] = pFromP->Otkaz[89];
    cabinlighting.otk_pbusto4[2][0] = pFromP->Otkaz[90];
    cabinlighting.otk_pbusto4[2][1] = pFromP->Otkaz[91];
    cabinlighting.otk_pbusto4[3][0] = pFromP->Otkaz[92];
    cabinlighting.otk_pbusto4[3][1] = pFromP->Otkaz[93];
    cabinlighting.otk_pbusto3[0][0] = pFromP->Otkaz[94];
    cabinlighting.otk_pbusto3[0][1] = pFromP->Otkaz[95];
    cabinlighting.otk_pbusto3[1][0] = pFromP->Otkaz[96];
    cabinlighting.otk_pbusto3[1][1] = pFromP->Otkaz[97];
    cabinlighting.otk_pbusto3[2][0] = pFromP->Otkaz[98];
    cabinlighting.otk_pbusto3[2][1] = pFromP->Otkaz[99];
    cabinlighting.otk_pbusto3[3][0] = pFromP->Otkaz[100];
    cabinlighting.otk_pbusto3[3][1] = pFromP->Otkaz[101];

    cabinlighting.Vpr = pISU->Vpr;
}
void IN_emergencyalarm_int ()
{}
void IN_hydro_int          ()
{
    hydro.EZR1_34 = pISU->ezr1_34;
    hydro.EZR2_34 = pISU->ezr2_34;
    hydro.EZR3_34 = pISU->ezr3_34;
    hydro.EZR4_34 = pISU->ezr4_34;
    hydro.PBI4M_1 = pISU->PBI4M_1;
    exchange::PRD1dv = pISU->prd1dv;
    exchange::PRD2dv = pISU->prd2dv;
    exchange::PRD3dv = pISU->prd3dv;
    exchange::PRD4dv = pISU->prd4dv;
    hydro.s1_2910 = pDev->IN_MAT[35];
    hydro.s2_2910 = pDev->IN_MAT[756];
    hydro.s3_2910 = pDev->IN_MAT[753];
    hydro.s4_2910 = pDev->IN_MAT[755];
    hydro.S5_2910 = pDev->IN_MAT[353];
    hydro.S6_2910 = pDev->IN_MAT[352];
    hydro.S7_2910 = pDev->IN_MAT[358];
    hydro.Sfirst4_2920[0] = pDev->IN_MAT[45];
    hydro.Sfirst4_2920[1] = pDev->IN_MAT[46];
    hydro.Sfirst4_2920[2] = pDev->IN_MAT[47];
    hydro.Sfirst4_2920[3] = pDev->IN_MAT[48];
    hydro.Ssecond4_2920[0] = pDev->IN_MAT[204];
    hydro.Ssecond4_2920[1] = pDev->IN_MAT[205];
    hydro.Ssecond4_2920[2] = pDev->IN_MAT[206];
    hydro.Ssecond4_2920[3] = pDev->IN_MAT[207];
    if(pDev->IN_MAT[37]) hydro.Sthird4_2920[0] = 0;
    if(pDev->IN_MAT[38]) hydro.Sthird4_2920[0] = 1;
    if(pDev->IN_MAT[39]) hydro.Sthird4_2920[1] = 0;
    if(pDev->IN_MAT[40]) hydro.Sthird4_2920[1] = 1;
    if(pDev->IN_MAT[41]) hydro.Sthird4_2920[2] = 0;
    if(pDev->IN_MAT[42]) hydro.Sthird4_2920[2] = 1;
    if(pDev->IN_MAT[43]) hydro.Sthird4_2920[3] = 0;
    if(pDev->IN_MAT[44]) hydro.Sthird4_2920[3] = 1;
    hydro.S13_2920 = pDev->IN_MAT[757];
    exchange::S18_2930 = pDev->IN_MAT[761];
    if(pFromP->balHydroToFull)
    {
        hydro.p0gat = 115.0;
        hydro.p0gs1 = 115.0;
        hydro.p0gs2 = 115.0;
        hydro.p0gs3 = 115.0;
        hydro.p0gs4 = 115.0;
        exchange::pgat = 280.0;
    }
    hydro.otkaz_gs1 = pFromP->Otkaz[1];
    hydro.otkaz_gs2 = pFromP->Otkaz[2];
    hydro.otkaz_gs3 = pFromP->Otkaz[3];
    hydro.otkaz_gs4 = pFromP->Otkaz[4];

}
void IN_landinggear_int    ()
{
    exchange::S1_3230 = pDev->IN_MAT[157];
    exchange::s2_3230 = pDev->IN_MAT[156];
    landinggea.S3_3230 = pDev->IN_MAT[762];
    landinggea.S30_3230 = pDev->IN_MAT[469];
    exchange::s1_3250 = pDev->IN_MAT[5];
    exchange::s4_3250 = pDev->IN_MAT[7];
    exchange::S31_3230 = pDev->IN_MAT[763];
    exchange::S55_3230 = pDev->IN_MAT[857];
    exchange::S56_3230 = pDev->IN_MAT[861];
    exchange::S57_3230 = pDev->IN_MAT[859];
    exchange::S58_3230 = pDev->IN_MAT[863];
    landinggea.Xped_buf = pDev->IN_A[0][12];

    if(pISU->wrapsign)
    {
        landinggea.Sl = 0.2;
        landinggea.Sp = 0.2;
    }
    else
    {
        landinggea.Sl = 0.0;
        landinggea.Sp = 0.0;
    }

    if(pFromP->Otkaz[72])
    {
        landinggea.otkaz_nevip_l_opor = true;
        landinggea.otkaz_nevip_p_opor = true;
        landinggea.otkaz_nevip_n_opor = true;
    }
    landinggea.otkaz_nevip_l_opor = pFromP->Otkaz[76];
    landinggea.otkaz_nevip_n_opor = pFromP->Otkaz[78];
    landinggea.otkaz_nevip_p_opor = pFromP->Otkaz[77];
    landinggea.otkaz_nepoln_ubor_n = pFromP->Otkaz[73];
    landinggea.otkaz_nepoln_ubor_l = pFromP->Otkaz[74];
    landinggea.otkaz_nepoln_ubor_p = pFromP->Otkaz[75];
    landinggea.otkaz_ne_vikl_avt_pos_vip_shas = pFromP->Otkaz[79];
    landinggea.otkaz_1_kanala = pFromP->Otkaz[80];
    landinggea.otkaz_2_kanala = pFromP->Otkaz[81];
}
void IN_pneumatic_int      ()
{
    pneumatic.du_o = pDev->IN_MAT[1035];
    exchange::s1_2830 = pDev->IN_MAT[278];
    exchange::s2_2830 = pDev->IN_MAT[279];
    exchange::s1_3650 = pDev->IN_MAT[598];
    exchange::s2_3650 = pDev->IN_MAT[599];
    if(pFromP->balPneuToFull)
    {
        pneumatic.Pzm = 150.0;
        pneumatic.Pger = 150.0;
        pneumatic.Pslt = 150.0;
        pneumatic.Pnpb = 150.0;
        pneumatic.Pnzb = 150.0;
        pneumatic.Vzm = 3000.0;
        pneumatic.Vslt = 3000.0;
        pneumatic.Vnpb = 3000.0;
        pneumatic.Vnzb = 3000.0;
    }
}
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
    exchange::s13_2430 = pDev->IN_MAT[524];
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

    if(pFromP->accChargeToFull)
    {
        powerdc.qa1 = 40.0;
        powerdc.qa2 = 40.0;
        powerdc.ea1 = 25.5;
        powerdc.ea2 = 25.5;
        powerdc.uak1 = 25.5;
        powerdc.uak2 = 25.5;
    }
    if(pFromP->rap1PlugIn) powerdc.pvrap1 = true;
    if(pFromP->rap2PlugIn) powerdc.pvrap2 = true;
    if(pFromP->rapPlugIn) powerdc.pvrap = true;

    exchange::eng1_spd = pISU->nvd1;
    exchange::eng2_spd = pISU->nvd2;
    exchange::eng3_spd = pISU->nvd3;
    exchange::eng4_spd = pISU->nvd4;

}
void IN_presure_int        ()
{
    presure.PNU = pFromP->pnu_presure;
    presure.H = pISU->H_;
    presure.Ph = pISU->Ph_;
    presure.PRTHU1 = pFromP->prthu1;//delete!!!
    if(pDev->IN_MAT[656]) presure.S1_2131 = 1;
    else if(pDev->IN_MAT[657]) presure.S1_2131 = 2;
    else presure.S1_2131 = 0;

    presure.S2_2131 = (pDev->IN_MAT[12]) ? true : false;

    presure.otkaz_perenadduv = (pFromP->Otkaz[59]) ? true : false;
    presure.otkaz_razgermetizatsiya = (pFromP->Otkaz[60]) ? true : false;
    presure.lyukizagermetizirovany = (pFromP->LK) ? true : false;
}
void IN_wingsmech_int      ()
{
    wingsmech.S1_2750 = pDev->IN_MAT[367];
    wingsmech.S2_2750 = pDev->IN_MAT[382];


    wingsmech.S13_2750 = pDev->IN_MAT[303];
    wingsmech.s1_2780 = pDev->IN_MAT[366];

    if(pDev->IN_MAT[380]) wingsmech.s2_2780 = 2;
    else  if(pDev->IN_MAT[379]) wingsmech.s2_2780 = 1;
    else wingsmech.s2_2780 = 0;

    if(pDev->IN_MAT[382]) wingsmech.S2_2750 = 2;
    else  if(pDev->IN_MAT[381]) wingsmech.S2_2750 = 1;
    else wingsmech.S2_2750 = 0;

    wingsmech.s1_2790 = pDev->IN_MAT[365];

    if(pDev->IN_MAT[376]) wingsmech.s2_2790 = 2;
    else  if(pDev->IN_MAT[375]) wingsmech.s2_2790 = 1;
    else wingsmech.s2_2790 = 0;

    if(pDev->IN_MAT[375]) wingsmech.s2_2790 = 2;
    if(pDev->IN_MAT[376]) wingsmech.s2_2790 = 1;
    wingsmech.delta_zr_vh = pDev->IN_A[1][26];
    wingsmech.delta_ruk_vh = pDev->IN_A[1][27];

    wingsmech.otkaz_1k_zakr = pFromP->Otkaz[61];
    wingsmech.otkaz_2k_zakr = pFromP->Otkaz[62];
    wingsmech.otkaz_osn_1k_zakr = pFromP->Otkaz[63];
    wingsmech.otkaz_osn_2k_zakr = pFromP->Otkaz[64];
    wingsmech.otkaz_rassgl_zakr = pFromP->Otkaz[65];
    wingsmech.otkaz_osn_1k_prekr = pFromP->Otkaz[66];
    wingsmech.otkaz_osn_2k_prekr = pFromP->Otkaz[67];
    wingsmech.otkaz_rassgl_prekr = pFromP->Otkaz[68];
    wingsmech.otkaz_osn_1k_PCHK = pFromP->Otkaz[69];
    wingsmech.otkaz_osn_2k_PCHK = pFromP->Otkaz[70];
    wingsmech.otkaz_RASSINHR_PCHK = pFromP->Otkaz[71];

}


//================== OUT Data
void OUT_aircondition_int()
{
    pDev->OUT_D[2][85] =bss_inst.BSS926X2A;
    pDev->OUT_D[2][93] =bss_inst.BSS926X2F;
    pDev->OUT_D[2][94] =  bss_inst.BSS926X2G;
    pDev->OUT_D[2][103] =  bss_inst.BSS838X6T;
    pDev->OUT_D[2][102] =  bss_inst.BSS838X6S;
    pDev->OUT_D[2][86] = bss_inst.BSS926X2B;
    pDev->OUT_D[2][87] = bss_inst.BSS926X2C;
    pDev->OUT_D[2][99] = bss_inst.BSS838X6R;
    pDev->OUT_D[2][98] = bss_inst.BSS838X6P;
    pDev->OUT_D[2][100] = bss_inst.BSS838X6U;
    pDev->OUT_D[2][91] = bss_inst.BSS838X6K;
    pDev->OUT_D[2][92] = bss_inst.BSS838X6L;
    pDev->OUT_D[2][95] = bss_inst.BSS838X6M;
    pDev->OUT_D[2][96] = bss_inst.BSS838X6N;
    pDev->OUT_D[2][97] = bss_inst.BSS838X6W;
    pDev->OUT_D[1][50] = bss_inst.BSS825X6q;
    pDev->OUT_D[1][49] = bss_inst.BSS824X2i;
    pDev->OUT_D[2][105] = bss_inst.BSS926X1T;
    pDev->OUT_D[2][89] = bss_inst.BSS926X2E;
    pDev->OUT_D[2][88] = bss_inst.BSS926X2D;
    pDev->OUT_D[2][90] = bss_inst.BSS838X6J;
    pDev->OUT_D[2][114] = bss_inst.BSS926X2K;
    pDev->OUT_D[2][110] = bss_inst.BSS838X6Z;
    pDev->OUT_D[2][112] = bss_inst.BSS838X6b;
    pDev->OUT_D[2][119] = bss_inst.BSS838X6d;
    pDev->OUT_D[2][121] = bss_inst.BSS838X6f;
    pDev->OUT_D[2][109] = bss_inst.BSS838X6Y;
    pDev->OUT_D[2][111] = bss_inst.BSS838X6a;
    pDev->OUT_D[2][118] = bss_inst.BSS838X6c;
    pDev->OUT_D[2][120] = bss_inst.BSS838X6e;
    pDev->OUT_D[2][108] = bss_inst.BSS838X6q;
    pDev->OUT_D[2][117] = bss_inst.BSS838X6r;
    pDev->OUT_D[2][113] = bss_inst.BSS926X2L;
    pDev->OUT_D[2][122] = bss_inst.BSS926X2M;
    pDev->OUT_D[2][123] = bss_inst.BSS926X2N;
    pDev->OUT_D[2][104] = bss_inst.BSS926X2H;
    pDev->OUT_D[2][106] = bss_inst.BSS926X2p;
    pDev->OUT_D[2][115] = bss_inst.BSS926X2s;
    pDev->OUT_D[2][107] = bss_inst.zakr_om1;
    pDev->OUT_D[2][116] = bss_inst.zakr_om2;
}
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
{
    pDev->OUT_D[1][45] = bss_inst.BSS824X2a;
    pDev->OUT_D[1][46] = bss_inst.BSS824X2b;
    pDev->OUT_D[1][47] = bss_inst.BSS824X2C;
    pDev->OUT_D[1][48] = bss_inst.BSS824X2D;
    pDev->OUT_D[1][44] = bss_inst.BSS825_prog;
    pDev->OUT_D[0][78] = bss_inst.BSS811X2L;
    pDev->OUT_D[1][4] = bss_inst.BSS824X2J;
    pDev->OUT_D[1][53] = bss_inst.BSS825X6f;
    pDev->OUT_D[1][54] = bss_inst.BSS825X6g;
    pDev->OUT_D[3][68] = antiicing.H1_3040;
    pDev->OUT_D[1][114] = antiicing.H1_3030;
    pDev->OUT_D[1][115] = antiicing.H2_3030;
    pDev->OUT_D[1][113] = antiicing.H3_3030;
}

void OUT_brakes_int         ()
{
    pDev->OUT_D[0][67] = bss_inst.BSS812X6r;
    pDev->OUT_D[0][65] = bss_inst.BSS812X6n;
    pDev->OUT_D[0][66] = bss_inst.BSS812X6p;
    pDev->OUT_D[0][69] = bss_inst.BSS812X6W;
    pDev->OUT_D[1][5] = bss_inst.BSS824X2R;
    pDev->OUT_D[1][7] = bss_inst.BSS824X2H;
    pDev->OUT_D[1][6] = bss_inst.BSS824X2G;
}

void OUT_cabinlighting_int  ()
{
    pDev->OUT_D[5][92] = cabinlighting.PK1PBLLZO;
    pDev->OUT_D[5][93] = cabinlighting.PK2PBLLZO;
    pDev->OUT_D[5][94] = cabinlighting.PK1PBPLZO;
    pDev->OUT_D[5][95] = cabinlighting.PK2PBPLZO;
    pDev->OUT_D[5][96] = cabinlighting.PK1LSPDZO;
    pDev->OUT_D[5][97] = cabinlighting.PK2LSPDZO;
    pDev->OUT_D[5][98] = cabinlighting.PK1PPDZO;
    pDev->OUT_D[5][99] = cabinlighting.PK2PPDZO;
    pDev->OUT_D[5][100] = cabinlighting.PK1SPLZO;
    pDev->OUT_D[5][101] = cabinlighting.PK2SPLZO;
    pDev->OUT_D[5][102] = cabinlighting.PK1PDSHOZO;
    pDev->OUT_D[5][103] = cabinlighting.PK2PDSHOZO;
    pDev->OUT_D[5][104] = cabinlighting.PK1LBSHOZO;
    pDev->OUT_D[5][105] = cabinlighting.PK2LBSHOZO;
    pDev->OUT_D[5][106] = cabinlighting.PK1PDSHNZO;
    pDev->OUT_D[5][107] = cabinlighting.PK2PDSHNZO;
    pDev->OUT_D[5][108] = cabinlighting.PK1PBSHNZO;
    pDev->OUT_D[5][109] = cabinlighting.PK2PBSHNZO;
    pDev->OUT_D[5][90] = cabinlighting.PSSD37RKL;
    pDev->OUT_D[5][91] = cabinlighting.PSSD37RKSH;
    pDev->OUT_D[5][110] = cabinlighting.PSSD42L;
    pDev->OUT_D[5][111] = cabinlighting.PSSD42P;
    pDev->OUT_D[4][34] = cabinlighting.pvpmfi[0];
    pDev->OUT_D[4][35] = cabinlighting.pvpmfi[1];
    pDev->OUT_D[4][41] = cabinlighting.pvpmfi[2];
    pDev->OUT_D[4][37] = cabinlighting.pvpmfi[3];
    pDev->OUT_D[4][38] = cabinlighting.pvpmfi[4];
    pDev->OUT_D[4][54] = cabinlighting.pvpmfi[5];
    pDev->OUT_D[4][56] = cabinlighting.pvpmfi[6];
    pDev->OUT_D[4][55] = cabinlighting.pvpmfi[7];
    pDev->OUT_D[4][46] = cabinlighting.pvpmfi[8];
    pDev->OUT_D[4][48] = cabinlighting.pvpmfi[9];
    pDev->OUT_D[4][47] = cabinlighting.pvpmfi[10];
    pDev->OUT_D[4][42] = cabinlighting.pvpmfpu[0];
    pDev->OUT_D[4][57] = cabinlighting.pvpmfpu[1];
    pDev->OUT_D[4][45] = cabinlighting.pvpmfpu[2];
    pDev->OUT_D[0][118] = cabinlighting.pvvomfi[0];
    pDev->OUT_D[0][119] = cabinlighting.pvvomfi[1];
    pDev->OUT_D[0][92] = cabinlighting.pvvomfi[2];
    pDev->OUT_D[0][120] = cabinlighting.pvvomfi[3];
    pDev->OUT_D[0][121] = cabinlighting.pvvomfi[4];
    pDev->OUT_D[0][122] = cabinlighting.pvvomfi[5];
    pDev->OUT_D[0][123] = cabinlighting.pvvomfi[6];
    pDev->OUT_D[0][124] = cabinlighting.pvvomfi[7];
    pDev->OUT_D[0][125] = cabinlighting.pvvomfi[8];
    pDev->OUT_D[0][126] = cabinlighting.pvvomfi[9];
    pDev->OUT_D[0][127] = cabinlighting.pvvomfi[10];
    pDev->OUT_D[0][63] = cabinlighting.pvvopui[0];
    pDev->OUT_D[3][39] = cabinlighting.pvvopui[1];
    pDev->OUT_D[0][93] = cabinlighting.pvvomfpu[0];
    pDev->OUT_D[0][94] = cabinlighting.pvvomfpu[1];
    pDev->OUT_D[0][95] = cabinlighting.pvvomfpu[2];
    pDev->OUT_D[1][61] = cabinlighting.pk31pdshovo;
    pDev->OUT_D[1][62] = cabinlighting.pk31pdshovo;
    pDev->OUT_D[1][63] = cabinlighting.pk31pdshovo;
    pDev->OUT_D[1][94] = cabinlighting.pk31pdshnvo;
    pDev->OUT_D[1][95] = cabinlighting.pk31pdshnvo;
}

void OUT_emergencyalarm_int ()
{}

void OUT_hydro_int          ()
{
    pDev->OUT_D[0][101] = hydro.H1_2910;
    pDev->OUT_D[0][100] = hydro.H2_2910;
    pDev->OUT_D[0][102] = hydro.H4_2910;
    pDev->OUT_D[0][103] = hydro.H5_2910;
    pDev->OUT_D[0][96] = hydro.H10_2930;
    pDev->OUT_D[0][97] = hydro.H11_2930;
    pDev->OUT_D[0][98] = hydro.H12_2930;
    pDev->OUT_D[0][99] = hydro.H13_2930;
    pDev->OUT_D[0][104] = hydro.H1_2935;
    pDev->OUT_D[0][4] = bss_inst.BSS811X2M;
    pDev->OUT_D[0][5] = bss_inst.BSS811X2N;
    pDev->OUT_D[0][6] = bss_inst.BSS811X2P;
    pDev->OUT_D[0][7] = bss_inst.BSS811X2R;
    pDev->OUT_D[0][79] = bss_inst.BSS811X2d;
    pDev->OUT_D[0][80] = bss_inst.BSS811X2e;
    pDev->OUT_D[0][81] = bss_inst.BSS811X2f;
    pDev->OUT_D[0][82] = bss_inst.BSS811X2g;
    pDev->OUT_D[0][74] = bss_inst.BSS812X6C;
    pDev->OUT_D[0][75] = bss_inst.BSS812X6D;
    pDev->OUT_D[0][76] = bss_inst.BSS812X6E;
    pDev->OUT_D[0][77] = bss_inst.BSS812X6F;
    pDev->OUT_D[0][73] = bss_inst.BSS812X6G;
    pDev->OUT_D[1][52] = bss_inst.BSS824X2e;
    pDev->OUT_D[0][22] = bss_inst.BSS811X2G;
    pDev->OUT_A[0][12] = hydro.pprgs1;
    pDev->OUT_A[0][13] = hydro.pprgs2;
    pDev->OUT_A[0][14] = hydro.pprgs3;
    pDev->OUT_A[0][15] = hydro.pprgs4;

}

void OUT_landinggear_int    ()
{
    pDev->OUT_D[1][28] = bss_inst.BSS825X6Y;
    pDev->OUT_D[1][30] = bss_inst.BSS825X6Z;
    pDev->OUT_D[1][32] = bss_inst.BSS825X6a;
    pDev->OUT_D[1][27] = bss_inst.BSS824X2X;
    pDev->OUT_D[1][26] = bss_inst.BSS824X2Y;
    pDev->OUT_D[1][29] = bss_inst.BSS824X2U;
    pDev->OUT_D[1][31] = bss_inst.BSS824X2V;
    pDev->OUT_D[1][33] = bss_inst.BSS824X2W;
    pDev->OUT_D[1][64] = bss_inst.BSS812X6Y;

}

void OUT_pneumatic_int      ()
{
    pDev->OUT_D[4][4] = pneumatic.psdzh_duo;
    pDev->OUT_D[4][5] = pneumatic.psdz_duo;
    pDev->OUT_D[0][12] = bss_inst.BSS811X2c;
    pDev->OUT_D[1][12] = bss_inst.BSS824X2E;
    pDev->OUT_D[2][62] = bss_inst.BSS837X2M;
    pDev->OUT_D[2][61] = bss_inst.BSS837X2L;
    pDev->OUT_D[1][18] = bss_inst.BSS824X2B;
    pDev->OUT_D[0][116] = bss_inst.BSS811X2S;
    pDev->OUT_D[0][117] = bss_inst.BSS811X2T;
}

void OUT_powerdc_int        ()
{
    pDev->OUT_D[2][32] = bss_inst.BSS837X2P;
    pDev->OUT_D[2][33] = bss_inst.BSS837X2V;
    pDev->OUT_D[2][27] = bss_inst.BSS926X2i;
    pDev->OUT_D[2][11] = bss_inst.BSS926X2g;
    pDev->OUT_D[2][21] = bss_inst.BSS926X2m;
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
    pDev->OUT_D[2][46] = bss_inst.BSS837X2m;
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
{
    pDev->OUT_D[2][83] = bss_inst.BSS838X6g;
    pDev->OUT_D[1][1] = bss_inst.BSS824X2D;
    pDev->OUT_D[0][12] = bss_inst.BSS811X2C;
    pDev->OUT_D[2][84] = bss_inst.BSS838X6h;
}

void OUT_wingsmech_int      ()
{
    pDev->OUT_D[1][66] = bss_inst.BSS824X2f;
    pDev->OUT_D[1][67] = bss_inst.BSS824X2h;
    pDev->OUT_D[1][65] = bss_inst.BSS825X6E;
    pDev->OUT_D[0][114] = bss_inst.BSS913X2h;
    pDev->OUT_D[0][115] = bss_inst.BSS913X2i;
}

