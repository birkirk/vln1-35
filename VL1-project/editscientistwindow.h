#ifndef EDITSCIENTISTWINDOW_H
#define EDITSCIENTISTWINDOW_H
#include "scientist.h"
#include "const.h"
#include "computer.h"
#include "servicelayer.h"

#include <QDialog>

namespace Ui {
class editScientistWindow;
}

class editScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editScientistWindow(QWidget *parent = 0);
    explicit editScientistWindow(Scientist selectedScientist, QWidget *parent = 0);
    ~editScientistWindow();

private slots:
    void on_button_editsci_browse_clicked();

private:
    Ui::editScientistWindow *ui;

    void displayScientistInfo(Scientist selectedScientist);
    ServiceLayer _service;
    Scientist _selectedScientist;
};

#endif // EDITSCIENTISTWINDOW_H
