#pragma once
#include "bss.h"
#include "allElCons.h"
#include "input_feed.h"
#include "exchange.h"
#include "algorithms.h"

extern bss bss_inst;

const int NUMBER_OF_MONITORS{11};

class cabinlighting_int
{
public:

    /*выключатель графической станции */
    bool bgs1{};
    /*выключатель графической станции */
    bool bgs2{};

    /*признак огня выпуска шасси левого */
    bool POVSH_L{};

    /*признак огня выпуска шасси правого */
    bool POVSH_P{};

    /*признак огня выпуска шасси переднего */
    bool POVSH_PER{};

    /*признак выпуска фары ФСВ-01 левой*/
    bool PVFL{};

    /*признак выпуска фары ФСВ-01 правой*/
    bool PVFP{};


    /*priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
levogo borta shturmana-operatora*/
    bool PK1LBSHOZO{};

    /*priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
 levoy i srendey pribornih dosok letchikov(SSD24)*/
    bool PK1LSPDZO{};

    /*priznak podlkyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
 pravogo borta shturmana0navigatora*/
    bool PK1PBSHNZO{};

    /*признак подключения канала 1 светильников заливающего освещения пульта
бортового левого летчика*/
    bool PK1PBLLZO{};

    /*признак подключения канала 2 светильников заливающего освещения пульта
бортового левого летчика*/
    bool PK2PBLLZO{};

    /*признак подключения канала 2 светильников заливающего освещения пульта
бортового левого летчика*/
    bool PK1PBPLZO{};

    /*признак подключения канала 2 светильников заливающего освещения пульта
бортового левого летчика*/
    bool PK2PBPLZO{};


    /*priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
 pribornoy doski shturmana-navigatora*/
    bool PK1PDSHNZO{};

    /*priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
 pribornoy doski sjturmana - operatora*/
    bool PK1PDSHOZO{};

    /*priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
 levoy i srendey pribornih dosok letchikov(SSD24)*/
    bool PK1PPDZO{};

    bool PK2PPDZO{};

    /*priznak podlkyucheniya levogo svetilnika zalivayushego osvesheniya
 srednego pulta*/
    bool PK1SPLZO{};

    bool PK2SPLZO{};

    /*priznak podlkyucheniya pravogo svetilnika zalivayushego osvesheniya
 srednego pulta*/
    bool PK1SPPSZO;

    /*priznak podklyucheniya kanala 2 svetil'nikov zalivayushego osvesheniya
 pulta bortovogo pravogo letchika*/
    bool PK22PBPLZO;

    /*priznak podklyucheniya kanala 2 svetilnikov zalivayushego osvesheniya
 levogo borta shturmana-operatora*/
    bool PK2LBSHOZO;

    /*priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
 pravoy i srendey pribornih dosok letchikov(SSD24)*/
    bool PK2LSPDZO;

    /*priznak podlkyucheniya kanala 2 svetilnikov zalivayushego osvesheniya
 pravogo borta shturmana0navigatora*/
    bool PK2PBSHNZO;

    /*priznak podklyucheniya kanala 2 svetilnikov zalivayushego osvesheniya
 pribornoy doski shturmana-navigatora*/
    bool PK2PDSHNZO;

    /*priznak podklyucheniya kanala 2 svetilnikov zalivayushego osvesheniya
 pribornoy doski sjturmana - operatora*/
    bool PK2PDSHOZO;

    /*priznak podklyucheniya kanala 1 svetilnikov zalivayushego osvesheniya
 levoy i srendey pribornih dosok letchikov(SSD24)*/

    /*priznak podklyucheniya svetilnika svetodiodnogo kabini letchikov*/
    bool PSSD37RKL;

    /*priznak podklyucheniya svetilnika svetodiodnogo kabini shturmanov*/
    bool PSSD37RKSH;

    /*priznak podklyucheniya svetilnikov svetodiodnih individualnogo
 osvesheniya levogo*/
    bool PSSD42L;

    /*priznak podklyucheniya svetilnikov svetodiodnih individualnogo
 osvesheniya pravogo*/
    bool PSSD42P;


    /*viklyuchatel' upravleniya posadochno-rulezhnimi farami "UBORKA-VIPUSK"*/
    bool S1_3340;

