#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

using namespace std;

void DatabaseManager::debugQuery(const QSqlQuery query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK:"  << query.lastQuery();
    } else {
       qWarning() << "Query KO:" << query.lastError().text();
       qWarning() << "Query text:" << query.lastQuery();
    }
}

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


//should be specific pointer (e.g landcomstations::vorBeacon) and method
//should be named accordingly
unique_ptr<vector<unique_ptr<vorBeacon>>> AirfieldDao::stations() const
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
