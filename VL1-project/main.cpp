#include <iostream>
#include "userinterface.h"
#include <QSqlQuery>
#include <QDebug>

using namespace std;

int main()
{
    DataLayer data("../ScienceData.sqlite");
    data.addScientist("Antonius", 1995, 0, 'm');
    //UserInterface ui;
    //ui.run();


    return 0;

}
