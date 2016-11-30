#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "servicelayer.h"


class UserInterface
{
public:
    UserInterface();
    // main mennu
    void run();
    friend ostream& operator << (ostream& out, vector<Scientist> sVector);
    void printOut(vector<Scientist> vScientist);
private:
    ServiceLayer service;
};

#endif // USERINTERFACE_H
