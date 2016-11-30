#include <iostream>
#include "userinterface.h"
#include "scientist.h"
#include <string>
#include <vector>

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::run() {
    string command, listCommand;

    do {
        cout << "Enter one of the following commands: " << endl;
        cout << "add (to add a scientist)" << endl;
        cout << "list (to see the list of scientists)" << endl;
        cout << "search (to search in the list of scientists)" << endl;
        cout << "q (quit)" << endl;

        cin >> command;

        if (command == "add") {
            string fName;
            string lName;
            char gender, stillAlive;
            int born, death;
            cout << "======= Add a scientist =======" << endl;
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
                cout << "Year of birth: ";
                cin >> born;
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
                    cout << "Year of death: ";
                    cin >> death;
                } while(death > 2016 || death < born);
            }

            Scientist aScientist(fName, lName, gender, born, death);

        } else if (command == "list") {
            cout << "How would you like to list the scientists?" << endl;
            cout << "alpha (sort alphabetically)" << endl;
            cout << "gender (sort by gender)" << endl;
            cout << "fromold (oldest to youngest)" << endl;
            cout << "fromyoung (youngest to oldest)" << endl;

            cin >> listCommand;
            if (listCommand == "alpha") {

            } else if (listCommand == "gender") {

            } else if (listCommand == "fromold") {

            } else if (listCommand == "fromyoung") {

            } else {
                cout << "Please enter a valid command!" << endl;
            }
        } else if (command == "search") {

        } else if (command != "q") {
            cout << "Please enter a valid command!" << endl;
        }
    } while (command != "q");
}
