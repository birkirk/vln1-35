using namespace std;
#include "mainwindow.h"
#include "addwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    addWindow w;
    w.show();

    return a.exec();
}
