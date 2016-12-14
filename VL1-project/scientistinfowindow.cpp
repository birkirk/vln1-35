#include "scientistinfowindow.h"
#include "ui_scientistinfowindow.h"

scientistInfoWindow::scientistInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistInfoWindow)
{
    ui->setupUi(this);

}

scientistInfoWindow::scientistInfoWindow(Scientist selectedScientist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistInfoWindow)
{
    ui->setupUi(this);
    setUpSci(selectedScientist);

}

scientistInfoWindow::~scientistInfoWindow()
{
    delete ui;
}

void scientistInfoWindow::setUpSci(Scientist selectedScientist)
{
    QString name = QString::fromStdString(selectedScientist.getName());
    QString born = QString::number(selectedScientist.getBirth());
    QString died;
    if(selectedScientist.getDeath() == ifDead)
    {
        died = QString::fromStdString("?");
    }
    else
    {
        died = QString::number(selectedScientist.getDeath());
    }
    QString gender;
    if(selectedScientist.getGender() == 'm' || selectedScientist.getGender() == 'M')
    {
        gender = QString::fromStdString("Male");
    }
    else
    {
        gender = QString::fromStdString("Female");
    }

    ui->label_infosci_name->setText(name);
    ui->label_infosci_gender->setText(gender);
    ui->label_infosci_life->setText(born + " - " + died);
}

