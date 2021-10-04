#pragma once

#include <memory>
#include <vector>

#include <QString>

class QSqlQuery;
class QSqlDatabase;
class vorBeacon;
class ilsBeacon;
class QSqlError;

const QString DATABASE_FILENAME = "airports.db";
//const QString DATABASE_FILENAME = "airports_2.db";

class DatabaseManager
{
public:
    std::unique_ptr<std::vector<std::unique_ptr<vorBeacon>>> getVorBeacons();
    std::unique_ptr<std::vector<std::unique_ptr<ilsBeacon>>> getIlsBeacons();
    void testDatabase_1();
    void testDatabase_2();

    static DatabaseManager& instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;
    QSqlError initDb();
    void addVorBeacon(QSqlQuery &q,  int xpos, int ypos, int freq, QString name);
    void addIlsBeacon(QSqlQuery &q,  int xpos1, int ypos1, int xpos2, int ypos2,
                      int angle, int marker, QString name);

};

