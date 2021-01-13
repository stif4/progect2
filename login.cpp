#include "login.h"
#include "ui_login.h"

#include "in.h"

#include <QWaitCondition>

#include <QDebug>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

bool login::login_in()
{
    return cond;
}

int login::get_person()
{
    return person;
}

void login::push_admin()
{
    in *in_1 = new in(2);
    in_1->setAttribute(Qt::WA_DeleteOnClose);
    in_1->show();

    if((in_1->exec() != in::Accepted)&&(in_1->give_signal_log() == true))
    {
       cond=true;
       person=2;
       this->close();
    }
}

void login::push_cassir()
{
    in *in_2 = new in(1);
    in_2->setAttribute(Qt::WA_DeleteOnClose);
    in_2->show();

    if((in_2->exec() != in::Accepted)&&(in_2->give_signal_log() == true))
    {
       cond=true;
       person = 1;
       this->close();
    }
}

void login::push_user()
{
    cond=true;
    person=3;
    this->close();
}
