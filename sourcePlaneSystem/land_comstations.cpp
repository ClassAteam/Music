#include "land_comstations.h"
#include "algorithms.h"
#include "math.h"
#include <QDebug>

#include "databasemanager.h"

const double APPROACHING_MAXIMUM_DISTANCE{18000};
const double VOR_BEACON_REACH_DISTANCE{10000};
const double ACCEPTABLE_DISTANCE_TO_LOCALIZER{50};
const double ACCEPTABLE_DISTANCE_TO_GLISSADE{30};
const double INNER_MARKER_DISTANCE{304.8};
const double MIDDLE_MARKER_DISTANCE{1066.8};

land_comstations::land_comstations()
{
    vorBeacons = DatabaseManager::instance().getVorBeacons();
    ilsBeacons = DatabaseManager::instance().getIlsBeacons();
}

ilsBeacon* land_comstations::tryIlsCapture(double x_position, double y_position)
{
    static ilsBeacon* null = new ilsBeacon;
    QPointF position_point(x_position, y_position);
    for(auto &beacon : *ilsBeacons)
    {
        return beacon->inRange(position_point);
    }
    return null;
}

QLineF ilsBeacon::makeHorizonLine()
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

QPolygonF ilsBeacon::makeApproachingZone()
{
    QPolygonF zone;
    QLineF leftBorder{glissadeHorizonLine.p1(), glissadeHorizonLine.p2()};
    QLineF rightBorder{glissadeHorizonLine.p1(), glissadeHorizonLine.p2()};
    leftBorder.setAngle(leftBorder.angle() + 30);
    rightBorder.setAngle(rightBorder.angle() - 30);
    zone << glissadeHorizonLine.p1() << leftBorder.p2() << rightBorder.p2();
    return zone;
}

QVector<QVector3D> ilsBeacon::makeGlissadePlane(double angle)
{
    QVector<QVector3D> glissadeVertPlane;
    QVector3D approachingEntranceHeight;
    QVector3D runWayStartPoint;
    QVector3D normalizedStartPoint;
    approachingEntranceHeight = QVector3D(glissadeHorizonLine.p2().x(),
                                          glissadeHorizonLine.p2().y(),
                                          ApproachingHeight(angle));
    runWayStartPoint = QVector3D(glissadeHorizonLine.p1());
    QLineF glissadeLine(ilsBeacon::glissadeHorizonLine);
    glissadeLine.setLength(500);
    glissadeLine.setAngle(glissadeLine.angle() + 90);
    normalizedStartPoint = QVector3D(glissadeLine.p2());
    glissadeVertPlane.push_back(approachingEntranceHeight);
    glissadeVertPlane.push_back(runWayStartPoint);
    glissadeVertPlane.push_back(normalizedStartPoint);
    return glissadeVertPlane;
}

double ilsBeacon::ApproachingHeight(double angle)
{
    double slope;
    double height;
    slope = glissadeHorizonLine.length() / abs(cos(angle));
    qDebug() << "horizonLinelength = " << glissadeHorizonLine.length();
    height = sin(angle) * slope;
    return height;
}

bool ilsBeacon::innerMarkerPos(double x, double y, double z)
{
    if(distanceToTouchDownPoint(x,y,z) > INNER_MARKER_DISTANCE - 50.0 &&
        distanceToTouchDownPoint(x,y,z) < INNER_MARKER_DISTANCE +50)
        return true;
    else
        return false;
}

bool ilsBeacon::middleMarkerPos(double x, double y, double z)
{
    if(distanceToTouchDownPoint(x,y,z) > MIDDLE_MARKER_DISTANCE - 50.0 &&
        distanceToTouchDownPoint(x,y,z) < MIDDLE_MARKER_DISTANCE +50)
        return true;
    else
        return false;
}

bool ilsBeacon::outerMarkerPos(double x, double y, double z)
{
    if(distanceToTouchDownPoint(x,y,z) > outerMarkerDist - 50.0 &&
        distanceToTouchDownPoint(x,y,z) < outerMarkerDist +50)
        return true;
    else
        return false;
}

double ilsBeacon::distanceToTouchDownPoint(double x, double y, double z)
{
    QVector3D jetPos(x, y, z);
    QVector3D touchDownPoint(runWayStartPos.x(), runWayStartPos.y(), 0.0);
    return jetPos.distanceToPoint(touchDownPoint);
}

ilsBeacon::passedMarker ilsBeacon::checkMarker(double x, double y, double z)
{
    if(isAccurateApproach(x,y,z))
    {
        if(innerMarkerPos(x,y,z)) return INNER;
        if(middleMarkerPos(x,y,z)) return MIDDLE;
        if(outerMarkerPos(x,y,z)) return OUTER;
    }
    return NOT_APPROACHED;
}

