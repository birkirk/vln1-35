#ifndef COMPUTERINFOWINDOW_H
#define COMPUTERINFOWINDOW_H
#include "servicelayer.h"
#include "computer.h"
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

private:
    void setUpComp(Computer selectedComputer);
    void displayConnections(Computer selectedComputer);
    Ui::computerInfoWindow *ui;

    ServiceLayer _service;
};

#endif // COMPUTERINFOWINDOW_H
