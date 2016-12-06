#ifndef COMPUTER_H
#define COMPUTER_H
#include <vector>
#include <string>

using namespace std;

class Computer {
public:
    Computer();
    
    Computer(bool ifMade, string name, string type, int yearMade);
    int getYearMade();
    bool getIfMade();
    string getName();
    string getType();
    
private:
    bool _ifMade;
    string _name, _type;
    int _yearMade;
};

#endif // SCIENTIST_H

