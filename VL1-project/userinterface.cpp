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
        cout << "clear" << '\t' << "(to empty the database of scientists or computers)" << endl;
        cout << "joke" << '\t' << "(Homo sapiens need to laugh for at least 17 minutes per day)" << endl;
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
            search();
        }
        else if (command == "connect")
        {
            //connect(); TODO
        }
        else if (command == "clear")
        {
            //clear(); TODO
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
        cout << "sci" << '\t' << "(list of just the scientists)" << endl;
        cout << "comp" << '\t' << "(list of just the computers)" << endl;
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
                cout << "alpha" << '\t' << '\t' << "(alphabetical order)" << endl;
                cout << "ralpha" << '\t' << '\t' << "(reversed alphabetical order)" << endl;
                cout << "ageasc" << '\t' << '\t' << "(ascending age order)" << endl;
                cout << "agedesc" << '\t' << '\t' << "(descending age order)" << endl;
                cout << "deathasc" << '\t' << "(ascending death year order)" << endl;
                cout << "deathdesc" << '\t' << "(descending death year order)" << endl;
                cout << "b" << '\t' << '\t' << "(go back)" << endl;
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
                cout << "type" << '\t' << "(by type)" << endl;
                cout << "b" << '\t' << "(go back)" << endl;
                cout << "=> Command: ";
                cin >> innerCommand;
                
                if(innerCommand != "alpha" && innerCommand != "ralpha" && innerCommand != "ageasc" && innerCommand != "agedesc" && innerCommand != "made" && innerCommand != "notmade" && innerCommand != "type" && innerCommand != "b")
                {
                    cout << "!--- Please enter a valid command ---!" << endl;
                }
                else if(innerCommand == "b")
                {
                    cout << endl;
                }
                else if(innerCommand == "alpha")
                {
                    vector<Computer> vUse = _service.compAlpha();
                    cout << "<--- Computers in alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "ralpha")
                {
                    vector<Computer> vUse = _service.compRalpha();
                    cout << "<--- Computers in reversed alphabetical order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "ageasc")
                {
                    vector<Computer> vUse = _service.compAgeAsc();
                    cout << "<--- Computers in age ascending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "agedesc")
                {
                    vector<Computer> vUse = _service.compAgeDesc();
                    cout << "<--- Computers in age descending order --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "made")
                {
                    vector<Computer> vUse = _service.compMade();
                    cout << "<--- Computers that were made --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "notmade")
                {
                    vector<Computer> vUse = _service.compNotMade();
                    cout << "<--- Computers that were not made --->" << endl << endl;
                    cout << vUse;
                }
                else if(innerCommand == "type")
                {
                    vector<Computer> vUse = _service.compType();
                    cout << "<--- Computers in type order --->" << endl << endl;
                    cout << vUse;
                }
            } while(innerCommand != "alpha" && innerCommand != "ralpha" && innerCommand != "type" && innerCommand != "ageasc" && innerCommand != "agedesc" && innerCommand != "made" && innerCommand != "notmade" && innerCommand != "b");
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

void UserInterface::search()
{
    string command;
    do
    {
        cout << endl << "<--- What would you like to search for? --->" << endl;
        cout << "sci" << '\t' << "(to search in Scientists database)" << endl;
        cout << "comp" << '\t' << "(to search in Computers database)" << endl;
        cout << "c" << '\t' << "(to cancell)" << endl;
        cout << "=> Command: ";
        cin >> command;
        if(command == "sci")
        {
            string name, sGender, sStillAlive, born, death;
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
            cout << "Year of birth (type a number < 0 if you want to skip this): ";

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
                cout << "Year of death (type a number < 0 if you want to skip this): ";


                getline(cin, death);
                if(death.length() == 0)
                {
                    death = "";
                }
            }
            
            cout << "<--- Searching for scientist... --->" << endl << endl;
            
            //If something is skipped than sends: "", 'O', NULL, NULL;
            vector<Scientist> vSci = _service.searchSci(name, gender, born, death);
            cout << vSci;
        }
        else if(command == "comp")
        {
            
        }
        else if(command != "c")
        {
            cout << "!--- Not a valid command ---!" << endl;
        }
        else if(command == "c")
        {
            
        }
    } while(command != "sci" && command != "comp" && command != "c");
}




void UserInterface::generateJoke()
{
    int random = rand() % 10;
    for(int i = 1; i <= 10; i++)
    {
        if(i == 1)
        {
            cout << "Generating..." << '\t' << " " << i*10 << "%";
        }
        cout << "///";
        usleep(200000);
    }
    cout << endl;
    
    if(random == 0)
    {
        cout << endl << "Can a kangaroo jump higher than a house? Of course, a house doesn’t jump at all." << endl << endl;
    }
    else if(random == 1)
    {
        cout << endl << "I used to think the brain was the most important organ. Then I thought, look what’s telling me that" << endl << endl;
    }
    else if(random == 2)
    {
        cout << endl << "What is Bruce Lee’s favorite drink? Wataaaaah!" << endl << endl;
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
        cout << endl << "What did Jay-Z call his girlfriend before they got married? Feyoncé." << endl << endl;
    }
    else if(random == 8)
    {
        cout << endl << "What’s the best part about living in Switzerland? Not sure, but the flag is a big plus." << endl << endl;
    }
    else if(random == 9)
    {
        cout << endl << "Why can’t a bike stand on its own? It’s two tired." << endl << endl;
    }
}





