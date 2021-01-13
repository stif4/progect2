#include "ordertoby.h"

#include <QErrorMessage>
#include <QFile>
#include <QString>
#include <QTextStream>

ordertoby::ordertoby(int person)
{
    row = re.read(mfile);
    awe2 = new Dialog("",person,NK,row,colum,mfile);
    awe2->setAttribute(Qt::WA_DeleteOnClose);
    awe2->show();
}



