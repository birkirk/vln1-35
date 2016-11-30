#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#include "scientist.h"

class ServiceLayer
{
public:
    void addScientitst(Scientist aScientist);
    ServiceLayer();
    void sortAlphabetical();
    void sortByBirthAscendng();
    void sortByBirthDescending();
    void sortByGender();
    void sortByDeathAscending();
    void sortByDeathDescending();
    void search();
private:
    vector<Scientist> vScientists;
};

#endif // SERVICELAYER_H
