#pragma once

#include <memory>

#include <QString>

#include "airfielddao.h"

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

public:
    const AirfieldDao stationsDao;
};

