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
    
    vector<int> receiveCon(int usedid, string which);

    bool deleteSci(Scientist newSci);
    bool deleteComp(Computer newComp);

    void clearData(string com);

    vector<Computer> getConnectedComp(Scientist sci);
    vector<Scientist> getConnectedSci(Computer comp);
    
    bool connect(Scientist Sci, Computer Comp);

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

    vector<string> getManual();
private:
    vector<Scientist> _vScientists;
    vector<Computer> _vComputer;
    DataLayer _dataL;
};

#endif // SERVICELAYER_H
