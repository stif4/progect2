#include "dialog.h"
#include "ui_dialog.h"

#include "cassir2.h"
#include "performance2.h"
#include "tickets.h"
#include "ordertoby.h"
#include "acter.h"
#include "by.h"
#include "cchoicepathdelegate.h"

#include <QErrorMessage>
#include <QMessageBox>
#include <QVector>

#include <QDebug>
#include "QCloseEvent"

#include <QTextCodec>

Dialog::Dialog(QString name_p,int person_log,int NK,int row, int colum,QString file1, QWidget *parent)
    : QDialog(parent),  ui(new Ui::Dialog)
{
    ui->setupUi(this);
    type_table=NK;

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    if(type_table==type_table_1)
    {
       ui->tableWidget->setItemDelegateForColumn(colum_t_1, new CChoicePathDelegate(type_table,colum_t_1,this));
       ui->tableWidget->setItemDelegateForColumn(colum_t_2, new CChoicePathDelegate(type_table,colum_t_2,this));
       ui->tableWidget->setItemDelegateForColumn(colum_t_0, new CChoicePathDelegate(type_table,colum_t_0,this));
    }
    if(type_table==type_table_4)
    {
       ui->tableWidget->setItemDelegateForColumn(colum_t_0, new CChoicePathDelegate(type_table,colum_t_0,this));
       ui->tableWidget->setItemDelegateForColumn(colum_t_1, new CChoicePathDelegate(type_table,colum_t_0,this));
       ui->tableWidget->setItemDelegateForColumn(colum_t_2, new CChoicePathDelegate(type_table,colum_t_0,this));
    }
    if(type_table==type_table_3)
    {
       ui->tableWidget->setItemDelegateForColumn(colum_t_0, new CChoicePathDelegate(type_table,colum_t_0,this));
       ui->tableWidget->setItemDelegateForColumn(colum_t_1, new CChoicePathDelegate(type_table,colum_t_0,this));
    }
    if(type_table==type_table_5)
    {
        ui->tableWidget->setItemDelegateForColumn(colum_t_0, new CChoicePathDelegate(type_table,colum_t_1,this));
        ui->tableWidget->setItemDelegateForColumn(colum_t_1, new CChoicePathDelegate(type_table,colum_t_2,this));
        ui->tableWidget->setItemDelegateForColumn(colum_t_2, new CChoicePathDelegate(type_table,colum_t_3,this));
        ui->tableWidget->setItemDelegateForColumn(colum_t_3, new CChoicePathDelegate(type_table,colum_t_4,this));
        ui->tableWidget->setItemDelegateForColumn(colum_t_4, new CChoicePathDelegate(type_table,colum_t_5,this));
    }

    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setColumnCount(colum);

    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    if(type_table == colum_t_1)
    {
        ui->tableWidget->setHorizontalHeaderLabels( QStringList()<<"Спектакли"<<"Дата"<<"Время"<<"Заказать билет");
    }
    if(type_table == colum_t_2)
    {
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Login"<<"Password");
    }
    if(type_table == colum_t_4)
    {
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Авторы"<<"Постановщики"<<"Актеры");
    }
    if(type_table == colum_t_3)
    {
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Балкон"<<"Ложи"<<"Партер");
        ui->tableWidget->setVerticalHeaderLabels(QStringList() << "Цена" << "Количество" );
    }
    if(type_table == colum_t_5)
    {
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Фамилия"<<"Имя"<<"Отчество"<<"Кол-во билетов"<<"Номер телефона"<<"Тип билета"<<"Спектакль");
    }

    name_performance = name_p;

    person = person_log;

    if(type_table== type_table_1 &&(person== type_person_2||person== type_person_1))
    {
      menu = new QMenu("Menu");

     if(person== type_person_2)
     {
        editCasir = new QAction("Кассиры");
        menu->addAction(editCasir);
        connect(editCasir, SIGNAL(triggered()), this, SLOT(make_window_cassir()));
     }

      application = new QAction("Заявки на покупку");
      menu->addAction(application);

      menubar = new QMenuBar();
      menubar->addMenu(menu);

      ui->gridLayout_4->setMenuBar(menubar);

      connect(application, SIGNAL(triggered()), this, SLOT(make_window_application()));
    }

    if(person== type_person_1||person== type_person_3||type_table==type_table_3)
    {
      ui->pushButton_2->hide();
      ui->pushButton->hide();
    }

    if(type_table==type_table_5 && person==type_person_1)
    {
       ui->pushButton_2->show();
       ui->pushButton->show();
    }

    if(type_table==type_table_3)
    {
        ui->lineEdit->hide();
        ui->pushButton_3->hide();
    }

    vec_itm.push_back(nullptr);

    mfile = file1;
    readfile();
}

