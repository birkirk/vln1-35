#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"
#include "addtypewindow.h"
#include <QFileDialog>

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
    qDebug() << "Got to palette change 1!";
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
        ui->input_addcomp_yearmade->setText(QString::fromStdString(""));
        ui->input_addcomp_yearmade->setReadOnly(true);
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::gray);
        ui->input_addcomp_yearmade->setPalette(*palette);
        qDebug() << "Got to palette change 2!";
    }
}

void addComputerWindow::on_button_addcomp_add_clicked()
{
    QFile file(ui->input_addcomp_image_path->text());
    file.open(QIODevice::ReadOnly);
    bool isValidEntry = true;
    if(ui->input_addcomp_name->text().length() == 0)
    {
        ui->label_addcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Name cannot be empty!</span>"));
        isValidEntry = false;
    }
    if(ui->checkbox_addcomp_made->isChecked() && ui->input_addcomp_yearmade->text().length() == 0)
    {
        ui->label_addcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Dont forget to input year made!</span>"));
        isValidEntry = false;
    }
    if(ui->input_addcomp_type->currentText().length() == 0)
    {
        ui->label_addcomp_status->setText("<span style='color: #E94949'>Type cannot be empty!</span>");
        isValidEntry = false;
    }
    if(!file.isOpen() && ui->input_addcomp_image_path->text() != "")
    {
        ui->label_addcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Invalid input in image path!</span>"));
        isValidEntry = false;
    }
    if(ui->input_addcomp_type->currentText() == "Add new type")
    {
        isValidEntry = false;
        ui->label_addcomp_status->setText(QString::fromStdString("<span style='color: #E94949'>Choose type!</span>"));
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

        if(ui->input_addcomp_image_path->text().length() != 0 && file.isOpen())
        {
            QByteArray picture = file.readAll();
            Computer newComputer(ui->checkbox_addcomp_made->isChecked(), ui->input_addcomp_name->text().toStdString(),
                                 ui->input_addcomp_type->currentText().toStdString(), yearMade, picture);
            if(ui->input_addcomp_description->toPlainText() != "")
            {
                newComputer.addInfo(ui->input_addcomp_description->toPlainText().toStdString());
            }
            _computerVector.push_back(newComputer);
        }
        else
        {
            Computer newComp(ui->checkbox_addcomp_made->isChecked(), ui->input_addcomp_name->text().toStdString(),
                             ui->input_addcomp_type->currentText().toStdString(), yearMade);
            if(ui->input_addcomp_description->toPlainText() != "")
            {
                newComp.addInfo(ui->input_addcomp_description->toPlainText().toStdString());
            }

            _computerVector.push_back(newComp);
        }


        ui->checkbox_addcomp_made->setChecked(false);
        ui->label_addcomp_status->setText(QString::fromStdString("<span style='color: #5EC748'>Computer successfully added!</span>"));
        ui->input_addcomp_name->setText(QString::fromStdString(""));
        ui->input_addcomp_yearmade->setText(QString::fromStdString(""));
        ui->input_addcomp_type->setCurrentIndex(0);
        ui->input_addcomp_image_path->setText(QString::fromStdString(""));
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

void addComputerWindow::on_button_addcomp_browse_image_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                    "Search for image",
                                    "",
                                    "Image files (*.png *.jpg");
    ui->input_addcomp_image_path->setText(filePath);
}

void addComputerWindow::on_input_addcomp_type_currentIndexChanged(int index)
{
    if(ui->input_addcomp_type->currentText() == "Add new type")
    {
        addTypeWindow newType;
        newType.exec();
        vector<string> types = _service.getTypes();
        ui->input_addcomp_type->clear();
        for(unsigned int i = 0; i < types.size(); i++)
        {
            ui->input_addcomp_type->addItem(QString::fromStdString(types[i]));
        }
        ui->input_addcomp_type->addItem(QString::fromStdString("Add new type"));
    }
}
