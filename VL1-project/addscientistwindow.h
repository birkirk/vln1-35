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
    void on_pushbutton_add_scientist_clicked();

    void on_pushbutton_done_clicked();

private:
    ServiceLayer _service;
    vector<Scientist> scientistVector;
    Ui::addScientistWindow *ui;
};

#endif // ADDSCIENTISTWINDOW_H
