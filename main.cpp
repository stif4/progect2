#include "afisha2.h"
#include "login.h"
#include <QApplication>
#include <QTextCodec>

#include <QDebug>
int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    //QTextCodec *codec = QTextCodec::codecForName("UTF-8");
   // QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    login log;
    log.show();

    if(log.exec() != login::Accepted)
    {
      if(log.login_in() == true)
      {
          qDebug()<<"here3";
         afisha2 w2(log.get_person());
      }
      else
      {
         return 0;
      }
    }

   return a.exec();
}
