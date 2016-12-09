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
    void deleteSom();
    void printSciToComp();
    void printCompToSci();
    void clear();
    void generateJoke();
    void info();
    void readMe();
    
    vector<Scientist> searchScientist();
    vector<Computer> searchComputer();
    
    friend ostream& operator << (ostream& out, vector<Scientist> vScientist);
    friend ostream& operator << (ostream& out, vector<Computer> vComputers);
private:
    ServiceLayer _service;
};

#endif // USERINTERFACE_H
