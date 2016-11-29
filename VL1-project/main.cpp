#include <iostream>
#include "scientist.h"
#include "datalayer.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;

    DataLayer data;
    for(int i = 0; i < data.dataVector.size(); i++)
    {
        cout << data.dataVector[i].getName() << endl;
        cout << data.dataVector[i].getBirth() << endl;

    }
    return 0;

}
