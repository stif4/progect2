#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QFile>
#include <QString>
#include <QTextStream>
#include "by.h"
#include "reader.h"

#include <QTableWidgetItem>

#include <QMenuBar>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public slots:

    void add();
    void removerow();

    void make_window_cassir();
    void make_window_application();
    void make_windows();
    void closeEvent(QCloseEvent *e);
    void search();

public:
    Dialog(QString name_p,int person_log,int NK,int row,int colum,QString file1,QWidget *parent = nullptr);
    ~Dialog();

    void readfile();
    void savefile();

    friend void make_cassir();
private:
    Ui::Dialog *ui;
    int type_table;
    int person;
    QString name_performance;

    int add_row=0;
    int delete_row=0;

    reader read_r;

    QVector<QString> vec;

    QTableWidgetItem *itm_calor=nullptr;
    QTableWidgetItem *itm_calor_brfore=nullptr;
    QVector<QTableWidgetItem*> vec_itm;

    QString mfile;
    QGridLayout *layout;
    QMenu *menu;
    QAction *editCasir;
    QAction *application;
    QMenuBar *menubar;

    QPushButton* btn;
    bool g=true;

    int colum_t_0=0;
    int colum_t_1=1;
    int colum_t_2=2;
    int colum_t_3=3;
    int colum_t_4=4;
    int colum_t_5=5;
    int colum_t_6=6;
    int colum_t_7=7;

    int type_person_1=1;
    int type_person_2=2;
    int type_person_3=3;

    int type_table_1=1;
    int type_table_2=2;
    int type_table_3=3;
    int type_table_4=4;
    int type_table_5=5;



};
#endif // DIALOG_H
