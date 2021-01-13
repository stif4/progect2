#ifndef AFISHA2_H
#define AFISHA2_H

#include <QWidget>

#include "dialog.h"

#include "reader.h"

namespace Ui {
class afisha2;
}

class afisha2 : public QWidget
{
    Q_OBJECT

public:
    explicit afisha2(int person,QWidget *parent = nullptr);
    ~afisha2();

    //void read_line_file();

private:

Dialog *awe;

reader re;

int colum = 4;
int row =0;

int NK=1;

QString mfile = "C:/Users/User/Documents/vano1.txt";

};

#endif // AFISHA2_H
