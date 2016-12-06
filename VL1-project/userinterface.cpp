#include <iostream>
#include "userinterface.h"
#include "scientist.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator << (ostream& out, vector<Scientist> vScientist);
void printResault(vector<Scientist> resaultVector);
void enterToContinue();

UserInterface::UserInterface()
{
    
}

void UserInterface::run() {
    string command;
    
    //Program loop
    do {
        //Menu
        cout << "<--- Enter one of the following commands: --->" << endl;
        cout << "add" << '\t' << "(to add a scientist or computer)" << endl;
        cout << "list" << '\t' << "(to see the list of scientists or computers)" << endl;
        cout << "search" << '\t' << "(to search in the list)" << endl;
        cout << "connect" << '\t' << "(to connect scientists and computers)" << endl;
        cout << "clear" << '\t' << "(to clear the list of scientists or computers)" << endl;
        cout << "q" << '\t' << "(quit)" << endl;
        cout << "=> Command: ";

        getline(cin, command);
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);


        // Selection
        if (command == "add") {
            string nextcommand;
            cout << "<--- Which of the following would you like to add? --->" << endl;
            cout << "sci" << '\t' << "(to add a scientist)" << endl;
            cout << "comp" << '\t' << "(to add a computer)" << endl;
            cout << "=> Command: ";
            cin >> nextcommand;
            if(nextcommand == "sci" || nextcommand == "scientist" || nextcommand == "s") {
                addSci();
            } else if(nextcommand == "comp" || nextcommand == "computer" || nextcommand == "c") {
                addComp();
            } else {
                cout << "!--- Not a valid command ---!" << endl << endl;
            }
        } else if (command == "list") {
            list();
        } else if (command == "search") {
            search();
        } else if (command == "clear") {
            clearSci();
        } else if (command != "q") {
            cout << "!--- Please enter a valid command --->" << endl << endl;
        }
    } while (command != "q");

}

//Funcition that adds to the database file
void UserInterface::addSci() {
    string name;
    char gender, stillAlive;
    int born, death;
    cout << "<--- Add a scientist --->" << endl;
    do {
        cout << "Name: ";
        cin >> name;
    } while(name.length() <= 1);
    
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
            cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
        }
    } while (stillAlive != 'Y' && stillAlive != 'y' && stillAlive != 'N' && stillAlive != 'n');
    
    if(stillAlive == 'Y' || stillAlive == 'y') {
        death = 0;
        cin.ignore();
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
    Scientist aScientist(name, gender, born, death);
    service.addScientitst(aScientist);
}

void UserInterface::list() {
    string listCommand, innerCommand;
    do {
        cout << endl << "<--- How would you like to list? --->" << endl;
        cout << "all" << '\t' << "(list everything)" << endl;
        cout << "sci" << '\t' << "(list just the scientists)" << endl;
        cout << "comp" << '\t' << "(list just the computers)" << endl;
        cout << "Command => ";
        cin >> listCommand;
        
        if(listCommand == "all" || listCommand == "a") {
            cout << endl << "<--- All - in which order? --->" << endl;
            cout << "alpha" << '\t' << "(alphabetical order)" << endl;
            cout << "ralpha" << '\t' << "(reversed alphabetical order)" << endl;
            cout << "ascage" << '\t' << "(ascending age order)" << endl;
            cout << "descage" << '\t' << "(descending age order)" << endl;
            cout << "b" << '\t' << "(<< go back)" << endl;
            cout << "Command => ";
            cin >> innerCommand;
            if(innerCommand == "b") {
                listCommand = "back";
            }
        } else if(listCommand == "sci" || listCommand == "scientist" || listCommand == "s") {
            cout << endl << "<--- Scientists - in which order? --->" << endl;
            cout << "alpha" << '\t' << "(alphabetical order)" << endl;
            cout << "ralpha" << '\t' << "(reversed alphabetical order)" << endl;
            cout << "ascage" << '\t' << "(ascending age order)" << endl;
            cout << "descage" << '\t' << "(descending age order)" << endl;
            cout << "male" << '\t' << "(only males)" << endl;
            cout << "female" << '\t' << "(only females)" << endl;
            cout << "b" << '\t' << "(<< go back)" << endl;
            cout << "Command => ";
            cin >> innerCommand;
            if(innerCommand == "b") {
                listCommand = "back";
            }
        } else if(listCommand == "comp" || listCommand == "computer" || listCommand == "c") {
            cout << endl << "<--- Computers - in which order? --->" << endl;
            cout << "alpha" << '\t' << "(alphabetical order)" << endl;
            cout << "ralpha" << '\t' << "(reversed alphabetical order)" << endl;
            cout << "ascage" << '\t' << "(ascending age order)" << endl;
            cout << "descage" << '\t' << "(descending age order)" << endl;
            cout << "made" << '\t' << "(only the ones that were made)" << endl;
            cout << "notmade" << '\t' << "(only the ones that were not made)" << endl;
            cout << "b" << '\t' << "(<< go back)" << endl;
            cout << "Command => ";
            cin >> innerCommand;
            if(innerCommand == "b") {
                listCommand = "back";
            }
        } else if (listCommand != "back") {
            cout << "!--- Not a valid command ---!" << endl;
        }
    } while(listCommand != "all" && listCommand != "a" && listCommand != "s" && listCommand != "sci" && listCommand != "scientist" && listCommand != "c" && listCommand != "comp" && listCommand != "computer");
}

void UserInterface::search() {

}

//Function that clears the database file
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
        cout << "!--- You must only type Y or N ---!" << endl << endl;
    }
}

ostream& operator << (ostream& out, vector<Scientist> vScientist) {
    if(vScientist.size() != 0) {
        for(size_t i = 0; i < vScientist.size(); i++) {
            cout << endl << "Name: " << vScientist[i].getName() << endl;
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
        cout << "!--- There are no scientists on the list ---!" << endl;
    }
    cout << endl;

    return out;
}

void printResault(vector<Scientist> resaultVector) {
    if(resaultVector.size() > 0)
    {
        cout << resaultVector;
    }
    else cout << "Not found" << endl << endl;
}

void enterToContinue() {
    cout << "Press enter/return to continue." << endl;
    cin.ignore();
}

void UserInterface::addComp() {
    string name, type;
    char check;
    bool ifMade = false;
    int yearMade;
    cout << "<--- Add a computer --->" << endl;
    do {
        cout << "Name: ";
        cin >> name;
    } while(name.length() < 1);
    
    do {
        cout << "Type: ";
        cin >> type;
    } while(type.length() < 1);
    
    do {
        cout << "Was it ever made? (y/n) ";
        cin >> check;
        if(check != 'Y' && check != 'y' && check != 'N' && check != 'n') {
            cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
        }
        if(check == 'Y' || check == 'y') {
            ifMade = true;
        } else if(check == 'N' || check == 'n') {
            ifMade = false;
            yearMade = 0;
            cin.ignore();
        }
    } while (check != 'Y' && check != 'y' && check != 'N' && check != 'n');
    
    if(ifMade == true) {
        do {
            cin.clear();
            cin.ignore();
            cout << "Year made: ";
            cin >> yearMade;
            if(cin.fail()) cout << "!--- Please enter a valid year ---!" << endl;
        } while(yearMade <= 0 || yearMade > 2016);
    }
    
    cout << "<--- Successfully added a computer --->" << endl << endl;
    Computer aComputer(ifMade, name, type, yearMade);
    service.addComputer(aComputer);
}





