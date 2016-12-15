#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addscientistwindow.h"
#include "addcomputerwindow.h"
#include "scientistinfowindow.h"
#include "computerinfowindow.h"
#include "const.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
    displayAllComputers();
    displayAllRemovedScientists();
    displayAllRemovedComputers();
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

void MainWindow::displayAllComputers()
{
    vector<Computer> allcomputers = _service.compGet();
    displayComputers(allcomputers);
}

void MainWindow::displayAllRemovedScientists()
{
    vector<Scientist> removedScientists = _service.getDeletedSci();
    displayRemovedScientists(removedScientists);
}

void MainWindow::displayAllRemovedComputers()
{
    vector<Computer> removedComputers = _service.getDeletedComp();
    displayRemovedComputers(removedComputers);
}

void MainWindow::displayScientists(vector<Scientist> scientists)
{
    ui->table_display_scientists->clearContents();
    ui->table_display_scientists->setRowCount(scientists.size());
    ui->table_display_scientists->hideColumn(4);

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

        ui->table_display_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_scientists->setItem(i, 1, new QTableWidgetItem(born));
        ui->table_display_scientists->setItem(i, 2, new QTableWidgetItem(died));
        ui->table_display_scientists->setItem(i, 3, new QTableWidgetItem(gender));
        ui->table_display_scientists->setItem(i, 4, new QTableWidgetItem(ID));
    }
    _currentlyDisplaydedScientists = scientists;
}

void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->table_display_computers->clearContents();
    ui->table_display_computers->setRowCount(computers.size());
    ui->table_display_computers->hideColumn(4);

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

        ui->table_display_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_display_computers->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_display_computers->setItem(i, 3, new QTableWidgetItem(yearMade));
        ui->table_display_computers->setItem(i, 4, new QTableWidgetItem(ID));
    }
    _currentlyDisplaydedComputers = computers;
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
    ui->button_details_scientists->setEnabled(true);
    ui->label_status_scientists->setText("");
}

void MainWindow::on_button_remove_scientists_clicked()
{
    ui->button_recover_all_scientists->setEnabled(true);
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();
    QString ID = ui->table_display_scientists->item(selectedScientistRow, 4)->text();
    int scientistID = ID.toInt();

    Scientist selectedScientist = _currentlyDisplaydedScientists.at(scientistID);

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
    displayAllRemovedScientists();
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
    ui->button_details_computers->setEnabled(true);
    ui->label_status_computers->setText("");
}

void MainWindow::on_button_remove_computers_clicked()
{
    ui->button_recover_all_computers->setEnabled(true);
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();
    QString ID = ui->table_display_computers->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();

    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);

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
    displayAllRemovedComputers();
}

void MainWindow::on_table_removed_scientists_clicked(const QModelIndex &index)
{
    ui->button_recover_scientists->setEnabled(true);
    ui->label_status_bin->setText("");
}

void MainWindow::on_table_removed_computers_clicked(const QModelIndex &index)
{
    ui->button_recover_computers->setEnabled(true);
    ui->label_status_bin->setText("");
}

void MainWindow::displayRemovedScientists(vector<Scientist> scientists)
{
    ui->table_removed_scientists->clearContents();
    ui->table_removed_scientists->setRowCount(scientists.size());
    ui->table_removed_scientists->hideColumn(4);

    if(scientists.size() > 0)
    {
        ui->button_recover_all_scientists->setEnabled(true);
    }
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

        ui->table_removed_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_removed_scientists->setItem(i, 1, new QTableWidgetItem(born));
        ui->table_removed_scientists->setItem(i, 2, new QTableWidgetItem(died));
        ui->table_removed_scientists->setItem(i, 3, new QTableWidgetItem(gender));
        ui->table_removed_scientists->setItem(i, 4, new QTableWidgetItem(ID));
    }
    _currentlyRemovedScientists = scientists;
}

void MainWindow::displayRemovedComputers(vector<Computer> computers)
{
    ui->table_removed_computers->clearContents();
    ui->table_removed_computers->setRowCount(computers.size());
    ui->table_removed_computers->hideColumn(4);

    if(computers.size() > 0)
    {
        ui->button_recover_all_computers->setEnabled(true);
    }
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

        ui->table_removed_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_removed_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_removed_computers->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_removed_computers->setItem(i, 3, new QTableWidgetItem(yearMade));
        ui->table_removed_computers->setItem(i, 4, new QTableWidgetItem(ID));
    }
    _currentlyRemovedComputers = computers;
}

