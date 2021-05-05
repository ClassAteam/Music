
#include "QtAdvantechClass.h"
//using namespace Automation::BDaq;

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
//int     iTipDev;//тип у-ва
//                // 1 - D inp 128k //PCI-1754
//                // 2 - D out 128k //PCI-1758
//                // 3 - A inp 32k dif //PCI-1747,1715
//                // 4 - A out 32k  //PCI-1724
//                // 5 - A inp/out 96+96k  //PCI-1753
//enum{PCI_1754=1,PCI_1758,PCI_1715_47, PCI_1724 ,PCI_1753};
SHADVAN_DI   ADVAN_DI[NUM_DI];
SHADVAN_DO   ADVAN_DO[NUM_DO];
SHADVAN_AI   ADVAN_AI[NUM_AI];
SHADVAN_AO   ADVAN_AO[NUM_AO];


QtAdvantechClass::QtAdvantechClass()
{
     numDO = 0;// всего device определенного типа в ини
     numDI = 0;// всего device определенного типа в ини
     numAI = 0;// всего device определенного типа в ини
     numAO = 0;// всего device определенного типа в ини
     vklAll =0;//система включена в ини
     ReadInitAdvan();
     InitAdvan();
}

QtAdvantechClass::~QtAdvantechClass()
{

    DeleteAdvan();

}

void QtAdvantechClass::InitAdvan()
{


    //-----------------DI
    for(int ii=0;ii<numDI;ii++)
    {
       pDiCtrl[ii] = AdxInstantDiCtrlCreate();
       int t= mbstowcs(deviceDescriptionDI[ii],pDI[ii]->IDdevice, SIZE_ID_DEV);
       if(t<0)
       {
          pDI[ii]->iState=20;
          continue;
       }
       DeviceInformation devInfo(deviceDescriptionDI[ii]);
       retDI[ii] =pDiCtrl[ii]->setSelectedDevice(devInfo);
       if(BioFailed(retDI[ii]))
       {
        pDI[ii]->iState=21 ;
        continue;
       }
       const wchar_t* profilePath = L"profilsAdvan/DemoDevice.xml";
       retDI[ii] =pDiCtrl[ii]->LoadProfile(profilePath);
       if(BioFailed(retDI[ii]))
       {
        pDI[ii]->iState=22 ;
        continue;
       }
       //----OK!!!
       pDI[ii]->iState=1 ;
    }//DI

    //-----------------DO
    for(int ii=0;ii<numDO;ii++)
    {
       pDoCtrl[ii] = AdxInstantDoCtrlCreate();
       int t= mbstowcs(deviceDescriptionDO[ii],pDO[ii]->IDdevice, SIZE_ID_DEV);
       if(t<0)
       {
          pDO[ii]->iState=20;
          continue;
       }
       DeviceInformation devInfo(deviceDescriptionDO[ii]);
       retDO[ii] =pDoCtrl[ii]->setSelectedDevice(devInfo);
       if(BioFailed(retDO[ii]))
       {
        pDO[ii]->iState=21 ;
        continue;
       }
//       AiChannelCollection *channels = bfdAiCtrl->getChannels();
//       int var=U->iNvar;
//       if(var==0)//diff
//       {
//           for(int i=0;i<iMAXNUMSIGNAL;i+=2)//диф  каналы
//             channels->getItem(i).setSignalType((AiSignalType)1);//диф
//       }
//       else if(var==1)//1,2,3,4 odnopr  and diff
//       {
//           for(int i=0;i<4;i+=1)
//               channels->getItem(i).setSignalType((AiSignalType)0);//однопр
//           for(int i=4;i<iMAXNUMSIGNAL;i+=2)
//               channels->getItem(i).setSignalType((AiSignalType)1);//диф
//       }

       const wchar_t* profilePath = L"profilsAdvan/DemoDevice.xml";
       retDO[ii] =pDoCtrl[ii]->LoadProfile(profilePath);
       if(BioFailed(retDO[ii]))
       {
        pDO[ii]->iState=22 ;
        continue;
       }
       //----OK!!!
       pDO[ii]->iState=1 ;
    }//DO
    //-----------------AI
    for(int ii=0;ii<numAI;ii++)
    {
       pAiCtrl[ii] = AdxInstantAiCtrlCreate();
       int t= mbstowcs(deviceDescriptionAI[ii],pAI[ii]->IDdevice, SIZE_ID_DEV);
       if(t<0)
       {
          pAI[ii]->iState=20;
          continue;
       }
       DeviceInformation devInfo(deviceDescriptionAI[ii]);
       retAI[ii] =pAiCtrl[ii]->setSelectedDevice(devInfo);
       if(BioFailed(retAI[ii]))
       {
        pAI[ii]->iState=21 ;
        continue;
       }
       const wchar_t* profilePath = L"profilsAdvan/DemoDevice.xml";
       retAI[ii] =pAiCtrl[ii]->LoadProfile(profilePath);
       if(BioFailed(retAI[ii]))
       {
        pAI[ii]->iState=22 ;
        continue;
       }
       //----OK!!!
       pAI[ii]->iState=1 ;
    }//AI

    //-----------------AO
    for(int ii=0;ii<numAO;ii++)
    {
       pAoCtrl[ii] = AdxInstantAoCtrlCreate();
       int t= mbstowcs(deviceDescriptionAO[ii],pAO[ii]->IDdevice, SIZE_ID_DEV);
       if(t<0)
       {
          pAO[ii]->iState=20;
          continue;
       }
       DeviceInformation devInfo(deviceDescriptionAO[ii]);
       retAO[ii] =pAoCtrl[ii]->setSelectedDevice(devInfo);
       if(BioFailed(retAO[ii]))
       {
        pAO[ii]->iState=21 ;
        continue;
       }
       pAO[ii]->iState=1 ;
    }//AO




//    void ErrStateUpdate(int state,char* err[]);

//    InstantDiCtrl * pDiCtrl[NUM_DI];
//    InstantDoCtrl * pDoCtrl[NUM_DO];
//    InstantAiCtrl * pAiCtrl[NUM_AI];
//    InstantAoCtrl * pAoCtrl[NUM_AO];

}

