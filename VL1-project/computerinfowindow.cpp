#include "computerinfowindow.h"
#include "ui_computerinfowindow.h"

computerInfoWindow::computerInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::computerInfoWindow)
{
    ui->setupUi(this);
}

computerInfoWindow::computerInfoWindow(Computer selectedComputer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::computerInfoWindow)
{
    ui->setupUi(this);

    setUpComp(selectedComputer);
    displayConnections(selectedComputer);
}

computerInfoWindow::~computerInfoWindow()
{
    delete ui;
}

void computerInfoWindow::setUpComp(Computer selectedComputer)
{

}

void computerInfoWindow::displayConnections(Computer selectedComputer)
{

}

void computerInfoWindow::on_button_infocomp_done_clicked()
{
    this->done(1);
}
