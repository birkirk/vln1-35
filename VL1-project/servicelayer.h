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
    void addScientitst(Scientist aScientist);
    void addComputer(Computer aComputer);
    bool deleteSci(Scientist newSci);
    
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
private:
    vector<Scientist> _vScientists;
    vector<Computer> _vComputer;
    DataLayer _dataL;
};

#endif // SERVICELAYER_H
