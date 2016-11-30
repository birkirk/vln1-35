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

void DataLayer::readFile() {
    ifstream inputFile;
    inputFile.open ("ScientistData.txt");
    string fName;
    string lName;
    bool isMale;
    int yearOfBirth;
    int yearOfDeath;
    
    while(inputFile >> fName)
    {
        inputFile >> lName;
        inputFile >> isMale;
        inputFile >> yearOfBirth;
        inputFile >> yearOfDeath;
        Scientist newScientist(fName, lName, isMale, yearOfBirth, yearOfDeath);
        dataVector.push_back(newScientist);
    }
    inputFile.close();
}

void DataLayer::addScientist(Scientist newScientist)
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
}


