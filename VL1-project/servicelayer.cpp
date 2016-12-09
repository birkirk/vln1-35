#include "servicelayer.h"
#include <algorithm>
#include <iostream>

ServiceLayer::ServiceLayer()
{

}

bool ServiceLayer::closeData()
{
    bool reportClose = _dataL.closeDatabase();
    return reportClose;
}

bool ServiceLayer::deleteSci(Scientist newSci)
{
    bool returnBool = _dataL.deleteScientist(newSci);
    return returnBool;
}

bool ServiceLayer::deleteComp(Computer newComp)
{
    bool returnBool = _dataL.deleteComputer(newComp);
    return returnBool;
}

bool ServiceLayer::addScientitst(Scientist aScientist)
{
    bool success = _dataL.addScientist(aScientist);
    return success;
}

bool ServiceLayer::addComputer(Computer aComputer)
{
    bool success = _dataL.addComputer(aComputer);
    return success;
}

vector<Scientist> ServiceLayer::searchSci(string name, char gender, string born, string death)
{
    vector<Scientist> vSearched = _dataL.searchSci(name, gender, born, death);
    return vSearched;
}

vector<Computer> ServiceLayer::searchComp(string ifMade, string name, string type, string yearMade)
{
    vector<Computer> vSearched = _dataL.searchComp(ifMade, name, type, yearMade);
    return vSearched;
}

vector<Scientist> ServiceLayer::sciGet()
{
    string com = "non";
    vector<Scientist> vOrder = _dataL.readSci(com);
    return vOrder;
}

vector<Computer> ServiceLayer::compGet()
{
    string com = "non";
    vector<Computer> vOrder = _dataL.readComp(com);
    return vOrder;
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

void ServiceLayer::clearData(string com)
{
    if(com == "all")
    {
        _dataL.clearDataFile();
    }
    else if(com == "sci")
    {
        _dataL.clearSci();
    }
    else if(com == "comp")
    {
        _dataL.clearComp();
    }
    else if(com == "con")
    {
        _dataL.clearCon();
    }
}

vector<int> ServiceLayer::getConnections() {
    vector<int> vConnections = _dataL.getCon();
    return vConnections;
}

bool ServiceLayer::connect(Scientist sci, Computer comp)
{
    bool success = _dataL.connect(sci, comp);
    return success;
}



vector<int> ServiceLayer::receiveCon(int usedid, string which)
{
    vector<int>allCon;
    if(which == "computer")
    {
        allCon = _dataL.findConnectedSci(usedid);
    }
    else if(which == "scientist")
    {
        allCon = _dataL.findConnectedComp(usedid);
    }
    return allCon;
}





