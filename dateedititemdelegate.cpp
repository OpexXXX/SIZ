#include "dateedititemdelegate.h"
#include <QDateEdit>
#include "mainsizwindow.h"
DateEditItemDelegate::DateEditItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{


}
DateEditItemDelegate::~DateEditItemDelegate()
{
}


QWidget *DateEditItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
    QDateEdit *cb = new QDateEdit(parent);
    cb->setMaximumDate(QDate::fromString("01.01.2030","dd.MM.yyyy"));
    cb->setMinimumDate(QDate::fromString("01.01.2014","dd.MM.yyyy"));
    cb->setCalendarPopup(true);
    const int row = index.row();
    return cb;
}


void DateEditItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDateEdit *cb = qobject_cast<QDateEdit *>(editor);
    Q_ASSERT(cb);
    // get the index of the text in the combobox that matches the current value of the item
 const QString currentText = index.data(Qt::EditRole).toString();

    // if it is valid, adjust the combobox
 QDate datte = *new QDate () ;
 datte.fromString(currentText,"yyyy-MM-dd");

    cb->setDate(QDate::fromString(currentText,"yyyy-MM-dd"));

}


void DateEditItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateEdit *cb = qobject_cast<QDateEdit *>(editor);
    Q_ASSERT(cb);
    if(cb->date().toString("yyyy-MM-dd" )=="2014-01-01" )
    {
         model->setData(index, "", Qt::EditRole);
    }else{

        model->setData(index, cb->date().toString("yyyy-MM-dd"), Qt::EditRole);
    }
}
