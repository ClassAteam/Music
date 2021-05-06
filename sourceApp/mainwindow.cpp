
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

QSharedMemory SHARE_ADVANTECH;  // Создаём экземпляр разделяемой памяти выходной

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

    socket_out = new QUdpSocket(this); // выходной сокет bind не нужен !!!!
    socket_out->setProxy(QNetworkProxy::NoProxy);

    socket_in = new QUdpSocket(this);
    socket_in->setProxy(QNetworkProxy::NoProxy);

   // s2 = socket_in->bind(QHostAddress::LocalHost, 7755);
    s2 = socket_in->bind(7755, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(socket_in, SIGNAL(readyRead()), this, SLOT(receivingData()));

    SHARE_ADVANTECH.setKey(SHARED_MEMORY_DEVICE_CONNECT);
//    SHARE_ADVANTECH.create(sizeof(DEVICE_CONNECT));
    SHARE_ADVANTECH.attach();
    //pDevShar=(DEVICE_CONNECT)&SHARE_ADVANTECH;
   // pQtAdvan=new QtAdvantechClass();
    // Для Миши на камеру и приборы (РАСКОМЕНТИРОВАТЬ ДЛЯ LINUX!!!)
   /* shm = shm_open(SHARED_MEMORY_OBJECT_NAME, O_CREAT | O_RDWR, 0777);  //создание общей области памяти
      ftruncate(shm, sizeof(SUT));  //установка нужного размера памяти
      addr = mmap(NULL, sizeof(SUT), PROT_WRITE, MAP_SHARED, shm, 0); */
     model = new ThreadModel();//
   // MyThread thread;

   // model->start(QThread::HighestPriority);
    model->start(QThread::TimeCriticalPriority);
    /* Инициализируем Таймер и подключим его к слоту,
       который будет обрабатывать timeout() таймера */
    timer = new QTimer();
    pFrameMain= new TimeClass("F_Graf",TICK_Graf,200,25);//for control
    pFramePlanSys= new TimeClass("D_PlanSys ",200);//for control
    pFrameModel = new TimeClass("F_Model ",TICK,200,10);//for control
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start((int)TICK_Graf); // И запустим таймер


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

 // Для Миши на камеру и приборы (РАСКОМЕНТИРОВАТЬ ДЛЯ LINUX!!!)
 //shm_unlink(SHARED_MEMORY_OBJECT_NAME);

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

}
void  MainWindow:: Print_presure       ()
{

}
void  MainWindow:: Print_wingsmech     ()
{

}


