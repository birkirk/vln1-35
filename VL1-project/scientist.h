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
    string getInfo();
    QByteArray getPicture();
    bool hasPicture();
    bool hasInfo();
    void addInfo(string ing);
private:
    char _gender;
    string _name, _info;
    QByteArray _picture;
    int _born, _death;
    bool _hasPicture, _hasInfo;
};

#endif // SCIENTIST_H

