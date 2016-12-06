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
    
    vector<Scientist> sortAlphabetical();
    vector<Scientist> sortReverseAlphabetical();
    vector<Scientist> sortByBirthAscending();
    vector<Scientist> sortByBirthDescending();
    vector<Scientist> sortByMaleFemale();
    vector<Scientist> sortByFemaleMale();
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
