#ifndef SERVICELAYER_H
#define SERVICELAYER_H
#include "scientist.h"
#include "computer.h"
#include "datalayer.h"
#include <algorithm>
#include <QDebug>

class ServiceLayer
{
public:
    ServiceLayer();
    
    bool addScientitstPicture(Scientist sci, QByteArray image);
    QByteArray getScientistPicture(Scientist sci);
    bool addScientitst(Scientist aScientist);
    bool addScientistInfo(Scientist sci, string inf);
    bool recycleSci(Scientist sci);
    vector<Scientist> getDeletedSci();
    bool deleteSci(Scientist newSci);

    QByteArray getComputerPicture(Computer comp);

    bool updateScientist(Scientist oldSci, Scientist newSci);

    vector<string> getTypes();

    void addType(string type);

    vector<Computer> getDeletedComp();
    bool recycleComp(Computer comp);
    bool addComputer(Computer aComputer);
    bool deleteComp(Computer newComp);


    string getScientistInfo(Scientist sci);

    bool closeData();
    bool connect(Scientist Sci, Computer Comp);
    bool deleteConnection(Computer comp, Scientist sci);

    void clearData(string com);

    bool addComputerPicture(Computer comp, QByteArray pict);
    
    vector<int> receiveCon(int usedid, string which);
    vector<Computer> getConnectedComp(Scientist sci);
    vector<Scientist> getConnectedSci(Computer comp);
    vector<Scientist> sciGet();
    vector<Computer> compGet();
    vector<Scientist> searchSci(string input);
    vector<Computer> searchComp(string input);
    vector<string> getManual();
private:
    vector<Scientist> _vScientists;
    vector<Computer> _vComputer;
    DataLayer _dataL;
};

#endif // SERVICELAYER_H
