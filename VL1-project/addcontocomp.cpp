#include "addcontocomp.h"
#include "ui_addcontocomp.h"

addConToComp::addConToComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addConToComp)
{
    ui->setupUi(this);
}

addConToComp::~addConToComp()
{
    delete ui;
}
