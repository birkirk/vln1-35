#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "servicelayer.h"


class UserInterface
{
public:
    UserInterface();

    // main mennu
    void run();
private:
    ServiceLayer service;
};

#endif // USERINTERFACE_H
