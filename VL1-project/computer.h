#ifndef COMPUTER_H
#define COMPUTER_H
#include <vector>
#include <string>
#include <QtSql>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(bool ifMade, string name, string type, int yearMade);
    Computer(bool ifMade, string name, string type, int yearMade, QByteArray pict);
    
    QByteArray getPicture();
    int getYearMade();
    bool getIfMade();
    string getName();
    string getType();
    bool hasPicture();
private:
    bool _ifMade, _hasPicture;
    string _name, _type;
    int _yearMade;
    QByteArray _picture;
};

#endif // SCIENTIST_H

