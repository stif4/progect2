#include "cassir2.h"
/*
#include <QErrorMessage>
#include <QFile>
#include <QString>
#include <QTextStream>
*/
cassir2::cassir2(int person ,QWidget *parent) :
    QDialog(parent)
{
    //read_line_file();
    row = re.read(mfile);

    awe2 = new Dialog("",person,NK,row,colum,mfile);
    awe2->setAttribute(Qt::WA_DeleteOnClose);
    awe2->show();
}

cassir2::~cassir2()
{
}


