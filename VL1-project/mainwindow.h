#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "servicelayer.h"
using namespace std;
#include <vector>
#include <string>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_input_search_scientists_textChanged(const QString &arg1);

private:
    void displayAllScientists();
    void displayScientists(vector<Scientist> sceintists);

    Ui::MainWindow *ui;
    ServiceLayer _service;
};

#endif // MAINWINDOW_H
