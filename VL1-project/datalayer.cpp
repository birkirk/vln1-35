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
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
    if (!db.open())
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
    QSqlQuery query;
    query = QSqlQuery(db);
    QString qName = QString::fromStdString(sName);
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


vector<Scientist> DataLayer::readSci() {
    vector<Scientist> tempV;
    return tempV;
}

vector<Computer> DataLayer::readComp() {
    vector<Computer> tempV;
    
    return tempV;
}

void DataLayer::clearFile() {
    
}

