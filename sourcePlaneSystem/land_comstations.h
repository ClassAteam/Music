#pragma once
#include <QString>
#include <QVector>
#include <QLineF>
#include <QPointF>
#include <QPolygonF>
#include <QVector3D>
#include <vector>
#include <memory>
#include "externStruct/Struct_ISU.h"

class Airfield;
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
    std::unique_ptr<std::vector<std::unique_ptr<Airfield>>> stations;
};

class vorBeacon
{
public:
    vorBeacon* inRange(QPointF position);
    double northCourseToBeacon(double x, double y);
    double relativeCourseToBeacon(double x, double y, double Course);
    bool to_from(double x, double y, double jet_course);
    double distanceToBeacon(double x, double y);
    double getFreq();
    QString checkName();

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
    enum passedMarker{INNER, MIDDLE, OUTER, NOT_APPROACHED};
    double distanceToGlissadeProj(double x, double y);
    double distnaceToGlissadePlane(double x, double y, double z);
    double distanceToTouchDownPoint(double x, double y, double z);
    passedMarker checkMarker(double x, double y, double z);
    bool isAccurateApproach(double x, double y, double z);
    QString checkName();
    ilsBeacon* inRange(QPointF position);

    ilsBeacon(QString name, QPointF runwaystart, QPointF runwayend,
              double glissadeAngle, double outer_marker_dist);
    ilsBeacon();


private:
    const QString name;
    const QPointF runWayStartPos;
    const QPointF runWayEndPos;
    const QLineF glissadeHorizonLine;
    const QPolygonF approachingZone;
    const QVector<QVector3D> glissadePlane;
    const double outerMarkerDist;

    QLineF makeHorizonLine();
    QPolygonF makeApproachingZone();
    QVector<QVector3D> makeGlissadePlane(double angle);
    double ApproachingHeight(double angle);
    bool innerMarkerPos(double x, double y, double z);
    bool middleMarkerPos(double x, double y, double z);
    bool outerMarkerPos(double x, double y, double z);

    double freq;
    bool setFreq();
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
