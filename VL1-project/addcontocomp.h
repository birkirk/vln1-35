#ifndef ADDCONTOCOMP_H
#define ADDCONTOCOMP_H
#include "scientist.h"
#include "computer.h"
#include "servicelayer.h"
#include <string>
#include "const.h"

#include <QDialog>

namespace Ui {
class addConToComp;
}

class addConToComp : public QDialog
{
    Q_OBJECT

public:
    explicit addConToComp(QWidget *parent = 0);
    explicit addConToComp(Computer selectedComputer, QWidget *parent = 0);
    ~addConToComp();

private slots:


    void on_input_concomp_search_textChanged(const QString &arg1);

    void on_table_concomp_connections_clicked(const QModelIndex &index);

    void on_button_concomp_connect_clicked();

    void on_button_concomp_done_clicked();

private:
    void setUpAvalibleCon();
    void setComputer(Computer selectedComputer);
    void displayScientists(vector<Scientist> scientists);

    Ui::addConToComp *ui;
    ServiceLayer _service;
    Computer _selectedComputer;
    vector<Scientist> _currentlyDisplayedScientists;
};

#endif // ADDCONTOCOMP_H
