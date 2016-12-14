#include "computerinfowindow.h"
#include "ui_computerinfowindow.h"

computerInfoWindow::computerInfoWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::computerInfoWindow)
{
    ui->setupUi(this);
}

computerInfoWindow::computerInfoWindow(Computer selectedComputer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::computerInfoWindow)
{
    ui->setupUi(this);

    setUpComp(selectedComputer);
    displayConnections(selectedComputer);
}

computerInfoWindow::~computerInfoWindow()
{
    delete ui;
}

void computerInfoWindow::setUpComp(Computer selectedComputer)
{
    QString name = QString::fromStdString(selectedComputer.getName());
    QString type = QString::fromStdString(selectedComputer.getType());
    QString ifMade;
    if(selectedComputer.getIfMade() == 1)
    {
        ifMade = QString::fromStdString("Was made in");
    }
    else
    {
        ifMade = QString::fromStdString("Was never made");
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

    ui->label_infocomp_name->setText(name);
    ui->label_infocomp_type->setText(type);
    ui->label_infocomp_ifmade->setText(ifMade);
    ui->label_infocomp_yearmade->setText(yearMade);

    QByteArray picture = _service.getComputerPicture(selectedComputer);
    QPixmap image;
    image.loadFromData(picture);

    ui->label_infocomp_image->setPixmap(image);
}

void computerInfoWindow::displayConnections(Computer selectedComputer)
{
    vector<Scientist> connectedScientists = _service.getConnectedSci(selectedComputer);

    ui->table_infocomp_connections->clearContents();
    ui->table_infocomp_connections->setRowCount(connectedScientists.size());

    for(size_t i = 0; i < connectedScientists.size(); i++)
    {
        QString name = QString::fromStdString(connectedScientists[i].getName());
        QString born = QString::number(connectedScientists[i].getBirth());
        QString died;
        if(connectedScientists[i].getDeath() == ifDead)
        {
            died = QString::fromStdString("?");
        }
        else
        {
            died = QString::number(connectedScientists[i].getDeath());
        }
        QString gender;
        if(connectedScientists[i].getGender() == 'm' || connectedScientists[i].getGender() == 'M')
        {
            gender = QString::fromStdString("Male");
        }
        else
        {
            gender = QString::fromStdString("Female");
        }

        ui->table_infocomp_connections->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_infocomp_connections->setItem(i, 1, new QTableWidgetItem(born));
        ui->table_infocomp_connections->setItem(i, 2, new QTableWidgetItem(died));
        ui->table_infocomp_connections->setItem(i, 3, new QTableWidgetItem(gender));
    }
}

void computerInfoWindow::on_button_infocomp_done_clicked()
{
    this->done(1);
}

void computerInfoWindow::on_table_infocomp_connections_clicked(const QModelIndex &index)
{
    ui->button_infocomp_remove->setEnabled(true);
}

void computerInfoWindow::on_button_infocomp_remove_clicked()
{
    int selectedComputerRow = ui->table_infocomp_connections->currentIndex().row();
}