void MainWindow::on_button_recover_scientists_clicked()
{
    int selectedRecoverScientistRow = ui->table_removed_scientists->currentIndex().row();
    QString ID = ui->table_removed_scientists->item(selectedRecoverScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyRemovedScientists.at(scientistID);

    bool scientistWasRecovered = _service.recycleSci(selectedScientist);
    if(scientistWasRecovered)
    {
        displayAllRemovedScientists();
        ui->button_recover_scientists->setEnabled(false);
        ui->label_status_bin->setText("<span style='color: #5EC748'>Scientist successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>Scientist could not be recovered</span>");
    }
    displayAllScientists();
}

void MainWindow::on_button_recover_computers_clicked()
{
    int selectedRecoverComputerRow = ui->table_removed_computers->currentIndex().row();
    QString ID = ui->table_removed_computers->item(selectedRecoverComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyRemovedComputers.at(computerID);

    bool computerWasRecovered = _service.recycleComp(selectedComputer);
    if(computerWasRecovered)
    {
        displayAllRemovedComputers();
        ui->button_recover_computers->setEnabled(false);
        ui->label_status_bin->setText("<span style='color: #5EC748'>Computer successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>Computer could not be recovered</span>");
    }
    displayAllComputers();
}

void MainWindow::on_button_recover_all_scientists_clicked()
{
    ui->button_recover_all_scientists->setEnabled(false);
    bool allWentOk = true;
    for(size_t i = 0; i < _currentlyRemovedScientists.size(); i++)
    {
        Scientist selectedScientist = _currentlyRemovedScientists[i];

        bool scientistWasRecovered = _service.recycleSci(selectedScientist);
        if(!scientistWasRecovered)
        {
            allWentOk = false;
        }
    }
    if(allWentOk)
    {
        ui->label_status_bin->setText("<span style='color: #5EC748'>All scientists successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>All scientists could not be recovered</span>");
    }
    displayAllRemovedScientists();
    displayAllScientists();
}

void MainWindow::on_button_recover_all_computers_clicked()
{
    ui->button_recover_all_computers->setEnabled(false);
    bool allWentOk = true;
    for(size_t i = 0; i < _currentlyRemovedComputers.size(); i++)
    {
        Computer selectedComputer = _currentlyRemovedComputers[i];

        bool computerWasRecovered = _service.recycleComp(selectedComputer);
        if(!computerWasRecovered)
        {
            allWentOk = false;
        }
    }
    if(allWentOk)
    {
        ui->label_status_bin->setText("<span style='color: #5EC748'>All computers successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>All computers could not be recovered</span>");
    }
    displayAllRemovedComputers();
    displayAllComputers();
}

void MainWindow::on_button_addnew_scientists_clicked()
{
    addScientistWindow addSci;
    addSci.exec();
}

void MainWindow::on_button_addnew_computers_clicked()
{
    addComputerWindow addComp;
    addComp.exec();
}

void MainWindow::on_button_details_scientists_clicked()
{
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();
    QString ID = ui->table_display_scientists->item(selectedScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyDisplaydedScientists.at(scientistID);

    scientistInfoWindow infoSci(selectedScientist);
    infoSci.exec();
}

void MainWindow::on_button_details_computers_clicked()
{
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();
    QString ID = ui->table_display_computers->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);

    computerInfoWindow infoComp(selectedComputer);
    infoComp.exec();

}

void MainWindow::on_table_display_scientists_doubleClicked(const QModelIndex &index)
{
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();
    QString ID = ui->table_display_scientists->item(selectedScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyDisplaydedScientists.at(scientistID);

    scientistInfoWindow infoSci(selectedScientist);
    infoSci.exec();
}

void MainWindow::on_table_display_computers_doubleClicked(const QModelIndex &index)
{
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();
    QString ID = ui->table_display_computers->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);

    computerInfoWindow infoComp(selectedComputer);
    infoComp.exec();
}

void MainWindow::on_button_bin_clear_clicked()
{
    if(ui->checkbox_bin_clear->isChecked())
    {
        _service.clearData("all");
        ui->label_status_bin->setText("<span style='color: #E94949'>Database will be cleared!</span>");
    }
}

void MainWindow::on_tabs_tabBarClicked(int index)
{
    ui->checkbox_bin_clear->setChecked(false);
    ui->button_details_computers->setEnabled(false);
    ui->button_details_scientists->setEnabled(false);
}
