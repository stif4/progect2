#ifndef PERFORMANCE2_H
#define PERFORMANCE2_H

#include "dialog.h"
#include "reader.h"

class performance2
{
public:
    performance2(QString name_p,int person);
private:
    Dialog *awe2;

    reader re;

    int tupe_per;
    int colum = 3;
    int row =0;
    int NK=4;
    QString mfile;

   // QString mfile = "performance.txt";
};

#endif // PERFORMANCE2_H
