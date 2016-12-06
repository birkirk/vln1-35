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
    
    vector<Scientist> sciAlpha();
    vector<Scientist> sciRalpha();
    vector<Scientist> sciAgeAsc();
    vector<Scientist> sciAgeDesc();
    vector<Scientist> sciMale();
    vector<Scientist> sciFemale();
private:
    vector<Scientist> _vScientists;
    vector<Computer> _vComputer;
    DataLayer _dataL;
};

#endif // SERVICELAYER_H
