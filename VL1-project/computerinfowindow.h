#ifndef COMPUTERINFOWINDOW_H
#define COMPUTERINFOWINDOW_H
#include "servicelayer.h"
#include "computer.h"
#include "scientist.h"
#include "const.h"
#include <QDialog>

namespace Ui {
class computerInfoWindow;
}

class computerInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit computerInfoWindow(QWidget *parent = 0);
    explicit computerInfoWindow(Computer selectedComputer, QWidget *parent = 0);
    ~computerInfoWindow();

private slots:
    void on_button_infocomp_done_clicked();

    void on_table_infocomp_connections_clicked(const QModelIndex &index);

    void on_button_infocomp_remove_clicked();

    void on_button_infocomp_add_clicked();

private:
    void setUpComp(Computer selectedComputer);
    void displayConnections(Computer selectedComputer);
    void setComputer(Computer selectedComputer);
    Ui::computerInfoWindow *ui;

    Computer _selectedComputer;
    ServiceLayer _service;
    vector<Scientist> _currentlyConnected;
};

#endif // COMPUTERINFOWINDOW_H
