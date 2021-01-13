#include "in.h"
#include "ui_in.h"
#include <QMessageBox>

#include <QDebug>
in::in(int condiditon,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::in)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    condition_in = condiditon;
    ui->lineEdit_2->setEchoMode(QLineEdit::EchoMode::Password);
}

in::~in()
{
    delete ui;
}

void in::read_in_log()
{
    QFile file(file_cassir);
    QString line_log="";
    QString line_pass="";
    if(!file.exists())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("The specified file was not found");
        errorMessage.exec();
    }
    else
    {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            while (!stream.atEnd())
            {
               stream>>line_log;
               stream>>line_pass;
               if(line_log==login && line_pass == password)
               {
                   correct_log = true; 
                   break;
               }
               //log.push_back(line1);
            }
            if(correct_log==false)
            {
               (new QErrorMessage(this))->showMessage("Write Error");
            }
        }
        file.close();
    }
}

bool in::give_signal_log()
{
    return correct_log;
}

void in::log_in()
{
    login = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(condition_in == 1)
    {
      read_in_log();
      if(correct_log==true)
      {
        this->close();
      }
    }

    if(condition_in == 2)
    {
        if(login == "admin228" && password =="228")
        {
           correct_log = true;
           this->close();
        }
        else
        {
           (new QErrorMessage(this))->showMessage("Write Error");
        }
    }
}
