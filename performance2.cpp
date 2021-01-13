#include "performance2.h"

performance2::performance2(QString name_p,int persen)
{
    mfile="C:/Users/User/Documents/"+name_p+".txt";
    row = re.read(mfile);
    awe2 = new Dialog(name_p,persen,NK,row,colum,mfile);
    awe2->setAttribute(Qt::WA_DeleteOnClose);
    awe2->show();
}
