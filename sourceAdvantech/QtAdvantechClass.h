
#ifndef QTADVANTECHCLASS_H
#define QTADVANTECHCLASS_H
#include <stdint.h>
#include <string.h>
//#include <cstdlib>
#include "Advantech/bdaqctrl.h"
#include "QtAdvantech.h"
using namespace Automation::BDaq;

//#define NUM_DI        8  //максимально возможное к-во модулей (резервирование памяти )  DI
//#define NUM_DO        8  //максимально возможное к-во модулей (резервирование памяти )  DO
//#define NUM_AI        4  //максимально возможное к-во модулей (резервирование памяти )  AI
//#define NUM_AO        4  //максимально возможное к-во модулей (резервирование памяти )  AO
//#define NUM_DIO       4
//#define MAXTAR        25 //максимально возможное число интерполяций

//#define NUMCHANEL_AO      64  //
//#define NUMCHANEL_AI      64  //
//#define NUMCHANEL_DO      128// 64  //
//#define NUMCHANEL_DI      128  //
//#define NUMCHANEL_DIO     96  //

////int     iTipDev;//тип у-ва
////                // 1 - D inp 128k //PCI-1754
////                // 2 - D out 128k //PCI-1758
////                // 3 - A inp 32k dif //PCI-1747,1715
////                // 4 - A out 32k  //PCI-1724
////                // 5 - A inp/out 96+96k  //PCI-1753

//enum{PCI_1754=1,PCI_1758,PCI_1715_47, PCI_1724 ,PCI_1753};

class QtAdvantechClass
{

public:
     QtAdvantechClass();
    ~QtAdvantechClass();

     void  UpdateAdvanDI();
     void  UpdateAdvanDO();
     void  UpdateAdvanAI();
     void  UpdateAdvanAO();
   // int CreateAdvantechThread();

    SHADVAN_DI *    pDI[NUM_DI];
    SHADVAN_DO *    pDO[NUM_DO];
    SHADVAN_AI *    pAI[NUM_AI];
    SHADVAN_AO *    pAO[NUM_AO];

    int numDO;// всего device определенного типа в ини
    int numDI;// всего device определенного типа в ини
    int numAI;// всего device определенного типа в ини
    int numAO;// всего device определенного типа в ини

    //int numRead;//максимально-возможное число device
    bool vklAll;//система включена в ини
    //bool stateAll;//система готова или нет
    void ErrStateUpdate(int state,char* err[]);

private:
    InstantDiCtrl * pDiCtrl[NUM_DI];
    InstantDoCtrl * pDoCtrl[NUM_DO];
    InstantAiCtrl * pAiCtrl[NUM_AI];
    InstantAoCtrl * pAoCtrl[NUM_AO];

    wchar_t  deviceDescriptionDI[NUM_DI][SIZE_ID_DEV*2];
    wchar_t  deviceDescriptionDO[NUM_DI][SIZE_ID_DEV*2];
    wchar_t  deviceDescriptionAI[NUM_DI][SIZE_ID_DEV*2];
    wchar_t  deviceDescriptionAO[NUM_DI][SIZE_ID_DEV*2];


    ErrorCode     retDI[NUM_DI];//детализированный код ошибки - при создании и иниц. (специальной для ADVANTECH)
    ErrorCode     retDO[NUM_DO];
    ErrorCode     retAI[NUM_AI];
    ErrorCode     retAO[NUM_AO];

    void InitAdvan();
    void DeleteAdvan();
    void ReadInitAdvan();

    byte  tempDI[NUMCHANEL_DI] ;  //job
    byte  tempDO[NUMCHANEL_DO] ;  //job

};

#endif // QTADVANTECHCLASS_H

