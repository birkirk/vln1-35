#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();

    Scientist(string fName, string lName, char gender,int born,int death);
    friend istream& operator >> (istream& in, Scientist& s);
    int getBirth();
    int getDeath();
    char getGender();
    string getFirstName();
    string getLastName();


private:
    char _gender;
    string _firstName, _lastName;
    int _born, _death;
};

#endif // SCIENTIST_H

