#include "reader.h"
#include <QDebug>
reader::reader()
{
}

int reader::read(QString file_name)
{
    QFile file(file_name);
    QString line1="";
    if(!file.exists())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Файл был создан, т.к не был найден в системе!");
        errorMessage.exec();
    }
    else
    {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            while (!stream.atEnd())
            {
              QByteArray line = file.readLine();
              row_count++;
            }
        }
        file.close();
    }
    return row_count;
}

void reader::savefile()
{
    QFile file(mfile_rec);

    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        for(int i=0; i<vec.size()-1;i++)
        {
            if(i==3)
            {
              stream<<"\n";
            }
           stream<<QString::number(vec[i])<<" ";
        }
    }
    file.close();
    vec.clear();
}

bool reader::recalculation(bool plus_or_minus,QString name_performace,int count,int type)
{
    mfile_rec ="C:/Users/User/Documents/"+name_performace+"tickets.txt";
    QFile file(mfile_rec);
    QString line1="";
    if(!file.exists())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Вернуть или взять билет не возможно, нет билетов списка билетов на спектакль");
        errorMessage.exec();
        return 0;
    }
    else
    {
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            while(!stream.atEnd())
            {
                stream>>line1;
                vec.push_back(line1.toInt());
            }
        }
        file.close();
    }
    if(plus_or_minus==false)
    {
        vec[type+3] = vec[type+3] + count;
        savefile();
        return 1;
    }
    if(vec[type+3]<count)
    {
         QErrorMessage errorMessage;
         errorMessage.showMessage("В кассе нет столько билетов!");
         errorMessage.exec();
         return 0;
    }
    else
    {
      if(plus_or_minus==true)
      {
         vec[type+3] = vec[type+3] - count;
         savefile();
      } 
      return 1;
    }

}

