#ifndef ORDERTOBY_H
#define ORDERTOBY_H

#include "dialog.h"
#include "reader.h"

class ordertoby
{
public:
    ordertoby(int person);

private:
    Dialog *awe2;

    reader re;

    int colum = 7;
    int row =0;
    int NK=5;
    QVector<int> vec;

    QString mfile = "C:/Users/User/Documents/orders.txt";
    //QString mfile_rec = "tickets.txt";
};

#endif // ORDERTOBY_H
