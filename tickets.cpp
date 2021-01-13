#include "tickets.h"

tickets::tickets(QString name_p,int person)
{
    mfile ="C:/Users/User/Documents/"+name_p+"tickets.txt";
    awe2 = new Dialog(name_p,person,NK,row,colum,mfile);
    awe2->setAttribute(Qt::WA_DeleteOnClose);
    awe2->show();
}

tickets::~tickets()
{
}


