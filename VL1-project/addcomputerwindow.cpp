#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"

addComputerWindow::addComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerWindow)
{
    ui->setupUi(this);
    vector<string> types = _service.getTypes();

    ui->input_addcomp_type->addItem(QString::fromStdString(""));
    for(unsigned int i = 0; i < types.size(); i++)
    {
        ui->input_addcomp_type->addItem(QString::fromStdString(types[i]));
    }
    ui->input_addcomp_type->addItem(QString::fromStdString("Add new type"));
    ui->input_addcomp_yearmade->setReadOnly(true);

    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    ui->input_addcomp_yearmade->setPalette(*palette);
}

addComputerWindow::~addComputerWindow()
{
    delete ui;
}


void addComputerWindow::on_checkbox_addcomp_made_stateChanged(int arg1)
{
    if(ui->checkbox_addcomp_made->isChecked())
    {
        ui->input_addcomp_yearmade->setReadOnly(false);
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::white);
        ui->input_addcomp_yearmade->setPalette(*palette);
    }
    else
    {
        ui->input_addcomp_yearmade->setReadOnly(true);
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::gray);
        ui->input_addcomp_yearmade->setPalette(*palette);
    }
}

void addComputerWindow::on_button_addcomp_add_clicked()
{
    bool isValidEntry = true;
    if(ui->input_addcomp_name->text().length() == 0)
    {
        ui->label_addcomp_status->setText(QString::fromStdString("Name cannot be empty!"));
        isValidEntry = false;
    }
    if(ui->checkbox_addcomp_made->isChecked() && ui->input_addcomp_yearmade->text().length() == 0)
    {
        ui->label_addcomp_status->setText(QString::fromStdString("Dont forget to input year made!"));
        isValidEntry = false;
    }
    if(ui->input_addcomp_type->currentText().length() == 0)
    {
        ui->label_addcomp_status->setText("Type cannot be empty!");
        isValidEntry = false;
    }

    if(isValidEntry)
    {
        int yearMade;
        if(ui->checkbox_addcomp_made->isChecked())
        {
            QString qYearMade = ui->input_addcomp_yearmade->text();
            string sYearMade = qYearMade.toStdString();
            yearMade = atoi(sYearMade.c_str());
        }
        else yearMade = 0;
        Computer newComp(ui->checkbox_addcomp_made->isChecked(), ui->input_addcomp_name->text().toStdString(),
                         ui->input_addcomp_type->currentText().toStdString(), yearMade);
        _computerVector.push_back(newComp);

        ui->checkbox_addcomp_made->setChecked(false);
        ui->label_addcomp_status->setText(QString::fromStdString(""));
        ui->input_addcomp_name->setText(QString::fromStdString(""));
        ui->input_addcomp_yearmade->setText(QString::fromStdString(""));
        ui->input_addcomp_type->setCurrentIndex(0);
    }
}



void addComputerWindow::on_button_addcomp_done_clicked()
{
    for(unsigned int i = 0; i < _computerVector.size(); i++)
    {
        _service.addComputer(_computerVector[i]);
    }
    this->done(1);
}
