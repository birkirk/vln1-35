#ifndef EDITCOMPUTERWINDOW_H
#define EDITCOMPUTERWINDOW_H

#include <QDialog>

namespace Ui {
class editComputerWindow;
}

class editComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editComputerWindow(QWidget *parent = 0);
    ~editComputerWindow();

private:
    Ui::editComputerWindow *ui;
};

#endif // EDITCOMPUTERWINDOW_H
