#include "servicelayer.h"
#include <algorithm>

bool icompare_pred(unsigned char a, unsigned char b)
{
    return std::tolower(a) == std::tolower(b);
}

bool icompare(std::string const& a, std::string const& b)
{
    if (a.length()==b.length()) {
        return std::equal(b.begin(), b.end(), a.begin(), icompare_pred);
    }
    else {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////

ServiceLayer::ServiceLayer()
{

}

struct ScientistComparisonAlphabet {
    bool operator() (Scientist i,Scientist j) { return (i.getFirstName()<j.getFirstName());}
};
struct ScientistComparisonReverseAlphabet {
    bool operator() (Scientist i,Scientist j) { return (i.getFirstName()>j.getFirstName());}
};


void ServiceLayer::addScientitst(Scientist aScientist) {
    vector<Scientist> vUse = dataL.readFile();
    vUse.push_back(aScientist);
    dataL.writeFile(vUse);
}

vector<Scientist> ServiceLayer::sortAlphabetical()
{
    vector<Scientist> vAlpha = dataL.readFile();
    ScientistComparisonAlphabet cmp;
    std::sort(vAlpha.begin(), vAlpha.end(), cmp);
    return vAlpha;
}
vector<Scientist> ServiceLayer::sortReverseAlphabetical()
{
    vector<Scientist> vAlpha = dataL.readFile();
    ScientistComparisonReverseAlphabet cmp;
    std::sort(vAlpha.begin(), vAlpha.end(), cmp);
    return vAlpha;
}

vector<Scientist> ServiceLayer::sortByBirthAscendng()
{
    vector<Scientist> vBirth = dataL.readFile();
    ScientistComparisonAlphabet cmp;
    std::sort(vBirth.begin(), vBirth.end(), cmp);
    return vBirth;
}
vector<Scientist> ServiceLayer::sortByBirthDescending()
{
    vector<Scientist> vBirth = dataL.readFile();
    return vBirth;
}
vector<Scientist> ServiceLayer::sortByGender()
{
    vector<Scientist> vGender = dataL.readFile();
    return vGender;
}
void ServiceLayer::sortByDeathAscending()
{
    //TODO
}
void ServiceLayer::sortByDeathDescending()
{

}

vector<Scientist> ServiceLayer::searchByName(string s1)
{
    vector<Scientist> dataVector = dataL.readFile();
    vector<Scientist> returnVector;

    for(unsigned int i = 0; i < dataVector.size(); i++)
    {
        if(icompare(s1, dataVector[i].getFirstName()) || icompare(s1, dataVector[i].getLastName()))
        {
            returnVector.push_back(dataVector[i]);
        }
    }
    return returnVector;
}
vector<Scientist> ServiceLayer::searchByBirth(int s1)
{
    vector<Scientist> dataVector = dataL.readFile();
    vector<Scientist> returnVector;

    for(unsigned int i = 0; i < dataVector.size(); i++)
    {
        if(s1 == dataVector[i].getBirth())
        {
            returnVector.push_back(dataVector[i]);
        }
    }
    return returnVector;
}
vector<Scientist> ServiceLayer::searchByDeath(int s1)
{
    vector<Scientist> dataVector = dataL.readFile();
    vector<Scientist> returnVector;

    for(unsigned int i = 0; i < dataVector.size(); i++)
    {
        if(s1 == dataVector[i].getDeath())
        {
            returnVector.push_back(dataVector[i]);
        }
    }
    return returnVector;
}



