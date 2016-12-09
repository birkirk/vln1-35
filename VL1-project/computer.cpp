#include "computer.h"
#include <vector>
#include <string>

Computer::Computer()
{
}

Computer::Computer(bool ifMade, string name, string type, int yearMade)
{
    _name = name;
    _ifMade = ifMade;
    _type = type;
    _yearMade = yearMade;
}

bool Computer::getIfMade()
{
    return _ifMade;
}

string Computer::getName()
{
    return _name;
}

string Computer::getType()
{
    return _type;
}

int Computer::getYearMade()
{
    return _yearMade;
}
