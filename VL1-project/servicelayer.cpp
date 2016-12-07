#include "servicelayer.h"
#include <algorithm>


ServiceLayer::ServiceLayer()
{

}

void ServiceLayer::addScientitst(Scientist aScientist)
{
    
}

void ServiceLayer::addComputer(Computer aComputer)
{
    
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





