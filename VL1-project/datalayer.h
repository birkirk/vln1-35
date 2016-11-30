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
    vector<Scientist> dataVector;
    void readFile();
private:

};



#endif // DATALAYER_H

