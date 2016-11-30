#include <iostream>
#include "userinterface.h"
#include "scientist.h"
#include <string>
#include <vector>

using namespace std;

ostream& operator << (ostream& out, vector<Scientist> sVector)
{
    for(unsigned int i = 0; i < sVector.size(); i++)
    {
        out << "Name: " << sVector[i].getFirstName() << " " << sVector[i].getLastName() << endl;
        out << "Born in " << sVector[i].getBirth();
        if(sVector[i].getDeath() != 0) out << "Died" << sVector[i].getDeath() << endl;
        out << endl;
    }
    return out;
}

UserInterface::UserInterface()
{

}

void UserInterface::run() {
    string command, listCommand;

    do {
        cout << "== Enter one of the following commands: ==" << endl;
        cout << "add" << '\t' << "(to add a scientist)" << endl;
        cout << "list" << '\t' << "(to see the list of scientists)" << endl;
        cout << "search" << '\t' << "(to search in the list of scientists)" << endl;
        cout << "q" << '\t' << "(quit)" << endl;
        cout << "=> Command: ";

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

            cout << "=== Successfully added a scientist ===" << endl << endl;
            Scientist aScientist(fName, lName, gender, born, death);
            service.addScientitst(aScientist);

        } else if (command == "list") {
            cout << endl << "=== In which order? ===" << endl;
            cout << "alpha" << '\t' << '\t' << "(sort alphabetically)" << endl;
            cout << "gender" << '\t' << '\t' << "(sort by gender)" << endl;
            cout << "fromold" << '\t' << '\t' << "(oldest to youngest)" << endl;
            cout << "fromyoung" << '\t' << "(youngest to oldest)" << endl;
            cout << "=> Order: ";

            cin >> listCommand;
            if (listCommand == "alpha") {
                vector<Scientist> vTemp = service.sortAlphabetical();
                printOut(vTemp);
            } else if (listCommand == "gender") {
                vector<Scientist> vTemp = service.sortByGender();
                printOut(vTemp);
            } else if (listCommand == "fromold") {
<<<<<<< Updated upstream
                vector<Scientist> vTemp = service.sortByBirthDescending();
                printOut(vTemp);
            } else if (listCommand == "fromyoung") {
                vector<Scientist> vTemp = service.sortByBirthAscendng();
                printOut(vTemp);
=======
                //vector<Scientist> vTemp = service.sortByBirthDescending()();
                //printOut(vTemp);
            } else if (listCommand == "fromyoung") {
                //vector<Scientist> vTemp = service.sortByBirthAscendng()();
                //printOut(vTemp);
>>>>>>> Stashed changes
            } else {
                cout << "Please enter a valid command!" << endl;
            }
        } else if (command == "search") {
            cout << "Would you like to search by name, year of birth, or year of death?" << endl << "==> command:";
            string inputString;
            cin >> inputString;

            if(inputString == "name" && inputString == "Name");
            {
                string searchString;
                cout << "Enter name for search: ";
                cin >> searchString;
                vector<Scientist> tempVector;
                tempVector = service.search(searchString);
                if(tempVector.size() > 0)
                {
                    cout << tempVector;
                }
                else cout << "Not found";
            }


        } else if (command != "q") {
            cout << "Please enter a valid command!" << endl;
        }
    } while (command != "q");
}

void UserInterface::printOut(vector<Scientist> vScientist) {
    for(size_t i = 0; i < vScientist.size(); i++) {
        cout << endl << "Name: " << vScientist[i].getFirstName() << " " << vScientist[i].getLastName() << endl;
        if(vScientist[i].getGender() == 'm' || vScientist[i].getGender() == 'M') {
            cout << "Gender: Male" << endl;
        } else {
            cout << "Gender: Female" << endl;
        }
        cout << "Year born: " << vScientist[i].getBirth() << endl;
        if(vScientist[i].getDeath() == 0) {
            cout << vScientist[i].getFirstName() << " is still alive." << endl;
        } else {
            cout << "Year of death: " << vScientist[i].getDeath() << endl;
        }
    }
}




