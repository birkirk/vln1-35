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
    QSqlQuery findScientists(string sName, int sYearOfBirth, int sYearOfDeath, char sGender);

    DataLayer();
    DataLayer(const QString& path);
    
    bool closeDatabase();
    
    vector<Scientist> readSci(string com);
    vector<Computer> readComp(string com);
    vector<int> getCon();
    void writeFile(vector<Scientist> vScientist);

    bool addScientist(string sName, int sYearOfBirth, int sYearOfDeath, char sGender);

    bool addScientist(string sName, int sYearOfBirth, char sGender);

    bool deleteScientist(Scientist newSci);
    
    vector<string> connectSci(int whichSci, vector<int> vWhichComp);
    vector<string> connectComp(int whichComp, vector<int> vWhichSci);

    bool addComputer(string cName, string cType, bool cIfMade, int cYearMade);
    vector<Scientist> searchSci(string sName, char sGender, string sYearOfBirth, string sYearOfDeath);
    vector<Computer> searchComp(string ifMade, string name, string type, string yearMade);

    void clearDataFile();
    void clearSci();
    void clearComp();
    void clearCon();
private:
    QSqlDatabase _db;
};



#endif // DATALAYER_H

