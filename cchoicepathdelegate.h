#ifndef CCHOICEPATHDELEGATE_H
#define CCHOICEPATHDELEGATE_H

#include "dialog.h"
#include <QWidget>
#include <QStyledItemDelegate>
#include <QLineEdit>

class CChoicePathDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit CChoicePathDelegate(int NK,int stay,QObject *parent = Q_NULLPTR);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

private:
    int type_table;
    int stay_type_table;

    int colum_1=1;
    int colum_2=2;
    int colum_3=3;
    int colum_4=4;
    int colum_5=5;
    int colum_6=6;
    int colum_7=7;

};

#endif // CCHOICEPATHDELEGATE_H
