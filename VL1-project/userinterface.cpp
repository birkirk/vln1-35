#include <iostream>
#include "userinterface.h"
#include "scientist.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

UserInterface::UserInterface()
{
    
}

void UserInterface::run() {
    string command;
    
    do {
        cout << "<--- Enter one of the following commands: --->" << endl;
        cout << "add" << '\t' << "(to add a scientist or computer)" << endl;
        cout << "list" << '\t' << "(to see the list of scientists or computers)" << endl;
        cout << "search" << '\t' << "(to search in the list)" << endl;
        cout << "connect" << '\t' << "(to connect scientists and computers)" << endl;
        cout << "clear" << '\t' << "(to clear the list of scientists or computers)" << endl;
        cout << "q" << '\t' << "(quit)" << endl;
        cout << "=> Command: ";

        cin >> command;

        if (command == "add") {
            string nextCommand;
            do {
                cout << endl << "<--- Which of the following would you like to add? --->" << endl;
                cout << "sci" << '\t' << "(to add a scientist)" << endl;
                cout << "comp" << '\t' << "(to add a computer)" << endl;
                cout << "c" << '\t' << "(to cancell)" << endl;
                cout << "=> Command: ";
                cin >> nextCommand;
                if(nextCommand == "sci") {
                    addSci();
                } else if(nextCommand == "comp") {
                    addComp();
                } else if(nextCommand != "c") {
                    cout << "!--- Not a valid command ---!" << endl;
                } else if(nextCommand == "c") {
                    cout << endl;
                }
            } while(nextCommand != "sci" && nextCommand != "comp" && nextCommand != "c");
        } else if (command == "list") {
            list();
        } else if (command == "search") {
            search();
        } else if (command == "connect") {
            //connect(); TODO
        } else if (command == "clear") {
            //clear(); TODO
        } else if (command != "q") {
            cout << "!--- Please enter a valid command ---!" << endl << endl;
        }
    } while (command != "q");

}

void UserInterface::addSci() {
    string name;
    char gender, stillAlive;
    int born, death;
    cout << endl << "<--- Add a scientist --->" << endl;
    
    do {
        cin.clear();
        cin.ignore();
        cout << "Name: ";
        cin >> name;
        if(name.length() == 0) {
            cout << "!--- Must enter a name ---!" << endl;
        }
    } while(name.length() <= 1);
    
    do {
        cin.clear();
        cin.ignore();
        cout << "Gender (M/F): ";
        cin >> gender;
        if(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
            cout << "!--- You can only enter 'M' or 'F' ---!" << endl;
        }
    } while(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f');
    
    do {
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> born;
        if(born <= 0 || born > 2016 || cin.fail()) {
            cout << "!--- Please enter a valid year ---!" << endl;
        }
    } while(born <= 0 || born > 2016);
    
    do {
        cin.clear();
        cin.ignore();
        cout << "Is he/her still alive? (y/n) ";
        cin >> stillAlive;
        if(stillAlive != 'Y' && stillAlive != 'y' && stillAlive != 'N' && stillAlive != 'n' && !cin.fail()) {
            cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
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
            if(death > 2016 || death < born || cin.fail()) {
                cout << "!--- Please enter a valid year ---!" << endl;
            }
        } while(death > 2016 || death < born);
        
        
    }
    
    cout << "<--- Trying to add scientist... --->" << endl << endl;
    Scientist aScientist(name, gender, born, death);
    _service.addScientitst(aScientist);
}

void UserInterface::addComp() {
    string name, type;
    char check;
    bool ifMade = false;
    int yearMade;
    cout << "<--- Add a computer --->" << endl;
    do {
        cin.clear();
        cin.ignore();
        cout << "Name: ";
        cin >> name;
        if(name.length() < 1) {
            cout << "!--- Please enter a valid name ---!" << endl;
        }
    } while(name.length() < 1);
    
    do {
        cin.clear();
        cin.ignore();
        cout << "Type: ";
        cin >> type;
        if(type.length() < 1 || cin.fail()) {
            cout << "!--- Please enter a valid type ---!" << endl;
        }
    } while(type.length() < 1);
    
    do {
        cin.clear();
        cin.ignore();
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
            cin.clear();
            cin.ignore();
        }
    } while (check != 'Y' && check != 'y' && check != 'N' && check != 'n');
    
    if(ifMade == true) {
        do {
            cin.clear();
            cin.ignore();
            cout << "Year made: ";
            cin >> yearMade;
            if(yearMade <= 0 || yearMade > 2016) {
                cout << "!--- Please enter a valid year ---!" << endl;
            }
        } while(yearMade <= 0 || yearMade > 2016);
    }
    
    cout << "<--- Trying to add computer... --->" << endl << endl;
    Computer aComputer(ifMade, name, type, yearMade);
    _service.addComputer(aComputer);
}

void UserInterface::list() {
    string listCommand, innerCommand;
    do {
        cout << endl << "<--- How would you like to list? --->" << endl;
        cout << "all" << '\t' << "(list everything)" << endl;
        cout << "sci" << '\t' << "(list just the scientists)" << endl;
        cout << "comp" << '\t' << "(list just the computers)" << endl;
        cout << "b" << '\t' << "(<< go back)" << endl;
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
        } else if (listCommand != "back" && listCommand != "b") {
            cout << "!--- Not a valid command ---!" << endl;
        } else if (listCommand != "b") {
            cout << endl;
        }
    } while(listCommand != "all" && listCommand != "a" && listCommand != "s" && listCommand != "sci" && listCommand != "scientist" && listCommand != "c" && listCommand != "comp" && listCommand != "computer" && listCommand != "b");
}

void UserInterface::search() {

}





