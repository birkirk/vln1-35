#include <iostream>
#include "userinterface.h"
#include "const.h"
#include "scientist.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;

ostream& operator << (ostream& out, vector<Scientist> vScientist)
{
    if(vScientist.size() != 0)
    {
        cout << "Nr."<< '\t' << "Name" << '\t' << '\t' << '\t' << "Gender" << '\t' << '\t' << "Born" << '\t' << '\t'  << "Died" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        for(size_t i = 0; i < vScientist.size(); i++)
        {
            string name = vScientist[i].getName();
            char gender = vScientist[i].getGender();
            int born = vScientist[i].getBirth();
            int died = vScientist[i].getDeath();
            string sGender;

            //check how many tabs is best to use after name:
            out << " " << i+1 << '\t';
            if(name.length() < firstTabLimit)
            {
                out << name << '\t' << '\t' << '\t';
            }
            else if(name.length() >= firstTabLimit && name.length() < secondTabLimit)
            {
                out << name << '\t' << '\t';
            }
            else
            {
                out << name << '\t';
            }

            if(gender == 'm' || gender == 'M')
            {
                sGender = "Male";
            }
            else if(gender == 'f' || gender == 'F')
            {
                sGender = "Female";
            }
            out << sGender << '\t' << '\t' << born << '\t' << '\t';

            if(died == yearsIfAlive)
            {
                out << '?' << endl;
            }
            else
            {
                out << died << endl;
            }
        }
    }
    else
    {
        cout << "!--- There are no such scientists in the database ---!" << endl;
    }
    cout << endl;

    return out;
}

ostream& operator << (ostream& out, vector<Computer> vComputers)
{
    if(vComputers.size() != 0)
    {
        cout << "Nr."<< '\t' << "Name" << '\t' << '\t' << '\t' << "Type" << '\t' << '\t' << "If Made" << '\t' << '\t'  << "Year Made" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        for(size_t i = 0; i < vComputers.size(); i++)
        {
            string name = vComputers[i].getName();
            bool made = vComputers[i].getIfMade();
            int yearMade = vComputers[i].getYearMade();
            string type = vComputers[i].getType();

            out << " " << i+1 << '\t';

            //check how many tabs is best to use after name:
            if(name.length() < firstTabLimit)
            {
                out << name << '\t' << '\t' << '\t';
            }
            else if(name.length() >= firstTabLimit && name.length() < firstTabLimit)
            {
                out << name << '\t' << '\t';
            }
            else
            {
                out << name << '\t';
            }

            if(type.length() < firstTabLimit)
            {
                out << type << '\t' << '\t';
            }
            else
            {
                out << type << 't';
            }
            if(made)
            {
                out << "Yes" << '\t' << '\t' << yearMade << endl;
            }
            else
            {
                out << "No" << '\t' << '\t' << "----" << endl;
            }
        }
    }
    else
    {
        cout << "!--- There are no such computers in the database ---!" << endl;
    }
    cout << endl;

    return out;
}

UserInterface::UserInterface()
{

}

