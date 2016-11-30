#include "servicelayer.h"

ServiceLayer::ServiceLayer()
{

}

struct ScientistComparison {
    bool operator() (Scientist i,Scientist j) { return (i.getFirstName()<j.getFirstName());}
};

void ServiceLayer::addScientitst(Scientist aScientist) {
    vector<Scientist> vUse = dataL.readFile();
    vUse.push_back(aScientist);
    dataL.writeFile(vUse);
}

vector<Scientist> ServiceLayer::sortAlphabetical()
{
    vector<Scientist> vAlpha = dataL.readFile();
    ScientistComparison cmp;
    std::sort(vAlpha.begin(), vAlpha.end(), cmp);
    return vAlpha;
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
