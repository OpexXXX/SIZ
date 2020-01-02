#include "comboboxitemdelegate.h"
#include <QComboBox>
#include "mainsizwindow.h"

ComboBoxItemDelegate::ComboBoxItemDelegate(QObject *parent , const QStringList &itemName )
    : QStyledItemDelegate(parent)
{

this->objects = itemName;

}


ComboBoxItemDelegate::~ComboBoxItemDelegate()
{
}


QWidget *ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
    QComboBox *cb = new QComboBox(parent);
    const int row = index.row();



            // Преобразуем Вариант в наш список


cb->addItem(QString(""));
        // Инициализируем наш Комбо
    for (int i = 0 ; i<this->objects.length();i++)
    {

      cb->addItem(QString(objects[i]));
}


    return cb;
}


void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    // get the index of the text in the combobox that matches the current value of the item
    const QString currentText = index.data(Qt::EditRole).toString();
    const int cbIndex = cb->findText(currentText);
    // if it is valid, adjust the combobox
    if (cbIndex >= 0)
       cb->setCurrentIndex(cbIndex);
}


void ComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    model->setData(index, cb->currentText(), Qt::EditRole);
}
