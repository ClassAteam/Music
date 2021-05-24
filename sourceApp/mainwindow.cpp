
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
#include "externStruct/Struct_ISU.h"

#include "sourceApp/utilTimeClassQt.h"

#define SHARED_MEMORY_RMI_PIL "RMI_PIL"
#define SHARED_MEMORY_DEVICE_CONNECT "Struct_DEVICE_CONNECT"
#define SHARED_MEMORY_ISU "ISU_CONNECT"

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
SH_ISU  ISU, *pISU=&ISU ;//

QUdpSocket *socket_out = nullptr;
QUdpSocket *socket_in = nullptr;

QSharedMemory SHARE_ADVANTECH;
QSharedMemory SHARE_RMI_PILOT;
QSharedMemory SHARE_ISU;

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

    SHARE_ISU.setKey(SHARED_MEMORY_ISU);
    SHARE_ISU.attach();

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
 SHARE_ISU.detach();


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
    ui->peregrevDv1->setText("Признак входного сигнала ПЕРЕГРЕВ ДВИГАТЕЛЯ 1 = " + QString::number(uks_inst.UKS3X314));
    ui->peregrevDv2->setText("Признак входного сигнала ПЕРЕГРЕВ ДВИГАТЕЛЯ 2 = " + QString::number(uks_inst.UKS3X315));
    ui->peregrevDv3->setText("Признак входного сигнала ПЕРЕГРЕВ ДВИГАТЕЛЯ 3 = " + QString::number(uks_inst.UKS3X316));
    ui->peregrevDv4->setText("Признак входного сигнала ПЕРЕГРЕВ ДВИГАТЕЛЯ 4 = " + QString::number(uks_inst.UKS3X317));
    ui->ochered_1_razr->setText("Признак входного сигнала ОЧЕРЕДЬ 1 РАЗРЯДИЛАСЬ = " + QString::number(uks_inst.UKS3X318));
    ui->pozharDv1->setText("Признак входного сигнала ПОЖАР ДВИГАТЕЛЯ 1 = " + QString::number(uks_inst.UKS4X33));
    ui->pozharDv2->setText("Признак входного сигнала ПОЖАР ДВИГАТЕЛЯ 2 = " + QString::number(uks_inst.UKS4X34));
    ui->pozharDv3->setText("Признак входного сигнала ПОЖАР ДВИГАТЕЛЯ 3 = " + QString::number(uks_inst.UKS4X35));
    ui->pozharDv4->setText("Признак входного сигнала ПОЖАР ДВИГАТЕЛЯ 4 = " + QString::number(uks_inst.UKS4X36));
    ui->ocheredVsu->setText("Признак входного сигнала ОЧЕРЕДЬ ВСУ = " + QString::number(uks_inst.UKS4X37));

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
    ui->uks1x329->setText("ТНУ1 включена на УКС1 = " + QString::number(uks_inst.UKS1X329));
    ui->uks1x330->setText("ТНУ1 включена на УКС2 = " + QString::number(uks_inst.UKS1X330));
    ui->uks1x331->setText("ТНУ1 включена на УКС3 = " + QString::number(uks_inst.UKS1X331));
    ui->uks1x332->setText("ТНУ1 включена на УКС4 = " + QString::number(uks_inst.UKS1X332));
    ui->uks1x333->setText("ТНУ1 работает на УКС1 = " + QString::number(uks_inst.UKS1X333));
    ui->uks1x334->setText("ТНУ2 работает на УКС1 = " + QString::number(uks_inst.UKS1X334));
    ui->uks1x335->setText("ТНУ3 работает на УКС1 = " + QString::number(uks_inst.UKS1X335));
    ui->uks1x335->setText("ТНУ4 работает на УКС1 = " + QString::number(uks_inst.UKS1X336));
    ui->uks2x324->setText("ГС2 насос H1 не работает для ИУС = " + QString::number(uks_inst.UKS2X324));
    ui->uks2x325->setText("ГС1 насос H2 не работает для ИУС = " + QString::number(uks_inst.UKS2X325));
    ui->uks2x326->setText("ГС2 насос H3 не работает для ИУС = " + QString::number(uks_inst.UKS2X326));
    ui->uks2x327->setText("ГС1 насос H4 не работает для ИУС = " + QString::number(uks_inst.UKS2X327));
    ui->uks2x328->setText("ГС4 насос H5 не работает для ИУС = " + QString::number(uks_inst.UKS2X328));
    ui->uks2x329->setText("ГС3 насос H6 не работает для ИУС = " + QString::number(uks_inst.UKS2X329));
    ui->uks2x330->setText("ГС4 насос H7 не работает для ИУС = " + QString::number(uks_inst.UKS2X330));
    ui->uks2x331->setText("ГС3 насос H8 не работает для ИУС = " + QString::number(uks_inst.UKS2X331));
    ui->uks2x332->setText("ГС2 насос H1 отключен ИУС = " + QString::number(uks_inst.UKS2X332));
    ui->uks2x333->setText("ГС1 насос H2 отключен ИУС = " + QString::number(uks_inst.UKS2X333));
    ui->uks2x334->setText("ГС2 насос H3 отключен ИУС = " + QString::number(uks_inst.UKS2X334));
    ui->uks2x335->setText("ГС1 насос H4 отключен ИУС = " + QString::number(uks_inst.UKS2X335));
    ui->uks2x336->setText("ГС4 насос H5 отключен ИУС = " + QString::number(uks_inst.UKS2X336));
    ui->uks2x337->setText("ГС3 насос H6 отключен ИУС = " + QString::number(uks_inst.UKS2X337));
    ui->uks2x338->setText("ГС4 насос H7 отключен ИУС = " + QString::number(uks_inst.UKS2X338));
    ui->uks2x339->setText("ГС3 насос H8 отключен на УКС = " + QString::number(uks_inst.UKS2X339));
    ui->uks2x316->setText("давление в ГС1 меньше 130 = " + QString::number(uks_inst.UKS2X316));
    ui->uks2x317->setText("давление в ГС2 меньше 130 = " + QString::number(uks_inst.UKS2X317));
    ui->uks2x318->setText("давление в ГС3 меньше 130 = " + QString::number(uks_inst.UKS2X318));
    ui->uks2x319->setText("давление в ГС4 меньше 130 = " + QString::number(uks_inst.UKS2X319));
    ui->uks2x340->setText("ГС1, ГС2, ГС3, ГС4 кран кольцевания включен = " + QString::number(uks_inst.UKS2X340));

    ui->uks1x25960->setText("Давление в ГС1 = " + QString::number(uks_inst.UKS1X259_60));
    ui->uks1x26263->setText("Давление в ГС2 = " + QString::number(uks_inst.UKS1X262_63));
    ui->uks1x26465->setText("Давление в ГС3 = " + QString::number(uks_inst.UKS1X264_65));
    ui->uks1x26768->setText("Давление в ГС4 = " + QString::number(uks_inst.UKS1X267_68));

    ui->uks4x294->setText("Температура жидкости в ГС1 = " + QString::number(uks_inst.UKS4X294));
    ui->uks4x296->setText("Температура жидкости в ГС2 = " + QString::number(uks_inst.UKS4X296));
    ui->uks4x298->setText("Температура жидкости в ГС3 = " + QString::number(uks_inst.UKS4X298));
    ui->uks4x2100->setText("Температура жидкости в ГС4 = " + QString::number(uks_inst.UKS4X2100));
    ui->uks4x24849->setText("Давление азота в 1 баллоне наддува = " + QString::number(uks_inst.UKS4X248_49));
    ui->uks4x25152->setText("Давление азота в 2 баллоне наддува = " + QString::number(uks_inst.UKS4X251_52));
    ui->uks4x25354->setText("Давление наддува в гидробаке ГС1 = " + QString::number(uks_inst.UKS4X253_54));
    ui->uks4x25657->setText("Давление наддува в гидробаке ГС2 = " + QString::number(uks_inst.UKS4X256_57));
    ui->uks4x25960->setText("Давление наддува в гидробаке ГС3 = " + QString::number(uks_inst.UKS4X259_60));
    ui->uks4x26263->setText("Давление наддува в гидробаке ГС4 = " + QString::number(uks_inst.UKS4X262_63));
    ui->uks2x256->setText("Давление азота в газовой полости 1го гидроаккумулятора = " + QString::number(uks_inst.UKS2X25_6));
    ui->uks2x21314->setText("Давление азота в газовой полости 2го гидроаккумулятора = " + QString::number(uks_inst.UKS2X213_14));
    ui->uks2x2158->setText("Давление азота в газовой полости 3го гидроаккумулятора = " + QString::number(uks_inst.UKS2X215_8));
    ui->uks2x2169->setText("Давление азота в газовой полости 4го гидроаккумулятора = " + QString::number(uks_inst.UKS2X216_9));
    ui->uks2ubgs1->setText("Уровень рабочей жидкости в баке ГС1 = " + QString::number(uks_inst.UKS2UBGS1));
    ui->uks2ubgs2->setText("Уровень рабочей жидкости в баке ГС2 = " + QString::number(uks_inst.UKS2UBGS2));
    ui->uks2ubgs3->setText("Уровень рабочей жидкости в баке ГС3 = " + QString::number(uks_inst.UKS2UBGS3));
    ui->uks2ubgs4->setText("Уровень рабочей жидкости в баке ГС4 = " + QString::number(uks_inst.UKS2UBGS4));
    ui->uks2x320->setText("Минимальный остаток жидкости в баке 1" + QString::number(uks_inst.UKS2X320));
    ui->uks2x321->setText("Минимальный остаток жидкости в баке 2" + QString::number(uks_inst.UKS2X321));
    ui->uks2x322->setText("Минимальный остаток жидкости в баке 3" + QString::number(uks_inst.UKS2X322));
    ui->uks2x323->setText("Минимальный остаток жидкости в баке 4" + QString::number(uks_inst.UKS2X323));
}
void  MainWindow:: Print_landinggea    ()
{

}
void  MainWindow:: Print_pneumatic     ()
{

}
void  MainWindow:: Print_powerdc       ()
{
    ui->label_9->setText("Напряжение генератора постоянного тока №1, В = " + QString::number(powerdc.ug1_27));
    ui->label_17->setText("Напряжение генератора постоянного тока №2, В = " + QString::number(powerdc.ug2_27));
    ui->label_18->setText("Напряжение генератора постоянного тока №3, В = " + QString::number(powerdc.ug3_27));
    ui->label_8->setText("Напряжение генератора постоянного тока №4, В = " + QString::number(powerdc.ug4_27));
    ui->label_7->setText("Напряжение генератора постоянного тока ВСУ, В = " + QString::number(powerdc.ugrvsu27));
    ui->label_6->setText("Напряжение аккумулятора №1, В = " + QString::number(powerdc.uak1));
    ui->label_5->setText("Напряжение аккумулятора №2, В = " + QString::number(powerdc.uak2));
    ui->label_4->setText("Напряжение на шине аккумуляторной левого борта, В = " + QString::number(exchange::ushal));
    ui->label_3->setText("Напряжение на шине аккумуляторной правого борта, В = " + QString::number(exchange::ushap));
    ui->label_2->setText("Напряжение на шине 1 двойного питания левого борта, В = " + QString::number(exchange::ush1dpl));
    ui->label_10->setText("Напряжение на шине 1 двойного питания правого борта, В = " + QString::number(exchange::ush1dpp));
    ui->label_11->setText("Напряжение на шине 2 двойного питания левого борта, В = " + QString::number(exchange::ush2dpl));
    ui->label_12->setText("Напряжение на шине 2 двойного питания правого борта, В = " + QString::number(exchange::ush2dpp));
    ui->label_14->setText("Напряжение на шине 1 отключаемой левого борта, В = " + QString::number(exchange::usho1l));
    ui->label_13->setText("Напряжение на шине 1 отключаемой правого борта, В = " + QString::number(exchange::usho1p));
    ui->label_15->setText("Напряжение на шине 2 отключаемой левого борта, В = " + QString::number(exchange::usho2l));
    ui->label_16->setText("Напряжение на шине 2 отключаемой правого борта, В = " + QString::number(exchange::usho2p));
    ui->label_19->setText("Напряжение на шине 1 левого борта, В = " + QString::number(exchange::ush1l));
    ui->label_20->setText("Напряжение на шине 1 правого борта, В = " + QString::number(exchange::ush1p));
    ui->label_21->setText("Напряжение на шине 2 левого борта, В = " + QString::number(exchange::ush2l));
    ui->label_22->setText("Напряжение на шине 2 правого борта, В = " + QString::number(exchange::ush2p));
    ui->label_23->setText("Напряжение генератора переменного тока №1 фазы А, В, С, В = " + QString::number(powerdc.ug1));
    ui->label_24->setText("Напряжение генератора переменного тока №2 фазы А, В, С, В = " + QString::number(powerdc.ug2));
    ui->label_25->setText("Напряжение генератора переменного тока №3 фазы А, В, С, В = " + QString::number(powerdc.ug3));
    ui->label_26->setText("Напряжение генератора переменного тока №4 фазы А, В, С, В = " + QString::number(powerdc.ug4));
    ui->label_27->setText("Напряжение генератора переменного тока ВСУ фазы А, В, С, В = " + QString::number(powerdc.ugvsu));
    ui->label_28->setText("Напряжение ПТС фазы А, В, С, В = " + QString::number(exchange::upts));
    ui->label_29->setText("Напряжение ПОС, В = " + QString::number(exchange::upos));
    ui->label_30->setText("Напряжение на шине генератора переменного тока #1 фазы А, В, С, В = " + QString::number(exchange::ushgP[0][0]));
    ui->label_31->setText("Напряжение на шине генератора переменного тока #2 фазы А, В, С, В = " + QString::number(exchange::ushgP[1][0]));
    ui->label_32->setText("Напряжение на шине генератора переменного тока #3 фазы А, В, С, В = " + QString::number(exchange::ushgP[2][0]));
    ui->label_33->setText("Напряжение на шине генератора переменного тока #4 фазы А, В, С, В = " + QString::number(exchange::ushgP[3][0]));
    ui->label_34->setText("Напряжение на шине генератора переменного тока РАП фазы А, В, С, В = " + QString::number(exchange::urapP[0]));
    ui->label_35->setText("Напряжение на шине переключаемой переменного тока левой фазы А, В, С, В = " + QString::number(exchange::ushpP[0][0]));
    ui->label_36->setText("Напряжение на шине переключаемой переменного тока правой фазы А, В, С, В = " + QString::number(exchange::ushpP[1][0]));
    ui->label_37->setText("Напряжение на шине 1 аварийной переменного тока = " + QString::number(exchange::ushavP[0][0]));
    ui->label_38->setText("Напряжение на шине 2 аварийной переменного тока = " + QString::number(exchange::ushavP[1][0]));
    ui->label_39->setText("Напряжение на шине аварийной переменного тока левой фазы А, В, С, В = " + QString::number(exchange::ushal));
    ui->label_40->setText("Напряжение на шине аварийной переменного тока правой фазы А, В, С, В = " + QString::number(exchange::ushap));
    ui->label_41->setText("Ток нагрузки генератора ВСУ фаза Ф (В,С), А = " + QString::number(powerdc.ingvsu));
    ui->label_42->setText("Ток нагрузки РАП фаза Ф (В,С), А = " + QString::number(powerdc.ingrap));
    ui->label_43->setText("Приборное значение тока, А = " + QString::number(powerdc.ipr));
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
    ui->uks1x2105106->setText("Ток генератоа ВСУ (пост ток) = " + QString::number(uks_inst.UKS1X2105_106));
    ui->uks1x394->setText("Напряжение на шине 1 левой сети = 27В = " + QString::number(uks_inst.UKS1X394));
    ui->uks1x395->setText("Напряжение на шине 2 левой сети = 27В = " + QString::number(uks_inst.UKS1X395));
    ui->uks2x2105106->setText("Ток аккумулятора 1, Ток РАП1 = " + QString::number(uks_inst.UKS2X2105));
    ui->uks4x2105106->setText("Ток аккумулятора 2, Ток РАП2 = " + QString::number(uks_inst.UKS4X2105));
    ui->uks2x394->setText("Напряжение аккумулятора 1 = " + QString::number(uks_inst.UKS2X394));
    ui->uks4x394->setText("Напряжение аккумулятора 2 = " + QString::number(uks_inst.UKS4X394));
    ui->uks2x395->setText("Напряжение шины авар. 1 = " + QString::number(uks_inst.UKS2X395));
    ui->uks4x395->setText("Напряжение шины авар. 2 = " + QString::number(uks_inst.UKS4X395));
    ui->uks3x394->setText("Напряжение на шине 1 правой сети = 27В = " + QString::number(uks_inst.UKS3X394));
    ui->uks3x395->setText("Напряжение на шине 2 правой сети = 27В = " + QString::number(uks_inst.UKS3X395));
    ui->uks1x382->setText("Напряжение сети ген.1, фаза А(В, С) = " + QString::number(uks_inst.UKS1X382));
    ui->uks1x385->setText("Напряжение сети ген.2, фаза А(В, С) = " + QString::number(uks_inst.UKS1X385));
    ui->uks3x382->setText("Напряжение сети ген.3, фаза А(В, С) = " + QString::number(uks_inst.UKS1X382));
    ui->uks3x385->setText("Напряжение сети ген.4, фаза А(В, С) = " + QString::number(uks_inst.UKS1X385));
    ui->uks1x388->setText("Напряжение аварийной сети 1(левой), фаза А(В, С) = " + QString::number(uks_inst.UKS1X388));
    ui->uks3x388->setText("Напряжение аварийной сети 2(правой), фаза А(В, С) = " + QString::number(uks_inst.UKS3X388));
    ui->uks2x382->setText("Напряжение шины преобразователя 1 (ПТС1), фаза А(В, С) = " + QString::number(uks_inst.UKS2X382));
    ui->uks1x248->setText("Ток генератора ВСУ, фаза А(В, С) = " + QString::number(uks_inst.UKS1X248_49));
    ui->uks3x248->setText("Ток РАП, фаза А(В, С) = " + QString::number(uks_inst.UKS3X248_49));
    ui->uks1x3105106->setText("Частота на шине генератора 1 (2), фаза А = " + QString::number(uks_inst.UKS1X3105_106));
    ui->uks1x3109110->setText("Частота на шине авар. сети 1(левой), фаза А = " + QString::number(uks_inst.UKS1X3109_110));
    ui->uks3x3105106->setText("Частота на шине генератора 3(4), фаза А = " + QString::number(uks_inst.UKS3X3105_106));
    ui->uks3x3109110->setText("Частота на шине авар. сети 2 (правой), фаза А = " + QString::number(uks_inst.UKS3X3109_110));
    ui->uks2x385->setText("Напряжение шины преобразователя 3(ПОС) левой(правой), фаза А = " + QString::number(uks_inst.UKS2X385));
    ui->uks2x386->setText("Напряжение преобразователя 1(ПТС1), фаза А = " + QString::number(uks_inst.UKS2X386));
    ui->uks2x3105106->setText("Частота на шине преобразователя 1(ПТС1), фаза А = " + QString::number(uks_inst.UKS2X3105_106));
    ui->uks2x3107108->setText("Частота на шине преобразователя 3(ПОС), фаза А = " + QString::number(uks_inst.UKS2X3107_108));
    ui->uks4x387->setText("Напряжение преобразователя 3(ПОС), фаза А = " + QString::number(uks_inst.UKS4X387));
    ui->uks1x31->setText("Генератор 1(2) перегрузка = " + QString::number(uks_inst.UKS1X31));
    ui->uks1x33->setText("ППО генератора1 (Р мало) отключи = " + QString::number(uks_inst.UKS1X33));
    ui->uks1x34->setText("ППО генератора2 (Р мало) отключи = " + QString::number(uks_inst.UKS1X34));
    ui->uks1x35->setText("Сети соединены = " + QString::number(uks_inst.UKS1X35));
    ui->uks2x31->setText("Генератор 1(2) не работает = " + QString::number(uks_inst.UKS2X31));
    ui->uks2x33->setText("Генератор ВСУ работает = " + QString::number(uks_inst.UKS2X33));
    ui->uks2x34->setText("Сеть левая частичный режим = " + QString::number(uks_inst.UKS2X34));
    ui->uks3x320->setText("Генератор 3(4) перегрузка = " + QString::number(uks_inst.UKS3X320));
    ui->uks3x322->setText("ППО генератора 3 (Р мало) отключи = " + QString::number(uks_inst.UKS3X322));
    ui->uks3x323->setText("ППО генератора 4 (Р мало) отключи = " + QString::number(uks_inst.UKS3X323));
    ui->uks4x327->setText("Генератор 3 не работает = " + QString::number(uks_inst.UKS4X327));
    ui->uks4x328->setText("Генератор 4 не работает = " + QString::number(uks_inst.UKS4X328));
    ui->uks4x329->setText("Сеть правая частичный режим = " + QString::number(uks_inst.UKS4X329));
    ui->uks2x36->setText("Преобразователь 1 (ПТС1) включен = " + QString::number(uks_inst.UKS2X36));
    ui->uks2x37->setText("Преобразователь 1 (ПТС1) подключен к шине ПТС1 = " + QString::number(uks_inst.UKS2X37));
    ui->uks2x38->setText("Преобразователь 3 (ПОС) подключен к шине ПОС левой = " + QString::number(uks_inst.UKS2X38));
    ui->uks4x331->setText("Преобразователь 3 (ПОС) включен = " + QString::number(uks_inst.UKS4X331));
    ui->uks4x333->setText("Преобразователь 3 (ПОС) подключен к шине ПОС правой = " + QString::number(uks_inst.UKS4X333));
    ui->uks2x348->setText("Неисправность ППО генератора 1 = " + QString::number(uks_inst.UKS2X348));
    ui->uks2x349->setText("Неисправность ППО генератора 2 = " + QString::number(uks_inst.UKS2X349));
    ui->uks4x347->setText("Неисправность ППО генератора 3 = " + QString::number(uks_inst.UKS4X347));
    ui->uks4x348->setText("Неисправность ППО генератора 4 = " + QString::number(uks_inst.UKS4X348));
    ui->uks2x343->setText("Генератор 1 включен(переменного тока) = " + QString::number(uks_inst.UKS2X343));
    ui->uks2x344->setText("Генератор 2 включен(переменного тока) = " + QString::number(uks_inst.UKS2X344));
    ui->uks4x343->setText("Генератор 3 включен(переменного тока) = " + QString::number(uks_inst.UKS4X343));
    ui->uks4x344->setText("Генератор 4 включен(переменного тока) = " + QString::number(uks_inst.UKS4X344));
    ui->uks2x35->setText("Генератор ВСУ включен (115/200В) = " + QString::number(uks_inst.UKS2X35));
    ui->uks3x324->setText("ВКЛ(РАП 115/200В) = " + QString::number(uks_inst.UKS3X324));
    ui->uks2x39->setText("Подключение аварийных шин 1 к аварийным шинам = " + QString::number(uks_inst.UKS2X39));
    ui->uks4x334->setText("Подключение аварийных шин 2 к аварийным шинам = " + QString::number(uks_inst.UKS4X334));
    ui->uks4x338->setText("Сеть правая от аккумулятора = " + QString::number(uks_inst.UKS4X338));
    ui->uks2x313->setText("Сеть левая от аккумулятора = " + QString::number(uks_inst.UKS2X313));
    ui->uks2x359->setText("Неисправность генератора 1 = " + QString::number(uks_inst.UKS2X359));
    ui->uks2x360->setText("Неисправность генератора 2 = " + QString::number(uks_inst.UKS2X360));
    ui->uks4x355->setText("Неисправность генератора 3 = " + QString::number(uks_inst.UKS4X355));
    ui->uks4x356->setText("Неисправность генератора 4 = " + QString::number(uks_inst.UKS4X356));
    ui->uks3x343->setText("Подключение отключаемых шины 1 правых = " + QString::number(uks_inst.UKS3X343));
    ui->uks3x344->setText("Подключение отключаемых шины 2 правых = " + QString::number(uks_inst.UKS3X344));
    ui->uks4x351->setText("Генератор 3 включен = " + QString::number(uks_inst.UKS4X351));
    ui->uks4x357->setText("Генератор 4 включен = " + QString::number(uks_inst.UKS4X357));

}
void  MainWindow:: Print_presure       ()
{

}
void  MainWindow:: Print_wingsmech     ()
{

}


