#include "scientist.h"
#include <vector>
#include <string>


Scientist::Scientist()
{
}

Scientist::Scientist(string name, char gender,int born,int death)
{
    _name = name;
    _gender = gender;
    _born = born;
    _death = death;
}

int Scientist::getBirth()
{
    return yearOfBirth;
}
int Scientist::getDeath()
{
    return yearOfDeath;
}
bool Scientist::getGender()
{
    return gender;
}
string Scientist::getName()
{
    return name;
}

