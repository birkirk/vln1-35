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
    string addScientist(Scientist newScientist);
    vector<Scientist> dataVector;
private:

};



#endif // DATALAYER_H

