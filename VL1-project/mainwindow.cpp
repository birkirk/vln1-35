#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
    displayAllComputers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    vector<Scientist> allScientists = _service.sciGet();
    displayScientists(allScientists);
}

void MainWindow::displayScientists(vector<Scientist> scientists)
{
    ui->table_display_scientists->clearContents();
    ui->table_display_scientists->setRowCount(scientists.size());

    for(size_t i = 0; i < scientists.size(); i++)
    {
        QString name = QString::fromStdString(scientists[i].getName());
        QString born = QString::number(scientists[i].getBirth());
        QString died;
        if(scientists[i].getDeath() == 3000)
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

        ui->table_display_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_scientists->setItem(i, 1, new QTableWidgetItem(born));
        ui->table_display_scientists->setItem(i, 2, new QTableWidgetItem(died));
        ui->table_display_scientists->setItem(i, 3, new QTableWidgetItem(gender));
    }

    currentlyDisplaydedScientists = scientists;
}

void MainWindow::displayAllComputers()
{
    vector<Computer> allcomputers = _service.compGet();
    displayComputers(allcomputers);
}

void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->table_display_computers->clearContents();
    ui->table_display_computers->setRowCount(computers.size());

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

        ui->table_display_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_display_computers->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_display_computers->setItem(i, 3, new QTableWidgetItem(yearMade));
    }

    currentlyDisplaydedComputers = computers;
}

void MainWindow::on_input_search_scientists_textChanged(const QString &arg1)
{
    string searchScientistsInput = ui->input_search_scientists->text().toStdString();

    vector<Scientist> searchedScientists = _service.searchSci(searchScientistsInput);

    displayScientists(searchedScientists);
    ui->label_status_scientists->setText("");
}

void MainWindow::on_table_display_scientists_clicked(const QModelIndex &index)
{
    ui->button_remove_scientists->setEnabled(true);
    ui->label_status_scientists->setText("");
}

void MainWindow::on_button_remove_scientists_clicked()
{
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();

    Scientist selectedScientist = currentlyDisplaydedScientists.at(selectedScientistRow);

    bool scientistWasRemoved = _service.deleteSci(selectedScientist);
    if(scientistWasRemoved)
    {
        ui->input_search_scientists->setText("");
        displayAllScientists();
        ui->button_remove_scientists->setEnabled(false);
        ui->label_status_scientists->setText("<span style='color: #5EC748'>Scientist successfully removed</span>");
    }
    else
    {
        ui->label_status_scientists->setText("<span style='color: #E94949'>Scientist could not be removed</span>");
    }
}

void MainWindow::on_input_search_computers_textChanged(const QString &arg1)
{
    string searchComputersInput = ui->input_search_computers->text().toStdString();

    vector<Computer> searchedComputers = _service.searchComp(searchComputersInput);

    displayComputers(searchedComputers);
    ui->label_status_computers->setText("");
}

void MainWindow::on_table_display_computers_clicked(const QModelIndex &index)
{
    ui->button_remove_computers->setEnabled(true);
    ui->label_status_computers->setText("");
}

void MainWindow::on_button_remove_computers_clicked()
{
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();

    Computer selectedComputer = currentlyDisplaydedComputers.at(selectedComputerRow);

    bool computerWasRemoved = _service.deleteComp(selectedComputer);
    if(computerWasRemoved)
    {
        ui->input_search_computers->setText("");
        displayAllComputers();
        ui->button_remove_computers->setEnabled(false);
        ui->label_status_computers->setText("<span style='color: #5EC748'>Computer successfully removed</span>");
    }
    else
    {
        ui->label_status_computers->setText("<span style='color: #E94949'>Computer could not be removed</span>");
    }
}
