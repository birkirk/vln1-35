#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
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
        QString died = QString::number(scientists[i].getDeath());
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
}


void MainWindow::on_input_search_scientists_textChanged(const QString &arg1)
{
    string searchScientistInput = ui->input_search_scientists->text().toStdString();

    vector<Scientist> searchedScientists = _service.searchSci(searchScientistInput);

    displayScientists(searchedScientists);
}
