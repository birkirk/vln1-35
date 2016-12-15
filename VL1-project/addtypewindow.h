#ifndef ADDTYPEWINDOW_H
#define ADDTYPEWINDOW_H
#include "servicelayer.h"

#include <QDialog>

namespace Ui {
class addTypeWindow;
}

class addTypeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addTypeWindow(QWidget *parent = 0);
    ~addTypeWindow();

private slots:
    void on_button_addtype__clicked();

    void on_button_addtype_done_clicked();

private:
    ServiceLayer _service;
    Ui::addTypeWindow *ui;
};

#endif // ADDTYPEWINDOW_H
