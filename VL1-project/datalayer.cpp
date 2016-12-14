#include "datalayer.h"
#include "scientist.h"
#include "computer.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include <cstdlib>
#include <sstream>
using namespace std;

QSqlQuery findScientists(Scientist sci)
{

    QSqlQuery searchQuery;
    searchQuery.prepare("SELECT ID FROM Scientists"
                        " WHERE name LIKE '%'||:name||'%' "
                        "AND yearOfBirth LIKE '%'||:yearOfBirth||'%' "
                        "AND gender LIKE '%'||:gender||'%'");
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
    query.prepare("SELECT ID FROM Computers"
                  " WHERE name LIKE '%'||:name||'%' "
                  "AND type LIKE '%'||:type||'%' "
                  "AND ifMade LIKE '%'||:ifMade||'%' "
                  "AND yearMade LIKE '%'||:yearMade||'%'");
    query.bindValue(":name", QString::fromStdString(comp.getName()));
    query.bindValue(":type", QString::fromStdString(comp.getType()));
    query.bindValue(":ifMade", QString::number(comp.getIfMade()));
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
                            " 'picture' BLOB, "
                            " 'valid' DOUBLE NOT NULL  DEFAULT 1)");
        createQuery.exec();

        createQuery.prepare("CREATE TABLE scicomp('scientistID' INTEGER ,"
                            "'computerID' INTEGER, "
                            "'valid' BOOL NOT NULL  DEFAULT 1,"
                            " FOREIGN KEY(scientistID) REFERENCES Scientists(ID) ON DELETE CASCADE,"
                            " FOREIGN KEY(computerID) REFERENCES Computers(ID) ON DELETE CASCADE)");
        createQuery.exec();

        createQuery.prepare("CREATE TABLE 'types' "
                            "('ID' INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE ,"
                            " 'type' VARCHAR NOT NULL)");
        createQuery.exec();
        QSqlQuery insert;
        insert.prepare("INSERT INTO types (type) VALUES(:type) ");
        insert.bindValue(":type", QString::fromStdString("Mechanical"));
        qDebug() << insert.exec();
        insert.bindValue(":type", QString::fromStdString("Electronic"));
        insert.exec();
        insert.bindValue(":type", QString::fromStdString("Transistor Machine"));
        insert.exec();
        insert.bindValue(":type", QString::fromStdString("Mainframe Computer"));
        insert.exec();
        insert.bindValue(":type", QString::fromStdString("Personal computer 'PC'"));
        insert.exec();
        insert.bindValue(":type", QString::fromStdString("Laptop"));
        insert.exec();
        insert.bindValue(":type", QString::fromStdString("Calculator"));
        insert.exec();


    }
}

DataLayer::DataLayer(const QString& path)
{
    _db = QSqlDatabase::addDatabase("QSQLITE");
    _db.setDatabaseName(path);
    _db.open();

}

bool DataLayer::closeDatabase()
{
    bool gotClosed = false;
    if(_db.isOpen())
    {
        _db.close();
        gotClosed = true;
    }
    return gotClosed;
}

vector<Scientist> DataLayer::getDeletedSci()
{
    QSqlQuery query;
    query.prepare("SELECT name, yearOfBirth, yearOfDeath, gender FROM Scientists WHERE valid = 0");
    query.exec();

    vector<Scientist> returnVector;
    while(query.next())
    {
        QString qName = query.value(0).toString();
        string name = qName.toStdString();

        QString qGender = query.value(3).toString();
        string sGender = qGender.toStdString();
        char gender = sGender.at(0);
        Scientist newSci(name, gender, query.value(1).toInt(), query.value(2).toInt());

        returnVector.push_back(newSci);

    }
    return returnVector;
}

vector<Computer> DataLayer::getDeletedComp()
{
    QSqlQuery query;
    query.prepare("SELECT name, type, ifMade, yearMade FROM Computers WHERE valid = 0");
    query.exec();

    vector<Computer> returnVector;
    while(query.next())
    {
        QString qName = query.value(0).toString();
        string name = qName.toStdString();

        QString qType = query.value(1).toString();
        string type = qType.toStdString();

        Computer newComp(query.value(2).toInt(), name, type, query.value(3).toInt());

        returnVector.push_back(newComp);

    }
    return returnVector;
}

bool DataLayer::recycleSci(Scientist sci)
{
    bool returnValue = false;
    QSqlQuery sciQuery = findScientists(sci);
    
    QSqlQuery query;
    query.prepare("UPDATE Scientists SET valid = 1 WHERE id = (:ID)");
    query.bindValue(":ID", sciQuery.value(0).toInt());
    returnValue = query.exec();

    return returnValue;
}

bool DataLayer::recycleComp(Computer comp)
{
    bool returnValue = false;
    QSqlQuery compQuery = findComputers(comp);

    QSqlQuery query;
    query.prepare("UPDATE Computers SET valid = 1 WHERE id = (:ID)");
    query.bindValue(":ID", compQuery.value(0).toInt());
    returnValue = query.exec();

    return returnValue;
}

