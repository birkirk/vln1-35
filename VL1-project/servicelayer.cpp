#include "servicelayer.h"

ServiceLayer::ServiceLayer()
{

}

void ServiceLayer::addScientitst(Scientist aScientist) {
    vector<Scientist> vUse = dataL.readFile();
    vUse.push_back(aScientist);
    dataL.writeFile(vUse);
}

void ServiceLayer::sortAlphabetical()
{
    //TODO
}
void ServiceLayer::sortByBirthAscendng()
{
    //TODO
}
void ServiceLayer::sortByBirthDescending()
{
    //TODO
}
void ServiceLayer::sortByGender()
{
    //TODO
}
void ServiceLayer::sortByDeathAscending()
{
    //TODO
}
void ServiceLayer::sortByDeathDescending()
{

}

void ServiceLayer::search()
{

}
