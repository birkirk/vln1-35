#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>
#include <QtSql>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, char gender,int born,int death);
    Scientist(string name, char gender, int born, int death, QByteArray img);
    
    int getBirth();
    int getDeath();
    char getGender();
    string getName();
    QByteArray getPicture();
    bool hasPicture();
private:
    char _gender;
    string _name;
    QByteArray _picture;
    int _born, _death;
    bool _hasPicture;
};

#endif // SCIENTIST_H

