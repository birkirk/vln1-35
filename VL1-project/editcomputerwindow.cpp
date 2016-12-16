#include "editcomputerwindow.h"
#include "ui_editcomputerwindow.h"
#include <string>
#include <QFileDialog>

editComputerWindow::editComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputerWindow)
{
    ui->setupUi(this);
}

editComputerWindow::editComputerWindow(Computer selectedComputer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editComputerWindow)
{
    ui->setupUi(this);
    _selectedComputer = selectedComputer;
    displayScientistInfo(selectedComputer);
}

editComputerWindow::~editComputerWindow()
{
    delete ui;
}

void editComputerWindow::displayScientistInfo(Computer selectedComputer)
{
    QString name = QString::fromStdString(selectedComputer.getName());
    QString type = QString::fromStdString(selectedComputer.getType());
    if(selectedComputer.getIfMade() == 1)
    {
        ui->input_editcomp_yearmade->setReadOnly(false);
        ui->checkbox_editcomp_made->setChecked(true);
    }
    else
    {
        ui->input_editcomp_yearmade->setReadOnly(true);
    }
    QString yearMade;
    if(selectedComputer.getYearMade() == 0)
    {
        yearMade = QString::fromStdString("");
    }
    else
    {
        yearMade = QString::number(selectedComputer.getYearMade());
    }

//    if(selectedComputer.hasInfo())
//    {
//        ui->input_editcomp_info->setText(QString::fromStdString(selectedComputer.getInfo()));
//    }

    ui->input_editcomp_name->setText(name);
    ui->input_editcomp_type->setCurrentText(type);
    ui->input_editcomp_yearmade->setText(yearMade);
}

void editComputerWindow::on_button_editcomp_browse_image_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                    "Search for image",
                                    "",
                                    "Image files (*.png *.jpg");
    ui->input_editcomp_path->setText(filePath);
}

void editComputerWindow::on_button_editcomp_cancel_clicked()
{
    this->done(1);
}
