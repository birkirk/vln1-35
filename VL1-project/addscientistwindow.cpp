#include "addscientistwindow.h"
#include "ui_addscientistwindow.h"
#include <string>
#include <QFileDialog>


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

void addScientistWindow::on_button_addsci_add_clicked()
{
    string name = ui->input_addsci_name->text().toStdString();
    string sBirth = ui->input_addsci_born->text().toStdString();
    string sGender = ui->input_addsci_died->text().toStdString();
    QString qBirth = ui->input_addsci_born->text();
    QString qDeath = ui->input_addsci_died->text();
    int birth = qBirth.toInt();
    int death = qDeath.toInt();
    if(name.length() == 0)
    {
        ui->label_addsci_status->setText(QString::fromStdString("Name cannot be empty!"));
        // do nothing
    }
    else if(sBirth.length() == 0)
    {
        ui->label_addsci_status->setText(QString::fromStdString("Year of birth cannot be empty!"));
    }
    else if(sGender.length() == 0)
    {
        ui->label_addsci_status->setText(QString::fromStdString("Gender cannot be empty!"));
    }

    if(name.length() > 0 && sBirth.length() > 0 && sGender.length() > 0 )
    {
        char gender;
        if(sGender == "Male") gender = 'm';
        else if(sGender == "Female") gender = 'f';
        QFile file(ui->input_addsci_path->text());

        if(ui->input_addsci_path->text().length() != 0 && file.open(QIODevice::ReadOnly))
        {
            QByteArray inByteArray = file.readAll();
            Scientist newScientist(name, gender, birth, death, inByteArray);
            _scientistVector.push_back(newScientist);
        }
        else
        {
            Scientist newScientist(name, gender, birth, death);
            _scientistVector.push_back(newScientist);
        }
        ui->label_addsci_status->setText(QString::fromStdString(""));
        ui->input_addsci_name->setText(QString::fromStdString(""));
        ui->input_addsci_born->setText(QString::fromStdString(""));
        ui->input_addsci_died->setText(QString::fromStdString(""));
        ui->input_addsci_gender->setCurrentIndex(0);
    }
}

void addScientistWindow::on_button_addsci_done_clicked()
{
    for(unsigned int i = 0; i < _scientistVector.size(); i++)
    {
        _service.addScientitst(_scientistVector[i]);
    }
    this->done(1);
}

void addScientistWindow::on_button_addsci_browse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                    "Search for image",
                                    "",
                                    "Image files (*.png *.jpg");
    ui->input_addsci_path->setText(filePath);
}
