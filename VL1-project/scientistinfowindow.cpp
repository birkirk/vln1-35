#include "scientistinfowindow.h"
#include "ui_scientistinfowindow.h"

scientistInfoWindow::scientistInfoWindow(QWidget *parent, Scientist sci) :
    QDialog(parent),
    ui(new Ui::scientistInfoWindow)
{
    ui->setupUi(this);
    ui->label_scientist_name->setText();
}

scientistInfoWindow::~scientistInfoWindow()
{
    delete ui;
}