bool ilsBeacon::isAccurateApproach(double x, double y, double z)
{
    if(abs(distanceToGlissadeProj(x,y)) < ACCEPTABLE_DISTANCE_TO_LOCALIZER &&
        abs(distnaceToGlissadePlane(x,y,z)) < ACCEPTABLE_DISTANCE_TO_GLISSADE)
        return true;
    else
        return false;
}

ilsBeacon::ilsBeacon(QString name_in, QPointF runwaystart_in,
                     QPointF runwayend_in, double glissadeAngle,
                     double outerMarker_in)
    : name{name_in}, runWayStartPos{runwaystart_in}, runWayEndPos{runwayend_in},
    glissadeHorizonLine{makeHorizonLine()},
    approachingZone{makeApproachingZone()},
    glissadePlane{makeGlissadePlane(glissadeAngle)},
    outerMarkerDist{outerMarker_in}
{

}

double ilsBeacon::distanceToGlissadeProj(double x, double y)
{
        QPointF planePos{x, y};
        return dist_point_line(planePos, glissadeHorizonLine);
}

double ilsBeacon::distnaceToGlissadePlane(double x, double y, double z)
{
    QVector3D planePos(x, y, z);
    return planePos.distanceToPlane(glissadePlane[0], glissadePlane[1],
                                    glissadePlane[2]);
}

ilsBeacon* ilsBeacon::inRange(QPointF position)
{
    static ilsBeacon* null = new ilsBeacon;

    if(approachingZone.containsPoint(position, Qt::FillRule::OddEvenFill))
        return this;

    return null;
}

ilsBeacon::ilsBeacon() : name{"none"}, runWayStartPos{}, runWayEndPos{},
    glissadeHorizonLine{}, approachingZone{}, outerMarkerDist{}
{

}

QPolygonF vorBeacon::makeRangeZone()
{
    QPolygonF zone;
    QPointF edge;
    QLineF radian(position, edge);
    radian.setLength(VOR_BEACON_REACH_DISTANCE);
    for(int i = 0; i <= 360; i+=10)
    {
        radian.setAngle(i);
        zone << radian.p2();
    }
    return zone;
}

vorBeacon* vorBeacon::inRange(QPointF position)
{
    static vorBeacon* null = new vorBeacon;
    if(zone.containsPoint(position, Qt::FillRule::OddEvenFill))
        return this;
    return null;
}

double vorBeacon::northCourseToBeacon(double x, double y)
{
    double result;
    QPointF plane_pos(x,y);
    QLineF to_beacon_line (plane_pos, position);
    result = to_beacon_line.angle() - 270;
    if(result < 0.0)
        return 360 + result;
    else
        return result;
}

double vorBeacon::relativeCourseToBeacon(double x, double y,
                              double jetCourse)
{
    double result;
    result = 360 - (jetCourse - northCourseToBeacon(x,y));
    if(result > 360.0)
        return result - 360.0;
    else
        return result;
}

bool vorBeacon::to_from(double x, double y, double course)
{
    if(relativeCourseToBeacon(x,y, course) <= 90.0)
        return true;
    return false;
}

double vorBeacon::distanceToBeacon(double x, double y)
{
    QPointF planePos{x, y};
    QLineF line_to_beacon {planePos, position};
    return line_to_beacon.length();
}

vorBeacon* land_comstations::tryVorCapture(double freq, double x, double y)
{
    static vorBeacon* null = new vorBeacon;
    QPointF position(x, y);
    for(auto &beacon : *vorBeacons)
    {
        if(freq == beacon->getFreq())
        {
            null = beacon->inRange(position);
            if(null->checkName() != "none")
                return null;
        }
    }
    return null;
}

vorBeacon::vorBeacon() : freq{0.-1}, position{}, zone{}, name{"none"},
    beaconCourse{-999.0}
{

}

vorBeacon::vorBeacon(QPointF centralPoint, double freq, QString name) :
    freq{freq}, position{centralPoint}, zone{makeRangeZone()}, name{name}
{

}

double vorBeacon::getFreq()
{
    return freq;
}

QString vorBeacon::checkName()
{
    return name;
}

QString ilsBeacon::checkName()
{
    return name;
}

land_comstations &land_comstations::instance()
{
    static land_comstations singleton;
    return singleton;
}



//bool operator!=(const vorBeacon& beacon1, const vorBeacon& beacon2)
//{
//    if(beacon1.name != beacon2.name)
//        return true;
//    else
//        return false;
//}
//bool operator!=(const ilsLocalizer& localizer1, const ilsLocalizer& localizer2)
//{
//    if(localizer1.name != localizer2.name)
//        return true;
//    else
//        return false;
//}
