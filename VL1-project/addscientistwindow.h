#ifndef ADDSCIENTISTWINDOW_H
#define ADDSCIENTISTWINDOW_H
#include "servicelayer.h"
#include "scientist.h"

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

private:
    ServiceLayer _service();
    vector<Scientist> scientistVector;
    Ui::addScientistWindow *ui;
};

#endif // ADDSCIENTISTWINDOW_H
