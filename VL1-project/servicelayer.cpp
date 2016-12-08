#include "servicelayer.h"
#include <algorithm>
#include <iostream>

ServiceLayer::ServiceLayer()
{

}

bool ServiceLayer::deleteSci(Scientist newSci)
{
    bool returnBool = _dataL.deleteScientist(newSci);
    return returnBool;
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

vector<Scientist> ServiceLayer::searchSci(string name, char gender, string born, string death)
{
    vector<Scientist> vSearched = _dataL.searchSci(name, gender, born, death);
    return vSearched;
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


vector<Computer> ServiceLayer::compAlpha()
{
    string com = "alpha";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
}

vector<Computer> ServiceLayer::compRalpha()
{
    string com = "ralpha";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
}

vector<Computer> ServiceLayer::compAgeAsc()
{
    string com = "ageasc";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
}

vector<Computer> ServiceLayer::compAgeDesc()
{
    string com = "agedesc";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
}

vector<Computer> ServiceLayer::compMade()
{
    string com = "made";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
}

vector<Computer> ServiceLayer::compNotMade()
{
    string com = "notmade";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
}

vector<Computer> ServiceLayer::compType()
{
    string com = "type";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
}




