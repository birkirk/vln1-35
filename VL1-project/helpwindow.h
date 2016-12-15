#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include "servicelayer.h"
#include <QDialog>

namespace Ui {
class helpWindow;
}

class helpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit helpWindow(QWidget *parent = 0);
    ~helpWindow();

    void displayManual();
private:
    Ui::helpWindow *ui;
    ServiceLayer _service;

};

#endif // HELPWINDOW_H
