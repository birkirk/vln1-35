#ifndef SCIENTISTINFOWINDOW_H
#define SCIENTISTINFOWINDOW_H
#include "scientist.h"
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

private:
    void setUpSci(Scientist selectedScientist);
    void displayConnections(Scientist selectedScientist);
    Ui::scientistInfoWindow *ui;

    ServiceLayer _service;
};

#endif // SCIENTISTINFOWINDOW_H
