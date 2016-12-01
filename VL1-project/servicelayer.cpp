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

struct ScientistComparison {            //Alphabetical
    bool operator() (Scientist i,Scientist j) { return (i.getFirstName()<j.getFirstName());}
};

struct ScientistComparisonBa {          //Birth ascending
    bool operator() (Scientist i,Scientist j) { return (i.getBirth()<j.getBirth());}
};

struct ScientistComparisonBd {          //Birth descending
    bool operator() (Scientist i,Scientist j) { return (i.getBirth()>j.getBirth());}
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
    vector<Scientist> vBirth = dataL.readFile();
    ScientistComparisonBa cmp;
    std::sort(vBirth.begin(), vBirth.end(), cmp);
    return vBirth;
}
vector<Scientist> ServiceLayer::sortByBirthDescending()
{
    vector<Scientist> vBirth = dataL.readFile();
    ScientistComparisonBd cmp;
    std::sort(vBirth.begin(), vBirth.end(), cmp);
    return vBirth;
}
vector<Scientist> ServiceLayer::sortByMaleFemale()
{
    vector<Scientist> tempF, tempM, retVec;
    vector<Scientist> vGender = dataL.readFile();
    for(size_t i = 0; i < vGender.size(); i++) {
        if(vGender[i].getGender() == 'M' || vGender[i].getGender() == 'm') {
            tempM.push_back(vGender[i]);
        } else if(vGender[i].getGender() == 'F' || vGender[i].getGender() == 'f') {
            tempF.push_back(vGender[i]);
        }
    }
    for(size_t i = 0; i < tempM.size(); i++) {
        retVec.push_back(tempM[i]);
    }
    for(size_t i = 0; i < tempF.size(); i++) {
        retVec.push_back(tempF[i]);
    }
    return retVec;
}

vector<Scientist> ServiceLayer::sortByFemaleMale()
{
    vector<Scientist> tempF, tempM, retVec;
    vector<Scientist> vGender = dataL.readFile();
    for(size_t i = 0; i < vGender.size(); i++) {
        if(vGender[i].getGender() == 'M' || vGender[i].getGender() == 'm') {
            tempM.push_back(vGender[i]);
        } else if(vGender[i].getGender() == 'F' || vGender[i].getGender() == 'f') {
            tempF.push_back(vGender[i]);
        }
    }
    for(size_t i = 0; i < tempF.size(); i++) {
        retVec.push_back(tempF[i]);
    }
    for(size_t i = 0; i < tempM.size(); i++) {
        retVec.push_back(tempM[i]);
    }
    return retVec;
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

void ServiceLayer::clearAll() {
    dataL.clearFile();
}



