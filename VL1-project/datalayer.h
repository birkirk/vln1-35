#ifndef DATALAYER_H
#define DATALAYER_H
#include <vector>
#include <fstream>
#include "scientist.h"

using namespace std;

class DataLayer
{
public:
    DataLayer();
    void addScientist(Scientist newScientist);
    vector<Scientist> readFile();
    void writeFile(vector<Scientist> vScientist);
    friend ostream& operator << (ostream& out, Scientist aScientist);
private:
    vector<Scientist> dataVector;
};



#endif // DATALAYER_H

