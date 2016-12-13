#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "servicelayer.h"
using namespace std;
#include <vector>
#include <string>
#include <QMessageBox>


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

    void on_table_display_scientists_clicked(const QModelIndex &index);

    void on_button_remove_scientists_clicked();

    void on_input_search_computers_textChanged(const QString &arg1);

    void on_table_display_computers_clicked(const QModelIndex &index);

    void on_button_remove_computers_clicked();

private:
    void displayAllScientists();
    void displayScientists(vector<Scientist> sceintists);
    void displayAllComputers();
    void displayComputers(vector<Computer> computers);
    vector<Scientist> currentlyDisplaydedScientists;
    vector<Computer> currentlyDisplaydedComputers;

    Ui::MainWindow *ui;
    ServiceLayer _service;
};

#endif // MAINWINDOW_H
