#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"

addComputerWindow::addComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerWindow)
{
    ui->setupUi(this);
    vector<string> types = _service.getTypes();

    ui->combobox_type->addItem(QString::fromStdString(""));
    for(unsigned int i = 0; i < types.size(); i++)
    {
        ui->combobox_type->addItem(QString::fromStdString(types[i]));
    }
    ui->combobox_type->addItem(QString::fromStdString("Add new type"));
    ui->lineEdit_year_made->setReadOnly(true);

    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Base,Qt::gray);
    ui->lineEdit_year_made->setPalette(*palette);
}

addComputerWindow::~addComputerWindow()
{
    delete ui;
}


void addComputerWindow::on_checkBox_made_stateChanged(int arg1)
{
    if(ui->checkBox_made->isChecked())
    {
        ui->lineEdit_year_made->setReadOnly(false);
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::white);
        ui->lineEdit_year_made->setPalette(*palette);
    }
    else
    {
        ui->lineEdit_year_made->setReadOnly(true);
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::gray);
        ui->lineEdit_year_made->setPalette(*palette);
    }
}

void addComputerWindow::on_pushButton_add_compter_clicked()
{
    bool isValidEntry = true;
    if(ui->lineEdit_name_input->text().length() == 0)
    {
        ui->label_name_alarm->setText(QString::fromStdString("Name cannot be empty!"));
        isValidEntry = false;
    }
    if(ui->checkBox_made->isChecked() && ui->lineEdit_year_made->text().length() == 0)
    {
        ui->label_made_alarm->setText(QString::fromStdString("Dont forget to input year made!"));
        isValidEntry = false;
    }
    if(ui->combobox_type->currentText().length() == 0)
    {
        ui->label_type_alarm->setText("Type cannot be empty!");
        isValidEntry = false;
    }

    if(isValidEntry)
    {
        int yearMade;
        if(ui->checkBox_made->isChecked())
        {
            QString qYearMade = ui->lineEdit_year_made->text();
            string sYearMade = qYearMade.toStdString();
            yearMade = atoi(sYearMade.c_str());
        }
        else yearMade = 0;
        Computer newComp(ui->checkBox_made->isChecked(), ui->lineEdit_name_input->text().toStdString(),
                         ui->combobox_type->currentText().toStdString(), yearMade);
        _computerVector.push_back(newComp);

        ui->checkBox_made->setChecked(false);
        ui->label_made_alarm->setText(QString::fromStdString(""));
        ui->label_name_alarm->setText(QString::fromStdString(""));
        ui->label_type_alarm->setText(QString::fromStdString(""));
        ui->lineEdit_name_input->setText(QString::fromStdString(""));
        ui->lineEdit_year_made->setText(QString::fromStdString(""));
        ui->combobox_type->setCurrentIndex(0);
    }
}



void addComputerWindow::on_pushButton_done_clicked()
{
    for(unsigned int i = 0; i < _computerVector.size(); i++)
    {
        _service.addComputer(_computerVector[i]);
    }
    this->done(1);
}
