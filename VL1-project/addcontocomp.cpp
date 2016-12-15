#include "addcontocomp.h"
#include "ui_addcontocomp.h"

addConToComp::addConToComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConToComp)
{
    ui->setupUi(this);
}

addConToComp::addConToComp(Computer selectedComputer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConToComp)
{
    ui->setupUi(this);
    setUpAvalibleCon();
    setComputer(selectedComputer);
}

addConToComp::~addConToComp()
{
    delete ui;
}

void addConToComp::setUpAvalibleCon()
{
    vector<Scientist> allscientists = _service.sciGet();
    displayScientists(allscientists);
}

void addConToComp::displayScientists(vector<Scientist> scientists)
{
    ui->table_concomp_connections->clearContents();
    ui->table_concomp_connections->setRowCount(scientists.size());
    ui->table_concomp_connections->hideColumn(4);

    for(size_t i = 0; i < scientists.size(); i++)
    {
        QString name = QString::fromStdString(scientists[i].getName());
        QString born = QString::number(scientists[i].getBirth());
        QString died;
        if(scientists[i].getDeath() == ifDead)
        {
            died = QString::fromStdString("?");
        }
        else
        {
            died = QString::number(scientists[i].getDeath());
        }
        QString gender;
        if(scientists[i].getGender() == 'm' || scientists[i].getGender() == 'M')
        {
            gender = QString::fromStdString("Male");
        }
        else
        {
            gender = QString::fromStdString("Female");
        }

        QString ID = QString::number(i);

        ui->table_concomp_connections->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_concomp_connections->setItem(i, 1, new QTableWidgetItem(born));
        ui->table_concomp_connections->setItem(i, 2, new QTableWidgetItem(died));
        ui->table_concomp_connections->setItem(i, 3, new QTableWidgetItem(gender));
        ui->table_concomp_connections->setItem(i, 4, new QTableWidgetItem(ID));
    }
    _currentlyDisplayedScientists = scientists;
}

void addConToComp::setComputer(Computer selectedComputer)
{
    _selectedComputer = selectedComputer;
}

void addConToComp::on_input_concomp_search_textChanged(const QString &arg1)
{
    ui->button_concomp_connect->setEnabled(false);
    string searchScientistsInput = ui->input_concomp_search->text().toStdString();

    vector<Scientist> searchedScientists = _service.searchSci(searchScientistsInput);

    displayScientists(searchedScientists);
    ui->label_concomp_status->setText("");
}

void addConToComp::on_table_concomp_connections_clicked(const QModelIndex &index)
{
    ui->button_concomp_connect->setEnabled(true);
    ui->label_concomp_status->setText("");
}

void addConToComp::on_button_concomp_connect_clicked()
{
    int selectedScientistRow = ui->table_concomp_connections->currentIndex().row();
    QString ID = ui->table_concomp_connections->item(selectedScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyDisplayedScientists.at(scientistID);
    bool wasConnected = _service.connect(selectedScientist, _selectedComputer);
    if(wasConnected)
    {
        ui->button_concomp_connect->setEnabled(false);
        ui->label_concomp_status->setText("<span style='color: #5EC748'>Successfully connected</span>");
    }
    else
    {
        ui->label_concomp_status->setText("<span style='color: #E94949'>Could not be connected</span>");
    }
}

void addConToComp::on_button_concomp_done_clicked()
{
    ui->label_concomp_status->setText("");
    this->done(1);
}
