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
    _db.setDatabaseName("/Users/Birkir/Desktop/vln1-35/ScienceData.sqlite");
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

//readSci() and readComp() read the database file in different orders, depending on "string com"
vector<Scientist> DataLayer::readSci(string com)
{

    vector<Scientist> tempV;
    QSqlQuery query;
    
    if(com == "alpha")
    {
        query.exec("SELECT * FROM Scientists ORDER BY name");
    }
    else if(com == "ralpha")
    {
        query.exec("SELECT * FROM Scientists ORDER BY name DESC");
    }
    else if(com == "ageasc")
    {
        query.exec("SELECT * FROM Scientists ORDER BY yearOfBirth DESC");
    }
    else if(com == "agedesc")
    {
        query.exec("SELECT * FROM Scientists ORDER BY yearOfBirth");
    }
    else if(com == "deathasc")
    {
        query.exec("SELECT * FROM Scientists ORDER BY yearOfDeath");
    }
    else if(com == "deathdesc")
    {
        query.exec("SELECT * FROM Scientists ORDER BY yearOfDeath DESC");
    }
    
    while (query.next())
    {
        int valid = query.value(5).toInt();
        if(valid == 1)m
        {
            QString name = query.value(1).toString();
            string theName = name.toStdString();
            
            int yearBorn = query.value(2).toInt();
            
            int yearDied = query.value(3).toInt();
            
            QString gender = query.value(4).toString();
            char theGender = gender.at(0).toLatin1();
            
            Scientist newSci(theName, theGender, yearBorn, yearDied);
            tempV.push_back(newSci);
        }
    }
    
    return tempV;
}
    
vector<Computer> DataLayer::readComp(string com)
{
    vector<Computer> tempV;
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
    query.bindValue(":type", QString::fromStdString(cType));
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
