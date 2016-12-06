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
    friend istream& operator >> (istream& in, Scientist& s);
    friend vector<Scientist> sortByFemaleMale();
    int getBirth();
    int getDeath();
    char getGender();
    string getName();


private:
    char _gender;
    string _name;
    int _born, _death;
};

#endif // SCIENTIST_H

