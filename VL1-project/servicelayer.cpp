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
    bool success = _dataL.addComputer(aComputer.getName(), aComputer.getType(), aComputer.getIfMade(), aComputer.getYearMade());
    if(success) cout << "Computer successfully added";
    else cout << "FAILED";
}


vector<Scientist> ServiceLayer::sciAlpha()
{
    string com = "alpha";
    vector<Scientist> vOrder = _dataL.readSci(com);
    return vOrder;
}

vector<Scientist> ServiceLayer::sciRalpha()
{
    string com = "ralpha";
    vector<Scientist> vOrder = _dataL.readSci(com);
    return vOrder;
}

vector<Scientist> ServiceLayer::sciAgeAsc()
{
    string com = "ageasc";
    vector<Scientist> vOrder = _dataL.readSci(com);
    return vOrder;
}

vector<Scientist> ServiceLayer::sciAgeDesc()
{
    string com = "agedesc";
    vector<Scientist> vOrder = _dataL.readSci(com);
    return vOrder;
}

vector<Scientist> ServiceLayer::sciDeathAsc()
{
    string com = "deathasc";
    vector<Scientist> vOrder = _dataL.readSci(com);
    return vOrder;
}

vector<Scientist> ServiceLayer::sciDeathDesc()
{
    string com = "deathdesc";
    vector<Scientist> vOrder = _dataL.readSci(com);
    return vOrder;
}





