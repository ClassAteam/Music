#pragma once
#include <QString>
#include <QVector>
#include "externStruct/Struct_ISU.h"

struct vorPack
{
    int beaconCourse;	//азимут радиомаяка
    int shifting;		//отклонение от линии пути при полете по заданному азимуту
    bool to_from;;		//сигнал направления полета ВС
    int courseAngle;	//курсовой угол радиомаяка
    bool signalCaptured;//сигнал готовности курса
    QString beaconName;	//код опознанного маяка
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
        const QVector<SH_ISU::VorBeacon>* beacons;
        bool tryBeaconCapture();
        bool producePack();
        vor(int* course, double* freq, const QVector<SH_ISU::VorBeacon>& beacons);

    public:
        SH_ISU::VorBeacon currentBeacon;
        vorPack pack;
    };

public:
    VIM95(modeType mode);
    void proceed();
};

