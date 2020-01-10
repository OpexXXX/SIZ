#ifndef EVENTVIEWMODEL_H
#define EVENTVIEWMODEL_H
#include <QSortFilterProxyModel>

class EventViewModel : public QSortFilterProxyModel
{
public:
   EventViewModel(QObject *parent);
};

#endif // EVENTVIEWMODEL_H