    /*viklyuchatel SVET LEV*/
    bool S2_3340;

    /*viklyuchatel' SVET PRAV*/
    bool S5_3340;

    /*viklyuchatel' PITANIE upravleniya shtangoy zapravki*/
    bool s1_2860;


    /*признак подключения канала 1 встроенного освещения левой и средней прибо
орных досок летчиков в нормальном режиме */
    bool pk11lspdvo{};

    /*признак подключения канала 2 встроенного освещения левой и средней прибо
орных досок летчиков в нормальном режиме */
    bool pk12lspdvo{};

    /*признак подключения канала 1 встроенного освещения левой и
орных досок летчиков в нормальном режиме */
    bool pk11spvo{};
    bool pk12spvo{};
    bool pk11lblvo{};
    bool pk12lblvo{};
    bool pk11ppdvo{};
    bool pk12ppdvo{};
    bool pk11pblvo{};
    bool pk12pblvo{};
    bool pk21lspdvo{};
    bool pk22lspdvo{};
    bool pk21spvo{};
    bool pk22spvo{};
    bool pk21lblvo{};
    bool pk22lblvo{};
    bool pk21ppdvo{};
    bool pk22ppdvo{};
    bool pk21pblvo{};
    bool pk22pblvo{};
    bool pk31pdshovo{};
    bool pk32pdshovo{};
    bool pk31lbshvo{};
    bool pk32lbshvo{};
    bool pk31pbshvo{};
    bool pk32pbshvo{};
    bool pk31pdshnvo{};
    bool pk32pdshnvo{};
    bool pk41pdshovo{};
    bool pk42pdshovo{};
    bool pk41lbshvo{};
    bool pk42lbshvo{};
    bool pk41pbshvo{};
    bool pk42pbshvo{};
    bool pk41pdshnvo{};
    bool pk42pdshnvo{};

    bool pvpmfi[NUMBER_OF_MONITORS]{};
    bool pvpmfpu[NUMBER_OF_MONITORS]{};
    bool pvppui[NUMBER_OF_MONITORS]{};
    bool pvvopui[NUMBER_OF_MONITORS]{};
    bool pvvomfi[NUMBER_OF_MONITORS]{};
    bool pbbopui[NUMBER_OF_MONITORS]{};
    bool pvvomfpu[NUMBER_OF_MONITORS]{};
    bool pvvolspd{};
    bool pvvoppd{};
    bool pvvosp{};
    bool pvvolbl{};
    bool pvvopbl{};
    bool pvvopbsh{};
    bool pvvopbshav{};
    bool pvvopblav{};
    bool pvvolspdav{};
    bool pvvoppdav{};
    bool pvvospav{};
    bool pvvolblav{};
    bool pbbopblav{};

    bool s_11710[20]{};

    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs111{};
    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs211{};
    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs112{};
    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs212{};
    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs121{};
    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs221{};
    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs122{};
    /*признакл включения питания бортовой графической станции №1 канал 1,
полукомплект 2*/
    bool pvpbgs222{};

    /*pereklyuchatel' yarkosti aeronavigatsionnih ogney
 |ANO 10% - 30% - 1000% -Miganie"*/
    int S1_3341{};
    enum S1_3341{ANO10, ANO30, ANO100, MIGANIE, neytral};

    /*переключательв ключения режимов работы проблесковых маяков*/
    int S2_3341;
    enum S2_3341{mayak100, ponizh};

    /*pereklyuchatel' FARI ZAPRAVKI VIPUSK-UBORKA LEV*/
    int S3_3340;
    enum class S3_3340{uborka, vipusk, otkl};

    /*pereklyuchatel FARI ZAPRAVKI VIPUSK-UBORKA PRAV*/
    int S4_3340;
    enum  class S4_3340{uborka, vipusk, otkl};

    /*pereklyuchatel sveta posadochno-rulezhnih far
 |VZLET POSADKA RULENIE-OTKL"*/
    int S6_3340;
    enum s6_3340{vzlpos, rulenie, otkl};

    /*polozhenie fari svetodiodnoy vidvizhnoy FSV-01 levoy*/
    double alpha_fsv_ol;

    /*polozhenie fari svetodiodnoy vidvizhnoy FSV-01 pravoy*/
    double alpha_fsv_op;

    /*скорость приборная m/s*/
    double Vpr;

