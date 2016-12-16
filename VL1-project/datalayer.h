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

    bool addComputerPicture(Computer comp, QByteArray pict);
    QByteArray getComputerPicture(Computer comp);
    bool recycleComp(Computer comp);
    vector<Computer> getDeletedComp();
    vector<Computer> readComp(string com);
    vector<Computer> searchComp(string input);
    bool addComputerInfo(Computer comp);
    string getComputerInfo(Computer comp);

    bool addScientist(Scientist sci);
    bool deleteScientist(Scientist newSci);
    bool addScientistPicture(Scientist sci, QByteArray pict);
    bool recycleSci(Scientist sci);
    vector<Scientist> getDeletedSci();
    vector<Scientist> readSci(string com);
    vector<Scientist> searchSci(string input);




    void addType(string type);
    vector<int> getCon();
    QByteArray getScientistPicture(Scientist sci);

    bool addScientistInfo(Scientist sci);
    string getScientistInfo(Scientist sci);

    vector<Computer> findConnectedComp(Scientist sci);
    vector<Scientist> findConnectedSci(Computer comp);
    vector<string> readManual();

    
    bool addComputer(Computer comp);
    bool deleteComputer(Computer newComp);

    bool closeDatabase();
    void writeFile(vector<Scientist> vScientist);
    bool connect(Scientist newSci, Computer newComp);
    bool deleteConnection(Computer comp, Scientist sci);

    void clearSci();
    void clearDataFile();
    void clearComp();
    void clearCon();

private:
    QSqlDatabase _db;
};



#endif // DATALAYER_H

