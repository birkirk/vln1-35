#include "datalayer.h"
#include "scientist.h"
#include "computer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

QSqlQuery findScientists(Scientist sci)
{

    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT ID FROM Scientists"
                        " WHERE name LIKE '%'||:name||'%' AND yearOfBirth LIKE '%'||:yearOfBirth||'%' AND gender LIKE '%'||:gender||'%'");
    searchQuery.bindValue(":name", QString::fromStdString(sci.getName()));
    searchQuery.bindValue(":yearOfBirth", QString::number(sci.getBirth()));
    searchQuery.bindValue(":yearOfDeath", QString::number(sci.getDeath()));
    searchQuery.bindValue(":gender", QString(QChar(sci.getGender())));
    searchQuery.exec();
    searchQuery.first();

    return searchQuery;

}

QSqlQuery findComputers(Computer comp)
{
    QSqlQuery query;
    query.prepare("SELECT ID FROM Computers WHERE name LIKE '%'||:name||'%' AND type LIKE '%'||:type||'%' AND ifMade LIKE '%'||:ifMade||'%' AND yearMade LIKE '%'||:yearMade||'%' AND valid = 1");
    query.bindValue(":name", QString::fromStdString(comp.getName()));
    query.bindValue(":type", QString::fromStdString(comp.getType()));
    query.bindValue(":ifMade", comp.getIfMade());
    query.bindValue(":yearMade", QString::number(comp.getYearMade()));
    query.exec();
    query.first();

    return query;
}

