#pragma once

#include <memory>

#include <QString>

class QSqlQuery;
class QSqlDatabase;

const QString DATABASE_FILENAME = "airports.db";

class DatabaseManager
{
public:
    static void debugQuery(const QSqlQuery query);

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

};

#pragma once

#include <memory>
#include <vector>

class QSqlDatabase;
class Airfield;

class AirfieldDao
{
public:
    AirfieldDao(QSqlDatabase& database);
    void init() const;

    void addStation(Airfield& station) const;
    void updateStation(const Airfield& station) const;
    void removeStation(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Airfield>>> stations() const;

private:
    QSqlDatabase& mDatabase;
};

