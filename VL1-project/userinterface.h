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
    void connect();

    vector<Scientist> search();


    void clear();

    
    friend ostream& operator << (ostream& out, vector<Scientist> vScientist);
    friend ostream& operator << (ostream& out, vector<Computer> vComputers);
    
    void generateJoke();
    void info();
private:
    ServiceLayer _service;
};

#endif // USERINTERFACE_H
