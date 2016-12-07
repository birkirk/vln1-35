#include "datalayer.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;
DataLayer::DataLayer()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("../ScienceData.sqlite");
    _db.open();
}

DataLayer::DataLayer(const QString& path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(path);
    _db.open();
    if (!_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
    
}

bool DataLayer::addScientist(string sName, int sYearOfBirth, int sYearOfDeath, char sGender)
{
    bool success = false;
    QString qName = QString::fromStdString(sName);
    QSqlQuery countQuery;
    countQuery.prepare("SELECT name, yearOfBirth FROM Scientists WHERE name = :name  AND yearOfBirth = :yearOfBirth;");
    countQuery.bindValue(":name", qName);
    countQuery.bindValue(":yearOfBirth", QString::number(sYearOfBirth));
    countQuery.exec();
    qDebug() << countQuery.lastError();

    bool alreadyInDB = countQuery.next();

    QSqlQuery query;
    if(!alreadyInDB)
    {
        cout << "success";
        query = QSqlQuery(_db);
        query.prepare("INSERT INTO Scientists (name, yearOfBirth, yearOfDeath, gender) VALUES(:name, :yearOfBirth, :yearOfDeath, :gender);");
        query.bindValue(":name", qName);
        query.bindValue(":yearOfBirth", QString::number(sYearOfBirth));
        query.bindValue(":yearOfDeath", QString::number(sYearOfDeath));
        query.bindValue(":gender", QString(QChar(sGender)));
        if(query.exec())
        {
            success = true;
        }
        else
        {
            cout << "FAILED";
            qDebug() << "Scientist not successfully added: ";
            //qDebug() << query.lastError();
        }
    }
    return success;
}


bool DataLayer::addScientist(string sName, int sYearOfBirth, char sGender)
{
    bool success = false;

    QString qName = QString::fromStdString(sName);
    QSqlQuery countQuery;
    countQuery.prepare("SELECT name, yearOfBirth FROM Scientists WHERE name = :name and yearOfBirth = :yearOfBirth;");
    countQuery.bindValue(":name", qName);
    countQuery.bindValue(":yearOfBirth", QString::number(sYearOfBirth));
    countQuery.exec();
    countQuery.lastError();
    bool alreadyInDB = countQuery.next();

    QSqlQuery query;
    if(!alreadyInDB)
    {
        cout << "success";
        query = QSqlQuery(_db);
        query.prepare("INSERT INTO Scientists (name, yearOfBirth, gender) VALUES(:name, :yearOfBirth, :gender);");
        query.bindValue(":name", qName);
        query.bindValue(":yearOfBirth", QString::number(sYearOfBirth));
        query.bindValue(":gender", QString(QChar(sGender)));
        if(query.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "Scientist not successfully added: ";
            //qDebug() << query.lastError();
        }
    }
    return success;
}

//bool deleteScientist()
//readSci() and readComp() read the database file
vector<Scientist> DataLayer::readSci() {
    vector<Scientist> tempV;
    vector<string> gg;
    
    QSqlQuery query;
    query.exec("SELECT name FROM Scientists");
    while (query.next()) {
        QString name = query.value(0).toString();
        string bla = name.toStdString();
        gg.push_back(bla);
    }
    for(size_t i = 0; i < gg.size(); i++) {cout << gg[i];}
    
    return tempV;
}

vector<Computer> DataLayer::readComp()
{
    vector<Computer> tempV;
    return tempV;
}

