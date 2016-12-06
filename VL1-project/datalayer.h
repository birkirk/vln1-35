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
    
    vector<Scientist> readSci();
    vector<Computer> readComp();
    void writeFile(vector<Scientist> vScientist);

    bool addScientist(string sName, int sYearOfBirth, int sYearOfDeath, char sGender);
private:
    QSqlDatabase _db;
};



#endif // DATALAYER_H