void QtAdvantechClass::ReadInitAdvan()
{
    numDO = 1;// всего device определенного типа в ини
    numDI = 1;// всего device определенного типа в ини
    numAI = 1;// всего device определенного типа в ини
    numAO = 0;// всего device определенного типа в ини

    for(int i=0;i<numDI;i++)
    {
        pDI[i]=&ADVAN_DI[i];
        pDI[i]->iIndTip=i;
        pDI[i]->startPort=0;//стартовый канал
        pDI[i]->portCount=8;//всего ГРУПП каналов
        pDI[i]->iVkl=1;
    }
   // strcpy_s(pDI[0]->IDdevice ,SIZE_ID_DEV,"PCI-1754,BID#0");
    strncpy(pDI[0]->IDdevice,"PCI-1754,BID#0" , SIZE_ID_DEV);


    for(int i=0;i<numDO;i++)
    {
        pDO[i]=&ADVAN_DO[i];
        pDO[i]->iIndTip=i;
        pDO[i]->startPort=0;//стартовый канал
        pDO[i]->portCount=16;//всего ГРУПП каналов
        pDO[i]->iVkl=1;
    }
    //(pDO[0]->IDdevice ,SIZE_ID_DEV,"PCI-1758UDO,BID#0");
    strncpy(pDO[0]->IDdevice,"PCI-1758UDO,BID#0" , SIZE_ID_DEV);


    for(int i=0;i<numAI;i++)
    {
        pAI[i]=&ADVAN_AI[i];
        pAI[i]->iIndTip=i;
        pAI[i]->iVkl=1;
    }
    //strcpy_s(pAI[0]->IDdevice ,SIZE_ID_DEV,"PCI-1715U,BID#0");
    strncpy(pAI[0]->IDdevice,"PCI-1713U,BID#0" , SIZE_ID_DEV);
    //---------общее для у-ва

   // int     iVkl ;//0 не инициал.(м.б. в и) \ 1 у-во включено \2 выключено из опроса(автоном)
    pAI[0]->startPort=0;//стартовый канал
    pAI[0]->portCount=16;//всего каналов
    pAI[0]->countLogKan=5;//всего логических каналов
    //---------по каналам
    // for(int i=0;i<LogKan;i++)
    //{
//    strcpy_s(pAI[0]->Ident[0] ,SIZE_ID_DEV,"Заголовник F1");
//    strcpy_s(pAI[0]->Ident[1] ,SIZE_ID_DEV,"Заголовник F1");
//    strcpy_s(pAI[0]->Ident[2] ,SIZE_ID_DEV,"Заголовник F1");
//    strcpy_s(pAI[0]->Ident[3] ,SIZE_ID_DEV,"Заголовник F1");
//    strcpy_s(pAI[0]->Ident[4] ,SIZE_ID_DEV,"Заголовник F1");

    strncpy(pAI[0]->Ident[0],"Заголовник F1" ,SIZE_ID_DEV);
    strncpy(pAI[0]->Ident[1],"Заголовник F1" ,SIZE_ID_DEV);
    strncpy(pAI[0]->Ident[2],"Заголовник F1" ,SIZE_ID_DEV);
    strncpy(pAI[0]->Ident[3],"Заголовник F1" ,SIZE_ID_DEV);
    strncpy(pAI[0]->Ident[4],"Заголовник F1" ,SIZE_ID_DEV);

//    pAI[0]->Volt [0]=7;//  7 = 0/10 v
//    pAI[0]->Volt [1]=7; //  8 =  0/5v //
//    pAI[0]->Volt [2]=7;
//    pAI[0]->Volt [3]=7;
//    pAI[0]->Volt [4]=8;

//    pAI[0]->NumKan [0]=0;//физ. номер канала логического канала
//    pAI[0]->NumKan [1]=2;
//    pAI[0]->NumKan [2]=4;
//    pAI[0]->NumKan [3]=6;
//    pAI[0]->NumKan [4]=8;


    //iState;//код состояния (индикация ERR):
              //=0  инициализация успешна, у-во работоспособно иначе см. void ErrState(int state,char* err[]);

    vklAll =1;

}

