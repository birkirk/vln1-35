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
    vector<Scientist> searchByName(string s1);
    vector<Scientist> searchByBirth(int s1);
    vector<Scientist> searchByDeath(int s1);
private:
    vector<Scientist> vScientists;
    DataLayer dataL;
};

#endif // SERVICELAYER_H
