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
    QByteArray getImage();
    bool hasImage();
private:
    char _gender;
    string _name;
    QByteArray _image;
    int _born, _death;
    bool _hasImage;
};

#endif // SCIENTIST_H

