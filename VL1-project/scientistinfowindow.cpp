#include "scientistinfowindow.h"
#include "ui_scientistinfowindow.h"

scientistInfoWindow::scientistInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistInfoWindow)
{
    ui->setupUi(this);
    //ui->label_scientist_name->setText();
}

scientistInfoWindow::~scientistInfoWindow()
{
    delete ui;
}
