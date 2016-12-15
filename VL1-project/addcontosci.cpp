#include "addcontosci.h"
#include "ui_addcontosci.h"

addConToSci::addConToSci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConToSci)
{
    ui->setupUi(this);
}

addConToSci::~addConToSci()
{
    delete ui;
}
