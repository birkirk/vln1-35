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
vector<Scientist> ServiceLayer::sortByBirthAscendng()
{
    //TODO
}
vector<Scientist> ServiceLayer::sortByBirthDescending()
{
    //TODO
}
vector<Scientist> ServiceLayer::sortByGender()
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
