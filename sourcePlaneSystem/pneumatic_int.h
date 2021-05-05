#pragma once
#include "interfacing.h"
#include "bss.h"
#include "input_feed.h"
#include "exchange.h"
#include "uks.h"
extern double TICK;

extern bss bss_inst;
extern uks uks_inst;

class pneumatic_int //: public interfacing
{
    //Q_OBJECT
public:
//    QDeadlineTimer tsl1_timer{}, tsl2_timer{};
//    const int tsl1_ms{30000}, tsl2_ms{30000};

    bool
        psdzh_duo{},//priznak svetodioda zheltogo na DU-R8
        psdz_duo{},//priznak svetodioda zelenogo na DU-R8
        du_o{},//priznak vhodnogo signala ot perekluchatelya DU-R8 operatora
        s1_2830{},//vikluchatel AVAR SLIV TOPLIVA BAKI PEREDNIE
        s2_2830{},//vikluchatel AVAR SLIV TOPLIVA BAKI ZADNIE
        s1_3650{},//vikluchatel' NADDUV BLOKOV PEREDN
        s2_3650{},//vikluchatel' NADDUV BLOKOV ZADNIE
        y1_2830{},//priznak klapana avariynogo sliva topliva iz perednih bakov
        y4_2830{},//priznak klapana avariynogo sliva topliva iz zadnih bakov
        y1_3650{},//priznak klapana sistemi nadduva blokov REO perednih
        y2_3650{},//priznak klapana sistemi nadduva blokov REO zadnih
        k26_3230{};//priznak rele obhzatogo polozheniya levoy opori

    double
        Vnpb{},//objem gaza v sisteme nadduva blokov raioeletronnogo oborudovaniya perednih
        Vnzb{},//objem gaza v sisteme nadduva blokov radiolektronnogo oborudovaniya zadnih
        Pzm{},//davlenie v zapravochnoy magistrali
        Pger{},//davlenie v sisteme germetizatsii avariynih lyukov kabini ekipazha
        Pslt{},//davlenie v sisteme upravleniya avariynim slivom topliva
        Pnpb{},//davlenie v sisteme nadduva blokov REO perednih
        Pnzb{},//davlenie v sisteme nadduva blokov REO zadnih
        Vzm{},//objem gaza v zapravochnoy magistali pnevmosistemi
        Vslt{};//objem gaza v sisteme upravleniya avariynim slivom topliva

    bool
        du_r8{},
        PNU_pneum{},
        k91_10010{},
        k98_10010{},
        pzsnpb{},
        pzsnzb{};
    double
        Kslt1{},
        Kslt2{},
        Kger{},
        DVzm{},
        DVslt1{},
        DVslt2{},
        Vger{};

public:
   // pneumatic_int(QWidget *parent = nullptr);
        pneumatic_int(){};
    virtual void updateLogic();
    void pneumatic_1();
};
