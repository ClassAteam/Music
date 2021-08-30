#pragma once
#include <QString>
#include <QVector>
#include <QLineF>
#include <QPointF>
#include <QPolygonF>
#include <QVector3D>
#include "externStruct/Struct_ISU.h"

class vorBeacon;
class ilsBeacon;
class ilsLocalizer;

class land_comstations
{
public:
    vorBeacon tryBeaconCapture(double freq);
    ilsLocalizer* tryIlsCapture(double x_position, double y_position);

    land_comstations();
    static land_comstations& instance();

private:
    const double VISUAL_DISTANCE{10000};
    QVector<vorBeacon> beacons;
    QVector<ilsLocalizer*> ilsBeacons;
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
    double proceedValue();//относительная величина (0 - на горизонтальном
    //отрезке глиссады, 1000 - вне зоны захвата маяка)
    double proceedGlissadeValue();
    QString checkName();//позывной маяка
    ilsLocalizer* inRange(QPointF position);//возвращает свой указатель если мы
    //находимся в зоне действия данного маяка

    ilsLocalizer(QString name_in, QPointF runwaystart_in, QPointF runwayend_in,
                 double glissadeAngle);
    ilsLocalizer();

private:
    double value;
    double glissadeValue;
    QString name;
    double distance;
    double distanceToGlissade;
    const QPointF runWayStartPos;
    const QPointF runWayEndPos;
    const QLineF glissadeHorizonLine;
    const QPolygonF approachingZone;
    const QVector<QVector3D> glissadePlane;

    QLineF makeHorizonLine();
    QPolygonF makeApproachingZone();
    QVector<QVector3D> makeGlissadePlane(double angle);
    double makeApproachingHeightPoint(double angle);
};


bool operator!=(const vorBeacon& beacon1, const vorBeacon& beacon2);
bool operator!=(const ilsLocalizer& localizer1, const ilsLocalizer& localizer2);

//double glideSlope;
