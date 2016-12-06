#ifndef COMPUTER_H
#define COMPUTER_H
#include <vector>
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    
    Computer(char ifMade, string name, string type, int yearMade);
    int getYearMade();
    char getIfMade();
    string getName();
    string getType();
    
private:
    char _ifMade;
    string _name, _type;
    int _yearMade;
};

#endif // SCIENTIST_H