void UserInterface::run()
{
    string command;

    do
    {
        cout << "<--- Enter one of the following commands --->" << endl;
        cout << '\t' << "add" << '\t' << '\t' << "(to add a scientist or computer)" << endl;
        cout << '\t' << "delete" << '\t' << '\t' << "(to delete a scientist or computer)" << endl;
        cout << '\t' << "list" << '\t' << '\t' << "(to see the list of scientists or computers)" << endl;
        cout << '\t' << "search" << '\t' << '\t' << "(to search in the list)" << endl;
        cout << '\t' << "connect" << '\t' << '\t' << "(to connect scientists and computers)" << endl;
        cout << '\t' << "clear" << '\t' << '\t' << "(to empty the entire database)" << endl;
        cout << '\t' << "recycle" << '\t' << '\t' << "(to access deleted data)" << endl;
        cout << '\t' << "joke" << '\t' << '\t' << "(Homo sapiens need to laugh for at least 17 minutes per day)" << endl;
        cout << '\t' << "manual" << '\t' << '\t' << "(to display 'readme.txt')" << endl;
        cout << '\t' << "q" << '\t' << '\t' << "(quit)" << endl;
        cout << "=> Command: ";
        cin >> command;

        if (command == "add")
        {
            string nextCommand;
            do
            {
                cout << endl << "<--- Which of the following would you like to add? --->" << endl;
                cout << '\t' << "sci" << '\t' << "(to add a scientist)" << endl;
                cout << '\t' << "comp" << '\t' << "(to add a computer)" << endl;
                cout << '\t' << "c" << '\t' << "(to cancel)" << endl;
                cout << "=> Command: ";
                cin >> nextCommand;
                if(nextCommand == "sci")
                {
                    addSci();
                }
                else if(nextCommand == "comp")
                {
                    addComp();
                }
                else if(nextCommand != "c")
                {
                    cout << "!--- Not a valid command ---!" << endl;
                }
                else if(nextCommand == "c")
                {
                    cout << endl;
                }
            } while(nextCommand != "sci" && nextCommand != "comp" && nextCommand != "c");
        }
        else if (command == "recycle" || command == "rec")
        {
            do
            {
                cout << "<--- What would you like to retrieve? --->" << endl;
                cout << '\t' << "sci" << '\t' << "(to retrieve a scientist from the recycle bin.)" << endl;
                cout << '\t' << "comp" << '\t' << "(to retrieve a computer from the recycle bin.)" << endl;
                cout << "=> Command: ";
                cin.ignore();
                getline(cin, command);
                if(command == "sci")
                {
                    vector<Scientist> deletedSci = _service.getDeletedSci();
                    cout << deletedSci << endl;
                    cout << deletedSci.size();
                    cout << "<--- Select Scientist --->" << endl;
                    string innerCommand;
                    getline(cin, innerCommand);
                    int iChoice = atoi(innerCommand.c_str());
                    while(iChoice < 0 || iChoice > deletedSci.size() || iChoice == 0)
                    {
                        cout << "Invalid input, try again!: ";
                        getline(cin, innerCommand);
                        iChoice = atoi(innerCommand.c_str());
                    }
                    cout << "<--- Retrieving scientist! --->";
                    _service.recycleSci(deletedSci[iChoice-1]);


                }
                else if(command == "comp")
                {
                    vector<Computer> deletedComp = _service.getDeletedComp();
                    cout << deletedComp << endl;

                    cout << "<--- Select Scientist --->" << endl;
                    string innerCommand;
                    getline(cin, innerCommand);
                    int iChoice = atoi(innerCommand.c_str());
                    while(iChoice < 0 || iChoice > deletedComp.size() || iChoice == 0)
                    {
                        cout << "Invalid input, try again!: ";
                        getline(cin, innerCommand);
                        iChoice = atoi(innerCommand.c_str());
                    }
                    cout << "<--- Retrieving computer! --->";
                    _service.recycleComp(deletedComp[iChoice-1]);
                }
            } while(command != "sci" && command != "comp" && command != "c");
        }
        else if (command == "delete" || command == "del")
        {
            deleteSom();
        }
        else if (command == "list")
        {
            list();
        }
        else if (command == "search")
        {
            do
            {
                cin.ignore();
                cin.clear();
                cout << endl << "<--- What would you like to search for? --->" << endl;
                cout << '\t' << "sci" << '\t' << "(to search in Scientists database)" << endl;
                cout << '\t' << "comp" << '\t' << "(to search in Computers database)" << endl;
                cout << '\t' << "c" << '\t' << "(to cancel)" << endl;
                cout << "=> Command: ";
                cin >> command;
                if(command == "sci")
                {
                    vector<Scientist> printVector = searchScientist();
                    cout << printVector;
                }
                else if(command == "comp")
                {
                    vector<Computer> printVector = searchComputer();
                    cout << printVector;
                }
                else if(command != "c")
                {
                    cout << "!--- Not a valid command ---!" << endl;
                }
                else if(command == "c")
                {
                    cout << endl;
                }
            } while(command != "sci" && command != "comp" && command != "c");

        }
        else if (command == "connect")
        {
            connect();
        }
        else if (command == "clear")
        {
            clear();
        }
        //Easter Egg command
        else if (command == "joke")
        {
            generateJoke();
        }
        //Hidden command
        else if (command == "info")
        {
            info();
        }
        else if (command == "manual")
        {
            readMe();
        }
        else if (command != "manual" && command != "q" && command != "add" && command != "list" && command != "delete" && command != "connect" && command != "search" && command != "clear" && command != "joke")
        {
            cout << "!--- Please enter a valid command ---!" << endl << endl;
        }
        else if (command == "q")
        {
            bool ifClosed = _service.closeData();
            if(ifClosed)
            {
                cout << endl << "Successfully closed the database!" << endl << endl;
            }
            else
            {
                cout << endl << "Error, can't close something that isn't open!" << endl << endl;
            }
        }
    } while (command != "q");

}

void UserInterface::addSci()
{
    string name, sGender, sStillAlive;
    char gender, stillAlive;
    int born, death;
    cout << endl << endl << "<--- Add a scientist --->" << endl;

    do
    {
        cin.ignore();
        cin.clear();
        cout << "Name: ";
        getline(cin, name);
        name[0] = toupper(name[0]);
        if(name.length() == 0)
        {
            cout << "!--- Must enter a name ---!" << endl;
        }
    } while(name.length() <= 1);

    do
    {
        cin.clear();
        cout << "Gender (M/F): ";
        cin >> sGender;
        if(sGender != "M" && sGender != "m" && sGender != "F" && sGender != "f")
        {
            cout << "!--- You can only enter 'M' or 'F' ---!" << endl;
        }
    } while(sGender != "M" && sGender != "m" && sGender != "F" && sGender != "f");
    gender = sGender.at(0);

    do
    {
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> born;
        if(born <= 0 || born > currentYear || cin.fail())
        {
            cout << "!--- Please enter a valid year ---!" << endl;
        }
    } while(born <= 0 || born > currentYear);

    do
    {
        cin.clear();
        cin.ignore();
        cout << "Is he/she still alive? (y/n) ";
        cin >> sStillAlive;
        if(sStillAlive != "Y" && sStillAlive != "y" && sStillAlive != "N" && sStillAlive != "n" && !cin.fail())
        {
            cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
        }
    } while (sStillAlive != "Y" && sStillAlive != "y" && sStillAlive != "N" && sStillAlive != "n");
    stillAlive = sStillAlive.at(0);

    if(stillAlive == 'Y' || stillAlive == 'y')
    {
        //has to be high so that list be death is correct, const are in const.h
        death = yearsIfAlive;
    }
    else
    {
        do
        {
            cin.clear();
            cin.ignore();
            cout << "Year of death: ";
            cin >> death;
            if(death > currentYear || death < born || cin.fail())
            {
                cout << "!--- Please enter a valid year ---!" << endl;
            }
        } while(death > currentYear || death < born);
    }

    cout << endl << "<--- Trying to add scientist... --->" << endl;
    Scientist aScientist(name, gender, born, death);
    bool ifSuccess = _service.addScientitst(aScientist);
    if(ifSuccess)
    {
        cout << "<--- Scientist successfully added! --->" << endl << endl;
    }
    else
    {
        cout << "!--- Scientist could not be added - Already exists in database ---!" << endl << endl;
    }
}

