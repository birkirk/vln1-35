#ifndef EDITSCIENTISTWINDOW_H
#define EDITSCIENTISTWINDOW_H

#include <QDialog>

namespace Ui {
class editScientistWindow;
}

class editScientistWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editScientistWindow(QWidget *parent = 0);
    ~editScientistWindow();

private:
    Ui::editScientistWindow *ui;
};

#endif // EDITSCIENTISTWINDOW_H
