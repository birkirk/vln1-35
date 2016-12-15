#include "helpwindow.h"
#include "ui_helpwindow.h"

helpWindow::helpWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpWindow)
{
    ui->setupUi(this);
    displayManual();
}

helpWindow::~helpWindow()
{
    delete ui;
}

void helpWindow::displayManual()
{
    vector<string> lines = _service.getManual();
    ui->input_readme->setText("");
    string text;

    for(size_t i = 0; i < lines.size(); i++)
    {
        text += lines[i] + '\n';
    }

    ui->input_readme->setText(QString::fromStdString(text));
}

