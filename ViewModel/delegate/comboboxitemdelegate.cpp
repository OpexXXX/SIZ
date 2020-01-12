#include "comboboxitemdelegate.h"
#include <QComboBox>
#include <QAbstractItemModel>
#include "mainsizwindow.h"

ComboBoxItemDelegate::ComboBoxItemDelegate(QObject *parent ,QAbstractItemModel *model )
    : QStyledItemDelegate(parent)
{

    this->cbModel=model;

}




QWidget *ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
QComboBox *cb = new QComboBox(parent);
cb->setModel(cbModel);
cb->setModelColumn(1);
    return cb;
}


void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    // get the index of the text in the combobox that matches the current value of the item
    const QString currentText = index.data(Qt::EditRole).toString();

    int cbIndex = cb->findText(currentText);

    if(cbIndex<0) {
        cbIndex = index.data(Qt::EditRole).toInt();
    }
    // if it is valid, adjust the combobox
    if (cbIndex >= 0)
       cb->setCurrentIndex(cbIndex);
}


void ComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QVariant prevous = model->data(index);

    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
     QModelIndex primaryKeyIndex = cbModel->index(cb->currentIndex(), 0);
       QModelIndex primaryKeyIndexString = cbModel->index(cb->currentIndex(), 1);

    QString idString =  cbModel->data(primaryKeyIndexString, Qt::DisplayRole).toString();
    int id =  cbModel->data(primaryKeyIndex, Qt::DisplayRole).toInt();
  //  QVariant c = cb->(, Qt::UserRole );

    if(idString!=prevous.toString()){
        model->setData(index, id, Qt::EditRole);
    }

}
