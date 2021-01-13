#include "afisha2.h"
#include "dialog.h"

afisha2::afisha2(int person,QWidget *parent) :
    QWidget(parent)
{
    row = re.read(mfile);
    awe = new Dialog("",person,NK,row,colum,mfile);
    awe->setAttribute(Qt::WA_DeleteOnClose);
    awe->show();
}

afisha2::~afisha2()
{

}


