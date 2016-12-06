#include "datalayer.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>



using namespace std;
DataLayer::DataLayer()
{

}

DataLayer::DataLayer(const QString& path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
    
}





//Reads the database file
vector<Scientist> DataLayer::readSci() {
    vector<Scientist> tempV;
    return tempV;
}

vector<Computer> DataLayer::readComp() {
    vector<Computer> tempV;
    
    return tempV;
}


//Clears the whole database
void DataLayer::clearFile() {
    
}

