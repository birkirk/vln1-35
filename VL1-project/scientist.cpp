#include "scientist.h"
#include <vector>
#include <string>

Scientist::Scientist()
{
}

Scientist::Scientist(string name, char gender, int born, int death)
{
    _name = name;
    _gender = gender;
    _born = born;
    _death = death;
    _hasPicture = false;
    _hasInfo = false;

}
Scientist::Scientist(string name, char gender, int born, int death, QByteArray pict)
{
    _name = name;
    _gender = gender;
    _born = born;
    _death = death;
    _picture = pict;
    _hasPicture = true;
    _hasInfo = false;
}

string Scientist::getInfo()
{
    return _info;
}

void Scientist::addInfo(string inf)
{
    _info = inf;
    _hasInfo = true;
}

bool Scientist::hasPicture()
{
    return _hasPicture;
}

bool Scientist::hasInfo()
{
    return _hasInfo;
}

int Scientist::getBirth()
{
    return _born;
}

int Scientist::getDeath()
{
    return _death;
}

char Scientist::getGender()
{
    return _gender;
}

string Scientist::getName()
{
    return _name;
}

QByteArray Scientist::getPicture()
{
    return _picture;
}

