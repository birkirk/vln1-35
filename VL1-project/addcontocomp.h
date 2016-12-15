#ifndef ADDCONTOCOMP_H
#define ADDCONTOCOMP_H

#include <QDialog>

namespace Ui {
class addConToComp;
}

class addConToComp : public QDialog
{
    Q_OBJECT

public:
    explicit addConToComp(QWidget *parent = 0);
    ~addConToComp();

private:
    Ui::addConToComp *ui;
};

#endif // ADDCONTOCOMP_H
