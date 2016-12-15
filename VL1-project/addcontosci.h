#ifndef ADDCONTOSCI_H
#define ADDCONTOSCI_H

#include <QDialog>

namespace Ui {
class addConToSci;
}

class addConToSci : public QDialog
{
    Q_OBJECT

public:
    explicit addConToSci(QWidget *parent = 0);
    ~addConToSci();

private:
    Ui::addConToSci *ui;
};

#endif // ADDCONTOSCI_H
