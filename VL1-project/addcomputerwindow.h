#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H
#include "servicelayer.h"
#include "computer.h"
#include <string>



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

    void on_checkbox_addcomp_made_stateChanged(int arg1);

    void on_button_addcomp_add_clicked();


    void on_button_addcomp_done_clicked();

    void on_button_addcomp_browse_image_clicked();

private:
    vector<Computer> _computerVector;
    Ui::addComputerWindow *ui;
    ServiceLayer _service;
};

#endif // ADDCOMPUTERWINDOW_H
