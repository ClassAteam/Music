#pragma once
#include <QString>
#include <QVector>
#include <QLineF>
#include <QPointF>
#include <QPolygonF>
#include "externStruct/Struct_ISU.h"

extern SH_ISU ISU;

class vorBeacon;
class ilsBeacon;
class ilsLocalizer;

class land_comstations
{
private:
    const double VISUAL_DISTANCE{10000};
    QPointF position;
    QVector<vorBeacon> beacons;
    QVector<ilsLocalizer> ilsBeacons;
public:
    vorBeacon tryBeaconCapture(double freq);
    ilsLocalizer* tryIlsCapture(double x_position, double y_position);
    ilsLocalizer checkIlsLocalizer();//проверить сигнал горизонта глиссады

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
    QPolygonF getZone();
    ilsLocalizer();
private:
    double course;
    double distance;
    const QPointF runWayStartPos;
    const QPointF runWayEndPos;
    const QLineF glissadeHorizonLine;
    const QPolygonF approachingZone;
    int runWayAzimuth;
    QLineF makeHorizonLine();
    QPolygonF makeApproachingZone();
    ilsLocalizer(QString name_in, QPointF runwaystart_in, QPointF runwayend_in);
public:
    ilsLocalizer& operator=(const ilsLocalizer& localizer);
};


bool operator!=(const vorBeacon& beacon1, const vorBeacon& beacon2);
bool operator!=(const ilsLocalizer& localizer1, const ilsLocalizer& localizer2);

//double glideSlope;
