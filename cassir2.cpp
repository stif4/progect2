#include "cassir2.h"

cassir2::cassir2(int person ,QWidget *parent) :
    QDialog(parent)
{
    row = re.read(mfile);

    awe2 = new Dialog("",person,NK,row,colum,mfile);
    awe2->setAttribute(Qt::WA_DeleteOnClose);
    awe2->show();
}

cassir2::~cassir2()
{
}


