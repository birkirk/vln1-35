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

using namespace std;

class DataLayer
{
public:
    DataLayer();
    DataLayer(const QString& path);
    
    vector<Scientist> readSci(string com);
    vector<Computer> readComp(string com);
    void writeFile(vector<Scientist> vScientist);

    bool addScientist(string sName, int sYearOfBirth, int sYearOfDeath, char sGender);

    bool addScientist(string sName, int sYearOfBirth, char sGender);

    bool addComputer(string cName, string cType, bool cIfMade, char cYearMade);

private:
    QSqlDatabase _db;
};



#endif // DATALAYER_H

