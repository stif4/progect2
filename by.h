#ifndef BY_H
#define BY_H
#include "dialog.h"

#include <QTableWidgetItem>

#include <QErrorMessage>
#include <QFile>
#include <QString>
#include <QTextStream>

namespace Ui {
class by;
}

class by : public QDialog
{
    Q_OBJECT

public:
    explicit by(QString name_performanc,QTableWidgetItem *itm,QWidget *parent = nullptr);
    ~by();
    QString give_cahnge_tickets();
    bool geter_temp();

public slots:
    void orderby();

private:
    Ui::by *ui;
    QString orders ="C:/Users/User/Documents/orders.txt";

    QVector<QString>vec;
    int tupe;

    int number_tickets;

    int number_by;

    QString performance;

    int count_tickets_by;
    QString number_change;
    bool temp = false;
};

#endif // BY_H
