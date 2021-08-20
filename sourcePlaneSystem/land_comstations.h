#pragma once
#include <QString>
#include <QVector>
#include "externStruct/Struct_ISU.h"

class vorBeacon;
class ilsBeacon;
class ilsLocalizer;

class land_comstations
{
private:
    const double VISUAL_DISTANCE{10000};
    SH_ISU::PlanePos positon;
    QVector<vorBeacon> beacons;
    QVector<ilsLocalizer> ilsBeacons;
public:
    vorBeacon tryBeaconCapture(double freq);
    ilsLocalizer takeIlsLocalizer();//проверить сигнал горизонта глиссады

    land_comstations();
    static land_comstations& instance();
};

class vorBeacon
{
public:
    double freq;
    double distance;
    double azimuth;
    QString name;
};

class ilsLocalizer
{
public:
    double value;//относительная величина (0 - верный горизонтальный курс
    //на полосу, 100 - вне зоны захвата маяка)
    QString name;
    double x;
    double y;
    int magneticAzimuth;
};


bool operator!=(const vorBeacon& beacon1, const vorBeacon& beacon2);
bool operator!=(const ilsLocalizer& localizer1, const ilsLocalizer& localizer2);

double glideSlope;
