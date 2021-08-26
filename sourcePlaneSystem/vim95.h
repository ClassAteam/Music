#pragma once
#include <QString>
#include <QVector>
#include "land_comstations.h"

struct vorPack//выходные данные в режиме VOR
{

    int beaconCourse;//азимут радиома€ка
    int shifting;//отклонение от линии пути при полете по заданному азимуту
    bool to_from;//сигнал направлени€ полета ¬—
    int courseAngle;//курсовой угол радиома€ка
    bool signalCaptured;//сигнал готовности курса
    QString beaconName;//код опознанного ма€ка
};


class VIM95
{
    enum modeType{VOR, ILS, SP50};
    modeType mode;

    class vor
    {
        const double VISUAL_DISTANCE{10000};
        const int* course;
        const double* freq;
        bool tryBeaconCapture();
        bool producePack();
        int beaconAzimuth();
        int shifting();
        bool to_from();
        int courseAngle();
        bool signalCaptured();
        vor(int* course, double* freq);

    public:
        vorBeacon currBeacon;//захваченный ма€к в предыдущем фрейме,
        //если currBeacon.alias = "none", то ма€к не был захвачен
        vorPack pack;//выходной пакет данных дл€ последнего фрейма
    };

    class ils
    {
    public:
        bool tryBeaconCapture();
        double proceedValue();
        ilsLocalizer* currLocalizer;
    };

public:
    ils ils;
public:
    VIM95();

    static VIM95& instance();
};

