#include "addscientistwindow.h"
#include "ui_addscientistwindow.h"
#include <string>

#include <string>
addScientistWindow::addScientistWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addScientistWindow)
{
    ui->setupUi(this);

}

addScientistWindow::~addScientistWindow()
{
    delete ui;
}





void addScientistWindow::on_pushbutton_add_scientist_clicked()
{
    string name = ui->lineEdit_name_input->text().toStdString();
    string sBirth = ui->lineEdit_birth_input->text().toStdString();
    string sGender = ui->comboBox_gender_input->currentText().toStdString();
    QString qBirth = ui->lineEdit_birth_input->text();
    QString qDeath = ui->lineEdit_death_input->text();
    int birth = qBirth.toInt();
    int death = qDeath.toInt();
    if(name.length() == 0)
    {
        ui->label_name_alarm->setText(QString::fromStdString("Name cannot be empty!"));
        // do nothing
    }
    if(sBirth.length() == 0)
    {
        ui->label_birth_alarm->setText(QString::fromStdString("Year of birth cannot be empty!"));
    }
    if(sGender.length() == 0)
    {
        ui->label_gender_alarm->setText(QString::fromStdString("Gender cannot be empty!"));
    }

    if(name.length() > 0 && sBirth.length() > 0 && sGender.length() > 0 )
    {

        char gender;
        if(sGender == "Male") gender = 'm';
        else if(sGender == "Female") gender = 'f';
        Scientist newScientist(name, gender, birth, death);
        _scientistVector.push_back(newScientist);
        ui->label_birth_alarm->setText(QString::fromStdString(""));
        ui->label_name_alarm->setText(QString::fromStdString(""));
        ui->label_gender_alarm->setText(QString::fromStdString(""));
        ui->lineEdit_name_input->setText(QString::fromStdString(""));
        ui->lineEdit_death_input->setText(QString::fromStdString(""));
        ui->lineEdit_birth_input->setText(QString::fromStdString(""));
        ui->comboBox_gender_input->setCurrentIndex(0);
    }
}

void addScientistWindow::on_pushbutton_done_clicked()
{
    for(unsigned int i = 0; i < _scientistVector.size(); i++)
    {
        _service.addScientitst(_scientistVector[i]);
    }
    this->done(1);
}
