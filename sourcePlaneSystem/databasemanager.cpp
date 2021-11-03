#include "databasemanager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

#include "land_comstations.h"

const auto VORBEACON_SQL = QLatin1String(R"(
    create table vorbeacons(id integer primary key, xpos integer, ypos integer,
                       freq integer, name varchar)
    )");
const auto INSERT_VORBEACON_SQL = QLatin1String(R"(
    insert into vorbeacons(xpos, ypos, freq, name)
                      values(?, ?, ?, ?)
    )");
const auto ILSBEACON_SQL = QLatin1String(R"(
    create table ilsbeacons(id integer primary key, xpos1 integer,
 ypos1 integer, xpos2 integer, ypos2 integer, angle integer, marker integer,
 name varchar)
    )");
const auto INSERT_ILSBEACON_SQL = QLatin1String(R"(
    insert into ilsbeacons(xpos1, ypos1, xpos2, ypos2, angle, marker, name)
                      values(?, ?, ?, ?, ?, ?, ?)
    )");

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

    QStringList tables = mDatabase->tables();
    if (!(tables.contains("testtable", Qt::CaseInsensitive)))
    {
        qDebug() << "Initializing database";
        initDb();
    }
    else
    {
        qDebug() << "Database is loaded";
        initDb();
    }
}

QSqlError DatabaseManager::initDb()
{
    QSqlQuery q(*mDatabase);

    if (!q.exec(VORBEACON_SQL))
        return q.lastError();

    if (!q.prepare(INSERT_VORBEACON_SQL))
        return q.lastError();
    addVorBeacon(q, -2000, 2000, 150, QLatin1String("test_vor_beacon1"));

    if (!q.prepare(INSERT_VORBEACON_SQL))
        return q.lastError();
    addVorBeacon(q, 7000, -7000, 150, QLatin1String("test_vor_beacon2"));

    if (!q.exec(ILSBEACON_SQL))
        return q.lastError();

    if (!q.prepare(INSERT_ILSBEACON_SQL))
        return q.lastError();
    addIlsBeacon(q, 1000, 1000, 1100, 1100, 3, 5000,
                 QLatin1String("test_ils_beacon1"));

    return QSqlError();
}

void DatabaseManager::addVorBeacon(QSqlQuery &q,  int xpos, int ypos, int freq,
                                   QString name)
{
    q.addBindValue(xpos);
    q.addBindValue(ypos);
    q.addBindValue(freq);
    q.addBindValue(name);
    q.exec();
}

void DatabaseManager::addIlsBeacon(QSqlQuery &q, int xpos1, int ypos1,
                                   int xpos2, int ypos2, int angle, int marker,
                                   QString name)
{
    q.addBindValue(xpos1);
    q.addBindValue(ypos1);
    q.addBindValue(xpos2);
    q.addBindValue(ypos2);
    q.addBindValue(angle);
    q.addBindValue(marker);
    q.addBindValue(name);
    q.exec();
}

unique_ptr<vector<unique_ptr<vorBeacon>>> DatabaseManager::getVorBeacons()
{
    QSqlQuery query("SELECT * FROM vorbeacons", *mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<vorBeacon>>> list (new vector<unique_ptr<vorBeacon>>());
    while(query.next())
    {
        QPointF centr(query.value("xpos").toDouble(),
                      query.value("ypos").toDouble());

        unique_ptr<vorBeacon> beacon(new vorBeacon(centr,
                                                   query.value("freq").toDouble(),
                                                   query.value("name").toString()
                                                   ));
        list->push_back(move(beacon));
    }
    return list;
}

std::unique_ptr<std::vector<std::unique_ptr<ilsBeacon>>> DatabaseManager::getIlsBeacons()
{
    QSqlQuery query("SELECT * FROM ilsbeacons", *mDatabase);
    query.exec();
    unique_ptr<vector<unique_ptr<ilsBeacon>>> list (new vector<unique_ptr<ilsBeacon>>());
    while(query.next())
    {
        QPointF start(query.value("xpos1").toDouble(),
                      query.value("ypos1").toDouble());

        QPointF end(query.value("xpos2").toDouble(),
                      query.value("ypos2").toDouble());

        unique_ptr<ilsBeacon> beacon(new ilsBeacon(query.value("name").toString(),
                                                   start, end,
                                                   query.value("angle").toDouble(),
                                                   query.value("marker").toDouble()
                                                   ));
        list->push_back(move(beacon));
    }
    return list;
}

void DatabaseManager::testDatabase_1()
{
    qDebug() << "testing database";
    QSqlQuery query("SELECT * FROM testtable", *mDatabase);
    query.exec();
    while(query.next())
    {
        qDebug() << query.value("id").toString() << ":"
                 << "lon=" << query.value("airfield_lon").toString()
                 << "lat=" << query.value("airfield_lat").toString()
                 << "type=" << query.value("airfield_type").toString()
                 << "last_update=" << query.value("airfield_last_update").toString()
                 << "is_active=" << query.value("airfield_active").toString()
                 << "is_verified=" << query.value("airfield_verified").toString()
                 << "is_international=" << query.value("airfield_international").toString()
                 << "name=" << query.value("airfield_name").toString()
                 << "nameru=" << query.value("airfield_name_ru").toString()
                 << "city=" << query.value("airfield_city").toString()
                 << "belongs=" << query.value("airfield_belongs").toString()
                 << "height=" << query.value("airfield_height").toString()
                 << "deltam=" << query.value("airfield_delta_m").toString()
                 << "internal_id=" << query.value("internal_id").toString();
    }
}

void DatabaseManager::testDatabase_2()
{
    QSqlQuery query("SELECT * FROM vorbeacons", *mDatabase);
    query.exec();
    while(query.next())
    {
        qDebug() << query.value("xpos").toString() << "==";
    }
}
void DatabaseManager::debugQuery(const QSqlQuery query)
{
    if (query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK:"  << query.lastQuery();
    } else {
        qWarning() << "Query KO:" << query.lastError().text();
        qWarning() << "Query text:" << query.lastQuery();
    }
}

DatabaseManager::~DatabaseManager()
{
    mDatabase->close();
}
