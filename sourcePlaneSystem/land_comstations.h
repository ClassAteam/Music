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
class ilsBeacon;

class land_comstations
{
public:
    vorBeacon* tryVorCapture(double freq, double x_position, double y_position);
    ilsBeacon* tryIlsCapture(double x_position, double y_position);

    land_comstations();
    static land_comstations& instance();

private:
    QVector<vorBeacon*> vorBeacons;
    QVector<ilsBeacon*> ilsBeacons;
};

class vorBeacon
{
public:
    vorBeacon* inRange(QPointF position);
    double northCourseToBeacon(double x_coord, double y_coord);
    double relativeCourseToBeacon(double x_coord, double y_coord,
                                  double jetCourse);
    bool to_from(double x_coord, double y_coord, double jet_course);
    double getFreq();
    QString checkName();//позывной маяка

    vorBeacon(QPointF centralPoint, double freq, QString name);
    vorBeacon();


private:
    const double freq;
    const QPointF position;
    const QPolygonF zone;
    QString name;
    double beaconCourse;
    QPolygonF makeRangeZone();
};

class ilsBeacon
{
public:
    double proceedValue();//относительная величина (0 - на горизонтальном
    //отрезке глиссады, 1000 - вне зоны захвата маяка)
    double proceedGlissadeValue();
    QString checkName();//позывной маяка
    ilsBeacon* inRange(QPointF position);//возвращает свой указатель если мы
    //находимся в зоне действия данного маяка

    ilsBeacon(QString name_in, QPointF runwaystart_in, QPointF runwayend_in,
                 double glissadeAngle);
    ilsBeacon();

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
bool operator!=(const ilsBeacon& localizer1, const ilsBeacon& localizer2);

//double glideSlope;

struct vorPack//выходные данные в режиме VOR
{

    int beaconCourse;//азимут радиомаяка
    int shifting;//отклонение от линии пути при полете по заданному азимуту
    bool to_from;//сигнал направления полета ВС
    int courseAngle;//курсовой угол радиомаяка
    bool signalCaptured;//сигнал готовности курса
    QString beaconName;//код опознанного маяка
};
