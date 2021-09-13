#pragma once

#include <memory>
#include <vector>

class QSqlDatabase;
class Airfield;

class AirfieldsDao
{
public:
    AirfieldsDao(QSqlDatabase& database);
    void init() const;

    void addStation(Airfield& station) const;
    void updateStation(const Airfield& station) const;
    void removeStation(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Airfield>>> stations() const;

private:
    QSqlDatabase& mDatabase;
};

