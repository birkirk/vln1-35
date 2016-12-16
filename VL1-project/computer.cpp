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
    _hasPicture = false;
    _yearMade = yearMade;

}

Computer::Computer(bool ifMade, string name, string type, int yearMade, QByteArray pict)
{
    _name = name;
    _ifMade = ifMade;
    _type = type;
    _yearMade = yearMade;
    _hasPicture = true;
    _picture = pict;

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

QByteArray Computer::getPicture()
{
    return _picture;
}

bool Computer::hasPicture()
{
    return _hasPicture;
}

void Computer::addInfo(string inf)
{
    _info = inf;
    _hasInfo = true;
}

string Computer::getInfo()
{
    return _info;
}

bool Computer::hasInfo()
{
    return _hasInfo;
}
