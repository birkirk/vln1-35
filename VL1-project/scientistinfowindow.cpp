#include "scientistinfowindow.h"
#include "ui_scientistinfowindow.h"

scientistInfoWindow::scientistInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistInfoWindow)
{
    ui->setupUi(this);

}

scientistInfoWindow::scientistInfoWindow(Scientist selectedScientist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scientistInfoWindow)
{
    ui->setupUi(this);
    setUpSci(selectedScientist);
    displayConnections(selectedScientist);
}

scientistInfoWindow::~scientistInfoWindow()
{
    delete ui;
}

void scientistInfoWindow::setUpSci(Scientist selectedScientist)
{
    QString name = QString::fromStdString(selectedScientist.getName());
    QString born = QString::number(selectedScientist.getBirth());
    QString died;
    if(selectedScientist.getDeath() == ifDead)
    {
        died = QString::fromStdString("?");
    }
    else
    {
        died = QString::number(selectedScientist.getDeath());
    }
    QString gender;
    if(selectedScientist.getGender() == 'm' || selectedScientist.getGender() == 'M')
    {
        gender = QString::fromStdString("Male");
    }
    else
    {
        gender = QString::fromStdString("Female");
    }

    ui->label_infosci_name->setText(name);
    ui->label_infosci_gender->setText(gender);
    ui->label_infosci_life->setText(born + " - " + died);

    QByteArray picture = _service.getScientistPicture(selectedScientist);
    QPixmap image;
    image.loadFromData(picture);

    ui->label_infosci_image->setPixmap(image);
}

void scientistInfoWindow::displayConnections(Scientist selectedScientist)
{
    vector<Computer> connectedComputers = _service.getConnectedComp(selectedScientist);

    ui->table_infosci_connections->clearContents();
    ui->table_infosci_connections->setRowCount(connectedComputers.size());

    for(size_t i = 0; i < connectedComputers.size(); i++)
    {
        QString name = QString::fromStdString(connectedComputers[i].getName());
        QString type = QString::fromStdString(connectedComputers[i].getType());
        QString ifMade;
        if(connectedComputers[i].getIfMade() == 1)
        {
            ifMade = QString::fromStdString("Yes");
        }
        else
        {
            ifMade = QString::fromStdString("No");
        }
        QString yearMade;
        if(connectedComputers[i].getYearMade() == 0)
        {
            yearMade = QString::fromStdString("----");
        }
        else
        {
            yearMade = QString::number(connectedComputers[i].getYearMade());
        }

        ui->table_infosci_connections->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_infosci_connections->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_infosci_connections->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_infosci_connections->setItem(i, 3, new QTableWidgetItem(yearMade));
    }
}

void scientistInfoWindow::on_button_infosci_done_clicked()
{
    this->done(1);
}
