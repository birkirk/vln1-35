#include <iostream>
#include "userinterface.h"
#include "scientist.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator << (ostream& out, vector<Scientist> vScientist);
void printResault(vector<Scientist> resaultVector);
void askContinue();

UserInterface::UserInterface()
{

}

void UserInterface::run() {
    string command, listCommand;
    
    do {
        
        cout << "<--- Enter one of the following commands: --->" << endl;
        cout << "add" << '\t' << "(to add a scientist)" << endl;
        cout << "list" << '\t' << "(to see the list of scientists)" << endl;
        cout << "search" << '\t' << "(to search in the list of scientists)" << endl;
        cout << "clear" << '\t' << "(to clear the list of scientists)" << endl;
        cout << "q" << '\t' << "(quit)" << endl;
        cout << "=> Command: ";

        getline(cin, command);
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);



        if (command == "add") {
            addSci();
        } else if (command == "list") {
            listSci(listCommand);
        } else if (command == "search") {
            searchSci();
        } else if (command == "clear") {
            clearSci();
        } else if (command != "q") {
            cout << "!--- Please enter a valid command --->" << endl << endl;
        }
    } while (command != "q");

}
/*
void UserInterface::editSci(){

}*/

void UserInterface::addSci() {
    string fName;
    string lName;
    char gender, stillAlive;
    int born, death;
    cout << "<--- Add a scientist --->" << endl;
    do {
        cout << "First name: ";
        cin >> fName;
    } while(fName.length() <= 1);
    
    do {
        cout << "Last name: ";
        cin >> lName;
    } while(fName.length() <= 1);
    
    do {
        cout << "Gender (M/F): ";
        cin >> gender;
    } while(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f');
    
    do {
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> born;
        if(cin.fail()) cout << "!--- Please enter a valid year ---!" << endl;
        
    } while(born <= 0 || born > 2016);
    
    do {
        cout << "Is he/her still alive? (y/n) ";
        cin >> stillAlive;
        if(stillAlive != 'Y' && stillAlive != 'y' && stillAlive != 'N' && stillAlive != 'n') {
            cout << "You can only enter 'y' or 'n' " << endl;
        }
    } while (stillAlive != 'Y' && stillAlive != 'y' && stillAlive != 'N' && stillAlive != 'n');
    
    if(stillAlive == 'Y' || stillAlive == 'y') {
        death = 0;
    } else {
        do {
            cin.clear();
            cin.ignore();
            cout << "Year of death: ";
            cin >> death;
            cin.ignore();
            if(cin.fail()) cout << "!--- Please enter a valid year ---!" << endl << endl;
        } while(death > 2016 || death < born);
        
        
    }
    
    cout << "<--- Successfully added a scientist --->" << endl << endl;
    Scientist aScientist(fName, lName, gender, born, death);
    service.addScientitst(aScientist);
}

void UserInterface::listSci(string listCommand) {
    cout << endl << "<--- In which order? --->" << endl;
    cout << "alpha" << '\t' << '\t' << "(sort alphabetically)" << endl;
    cout << "rAlpha" << '\t' << '\t' << "(sort in reverse alphabetical order)" << endl;
    cout << "gender" << '\t' << '\t' << "(sort by gender)" << endl;
    cout << "fromold" << '\t' << '\t' << "(oldest to youngest)" << endl;
    cout << "fromyoung" << '\t' << "(youngest to oldest)" << endl;
    cout << "=> Order: ";
    
    cin >> listCommand;
    cin.ignore();
    if (listCommand == "alpha") {
        vector<Scientist> vTemp = service.sortAlphabetical();
        cout << vTemp;
    }else if (listCommand == "ralpha" || listCommand == "reverse" || listCommand == "reverse alphabetical"){
        vector<Scientist> vTemp = service.sortReverseAlphabetical();
        cout << vTemp;
    } else if (listCommand == "gender") {
        char choice;
        cout << "<--- Type m for males first or f for females first --->" << endl << "==> ";
        cin >> choice;
        cin.ignore();
        if(choice == 'm' || choice == 'M') {
            vector<Scientist> vTemp = service.sortByMaleFemale();
            cout << vTemp;
        } else if(choice == 'f' || choice == 'F') {
            vector<Scientist> vTemp = service.sortByFemaleMale();
            cout << vTemp;
        } else {
            cout << "!--- You must only type M or F ---!" << endl;
        }
        
    } else if (listCommand == "fromold") {
        vector<Scientist> vTemp = service.sortByBirthAscending();
        cout << vTemp;
    } else if (listCommand == "fromyoung") {
        vector<Scientist> vTemp = service.sortByBirthDescending();
        cout << vTemp;
    } else {
        cout << "!--- Please enter a valid command ---!" << endl << endl;
    }
}

void UserInterface::searchSci() {
    cout << "Would you like to search by name, year of birth, or year of death?" << endl << "=> command: ";
    string inputString;
    getline(cin, inputString);
    std::transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
    
    if(inputString == "name")
    {
        string searchString;
        cout << "Enter name: ";
        cin >> searchString;
        vector<Scientist> tempVector;
        tempVector = service.searchByName(searchString);
        printResault(tempVector);
        askContinue();
    }
    else if(inputString == "birth" || inputString == "year of birth" || inputString == "yearofbirth")
    {
        int searchString;
        cout << "Enter year: ";
        cin >> searchString;
        vector<Scientist> tempVector = service.searchByBirth(searchString);
        printResault(tempVector);
        askContinue();
    }
    else if(inputString == "death" || inputString == "year of death" || inputString == "yearofdeath")
    {
        int searchString;
        cout << "Enter year: ";
        cin >> searchString;
        vector<Scientist> tempVector = service.searchByDeath(searchString);
        printResault(tempVector);
        askContinue();
    }
}

void UserInterface::clearSci() {
    char answer;
    cout << "<--- Are you sure you want to clear all? (y/n) --->" << endl << "==> ";
    cin >> answer;
    cin.ignore();
    if(answer == 'y' || answer == 'Y') {
        service.clearAll();
        cout << "<--- Successfully cleared list --->" << endl << endl;
    } else if(answer == 'n' || answer == 'N') {
        cout << "<--- Clear cancelled --->" << endl << endl;
    } else {
        cout << "!--- You must only type M or F ---!" << endl << endl;
    }
}

ostream& operator << (ostream& out, vector<Scientist> vScientist)
{
    if(vScientist.size() != 0) {
        for(size_t i = 0; i < vScientist.size(); i++) {
            cout << endl << "Name: " << vScientist[i].getFirstName() << " " << vScientist[i].getLastName() << endl;
            if(vScientist[i].getGender() == 'm' || vScientist[i].getGender() == 'M') {
                cout << "Gender: Male" << endl;
            } else {
                cout << "Gender: Female" << endl;
            }
            cout << "Year born: " << vScientist[i].getBirth() << endl;
            if(vScientist[i].getDeath() == 0) {
                cout << "Year of death: ?" << endl;
            } else {
                cout << "Year of death: " << vScientist[i].getDeath() << endl;
            }
        }
    } else {
        cout << "!--- There are no scientist on the list ---!" << endl;
    }
    cout << endl;

    return out;
}

void printResault(vector<Scientist> resaultVector)
{
    if(resaultVector.size() > 0)
    {
        cout << resaultVector;
    }
    else cout << "Not found" << endl << endl;
}

void askContinue()
{
    char cont;
    do
    {
        cout << "Press y when ready to continue: " << endl;
        cin >> cont;
        cin.ignore();
    } while(cont != 'Y' && cont != 'y');
    cout << endl;
}







