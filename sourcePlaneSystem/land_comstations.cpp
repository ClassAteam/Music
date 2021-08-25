#include "land_comstations.h"

land_comstations::land_comstations()
{


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

ilsLocalizer* land_comstations::tryIlsCapture(double x_position, double y_position)
{
    static ilsLocalizer* null = new ilsLocalizer;
    QPointF position_point(x_position, y_position);
    for(auto &beacon : ilsBeacons)
    {
        if(beacon.getZone().containsPoint(position_point,
                                           Qt::FillRule::OddEvenFill))
        {
            return &beacon;
        }
    }
    return null;
}

bool operator!=(const vorBeacon& beacon1, const vorBeacon& beacon2)
{
    if(beacon1.name != beacon2.name)
        return true;
    else
        return false;
}
bool operator!=(const ilsLocalizer& localizer1, const ilsLocalizer& localizer2)
{
    if(localizer1.name != localizer2.name)
        return true;
    else
        return false;
}

QLineF ilsLocalizer::makeHorizonLine()
{
    double PolarAngle{};
    QLineF runWayLine{runWayStartPos, runWayEndPos};
    PolarAngle = runWayLine.angle();
    QPointF point{};
    QLineF approachLine{runWayEndPos, point};
    approachLine.setAngle(PolarAngle - 180);
    approachLine.setLength(4000);
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

ilsLocalizer::ilsLocalizer(QString name_in, QPointF runwaystart_in,
                           QPointF runwayend_in)
    : name{name_in}, runWayStartPos{runwaystart_in}, runWayEndPos{runwayend_in},
    glissadeHorizonLine{makeHorizonLine()}, approachingZone{makeApproachingZone()}
{

}

QPolygonF ilsLocalizer::getZone()
{
    return approachingZone;
}

ilsLocalizer::ilsLocalizer()
{
    name = "none";
}
