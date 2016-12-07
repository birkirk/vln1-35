#include <iostream>
#include "userinterface.h"
#include "scientist.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Overloading the opperator << to be able to print out scientists in a table
ostream& operator << (ostream& out, vector<Scientist> vScientist)
{
    if(vScientist.size() != 0)
    {
        cout << "Name" << '\t' << '\t' << '\t' << "Gender" << '\t' << '\t' << "Born" << '\t' << '\t'  << "Died" << endl;
        cout << "------------------------------------------------------------------" << endl;
        for(size_t i = 0; i < vScientist.size(); i++)
        {
            string name = vScientist[i].getName();
            char gender = vScientist[i].getGender();
            int born = vScientist[i].getBirth();
            int died = vScientist[i].getDeath();
            string space;
            
            //check how many tabs is best to use after name:
            if(name.length() < 8)
            {
                out << name << '\t' << '\t' << '\t';
            }
            else if(name.length() > 8 && name.length() < 16)
            {
                out << name << '\t' << '\t';
            }
            else
            {
                out << name << '\t';
            }
            
            //print gender and birth year:
            out << gender << '\t' << '\t' << born << '\t' << '\t';;
            
            //check if scientist has not died yet:
            if(died == 3000)
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
        cout << "!--- There are no scientists in the database ---!" << endl;
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
        cout << "add" << '\t' << "(to add a scientist or computer)" << endl;
        cout << "delete" << '\t' << "(to delete a scientist or computer)" << endl;
        cout << "list" << '\t' << "(to see the list of scientists or computers)" << endl;
        cout << "search" << '\t' << "(to search in the list)" << endl;
        cout << "connect" << '\t' << "(to connect scientists and computers)" << endl;
        cout << "clear" << '\t' << "(to clear the list of scientists or computers)" << endl;
        cout << "q" << '\t' << "(quit)" << endl;
        cout << "=> Command: ";

        cin >> command;

        if (command == "add")
        {
            string nextCommand;
            do
            {
                cout << endl << "<--- Which of the following would you like to add? --->" << endl;
                cout << "sci" << '\t' << "(to add a scientist)" << endl;
                cout << "comp" << '\t' << "(to add a computer)" << endl;
                cout << "c" << '\t' << "(to cancell)" << endl;
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
        if (command == "delete")
        {
            string nextCommand;
            do
            {
                cout << endl << "<--- Which of the following would you like to delete? --->" << endl;
                cout << "sci" << '\t' << "(to delete a scientist)" << endl;
                cout << "comp" << '\t' << "(to delete a computer)" << endl;
                cout << "c" << '\t' << "(to cancell)" << endl;
                cout << "=> Command: ";
                cin >> nextCommand;
                if(nextCommand == "sci")
                {
                   // deleteSci();
                }
                else if(nextCommand == "comp")
                {
                  //  deleteComp();
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
        else if (command == "list")
        {
            list();
        }
        else if (command == "search")
        {
            //search(); TODO
        }
        else if (command == "connect")
        {
            //connect(); TODO
        }
        else if (command == "clear")
        {
            //clear(); TODO
        }
        else if (command != "q")
        {
            cout << "!--- Please enter a valid command ---!" << endl << endl;
        }
    } while (command != "q");

}

void UserInterface::addSci()
{
    string name;
    char gender, stillAlive;
    int born, death;
    cout << endl << "<--- Add a scientist --->" << endl;
    
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
        cin.ignore();
        cout << "Gender (M/F): ";
        cin >> gender;
        if(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f')
        {
            cout << "!--- You can only enter 'M' or 'F' ---!" << endl;
        }
    } while(gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f');
    
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> born;
        if(born <= 0 || born > 2016 || cin.fail())
        {
            cout << "!--- Please enter a valid year ---!" << endl;
        }
    } while(born <= 0 || born > 2016);
    
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Is he/her still alive? (y/n) ";
        cin >> stillAlive;
        if(stillAlive != 'Y' && stillAlive != 'y' && stillAlive != 'N' && stillAlive != 'n' && !cin.fail())
        {
            cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
        }
    } while (stillAlive != 'Y' && stillAlive != 'y' && stillAlive != 'N' && stillAlive != 'n');
    
    if(stillAlive == 'Y' || stillAlive == 'y')
    {
        //has to be high so that list be death is correct
        death = 3000;
    }
    else
    {
        do
        {
            cin.clear();
            cin.ignore();
            cout << "Year of death: ";
            cin >> death;
            if(death > 2016 || death < born || cin.fail())
            {
                cout << "!--- Please enter a valid year ---!" << endl;
            }
        } while(death > 2016 || death < born);
    }
    
    cout << "<--- Trying to add scientist... --->" << endl << endl;
    Scientist aScientist(name, gender, born, death);
    _service.addScientitst(aScientist);
}

void UserInterface::addComp()
{
    string name, type;
    char check;
    bool ifMade = false;
    int yearMade;
    cout << "<--- Add a computer --->" << endl;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Name: ";
        cin >> name;
        if(name.length() < 1)
        {
            cout << "!--- Please enter a valid name ---!" << endl;
        }
    } while(name.length() < 1);
    
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Type: ";
        cin >> type;
        if(type.length() < 1 || cin.fail())
        {
            cout << "!--- Please enter a valid type ---!" << endl;
        }
    } while(type.length() < 1);
    
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Was it ever made? (y/n) ";
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
            if(yearMade <= 0 || yearMade > 2016)
            {
                cout << "!--- Please enter a valid year ---!" << endl;
            }
        } while(yearMade <= 0 || yearMade > 2016);
    }
    
    cout << "<--- Trying to add computer... --->" << endl << endl;
    Computer aComputer(ifMade, name, type, yearMade);
    _service.addComputer(aComputer);
}

void UserInterface::list()
{
    string listCommand, innerCommand;
    do
    {
        cin.clear();
        cin.ignore();
        
        cout << endl << "<--- What would you like to see a list of? --->" << endl;
        cout << "sci" << '\t' << "(list of just the scientists)" << endl;
        cout << "somp" << '\t' << "(list of just the computers)" << endl;
        cout << "con" << '\t' << "(list of the connections between scientists and computers)" << endl;
        cout << "c" << '\t' << "(cancell)" << endl;
        cout << "=> Command: ";
        cin >> listCommand;
        
        if(listCommand == "sci")
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout << endl << "<--- Scientists - in which order? --->" << endl;
                cout << "alpha" << '\t' << "(alphabetical order)" << endl;
                cout << "ralpha" << '\t' << "(reversed alphabetical order)" << endl;
                cout << "ageasc" << '\t' << "(ascending age order)" << endl;
                cout << "agedesc" << '\t' << "(descending age order)" << endl;
                cout << "deathasc" << '\t' << "(ascending death year order)" << endl;
                cout << "deathdesc" << '\t' << "(descending death year order)" << endl;
                cout << "b" << '\t' << "(go back)" << endl;
                cout << "=> Command: ";
                cin >> innerCommand;
                
                if(innerCommand != "alpha" && innerCommand != "ralpha" && innerCommand != "ageasc" && innerCommand != "agedesc" && innerCommand != "deathasc" && innerCommand != "deathdesc" && innerCommand != "b")
                {
                    cout << "!--- Please enter a valid command ---!" << endl;
                }
                else if(innerCommand == "b")
                {
                    cout << endl;
                }
                else if(innerCommand == "alpha")
                {
                    vector<Scientist> vUse = _service.sciAlpha();
                    cout << "<--- Scientists in alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "ralpha")
                {
                    vector<Scientist> vUse = _service.sciRalpha();
                    cout << "<--- Scientists in reversed alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "ageasc")
                {
                    vector<Scientist> vUse = _service.sciAgeAsc();
                    cout << "<--- Scientists in age ascending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "agedesc")
                {
                    vector<Scientist> vUse = _service.sciAgeDesc();
                    cout << "<--- Scientists in age descending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "deathasc")
                {
                    vector<Scientist> vUse = _service.sciDeathAsc();
                    cout << "<--- Scientists in death ascending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "deathdesc")
                {
                    vector<Scientist> vUse = _service.sciDeathDesc();
                    cout << "<--- Scientists in death descending order --->" << endl << endl;
                    cout << vUse;
                }
            } while(innerCommand != "alpha" && innerCommand != "ralpha" && innerCommand != "ageasc" && innerCommand != "agedesc" && innerCommand != "deathasc" && innerCommand != "deathdesc" && innerCommand != "b");
        }
        else if(listCommand == "comp")
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout << endl << "<--- Computers - in which order? --->" << endl;
                cout << "alpha" << '\t' << "(alphabetical order)" << endl;
                cout << "ralpha" << '\t' << "(reversed alphabetical order)" << endl;
                cout << "ageasc" << '\t' << "(ascending age order)" << endl;
                cout << "agedesc" << '\t' << "(descending age order)" << endl;
                cout << "made" << '\t' << "(only the ones that were made)" << endl;
                cout << "notmade" << '\t' << "(only the ones that were not made)" << endl;
                cout << "b" << '\t' << "(go back)" << endl;
                cout << "=> Command: ";
                cin >> innerCommand;
                
                if(innerCommand != "alpha" && innerCommand != "ralpha" && innerCommand != "ageasc" && innerCommand != "agedesc" && innerCommand != "made" && innerCommand != "notmade" && innerCommand != "b")
                {
                    cout << "!--- Please enter a valid command ---!" << endl;
                }
                else if(innerCommand == "b")
                {
                    cout << endl;
                }
                else if(innerCommand == "alpha")
                {
                    
                }
                else if(innerCommand == "ralpha")
                {
                    
                }
                else if(innerCommand == "ageasc")
                {
                    
                }
                else if(innerCommand == "agedesc")
                {
                    
                }
                else if(innerCommand == "made")
                {
                    
                }
                else if(innerCommand == "notmade")
                {
                    
                }
            } while(innerCommand != "alpha" && innerCommand != "ralpha" && innerCommand != "ageasc" && innerCommand != "agedesc" && innerCommand != "made" && innerCommand != "notmade" && innerCommand != "b");
        }
        else if(listCommand == "con")
        {
            do
            {
                cin.clear();
                cin.ignore();
                cout << endl << "<--- Connections - in which order? --->" << endl;
                cout << "sciToComp" << '\t' << "(scientists to computers)" << endl;
                cout << "compToSci" << '\t' << "(computers to scientits)" << endl;
                cout << "b" << '\t' << "(go back)" << endl;
                cout << "=> Command: ";
                cin >> innerCommand;
                
                if(innerCommand != "scitocomp" && innerCommand != "sciToComp" && innerCommand != "comptosci" && innerCommand != "compToSci" && innerCommand != "b")
                {
                    cout << "!--- Please enter a valid command ---!" << endl;
                }
                else if(innerCommand == "b")
                {
                    cout << endl;
                }
                else if(innerCommand == "scitocomp" || innerCommand == "sciToComp")
                {
                    //TODO
                }
                else if(innerCommand == "comptosci" || innerCommand == "compToSci")
                {
                    //TODO
                }
            } while(innerCommand != "scitocomp" && innerCommand != "sciToComp" && innerCommand != "comptosci" && innerCommand != "compToSci" && innerCommand != "b");
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