void QtAdvantechClass::DeleteAdvan()
{

    int ii=0;
    for(ii=0;ii<numDI;ii++)
    {
            pDiCtrl[ii]->Dispose();
    }
//#ifdef  NUM_DI_2
//
//	for(ii=0;ii<numDI2;ii++)
//	{
//			DiCtrl2[ii]->Dispose();
//	}
//
//#endif


    for(ii=0;ii<numDO;ii++)
    {
            pDoCtrl[ii]->Dispose();
    }

    for (ii=0; ii<numAI; ii++)
   {
        pDiCtrl[ii]->Dispose();

   }



}

//===========  UPDATE =======================
void QtAdvantechClass::UpdateAdvanDI()
{
    for(int i=0;i<numDI;i++)
    {
        if(pDI[i]->iState<20 && pDI[i]->iVkl==1)
        {
           // ZeroMemory(&tempReadWrite , sizeof(tempReadWrite) );
          //  memset(&tempReadWrite ,0, sizeof(tempReadWrite) );
            for(int i=0;i<NUMCHANEL_DI;i++)
                tempDI[i]=0;
           // int ind=pDI[i]->iIndTip;
            retDI[i]= pDiCtrl[i]->Read(pDI[i]->startPort,pDI[i]->portCount,tempDI);
            if(BioFailed(retDI[i]))
                pDI[i]->iState=3 ;
            else
            {
                int n=0;
                //bufReadWrite[0]=0xA2;
                for(int ib=0;ib<pDI[i]->portCount;ib++)
                {

                    for(int in=0;in<8;in++)
                    {
                        byte tem=tempDI[ib]>>(in);//7-in
                        if(tem & 0x0001)
                            pDI[i]->pD[n]=1;
                        else
                            pDI[i]->pD[n]=0;
                        n+=1;
                        if(n> pDI[i]->portCount*8)
                             n=pDI[i]->portCount*8;
                    }

                }

                pDI[i]->iState=1 ;

            }//else / if(BioFailed(retDI[i]))
        }

    }
}//void QtAdvantechClass::UpdateAdvanDI()


void QtAdvantechClass::UpdateAdvanDO()
{
    for(int i=0;i<numDO;i++)
    {
        if(pDO[i]->iState<20 &&  pDO[i]->iVkl==1  )
        {
            //ZeroMemory(&tempReadWrite , sizeof(tempReadWrite) );
            for(int i=0;i<NUMCHANEL_DO;i++)
                tempDO[i]=0;
            int n=0;
            for(int ib=0;ib<pDO[i]->portCount;ib++)
                {

                    for(int in=0;in<8;in++)
                    {
                        if(pDO[i]->pD[n]==1)
                             tempDO[ib] |= (1<<in);
                        n+=1;
                        if(n>pDO[i]->portCount*8)
                                n=pDO[i]->portCount*8;
                    }

                }



        retDO[i]= pDoCtrl[i]->Write(pDO[i]->startPort,pDO[i]->portCount,tempDO);
        if(BioFailed(retDO[i]))
             pDO[i]->iState=3 ;
        else
              pDO[i]->iState=1 ;
        }
       // else if (pDO[i]->iVkl==2)//AVTONOM
       // {
        //}

    }//for(int i=0;i<numDO;i++)
}//void QtAdvantechClass::UpdateAdvanDO()

void QtAdvantechClass::UpdateAdvanAI()
{
    for(int i=0;i<numAI;i++)
    {
        if(pAI[i]->iState<20 && pAI[i]->iVkl==1)
        {
          retAI[i] = pAiCtrl[i]->Read(pAI[i]->startPort,pAI[i]->portCount,pAI[i]->pAf );
          if(BioFailed(retAI[i]))
               pAI[i]->iState=3 ;
          else
                pAI[i]->iState=1 ;
        }
    }
}

void QtAdvantechClass::UpdateAdvanAO()
{
    for(int i=0;i<numAO;i++)
    {
        if(pAO[i]->iState<20 && pAO[i]->iVkl==1)
        {

        }

    }
}


