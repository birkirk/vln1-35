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

