#include <iostream>
#include "userinterface.h"
#include <QSqlQuery>
#include <QDebug>

using namespace std;

int main()
{
    DataLayer data("../ScienceData.sqlite");
    data.addScientist("Rikhardur", 1295, 2020, 'm');
   // UserInterface ui;

    //Calls function run() to run the program
    //ui.run();

    return 0;

}
