#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#include "scientist.h"
#include "datalayer.h"

class ServiceLayer
{
public:
    ServiceLayer();
    void addScientitst(Scientist aScientist);
    vector<Scientist> sortAlphabetical();
    void sortByBirthAscendng();
    void sortByBirthDescending();
    void sortByGender();
    void sortByDeathAscending();
    void sortByDeathDescending();
    void search();
private:
    vector<Scientist> vScientists;
    DataLayer dataL;
};

#endif // SERVICELAYER_H