Dialog::~Dialog()
{
   delete ui;
}

void Dialog::readfile()
{ 
    QFile file(mfile);
    QString line1="";
    QStringList listL;

        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
          QTextStream stream(&file);

          for(int i =0;i< ui->tableWidget->rowCount();i++)
          {
            for(int j =0;j< ui->tableWidget->columnCount();j++)
            {
              QTableWidgetItem *newit = new QTableWidgetItem();

              if(person==1||person==3)
              {
                newit->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
              }

              if(type_table==type_table_5)
              {
                  stream >> line1;
                  QString s =line1;
                  QStringList sList = s.split("*");
                  QString newS = sList.join(" ");
                  newit->setText(newS);
                  ui->tableWidget->setItem(i,j,newit);
              }
              else if(type_table==type_table_1)
              {
                  QString list2;
                  list2 = stream.readLine();
                  if (list2 !="")
                  {
                   listL = list2.split(QRegExp("\\/"), QString::SkipEmptyParts);

                   QTableWidgetItem *newit1 = new QTableWidgetItem();
                   newit1->setText(listL[0]);
                   ui->tableWidget->setItem(i,0,newit1);

                   QTableWidgetItem *newit2 = new QTableWidgetItem();
                   newit2->setText(listL[1]);
                   ui->tableWidget->setItem(i,1,newit2);

                   QTableWidgetItem *newit3 = new QTableWidgetItem();
                   newit3->setText(listL[2]);
                   ui->tableWidget->setItem(i,2,newit3);

                   QTableWidgetItem *newit4 = new QTableWidgetItem();
                   newit4->setText(listL[3]);
                   ui->tableWidget->setItem(i,3,newit4);

                   j=j+3;
                  }
              }
              else if(type_table==4)
              {
                  QString list2;
                  list2 = stream.readLine();
                  listL = list2.split(QRegExp("\\(|\\)"), QString::SkipEmptyParts);

                  qDebug()<<listL;
                  vec.push_back(listL[1]);
                  vec.push_back(listL[3]);
                  vec.push_back(listL[5]);

                  QTableWidgetItem *newit1 = new QTableWidgetItem();

                  newit1->setText(listL[0]);
                  ui->tableWidget->setItem(i,j,newit1);

                  QTableWidgetItem *newit2 = new QTableWidgetItem();
                  newit2->setText(listL[2]);
                  ui->tableWidget->setItem(i,j+1,newit2);

                  QTableWidgetItem *newit3 = new QTableWidgetItem();
                  newit3->setText(listL[4]);
                  ui->tableWidget->setItem(i,j+2,newit3);
                  j=j+2;
              }
              else
              {
                  stream >> line1;
                  newit->setText(line1);
                  ui->tableWidget->setItem(i,j,newit);
              }
              if(type_table==type_table_1 && j==3)
              {
                btn = new QPushButton( "Купить!" );
                ui->tableWidget->setCellWidget(i,j,btn);
                connect( btn, SIGNAL( clicked( bool ) ), SLOT( make_windows() ) );
              }
            }
          }
          file.close();
        }
    else
    {
        for(int i =0;i< ui->tableWidget->rowCount()+1;i++)
        {
          for(int j =0;j< ui->tableWidget->columnCount();j++)
          {
            QTableWidgetItem *newit = new QTableWidgetItem();

            if(person==1||person==3)
            {
               newit->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            }
            newit->setText(line1);
            ui->tableWidget->setItem(i,j,newit);
          }
        }
    }
}

void Dialog::savefile()
{
    QFile file(mfile);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        for(int i =0;i< ui->tableWidget->rowCount();i++)
        {
          if(i!=0)
          {
            stream<<"\n";
          }
          for(int j =0;j< ui->tableWidget->columnCount();j++)
          {
            QTableWidgetItem *itm_1 = ui->tableWidget->item(i,j);

            if(type_table==5)
            {
                QString s = itm_1->text();
                QStringList sList = s.split(" ");
                QString newS = sList.join("*");
                stream <<newS<<" ";
            }
            else if(type_table==type_table_1)
            {
               stream <<"/"<<itm_1->text();
            }
            else if(type_table==type_table_4)
            {
               stream <<itm_1->text()<< "( "<<vec[i*3+j]<<" )";
            }
            else
            {
               stream <<itm_1->text()<<" ";
            }
          }
          if(type_table==type_table_1)
          {
            stream<<"/";
          }
        }
    }
    file.close();
}

