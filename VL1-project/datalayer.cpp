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
    in >> s._name;
    in >> s._gender;
    in >> s._born;
    in >> s._death;
    return in;
}

//Reads the database file
vector<Scientist> DataLayer::readFile() {
    ifstream inputFile;
    inputFile.open ("ScientistData.txt");
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
    out << aScientist.getName() << endl << aScientist.getGender() << endl << aScientist.getBirth() << endl << aScientist.getDeath() << endl;
    return out;
}

//Adds to the database file
void DataLayer::writeFile(vector<Scientist> vScientist) {
    ofstream outputFile;
    outputFile.open ("ScientistData.txt");
    if(outputFile) {
        for(size_t i = 0; i < vScientist.size(); i++) {
            outputFile << vScientist[i] << endl;
        }
    }
    outputFile.close();
}

//Clears the whole database file
void DataLayer::clearFile() {
    ofstream clear;
    clear.open("ScientistData.txt", ios::out | ios::trunc);
    clear.close();
}

