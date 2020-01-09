#ifndef DATEEDITITEMDELEGATE_H
#define DATEEDITITEMDELEGATE_H
#include <QWidget>
#include <QStyledItemDelegate>

class DateEditItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    DateEditItemDelegate(QObject *parent = nullptr);
    ~DateEditItemDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};

#endif // DATEEDITITEMDELEGATE_H
