#include <iostream>
#include "userinterface.h"
#include <QSqlQuery>
#include <QDebug>

using namespace std;

int main()
{
    UserInterface ui;

    //Calls function run() to run the program
    ui.run();


    DataLayer data("../ScienceData.sqlite");
    data.addScientist("Helgi", 1995, 2005, 'm');
/*

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../ScientistData.sqlite");
    db.open();


    QSqlQuery query;
        query.prepare("SELECT* FROM Scientists");
        query.exec();

while (query.next()) {
       QString name = query.value(1).toString();
       qDebug() << name;
}
*/


    return 0;

}