void UserInterface::addComp()
{
    string name, type;
    char check;
    bool ifMade = false;
    int yearMade;
    cout << endl << endl << "<--- Add a computer --->" << endl;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        name[0] = toupper(name[0]);
        if(name.length() < 1)
        {
            cout << "!--- Please enter a valid name ---!" << endl;
        }
    } while(name.length() < 1);

    bool overTest = false;
    do
    {
        cout << "What kind of a computer is it?" << endl;
        vector<string> vTypes = _service.getTypes();
        for(unsigned int i = 0; i < vTypes.size(); i++)
        {
            cout << i+1 << '\t' << vTypes[i] << endl;
        }
        cout << "Enter 'a' to add a new type." << endl;
        cout << "Type: ";
        string choice;
        getline(cin, choice);
        if(choice != "a" && choice != "A")
        {
            int iChoice = atoi(choice.c_str());
            if(iChoice != 0 && iChoice > 0 && iChoice <= vTypes.size())
            {
                type = vTypes[iChoice-1];
                overTest = true;
            }
        }
        else if(choice == "a" || choice == "A")
        {
            overTest = true;
            cin.clear();
            cout << "Enter new type: ";
            getline(cin, type);
            type[0] = toupper(type[0]);
            bool existTest = false;
            for(unsigned int i = 0; i < vTypes.size(); i++)
            {
                string compare1 = type;
                transform(compare1.begin(), compare1.end(), compare1.begin(), ::tolower);
                string compare2 = vTypes[i];
                transform(compare2.begin(), compare2.end(), compare2.begin(), ::tolower);
                if(compare1 == compare2) existTest = true;
            }
            if(existTest)
            {
                overTest = false;
                cout << "!--- Type already exists ---!" << endl;
            }


            if(overTest == true)
            {
                _service.addType(type);
                cout << "<--- Adding computer type" << type << "... --->" << endl;
            }
            else
            {
                cout << "!--- Invalid input ---!" << endl << endl;
            }
        }
        else cout << "!--- Invalid input ---!" << endl << endl;
    } while(!overTest);

    do
    {
        cin.clear();
        cout << "Was it ever made? (y/n) :";
        cin >> check;
        if(check != 'Y' && check != 'y' && check != 'N' && check != 'n')
        {
            cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
        }
        if(check == 'Y' || check == 'y')
        {
            ifMade = true;
        }
        else if(check == 'N' || check == 'n')
        {
            ifMade = false;
            yearMade = 0;
            cin.clear();
            cin.ignore();
        }
    } while (check != 'Y' && check != 'y' && check != 'N' && check != 'n');

    if(ifMade == true)
    {
        do
        {
            cin.clear();
            cin.ignore();
            cout << "Year made: ";
            cin >> yearMade;
            if(yearMade <= 0 || yearMade > currentYear)
            {
                cout << "!--- Please enter a valid year ---!" << endl;
            }
        } while(yearMade <= 0 || yearMade > currentYear);
    }

    cout << endl << "<--- Trying to add computer... --->" << endl;
    Computer aComputer(ifMade, name, type, yearMade);
    bool ifSuccess = _service.addComputer(aComputer);
    if(ifSuccess)
    {
        cout << "<--- Computer successfully added! --->" << endl << endl;
    }
    else
    {
        cout << "!--- Computer could not be added - Already exists in database ---!" << endl << endl;
    }
}

