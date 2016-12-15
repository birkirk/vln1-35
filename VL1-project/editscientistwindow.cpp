#include "editscientistwindow.h"
#include "ui_editscientistwindow.h"

editScientistWindow::editScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editScientistWindow)
{
    ui->setupUi(this);
}

editScientistWindow::~editScientistWindow()
{
    delete ui;
}
