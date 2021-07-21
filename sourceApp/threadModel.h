#ifndef THREADMODEL_H
#define THREADMODEL_H

#include <QThread>
//#include <QMainWindow>
//#include <QTimer>
//#include <QTime>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE
//========================================model
#include "sourcePlaneSystem\antifire_int.h       "     //  противопожарный
#include "sourcePlaneSystem\antiicing_int.h      "     //  антиобледенительный
#include "sourcePlaneSystem\brakes_int.h         "     //  тормоза
#include "sourcePlaneSystem\cabinlighting_int.h  "     //  кабинное освещение
#include "sourcePlaneSystem\emergencyalarm_int.h "     //  аварийная сигнализация
#include "sourcePlaneSystem\exchange.h           "     //  обмен
#include "sourcePlaneSystem\hydro_int.h          "     //  гидро
#include "sourcePlaneSystem\landinggear_int.h    "     //  шасси
#include "sourcePlaneSystem\pneumatic_int.h      "     //  пневматика
#include "sourcePlaneSystem\powerdc_int.h        "     //  электроэнергия
#include "sourcePlaneSystem\presure_int.h        "     //  давление
#include "sourcePlaneSystem\uks.h                "     //
#include "sourcePlaneSystem\wingsmech_int.h      "     //  мехаанизация крыла
#include "sourcePlaneSystem\aircondition_int.h   "     //  кондиционир воздуха
//void dispPlanSystem();
//void antifire_1();
//void antifire_2();
//void antifire_3();
//void antiicing_1();
//void antiicing_2();
//void antiicing_3();
//void antiicing_4();
//void antiicing_5();
//void antiicing_6();
//void brakes_1();
//void brakes_2();
//void brakes_3();
//void brakes_4();
//void brakes_5();
//void brakes_6();
//void cabinlighting_1();
//void cabinlighting_2();
//void cabinlighting_3();
//void cabinlighting_4();
//void cabinlighting_5();
//void emergencyalarm_1();
//void emergencyalarm_2();
//void emergencyalarm_3();
//void emergencyalarm_4();
//void emergencyalarm_5();
//void emergencyalarm_6();
//void emergencyalarm_7();
//void emergencyalarm_8();
//void emergencyalarm_9();
//void hydro_1();
//void hydro_2();
//void hydro_3();
//void hydro_4();
//void hydro_5();
//void hydro_7();
//void hydro_8();
//void hydro_9();
//void landinggear_1();
//void landinggear_2();
//void landinggear_3();
//void landinggear_4();
//void landinggear_5();
//void landinggear_6();
//void landinggear_7();
//void landinggear_8();
//void landinggear_9();
//void powerdc_1();
//void powerdc_2_3();
//void powerdc_4();
//void powerdc_5_6();
//void powerdc_7();
//void powerdc_8();
//void powerdc_9_10();
//void powerdc_11();
//void powerdc_12();
//void powerdc_13();
//void powerdc_14();
//void powerdc_15();
//void powerdc_16();
//void presure();
//void wingsmech_1();
//void wingsmech_2();
//void wingsmech_3();
//void wingsmech_4();
//======================================

class ThreadModel : public QThread
{
 //Q_OBJECT
public:
    ThreadModel(){};
    ~ThreadModel(){};

    void run () ;

};


#endif //THREADMODEL_H



