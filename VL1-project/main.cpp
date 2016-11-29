#include <iostream>
<<<<<<< HEAD
#include "scientist.h"
#include "datalayer.h"
=======
#include "userinterface.h"

>>>>>>> 01248c3250f9ed792159436e716bf8e1c842e66f
using namespace std;

int main()
{
    UserInterface ui;

    ui.run();

    DataLayer data;
    for(int i = 0; i < data.dataVector.size(); i++)
    {
        cout << data.dataVector[i].getName() << endl;
        cout << data.dataVector[i].getBirth() << endl;

    }
    return 0;

}
