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

    vector<string> types = _service.getTypes();

    ui->input_editcomp_type->addItem(QString::fromStdString(""));
    for(unsigned int i = 0; i < types.size(); i++)
    {
        ui->input_editcomp_type->addItem(QString::fromStdString(types[i]));
    }
    ui->input_editcomp_type->addItem(QString::fromStdString("Add new type"));

    if(selectedComputer.hasInfo())
    {
        ui->input_editcomp_info->setText(QString::fromStdString(selectedComputer.getInfo()));
    }

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

void editComputerWindow::on_button_editcomp_save_clicked()
{
    QFile file(ui->input_editcomp_path->text());
    file.open(QIODevice::ReadOnly);
    bool isValidEntry = true;
    if(ui->input_editcomp_name->text().length() == 0)
    {
        ui->label_editcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Name cannot be empty!</span>"));
        isValidEntry = false;
    }
    if(ui->checkbox_editcomp_made->isChecked() && ui->input_editcomp_yearmade->text().length() == 0)
    {
        ui->label_editcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Dont forget to input year made!</span>"));
        isValidEntry = false;
    }
    if(ui->input_editcomp_type->currentText().length() == 0)
    {
        ui->label_editcomp_status->setText("<span style='color: #E94949'>Type cannot be empty!</span>");
        isValidEntry = false;
    }
    if(!file.isOpen() && ui->input_editcomp_path->text() != "")
    {
        ui->label_editcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Invalid input in image path!</span>"));
        isValidEntry = false;
    }
    if(ui->input_editcomp_type->currentText() == "Add new type")
    {
        isValidEntry = false;
        ui->label_editcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Choose type!</span>"));
    }

    if(isValidEntry)
    {
        int yearMade;
        if(ui->checkbox_editcomp_made->isChecked())
        {
            QString qYearMade = ui->input_editcomp_yearmade->text();
            string sYearMade = qYearMade.toStdString();
            yearMade = atoi(sYearMade.c_str());
        }
        else yearMade = 0;

        if(ui->input_editcomp_path->text().length() != 0 && file.isOpen())
        {
            QByteArray picture = file.readAll();
            Computer newComputer(ui->checkbox_editcomp_made->isChecked(), ui->input_editcomp_name->text().toStdString(),
                                 ui->input_editcomp_type->currentText().toStdString(), yearMade, picture);
            if(ui->input_editcomp_info->toPlainText() != "")
            {
                newComputer.addInfo(ui->input_editcomp_info->toPlainText().toStdString());
            }
            _service.updateComputer(_selectedComputer, newComputer);
        }
        else
        {
            Computer newComp(ui->checkbox_editcomp_made->isChecked(), ui->input_editcomp_name->text().toStdString(),
                             ui->input_editcomp_type->currentText().toStdString(), yearMade);
            if(ui->input_editcomp_info->toPlainText() != "")
            {
                newComp.addInfo(ui->input_editcomp_info->toPlainText().toStdString());
            }

            _service.updateComputer(_selectedComputer, newComp);
        }
        this->done(1);
    }
}
