#ifndef ACTER_H
#define ACTER_H

#include <QDialog>

namespace Ui {
class Acter;
}

class Acter : public QDialog
{
    Q_OBJECT

public:
    explicit Acter(int person, QString *o,QWidget *parent = nullptr);
    ~Acter();

public slots:
    void save_actor();

private:
    Ui::Acter *ui;

    QString *inform_actor;

};

#endif // ACTER_H
