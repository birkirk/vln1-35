#include "scientist.h"
#include <vector>
#include <string>


Scientist::Scientist()
{
}

Scientist::Scientist(string n, bool g, int dOB, int dOD)
{
    name = n;
    gender = g;
    yearOfBirth = dOB;
    yearOfDeath = dOD;
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

