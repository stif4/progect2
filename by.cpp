#include "by.h"
#include "ui_by.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QDebug>
by::by(QString name_performanc,QTableWidgetItem *itm,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::by)
{ 
    ui->setupUi(this);
    vec.push_back("Балкон");
    vec.push_back("Ложи");
    vec.push_back("Партер");
    tupe = itm->column();
    number_tickets =itm->text().toInt();
    QRegExp int_i("[1-9][0-9]{0,2}");
    ui->lineEdit_4->setValidator(new QRegExpValidator(int_i,this));
    QRegExp rx("[А-Я,а-я]{1,30}");
    ui->lineEdit->setValidator(new QRegExpValidator(rx,this));
    ui->lineEdit_2->setValidator(new QRegExpValidator(rx,this));
    ui->lineEdit_3->setValidator(new QRegExpValidator(rx,this));
    QRegExp int_i2("[8][0-9]{10}");
    ui->lineEdit_5->setValidator(new QRegExpValidator(int_i2, this));
    count_tickets_by=itm->text().toInt();

    performance=name_performanc;

    this->setWindowModality(Qt::ApplicationModal);
}

by::~by()
{
    delete ui;
}

QString by::give_cahnge_tickets()
{
    count_tickets_by = count_tickets_by - number_by;
    number_change = QString::number(count_tickets_by);
    return number_change;
}

bool by::geter_temp()
{
    return temp;
}

void by::orderby()
{
    number_by = ui->lineEdit_4->text().toInt();

    if(ui->lineEdit->text()==""||ui->lineEdit_2->text()==""||ui->lineEdit_3->text()=="")
    {
       QMessageBox::information(this,"Заказ","Остались незаполненные поля!",QMessageBox::Cancel);
    }
    else if((number_by>number_tickets))
    {
       QMessageBox::information(this,"Заказ","Заявка не может быть обработана!",QMessageBox::Cancel);
    }
    else if(ui->lineEdit_5->text().toLongLong()<80000000000)
    {
       QMessageBox::information(this,"Заказ","Проверьте номер телефона."
                                                  ,QMessageBox::Cancel);
    }
    else
    {
      QFile file(orders);

      bool l =false;
      if(file.open(QIODevice::ReadOnly | QIODevice::Text))
      {
          QTextStream stream(&file);
          QString s ="";
          stream>>s;
          qDebug()<<s;
          if(s!="")
          {
              l=true;
          }
      }
      file.close();


      if(file.open(QIODevice::Append | QIODevice::Text))
      {
          QTextStream stream(&file);

          if (l)
          {
              stream <<"\n";
          }

          QString s = performance;
          QStringList sList = s.split(" ");
          QString newS = sList.join("*");

          stream <<ui->lineEdit->text()<<" "
                 <<ui->lineEdit_2->text()<<" "
                 <<ui->lineEdit_3->text()<<" "
                 <<number_by<<" "
                 <<ui->lineEdit_5->text()<<" "
                 <<vec[tupe]<<" "
                 <<newS;
      }
      file.close();

      QMessageBox::information(this,"Заказ","Заявка отправленна. Места будут забранированы."
                                            "Ожидайте звонка!",QMessageBox::Cancel);
      temp = true;
    }
}

