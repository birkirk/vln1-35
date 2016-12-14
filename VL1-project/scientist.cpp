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

}
Scientist::Scientist(string name, char gender, int born, int death, QByteArray pict)
{
    _name = name;
    _gender = gender;
    _born = born;
    _death = death;
    _picture = pict;
    _hasPicture = true;
}

bool Scientist::hasPicture()
{
    return _hasPicture;
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

