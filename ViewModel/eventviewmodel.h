#ifndef EVENTVIEWMODEL_H
#define EVENTVIEWMODEL_H
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QColor>
#include <QDate>
#include <QFont>
#include "database.h"
#include <QColor>
#include <QBrush>
#include "define.h"
class EventViewModel : public QSortFilterProxyModel
{
public:
   EventViewModel(QObject *parent);
   QVariant data(const QModelIndex &index, int role) const;
private:
   bool  filterAcceptsRow ( int sourceRow , const QModelIndex & sourceParent ) const;
   QColor getColorForRow(int event) const;
   QString getMessage(const QModelIndex &index) const;
   QStringList getRow(const QModelIndex &index);
};

#endif // EVENTVIEWMODEL_H
