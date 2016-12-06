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
private:
    vector<Scientist> _vScientists;
    vector<Computer> _vComputer;
    DataLayer _dataL;
};

#endif // SERVICELAYER_H
