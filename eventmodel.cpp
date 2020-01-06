#include "eventmodel.h"


EventList::EventList(QObject *parent) : QAbstractTableModel(parent) {
    listOfEvents = new QList<EventSiz > ();
}

int EventList::columnCount(const QModelIndex & parent) const {
    return 3;
}
int EventList::rowCount(const QModelIndex& parent) const {
    return listOfEvents->size();
}
QVariant EventList::data(const QModelIndex& index, int role) const {
    if (index.isValid() && role == Qt::DisplayRole)
        return getData(index.row(), index.column());
    return QVariant();
}

QVariant EventList::getData(int num, int position) const {
    switch (position) {
    case 0:
        return QVariant(listOfEvents->at(num).getId());
    case 1:
        return QVariant(listOfEvents->at(num).getType());
    case 2:
        return QVariant(listOfEvents->at(num).getNumber());

    default:
        return QVariant();
    }
}


QVariant EventList::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Vertical)
        return QVariant(section + 1);
    else
        switch (section) {
        case 0:
            return QVariant("ID");
        case 1:
            return QVariant("Тип СИЗ");
        case 2:
            return QVariant("НОМЕР");
        case 3:

            return QVariant();
        }
}
Qt::ItemFlags EventList::flags(const QModelIndex & index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEnabled|Qt::ItemIsEditable;
}

EventSiz& EventList::getEvent(const QModelIndex & index) const {
    return (*listOfEvents)[index.row()];
}
bool EventList::contain(int id)
{
    for (int i=0;i<listOfEvents->size() ;i++) {
        if(listOfEvents->at(i).getId()==id)
        {
            return true;
        }
    }
      return false;
}
EventSiz& EventList::getEvent(int id) const {

    for (int i=0;i<listOfEvents->size() ;i++) {
        if(listOfEvents->at(i).getId()==id)
        {
            return (*listOfEvents)[i];
        }
    }
    return (*listOfEvents)[0];          //  ***************************************
}

void EventList::updateEvents(QSqlQuery* query) {


}
void EventList::addEvent(EventSiz& newEvent) {
    beginInsertRows(QModelIndex(), listOfEvents->size(), listOfEvents->size());
    listOfEvents->append(newEvent);
    endInsertRows();
}
void EventList::delEvent(const QModelIndex &index) {
    beginRemoveRows(QModelIndex(), index.row(), index.row());
    listOfEvents->removeAt(index.row());
    endRemoveRows();
}
