
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
extern aircondition_int   aircondition  ;
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
const double ts{TICK / 1000}; //cyrcle time in seconds

SH_FROMRMI_PILOT   FROMRMI_PILOT,  *pFromP=&FROMRMI_PILOT;  // for socket_in
SH_FROMRMI_PILOT   FROMRMI_OPER,   *pFromO=&FROMRMI_OPER;  // for socket_in
//SH_DEVICE_CONNECT  DEVICE_CONNECT, *pDev=&DEVICE_CONNECT ;//, *pDevShar;
//          pDev = static_cast<SH_DEVICE_CONNECT*>(SHARE_ADVANTECH.data());
SH_ISU  ISU, *pISU=&ISU ;//

QUdpSocket *socket_out = nullptr;
QUdpSocket *socket_in = nullptr;

QSharedMemory SHARE_ADVANTECH;
QSharedMemory SHARE_RMI_PILOT;
QSharedMemory SHARE_ISU;
SH_DEVICE_CONNECT* pDev{};

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
    pDev = static_cast<SH_DEVICE_CONNECT*>(SHARE_ADVANTECH.data());
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
    Print_aircondition  ()   ;
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
void  MainWindow::Print_aircondition()
{
    ui->skv_d001->setText("Признак сигнала ОТБОР ОТ ДВ1 ЗАКРЫТ = " + QString::number(aircondition.skv_d001));
    ui->skv_d002->setText("Признак сигнала ОТБОР ОТ ДВ2 ЗАКРЫТ = " + QString::number(aircondition.skv_d002));
    ui->skvd003->setText("Признак сигнала ОТБОР ОТ ДВ3 ЗАКРЫТ = " + QString::number(aircondition.skv_d003));
    ui->skv_d004->setText("Признак сигнала ОТБОР ОТ ДВ4 ЗАКРЫТ = " + QString::number(aircondition.skv_d004));
    ui->skv_d005->setText("??? = " + QString::number(aircondition.skv_d005));
    ui->skv_d006->setText("Признак сигнала ЗАСЛОНКА КОЛЬЦЕВАНИЯ ОТБОРОВ ЛЕВАЯ ОТКРЫТА = " + QString::number(aircondition.skv_d006));
    ui->skv_d007->setText("Признак сигнала ЗАСЛОНКА КОЛЬЦЕВАНИЯ ОТБОРОВ ПРАВАЯ ОТКРЫТА = " + QString::number(aircondition.skv_d007));
    ui->skv_d008->setText("Признак сигнала МАГИСТРАЛЬ 1 ОТКЛЮЧЕНА = " + QString::number(aircondition.skv_d008));
    ui->skv_d009->setText("Признак сигнала МАГИСТРАЛЬ 2 ОТКЛЮЧЕНА = " + QString::number(aircondition.skv_d009));
    ui->skv_d010->setText("Признак сигнала ЗАСЛОНКА КОЛЬЦЕВАНИЯ МАГИСТРАЛЕЙ 1, 2 ЛЕВАЯ(ТВТ1, ТВТ2) открыта = " + QString::number(aircondition.skv_d010));
    ui->skv_d011->setText("Признак сигнала ЗАСЛОНКА КОЛЬЦЕВАНИЯ МАГИСТРАЛЕЙ 1, 2 ПРАВАЯ(ТВТ1, ТВТ2) открыта = " + QString::number(aircondition.skv_d011));
    ui->skv_d012->setText("Признак сигнала ТХУ1 ОТКЛЮЧЕНА = " + QString::number(aircondition.skv_d012));
    ui->skv_d013->setText("Признак сигнала ТХУ2 ОТКЛЮЧЕНА = " + QString::number(aircondition.skv_d013));
    ui->skv_d014->setText("Признак сигнала ТХУ3 ОТКЛЮЧЕНА = " + QString::number(aircondition.skv_d014));
    ui->skv_d015->setText("Признак сигнала ТХУ4 ОТКЛЮЧЕНА = " + QString::number(aircondition.skv_d015));
    ui->skv_d016->setText("Признак сигнала СКВ ЗС ВКЛЮЧЕНА = " + QString::number(aircondition.skv_d016));
    ui->skv_d017->setText("Признак сигнала ЗАСЛОНКА ПОДАЧИ ВОЗДУХА В НОСОВОЙ ТЕХНИЧЕСКИЙ ОТСЕК ОТ ТХУ2 ЗАКРЫТА  = " + QString::number(aircondition.skv_d017));
    ui->skv_d018->setText("Признак сигнала ЗАСЛОНКА ПОДАЧИ ВОЗДУХА В НОСОВОЙ ТЕХНИЧЕСКИЙ ОТСЕК ОТ ТХУ1 ЗАКРЫТА  = " + QString::number(aircondition.skv_d018));
    ui->skv_d019->setText("Признак сигнала ЗАСЛОНКА ЛИНИИ КОЛЬЦЕВАНИЯ ТХУ3 и ТХУ4 ОТКРЫТА = " + QString::number(aircondition.skv_d019));
    ui->skv_d020->setText("Признак сигнала ЗАСЛОНКА ЗАСЛОНКА ОБОГРЕВА ВСУ ОТКРЫТА = " + QString::number(aircondition.skv_d020));
    ui->skv_d024->setText("Признак сигнала МАГИСТРАЛЬ1 ОТКАЗ = " + QString::number(aircondition.skv_d024));
    ui->skv_d025->setText("Признак сигнала МАГИСТРАЛЬ2 ОТКАЗ = " + QString::number(aircondition.skv_d025));
    ui->skv_d026->setText("Признак сигнала ОТБОР ЛЕВОГО БОРТА ОТКАЗ = " + QString::number(aircondition.skv_d026));
    ui->skv_d027->setText("Признак сигнала ОТБОР ПРАВОГО БОРТА ОТКАЗ = " + QString::number(aircondition.skv_d027));
    ui->skv_d028->setText("Признак сигнала ОТКАЗ ТХУ1 = " + QString::number(aircondition.skv_d028));
    ui->skv_d029->setText("Признак сигнала ОТКАЗ ТХУ2 = " + QString::number(aircondition.skv_d029));
    ui->skv_d030->setText("Признак сигнала ОТКАЗ ТХУ3 = " + QString::number(aircondition.skv_d030));
    ui->skv_d031->setText("Признак сигнала ОТКАЗ ТХУ4 = " + QString::number(aircondition.skv_d031));
    ui->skv_d032->setText("Признак сигнала СКВ ТХУ ОТКАЗ = " + QString::number(aircondition.skv_d032));
    ui->skv_d033->setText("Признак сигнала СКВ ПОДАЧИ НЕТ = " + QString::number(aircondition.skv_d033));
    ui->skv_d034->setText("Признак сигнала ОТКАЗ СКВ ЗС = " + QString::number(aircondition.skv_d034));
    ui->skv_d035->setText("Признак сигнала РТР И САП ОХЛАЖД ОТКАЗ = " + QString::number(aircondition.skv_d035));
    ui->skv_d036->setText("Признак сигнала ОТКАЗ ОБОГРЕВА ОТСЕКА ВСУ = " + QString::number(aircondition.skv_d036));
    ui->skv_d037->setText("Признак сигнала ТО ЗАДНИЙ - ПЕРЕГРЕВ = " + QString::number(aircondition.skv_d037));
    ui->skv_a001->setText("Сигнал ТЕМПЕРАТУРА В КАБИНЕ ЭКИПАЖА = " + QString::number(aircondition.skv_a001));
    ui->skv_a002->setText("Сигнал ТЕМПЕРАТУРА В ПЕРЕДНЕМ ГРУЗОВОМ ОТСЕКЕ = " + QString::number(aircondition.skv_a002));
    ui->skv_a003->setText("Сигнал ТЕМПЕРАТУРА В ЗАДНЕМ ГРУЗОВОМ ОТСЕКЕ = " + QString::number(aircondition.skv_a003));
    ui->skv_a004->setText("Сигнал ТЕМПЕРАТУРА В ЗАДНЕМ ТЕХНИЧЕСКОМ ОТСЕКЕ = " + QString::number(aircondition.skv_a004));

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
    ui->uks1x316->setText("ОБЛЕДИНЕНИЕ ЛЕВЫЙ ДАТЧИК = " + QString::number(uks_inst.UKS1X316));
    ui->uks1x317->setText("ОБЛЕДИНЕНИЕ ПРАВЫЙ ДАТЧИК = " + QString::number(uks_inst.UKS1X317));
    ui->uks1x315->setText("ОТКАЗ ОБОГРЕВ СТЕКЛО ЛЕВОЕ = " + QString::number(uks_inst.UKS1X315));
    ui->uks3x334->setText("ОТКАЗ ОБОГРЕВ СТЕКЛО ЛОБОВОЕ = " + QString::number(uks_inst.UKS3X334));
    ui->uks3x335->setText("ОТКАЗ ОБОГРЕВ СТЕКЛО ПРАВОЕ = " + QString::number(uks_inst.UKS3X335));


}
void  MainWindow:: Print_brakes        ()
{
    ui->pt1->setText("Давление в тормозах 1-ой паре колес = " + QString::number(brakes.brakes_Pt[0]));
    ui->pt2->setText("Давление в тормозах 2-ой паре колес = " + QString::number(brakes.brakes_Pt[1]));
    ui->pt3->setText("Давление в тормозах 3-ой паре колес = " + QString::number(brakes.brakes_Pt[2]));
    ui->pt4->setText("Давление в тормозах 4-ой паре колес = " + QString::number(brakes.brakes_Pt[3]));
    ui->pt5->setText("Давление в тормозах 5-ой паре колес = " + QString::number(brakes.brakes_Pt[4]));
    ui->pt6->setText("Давление в тормозах 6-ой паре колес = " + QString::number(brakes.brakes_Pt[5]));
    ui->bd11->setText("Давление в тормозах передней пары левой тележки = " + QString::number(brakes.balarm_BD11));
    ui->bd12->setText("Давление в тормозах средней пары левой тележки = " + QString::number(brakes.balarm_BD12));
    ui->bd21->setText("Давление в тормозах передней пары правой тележки = " + QString::number(brakes.balarm_BD21));
    ui->bd22->setText("Давление в тормозах средней пары правой тележки = " + QString::number(brakes.balarm_BD22));
    ui->bd23->setText("Давление в тормозах задней пары правой тележки = " + QString::number(brakes.balarm_BD23));
    ui->p6f01->setText("Отказ блока бупт№1 = " + QString::number(brakes.balarm_6F01));
    ui->p6f10->setText("Отказ блока бупт№2 = " + QString::number(brakes.balarm_6F10));
    ui->brakes_cp->setText("Одна пара отказ = " + QString::number(brakes.balarm_SR));
    ui->brakes_ab3->setText("Переключатель ТОРМОЗА АТВ в положении НОРМ = " + QString::number(brakes.balarm_AV3));
    ui->brakes_ab2->setText("Переключатель ТОРМОЗА АТВ в положении ПОНИЖ = " + QString::number(brakes.balarm_AV2));
    ui->brakes_ab1->setText("Переключатель ТОРМОЗА АТВ в положении СЛАБО = " + QString::number(brakes.balarm_AV1));
    ui->brakes_ca3->setText("Торможние автоматическое включено в режиме НОРМ = " + QString::number(brakes.balarm_SA3));
    ui->brakes_ca2->setText("Торможние автоматическое включено в режиме ПОНИЖ = " + QString::number(brakes.balarm_SA2));
    ui->brakes_ca1->setText("Торможние автоматическое включено в режиме СЛАБО = " + QString::number(brakes.balarm_SA1));
    ui->brakes_abo->setText("Автоматическое торможение отключено = " + QString::number(brakes.balarm_AV0));
    ui->brakes_suf->setText("Готовность к включению = " + QString::number(brakes.balarm_SUF));
    ui->brakes_sf->setText("Включение форсированного торможения автоматичски или от кнопки ФОРСИР = " + QString::number(brakes.balarm_SF));
    ui->brakes_aa11->setText("Срабатывание антиюза в передней паре левой тележки = " + QString::number(brakes.balarm_AA11));
    ui->brakes_aa12->setText("Срабатывание антиюза в средней паре левой тележки = " + QString::number(brakes.balarm_AA12));
    ui->brakes_aa13->setText("Срабатывание антиюза в задней паре левой тележки = " + QString::number(brakes.balarm_AA13));
    ui->brakes_aa21->setText("Срабатывание антиюза в передней паре правой тележки = " + QString::number(brakes.balarm_AA21));
    ui->brakes_aa22->setText("Срабатывание антиюза в средней паре правой тележки = " + QString::number(brakes.balarm_AA22));
    ui->brakes_aa23->setText("Срабатывание антиюза в задней паре правой тележки = " + QString::number(brakes.balarm_AA23));
    ui->brakes_svr1->setText("Тормоза основные отказ/тормоза резервные включи = " + QString::number(brakes.balarm_SVR1));
    ui->brakes_svr2->setText("Тормоза основные отказ/тормоз резервный включен = " + QString::number(brakes.balarm_SVR2));
    ui->brakes_ss1->setText("Тормоза основные включены = " + QString::number(brakes.balarm_SS1));
    ui->brakes_ss2->setText("Тормоза резервные включены = " + QString::number(brakes.balarm_SS2));
    ui->brakes_st->setText("Стартовый тормоз включен = " + QString::number(brakes.balarm_ST));
    ui->brakes_sor->setText("Тормоз резервный отказ/тормози стояночным = " + QString::number(brakes.balarm_SOR));
    ui->brakes_sda->setText("Давление в гидроаккумуляторе тормозов мало = " + QString::number(brakes.balarm_SDA));
    ui->brakes_sur->setText("Кнопка резерв нажата = " + QString::number(brakes.balarm_SUR));
    ui->brakes_sat->setText("Торможение аварийное = " + QString::number(brakes.balarm_SAT));
    ui->uks1x318->setText("Стояночный тормоз включен = " + QString::number(uks_inst.UKS1X318));
    ui->uks2x12->setText("Давление жидкости в гидроаккумуляторе тормозной системы = " + QString::number(uks_inst.UKS2X212));
    ui->uks2x234->setText("Давление азота в гидроаккумуляторе тормозной системы = " + QString::number(uks_inst.UKS2X234));
    ui->uks3x39->setText("Парашют сброшен = " + QString::number(uks_inst.UKS3X39));
    ui->uks3x310->setText("Парашют выпущен = " + QString::number(uks_inst.UKS3X310));
    ui->uks3x311->setText("Парашют отказ = " + QString::number(uks_inst.UKS3X311));

}
void  MainWindow:: Print_cabinlighting ()
{
    ui->pvmn10->setText("Признак включения маяка нижнего 10 = " + QString::number(cabinlighting.PVMN10));
    ui->pvmv10->setText("Признак включения маяка верхнего 10 = " + QString::number(cabinlighting.PVMV10));
    ui->pvmn100->setText("Признак включения маяка нижнего 100 = " + QString::number(cabinlighting.PVMN100));
    ui->pvmv100->setText("Признак включения маяка верхнего 100 = " + QString::number(cabinlighting.PVMV100));
    ui->pvvolspd->setText("Признак включения встроенного освещения левой и средней приборных доск в нормальном режиме = " + QString::number(cabinlighting.pvvolspd));
    ui->pvvoppd->setText("Признак включения встроенного освещения правой приборной доски нормальном режиме = " + QString::number(cabinlighting.pvvoppd));
    ui->pvvosp->setText("Признак встроенного пульта нормальном режиме = " + QString::number(cabinlighting.pvvosp));
    ui->pvvolbl->setText("Признак подключения встроенного освещения левого борта летчиков в нормальном режиме  = " + QString::number(cabinlighting.pvvolbl));
    ui->pvvopbl->setText("Признак подключения встроенного освещения правого борта летчиков в нормальном режиме  = " + QString::number(cabinlighting.pvvopbl));
    ui->pvvolspdav->setText("Признак подключения встроенного освещения левой и сердней приборных досок в аварийном режиме  = " + QString::number(cabinlighting.pvvolspdav));
    ui->pvvoppdav->setText("Признак подключения встроенного освещения правой  приборной доски в аварийном режиме  = " + QString::number(cabinlighting.pvvoppdav));
    ui->pvvospav->setText("Признак подключения встроенного освещения среднего пульта в аварийном режиме  = " + QString::number(cabinlighting.pvvospav));
    ui->pvvolblav->setText("Признак подключения встроенного освещения левого борта летчиков в аварийном режиме  = " + QString::number(cabinlighting.pvvolblav));
    ui->pvvopblav->setText("Признак подключения встроенного освещения правого борта летчиков в аварийном режиме  = " + QString::number(cabinlighting.pvvopblav));
    ui->pvvopdsho->setText("Признак включения встроенного освещения приборной доски штурмана оператора в нормальном режиме  = " + QString::number(cabinlighting.pvvopdsho));
    ui->pvvolbsh->setText("Признак включения встроенного освещения левого борта штурманов в нормальном режиме  = " + QString::number(cabinlighting.pvvolbsh));
    ui->pvvopdshn->setText("Признак включения встроенного освещения приборной доски штурмана-навигатора в нормальном режиме  = " + QString::number(cabinlighting.pvvopdshn));
    ui->pvvopbsh->setText("Признак включения встроенного освещения правого борта штурманов в нормальном режиме  = " + QString::number(cabinlighting.pvvopbsh));
    ui->pvvopdshoav->setText("Признак включения встроенного освещения приборной доски штурмана оператора в аварийном режиме  = " + QString::number(cabinlighting.pvvopdshoav));
    ui->pvvolbshav->setText("Признак включения встроенного освещения левого борта штурманов в аварийном режиме  = " + QString::number(cabinlighting.pvvolbshav));
    ui->pvvopdshnav->setText("Признак включения встроенного освещения приборной доски штурмана-навигатоа в аварийном режиме  = " + QString::number(cabinlighting.pvvopdshnav));
    ui->pvvopbshav->setText("Признак включения встроенного освещения правого борта штурманов в аварийном режиме  = " + QString::number(cabinlighting.pvvopdshnav));
    ui->povshl->setText("Признак огня выпуска шасси левого  = " + QString::number(cabinlighting.POVSH_L));
    ui->povshp->setText("Признак огня выпуска шасси правого  = " + QString::number(cabinlighting.POVSH_P));
    ui->povshper->setText("Признак огня выпуска шасси носового  = " + QString::number(cabinlighting.POVSH_PER));
    ui->pvfl->setText("Признак выпуск фары ФСВ-01 левой  = " + QString::number(cabinlighting.PVFL));
    ui->pvfp->setText("Признак выпуск фары ФСВ-01 правой  = " + QString::number(cabinlighting.PVFP));
    ui->pfprlr->setText("Признак включения рулежного света левой фары посадочно-рулежной ФПР-16А = " + QString::number(cabinlighting.PFPRLR));
    ui->pfprpr->setText("Признак включения рулежного света правой фары посадочно-рулежной ФПР-16А = " + QString::number(cabinlighting.PFPRPR));
    ui->pfprlp->setText("Признак включения посадочного света левой фары посадочно-рулежной ФПР-16А = " + QString::number(cabinlighting.PFPRLP));
    ui->pfprpp->setText("Признак включения посадочного света правой фары посадочно-рулежной ФПР-16А = " + QString::number(cabinlighting.PFPRPP));
    ui->pfsv01lr->setText("Признак включения рулежного света левой фары светодиодной выдвижной ФСВ-01 = " + QString::number(cabinlighting.PFSV_01LR));
    ui->pfsv01pr->setText("Признак включения рулежного света правой фары светодиодной выдвижной ФСВ-01 = " + QString::number(cabinlighting.PFSV_01PR));
    ui->pfsv01lp->setText("Признак включения посадочного света левой фары светодиодной выдвижной ФСВ-01 = " + QString::number(cabinlighting.PFSV_01LP));
    ui->pfsv01pp->setText("Признак включения посадочного света правой фары светодиодной выдвижной ФСВ-01 = " + QString::number(cabinlighting.PFSV_01PP));
    ui->alphafsv01l->setText("Положение фары светодиодной выдвижной ФСВ-01 левой = " + QString::number(cabinlighting.alpha_fsv_ol));
    ui->alphafsv01p->setText("Положение фары светодиодной выдвижной ФСВ-01 правой = " + QString::number(cabinlighting.alpha_fsv_op));
    ui->alphafazl->setText("Положение фары освещения агрегатов заправки левой = " + QString::number(cabinlighting.alpha_fazl));
    ui->alphafazp->setText("Положение фары освещения агрегатов заправки правой = " + QString::number(cabinlighting.alpha_fazp));
    ui->pfsv02l->setText("Признак включения света левой фары светодиодной выдвижной ФСВ-02 = " + QString::number(cabinlighting.PFSV_02L));
    ui->pfsv02p->setText("Признак включения света правой фары светодиодной выдвижной ФСВ-02 = " + QString::number(cabinlighting.PFSV_02P));
    ui->bss825x5v->setText("Признак входного сигнала на блоке БСС для табло ФАРЫ ВЫПУЩ (фары заправки) = " + QString::number(bss_inst.BSS825X5V));
    ui->bss824x1e->setText("Признак входного сигнала на блоке БСС для табло ФАРЫ ВЫПУЩ (взлет-посадка) = " + QString::number(bss_inst.BSS824X1E));
    ui->bss824x1a->setText("Признак входного сигнала на блоке БСС для табло СВЕТ ПОСАДОЧ (фары) = " + QString::number(bss_inst.BSS824X1A));
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
    ui->uks1x336->setText("ТНУ4 работает на УКС1 = " + QString::number(uks_inst.UKS1X336));
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
    ui->uks2x320->setText("Минимальный остаток жидкости в баке 1 = " + QString::number(uks_inst.UKS2X320));
    ui->uks2x321->setText("Минимальный остаток жидкости в баке 2 = " + QString::number(uks_inst.UKS2X321));
    ui->uks2x322->setText("Минимальный остаток жидкости в баке 3 = " + QString::number(uks_inst.UKS2X322));
    ui->uks2x323->setText("Минимальный остаток жидкости в баке 4 = " + QString::number(uks_inst.UKS2X323));
}
void  MainWindow:: Print_landinggea    ()
{
    ui->delta_sh_l->setText("величина, пропорциональная углу выпуска левой стойки = " + QString::number(landinggea.delta_sh_l));
    ui->delta_sh_p->setText("величина, пропорциональная углу выпуска правой стойки = " + QString::number(landinggea.delta_sh_p));
    ui->delta_sh_n->setText("величина, пропорциональная углу выпуска носовой стойки = " + QString::number(landinggea.delta_sh_n));
    ui->fi_nk->setText("Текущее значение угла поворота носового колеса, град = " + QString::number(landinggea.fi_nk));
    ui->gk_vsh->setText("гидрокран выпуска шасси = " + QString::number(landinggea.gk_vsh));
    ui->gk_ush->setText("гидрокран уборки шасси = " + QString::number(landinggea.gk_ush));
    ui->p1oblop->setText("признак 1 обжатия левой опоры шасси = " + QString::number(exchange::P1OBLOP));
    ui->p2oblop->setText("признак 2 обжатия левой опоры шасси = " + QString::number(exchange::P2OBLOP));
    ui->p1obpop->setText("признак 1 обжатия правой опоры шасси = " + QString::number(exchange::P1OBPOP));
    ui->p2obpop->setText("признак 2 обжатия правой опоры шасси = " + QString::number(exchange::P2OBPOP));
    ui->pvplop->setText("признак выпущенного положения левой опоры шасси = " + QString::number(landinggea.PVPLOP));
    ui->puplop->setText("признак убранного положения левой опоры шасси = " + QString::number(landinggea.PUPLOP));
    ui->pvppop->setText("признак выпущенного положения правой опоры шасси = " + QString::number(landinggea.PVPPOP));
    ui->puppop->setText("признак убранного положения правой опоры шасси = " + QString::number(landinggea.PUPPOP));
    ui->pvpperop->setText("признак выпущенного положения передней опоры шасси = " + QString::number(landinggea.PVPPEROP));
    ui->pupperop->setText("признак убранного положения передней опоры шасси = " + QString::number(landinggea.PUPPEROP));
    ui->uks4x313->setText("ЛЕВАЯ ОПОРА ОБЖАТА КАНАЛ 1 = " + QString::number(uks_inst.UKS4X313));
    ui->uks4x316->setText("ЛЕВАЯ ОПОРА УБРАНА = " + QString::number(uks_inst.UKS4X316));
    ui->uks4x317->setText("СТВОРКИ ЛЕВОЙ ОПОРЫ ЗАКРЫТЫ = " + QString::number(uks_inst.UKS4X317));
    ui->uks4x315->setText("ЛЕВАЯ ОПОРА СМЕЩЕНА = " + QString::number(uks_inst.UKS4X315));
    ui->uks4x314->setText("ЛЕВАЯ ОПОРА ВЫПУЩЕНА = " + QString::number(uks_inst.UKS4X314));
    ui->uks4x38->setText("ПРАВАЯ ОПОРА ОБЖАТА КАНАЛ 1 = " + QString::number(uks_inst.UKS4X38));
    ui->uks4x39->setText("ПРАВАЯ ОПОРА ВЫПУЩЕНА = " + QString::number(uks_inst.UKS4X39));
    ui->uks4x310->setText("ПРАВАЯ ОПОРА СМЕЩЕНА = " + QString::number(uks_inst.UKS4X310));
    ui->uks4x311->setText("ПРАВАЯ ОПОРА УБРАНА = " + QString::number(uks_inst.UKS4X311));
    ui->uks4x312->setText("СТВОРКИ ПРАВОЙ ОПОРЫ ЗАКРЫТЫ = " + QString::number(uks_inst.UKS4X312));
    ui->uks4x322->setText("ЛЕВАЯ ОПОРА ОБЖАТА КАНАЛ 2 = " + QString::number(uks_inst.UKS4X322));
    ui->uks4x321->setText("ПРАВАЯ ОПОРА ОБЖАТА КАНАЛ 2 = " + QString::number(uks_inst.UKS4X321));
    ui->uks4x318->setText("ПЕРЕДНЯЯ ОПОРА ВЫПУЩЕНА = " + QString::number(uks_inst.UKS4X318));
    ui->uks4x320->setText("СТВОРКИ ПЕРЕДНЕЙ ОПОРЫ ЗАКРЫТЫ = " + QString::number(uks_inst.UKS4X320));
    ui->uks4x319->setText("ПЕРЕДНЯЯ ОПОРА УБРАНА = " + QString::number(uks_inst.UKS4X319));
    ui->sus14a1isp->setText("ИСПРАВНОСТЬ канала 1 СУС-14А = " + QString::number(landinggea.SUS_14A_1_isp));
    ui->sus14a2isp->setText("ИСПРАВНОСТЬ канала 2 СУС-14А = " + QString::number(landinggea.SUS_14A_2_isp));
    ui->sus14a1rul->setText("РУЛЕНИЕ канала 1 СУС-14А = " + QString::number(landinggea.SUS_14A_1_rul));
    ui->sus14a2rul->setText("РУЛЕНИЕ канала 2 СУС-14А = " + QString::number(landinggea.SUS_14A_2_rul));
    ui->sus14a1vzl->setText("ВЗЛЕТА - ПОСАДКА канала 1 СУС-14А = " + QString::number(landinggea.SUS_14A_1_vzl));
    ui->sus14a2vzl->setText("ВЗЛЕТА - ПОСАДКА канала 2 СУС-14А = " + QString::number(landinggea.SUS_14A_2_vzl));

}
void  MainWindow:: Print_pneumatic     ()
{
    ui->y1_2830->setText("признак аварийного слива топлива из передних баков = " + QString::number(pneumatic.y1_2830));
    ui->y4_2830->setText("признак аварийного слива топлива из задних баков = " + QString::number(pneumatic.y4_2830));
    ui->y1_3650->setText("признак клапана системы наддува блоков РЭО передних = " + QString::number(pneumatic.y1_3650));
    ui->y2_3650->setText("признак клапана системы наддува блоков РЭО задних = " + QString::number(pneumatic.y2_3650));
    ui->uks3x34->setText("Люки гермет отказ = " + QString::number(uks_inst.UKS3X34));
    ui->uks3x35->setText("Люки гермет отказ = " + QString::number(uks_inst.UKS3X35));
    ui->uks3x17->setText("Наддув блоков давл. мало передн. = " + QString::number(uks_inst.UKS3X17));
    ui->uks3x18->setText("Наддув блоков давл. мало задн. = " + QString::number(uks_inst.UKS3X18));
    ui->pzm->setText("Давление в заправочной магистрали = " + QString::number(pneumatic.Pzm));
    ui->pslt->setText("Давление в системе управление аварийным сливом топлива = " + QString::number(pneumatic.Pslt));
    ui->pnpb->setText("Давление в системе наддува блоков РЕО передних = " + QString::number(pneumatic.Pnpb));
    ui->pnzb->setText("Давление в системе наддува блоков РЕО задних = " + QString::number(pneumatic.Pnzb));
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
    ui->upr->setText("Приборное значение напряжения, В = " + QString::number(powerdc.upr));
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
    ui->dpkabind->setText("Перепад давление в гермокабине, индикаторное значение, кгс/см^2 = " + QString::number(presure.Pkab_ind_delta));
    ui->hkabind->setText("высота в гермокабине, индикаторное значение, кгс/см^2 = " + QString::number(presure.Hkab_ind));
    ui->skv_300->setText("КАБИНА ДАВЛ ВЕЛИКО = " + QString::number(presure.SKD_D300));
    ui->skv_301->setText("КАБИНА ДАВЛ МАЛО = " + QString::number(presure.SKD_D301));
}
void  MainWindow:: Print_wingsmech     ()
{
    ui->deltazl->setText("Текущее положение закрылков левых, град = " + QString::number(wingsmech.delta_z_l));
    ui->deltazp->setText("Текущее положение закрылков правых, град = " + QString::number(wingsmech.delta_z_p));
    ui->deltaprl->setText("Текущее положение предкрылков левых, град = " + QString::number(wingsmech.delta_pr_l));
    ui->deltaprp->setText("Текущее положение предкрылков правых, град = " + QString::number(wingsmech.delta_pr_p));
    ui->xl->setText("Положение подвижной части крыла левой = " + QString::number(wingsmech.X_L));
    ui->xp->setText("Положение подвижной части крыла правой = " + QString::number(wingsmech.X_P));
    ui->deltaz1pk->setText("значение сигнала с датчика положения закрылков 1 подканала левого = " + QString::number(wingsmech.delta_z_1_pk));
    ui->deltaz3pk->setText("значение сигнала с датчика положения закрылков 3 подканала левого = " + QString::number(wingsmech.delta_z_3_pk));
    ui->x1pk->setText("значение сигнала с датчика положения ПЧК 1 подканала левого = " + QString::number(wingsmech.X_1_pk));
    ui->x3pk->setText("значение сигнала с датчика положения ПЧК 3 подканала левого = " + QString::number(wingsmech.X_3_pk));
    ui->deltazl110->setText("положение левых закрылков в БИС№1 из состава ИУС, град = " + QString::number(wingsmech.delta_z_l_110));
    ui->deltazp111->setText("положение правых закрылков в БИС№1 из состава ИУС, град = " + QString::number(wingsmech.delta_z_p_111));
    ui->deltaz112->setText("положение трансмиссии закрылков, обороты = " + QString::number(wingsmech.delta_z_112));
    ui->deltaruz113->setText("положение ручки управления закрылками = " + QString::number(wingsmech.delta_ruz_113));
    ui->deltaprl114->setText("положение левых предкрылков = " + QString::number(wingsmech.delta_pr_l_114));
    ui->deltaprp115->setText("положение правых предкрылков = " + QString::number(wingsmech.delta_pr_p_115));
    ui->deltapr116->setText("положение трансмиссии предкрылков = " + QString::number(wingsmech.delta_pr_116));
    ui->p130_11->setText("ГИДРОПИТАНИЕ 1 КАНАЛ = " + QString::number(uks_inst.P_130_11));
    ui->p130_12->setText("СЛЕДЯЩИЙ РЕЖИМ 1 КАНАЛ = " + QString::number(uks_inst.P_130_12));
    ui->p130_13->setText("ЗАКРЫЛКИ НЕВЗЛЕТ 1 КАНАЛ = " + QString::number(uks_inst.P_130_13));
    ui->p130_14->setText("ПРЕДКРЫЛКИ НЕВЗЛЕТ 1 КАНАЛ = " + QString::number(uks_inst.P_130_14));
    ui->p130_15->setText("Работа канала на выпуск закрылков 1 КАНАЛ = " + QString::number(uks_inst.P_130_15));
    ui->p130_16->setText("Работа канала на уборку закрылков 1 КАНАЛ = " + QString::number(uks_inst.P_130_16));
    ui->p130_17->setText("Работа канала на выпуск предкрылков 1 КАНАЛ = " + QString::number(uks_inst.P_130_17));
    ui->p130_18->setText("Работа канала на уборку предкрылков 1 КАНАЛ = " + QString::number(uks_inst.P_130_18));
    ui->p130_19->setText("РЕЗЕРВНЫЙ РЕЖИМ 1 КАНАЛ = " + QString::number(uks_inst.P_130_19));
    ui->p130_20->setText("ВЫПУСК ЗАКРЫЛКОВ В РЕЗЕРВНОМ РЕЖИМЕ 1 КАНАЛ = " + QString::number(uks_inst.P_130_20));
    ui->p130_21->setText("УБОРКА ЗАКРЫЛКОВ В РЕЗЕРВНОМ РЕЖИМЕ 1 КАНАЛ = " + QString::number(uks_inst.P_130_21));
    ui->p130_22->setText("ВЫПУСК ПРЕДКРЫЛКОВ В РЕЗЕРВНОМ РЕЖИМЕ 1 КАНАЛ = " + QString::number(uks_inst.P_130_22));
    ui->p130_23->setText("УБОРКА ПРЕДКРЫЛКОВ В РЕЗЕРВНОМ РЕЖИМЕ 1 КАНАЛ = " + QString::number(uks_inst.P_130_23));
    ui->p130_24->setText("Срабатывание тормоза левых закрылков 1 КАНАЛ = " + QString::number(uks_inst.P_130_24));
    ui->p130_25->setText("Срабатывание тормоза правых закрылков 1 КАНАЛ = " + QString::number(uks_inst.P_130_25));
    ui->p132_11->setText("Гидропитание (2канал СПМК) = " + QString::number(uks_inst.P_132_11));
    ui->p132_12->setText("Следящий режим (2канал СПМК) = " + QString::number(uks_inst.P_132_12));
    ui->p132_13->setText("Закрылки невзлет (2канал СПМК) = " + QString::number(uks_inst.P_132_13));
    ui->p132_14->setText("Предкрылки невзлет (2канал СПМК) = " + QString::number(uks_inst.P_132_14));
    ui->p132_15->setText("Работа канала на выпуск закрылков (2канал СПМК) = " + QString::number(uks_inst.P_132_15));
    ui->p132_16->setText("Работа канала на уборку закрылков (2канал СПМК) = " + QString::number(uks_inst.P_132_16));
    ui->p132_17->setText("Работа канала на выпуск предкрылков (2канал СПМК) = " + QString::number(uks_inst.P_132_17));
    ui->p132_18->setText("Работа канала на уборку предкрылков (2канал СПМК) = " + QString::number(uks_inst.P_132_18));
    ui->p132_19->setText("Резервный режим (2канал СПМК) = " + QString::number(uks_inst.P_132_19));
    ui->p132_20->setText("Выпуск закрылков в резервном режиме (2канал СПМК) = " + QString::number(uks_inst.P_132_20));
    ui->p132_21->setText("Уборка закрылков в резервном режиме (2канал СПМК) = " + QString::number(uks_inst.P_132_21));
    ui->p132_22->setText("Выпуск предкрылков в резервном режиме (2канал СПМК) = " + QString::number(uks_inst.P_132_22));
    ui->p132_23->setText("Уборка предкрылков в резервном режиме (2канал СПМК) = " + QString::number(uks_inst.P_132_23));
    ui->p132_24->setText("Срабатывание тормоза левых закрылков (2канал СПМК) = " + QString::number(uks_inst.P_132_24));
    ui->p132_25->setText("Срабатывание тормоза правых закрылков (2канал СПМК) = " + QString::number(uks_inst.P_132_25));
    ui->p131_11->setText("Нет корректных данных КЛС от БИС №1 (1канал СПМК) = " + QString::number(uks_inst.P_131_11));
    ui->p131_12->setText("Нет корректных данных КЛС от БИС №2 (1канал СПМК) = " + QString::number(uks_inst.P_131_12));
    ui->p131_13->setText("Отказ коррекции (1канал СПМК) = " + QString::number(uks_inst.P_131_13));
    ui->p131_14->setText("Отказ канала управления закрылками (1канал СПМК) = " + QString::number(uks_inst.P_131_14));
    ui->p131_15->setText("Отказ канала управления предкрылками (1канал СПМК) = " + QString::number(uks_inst.P_131_15));
    ui->p131_16->setText("Отказ следящего режима (1канал СПМК) = " + QString::number(uks_inst.P_131_16));
    ui->p131_17->setText("Заклинивание трансмиссии закрылков (1канал СПМК) = " + QString::number(uks_inst.P_131_17));
    ui->p131_18->setText("Заклинивание трансмиссии предкрылков (1канал СПМК) = " + QString::number(uks_inst.P_131_18));
    ui->p131_19->setText("Отказ, приводящий к выключению блока управления (1канал СПМК) = " + QString::number(uks_inst.P_131_19));
    ui->p131_20->setText("Рассинхронизация закрылков (1канал СПМК) = " + QString::number(uks_inst.P_131_20));
    ui->p131_21->setText("Рассинхронизация предкрылков (1канал СПМК) = " + QString::number(uks_inst.P_131_21));
    ui->p133_11->setText("Нет корректных данных по КЛС от БИС №1 (1канал СПМК) = " + QString::number(uks_inst.P_131_11));
    ui->p133_12->setText("Нет корректных данных по КЛС от БИС №2 (2канал СПМК) = " + QString::number(uks_inst.P_131_12));
    ui->p133_13->setText("Отказ коррекции (2канал СПМК) = " + QString::number(uks_inst.P_131_13));
    ui->p133_14->setText("Отказ канала управления закрылками (2канал СПМК) = " + QString::number(uks_inst.P_131_14));
    ui->p133_15->setText("Отказ канала управления предкрылками (2канал СПМК) = " + QString::number(uks_inst.P_131_15));
    ui->p133_16->setText("Отказ следящего режима (2канал СПМК) = " + QString::number(uks_inst.P_131_16));
    ui->p133_17->setText("Заклинивание трансмиссии закрылков (2канал СПМК) = " + QString::number(uks_inst.P_131_17));
    ui->p133_18->setText("Заклинивание трансмиссии предкрылков (2канал СПМК) = " + QString::number(uks_inst.P_131_18));
    ui->p133_19->setText("Отказ, приводящий к выключению блока управления (1канал СПМК) = " + QString::number(uks_inst.P_131_19));
    ui->p133_20->setText("Рассинхронизация закрылков (1канал СПМК) = " + QString::number(uks_inst.P_131_20));
    ui->p133_21->setText("Рассинхронизация предкрылков (1канал СПМК) = " + QString::number(uks_inst.P_133_21));
    ui->xl120->setText("Положение левой консоли = " + QString::number(wingsmech.XL_120));
    ui->xp121->setText("Положение правой консоли = " + QString::number(wingsmech.XP_121));
    ui->xtr122->setText("Положение трнасмиссии консоли = " + QString::number(wingsmech.XTR_122));
    ui->deltaruk123->setText("Положение ручки управления поворотом консоли = " + QString::number(wingsmech.delta_ruk_123));
    ui->p140_11->setText("Гидропитание 1 (1 канал СПК) = " + QString::number(uks_inst.P_140_11));
    ui->p140_12->setText("Гидропитание 2 (1 канал СПК) = " + QString::number(uks_inst.P_140_12));
    ui->p140_13->setText("Работа канала на выпуск консолей (1 канал СПК) = " + QString::number(uks_inst.P_140_13));
    ui->p140_14->setText("Работа канала на уборку консолей (1 канал СПК) = " + QString::number(uks_inst.P_140_14));
    ui->p140_15->setText("Резервный режим (1 канал СПК) = " + QString::number(uks_inst.P_140_15));
    ui->p140_16->setText("Выпуск консолей в резервном режиме (1 канал СПК) = " + QString::number(uks_inst.P_140_16));
    ui->p140_17->setText("Уборка консолей в резервном режиме (1 канал СПК) = " + QString::number(uks_inst.P_140_17));
    ui->p140_18->setText("Срабатывание тормоза левой консоли (1 канал СПК) = " + QString::number(uks_inst.P_140_18));
    ui->p140_19->setText("Срабатывание тормоза правой консоли (1 канал СПК) = " + QString::number(uks_inst.P_140_19));
    ui->p142_11->setText("Гидропитание 1 (2 канал СПК) = " + QString::number(uks_inst.P_142_11));
    ui->p142_12->setText("Гидропитание 2 (2 канал СПК) = " + QString::number(uks_inst.P_142_12));
    ui->p142_13->setText("Работа канала на выпуск консолей (2 канал СПК) = " + QString::number(uks_inst.P_142_13));
    ui->p142_14->setText("Работа канала на уборку консолей (2 канал СПК) = " + QString::number(uks_inst.P_142_14));
    ui->p142_15->setText("Резервный режим (2 канал СПК) = " + QString::number(uks_inst.P_142_15));
    ui->p142_16->setText("Выпуск консолей в резервном режиме (2 канал СПК) = " + QString::number(uks_inst.P_142_16));
    ui->p142_17->setText("Уборка консолей в резервном режиме (2 канал СПК) = " + QString::number(uks_inst.P_142_17));
    ui->p142_18->setText("Срабатывание тормоза левой консоли (2 канал СПК) = " + QString::number(uks_inst.P_142_18));
    ui->p142_19->setText("Срабатывание тормоза правой консоли (2 канал СПК) = " + QString::number(uks_inst.P_142_19));
    ui->p141_11->setText("Нет корректных данных по КЛС от БИС №1 (1 канал СПК) = " + QString::number(uks_inst.P_141_11));
    ui->p141_12->setText("Нет корректных данных по КЛС от БИС №2 (1 канал СПК) = " + QString::number(uks_inst.P_141_12));
    ui->p141_13->setText("Отказ канала управления консолями (1 канал СПК) = " + QString::number(uks_inst.P_141_13));
    ui->p141_14->setText("Отказ следящего режима (1 канал СПК) = " + QString::number(uks_inst.P_141_14));
    ui->p141_15->setText("Заклинивание трансмиссии консолей (1 канал СПК) = " + QString::number(uks_inst.P_141_15));
    ui->p141_16->setText("Отказ, приводящий к выключению блока управления (1 канал СПК) = " + QString::number(uks_inst.P_141_16));
    ui->p141_17->setText("Рассинхронизация консолей (1 канал СПК) = " + QString::number(uks_inst.P_141_17));
    ui->p143_11->setText("Нет корректных данных по КЛС от БИС №1 (2 канал СПК) = " + QString::number(uks_inst.P_143_11));
    ui->p143_12->setText("Нет корректных данных по КЛС от БИС №2 (2 канал СПК) = " + QString::number(uks_inst.P_143_12));
    ui->p143_13->setText("Отказ канала управления консолями (2 канал СПК) = " + QString::number(uks_inst.P_143_13));
    ui->p143_14->setText("Отказ следящего режима (2 канал СПК) = " + QString::number(uks_inst.P_143_14));
    ui->p143_15->setText("Заклинивание трансмиссии консолей (2 канал СПК) = " + QString::number(uks_inst.P_143_15));
    ui->p143_16->setText("Отказ приводящий к выключению блока управления (2 канал СПК) = " + QString::number(uks_inst.P_143_16));
    ui->p143_17->setText("Рассинхронизация консолей (2 канал СПК) = " + QString::number(uks_inst.P_143_17));
}


