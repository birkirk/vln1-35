#ifndef EDITCOMPUTERWINDOW_H
#define EDITCOMPUTERWINDOW_H
#include "scientist.h"
#include "const.h"
#include "computer.h"
#include "servicelayer.h"

#include <QDialog>

namespace Ui {
class editComputerWindow;
}

class editComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editComputerWindow(QWidget *parent = 0);
    explicit editComputerWindow(Computer selectedComputer, QWidget *parent = 0);
    ~editComputerWindow();

private slots:
    void on_button_editcomp_browse_image_clicked();

    void on_button_editcomp_cancel_clicked();

    void on_button_editcomp_save_clicked();

    void on_input_editcomp_type_currentIndexChanged(int index);

private:
    Ui::editComputerWindow *ui;
    ServiceLayer _service;
    Computer _selectedComputer;
    void displayScientistInfo(Computer selectedComputer);
};

#endif // EDITCOMPUTERWINDOW_H
