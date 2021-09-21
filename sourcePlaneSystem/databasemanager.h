#pragma once

#include <memory>

#include <QString>

class QSqlQuery;
class QSqlDatabase;
class vorBeacon;

const QString DATABASE_FILENAME = "airports.db";

class DatabaseManager
{
public:
    QVector<vorBeacon> getVorBeacons();

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

};