void UserInterface::list()
{
    string listCommand, innerCommand;
    do
    {
        cin.clear();
        cin.ignore();

        cout << endl << "<--- What would you like to see a list of? --->" << endl;
        cout << '\t' << "sci" << '\t' << "(list of just the scientists)" << endl;
        cout << '\t' << "comp" << '\t' << "(list of just the computers)" << endl;
        cout << '\t' << "con" << '\t' << "(list of the connections between scientists and computers)" << endl;
        cout << '\t' << "c" << '\t' << "(cancel)" << endl;
        cout << "=> Command: ";
        cin >> listCommand;

        if(listCommand == "sci")
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout << endl << "<--- Scientists - in which order? --->" << endl;
                cout << '\t' << "1." << '\t' << "(alphabetical order)" << endl;
                cout << '\t' << "2." << '\t' << "(reversed alphabetical order)" << endl;
                cout << '\t' << "3." << '\t' << "(ascending age order)" << endl;
                cout << '\t' << "4." << '\t' << "(descending age order)" << endl;
                cout << '\t' << "5." << '\t' << "(ascending death year order)" << endl;
                cout << '\t' << "6." << '\t' << "(descending death year order)" << endl;
                cout << '\t' << "b"  << '\t' << "(go back)" << endl;
                cout << "=> Command: ";
                cin >> innerCommand;

                if(innerCommand != "1" && innerCommand != "2" && innerCommand != "3" && innerCommand != "4" && innerCommand != "5" && innerCommand != "6" && innerCommand != "b")
                {
                    cout << "!--- Please enter a valid command ---!" << endl;
                }
                else if(innerCommand == "b")
                {
                    cout << endl;
                }
                else if(innerCommand == "1")
                {
                    vector<Scientist> vUse = _service.sciAlpha();
                    cout << "<--- Scientists in alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "2")
                {
                    vector<Scientist> vUse = _service.sciRalpha();
                    cout << "<--- Scientists in reversed alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "3")
                {
                    vector<Scientist> vUse = _service.sciAgeAsc();
                    cout << "<--- Scientists in age ascending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "4")
                {
                    vector<Scientist> vUse = _service.sciAgeDesc();
                    cout << "<--- Scientists in age descending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "5")
                {
                    vector<Scientist> vUse = _service.sciDeathAsc();
                    cout << "<--- Scientists in death ascending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "6")
                {
                    vector<Scientist> vUse = _service.sciDeathDesc();
                    cout << "<--- Scientists in death descending order --->" << endl << endl;
                    cout << vUse;
                }
            } while(innerCommand != "1" && innerCommand != "2" && innerCommand != "3" && innerCommand != "4" && innerCommand != "5" && innerCommand != "6" && innerCommand != "b");
        }
        else if(listCommand == "comp")
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout << endl << "<--- Computers - in which order? --->" << endl;
                cout << '\t' << "1." << '\t' << "(alphabetical order)" << endl;
                cout << '\t' << "2." << '\t' << "(reversed alphabetical order)" << endl;
                cout << '\t' << "3." << '\t' << "(ascending age order)" << endl;
                cout << '\t' << "4." << '\t' << "(descending age order)" << endl;
                cout << '\t' << "5." << '\t' << "(only the ones that were made)" << endl;
                cout << '\t' << "6." << '\t' << "(only the ones that were not made)" << endl;
                cout << '\t' << "7." << '\t' << "(by type)" << endl;
                cout << '\t' << "b" << '\t' << "(go back)" << endl;
                cout << "=> Command: ";
                cin >> innerCommand;

                if(innerCommand != "1" && innerCommand != "2" && innerCommand != "3" && innerCommand != "4" && innerCommand != "5" && innerCommand != "6" && innerCommand != "7" && innerCommand != "b")
                {
                    cout << "!--- Please enter a valid command ---!" << endl;
                }
                else if(innerCommand == "b")
                {
                    cout << endl;
                }
                else if(innerCommand == "1")
                {
                    vector<Computer> vUse = _service.compAlpha();
                    cout << "<--- Computers in alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "2")
                {
                    vector<Computer> vUse = _service.compRalpha();
                    cout << "<--- Computers in reversed alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "3")
                {
                    vector<Computer> vUse = _service.compAgeAsc();
                    cout << "<--- Computers in age ascending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "4")
                {
                    vector<Computer> vUse = _service.compAgeDesc();
                    cout << "<--- Computers in age descending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "5")
                {
                    vector<Computer> vUse = _service.compMade();
                    cout << "<--- Computers that were made --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "6")
                {
                    vector<Computer> vUse = _service.compNotMade();
                    cout << "<--- Computers that were not made --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "7")
                {
                    vector<Computer> vUse = _service.compType();
                    cout << "<--- Computers in type order --->" << endl << endl;
                    cout << vUse;
                }
            } while(innerCommand != "1" && innerCommand != "2" && innerCommand != "3" && innerCommand != "4" && innerCommand != "5" && innerCommand != "6" && innerCommand != "7" && innerCommand != "b");
        }
        else if(listCommand == "con")
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout << endl << "<--- Connections - in which order? --->" << endl;
                cout << '\t' << "1." << '\t' << "(scientist/s connected to computers)" << endl;
                cout << '\t' << "2." << '\t' << "(computer/s connected to scientits)" << endl;
                cout << '\t' << "b" << '\t' << "(go back)" << endl;
                cout << "=> Command: ";
                cin >> innerCommand;

                if(innerCommand != "1" && innerCommand != "2" && innerCommand != "b")
                {
                    cout << "!--- Please enter a valid command ---!" << endl;
                }
                else if(innerCommand == "b")
                {
                    cout << endl;
                }
                else if(innerCommand == "1" || innerCommand == "sciToComp")
                {
                    printSciToComp();
                }
                else if(innerCommand == "2" || innerCommand == "compToSci")
                {
                    printCompToSci();

                }
            } while(innerCommand != "1" && innerCommand != "2" && innerCommand != "b");
        }
        else if (listCommand != "all" && listCommand != "sci" && listCommand != "con" && listCommand != "comp" && listCommand != "b"  && listCommand != "c")
        {
            cout << "!--- Please enter a valid command ---!" << endl;
        }
        else if (listCommand == "c")
        {
            cout << endl;
        }
    } while(listCommand != "all" && listCommand != "sci" && listCommand != "comp" && listCommand != "con" && listCommand != "b"  && listCommand != "c");
}

vector<Scientist> UserInterface::searchScientist()
{

        string name, sGender, sStillAlive, born, death = "";
        char gender, stillAlive;
        cout << endl << "<--- Please enter information (it is OK to leave empty) --->" << endl;

        //Get name
        cin.ignore();
        cin.clear();
        cout << "Name: ";
        getline(cin, name);
        name[0] = toupper(name[0]);
        if(name.size() == 0)
        {
            name = "";
        }

        do
        {
            cin.clear();
            cout << "Gender (M/F): ";
            getline(cin, sGender);
            if(sGender != "M" && sGender != "m" && sGender != "F" && sGender != "f" && sGender != "")
            {
                cout << "!--- You can only enter 'M' or 'F' ---!" << endl;
            }
        } while(sGender != "M" && sGender != "m" && sGender != "F" && sGender != "f" && sGender != "");
        if(sGender != "")
        {
            gender = sGender.at(0);
        }
        else
        {
            gender = 'O';
        }

        //Get birth year
        cin.clear();
        cout << "Year of birth: ";

        getline(cin, born);
        if(born.length() == 0)
        {
            born = "";
        }

        do
        {
            cin.clear();
            cout << "Is he/she still alive? (y/n) ";
            getline(cin, sStillAlive);
            if(sStillAlive != "Y" && sStillAlive != "y" && sStillAlive != "N" && sStillAlive != "" && sStillAlive != "n" && !cin.fail())
            {
                cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
            }
        } while (sStillAlive != "Y" && sStillAlive != "y" && sStillAlive != "N" && sStillAlive != "n" && sStillAlive != "");
        if(sStillAlive != "")
        {
            stillAlive = sStillAlive.at(0);
        }
        else
        {
            stillAlive = 'O';
        }

        if(stillAlive == 'Y' || stillAlive == 'y')
        {
            //has to be high so that list by death is correct
            death = yearsIfAlive;
        }
        else
        {
            cin.clear();
            cout << "Year of death: ";

            getline(cin, death);
            if(death.length() == 0)
            {
                death = "";
            }
        }

        cout << "<--- Searching... --->" << endl << endl;

        //If something is skipped than sends: "", 'O', NULL, NULL;
        vector<Scientist> vSci = _service.searchSci(name, gender, born, death);
        return vSci;


}

vector<Computer> UserInterface::searchComputer()
{
        string name, type, yearMade, ifMade, check;
        cout << endl << "<--- Please enter information (it is OK to leave empty) --->" << endl;

        //Get name
        cin.clear();
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        name[0] = toupper(name[0]);
        if(name.length() == 0)
        {
            name = "";
        }

        //Get type
        cin.clear();
        cout << "Type: ";
        getline(cin, type);
        type[0] = toupper(type[0]);
        if(type.length() == 0)
        {
            type = "";
        }

        do
        {
            cin.clear();
            cout << "Was it ever made? (y/n) ";
            getline(cin, check);
            if(check != "Y" && check != "y" && check != "N" && check != "n" && check != "")
            {
                cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
            }
            if(check == "Y" || check == "y")
            {
                ifMade = "1";
            }
            else if(check == "N" || check == "n")
            {
                ifMade = "0";
                yearMade = "";
                cin.clear();
            }
        } while (check != "Y" && check != "y" && check != "N" && check != "n" && check != "");

        if(ifMade == "1")
        {
            cin.clear();
            cout << "Year made: ";
            getline(cin, yearMade);
            if(yearMade.length() == 0)
            {
                yearMade = "";
            }
        }

        cout << "<--- Searching... --->" << endl << endl;
        vector<Computer> aComputer = _service.searchComp(ifMade, name, type, yearMade);
        return aComputer;
}


void UserInterface::generateJoke()
{
    int random = rand() % 10;
    cout << endl;
    for(int i = 1; i <= 10; i++)
    {
        if(i == 1)
        {
            cout << "Generating..." << '\t';
        }
        cout << "///";
        if(i == 10)
        {
            cout << "100%";
        }
        usleep(200000);
    }
    cout << endl;

    if(random == 0)
    {
        cout << endl << "Can a kangaroo jump higher than a house? Of course, a house doesn't jump at all." << endl << endl;
    }
    else if(random == 1)
    {
        cout << endl << "I used to think the brain was the most important organ. Then I thought, look what's telling me that" << endl << endl;
    }
    else if(random == 2)
    {
        cout << endl << "What is Bruce Lee's favorite drink? Wataaaaah!" << endl << endl;
    }
    else if(random == 3)
    {
        cout << endl << "If you want to catch a squirrel just climb a tree and act like a nut." << endl << endl;
    }
    else if(random == 4)
    {
        cout << endl << "A magician was walking down the street and turned into a grocery store." << endl << endl;
    }
    else if(random == 5)
    {
        cout << endl << "Did you hear about the Mexican train killer? He had locomotives." << endl << endl;
    }
    else if(random == 6)
    {
        cout << endl << "What time is it when you have to go to the dentist? Tooth-hurtie." << endl << endl;
    }
    else if(random == 7)
    {
        cout << endl << "What did Jay-Z call his girlfriend before they got married? Feyonce." << endl << endl;
    }
    else if(random == 8)
    {
        cout << endl << "What's the best part about living in Switzerland? Not sure, but the flag is a big plus." << endl << endl;
    }
    else if(random == 9)
    {
        cout << endl << "Why can't a bike stand on its own? It's two tired." << endl << endl;
    }
}

void UserInterface::clear()
{
    string command, innerCommand;
    do
    {
        cin.clear();
        cin.ignore();
        cout << endl << "<--- Which database whould you like to clear? --->" << endl;
        cout << '\t' << "sci" << '\t' << "(to clear Scientists database)" << endl;
        cout << '\t' << "comp" << '\t' << "(to clear Computers database)" << endl;
        cout << '\t' << "con" << '\t' << "(to clear Connections database)" << endl;
        cout << '\t' << "all" << '\t' << "(to clear the whole database)" << endl;
        cout << '\t' << "c" << '\t' << "(to cancel)" << endl;
        cout << "=> Command: ";
        cin >> command;
        if(command == "sci")
        {
            cout << "!--- Are you sure you want to clear Scientist database? This action can not be undone ---!" << endl;
            cout << "=> (y/n): ";
            cin >> innerCommand;
            if(innerCommand == "y" || innerCommand == "Y")
            {
                cout << "!--- YES selsected - Scientist database will be cleared ---!" << endl << endl;
                _service.clearData("sci");
            }
            else if(innerCommand == "n" || innerCommand == "N")
            {
                cout << "!--- NO selected - Data will not be cleared ---!" << endl << endl;
            }
            else
            {
                cout << "!--- not a correct input, aborting clear Scientists ---!" << endl;
            }
        }
        else if(command == "comp")
        {
            cout << "!--- Are you sure you want to clear Computer database? This action can not be undone ---!" << endl;
            cout << "=> (y/n): ";
            cin >> innerCommand;
            if(innerCommand == "y" || innerCommand == "Y")
            {
                cout << "!--- YES selected - Scientist database will be cleared ---!" << endl << endl;
                _service.clearData("comp");
            }
            else if(innerCommand == "n" || innerCommand == "N")
            {
                cout << "!--- NO selected - Data will not be cleared ---!" << endl << endl;
            }
            else
            {
                cout << "!--- not a correct input, aborting clear Computers ---!" << endl;
            }
        }
        else if(command == "all")
        {
            cout << "!--- Are you sure you want to clear the whole database? This action can not be undone ---!" << endl;
            cout << "=> (y/n): ";
            cin >> innerCommand;
            if(innerCommand == "y" || innerCommand == "Y")
            {
                cout << "!--- YES selected - Database will be cleared ---!" << endl << endl;
                _service.clearData("all");
            }
            else if(innerCommand == "n" || innerCommand == "N")
            {
                cout << "!--- NO selected - Database will not be cleared ---!" << endl << endl;
            }
            else
            {
                cout << "!--- not a correct input, aborting clear database ---!" << endl;
            }
        }
        else if(command == "con")
        {
            cout << "!--- Are you sure you want to clear Connections database? This action can not be undone ---!" << endl;
            cout << "=> (y/n): ";
            cin >> innerCommand;
            if(innerCommand == "y" || innerCommand == "Y")
            {
                cout << "!--- YES selected - Database will be cleared ---!" << endl << endl;
                _service.clearData("con");
            }
            else if(innerCommand == "n" || innerCommand == "N")
            {
                cout << "!--- NO selected - Database will not be cleared ---!" << endl << endl;
            }
            else
            {
                cout << "!--- not a correct input, aborting clear database ---!" << endl;
            }
        }
        else if(command != "c" && command != "C")
        {
            cout << "!--- Please enter a valid command ---!" << endl << endl;
        }
        else if(command == "c" || command == "C")
        {
            cout << endl;
        }

    } while(command != "c" && command != "C" && innerCommand != "y" && innerCommand != "Y" && innerCommand != "n" && innerCommand != "N");
}

void UserInterface::connect()
{
    string command;
    do
    {
        cin.clear();
        cin.ignore();

        cout << endl << "<--- What would you connect? --->" << endl;
        cout << '\t' << "sci" << '\t' << "(connect computer/s to a scientist)" << endl;
        cout << '\t' << "comp" << '\t' << "(connect scientist/s to a computer)" << endl;
        cout << '\t' << "c" << '\t' << "(cancel)" << endl;
        cout << "=> Command: ";
        cin >> command;


        if(command == "sci")
        {
            string whichSci, toWhichComp;
            vector<int> vWhichComp;

            vector<Scientist> vListSci = _service.sciGet();
            vector<Computer> vListComp = _service.compGet();
            if(vListSci.size() == 0 || vListComp.size() == 0)
            {
                cout << endl <<"There ar no scientists and/or computers in the database!" << endl << "Aborting..." << endl;
            }
            else
            {
                cout << endl << "<--- List of scientists --->" << endl;
                cout << vListSci;
                cout << "Which scientist would you like to connect a computer to? (ID number) : ";
                cin.ignore();
                getline(cin, whichSci);
                while(whichSci.length() == 0)
                {
                    getline(cin, whichSci);
                }
                int sWhichSci = atoi(whichSci.c_str());
                while(sWhichSci < 0 || sWhichSci > vListSci.size()+1 || sWhichSci == 0)
                {
                    cout << "Invalid input, try again!: ";
                    getline(cin, whichSci);
                    sWhichSci = atoi(whichSci.c_str());
                }
                
                cout << "<--- List of Computers --->" << endl;
                cout << vListComp;
                cout << "To which computer/s? (ID number - TYPE 'q' TO QUIT) : ";
                int sToWhichComp;
                do
                {
                    getline(cin, toWhichComp);
                    
                    if(toWhichComp != "c" && toWhichComp != "q")
                    {
                        while(toWhichComp.size() == 0)
                        {
                            getline(cin, toWhichComp);
                        }
                        sToWhichComp = atoi(toWhichComp.c_str());
                        while(sToWhichComp < 0 || sToWhichComp > vListComp.size()+1 || sToWhichComp == 0)
                        {
                            cout << "Invalid input, try again!: ";
                            getline(cin, toWhichComp);
                            sToWhichComp = atoi(toWhichComp.c_str());
                        }
                        if(sToWhichComp != 0)
                        {
                            vWhichComp.push_back(sToWhichComp);
                        }
                    }
                } while(toWhichComp != "c" && toWhichComp != "q");
                
                cout << endl << "<--- Trying to connect... --->" << endl;
                Scientist newSci(vListSci[sWhichSci-1].getName(), vListSci[sWhichSci-1].getGender(), vListSci[sWhichSci-1].getBirth(), vListSci[sWhichSci-1].getDeath());
                vector<bool> whatHappened;
                for(unsigned int i = 0; i < vWhichComp.size(); i++)
                {
                    whatHappened.push_back(_service.connect(newSci, vListComp[vWhichComp[i]-1]));

                }
                for(size_t i = 0; i < whatHappened.size(); i++)
                {

                    cout << whatHappened[i] << endl;
                }
                cout << endl;
                
            }
        }
        else if(command == "comp")
        {
            string whichComp, toWhichSci;
            vector<int> vWhichSci;

            vector<Scientist> vListSci = _service.sciGet();
            vector<Computer> vListComp = _service.compGet();
            if(vListSci.size() == 0 || vListComp.size() == 0)
            {
                cout << endl <<"There ar no scientists and/or computers in the database!" << endl << "Aborting..." << endl;
            }
            else
            {
                cout << endl << "<--- List of computers --->" << endl;
                cout << vListComp;
                cout << "Which computers would you like to connect a scientist to? (ID number) : ";
                cin.ignore();
                getline(cin, whichComp);
                while(whichComp.length() == 0)
                {
                    getline(cin, whichComp);
                }
                int sWhichComp = atoi(whichComp.c_str());
                while(sWhichComp < 0 || sWhichComp > vListComp.size()+1 || sWhichComp == 0)
                {
                    cout << "Invalid input, try again!: ";
                    getline(cin, whichComp);
                    sWhichComp = atoi(whichComp.c_str());
                }

                cout << "<--- List of Scientists --->" << endl;
                cout << vListSci;
                cout << "To which scientist/s? (ID number - TYPE 'q' TO QUIT) : ";
                int sToWhichSci;
                do
                {
                    getline(cin, toWhichSci);

                    if(toWhichSci != "c" && toWhichSci != "q")
                    {
                        while(toWhichSci.size() == 0)
                        {
                            getline(cin, toWhichSci);
                        }
                        sToWhichSci = atoi(toWhichSci.c_str());
                        while(sToWhichSci < 0 || sToWhichSci > vListSci.size()+1 || sToWhichSci == 0)
                        {
                            cout << "Invalid input, try again!: ";
                            getline(cin, toWhichSci);
                            sToWhichSci = atoi(toWhichSci.c_str());
                        }
                        if(sToWhichSci != 0)
                        {
                            vWhichSci.push_back(sToWhichSci);
                        }
                    }
                } while(toWhichSci != "c" && toWhichSci != "q");

                cout << endl << "<--- Trying to connect... --->" << endl;
                Computer newComp(vListComp[sWhichComp-1].getIfMade(), vListComp[sWhichComp-1].getName(), vListComp[sWhichComp-1].getType(), vListComp[sWhichComp-1].getYearMade());
                vector<bool> whatHappened;
                for(unsigned int i = 0; i < vWhichSci.size(); i++)
                {
                    whatHappened.push_back(_service.connect(vListSci[vWhichSci[i]-1], newComp));

                }
                for(size_t i = 0; i < whatHappened.size(); i++)
                {

                    cout << whatHappened[i] << endl;
                }
                cout << endl;

            }
        }
        else if (command != "sci" && command != "comp" && command != "c")
        {
            cout << "!--- Please enter a valid command ---!" << endl;
        }
        else if (command == "c")
        {
            cout << endl;
        }
    } while(command != "sci" && command != "comp" && command != "c");
}

void UserInterface::deleteSom()
{
    string nextCommand;
    do
    {
        cout << endl << "<--- Which of the following would you like to delete? --->" << endl;
        cout << '\t' << "sci" << '\t' << "(to delete a scientist)" << endl;
        cout << '\t' << "comp" << '\t' << "(to delete a computer)" << endl;
        cout << '\t' << "c" << '\t' << "(to cancel)" << endl;
        cout << "=> Command: ";
        cin >> nextCommand;
        if(nextCommand == "sci")
        {
            vector<Scientist> returnVector = searchScientist();
            if(returnVector.size() == 1)
            {
                cout << returnVector;
                cout << "Do you want to delete: " << returnVector[0].getName() << " (y/n): ";
                string inputString;
                getline(cin, inputString);
                while(inputString != "y" && inputString != "Y" && inputString != "n" && inputString != "N")
                {
                    cout << "Please enter eather 'y' or 'n'!: ";
                    getline(cin, inputString);
                }
                if(inputString == "y" || inputString == "Y")
                {
                    _service.deleteSci(returnVector[0]);
                    cout << endl;
                }
                else if(inputString == "n" || inputString == "N")
                {
                    cout << "Cancelling..." << endl << endl;
                }

            }
            else if(returnVector.size() > 1)
            {
                cout << "multiple matching scientists!" << endl << "Please choose scientist to delete!" << endl;
                cout << returnVector;
                int choice;
                cin >> choice;
                while(choice < 1 && choice > (returnVector.size()+1))
                {
                    cout << "Invalid entry. Pleasy try again: ";
                    cin >> choice;

                }
                cout << "Do you want to delete entry Nr. " << choice << " :" << returnVector[choice-1].getName() << endl;
                string inputString;
                getline(cin, inputString);
                while(inputString != "y" && inputString != "Y" && inputString != "n" && inputString != "N")
                {
                    cout << "Please enter eather 'y' or 'n'!: ";
                    getline(cin, inputString);
                }
                if(inputString == "y" || inputString == "Y")
                {
                    _service.deleteSci(returnVector[choice-1]);
                }
                else if(inputString == "n" || inputString == "N")
                {
                    cout << "Cancelling..." << endl;
                }
            }
            else if(returnVector.size() == 0)
            {
                cout << "No such Scientist found!";
            }

        }
        else if(nextCommand == "comp")
        {
            vector<Computer> returnVector = searchComputer();
            if(returnVector.size() == 1)
            {
                cout << returnVector;
                cout << "Do you want to delete: " << returnVector[0].getName() << " (y/n)";
                string inputString;
                getline(cin, inputString);
                while(inputString != "y" && inputString != "Y" && inputString != "n" && inputString != "N")
                {
                    cout << "Please enter eather 'y' or 'n'!: ";
                    getline(cin, inputString);
                }
                if(inputString == "y" || inputString == "Y")
                {
                    _service.deleteComp(returnVector[0]);
                }
                else if(inputString == "n" || inputString == "N")
                {
                    cout << "Cancelling..." << endl;
                }

            }
            else if(returnVector.size() > 1)
            {
                cout << "multiple matching scientists!" << endl << "Please choose scientist to delete!" << endl;
                cout << returnVector;
                int choice;
                cin >> choice;
                while(choice < 1 && choice > (returnVector.size()+1))
                {
                    cout << "Invalid entry. Pleasy try again: ";
                    cin >> choice;

                }
                cout << "Do you want to delete entry Nr. " << choice << " :" << returnVector[choice-1].getName() << endl;
                string inputString;
                getline(cin, inputString);
                while(inputString != "y" && inputString != "Y" && inputString != "n" && inputString != "N")
                {
                    cout << "Please enter eather 'y' or 'n'!: ";
                    getline(cin, inputString);
                }
                if(inputString == "y" || inputString == "Y")
                {
                    _service.deleteComp(returnVector[choice-1]);
                }
                else if(inputString == "n" || inputString == "N")
                {
                    cout << "Cancelling..." << endl;
                }
            }
            else if(returnVector.size() == 0)
            {
                cout << "No such computer found in the database!";
            }
        }
        else if(nextCommand != "c")
        {
            cout << "!--- Not a valid command ---!" << endl;
        }
        else if(nextCommand == "c")
        {
            cout << endl;
        }
    } while(nextCommand != "sci" && nextCommand != "comp" && nextCommand != "c");
}

//Prints out the user manual 'readme.txt' in the console
void UserInterface::readMe()
{
    cout << endl;
    vector<string> read = _service.getManual();
    for(size_t i = 0; i < read.size(); i++)
    {
        cout << read[i] << endl;
    }
    cout << endl;
}

void UserInterface::info()
{
    cout << endl;
    cout << "=====================================================================" << endl;
    cout << " _______  ______    _______  __   __  _______       _______  _______ " << endl;
    cout << "|       ||    _ |  |       ||  | |  ||       |     |       ||       |" << endl;
    cout << "|    ___||   | ||  |   _   ||  | |  ||    _  |     |___    ||   ____|" << endl;
    cout << "|   | __ |   |_||_ |  | |  ||  |_|  ||   |_| |      ___|   ||  |____ " << endl;
    cout << "|   ||  ||    __  ||  |_|  ||       ||    ___|     |___    ||_____  |" << endl;
    cout << "|   |_| ||   |  | ||       ||       ||   |          ___|   | _____| |" << endl;
    cout << "|_______||___|  |_||_______||_______||___|         |_______||_______|" << endl;
    cout << "=====================================================================" << endl;
    cout << endl << endl;
}

void UserInterface::printSciToComp()
{
    cin.clear();
    cin.ignore();

    cout << endl << endl << "Computer" << '\t' << '\t' << "||" << '\t' << '\t' << "Scientists connected to the computer" << endl;
    cout << "-----------------------------------------------------------" << endl;
    vector<Computer> computers = _service.compAlpha();

    for(unsigned int i = 0; i < computers.size(); i++)
    {
        vector<Scientist> connectedSci = _service.getConnectedSci(computers[i]);
        if(connectedSci.size() != 0)
        {
            if(computers[i].getName().length() < firstTabLimit)
            {
                cout << computers[i].getName() << '\t' << '\t' << '\t' << "||  ";
            }
            else if(computers[i].getName().length() >= firstTabLimit && computers[i].getName().length() < firstTabLimit)
            {
                cout << computers[i].getName() << '\t' << '\t' << "||  ";
            }
            else
            {
                cout << computers[i].getName() << '\t' << "||  ";
            }
            for(unsigned int j = 0; j < connectedSci.size(); j++)
            {
                if(j == 0)
                {
                    cout << connectedSci[j].getName();
                }
                else
                {
                    cout << " & " << connectedSci[j].getName();
                }

            }
            cout << endl;
        }
    }
    cout<< endl;
}

void UserInterface::printCompToSci()
{
    cin.clear();
    cin.ignore();

    cout << endl << endl << "Computer" << '\t' << '\t' << "||  " << "Scientists connected to the computer" << endl;
    cout << "-----------------------------------------------------------" << endl;
    vector<Scientist> scientists = _service.sciAlpha();

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        vector<Computer> connectedComp = _service.getConnectedComp(scientists[i]);
        if(connectedComp.size() != 0)
        {
            if(scientists[i].getName().length() < firstTabLimit)
            {
                cout << scientists[i].getName() << '\t' << '\t' << '\t' << "||  ";
            }
            else if(scientists[i].getName().length() >= firstTabLimit && scientists[i].getName().length() < firstTabLimit)
            {
                cout << scientists[i].getName() << '\t' << '\t' << "||  ";
            }
            else
            {
                cout << scientists[i].getName() << '\t' << "||  ";
            }
            for(unsigned int j = 0; j < connectedComp.size(); j++)
            {
                if(j == 0)
                {
                    cout << connectedComp[j].getName();
                }
                else
                {
                    cout << " & " << connectedComp[j].getName();
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}