void Dialog::search()
{
    if(vec_itm[0]!=nullptr)
    {
       for(int i=0; i<vec_itm.size();i++)
       {
          vec_itm[i]->setBackground(Qt::white);
       }
    }

    QString line_text = ui->lineEdit->text();

    bool find = false;

    if(type_table==type_table_1)
    {
      for(int i =0;i< ui->tableWidget->rowCount();i++)
      {
         itm_calor = ui->tableWidget->item(i,0);

         if(itm_calor->text() == line_text)
         {
           itm_calor->setBackground(Qt::blue);
           if(find==false)
           {
             vec_itm[0] = itm_calor;
           }
           vec_itm.push_back(itm_calor);
           find=true;
         }
      }
      if(!find)
      {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Данного спектакля нет!");
        errorMessage.exec();
      }
    }
    else if(type_table==type_table_4||type_table==type_table_2)
    {
        for(int i =0;i< ui->tableWidget->rowCount();i++)
        {
          for(int j =0;j< ui->tableWidget->columnCount();j++)
          {
            itm_calor = ui->tableWidget->item(i,j);
             if(itm_calor->text() == line_text)
             {
                itm_calor->setBackground(Qt::blue);
                if(find==false)
                {
                  vec_itm[0] = itm_calor;
                }
                vec_itm.push_back(itm_calor);
                find=true;
             }
          }
        }
        if(!find)
        {
          QErrorMessage errorMessage;
          errorMessage.showMessage("Такой персоны нет!");
          errorMessage.exec();
        }
    }
    if(type_table==type_table_5)
    {
        QStringList list;

        list = line_text.split(QRegExp("\\s+"),QString::SkipEmptyParts);
        int sl = list.size();

        for(int i =0;i< ui->tableWidget->rowCount();i++)
        {
          for(int j =0;j< ui->tableWidget->columnCount()-3;j++)
          {
              itm_calor = ui->tableWidget->item(i,j);

              if((sl>0 && list[0] == itm_calor->text())||(sl>1 && list[1] == itm_calor->text())||(sl>2 && list[2] == itm_calor->text()))
              {
                 itm_calor->setBackground(Qt::blue);

                 if(find==false)
                 {
                   vec_itm[0] = itm_calor;
                 }
                 vec_itm.push_back(itm_calor);
                 find=true;
              }
          }
        }
        if(!find)
        {
          QErrorMessage errorMessage;
          errorMessage.showMessage("Такой персоный нет!");
          errorMessage.exec();
        }
    }
}

void Dialog::add()
{
     ui->tableWidget->insertRow (ui->tableWidget->rowCount());
     int count_coum = ui->tableWidget->columnCount();
     while(count_coum!=0)
     {
         ui->tableWidget->setItem (ui->tableWidget->rowCount()-1,ui->tableWidget->columnCount()-count_coum, new QTableWidgetItem());
         count_coum--;
     }
     if(type_table==type_table_1)
     {
         QTableWidgetItem *itm =new QTableWidgetItem();
         itm->setText("Купить");
         ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,3,itm);

         btn = new QPushButton( "Купить!" );
         ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,3,btn);
         connect( btn, SIGNAL( clicked( bool ) ), SLOT( make_windows()));
     }
     if(type_table==4)
     {
         vec.push_back("");
         vec.push_back("");
         vec.push_back("");
     }
     add_row++;
     g=true;
}

void Dialog::removerow()
{
    if(g)
    {
       QTableWidgetItem *itm = ui->tableWidget->currentItem();

       if(itm==nullptr)
       {
         QErrorMessage errorMessage;
         errorMessage.showMessage("Нужно выбрать ячейку для удаления!");
         errorMessage.exec();
       }
       else
       {
            if(type_table==type_table_5 && add_row==0)
            {
                int count = ui->tableWidget->item(itm->row(),4-1)->text().toInt();
                QString type = ui->tableWidget->item(itm->row(),7-2)->text();
                name_performance = ui->tableWidget->item(itm->row(),7-1)->text();
                int type_int=-1;

              if(type=="Балкон")
              {
                 type_int= colum_t_0;
              }
              else if(type=="Ложи")
              {
                 type_int= colum_t_1;
              }
               else if(type=="Партер")
              {
                 type_int= colum_t_2;
              }
                  read_r.recalculation(false,name_performance,count,type_int);
                  ui->tableWidget->removeRow(itm->row());
                  if(add_row!=0)
                  {
                     add_row--;
                  }
            }
            else
            {
               ui->tableWidget->removeRow(itm->row());
               if(add_row!=0)
               {
                add_row--;
               }
            }
       }
       if(ui->tableWidget->rowCount()==0)
       {
        g=false;
       }
    }
}

void Dialog::make_window_cassir()
{
     cassir2 *w = new cassir2(person);
}

void Dialog::make_window_application()
{
     ordertoby *w4 =new ordertoby(person);
}

