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
    void clearAll();
private:
    vector<Scientist> vScientists;
    vector<Computer> vComputer;
    DataLayer dataL;
};

#endif // SERVICELAYER_H
