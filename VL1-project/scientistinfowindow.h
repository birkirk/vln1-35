#ifndef SCIENTISTINFOWINDOW_H
#define SCIENTISTINFOWINDOW_H
#include "scientist.h"
#include "computer.h"
#include "servicelayer.h"
#include "const.h"

#include <QDialog>

namespace Ui {
class scientistInfoWindow;
}

class scientistInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit scientistInfoWindow(QWidget *parent = 0);
    explicit scientistInfoWindow(Scientist selectedScientist, QWidget *parent = 0);

    ~scientistInfoWindow();

private slots:


    void on_button_infosci_done_clicked();

    void on_table_infosci_connections_clicked(const QModelIndex &index);

    void on_button_infosci_remove_clicked();

    void on_button_infosci_add_clicked();

private:
    void setUpSci(Scientist selectedScientist);
    void displayConnections(Scientist selectedScientist);
    void setScientist(Scientist selectedScientist);
    Ui::scientistInfoWindow *ui;

    ServiceLayer _service;
    Scientist _selectedScientist;
    vector<Computer> _currentlyConnected;
};

#endif // SCIENTISTINFOWINDOW_H
