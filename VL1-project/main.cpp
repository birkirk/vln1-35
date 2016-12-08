#include <iostream>
#include "userinterface.h"
#include <QSqlQuery>
#include <QDebug>

using namespace std;

int main()
{


    UserInterface ui;
    ui.info();
    ui.run();

    return 0;

}
