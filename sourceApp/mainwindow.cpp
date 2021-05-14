
#include <QSharedMemory>
#include <QtNetwork/QUdpSocket>
#include <QNetworkProxy>
#include <QTextCodec>

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "mainwindow.h"
#include "ui_T70_Win.h"
#include "sourceApp/threadModel.h"
#include "externStruct/Struct_FromRmiPilot.h"
#include "externStruct/Struct_DeviceConnect.h"
#include "externStruct/Struct_FromRmiOper.h"
#include "externStruct/Struct_FromRmiPilot.h"
#include "sourceApp/utilTimeClassQt.h"

#define SHARED_MEMORY_RMI_PIL "RMI_PIL"
#define SHARED_MEMORY_DEVICE_CONNECT "Struct_DEVICE_CONNECT"

//----------------------------------------------
extern antifire_int       antifire      ;
extern antiicing_int      antiicing     ;
extern brakes_int         brakes        ;
extern cabinlighting_int  cabinlighting ;
extern emergencyalarm_int emergencyalarm;
extern hydro_int          hydro         ;
extern landinggear_int    landinggea    ;
extern pneumatic_int      pneumatic     ;
extern powerdc_int        powerdc       ;
extern presure_int        presure       ;
extern wingsmech_int      wingsmech     ;
//----------------------------------------------
TimeClass* pFrameMain;
TimeClass* pFramePlanSys;
TimeClass* pFrameModel;


bool bAvtonon=false;
double TICK=5.0;//ms
double TICK_Graf=50.0;//

SH_FROMRMI_PILOT   FROMRMI_PILOT,  *pFromP=&FROMRMI_PILOT;  // for socket_in
SH_FROMRMI_PILOT   FROMRMI_OPER,   *pFromO=&FROMRMI_OPER;  // for socket_in
SH_DEVICE_CONNECT  DEVICE_CONNECT, *pDev=&DEVICE_CONNECT ;//, *pDevShar;

QUdpSocket *socket_out = nullptr;
QUdpSocket *socket_in = nullptr;

QSharedMemory SHARE_ADVANTECH;
QSharedMemory SHARE_RMI_PILOT;

extern bool exitThreadModel;
bool s2 = false;
int b_send, b_recv;

int packet_recv;
int packet_send;

// russian characters
QString RUS_String(const char* t)
{
 return QString::fromLocal8Bit(t);
}

//---------------------------------
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //move(0, 0);

    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    //setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("CP1251"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("Utf8"));

    socket_out = new QUdpSocket(this);
    socket_out->setProxy(QNetworkProxy::NoProxy);

    socket_in = new QUdpSocket(this);
    socket_in->setProxy(QNetworkProxy::NoProxy);

   // s2 = socket_in->bind(QHostAddress::LocalHost, 7755);
    s2 = socket_in->bind(7755, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(socket_in, SIGNAL(readyRead()), this, SLOT(receivingData()));

    SHARE_ADVANTECH.setKey(SHARED_MEMORY_DEVICE_CONNECT);
    SHARE_ADVANTECH.attach();

    SHARE_RMI_PILOT.setKey(SHARED_MEMORY_RMI_PIL);
    SHARE_RMI_PILOT.attach();

     model = new ThreadModel();//
   // MyThread thread;

   // model->start(QThread::HighestPriority);
    model->start(QThread::TimeCriticalPriority);

    timer = new QTimer();
    pFrameMain= new TimeClass("F_Graf",TICK_Graf,200,25);//for control
    pFramePlanSys= new TimeClass("D_PlanSys ",200);//for control
    pFrameModel = new TimeClass("F_Model ",TICK,200,10);//for control
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start((int)TICK_Graf);


}

MainWindow::~MainWindow()
{
 exitThreadModel=1;
 //delete pQtAdvan;
 delete pFrameMain;
 delete pFramePlanSys ;
 delete pFrameModel ;
 delete timer;
 delete socket_in;
 delete socket_out;
 delete  model;
 SHARE_ADVANTECH.detach();
 SHARE_RMI_PILOT.detach();


 delete ui;
}


