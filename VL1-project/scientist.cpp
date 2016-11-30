#include "scientist.h"
#include <vector>
#include <string>


Scientist::Scientist()
{
}

Scientist::Scientist(string fName, string lName, char gender,int born,int death)
{
    _firstName = fName;
    _lastName = lName;
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
string Scientist::getFirstName()
{
    return _firstName;
}
string Scientist::getLastName()
{
    return _lastName;
}

