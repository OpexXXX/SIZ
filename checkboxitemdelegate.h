#ifndef CHECKBOXITEMDELEGATE_H
#define CHECKBOXITEMDELEGATE_H
#include <QWidget>
#include <QStyledItemDelegate>
#include <QItemDelegate>
class CheckBoxItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
   public:
       CheckBoxItemDelegate(QObject *parent = nullptr);
       ~CheckBoxItemDelegate();

       QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
       void setEditorData(QWidget *editor, const QModelIndex &index) const override;
       void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
       /// переопределяем функцию рисования для замены отображения
       /// не редактируемого в данный момент элемента
        virtual void paint(QPainter *painter, const QStyleOptionViewItem &option,
        const QModelIndex &index) const;
};

#endif // CHECKBOXITEMDELEGATE_H
