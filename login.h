#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    bool login_in();
    int get_person();


public slots:
    void push_admin();
    void push_cassir();
    void push_user();

private:
    Ui::login *ui;
    int person=0;

    bool cond = false;
};

#endif // LOGIN_H
