#ifndef SIZMODEL_H
#define SIZMODEL_H
#include <QSqlRelationalTableModel>
#include <QDebug>
class sizModel : public QSqlRelationalTableModel
{
public:
      sizModel(QObject *parent = nullptr);

     void setDaysToEvents(int days);
     int getDaysToEvent();
     void updateAllEvents();

private:
     void chekRowForEvent(QModelIndex index);
     void setTypeSizData(const QModelIndex &index);
     int _daysToEvent=20;
     QVariant getColumnValue(QModelIndex index, int column);
     void setEventDataToRow(int event, int daysToEvent, QModelIndex index);
public slots:
     void dataToEventCalcChange(QModelIndex,QModelIndex);
};

#endif // SIZMODEL_H
