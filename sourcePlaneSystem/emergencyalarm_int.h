#pragma once
#include <QVector>
#include "algorithms.h"
#include "bss.h"
#include "allElCons.h"
#include "exchange.h"
extern bss bss_inst;
extern bss bss_inst;
extern double TICK;

enum class clrType {yellow, red, white};
enum class bssType {bss811, bss812, bss913, bss824, bss825, bss926, bss837
                     , bss838, bss939};


class emergencyalarm_int
{
public:
    emergencyalarm_int();

    class light
    {
    public:
        light(QString mname, bool* in_clue, bool* out_clue, clrType color , bssType bss);
        light(QString mname, bool* in_clue, bool* out_clue, clrType color ,
              bssType bss, bool* blinkclu);
        QString name;
        bool* inClue;
        bool* outClue;
        bool isChecked{};
        clrType color;
        bssType bss;
        bool* blinkClue{};
        int counter{};
        bool powerCheck();
        void lightFromBtn();
        void lightUp();
        void updCentrlLight(emergencyalarm_int& emergencyalarm);
        bool fromLlPad();
        bool fromPlPad();
        bool fromShoPad();
        bool fromShnPad();
        bool lamp_blink();
    };

    QVector<light*> lights;
    bool cso_ll_k{};//признак включения цсо ЛЛ красная
    bool cso_ll_zh{};//признак включения цсо ЛЛ желтая
    bool cso_pl_k{};//признак включения цсо ПЛ красная
    bool cso_pl_zh{};//признак включения цсо ПЛ желтая
    bool cso_sho_k{};//признак включения цсо ШО красная
    bool cso_sho_zh{};//признак включения цсо ШО желтая
    bool cso_shn_k{};//признак включения цсо ШН красная
    bool cso_shn_zh{};//признак включения цсо ШН желтая


public:
    virtual void updateLogic();
    void emergencyalarm_1();
};


