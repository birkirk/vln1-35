#include "servicelayer.h"
#include <algorithm>


ServiceLayer::ServiceLayer()
{

}

void ServiceLayer::addScientitst(Scientist aScientist) {
    vector<Scientist> vUse = dataL.readSci();
    vUse.push_back(aScientist);
    dataL.writeFile(vUse);
}

void ServiceLayer::addComputer(Computer aComputer) {
    vector<Computer> vUse = dataL.readComp();
    vUse.push_back(aComputer);
}

void ServiceLayer::clearAll() {
    dataL.clearFile();
}



