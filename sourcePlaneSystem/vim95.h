#pragma once
#include <QString>
#include <QVector>
#include "land_comstations.h"

struct vorPack//выходные данные в режиме VOR
{

    int beaconCourse;//азимут радиомаяка
    int shifting;//отклонение от линии пути при полете по заданному азимуту
    bool to_from;//сигнал направления полета ВС
    int courseAngle;//курсовой угол радиомаяка
    bool signalCaptured;//сигнал готовности курса
    QString beaconName;//код опознанного маяка
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
        vor(int* course, double* freq);

    public:
        vorBeacon currBeacon;//захваченный маяк в предыдущем фрейме,
        //если currBeacon.alias = "none", то маяк не был захвачен
        vorPack pack;//выходной пакет данных для последнего фрейма
    };

    class ilsSystem
    {
    public:
        double proceedValue();//получить отклонение по горизонту
        double proceedGlissadeValue();//получить отклонение от глиссады
        ilsLocalizer* currLocalizer;

    private:
        bool tryBeaconCapture();
    };

public:
    VIM95();
    ilsSystem ils;
    static VIM95& instance();
};

