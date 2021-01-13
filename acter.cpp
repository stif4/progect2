#include "acter.h"
#include "ui_acter.h"

Acter::Acter(int person,QString *o, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acter)
{
    ui->setupUi(this);
    inform_actor = o;

    QString s= *inform_actor;
    QStringList sList = s.split(" $ ");
    QString newS = sList.join("\n");
    ui->textEdit->setText(newS);

    if(person!=2)
    {
        ui->pushButton->hide();
        ui->textEdit->setReadOnly(true);
    }

    this->setWindowModality(Qt::ApplicationModal);
}

Acter::~Acter()
{
    delete ui;
}

void Acter::save_actor()
{
    QString s = ui->textEdit->toPlainText();
    QStringList sList = s.split("\n");
    QString newS = sList.join(" $ ");
    *(inform_actor)= newS;
}



