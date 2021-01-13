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
    int NKk;
    int stay_NKk;
};

#endif // CCHOICEPATHDELEGATE_H
