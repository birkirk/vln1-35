#ifndef SCIENTISTINFOWINDOW_H
#define SCIENTISTINFOWINDOW_H

#include <QDialog>

namespace Ui {
class scientistInfoWindow;
}

class scientistInfoWindow : public QDialog
{
    Q_OBJECT

public:
    explicit scientistInfoWindow(QWidget *parent = 0);
    ~scientistInfoWindow();

private:
    Ui::scientistInfoWindow *ui;
};

#endif // SCIENTISTINFOWINDOW_H