void MainWindow::receivingData()
{

    while (socket_in->hasPendingDatagrams())
    {
       QByteArray datagram;
       datagram.resize(socket_in->pendingDatagramSize());
       QHostAddress sender;
       quint16 senderPort;
       //SH_FROMRMI_PILOT  ,  *pFromP=&FROMRMI_PILOT;
       socket_in->readDatagram((char *) &FROMRMI_PILOT, sizeof(SH_FROMRMI_PILOT), &sender, &senderPort);

       packet_recv ++;

       ui->text_2->setText("Packets received: " + QString::number(packet_recv)
                          + ", size: " + QString::number(datagram.size()) + " Bytes");
     }
}

void MainWindow::slotTimerAlarm()
{
    //====control time
    pFrameMain->StartFrame();

    // send structure to WINDOWS
    // b_send = socket_out->writeDatagram((const char *)AIN, sizeof(RMI), QHostAddress::LocalHost, 5824);
    // if (b_send>0)
    //  packet_send ++;
    //====== PRINT
    Print_manager       ()   ;
    Print_antifire      ()   ;
    Print_antiicing     ()   ;
    Print_brakes        ()   ;
    Print_cabinlighting ()   ;
    Print_emergencyalarm()   ;
    Print_hydro         ()   ;
    Print_landinggea    ()   ;
    Print_pneumatic     ()   ;
    Print_powerdc       ()   ;
    Print_presure       ()   ;
    Print_wingsmech     ()   ;
}

//=============================PRINT=====================================

void  MainWindow:: Print_manager       ()
{


    ui->text_1->setText("Packets send: " + QString::number(packet_send)
                           + ", size: " + QString::number(b_send) + " Bytes");


    ui->text_3->setText("Сред.время рисования за период: " + QString::number(pFrameMain->_FrameN)+ " мс");
    ui->text_4->setText("Время рисования max за период: " + QString::number(pFrameMain->_FrameMaxN)+ " мс");
    ui->text_5->setText("Время рисования min за период: " + QString::number(pFrameMain->_FrameMinN)+ " мс");

    ui->text_6->setText("Сред.период самол.сист.: " + QString::number(pFramePlanSys->_FrameN)+ " мс");
    ui->text_7->setText("max период самол.сист.: " + QString::number(pFramePlanSys->_FrameMaxN)+ " мс");
    ui->text_8->setText("min период самол.сист.: " + QString::number(pFramePlanSys->_FrameMinN)+ " мс");

    ui->text_9->setText("Сред.время цикла за период: " + QString::number(pFrameModel->_FrameN)+ " мс");
    ui->text_10->setText("Время цикла max за период: " + QString::number(pFrameModel->_FrameMaxN)+ " мс");
    ui->text_11->setText("Время цикла min за период: " + QString::number(pFrameModel->_FrameMinN)+ " мс");

//    ui->label_48->setText("PCI1713_1kan ="     + QString::number(pQtAdvan->pAI[0]->pAf[0]));
}
void  MainWindow:: Print_antifire      ()
{

}
void  MainWindow:: Print_antiicing     ()
{

}
void  MainWindow:: Print_brakes        ()
{

}
void  MainWindow:: Print_cabinlighting ()
{

}
void  MainWindow:: Print_emergencyalarm()
{

}

