#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#include "scientist.h"
#include "computer.h"
#include "datalayer.h"
#include <algorithm>
#include <QDebug>

class ServiceLayer
{
public:
    ServiceLayer();
    
    vector<string> getTypes();
    void addType(string type);

    vector<Computer> getDeletedComp();
    vector<Scientist> getDeletedSci();

    bool recycleComp(Computer comp);
    bool recycleSci(Scientist sci);

    bool addScientitst(Scientist aScientist);
    bool addComputer(Computer aComputer);
    bool closeData();
    bool deleteSci(Scientist newSci);
    bool deleteComp(Computer newComp);
    bool connect(Scientist Sci, Computer Comp);
    
    void clearData(string com);
    
    vector<int> receiveCon(int usedid, string which);
    vector<Computer> getConnectedComp(Scientist sci);
    vector<Scientist> getConnectedSci(Computer comp);
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
    vector<Scientist> searchSci(string input);
    vector<Computer> searchComp(string input);
    vector<string> getManual();
private:
    vector<Scientist> _vScientists;
    vector<Computer> _vComputer;
    DataLayer _dataL;
};

#endif // SERVICELAYER_H
