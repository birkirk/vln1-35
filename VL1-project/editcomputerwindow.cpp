#include "editcomputerwindow.h"
#include "ui_editcomputerwindow.h"

editComputerWindow::editComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputerWindow)
{
    ui->setupUi(this);
}

editComputerWindow::~editComputerWindow()
{
    delete ui;
}
