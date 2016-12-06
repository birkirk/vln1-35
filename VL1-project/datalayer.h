#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include "computer.h"
#include "scientist.h"

using namespace std;

class DataLayer
{
public:
    DataLayer();
    void addScientist(Scientist newScientist);
    vector<Scientist> readSci();
    vector<Computer> readComp();
    void clearFile();
    void writeFile(vector<Scientist> vScientist);
private:
    vector<Scientist> dataVector;
};



#endif // DATALAYER_H

