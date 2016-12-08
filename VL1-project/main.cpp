#include <iostream>
#include "userinterface.h"
#include <QSqlQuery>
#include <QDebug>

using namespace std;

int main()
{


    UserInterface ui;
    
    //Runs Group 35 Display
    ui.info();
    
    //Runs main program
    ui.run();

    return 0;

}
