#include "datalayer.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



using namespace std;
DataLayer::DataLayer()
{

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
}

//Reads the database file
vector<Scientist> DataLayer::readSci() {
    vector<Scientist> tempV;
    return tempV;
}

vector<Computer> DataLayer::readComp()
{
    vector<Computer> tempV;
    return tempV;
}

