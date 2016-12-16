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
    ui->input_editsci_info->setText(QString::fromStdString(selectedScientist.getInfo()));
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

void editScientistWindow::on_button_editsci_save_clicked()
{

    string name = ui->input_editsci_name->text().toStdString();
    string sBirth = ui->input_editsci_born->text().toStdString();
    string sGender = ui->input_editsci_gender->currentText().toStdString();
    string sDeath = ui->input_editsci_died->text().toStdString();
    QString qBirth = ui->input_editsci_born->text();
    QString qDeath = ui->input_editsci_died->text();
    QFile file(ui->input_editsci_path->text());
    file.open(QIODevice::ReadOnly);

    int birth = atoi(sBirth.c_str());
    int death = atoi(sDeath.c_str());
    bool validInput = true;

    if(name.length() == 0)
    {
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>Name cannot be empty!</span>"));
        validInput = false;
    }
    else if(sBirth.length() == 0)
    {
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>Year of birth cannot be empty!</span>"));
        validInput = false;
    }
    else if(birth <= 0)
    {
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>Invalid input in year of birth!</span>"));
        validInput = false;
    }
    else if(birth > currentYear)
    {
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>Year of birth must be correct!</span>"));
        validInput = false;
    }
    else if(death <= 0 && qDeath.length() != 0)
    {
        validInput = false;
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>Invalid input in year of death!</span>"));
    }
    else if(birth > death && sDeath.length() != 0)
    {
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>No one can die before they are born!</span>"));
        validInput = false;
    }
    else if(sGender.length() == 0)
    {
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>Gender cannot be empty!</span>"));
        validInput = false;
    }
    else if(!file.isOpen() && ui->input_editsci_path->text() != "")
    {
        ui->label_editsci_status->setText(QString::fromStdString("<span style='color: #E94949'>Invalid input for image path!</span>"));
        validInput = false;
    }


    if(validInput)
    {
        char gender;
        if(sGender == "Male") gender = 'm';
        else if(sGender == "Female") gender = 'f';


        if(ui->input_editsci_path->text().length() != 0 && file.isOpen())
        {
            QByteArray inByteArray = file.readAll();
            Scientist newScientist(name, gender, birth, death, inByteArray);
            if(ui->input_editsci_info->toPlainText() != "")
            {
                newScientist.addInfo(ui->input_editsci_info->toPlainText().toStdString());
            }
            _service.updateScientist(_selectedScientist, newScientist);
        }
        else
        {
            qDebug() << _selectedScientist.hasPicture();
            if(_selectedScientist.hasPicture())
            {
                Scientist newScientist(name, gender, birth, death, _selectedScientist.getPicture());
                if(ui->input_editsci_info->toPlainText() != "")
                {
                    newScientist.addInfo(ui->input_editsci_info->toPlainText().toStdString());
                }
                _service.updateScientist(_selectedScientist, newScientist);
            }
            else
            {
                Scientist newScientist(name, gender, birth, death);
                if(ui->input_editsci_info->toPlainText() != "")
                {
                    newScientist.addInfo(ui->input_editsci_info->toPlainText().toStdString());
                }
                _service.updateScientist(_selectedScientist, newScientist);
            }



        }
        this->done(1);
    }

}
