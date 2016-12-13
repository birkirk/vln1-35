#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H
#include "servicelayer.h"
#include "computer.h"
#include <string>
#include "computer.h"


#include <QDialog>

namespace Ui {
class addComputerWindow;
}

class addComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addComputerWindow(QWidget *parent = 0);
    ~addComputerWindow();

private slots:

    void on_checkBox_made_stateChanged(int arg1);

    void on_pushButton_add_compter_clicked();


    void on_pushButton_done_clicked();

private:
    vector<Computer> _computerVector;
    Ui::addComputerWindow *ui;
    ServiceLayer _service;
};

#endif // ADDCOMPUTERWINDOW_H
