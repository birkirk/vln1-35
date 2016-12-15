#include "scientistinfowindow.h"
#include "ui_scientistinfowindow.h"
#include "addcontosci.h"

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
    setScientist(selectedScientist);
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
    ui->table_infosci_connections->hideColumn(4);

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
        QString ID = QString::number(i);

        ui->table_infosci_connections->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_infosci_connections->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_infosci_connections->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_infosci_connections->setItem(i, 3, new QTableWidgetItem(yearMade));
        ui->table_infosci_connections->setItem(i, 4, new QTableWidgetItem(ID));
    }
    _currentlyConnected = connectedComputers;
}

void scientistInfoWindow::setScientist(Scientist selectedScientist)
{
    _selectedScientist = selectedScientist;
}

void scientistInfoWindow::on_button_infosci_done_clicked()
{
    this->done(1);
}

void scientistInfoWindow::on_table_infosci_connections_clicked(const QModelIndex &index)
{
    ui->button_infosci_remove->setEnabled(true);
    ui->label_infosci_status->setText("");
}

void scientistInfoWindow::on_button_infosci_remove_clicked()
{
    int selectedComputerRow = ui->table_infosci_connections->currentIndex().row();
    QString ID = ui->table_infosci_connections->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyConnected.at(computerID);
    bool wasRemoved = _service.deleteConnection(selectedComputer, _selectedScientist);
    if(wasRemoved)
    {
        displayConnections(_selectedScientist);
        ui->button_infosci_remove->setEnabled(false);
        ui->label_infosci_status->setText("<span style='color: #5EC748'>Connection successfully removed</span>");
    }
    else
    {
        ui->label_infosci_status->setText("<span style='color: #E94949'>Connection could not be removed</span>");
    }
}

void scientistInfoWindow::on_button_infosci_add_clicked()
{
    addConToSci conSci(_selectedScientist);
    conSci.exec();
}
