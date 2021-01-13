#ifndef CASSIR2_H
#define CASSIR2_H

#include "dialog.h"
#include "reader.h"

namespace Ui {
class cassir2;
}

class cassir2 : public QDialog
{
    Q_OBJECT

public:
    explicit cassir2(int person,QWidget *parent = nullptr);
    ~cassir2();

    //void read_line_file();

private:

Dialog *awe2;

reader re;

int colum = 2;
int row =0;

int NK=2;

QString mfile = "C:/Users/User/Documents/cassirs.txt";

};

#endif // CASSIR2_H
