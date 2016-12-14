#ifndef COMPUTERINFOWINDOW_H
#define COMPUTERINFOWINDOW_H
#include "servicelayer.h"
#include "computer.h"
#include <QDialog>

namespace Ui {
class computerInfoWindow;
}

class computerInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit computerInfoWindow(QWidget *parent = 0);
    explicit computerInfoWindow(Computer selectedComputer, QWidget *parent = 0);
    ~computerInfoWindow();

private:
    void setUpComp(Computer selectedComputer);
    Ui::computerInfoWindow *ui;
};

#endif // COMPUTERINFOWINDOW_H
