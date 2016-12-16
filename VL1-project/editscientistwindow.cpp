#include "editscientistwindow.h"
#include "ui_editscientistwindow.h"
#include <string>
#include <QFileDialog>


editScientistWindow::editScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editScientistWindow)
{
    ui->setupUi(this);
}

editScientistWindow::editScientistWindow(Scientist selectedScientist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editScientistWindow)
{
    ui->setupUi(this);
    displayScientistInfo(selectedScientist);
    _selectedScientist = selectedScientist;
}

editScientistWindow::~editScientistWindow()
{
    delete ui;
}

void editScientistWindow::displayScientistInfo(Scientist selectedScientist)
{
    QString name = QString::fromStdString(selectedScientist.getName());
    QString born = QString::number(selectedScientist.getBirth());
    QString died;
    if(selectedScientist.getDeath() == ifDead)
    {
        died = QString::fromStdString("");
    }
    else
    {
        died = QString::number(selectedScientist.getDeath());
    }
    int gender;
    if(selectedScientist.getGender() == 'm' || selectedScientist.getGender() == 'M')
    {
        gender = 1;
    }
    else
    {
        gender = 2;
    }

    if(selectedScientist.hasInfo())
    {
        ui->input_editsci_info->setText(QString::fromStdString(selectedScientist.getInfo()));
    }

    ui->input_editsci_name->setText(name);
    ui->input_editsci_gender->setCurrentIndex(gender);
    ui->input_editsci_born->setText(born);
    ui->input_editsci_died->setText(died);
}

void editScientistWindow::on_button_editsci_browse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                    "Search for image",
                                    "",
                                    "Image files (*.png *.jpg");
    ui->input_editsci_path->setText(filePath);
}

void editScientistWindow::on_button_editsci_cancel_clicked()
{
    this->done(1);
}
