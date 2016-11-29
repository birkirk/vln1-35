#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();

    Scientist(string name, char gender,int born,int death);

    int getBirth();
    int getDeath();
    bool getGender();
    string getName();


private:
    char _gender;
    string _name;
    int _born, _death;
};

#endif // SCIENTIST_H

