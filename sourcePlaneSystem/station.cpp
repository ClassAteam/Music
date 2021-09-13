#include "station.h"

Airfield::Airfield(const QString& name) :
    mId(-1),
    mName(name)
{

}

int Airfield::id() const
{
    return mId;
}

void Airfield::setId(int id)
{
    mId = id;
}

QString Airfield::name() const
{
    return mName;
}

void Airfield::setName(const QString& name)
{
    mName = name;
}
