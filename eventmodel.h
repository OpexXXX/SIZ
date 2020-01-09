#ifndef EVENTMODEL_H
#define EVENTMODEL_H
#include <QSortFilterProxyModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QSqlQuery>
#include <QSqlRecord>

class EventList : public QSortFilterProxyModel
{
public:
    EventList(QObject *parent);

    void delEvent(const QModelIndex & index);
    bool contain(int id);
   // EventSiz& getEventByID(intId) const;
    void updateEvents(QSqlQuery* query);
private:


};


#endif // EVENTMODEL_H
