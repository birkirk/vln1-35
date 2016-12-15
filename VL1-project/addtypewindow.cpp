#include "addtypewindow.h"
#include "ui_addtypewindow.h"

addTypeWindow::addTypeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addTypeWindow)
{
    ui->setupUi(this);
}

addTypeWindow::~addTypeWindow()
{
    delete ui;
}

void addTypeWindow::on_button_addtype__clicked()
{

    if(ui->input_addtype_type->text() != "")
    {
        _service.addType(ui->input_addtype_type->text().toStdString());
    }
}

void addTypeWindow::on_button_addtype_done_clicked()
{
    this->done(1);
}
