#include "datalayer.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

QSqlQuery findScientists(string sName, int sYearOfBirth, int sYearOfDeath, char sGender)
{

    QString qName = QString::fromStdString(sName);
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT ID FROM Scientist"
                        " WHERE name LIKE '%'||:name||'%' AND yearOfBirth LIKE '%'||:yearOfBirth||'%' AND gender LIKE '%'||:gender||'%'"
                        " ORDER BY name");
    searchQuery.bindValue(":name", qName);
    searchQuery.bindValue(":yearOfBirth", QString::number(sYearOfBirth));
    searchQuery.bindValue(":yearOfDeath", QString::number(sYearOfDeath));
    searchQuery.bindValue(":gender", QString(QChar(sGender)));
    searchQuery.exec();
    return searchQuery;

}

DataLayer::DataLayer()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    if(QFile::exists(QString::fromStdString("../ScienceDataTEST.sqlite")))
    {
        _db.setDatabaseName("../ScienceDataTEST.sqlite");
        _db.open();
        cout << "Database found..." << endl;
    }
    else
    {
        _db.setDatabaseName("../ScienceDataTEST.sqlite");
        _db.open();
        QSqlQuery createQuery;

        createQuery.prepare("CREATE TABLE 'Computers' "
                            "('ID' INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE ,"
                            " 'name' VARCHAR NOT NULL ,"
                            " 'type' VARCHAR NOT NULL ,"
                            " 'ifMade' BOOL NOT NULL ,"
                            " 'yearMade' INTEGER, 'valid' BOOL NOT NULL  DEFAULT 1)");
        createQuery.exec();

        createQuery.prepare("CREATE TABLE 'Scientists' "
                            "('ID' INTEGER PRIMARY KEY  NOT NULL ,"
                            "'name' VARCHAR NOT NULL ,"
                            "'yearOfBirth' VARCHAR,"
                            "'yearOfDeath' VARCHAR,"
                            " 'gender' CHAR NOT NULL  DEFAULT N,"
                            " 'valid' DOUBLE NOT NULL  DEFAULT 1)");
        createQuery.exec();

        createQuery.prepare("CREATE TABLE scicomp(scientistID INTEGER ,"
                            "computerID INTEGER, "
                            "'valid' BOOL NOT NULL  DEFAULT 1,"
                            " FOREIGN KEY(scientistID) REFERENCES Scientists(ID) ON DELETE CASCADE,"
                            " FOREIGN KEY(computerID) REFERENCES Computers(ID) ON DELETE CASCADE)");
        cout << "Database not found... Creating database... " << endl;
    }
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
    /*
    QString qName = QString::fromStdString(sName);
    QSqlQuery countQuery;
    countQuery.prepare("SELECT name, yearOfBirth FROM Scientists WHERE name = :name  AND yearOfBirth = :yearOfBirth;");
    countQuery.bindValue(":name", qName);
    countQuery.bindValue(":yearOfBirth", QString::number(sYearOfBirth));
    countQuery.exec();
    qDebug() << countQuery.lastError();

    bool alreadyInDB = countQuery.next();
    */
    QSqlQuery countQuery = findScientists(sName, sYearOfBirth, sYearOfDeath, sGender);
    bool alreadyInDB = countQuery.next();

    QSqlQuery query;
    if(!alreadyInDB)
    {
        cout << "success";
        query = QSqlQuery(_db);
        query.prepare("INSERT INTO Scientists (name, yearOfBirth, yearOfDeath, gender) VALUES(:name, :yearOfBirth, :yearOfDeath, :gender);");
        query.bindValue(":name", QString::fromStdString((sName)));
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


bool DataLayer::deleteScientist(Scientist newSci)
{
    QSqlQuery query = findScientists(newSci.getName(), newSci.getBirth(), newSci.getDeath(), newSci.getGender());

    query.first();
    QSqlQuery deleteQuery;
    deleteQuery.prepare("UPDATE Scientists SET valid = 0 WHERE ID = (:ID)");
    int a = query.value(0).toInt();
    deleteQuery.bindValue(":ID", a);
    bool returnValue = deleteQuery.exec();
    return returnValue;
}

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
        if(valid == 1)
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
    QSqlQuery query;
    
    if(com == "alpha")
    {
        query.exec("SELECT * FROM Computers ORDER BY name");
    }
    else if(com == "ralpha")
    {
        query.exec("SELECT * FROM Computers ORDER BY name DESC");
    }
    else if(com == "ageasc")
    {
        query.exec("SELECT * FROM Computers ORDER BY yearMade DESC");
    }
    else if(com == "agedesc")
    {
        query.exec("SELECT * FROM Computers ORDER BY yearMade");
    }
    else if(com == "made")
    {
        query.exec("SELECT FROM Computers WHERE ifMade = 1");
    }
    else if(com == "notmade")
    {
        query.exec("SELECT FROM Computers WHERE ifMade = 0");
    }
    else if(com == "type")
    {
        query.exec("SELECT FROM Computers ORDER BY type");
    }
    
    while (query.next())
    {
        int valid = query.value(5).toInt();
        if(valid == 1)
        {
            QString name = query.value(1).toString();
            string theName = name.toStdString();
            
            QString type = query.value(2).toString();
            string theType = type.toStdString();
            
            int made = query.value(3).toInt();
            bool ifMade;
            if(made == 1)
            {
                ifMade = true;
            }
            else
            {
                ifMade = false;
            }
            
            int yearMade = query.value(4).toInt();
            
            Computer newComp(ifMade, theName, theType, yearMade);
            tempV.push_back(newComp);
        }
    }
    
    return tempV;
}

