#include "servicelayer.h"
#include <algorithm>


ServiceLayer::ServiceLayer() {

}

void ServiceLayer::addScientitst(Scientist aScientist) {
    vector<Scientist> vUse = _dataL.readSci();
    vUse.push_back(aScientist);
}

void ServiceLayer::addComputer(Computer aComputer) {
    vector<Computer> vUse = _dataL.readComp();
    vUse.push_back(aComputer);
}
