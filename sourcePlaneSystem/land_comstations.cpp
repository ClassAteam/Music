#include "land_comstations.h"
#include "algorithms.h"
#include "math.h"
#include <QDebug>

extern SH_ISU ISU;
extern SH_ISU* pISU;

const double APPROACHING_MAXIMUM_DISTANCE{18000};

land_comstations::land_comstations()
{
        ilsBeacons.append(new ilsLocalizer("test_beacon",
                                       QPointF(1000.0, 1000.0),
                                       QPointF(1100.0, 1100.0),
                                       3.0));
}

land_comstations &land_comstations::instance()
{
    static land_comstations singleton;
    return singleton;
}

vorBeacon land_comstations::tryBeaconCapture(const double freq)
{
    vorBeacon null;
    for(auto &beacon : beacons)
    {
        if(beacon.freq == freq && beacon.distance < VISUAL_DISTANCE)
        {
            return beacon;
        }
    }
    return null;
}

ilsLocalizer* land_comstations::tryIlsCapture(double x_position,
                                              double y_position)
{
    static ilsLocalizer* null = new ilsLocalizer;
    QPointF position_point(x_position, y_position);
    for(auto &beacon : ilsBeacons)
    {
        return beacon->inRange(position_point);
    }
    return null;
}

QLineF ilsLocalizer::makeHorizonLine()
{
    double PolarAngle{};
    QLineF runWayLine{runWayStartPos, runWayEndPos};
    PolarAngle = runWayLine.angle();
    QPointF point{};
    QLineF approachLine{runWayEndPos, point};
    approachLine.setAngle(PolarAngle - 180);
    approachLine.setLength(APPROACHING_MAXIMUM_DISTANCE);
    return approachLine;
}

QPolygonF ilsLocalizer::makeApproachingZone()
{
    QPolygonF zone;
    QLineF leftBorder{glissadeHorizonLine.p1(), glissadeHorizonLine.p2()};
    QLineF rightBorder{glissadeHorizonLine.p1(), glissadeHorizonLine.p2()};
    leftBorder.setAngle(leftBorder.angle() + 30);
    rightBorder.setAngle(rightBorder.angle() - 30);
    zone << glissadeHorizonLine.p1() << leftBorder.p2() << rightBorder.p2();
    return zone;
}

QVector<QVector3D> ilsLocalizer::makeGlissadePlane(double angle)
{
    QVector<QVector3D> glissadeVertPlane;
    QVector3D approachingEntranceHeight;
    QVector3D runWayStartPoint;
    QVector3D normalizedStartPoint;
    approachingEntranceHeight = QVector3D(glissadeHorizonLine.p2().x(),
                                          glissadeHorizonLine.p2().y(),
                                          makeApproachingHeightPoint(angle));
    runWayStartPoint = QVector3D(glissadeHorizonLine.p1());
    QLineF glissadeLine(ilsLocalizer::glissadeHorizonLine);
    glissadeLine.setLength(500);
    glissadeLine.setAngle(glissadeLine.angle() + 90);
    normalizedStartPoint = QVector3D(glissadeLine.p2());
    glissadeVertPlane.push_back(approachingEntranceHeight);
    glissadeVertPlane.push_back(runWayStartPoint);
    glissadeVertPlane.push_back(normalizedStartPoint);
    return glissadeVertPlane;
}

double ilsLocalizer::makeApproachingHeightPoint(double angle)
{
    double slope;
    double height;
    slope = glissadeHorizonLine.length() / abs(cos(angle));
    qDebug() << "horizonLinelength = " << glissadeHorizonLine.length();
    height = sin(angle) * slope;
    qDebug() << "cos angle = " << cos(angle);
    qDebug() << "sin angle = " << sin(angle);
    qDebug() << "height = " << height;
    return height;
}

ilsLocalizer::ilsLocalizer(QString name_in, QPointF runwaystart_in,
                           QPointF runwayend_in, double glissadeAngle)
    : name{name_in}, runWayStartPos{runwaystart_in}, runWayEndPos{runwayend_in},
    glissadeHorizonLine{makeHorizonLine()},
    approachingZone{makeApproachingZone()},
    glissadePlane{makeGlissadePlane(glissadeAngle)}
{

}

double ilsLocalizer::proceedValue()
{
        QPointF planePos{pISU->planePosX, pISU->planePosY};
        distance = dist_point_line(planePos, glissadeHorizonLine);
        return distance;
}

double ilsLocalizer::proceedGlissadeValue()
{
    QVector3D planePos(pISU->planePosX, pISU->planePosY, pISU->planePosZ);
    distanceToGlissade = planePos.distanceToPlane(glissadePlane[0],
                                                  glissadePlane[1],
                                                  glissadePlane[2]);
    return distanceToGlissade;
}

QString ilsLocalizer::checkName()
{
    return name;
}

ilsLocalizer* ilsLocalizer::inRange(QPointF position)
{
    static ilsLocalizer* null = new ilsLocalizer;

    if(approachingZone.containsPoint(position, Qt::FillRule::OddEvenFill))
        return this;

    return null;
}

ilsLocalizer::ilsLocalizer() : value{0.0}, name{"none"}, distance{0.0},
    runWayStartPos{}, runWayEndPos{}, glissadeHorizonLine{}, approachingZone{}
{

}

bool operator!=(const vorBeacon& beacon1, const vorBeacon& beacon2)
{
    if(beacon1.name != beacon2.name)
        return true;
    else
        return false;
}
//bool operator!=(const ilsLocalizer& localizer1, const ilsLocalizer& localizer2)
//{
//    if(localizer1.name != localizer2.name)
//        return true;
//    else
//        return false;
//}
