#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "servicelayer.h"


class UserInterface
{
public:
    UserInterface();
    void run();
    void addSci();
    void addComp();
    void list();
    
    friend ostream& operator << (ostream& out, vector<Scientist> vScientist);
private:
    ServiceLayer _service;
};

#endif // USERINTERFACE_H
