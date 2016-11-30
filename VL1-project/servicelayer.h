#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#include "scientist.h"
#include "datalayer.h"
#include <algorithm>

class ServiceLayer
{
public:
    ServiceLayer();
    void addScientitst(Scientist aScientist);
    vector<Scientist> sortAlphabetical();
    vector<Scientist> sortByBirthAscendng();
    vector<Scientist> sortByBirthDescending();
    vector<Scientist> sortByGender();
    void sortByDeathAscending();
    void sortByDeathDescending();
    void search();
private:
    vector<Scientist> vScientists;
    DataLayer dataL;
};

#endif // SERVICELAYER_H
