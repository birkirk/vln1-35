#include "servicelayer.h"
#include <algorithm>


ServiceLayer::ServiceLayer()
{

}

void ServiceLayer::addScientitst(Scientist aScientist)
{
    vector<Scientist> vUse = _dataL.readSci();
    vUse.push_back(aScientist);
}

void ServiceLayer::addComputer(Computer aComputer)
{
    vector<Computer> vUse = _dataL.readComp();
    vUse.push_back(aComputer);
}


vector<Scientist> sciAlpha()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> sciRalpha()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> sciAgeAsc()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> sciAgeDesc()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> sciMale()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> sciFemale()
{
    vector<Scientist> vOrder;
    return vOrder;
}





