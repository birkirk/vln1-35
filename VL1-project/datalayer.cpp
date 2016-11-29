#include "datalayer.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

DataLayer::DataLayer()
{
    ifstream inputFile;
    inputFile.open ("ScientistData.txt");
    string newName;
    bool isMale;
    int yearOfBirth;
    int yearOfDeath;

    while(inputFile >> newName)
    {
        inputFile >> isMale;
        inputFile >> yearOfBirth;
        inputFile >> yearOfDeath;
        Scientist newScientist(newName, isMale, yearOfBirth, yearOfDeath);
        dataVector.push_back(newScientist);
    }
    inputFile.close();
}

string DataLayer::addScientist(Scientist newScientist)
{
    bool inputTest = false;
    for(unsigned int i = 0; i < dataVector.size(); i++) if(newScientist.getName() == dataVector[i].getName()) inputTest = true;
    ofstream outputFile;
    outputFile.open ("ScientistData.txt", ios_base::app);
    string returnString;
    if(inputTest == false)
    {
        outputFile << endl << newScientist.getName() << " ";
        outputFile << newScientist.getGender() << " ";
        outputFile << newScientist.getBirth() << " " << newScientist.getDeath();
        returnString = "successful";
    }
    else returnString = "unsuccessful!";
    return returnString;
}


