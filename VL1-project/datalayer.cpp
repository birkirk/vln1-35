#include "datalayer.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



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

    /*
    QSqlQuery query1;
    query1.prepare("SELECT COUNT FROM Scientists WHERE name = 'Halldor' AND yearOfBirth = 1295");
    query1.exec();
    QString idName = query1.record().field(1).name();
    cout << idName << endl << endl;

    if(1 > 100)
    {*/
    QSqlQuery query;

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
        qDebug() << "Scientist not successfully added: ";
        //qDebug() << query.lastError();
    }

    return success;

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

bool DataLayer::addComputer(string cName, string cType, bool cIfMade, char cYearMade)
{
    bool success = false;
    QString qName = QString::fromStdString(cName);
    QSqlQuery query;

    query = QSqlQuery(_db);
    query.prepare("INSERT INTO Scientists (name, type, ifMade, yearMade) VALUES(:name, :type, :ifMade, :yearMade);");
    query.bindValue(":name", qName);
    query.bindValue(":type", QString::number(cType));
    query.bindValue(":ifMade", QString::number(cIfMade));
    query.bindValue(":yearMade", QString:: number(cYearMade));
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Computer not successfully added: " << endl;
        //qDebug() << query.lastError();
    }

    return success;
}

vector<Computer> DataLayer::readComp()
{
    vector<Computer> tempV;
    return tempV;
}

