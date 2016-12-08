#include <iostream>
#include "userinterface.h"
#include "scientist.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;


// Overloading the opperator << to be able to print out scientists in a table
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
            string space;
            
            //check how many tabs is best to use after name:
            out << " " << i+1 << '\t';
            if(name.length() < 8)
            {
                out << name << '\t' << '\t' << '\t';
            }
            else if(name.length() >= 8 && name.length() < 16)
            {
                out << name << '\t' << '\t';
            }
            else
            {
                out << name << '\t';
            }
            
            //print gender and birth year:
            out << gender << '\t' << '\t' << born << '\t' << '\t';
            
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
        cout << "!--- There are no such scientists in the database ---!" << endl;
    }
    cout << endl;
    
    return out;
}

// Overloading the opperator << to be able to print out computers in a table
ostream& operator << (ostream& out, vector<Computer> vComputers)
{
    if(vComputers.size() != 0)
    {
        cout << "Name" << '\t' << '\t' << '\t' << "Type" << '\t' << '\t' << "If Made" << '\t' << '\t'  << "Year Made" << endl;
        cout << "------------------------------------------------------------------" << endl;
        for(size_t i = 0; i < vComputers.size(); i++)
        {
            string name = vComputers[i].getName();
            bool made = vComputers[i].getIfMade();
            int yearMade = vComputers[i].getYearMade();
            string type = vComputers[i].getType();
            string space;
            
            //check how many tabs is best to use after name:
            if(name.length() < 8)
            {
                out << name << '\t' << '\t' << '\t';
            }
            else if(name.length() >= 8 && name.length() < 16)
            {
                out << name << '\t' << '\t';
            }
            else
            {
                out << name << '\t';
            }
            
            //print type:
            out << type << '\t' << '\t';
            
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

//ostream& operator << ()

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
        cout << '\t' << "joke" << '\t' << '\t' << "(Homo sapiens need to laugh for at least 17 minutes per day)" << endl;
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
                cout << '\t' << "c" << '\t' << "(to cancell)" << endl;
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
                cout << '\t' << "sci" << '\t' << "(to delete a scientist)" << endl;
                cout << '\t' << "comp" << '\t' << "(to delete a computer)" << endl;
                cout << '\t' << "c" << '\t' << "(to cancell)" << endl;
                cout << "=> Command: ";
                cin >> nextCommand;
                if(nextCommand == "sci")
                {
                    vector<Scientist> returnVector = search();
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
                            _service.deleteSci(returnVector[0]);
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
                            _service.deleteSci(returnVector[choice-1]);
                        }
                        else if(inputString == "n" || inputString == "N")
                        {
                            cout << "Cancelling..." << endl;
                        }
                    }

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
            vector<Scientist> printVector = search();
            cout << printVector;
        }
        else if (command == "connect")
        {
            //connect(); TODO
        }
        else if (command == "clear")
        {
            clear();
        }
        else if (command == "joke")
        {
            generateJoke();
        }
        else if (command != "q")
        {
            cout << "!--- Please enter a valid command ---!" << endl << endl;
        }
    } while (command != "q");
    
}

void UserInterface::addSci()
{
    string name, sGender, sStillAlive;
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
        cin >> sStillAlive;
        if(sStillAlive != "Y" && sStillAlive != "y" && sStillAlive != "N" && sStillAlive != "n" && !cin.fail())
        {
            cout << "!--- You can only enter 'y' or 'n' ---!" << endl;
        }
    } while (sStillAlive != "Y" && sStillAlive != "y" && sStillAlive != "N" && sStillAlive != "n");
    stillAlive = sStillAlive.at(0);
    
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
    cout << endl << "<--- Add a computer --->" << endl;
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
    
    do
    {
        cin.clear();
        cout << "Type: ";
        getline(cin, type);
        type[0] = toupper(type[0]);
        if(type.length() < 1 || cin.fail())
        {
            cout << "!--- Please enter a valid type ---!" << endl;
        }
    } while(type.length() < 1);
    
    do
    {
        cin.clear();
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
        cout << '\t' << "sci" << '\t' << "(list of just the scientists)" << endl;
        cout << '\t' << "comp" << '\t' << "(list of just the computers)" << endl;
        cout << '\t' << "con" << '\t' << "(list of the connections between scientists and computers)" << endl;
        cout << '\t' << "c" << '\t' << "(cancell)" << endl;
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
                cout << '\t' << "1." << '\t' << "(scientists to computers)" << endl;
                cout << '\t' << "2." << '\t' << "(computers to scientits)" << endl;
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
                    //TODO
                }
                else if(innerCommand == "2" || innerCommand == "compToSci")
                {
                    //TODO
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

vector<Scientist> UserInterface::search()
{
    string command;
    do
    {
        cout << endl << "<--- What would you like to search for? --->" << endl;
        cout << '\t' << "sci" << '\t' << "(to search in Scientists database)" << endl;
        cout << '\t' << "comp" << '\t' << "(to search in Computers database)" << endl;
        cout << '\t' << "c" << '\t' << "(to cancell)" << endl;
        cout << "=> Command: ";
        cin >> command;
        if(command == "sci")
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
                cout << "Is he/her still alive? (y/n) ";
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
                //has to be high so that list be death is correct
                death = 3000;
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
        else if(command == "comp")
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
                cin >> check;
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
            cout << aComputer;
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
        cout << '\t' << "all" << '\t' << "(to clear the whole database)" << endl;
        cout << '\t' << "c" << '\t' << "(to cancell)" << endl;
        cout << "=> Command: ";
        cin >> command;
        if(command == "sci")
        {
            cout << "!--- Are you sure you want to clear Scientist database? This action can not be undone ---!" << endl;
            cout << "=> (y/n): ";
            cin >> innerCommand;
            if(innerCommand == "y" || innerCommand == "Y")
            {
                cout << "!--- YES selsected - Scientist database will be cleared ---!" << endl;
                _service.clearData("sci");
            }
            else if(innerCommand == "n" || innerCommand == "N")
            {
                cout << "!--- NO selected - Data will not be cleared ---!" << endl;
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
                cout << "!--- YES selected - Scientist database will be cleared ---!" << endl;
                _service.clearData("comp");
            }
            else if(innerCommand == "n" || innerCommand == "N")
            {
                cout << "!--- NO selected - Data will not be cleared ---!" << endl;
            }
            else
            {
                cout << "!--- not a correct input, aborting clear Computers ---!" << endl;
            }
        }
        else if(command == "all")
        {
            cout << "!--- Are you sure you want to clear Computer database? This action can not be undone ---!" << endl;
            cout << "=> (y/n): ";
            cin >> innerCommand;
            if(innerCommand == "y" || innerCommand == "Y")
            {
                cout << "!--- YES selected - Database will be cleared ---!" << endl;
                _service.clearData("all");
            }
            else if(innerCommand == "n" || innerCommand == "N")
            {
                cout << "!--- NO selected - Database will not be cleared ---!" << endl;
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
        
    } while(command != "c" && command != "C" && command != "y" && command != "Y" && command != "n" && command != "N");
}





