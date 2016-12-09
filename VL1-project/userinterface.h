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

    vector<Scientist> searchScientist();
    vector<Computer> searchComputer();


    void clear();
    
    void printSciToComp();
    void printCompToSci();

    
    friend ostream& operator << (ostream& out, vector<Scientist> vScientist);
    friend ostream& operator << (ostream& out, vector<Computer> vComputers);
    
    void generateJoke();
    void info();
    void readMe();
private:
    ServiceLayer _service;
};

#endif // USERINTERFACE_H
