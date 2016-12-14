#ifndef ADDSCIENTISTWINDOW_H
#define ADDSCIENTISTWINDOW_H
#include "scientist.h"
#include "servicelayer.h"

#include <QDialog>

namespace Ui {
class addScientistWindow;
}

class addScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addScientistWindow(QWidget *parent = 0);
    ~addScientistWindow();

private slots:
    void on_button_addsci_add_clicked();

    void on_button_addsci_done_clicked();

    void on_button_browse_clicked();
    void on_button_addsci_browse_clicked();

private:
    ServiceLayer _service;
    vector<Scientist> _scientistVector;
    Ui::addScientistWindow *ui;
};

#endif // ADDSCIENTISTWINDOW_H