//#include "Print/PrintGidro.cpp"
void  MainWindow:: Print_hydro         ()
{
       ui->text_3001->setText("пp. ПРИНУД ПОДКЛ Г/НАСОСОВ              "+ QString::number(hydro.s1_2910));
       ui->text_3002->setText("кн. КОНТРОЛЬ РАЗГРУЗКИ                  "+ QString::number(hydro.s2_2910 ));
       ui->text_3003->setText("пр. ВЫБОР НАСОСА ГС1, 2                 "+ QString::number(hydro.s3_2910 ));
       ui->text_3004->setText("пр. ВЫБОР НАСОСА ГС3, 4                 "+ QString::number(hydro.s4_2910 ));
       ui->text_3005->setText("пр. ЭКСТРЕННОЕ ОТКЛ Г/НАСОСОВ ДВ2 И 3   "+ QString::number(hydro.S5_2910 ));
       ui->text_3006->setText("пр. ЭКСТРЕННОЕ ОТКЛ Г/НАСОСОВ ДВ1 И 4   "+ QString::number(hydro.S6_2910 ));
       ui->text_3007->setText("пр. ОТКЛ Г/НАСОСОВ ДВ2                  "+ QString::number(hydro.S7_2910 ));
       ui->text_3008->setText("пр. ГИДРОПИТАНИЕ СУР ГС1                "+ QString::number(hydro.Ffirst4_2920[0] ));
       ui->text_3009->setText("пр. ГИДРОПИТАНИЕ СУР ГС2                "+ QString::number(hydro.Ffirst4_2920[1] ));
       ui->text_3010->setText("пр. ГИДРОПИТАНИЕ СУР ГС3                "+ QString::number(hydro.Ffirst4_2920[2] ));
  //     ui->text_3011->setText("пр. ГИДРОПИТАНИЕ СУР ГС4                "+ QString::number(hydro.Ffirst4_2920[3] ));
}
void  MainWindow:: Print_landinggea    ()
{

}
void  MainWindow:: Print_pneumatic     ()
{

}
void  MainWindow:: Print_powerdc       ()
{
    ui->label_9->setText("Напряжение генератора постоянного тока №1, В = " + QString::number(powerdc.ushpzl));
    ui->label_17->setText("Напряжение генератора постоянного тока №2, В = " + QString::number(powerdc.ushpzp));
    ui->label_18->setText("Напряжение генератора постоянного тока №2, В = " + QString::number(powerdc.ushpzp));
    ui->label_8->setText("Напряжение генератора постоянного тока №4, В = " + QString::number(powerdc.ushpzp));
    ui->label_7->setText("Напряжение генератора постоянного тока ВСУ, В = " + QString::number(powerdc.ushpzp));
    ui->label_6->setText("Напряжение аккумулятора №1, В = " + QString::number(powerdc.ushpzp));
    ui->label_5->setText("Напряжение аккумулятора №2, В = " + QString::number(powerdc.ushpzp));
    ui->label_4->setText("Напряжение на шине аккумуляторной левого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_3->setText("Напряжение на шине аккумуляторной правого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_2->setText("Напряжение на шине 1 двойного питания левого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_10->setText("Напряжение на шине 1 двойного питания правого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_11->setText("Напряжение на шине 2 двойного питания левого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_12->setText("Напряжение на шине 2 двойного питания правого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_14->setText("Напряжение на шине 1 отключаемой левого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_13->setText("Напряжение на шине 1 отключаемой правого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_15->setText("Напряжение на шине 2 отключаемой левого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_16->setText("Напряжение на шине 2 отключаемой правого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_19->setText("Напряжение на шине 1 левого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_20->setText("Напряжение на шине 1 правого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_21->setText("Напряжение на шине 2 левого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_22->setText("Напряжение на шине 2 правого борта, В = " + QString::number(powerdc.ushpzp));
    ui->label_23->setText("Напряжение генератора переменного тока №1 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_24->setText("Напряжение генератора переменного тока №2 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_25->setText("Напряжение генератора переменного тока №3 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_26->setText("Напряжение генератора переменного тока №4 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_27->setText("Напряжение генератора переменного тока ВСУ фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_28->setText("Напряжение ПТС фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_29->setText("Напряжение ПОС, В = " + QString::number(powerdc.ushpzp));
    ui->label_30->setText("Напряжение на шине генератора переменного тока #1 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_31->setText("Напряжение на шине генератора переменного тока #2 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_32->setText("Напряжение на шине генератора переменного тока #3 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_33->setText("Напряжение на шине генератора переменного тока #4 фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_34->setText("Напряжение на шине генератора переменного тока РАП фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_35->setText("Напряжение на шине переключаемой переменного тока левой фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_36->setText("Напряжение на шине переключаемой переменного тока правой фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_37->setText("Напряжение на шине 1 аварийной переменного тока = " + QString::number(powerdc.ushpzp));
    ui->label_38->setText("Напряжение на шине 2 аварийной переменного тока = " + QString::number(powerdc.ushpzp));
    ui->label_39->setText("Напряжение на шине аварийной переменного тока левой фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_40->setText("Напряжение на шине аварийной переменного тока правой фазы А, В, С, В = " + QString::number(powerdc.ushpzp));
    ui->label_41->setText("Ток нагрузки генератора ВСУ фаза Ф (В,С), А = " + QString::number(powerdc.ushpzp));
    ui->label_42->setText("Ток нагрузки РАП фаза Ф (В,С), А = " + QString::number(powerdc.ushpzp));
    ui->label_43->setText("Приборное значение тока, А = " + QString::number(powerdc.ushpzp));
    ui->uks1x36->setText("Генераторо 1 перегрузка (27В) = " + QString::number(uks_inst.UKS1X36));
    ui->uks1x37->setText("Генераторо 2 перегрузка (27В) = " + QString::number(uks_inst.UKS1X37));
    ui->uks3x325->setText("Генераторо 3 перегрузка (27В) = " + QString::number(uks_inst.UKS3X325));
    ui->uks3x326->setText("Генераторо 4 перегрузка (27В) = " + QString::number(uks_inst.UKS3X326));
    ui->uks1x38->setText("Генераторо 1 отключи (27В) = " + QString::number(uks_inst.UKS1X38));
    ui->uks1x39->setText("Генераторо 2 отключи (27В) = " + QString::number(uks_inst.UKS1X39));
    ui->uks3x327->setText("Генераторо 3 отключи (27В) = " + QString::number(uks_inst.UKS3X327));
    ui->uks3x328->setText("Генераторо 4 отключи (27В) = " + QString::number(uks_inst.UKS3X328));
    ui->uks1x311->setText("РАП1 включен = " + QString::number(uks_inst.UKS1X311));
    ui->uks3x329->setText("РАП2 включен = " + QString::number(uks_inst.UKS3X329));
    ui->uks1x310->setText("Сети соединены (27В) = " + QString::number(uks_inst.UKS1X310));
    ui->uks2x353->setText("Генератор 1 включен (27В) = " + QString::number(uks_inst.UKS2X353));
    ui->uks2x354->setText("Генератор 2 включен (27В) = " + QString::number(uks_inst.UKS2X354));
    ui->uks1x343->setText("Подключение отключаемых шины 1 левых = " + QString::number(uks_inst.UKS1X343));
    ui->uks1x344->setText("Подключение отключаемых шины 2 левых = " + QString::number(uks_inst.UKS1X344));
    ui->uks2x314->setText("Левая сеть частичный режим = " + QString::number(uks_inst.UKS2X314));
    ui->uks4x339->setText("Правая сеть частичный режим = " + QString::number(uks_inst.UKS4X339));
    ui->uks2x355->setText("Аккумулятор1 включен = " + QString::number(uks_inst.UKS2X355));
    ui->uks4x352->setText("Аккумулятор2 включен = " + QString::number(uks_inst.UKS4X352));
    ui->uks2x312->setText("Аккумулятор1 перегрев = " + QString::number(uks_inst.UKS2X312));
    ui->uks4x337->setText("Аккумулятор2 перегрев = " + QString::number(uks_inst.UKS4X337));
    ui->uks4x340->setText("Обьединение аварийных шин = " + QString::number(uks_inst.UKS4X340));
    ui->uks2x310->setText("Генератор 1 не работает = " + QString::number(uks_inst.UKS2X310));
    ui->uks2x311->setText("Генератор 2 не работает = " + QString::number(uks_inst.UKS2X311));
    ui->uks4x335->setText("Генератор 3 не работает = " + QString::number(uks_inst.UKS4X335));
    ui->uks4x336->setText("Генератор 4 не работает = " + QString::number(uks_inst.UKS4X336));
    ui->uks2x315->setText("Генератор ВСУ работает = " + QString::number(uks_inst.UKS2X315));
    ui->uks2x356->setText("Генератор ВСУ включен = " + QString::number(uks_inst.UKS2X356));
    ui->uks1x2105106->setText("Ток генератоа ВСУ (пост ток) = " + QString::number(uks_inst.UKS1X2));

}
void  MainWindow:: Print_presure       ()
{

}
void  MainWindow:: Print_wingsmech     ()
{

}