void DataLayer::addType(string type)
{
    QSqlQuery query;
    query.prepare("INSERT INTO types (type) VALUES(:type)");
    query.bindValue(":type", QString::fromStdString(type));
    query.exec();
}

vector<string> DataLayer::getTypes()
{
    QSqlQuery query;
    query.exec("SELECT type FROM types");
    vector<string> returnVector;
    while(query.next())
    {
        QString qType = query.value(0).toString();
        string type = qType.toStdString();
        returnVector.push_back(type);
    }
    return returnVector;
}

bool DataLayer::addScientist(Scientist sci)
{

    bool success = false;

    QSqlQuery countQuery = findScientists(sci);
    bool alreadyInDB = countQuery.isValid();

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

bool DataLayer::addComputer(Computer comp)
{
    bool success = false;
    
    QSqlQuery countQuery = findComputers(comp);
    bool alreadyInDB = countQuery.isValid();
    
    QSqlQuery query;
    if(!alreadyInDB)
    {
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
    }
    return success;
}

bool DataLayer::addComputerPicture(Computer comp, QByteArray pict)
{
    QSqlQuery compQuery = findComputers(comp);
    QSqlQuery query;
    query.prepare("UPDATE Computers SET picture = (:picture) WHERE ID = (:ID)");
    query.bindValue(":ID", compQuery.value(0).toInt());
    query.bindValue(":picture", pict);
    bool returnValue = query.exec();

    return returnValue;
}

bool DataLayer::deleteComputer(Computer newComp)
{
    QSqlQuery query = findComputers(newComp);

    query.first();
    QSqlQuery deleteQuery;
    deleteQuery.prepare("UPDATE Computers SET valid = 0 WHERE ID = (:ID)");
    int a = query.value(0).toInt();
    deleteQuery.bindValue(":ID", a);
    deleteQuery.exec();
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
    deleteQuery.exec();
    bool returnValue = deleteQuery.exec();
    return returnValue;
}

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
    else if(com == "non")
    {
        query.exec("SELECT * FROM Scientists");
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
        query.exec("SELECT * FROM Computers WHERE ifMade = 1");
    }
    else if(com == "notmade")
    {
        query.exec("SELECT * FROM Computers WHERE ifMade = 0");
    }
    else if(com == "type")
    {
        query.exec("SELECT * FROM Computers ORDER BY type");
    }
    else if(com == "non")
    {
        query.exec("SELECT * FROM Computers");
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

vector<Scientist> DataLayer::searchSci(string input)
{
    stringstream sqlQuery;
        sqlQuery << "SELECT * FROM Scientists WHERE name LIKE '%" << input << "%"
                 << "' UNION "
                 << "SELECT * FROM Scientists WHERE yearOfBirth LIKE '%" << input << "%"
                 << "' UNION "
                 << "SELECT * FROM Scientists WHERE yearOfDeath LIKE '%" << input << "%'";

    QString sqlQ = QString::fromStdString(sqlQuery.str());
    vector<Scientist> scientists;

    if (!_db.isOpen())
    {
        return scientists;
    }

    QSqlQuery query(_db);

    if (!query.exec(sqlQ))
    {
        return scientists;
    }

    while (query.next())
    {
        int valid = query.value(5).toInt();
        if(valid == 1)
        {
            QString gender = query.value(4).toString();
            char gChar = gender.at(0).toLatin1();

            QString qName = query.value(1).toString();
            string name = qName.toStdString();
            Scientist newSci(name, gChar, query.value(2).toInt(), query.value(3).toInt());
            scientists.push_back(newSci);
        }
    }

    return scientists;
}

vector<Computer> DataLayer::searchComp(string input)
{
    stringstream sqlQuery;
        sqlQuery << "SELECT * FROM Computers WHERE name LIKE '%" << input << "%"
                 << "' UNION "
                 << "SELECT * FROM Computers WHERE type LIKE '%" << input << "%"
                 << "' UNION "
                 << "SELECT * FROM Computers WHERE yearMade LIKE '%" << input << "%'";

    QString sqlQ = QString::fromStdString(sqlQuery.str());
    vector<Computer> computers;

    if (!_db.isOpen())
    {
        return computers;
    }

    QSqlQuery query(_db);

    if (!query.exec(sqlQ))
    {
        return computers;
    }

    while (query.next())
    {
        int valid = query.value(5).toInt();
        if(valid == 1)
        {
            QString qName = query.value(1).toString();
            string nName = qName.toStdString();

            QString qIfMade = query.value(3).toString();
            bool nIfMade;
            if(qIfMade == "1") nIfMade = true;
            else nIfMade = false;

            QString qType = query.value(2).toString();
            string nType = qType.toStdString();

            int nYearMade = query.value(4).toInt();

            Computer newComp(nIfMade, nName, nType, nYearMade);
            computers.push_back(newComp);
        }
    }

    return computers;
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

bool DataLayer::connect(Scientist newSci, Computer newComp)
{
    QSqlQuery sciQuery = findScientists(newSci);
    QSqlQuery compQuery = findComputers(newComp);

    QSqlQuery updateQuery;
    updateQuery.prepare("INSERT INTO scicomp (scientistID, computerID, valid) VALUES(:scientistID, :computerID, :valid)");


    updateQuery.bindValue(":scientistID", sciQuery.value(0).toInt());
    updateQuery.bindValue(":computerID", compQuery.value(0).toInt());
    updateQuery.bindValue(":valid", QString::number(1));
    bool returnValue = updateQuery.exec();
    return returnValue;

}

vector<Computer> DataLayer::findConnectedComp(Scientist sci)
{
    QSqlQuery sciQuery = findScientists(sci);

    QSqlQuery sciCompQuery;
    sciCompQuery.prepare("SELECT computerID FROM scicomp WHERE scientistID = (:ID) AND valid = 1");
    sciCompQuery.bindValue(":ID", sciQuery.value(0).toInt());
    sciCompQuery.exec();

    vector<Computer> returnVector;
    while(sciCompQuery.next())
    {
        QSqlQuery compQuery;
        compQuery.prepare("SELECT name, ifMade, yearMade, type FROM Computers WHERE ID = (:ID)");
        compQuery.bindValue(":ID", sciCompQuery.value(0).toInt());
        compQuery.exec();
        compQuery.first();
        QString qName = compQuery.value(0).toString();
        string name = qName.toStdString();
        QString qType = compQuery.value(3).toString();
        string type = qType.toStdString();



        Computer newComp(compQuery.value(1).toInt(), name, type, compQuery.value(3).toInt());
        returnVector.push_back(newComp);
    }
    return returnVector;
}

vector<Scientist> DataLayer::findConnectedSci(Computer comp)
{
    QSqlQuery compQuery = findComputers(comp);

    QSqlQuery sciCompQuery;
    sciCompQuery.prepare("SELECT scientistID FROM scicomp WHERE computerID = (:ID)");
    sciCompQuery.bindValue(":ID", compQuery.value(0).toInt());
    sciCompQuery.exec();

    vector<Scientist> returnVector;
    while(sciCompQuery.next())
    {

        QSqlQuery sciQuery;
        sciQuery.prepare("SELECT name, gender, yearOfBirth, yearOfDeath FROM Scientists WHERE ID = (:ID)");
        sciQuery.bindValue(":ID", sciCompQuery.value(0).toInt());

        sciQuery.exec();
        sciQuery.first();
        QString qName = sciQuery.value(0).toString();
        string name = qName.toStdString();
        QString qGender = sciQuery.value(1).toString();
        string sGender = qGender.toStdString();
        char gender = sGender.at(0);


        Scientist newSci(name, gender, sciQuery.value(2).toInt(), sciQuery.value(3).toInt());
        returnVector.push_back(newSci);
    }
    return returnVector;
}

vector<string> DataLayer::readManual()
{
    string line;
    vector<string> manual;
    ifstream myFile;
    myFile.open("../readme.txt");
    if(myFile)
    {
        while(getline(myFile,line))
        {
            manual.push_back(line);
        }
        myFile.close();
    }
    else
    {
        manual.push_back("Ahh.. Could not find and open readMe.txt, I guess you'll have manage without it. Sorry...");
    }
    return manual;
}

bool DataLayer::addScientistPicture(Scientist sci, QByteArray pict)
{
    QSqlQuery scientistQuery = findScientists(sci);

    QSqlQuery query;
    query.prepare("UPDATE Scientists SET picture = (:picture) WHERE ID = (:ID)");
    query.bindValue(":picture", pict);
    query.bindValue(":ID", scientistQuery.value(0).toInt());
    qDebug() << query.exec();
    bool returnValue = query.exec();
    return returnValue;
}

QByteArray DataLayer::getScientistPicture(Scientist sci)
{
    QSqlQuery sciQuery = findScientists(sci);
    QSqlQuery query;
    query.prepare("SELECT picture FROM Scientist WHERE ID = (:ID)");
    query.bindValue(":ID", sciQuery.value(0).toInt());
    query.exec();
    QByteArray returnPict = query.value(0).toByteArray();
    return returnPict;
}

QByteArray DataLayer::getInfo(Scientist sci)
{
    QSqlQuery sciQuery = findScientists(sci);
    QSqlQuery query;
    query.prepare("SELECT info FROM Scientists WHERE ID = (:ID)");
    query.bindValue(":ID", sciQuery.value(0).toInt());
    query.exec();

    QByteArray returnValue = query.value(0).toByteArray();
    return returnValue;
}

bool DataLayer::addInfo(Scientist sci, QByteArray inf)
{
    QSqlQuery sciQuery = findScientists(sci);
    QSqlQuery query;
    query.prepare("UPDATE Scientists SET info = (:info) WHERE ID = (:ID)");
    query.bindValue(":ID", sciQuery.value(0).toInt());
    query.bindValue(":info", inf);
    bool returnValue = query.exec();
    return returnValue;

}
