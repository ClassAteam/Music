#pragma once

#include <QString>

class Airfield
{
public:
    Airfield(const QString& name = "");

    int id() const;
    void setId(int id);
    QString name() const;
    void setName(const QString& name);

private:
    int mId;
    QString mName;
};

