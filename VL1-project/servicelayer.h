#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#include "scientist.h"
#include "computer.h"
#include "datalayer.h"
#include <algorithm>

class ServiceLayer
{
public:
    ServiceLayer();
    bool addScientitst(Scientist aScientist);
    bool addComputer(Computer aComputer);
    bool closeData();

    bool deleteSci(Scientist newSci);
    bool deleteComp(Computer newComp);

    void clearData(string com);
    vector<int> getConnections();
    
    vector<string> connectSci(int whichSci, vector<int> vWhichComp);
    vector<string> connectComp(int whichComp, vector<int> vWhichSci);

    vector<Scientist> sciGet();
    vector<Computer> compGet();
    
    vector<Scientist> sciAlpha();
    vector<Scientist> sciRalpha();
    vector<Scientist> sciAgeAsc();
    vector<Scientist> sciAgeDesc();
    vector<Scientist> sciDeathAsc();
    vector<Scientist> sciDeathDesc();
    
    vector<Computer> compAlpha();
    vector<Computer> compRalpha();
    vector<Computer> compAgeAsc();
    vector<Computer> compAgeDesc();
    vector<Computer> compMade();
    vector<Computer> compNotMade();
    vector<Computer> compType();
    
    vector<Scientist> searchSci(string name, char gender, string born, string death);
    vector<Computer> searchComp(string ifMade, string name, string type, string yearMade);
private:
    vector<Scientist> _vScientists;
    vector<Computer> _vComputer;
    DataLayer _dataL;
};

#endif // SERVICELAYER_H
