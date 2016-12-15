#include "addcontosci.h"
#include "ui_addcontosci.h"

addConToSci::addConToSci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConToSci)
{
    ui->setupUi(this);
}

addConToSci::addConToSci(Scientist selectedScientist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConToSci)
{
    ui->setupUi(this);
    setUpAvalibleCon();
    setScientist(selectedScientist);
}

addConToSci::~addConToSci()
{
    delete ui;
}

void addConToSci::setUpAvalibleCon()
{
    vector<Computer> allcomputers = _service.compGet();
    displayComputers(allcomputers);
}

void addConToSci::displayComputers(vector<Computer> computers)
{
    ui->table_consci_connections->clearContents();
    ui->table_consci_connections->setRowCount(computers.size());
    ui->table_consci_connections->hideColumn(4);

    for(size_t i = 0; i < computers.size(); i++)
    {
        QString name = QString::fromStdString(computers[i].getName());
        QString type = QString::fromStdString(computers[i].getType());
        QString ifMade;
        if(computers[i].getIfMade() == 1)
        {
            ifMade = QString::fromStdString("Yes");
        }
        else
        {
            ifMade = QString::fromStdString("No");
        }
        QString yearMade;
        if(computers[i].getYearMade() == 0)
        {
            yearMade = QString::fromStdString("----");
        }
        else
        {
            yearMade = QString::number(computers[i].getYearMade());
        }

        QString ID = QString::number(i);

        ui->table_consci_connections->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_consci_connections->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_consci_connections->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_consci_connections->setItem(i, 3, new QTableWidgetItem(yearMade));
        ui->table_consci_connections->setItem(i, 4, new QTableWidgetItem(ID));
    }
    _currentlyDisplaydedComputers = computers;
}

void addConToSci::setScientist(Scientist selectedScientist)
{
    _selectedScientist = selectedScientist;
}

void addConToSci::on_input_consci_search_textChanged(const QString &arg1)
{
    ui->button_consci_connect->setEnabled(false);
    string searchComputersInput = ui->input_consci_search->text().toStdString();

    vector<Computer> searchedComputers = _service.searchComp(searchComputersInput);

    displayComputers(searchedComputers);
    ui->label_consci_status->setText("");
}

void addConToSci::on_table_consci_connections_clicked(const QModelIndex &index)
{
    ui->button_consci_connect->setEnabled(true);
    ui->label_consci_status->setText("");
}

void addConToSci::on_button_consci_connect_clicked()
{
    int selectedComputerRow = ui->table_consci_connections->currentIndex().row();
    QString ID = ui->table_consci_connections->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);
    bool wasConnected = _service.connect(_selectedScientist, selectedComputer);
    if(wasConnected)
    {
        ui->button_consci_connect->setEnabled(false);
        ui->label_consci_status->setText("<span style='color: #5EC748'>Successfully connected</span>");
    }
    else
    {
        ui->label_consci_status->setText("<span style='color: #E94949'>Could not be connected</span>");
    }
}

void addConToSci::on_button_consci_done_clicked()
{
    ui->label_consci_status->setText("");
    this->done(1);
}
