#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();

    Scientist(string name, bool gender, int dateOBirth, int dateOdeath);

    int getBirth();
    int getDeath();
    bool getGender();
    string getName();


private:
    string name;
    int yearOfBirth;
    int yearOfDeath;
    bool gender;
};

#endif // SCIENTIST_H

