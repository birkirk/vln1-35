#include "servicelayer.h"
#include <algorithm>
#include <iostream>

ServiceLayer::ServiceLayer()
{

}

void ServiceLayer::addScientitst(Scientist aScientist)
{
    bool success = _dataL.addScientist(aScientist.getName(), aScientist.getBirth(), aScientist.getDeath(), aScientist.getGender());
    if(success) cout << "Scientist successfully added";
    else cout << "FAILED";
}

void ServiceLayer::addComputer(Computer aComputer)
{
    
}


vector<Scientist> ServiceLayer::sciAlpha()
{
    vector<Scientist> vOrder = _dataL.readSci();
    return vOrder;
}

vector<Scientist> ServiceLayer::sciRalpha()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> ServiceLayer::sciAgeAsc()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> ServiceLayer::sciAgeDesc()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> ServiceLayer::sciDeathAsc()
{
    vector<Scientist> vOrder;
    return vOrder;
}

vector<Scientist> ServiceLayer::sciDeathDesc()
{
    vector<Scientist> vOrder;
    return vOrder;
}





