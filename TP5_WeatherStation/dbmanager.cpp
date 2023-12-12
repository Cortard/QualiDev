#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

void DbManager::verifyCityName(QString* city){
    for(int i=0;i<city->size();++i){
        if(city->at(i)==' ') (*city)[i]='_';
        else if(city->at(i)=='-') (*city)[i]='_';
    }
}

DbManager::DbManager(const QString &path)
{
    sqldb = QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName(path);

    if (!sqldb.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

DbManager::~DbManager()
{
    if (sqldb.isOpen())
    {
        sqldb.close();
    }
}

bool DbManager::isOpen() const
{
    return sqldb.isOpen();
}

bool DbManager::createTable(QString city)
{
    bool success = false;
    verifyCityName(&city);

    QSqlQuery query;
    query.prepare("CREATE TABLE pollution_"+city+" (id INTEGER PRIMARY KEY, dt INTEGER, aqi INTEGER);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'pollution_"+city+"' : one might already exist.";
        success = false;
    }

    return success;
}

bool DbManager::addData(int dt, int aqi, QString city)
{
    bool success = false;
    verifyCityName(&city);

    QSqlQuery queryAdd;
    queryAdd.prepare("INSERT INTO pollution_"+city+" (dt,aqi) VALUES (:dt,:aqi)");
    queryAdd.bindValue(":dt", dt);
    queryAdd.bindValue(":aqi", aqi);

    if(queryAdd.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add dt/aqi failed: " << queryAdd.lastError();
    }

    return success;
}

bool DbManager::removeData(int dt, QString city)
{
    bool success = false;
    verifyCityName(&city);

    if (entryExists(dt, city))
    {
        QSqlQuery queryDelete;
        queryDelete.prepare("DELETE FROM pollution_"+city+" WHERE dt = (:dt)");
        queryDelete.bindValue(":dt", dt);
        success = queryDelete.exec();

        if(!success)
        {
            qDebug() << "remove data failed: " << queryDelete.lastError();
        }
    }
    else
    {
        qDebug() << "remove data failed: dt doesnt exist";
    }

    return success;
}

void DbManager::printAllData(QString city)
{
    verifyCityName(&city);

    qDebug() << "Data in db:";
    QSqlQuery query("SELECT * FROM pollution_"+city+"");
    int idDt = query.record().indexOf("dt");
    int idAqi = query.record().indexOf("aqi");
    while (query.next())
    {
        int dt = query.value(idDt).toInt();
        int aqi = query.value(idAqi).toInt();
        qDebug() << "===" << dt << " " << aqi;
    }
}

bool DbManager::entryExists(int dt, QString city)
{
    verifyCityName(&city);
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT dt FROM pollution_"+city+" WHERE dt = (:dt)");
    checkQuery.bindValue(":dt", dt);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "data exists failed: " << checkQuery.lastError();
    }

    return exists;
}

QList<int*>* DbManager::getAllData(QString city)
{
    verifyCityName(&city);
    QList<int*>* res=new QList<int*>();
    QSqlQuery query("SELECT * FROM pollution_"+city+"");
    int idDt = query.record().indexOf("dt");
    int idAqi = query.record().indexOf("aqi");
    while (query.next())
    {
        int dt = query.value(idDt).toInt();
        int aqi = query.value(idAqi).toInt();
        res->append(new int[2]{dt,aqi});
    }

    return res;
}

bool DbManager::removeAllData(QString city)
{
    verifyCityName(&city);
    bool success = false;

    QSqlQuery removeQuery;
    removeQuery.prepare("DELETE FROM pollution_"+city+"");

    if (removeQuery.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "remove all data failed: " << removeQuery.lastError();
    }

    return success;
}
