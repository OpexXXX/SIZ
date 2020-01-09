#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H

#include <QWidget>
#include <QStyledItemDelegate>

class ComboBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
   public:

        ComboBoxItemDelegate(QObject *parent = nullptr, QAbstractItemModel *model = nullptr);

       QAbstractItemModel *cbModel;
       QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
       void setEditorData(QWidget *editor, const QModelIndex &index) const override;
       void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};

#endif // COMBOBOXITEMDELEGATE_H
