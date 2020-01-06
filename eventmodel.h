#ifndef EVENTMODEL_H
#define EVENTMODEL_H
#include <QAbstractTableModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QSqlQuery>
#include <QSqlRecord>
#include "eventsiz.h"
class EventList : public QAbstractTableModel
{
public:
    EventList(QObject *parent);
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
    Qt::ItemFlags flags (const QModelIndex & index) const;
    void addEvent(EventSiz& newEvent);
    void delEvent(const QModelIndex & index);
    EventSiz& getEvent(const QModelIndex & index) const;
    EventSiz& getEvent( int id) const;
    bool contain(int id);
    EventSiz& getEventByID(const QModelIndex & index) const;
    void updateEvents(QSqlQuery* query);
private:
    EventSiz& getByID(int id) const;
    QList<EventSiz> *listOfEvents;
    QVariant getData(int num, int position) const;

};


#endif // EVENTMODEL_H