    /*положение фары ФСВ-02 освещения агрегатов заправки правой   pravoy*/
    double alpha_fazl{};
    double alpha_fazp{};

    /* скорость изменения положения фары зап*/
    double dalpha_faz{12.5};

    /*признак работы канала бусто*/
    bool pbusto3[4][2]{};

    /*признак работы канала бусто*/
    bool pbusto4[4][2]{};

    /*отказы*/
    bool otk_pbusto3[4][2]{};
    bool otk_pbusto4[4][2]{};

    bool F1_3310{true};
    bool F2_3310{true};
    bool F3_3310{true};
    bool F4_3310{true};
    bool F5_3310{true};
    bool F6_3310{true};
    bool F7_3310{true};
    bool F8_3310{true};

    bool F1_3311{true};
    bool F2_3311{true};
    bool F3_3311{true};
    bool F4_3311{true};
    bool F5_3311{true};
    bool F6_3311{true};
    bool F7_3311{true};
    bool F8_3311{true};

    bool F1_3312{true};
    bool F2_3312{true};
    bool F3_3312{true};

    bool F1_3340{true};
    bool F2_3340{true};
    bool F4_3340{true};
    bool F12_3340{true};
    bool F13_3340{true};
    bool F14_3340{true};

    bool PSSD37RKSH_D{};
    bool PSSD37RKL_D{};

    /*признак включения света левой фары светодиодной выдвижной ФСВ-02 освещения
 агрегатов заправки*/
    bool PFSV_02L;

    /*признак включения света правой фары светодиодной выдвижной ФСВ-02 освещения
 агрегатов заправки*/
    bool PFSV_02P;

    /*признак включение рулежного света левой фары посадочно-рулежной ФПР-16А*/
    bool PFPRLR;
    bool PFPRLP;

    /*признак включение рулежного света правой фары посадочно-рулежной ФПР-16А*/
    bool PFPRPR;
    bool PFPRPP;

    /*признак включения рулежного света левой фары светодиодной выдвижной ФСВ01*/
    bool PFSV_01LR;

    /*признак включения рулежного света правой фары светодиодной выдвижной ФСВ01*/
    bool PFSV_01PR;

    bool PFSV_01LP;
    bool PFSV_01PP;

    /*признак включения встроенного освещения приборной доски штурмана-оператора
в нормальном режиме*/
    bool pvvopdsho;

    /*признак включения встроенного освещения приборной доски штурмана-оператора
в аварийном режиме*/
    bool pvvopdshoav;

    /*признак включения встроенного освещения приборной доски штурмана-оператора
в нормальном режиме*/
    bool pvvopdshn;
    /*признак включения встроенного освещения приборной доски штурмана-оператора
в аварийном режиме*/
    bool pvvopdshnav;

    /*признак включения встроенного освещения приборной доски штурманов в
 нормальном режиме*/
    bool pvvolbsh;
    /*признак включения встроенного освещения приборной доски штурманов в
 аварийном*/
    bool pvvolbshav;

    bool PV_OSN_HV_10;
    bool PV_OSN_HV_30;
    bool PV_OSN_HV_100;
    bool PV_OSN_HV_MIG;
    bool PV_DOP;
    bool K32_3230;
    bool PVMV10;
    bool PVMN10;
    bool PVMV100;
    bool PVMN100;

    double UZOPBLL1;
    double UZOPBLL2;
    double UZOPBPL1;
    double UZOPBPL2;
    double UZOPDSHO1;
    double UZOPDSHO2;
    double UZOLBSHO1;
    double UZOLBSHO2;
    double UZOPDSHN1;
    double UZOPDSHN2;
    double UZOPBSHN1;
    double UZOPBSHN2;
    double USOOKL;
    double USOOKSH;
    double UZOLSPD1;
    double UZOLSPD2;
    double UZOPPD1;
    double UZOPPD2;
    double UZOSPLS1;
    double UZOSPPS1;

public:
    virtual void updateLogic();

    void cabinlighting_1();
    void cabinlighting_2();
    void cabinlighting_3();
    void cabinlighting_4();
    void cabinlighting_5();
    void cabinlighting_6();
    void cabinlighting_7();
    void cabinlighting_8();
    void cabinlighting_9();
    void cabinlighting_10();
};
