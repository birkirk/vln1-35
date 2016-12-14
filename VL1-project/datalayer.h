#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include "computer.h"
#include "scientist.h"
#include <QSqlQuery>
#include <QDebug>
#include <QChar>
#include <QString>
#include <QtSql>
#include <QFile>


using namespace std;

class DataLayer
{
public:
    //Remove this later!!!
    //QSqlQuery findScientists(string sName, int sYearOfBirth, int sYearOfDeath, char sGender);
    //bool addScientist(string sName, int sYearOfBirth, char sGender);
    DataLayer();
    DataLayer(const QString& path);
    vector<string> getTypes();

    bool addScientistPicture(Scientist sci, QByteArray image);

    bool recycleComp(Computer comp);
    bool recycleSci(Scientist sci);

    vector<Computer> getDeletedComp();
    vector<Scientist> getDeletedSci();

    void addType(string type);
    vector<Scientist> readSci(string com);
    vector<Computer> readComp(string com);
    vector<Scientist> searchSci(string input);
    vector<Computer> searchComp(string input);
    vector<int> getCon();
    vector<Computer> findConnectedComp(Scientist sci);
    vector<Scientist> findConnectedSci(Computer comp);
    vector<string> readManual();
    
    bool closeDatabase();
    void writeFile(vector<Scientist> vScientist);
    bool addScientist(Scientist sci);
    bool deleteScientist(Scientist newSci);
    bool deleteComputer(Computer newComp);
    bool connect(Scientist newSci, Computer newComp);
    bool addComputer(Computer comp);

    void clearDataFile();
    void clearSci();
    void clearComp();
    void clearCon();

private:
    QSqlDatabase _db;
};



#endif // DATALAYER_H

