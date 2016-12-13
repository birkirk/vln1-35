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

    void on_button_addnew_scientists_clicked();

    void on_button_addnew_computers_clicked();

    void on_table_removed_scientists_clicked(const QModelIndex &index);

    void on_table_removed_computers_clicked(const QModelIndex &index);

    void on_button_recover_scientists_clicked();

    void on_button_recover_computers_clicked();

    void on_button_recover_all_scientists_clicked();

    void on_button_recover_all_computers_clicked();

private:
    void displayAllScientists();
    void displayAllComputers();
    void displayAllRemovedScientists();
    void displayAllRemovedComputers();
    void displayScientists(vector<Scientist> scientists);
    void displayComputers(vector<Computer> computers);
    void displayRemovedScientists(vector<Scientist> scientists);
    void displayRemovedComputers(vector<Computer> computers);
    vector<Scientist> currentlyDisplaydedScientists;
    vector<Computer> currentlyDisplaydedComputers;
    vector<Scientist> currentlyRemovedScientists;
    vector<Computer> currentlyRemovedComputers;

    Ui::MainWindow *ui;
    ServiceLayer _service;
};

#endif // MAINWINDOW_H