DataLayer::DataLayer()
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    if(QFile::exists(QString::fromStdString("../ScienceData.sqlite")))
    {
        _db.setDatabaseName("../ScienceData.sqlite");
        _db.open();
    }
    else
    {
        _db.setDatabaseName("../ScienceData.sqlite");
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

        createQuery.prepare("CREATE TABLE scicomp('scientistID' INTEGER ,"
                            "'computerID' INTEGER, "
                            "'valid' BOOL NOT NULL  DEFAULT 1,"
                            " FOREIGN KEY(scientistID) REFERENCES Scientists(ID) ON DELETE CASCADE,"
                            " FOREIGN KEY(computerID) REFERENCES Computers(ID) ON DELETE CASCADE)");
        createQuery.exec();
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

bool DataLayer::closeDatabase()
{
    bool gotClosed = false;
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName("../ScienceData.sqlite");
    if(_db.open())
    {
        _db.close();
        gotClosed = true;
    }
    return gotClosed;
}

bool DataLayer::addScientist(Scientist sci)
{

    bool success = false;

    QSqlQuery countQuery = findScientists(sci);
    bool alreadyInDB = countQuery.next();

    QSqlQuery query;
    if(!alreadyInDB)
    {
        query = QSqlQuery(_db);
        query.prepare("INSERT INTO Scientists (name, yearOfBirth, yearOfDeath, gender) VALUES(:name, :yearOfBirth, :yearOfDeath, :gender);");
        query.bindValue(":name", QString::fromStdString((sci.getName())));
        query.bindValue(":yearOfBirth", QString::number(sci.getBirth()));
        query.bindValue(":yearOfDeath", QString::number(sci.getDeath()));
        query.bindValue(":gender", QString(QChar(sci.getGender())));
        if(query.exec())
        {
            success = true;
        }
    }
    return success;
}

/*
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
*/

bool DataLayer::deleteComputer(Computer newComp)
{
    QSqlQuery query = findComputers(newComp);

    query.first();
    QSqlQuery deleteQuery;
    deleteQuery.prepare("UPDATE Computers SET valid = 0 WHERE ID = (:ID)");
    int a = query.value(0).toInt();
    deleteQuery.bindValue(":ID", a);
    qDebug() << deleteQuery.exec();
    bool returnValue = deleteQuery.exec();
    return returnValue;
}


bool DataLayer::deleteScientist(Scientist newSci)
{
    QSqlQuery query = findScientists(newSci);

    query.first();
    QSqlQuery deleteQuery;
    deleteQuery.prepare("UPDATE Scientists SET valid = 0 WHERE ID = (:ID)");
    int a = query.value(0).toInt();
    deleteQuery.bindValue(":ID", a);
    qDebug() << deleteQuery.exec();
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

vector<int> DataLayer::getCon()
{
    vector<int> connected;
    QSqlQuery query;

    query.exec("SELECT * FROM scicomp");

    while (query.next())
    {
        int valid = query.value(2).toInt();
        if(valid == 1)
        {
            int sciID = query.value(0).toInt();
            int compID = query.value(1).toInt();
            connected.push_back(sciID);
            connected.push_back(compID);
        }
    }
    return connected;
}

bool DataLayer::addComputer(Computer comp)
{
    bool success = false;
    QSqlQuery query;

    query = QSqlQuery(_db);
    query.prepare("INSERT INTO Computers (name, type, ifMade, yearMade) VALUES(:name, :type, :ifMade, :yearMade);");
    query.bindValue(":name", QString::fromStdString(comp.getName()));
    query.bindValue(":type", QString::fromStdString(comp.getType()));
    query.bindValue(":ifMade", QString::number(comp.getIfMade()));
    query.bindValue(":yearMade", QString:: number(comp.getYearMade()));
    if(query.exec())
    {
        success = true;
    }
    return success;
}

vector<Scientist> DataLayer::searchSci(string sName, char sGender, string sYearOfBirth, string sYearOfDeath)
{
    QString qName = QString::fromStdString(sName);
    QSqlQuery searchQuery;
    if(sGender == 'O')
    {
        searchQuery.prepare("SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists"
                            " WHERE name LIKE '%'||:name||'%' AND yearOfBirth LIKE '%'||:yearOfBirth||'%'"
                            " AND yearOfDeath LIKE '%'||:yearOfDeath||'%' AND valid = 1"
                            " ORDER BY name");
    }
    else
    {
        searchQuery.prepare("SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists"
                            " WHERE name LIKE '%'||:name||'%' AND yearOfBirth LIKE '%'||:yearOfBirth||'%' AND yearOfDeath LIKE '%'||:yearOfDeath||'%'"
                            " AND gender LIKE '%'||:gender||'%'"
                            " ORDER BY name");
        searchQuery.bindValue(":gender", QString(QChar(sGender)));
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

//bool string string int
vector<Computer> DataLayer::searchComp(string ifMade, string name, string type, string yearMade)
{


    QSqlQuery searchQuery;


    if(yearMade.size() != 0)
    {
        searchQuery.prepare("SELECT ifMade, name, type, yearMade"
                            " FROM Computers WHERE name LIKE '%'||:name||'%'"
                            " AND ifMade LIKE '%'||:ifMade||'%'"
                            " AND type LIKE '%'||:type||'%')"
                            " AND yearMade LIKE '%'||:yearMade||'%'");

        int qYear = atoi(yearMade.c_str());
        searchQuery.bindValue(":yearMade", QString::number(qYear));
    }
    else
    {
        searchQuery.prepare("SELECT ifMade, name, type, yearMade"
                            " FROM Computers WHERE name LIKE '%'||:name||'%'"
                            " AND ifMade LIKE '%'||:ifMade||'%'"
                            " AND type LIKE '%'||:type||'%' AND valid = 1");
    }
    if(ifMade.size() != 0)
    {
        int tIfMade = atoi(ifMade.c_str());
        searchQuery.bindValue(":ifMade", QString::number(tIfMade));
    }
    else
    {
        searchQuery.bindValue(":ifMade", QString::fromStdString(ifMade));
    }

    searchQuery.bindValue(":name", QString::fromStdString(name));
    searchQuery.bindValue(":type", QString::fromStdString(type));
    searchQuery.exec();


    vector<Computer> returnVector;
    qDebug() << searchQuery.next();
    while(searchQuery.next())
    {

        QString qName = searchQuery.value(1).toString();
        string nName = qName.toStdString();

        QString qIfMade = searchQuery.value(0).toString();
        bool nIfMade;
        if(qIfMade == "1") nIfMade = true;
        else nIfMade = false;

        QString qType = searchQuery.value(2).toString();
        string nType = qType.toStdString();

        int nYearMade = searchQuery.value(3).toInt();

        Computer newComp(nIfMade, nName, nType, nYearMade);
        returnVector.push_back(newComp);

        //returnVector.push_back(newPomc);
    }

    return returnVector;
}

void DataLayer::clearDataFile()
{
    QSqlQuery query;
    query.exec("DELETE FROM Scientists");
    query.exec("DELETE FROM Computers");
    query.exec("DELETE FROM scicomp");
}

void DataLayer::clearSci()
{
    QSqlQuery query;
    query.exec("DELETE FROM Scientists");
    query.exec("DELETE FROM scicomp");
}

void DataLayer::clearComp()
{
    QSqlQuery query;
    query.exec("DELETE FROM Computers");
    query.exec("DELETE FROM scicomp");
}

void DataLayer::clearCon()
{
    QSqlQuery query;
    query.exec("DELETE FROM scicomp");
}

void DataLayer::connect(Scientist newSci, Computer newComp)
{
    QSqlQuery sciQuery = findScientists(newSci);
    QSqlQuery compQuery = findComputers(newComp);

    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT INTO scicomp scientistID, computerID, valid"
                        " VALUES(:scientistID, :computerID :valid)");

    updateQuery.bindValue(":scientistID", sciQuery.value(0));
    updateQuery.bindValue(":computerID", compQuery.value(0));
    updateQuery.exec();
}

vector<int> DataLayer::findConnectedComp(int i)
{
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT ID FROM scicomp WHERE computerID = (:ID) AND valid = 1");
    searchQuery.bindValue(":ID", QString::number(i));
    searchQuery.exec();
    vector<int> returnVector;
    while(searchQuery.next())
    {
        returnVector.push_back(searchQuery.value(0).toInt());
    }
    return returnVector;
}

vector<int> DataLayer::findConnectedSci(int i)
{
    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT ID FROM scicomp WHERE scientistID = (:ID) AND valid = 1");
    searchQuery.bindValue(":ID", QString::number(i));
    searchQuery.exec();
    vector<int> returnVector;
    while(searchQuery.next())
    {
        returnVector.push_back(searchQuery.value(0).toInt());
    }
    return returnVector;
}



