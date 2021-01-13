#include "cchoicepathdelegate.h"

CChoicePathDelegate::CChoicePathDelegate(int NK,int stay,QObject *parent): QStyledItemDelegate(parent)
{
    NKk=NK;
    stay_NKk=stay;
}

QWidget *CChoicePathDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    if(NKk==1)
    {
        if(stay_NKk==1)
        {
          editor->setValidator(new QRegExpValidator(QRegExp(R"((0[1-9]|[12][0-9]|3[01])[.](0[1-9]|1[012])[.](19|20)\d\d)"), editor));
        }
        else if(stay_NKk==2)
        {
          editor->setValidator(new QRegExpValidator(QRegExp("([0-1][0-9]|[2][0-3])[:]([0-5][0-9])"), editor));
        }
        else
        {
          editor->setValidator(new QRegExpValidator(QRegExp("([А-Я,а-я, ]{0,30}|[0-9, ]{0,1000})([А-Я,а-я, ]{0,30}|[0-9, ]{0,1000})([А-Я,а-я, ]{0,30}|[0-9, ]{0,1000})"), editor));
        }
    }
    else if(NKk==4)
    {
         editor->setValidator(new QRegExpValidator(QRegExp("([А-Я][А-Я,а-я]{1,30})[.]([А-Я,а-я])[.]([А-Я,а-я])[.]"), editor));
    }
    else if(NKk==3)
    {
         editor->setValidator(new QRegExpValidator(QRegExp("[0-9]{1,10}"), editor));
    }
    else if(NKk==5)
    {
        if(stay_NKk==1||stay_NKk==2||stay_NKk==3)
        {
            editor->setValidator(new QRegExpValidator(QRegExp("([А-Я][А-Я,а-я]{1,30})"), editor));
        }
        if(stay_NKk==4)
        {
            editor->setValidator(new QRegExpValidator(QRegExp("[0-9][0-9]{0,4}"), editor));
        }
        if(stay_NKk==5)
        {
            editor->setValidator(new QRegExpValidator(QRegExp("[8][0-9]{10}"), editor));
        }
        if(stay_NKk==6)
        {
            editor->setValidator(new QRegExpValidator(QRegExp("[Балкон]{6}|[Ложи]{4}|[Партер]{6}"), editor));
        }
        if(stay_NKk==7)
        {
            editor->setValidator(new QRegExpValidator(QRegExp("([А-Я,а-я]{0,30}|[0-9]{0,1000})([А-Я,а-я]{0,30}|[0-9]{0,1000})([А-Я,а-я]{0,30}|[0-9]{0,1000})"), editor));
        }
    }
    return editor;
}

void CChoicePathDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    qobject_cast<QLineEdit *>(editor)->setText(index.data().toString());
}

void CChoicePathDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);
}
