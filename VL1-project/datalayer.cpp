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
    in >> s._firstName;
    in >> s._lastName;
    in >> s._gender;
    in >> s._born;
    in >> s._death;
    return in;
}

vector<Scientist> DataLayer::readFile() {
    ifstream inputFile;
    inputFile.open ("/Users/Birkir/Desktop/ScientistData.txt");
    Scientist tempSci;
    vector<Scientist> tempV;
    string test;
    
    if(inputFile) {
        while(inputFile >> tempSci)
        {
            tempV.push_back(tempSci);
        }
        inputFile.close();
    }
    return tempV;
}

ostream& operator << (ostream& out, Scientist aScientist) {
    out << aScientist.getFirstName() << endl << aScientist.getLastName() << endl << aScientist.getGender() << endl << aScientist.getBirth() << endl << aScientist.getDeath() << endl;
    return out;
}

void DataLayer::writeFile(vector<Scientist> vScientist) {
    ofstream outputFile;
    outputFile.open ("/Users/Birkir/Desktop/ScientistData.txt", ios::app);
    if(outputFile) {
        outputFile << vScientist[vScientist.size() - 1];
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


