#include "scientistinfowindow.h"
#include "ui_scientistinfowindow.h"

scientistInfoWindow::scientistInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistInfoWindow)
{
    ui->setupUi(this);
}

scientistInfoWindow::~scientistInfoWindow()
{
    delete ui;
}
