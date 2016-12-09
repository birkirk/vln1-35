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

    DataLayer();
    DataLayer(const QString& path);
    
    bool closeDatabase();
    
    vector<Scientist> readSci(string com);
    vector<Computer> readComp(string com);
    vector<int> getCon();
    void writeFile(vector<Scientist> vScientist);

    bool addScientist(Scientist sci);

    //bool addScientist(string sName, int sYearOfBirth, char sGender);

    bool deleteScientist(Scientist newSci);
    bool deleteComputer(Computer newComp);
    
    bool connect(Scientist newSci, Computer newComp);

    bool addComputer(Computer comp);
    vector<Scientist> searchSci(string sName, char sGender, string sYearOfBirth, string sYearOfDeath);
    vector<Computer> searchComp(string ifMade, string name, string type, string yearMade);

    void clearDataFile();
    void clearSci();
    void clearComp();
    void clearCon();

    vector<Computer> findConnectedComp(Scientist sci);
    vector<Scientist> findConnectedSci(Computer comp);
private:
    QSqlDatabase _db;
};



#endif // DATALAYER_H

