#ifndef READER_H
#define READER_H

#include<QString>

#include <QErrorMessage>
#include <QFile>
#include <QString>
#include <QTextStream>

class reader
{
public:
    reader();
    int read(QString name_file);

    void savefile();
    bool recalculation(bool plus_or_minus,QString name_performace,int count,int type);

private:
    int row_count=0;

    QVector<int> vec;

    QString mfile = "C:/Users/User/Documents/orders.txt";
    QString mfile_rec;

};

#endif // READER_H
