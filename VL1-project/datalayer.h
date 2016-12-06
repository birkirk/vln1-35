#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include "computer.h"
#include "scientist.h"
#include <QSqlQuery>
#include <QDebug>

using namespace std;

class DataLayer
{
public:
    DataLayer();
    DataLayer(const QString& path);
    void addScientist(Scientist newScientist);
    vector<Scientist> readSci();
    vector<Computer> readComp();
    void clearFile();
    void writeFile(vector<Scientist> vScientist);
private:
    vector<Scientist> dataVector;
    QSqlDatabase db;
};



#endif // DATALAYER_H

