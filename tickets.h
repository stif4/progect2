#ifndef TICKETS_H
#define TICKETS_H

#include "dialog.h"

class tickets
{
public:
    tickets(QString name_p,int persen);

    ~tickets();
private:

    Dialog *awe2;

    int *y1;
    int colum = 3;
    int row =2;
    int NK=3;

    QString mfile;
};

#endif // TICKETS_H
