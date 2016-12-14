#include "servicelayer.h"
#include <algorithm>
#include <iostream>

ServiceLayer::ServiceLayer()
{

}

vector<string> ServiceLayer::getTypes()
{
    vector<string> returnVector = _dataL.getTypes();
    return returnVector;
}

vector<Computer> ServiceLayer::getDeletedComp()
{
    vector<Computer> returnVector = _dataL.getDeletedComp();
    return returnVector;
}

bool ServiceLayer::recycleSci(Scientist sci)
{
    bool returnValue = _dataL.recycleSci(sci);
    return returnValue;
}
bool ServiceLayer::recycleComp(Computer comp)
{
    bool returnValue = _dataL.recycleComp(comp);
    return returnValue;
}

vector<Scientist> ServiceLayer::getDeletedSci()
{
    vector<Scientist> returnVector = _dataL.getDeletedSci();
    return returnVector;
}

void ServiceLayer::addType(string type)
{
    _dataL.addType(type);
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
    bool success;
    if(aScientist.hasPicture())
    {
        bool success = _dataL.addScientist(aScientist);
        _dataL.addScientistPicture(aScientist, aScientist.getPicture());
    }
    else
    {
        success = _dataL.addScientist(aScientist);
    }
    return success;
}

QByteArray ServiceLayer::getScientistPicture(Scientist sci)
{
    QByteArray returnPict = _dataL.getScientistPicture(sci);
    return returnPict;
}

bool ServiceLayer::addComputer(Computer aComputer)
{
    bool success = false;
    if(aComputer.hasPicture())
    {
        bool addedComp = _dataL.addComputer(aComputer);
        bool addedPict= _dataL.addComputerPicture(aComputer, aComputer.getPicture());
        if(addedComp && addedPict)
        {
            success = true;
        }
    }
    else
    {
        success = _dataL.addComputer(aComputer);
    }


    return success;
}

vector<Scientist> ServiceLayer::searchSci(string input)
{
    vector<Scientist> vSearched = _dataL.searchSci(input);
    return vSearched;
}

vector<Computer> ServiceLayer::searchComp(string input)
{
    vector<Computer> vSearched = _dataL.searchComp(input);
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

bool ServiceLayer::connect(Scientist sci, Computer comp)
{
    bool success = _dataL.connect(sci, comp);
    return success;
}

vector<Scientist> ServiceLayer::getConnectedSci(Computer comp)
{
    vector<Scientist> returnVector = _dataL.findConnectedSci(comp);
    return returnVector;
}

vector<Computer> ServiceLayer::getConnectedComp(Scientist sci)
{
    vector<Computer> returnVector = _dataL.findConnectedComp(sci);
    return returnVector;
}

vector<string> ServiceLayer::getManual()
{
    vector<string> manual = _dataL.readManual();
    return manual;
}

bool ServiceLayer::addComputerPicture(Computer comp, QByteArray pict)
{
    bool returnValue = _dataL.addComputerPicture(comp, pict);
    return returnValue;
}

bool ServiceLayer::addScientitstPicture(Scientist sci, QByteArray pict)
{
    bool returnValue = _dataL.addScientistPicture(sci, pict);
    return returnValue;
}

bool ServiceLayer::addScientistInfo(Scientist sci, QByteArray inf)
{
    bool returnValue = _dataL.addInfo(sci, inf);
    return returnValue;
}

QByteArray ServiceLayer::getInfo(Scientist sci)
{
    QByteArray returnValue = _dataL.getInfo(sci);
    return returnValue;
}


