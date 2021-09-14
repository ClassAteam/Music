#include "airfielddao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "station.h"
#include "databasemanager.h"

using namespace std;

AirfieldDao::AirfieldDao(QSqlDatabase& database) :
    mDatabase(database)
{
    Airfield test_airfield("test_airfield");
    addStation(test_airfield);
}

void AirfieldDao::init() const
{
    if(!mDatabase.tables().contains("stations"))
    {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE stations (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void AirfieldDao::addStation(Airfield& station) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO stations (name) VALUES (:name)");
    query.bindValue(":name", station.name());
    query.exec();
    station.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void AirfieldDao::updateStation(const Airfield& station)const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE stations SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", station.name());
    query.bindValue(":id", station.id());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AirfieldDao::removeStation(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM stations WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

//should be specific pointer (e.g landcomstations::vorBeacon) and method
//should be named accordingly
unique_ptr<vector<unique_ptr<Airfield>>> AirfieldDao::stations() const
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