void Dialog::make_windows()
{
    QTableWidgetItem *itm = ui->tableWidget->currentItem();

    if(type_table==1)
    {
       if(itm->column()==0&&itm->text()!="")
       {
           performance2 *w2 = new performance2(itm->text(),person);
           itm_calor = itm; //ui->tableWidget->currentItem();
           itm_calor->setBackground(Qt::white);
       }
       if(itm->column()== colum_t_3)
       {
          tickets *w3 = new tickets(ui->tableWidget->item(itm->row(),0)->text(),person);
       }
    }
    if(type_table==type_table_4)
    {
       // QTableWidgetItem *itm = ui->tableWidget->currentItem();

        if(itm->text()!="")
        {
            int g=0;
            int x = itm->row();
            int y = itm->column();

            g=x*3+y;

            Acter *a = new Acter(person,&vec[g]);
            a->setAttribute(Qt::WA_DeleteOnClose);
            a->show();

            itm_calor = ui->tableWidget->currentItem();
            itm_calor->setBackground(Qt::white);
        }
    }
    if(type_table==type_table_3)
    {
      if((itm->row()==1)&&(itm->text()!=""))
      {
         by *order_by = new by(name_performance,itm);
         order_by->setAttribute(Qt::WA_DeleteOnClose);
         order_by->show();
         order_by->setWindowModality(Qt::ApplicationModal);

         if((order_by->exec() != by::Accepted) && (order_by->geter_temp() == true))
         {
             //QTableWidgetItem *itm_change = ui->tableWidget->currentItem();
               itm->setText(order_by->give_cahnge_tickets());
               ui->tableWidget->setItem(itm->row(),itm->column(),itm);
         }
      }
    }
}

void Dialog::closeEvent(QCloseEvent *e)
{
       int quit = QMessageBox::information(this,
                     "Realy quit?", "Are you sure?", tr("Yes"), tr("No"));

       if(quit == 1)
       {
          e->ignore();
       }
       else
       {
           if(type_table==type_table_2)
           {
              for(int i=0; i < ui->tableWidget->rowCount();i++)
              {
                  for(int j=i+1; j < ui->tableWidget->rowCount();j++)
                  {
                      if(ui->tableWidget->item(i,0)->text()==ui->tableWidget->item(j,0)->text())
                      {
                          QErrorMessage errorMessage;
                          errorMessage.showMessage("Найдены схожие логины!");
                          errorMessage.exec();
                          e->ignore();
                          break;
                      }
                  }
              }
           }
           if(type_table==type_table_5 && add_row>0)
           {
               for(int i = 0; i<add_row;i++)
               {
                 int j=ui->tableWidget->columnCount();
                 int type_int=-1;
                 int count = ui->tableWidget->item(ui->tableWidget->rowCount()-i-1,4-1)->text().toInt();
                 QString type = ui->tableWidget->item(ui->tableWidget->rowCount()-i-1,7-2)->text();
                 name_performance = ui->tableWidget->item(ui->tableWidget->rowCount()-i-1,7-1)->text();

                 while(j)
                 {
                     if(ui->tableWidget->item(ui->tableWidget->rowCount()-i-1,j-1)->text()=="")
                     {
                         QErrorMessage errorMessage;
                         errorMessage.showMessage("Элемент таблицы пуст");
                         errorMessage.exec();
                         e->ignore();
                         break;
                     }
                     j--;
                 }

                 if(type=="Балкон"||type=="Ложи"||type=="Партер")
                 {
                   if(type=="Балкон")
                   {
                     type_int=0;
                   }
                   else if(type=="Ложи")
                   {
                     type_int=1;
                   }
                   else if(type=="Партер")
                   {
                     type_int=2;
                   }
                   bool tf = read_r.recalculation(true,name_performance,count,type_int);
                   if (tf==0)
                   {e->ignore();}
                   else
                   {e->accept();}
                 }
                 else
                 {
                     QErrorMessage errorMessage;
                     errorMessage.showMessage("Нет такого типа билетов!");
                     errorMessage.exec();
                     e->ignore();
                 }
               }
           }
       }
       if(type_table==type_table_1||type_table==type_table_2||type_table==type_table_3)
       {
           for(int i =0;i< ui->tableWidget->rowCount();i++)
           {
             for(int j =0;j< ui->tableWidget->columnCount();j++)
             {
                 if(ui->tableWidget->item(i,j)->text()=="")
                 {
                     QErrorMessage errorMessage;
                     errorMessage.showMessage("Остались пустые поля!");
                     errorMessage.exec();
                     e->ignore();
                     break;
                 }
             }
           }
       }
       savefile();
}


