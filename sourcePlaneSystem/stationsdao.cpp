#include "stationsdao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "station.h"
#include "databasemanager.h"

using namespace std;

AirfieldsDao::AirfieldsDao(QSqlDatabase& database) :
    mDatabase(database)
{
}

void AirfieldsDao::init() const
{
    if(!mDatabase.tables().contains("stations"))
    {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE stations (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");
        DatabaseManager::debugQuery(query);
    }
}

void AirfieldsDao::addStation(Airfield& station) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO stations (name) VALUES (:name)");
    query.bindValue(":name", station.name());
    query.exec();
    station.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void AirfieldsDao::updateStation(const Airfield& station)const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE stations SET name = (:name) WHERE id = (:id)");
    query.bindValue(":name", station.name());
    query.bindValue(":id", station.id());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void AirfieldsDao::removeStation(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM stations WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

unique_ptr<vector<unique_ptr<Airfield>>> AirfieldsDao::stations() const
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
