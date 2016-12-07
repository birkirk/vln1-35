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
    char death;
    if(vScientist.size() != 0)
    {
        cout << "Name" << '\t' << "Gender" << '\t' << "Born" << '\t'  << "Died" << endl;
        cout << "------------------------------------------------------" << endl;
        for(size_t i = 0; i < vScientist.size(); i++)
        {
            if(vScientist[i].getDeath() == 0)
            {
                death = '?';
            }
            else
            {
                death = vScientist[i].getDeath();
            }
            out << vScientist[i].getName() << '\t' << vScientist[i].getGender() << '\t' << vScientist[i].getBirth() << death<< endl;
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
        cin.clear();
        cin.ignore();
        cout << "Name: ";
        cin >> name;
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
        death = 0;
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
        cout << "sci" << '\t' << "(list just the scientists)" << endl;
        cout << "comp" << '\t' << "(list just the computers)" << endl;
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
                
                if(innerCommand != "alpha" && innerCommand != "ralpha" && innerCommand != "ageasc" && innerCommand != "agedesc" && innerCommand != "male" && innerCommand != "female" && innerCommand != "b")
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
                    cout << vUse;
                }
                else if(innerCommand == "ralpha")
                {
                    //vector<Scientist> vUse = _service.sciRalpha();
                    //cout << vUse;
                }
                else if(innerCommand == "ageasc")
                {
                    //vector<Scientist> vUse = _service.sciAgeAsc();
                    //cout << vUse;
                }
                else if(innerCommand == "agedesc")
                {
                    //vector<Scientist> vUse = _service.sciAgeDesc();
                    //cout << vUse;
                }
                else if(innerCommand == "deathAsc")
                {
                    //vector<Scientist> vUse = _service.sciDeathAsc();
                    //cout << vUse;
                }
                else if(innerCommand == "deathDesc")
                {
                    //vector<Scientist> vUse = _service.sciDeathDesc();
                    //cout << vUse;
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
        else if (listCommand != "all" && listCommand != "sci" && listCommand != "comp" && listCommand != "b"  && listCommand != "c")
        {
            cout << "!--- Please enter a valid command ---!" << endl;
        }
        else if (listCommand == "c")
        {
            cout << endl;
        }
    } while(listCommand != "all" && listCommand != "sci" && listCommand != "comp" && listCommand != "b"  && listCommand != "c");
}





