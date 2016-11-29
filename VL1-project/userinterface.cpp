#include <iostream>
#include "userinterface.h"
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

        } else if (command == "list") {
            cout << "How would you like to list the scientists?" << endl;
            cout << "alpha (alphabetically)" << endl;
            cout << "gender (by gender)" << endl;
            cout << "otoy (oldest to youngest)" << endl;
            cout << "ytoo (youngest to oldest)" << endl;

            cin >> listCommand;
            if (listCommand == "aplha") {

            } else if (listCommand == "gender") {

            } else if (listCommand == "otoy") {

            } else if (listCommand == "ytoo") {

            } else {
                cout << "Please enter a valid command!" << endl;
            }
        } else if (command == "search") {

        } else {
            cout << "Please enter a valid command!" << endl;
        }
    } while (command != "q");
}
