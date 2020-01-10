#include "checkboxitemdelegate.h"
#include <QCheckBox>
#include "mainsizwindow.h"
#include <QPainter>

CheckBoxItemDelegate::CheckBoxItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}


CheckBoxItemDelegate::~CheckBoxItemDelegate()
{
}


QWidget *CheckBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Create the combobox and populate it
    QCheckBox *cb = new QCheckBox(parent);
    const int row = index.row();
    return cb;
}


void CheckBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QCheckBox *cb = qobject_cast<QCheckBox *>(editor);
    Q_ASSERT(cb);
    // get the index of the text in the combobox that matches the current value of the item
   bool state =  index.data(Qt::EditRole).toBool();

    // if it is valid, adjust the combobox
    if (state)
       {cb->setCheckState(Qt::Checked);}
    else {cb->setCheckState(Qt::Unchecked);}
}


void CheckBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox *cb = qobject_cast<QCheckBox *>(editor);
    Q_ASSERT(cb);
    model->setData(index, cb->isChecked(), Qt::EditRole);
}

void CheckBoxItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
 const QModelIndex &index) const
{
 QString val;

 if (index.data().toBool())
 {

 const int PaintingScaleFactor = 100;

 QPolygonF diamondPolygon;
 painter->save();
 painter->setRenderHint(QPainter::Antialiasing, true);
 painter->setPen(Qt::NoPen);
 painter->setBrush( option.palette.dark() );
 int yOffset = (option.rect.height() - PaintingScaleFactor) / 2;
 painter->translate(option.rect.x(), option.rect.y() + yOffset);
 painter->scale(PaintingScaleFactor, PaintingScaleFactor);
 // создание ромба следует вынести из этой функции в конструктор.
 // Оставлено только с целью иллюстрации
 diamondPolygon << QPointF(0.4, 0.5) << QPointF(0.5, 0.4)
 << QPointF(0.6, 0.5) << QPointF(0.5, 0.6)
<< QPointF(0.4, 0.5);
 painter->drawPolygon(diamondPolygon, Qt::WindingFill);
 painter->translate(1.0, 0.0);
 painter->restore();

 }
 else {

// Для всех отстальных случаев выполняем действие по умолчанию
 //QItemDelegate::paint(painter, option, index);
 }
}
