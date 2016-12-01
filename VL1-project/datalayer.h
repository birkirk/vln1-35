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
    friend istream& operator >> (istream& in, Scientist& s);
    friend ostream& operator << (ostream& out, Scientist aScientist);
    void addScientist(Scientist newScientist);
    vector<Scientist> readFile();
    void clearFile();
    void writeFile(vector<Scientist> vScientist);
private:
    vector<Scientist> dataVector;
};



#endif // DATALAYER_H

