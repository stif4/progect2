#ifndef IN_H
#define IN_H

#include <QDialog>
#include <QVector>

#include <QErrorMessage>
#include <QFile>
#include <QString>
#include <QTextStream>

namespace Ui {
class in;
}

class in : public QDialog
{
    Q_OBJECT

public:
    explicit in(int condition,QWidget *parent = nullptr);
    ~in();
    void read_in_log();
    bool give_signal_log();

public slots:
    void log_in();

private:
    Ui::in *ui;

    QString login;
    QString password;

    int condition_in;
    bool correct_log = false;

    QVector<QString> log;

    QString file_cassir = "C:/Users/User/Documents/cassirs.txt";
};

#endif // IN_H
