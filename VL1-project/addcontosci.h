#ifndef ADDCONTOSCI_H
#define ADDCONTOSCI_H
#include "scientist.h"
#include "computer.h"
#include "servicelayer.h"
#include <string>

#include <QDialog>

namespace Ui {
class addConToSci;
}

class addConToSci : public QDialog
{
    Q_OBJECT

public:
    explicit addConToSci(QWidget *parent = 0);
    explicit addConToSci(Scientist selectedScientist, QWidget *parent = 0);
    ~addConToSci();

private slots:
    void on_input_consci_search_textChanged(const QString &arg1);

    void on_table_consci_connections_clicked(const QModelIndex &index);

    void on_button_consci_connect_clicked();

    void on_button_consci_done_clicked();

private:
    void setUpAvalibleCon();
    void setScientist(Scientist selectedScientist);
    void displayComputers(vector<Computer> computers);

    Ui::addConToSci *ui;
    ServiceLayer _service;
    Scientist _selectedScientist;
    vector<Computer> _currentlyDisplaydedComputers;
};

#endif // ADDCONTOSCI_H