bool DataLayer::addComputer(string cName, string cType, bool cIfMade, char cYearMade)
{
    bool success = false;
    QString qName = QString::fromStdString(cName);
    QSqlQuery query;

    query = QSqlQuery(_db);
    query.prepare("INSERT INTO Computers (name, type, ifMade, yearMade) VALUES(:name, :type, :ifMade, :yearMade);");
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

vector<Scientist> DataLayer::searchSci(string sName, char sGender, string sYearOfBirth, string sYearOfDeath)
{
    QString qName = QString::fromStdString(sName);
    //QSqlQuery searchQuery = findScientists(sName, sYearOfBirth, sYearOfDeath, sGender);
    QSqlQuery searchQuery;
    if(sGender == 'O')
    {
        searchQuery.prepare("SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists"
                            " WHERE name LIKE '%'||:name||'%' AND yearOfBirth LIKE '%'||:yearOfBirth||'%'"
                            " AND yearOfDeath LIKE '%'||:yearOfDeath||'%'"
                            " ORDER BY name");
    }
    else
    {
        searchQuery.prepare("SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists"
                            " WHERE name LIKE '%'||:name||'%' AND yearOfBirth LIKE '%'||:yearOfBirth||'%' AND yearOfDeath LIKE '%'||:yearOfDeath||'%'"
                            " AND gender LIKE '%'||:gender||'%'"
                            " ORDER BY name");
        searchQuery.bindValue(":gender", QString(QChar(sGender)));
        cout << "Got to gender" << endl;
    }

    if(sYearOfBirth.size() != 0)
    {
        int birth = atoi(sYearOfBirth.c_str());
        searchQuery.bindValue(":yearOfBirth", QString::number(birth));
    }
    else
    {
        string birth = sYearOfBirth;
        searchQuery.bindValue(":yearOfBirth", QString::fromStdString(birth));
    }
    if(sYearOfDeath.size() != 0)
    {
         int death = atoi(sYearOfDeath.c_str());
         searchQuery.bindValue(":yearOfDeath", QString::number(death));
    }
    else
    {
        string death = sYearOfDeath;
        searchQuery.bindValue(":yearOfDeath", QString::fromStdString(death));
    }
    searchQuery.bindValue(":name", qName);
    searchQuery.exec();



    vector<Scientist> returnVector;

    while(searchQuery.next())
    {
        QString gender = searchQuery.value(1).toString();
        char gChar = gender.at(0).toLatin1();

        QString qName = searchQuery.value(0).toString();
        string name = qName.toStdString();
        Scientist newSci(name, gChar, searchQuery.value(2).toInt(), searchQuery.value(3).toInt());
        returnVector.push_back(newSci);
    }

    return returnVector;
}
/*
void connect(Scientist newSci, Computer newCmp)
{
    QSqlQuery query = findScientsist();
    query.prepare()
}*/


