#include "datalayer.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

DataLayer::DataLayer()
{
    
}

istream& operator >> (istream& in, Scientist& s) {
    in >> s.getFirstName() >> s.getLastName() >> s.getGender() >> s.getBirth() >> s.getDeath();
    return in;
}

vector<Scientist> DataLayer::readFile() {
    ifstream inputFile;
    inputFile.open ("/Users/Birkir/Desktop/ScientistData.txt", ios::app);
    Scientist tempSci;
    
    if(inputFile) {
        while(inputFile >> tempSci)
        {
            dataVector.push_back(tempSci);
        }
        inputFile.close();
    }
    return dataVector;
}

ostream& operator << (ostream& out, Scientist aScientist) {
    out << aScientist.getFirstName() << " " << aScientist.getLastName() << " " << aScientist.getGender() << " " << aScientist.getBirth() << " " << aScientist.getDeath() << " ";
    return out;
}

void DataLayer::writeFile(vector<Scientist> vScientist) {
    ofstream outputFile;
    outputFile.open ("/Users/Birkir/Desktop/ScientistData.txt", ios::app);
    if(outputFile) {
        for(size_t i = 0; i < vScientist.size(); i++) {
            outputFile << vScientist[i] << endl;
        }
    }
    outputFile.close();
}

/* void DataLayer::addScientist(Scientist newScientist)
{
    bool inputTest = false;
    for(unsigned int i = 0; i < dataVector.size(); i++)
    {
        if(newScientist.getFirstName() == dataVector[i].getFirstName() && newScientist.getLastName() == dataVector[i].getLastName()) inputTest = true;
    }
    ofstream outputFile;
    outputFile.open ("ScientistData.txt", ios_base::app);
    string returnString;
    if(inputTest == false)
    {
        outputFile << endl << newScientist.getFirstName() << " ";
        outputFile << newScientist.getLastName();
        outputFile << newScientist.getGender() << " ";
        outputFile << newScientist.getBirth() << " " << newScientist.getDeath();
        returnString = "successful";
    }
    else returnString = "unsuccessful!";
} */


