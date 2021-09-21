#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

#include "land_comstations.h"

using namespace std;

DatabaseManager&DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::DatabaseManager(const QString& path) :
    mDatabase(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")))
{
    mDatabase->setDatabaseName(path);

    bool openStatus = mDatabase->open();
    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
}

QVector<vorBeacon> DatabaseManager::getVorBeacons()
{
    QSqlQuery query("SELECT * FROM stations", *mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<vorBeacon>>> list (new vector<unique_ptr<vorBeacon>>());
    while(query.next())
    {
        unique_ptr<vorBeacon> beacon(new vorBeacon);
        beacon->setName(query.value("vorbeacon_name").toString());

    }

}

//should be specific pointer (e.g landcomstations::vorBeacon) and method
//should be named accordingly
vorBeacon DatabaseManager::stations() const
{
    QSqlQuery query("SELECT * FROM stations", mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<Airfield>>> list(new vector<unique_ptr<Airfield>>());
    while(query.next()) {
        unique_ptr<Airfield> station(new Airfield());
        station->setId(query.value("id").toInt());
        station->setName(query.value("name").toString());
        list->push_back(move(station));
    }
    return list;
}

vorBeacon AirfieldDao::stations()
{

}
