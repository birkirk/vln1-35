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

    bool addScientistPicture(Scientist sci, QByteArray pict);
    bool addComputerPicture(Computer comp, QByteArray pict);
    QByteArray getComputerPicture(Computer comp);

    //Endurheimtir einingar úr ruslafötunni og setur aftur á listann
    bool recycleComp(Computer comp);
    bool recycleSci(Scientist sci);

    //Býr til vectora af eyddum einingum fyrir ruslafötuna
    vector<Computer> getDeletedComp();
    vector<Scientist> getDeletedSci();

    void addType(string type);

    //Les úr database-inu inn í vectora
    vector<Scientist> readSci(string com);
    vector<Computer> readComp(string com);

    vector<Scientist> searchSci(string input);
    vector<Computer> searchComp(string input);

    //Finnur allar tengingar sem eru í database-inu
    vector<int> getCon();

    QByteArray getScientistPicture(Scientist sci);

    bool addScientistInfo(Scientist sci);
    string getScientistInfo(Scientist sci);

    //Finnur ákveðnar tengingar
    vector<Computer> findConnectedComp(Scientist sci);
    vector<Scientist> findConnectedSci(Computer comp);

    //Les úr readme.txt inn í vector
    vector<string> readManual();

    bool addScientist(Scientist sci);
    bool deleteScientist(Scientist newSci);
    
    bool addComputer(Computer comp);
    bool deleteComputer(Computer newComp);

    bool closeDatabase();
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

