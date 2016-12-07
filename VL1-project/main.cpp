#include <iostream>
#include "userinterface.h"
#include <QSqlQuery>
#include <QDebug>

using namespace std;

int main()
{

    UserInterface ui;
    ui.run();
/*
    DataLayer data;
    vector<Scientist> sciVector = data.searchSci("Abu", 'm', 1895, 3000);
    cout << sciVector.size();
    for(int i = 0; i < sciVector.size(); i++)
    {
        cout << sciVector[i].getName();
    }
*/
    return 0;

}
