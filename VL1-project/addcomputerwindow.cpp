#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"

addComputerWindow::addComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addComputerWindow)
{
    ui->setupUi(this);
    vector<string> types = _service.getTypes();
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
}


