#ifndef SIZMODEL_H
#define SIZMODEL_H
#include <QSqlRelationalTableModel>
#include <QDebug>
class sizModel : public QSqlRelationalTableModel
{
public:
      sizModel(QObject *parent = nullptr);
     bool setData(const QModelIndex &index,const QVariant &value, int role);
     void setDaysToEvents(int days);
     int getDaysToEvent();
private:
     void chekRowForEvent(const QModelIndex &index);
     void setTypeSizData(const QModelIndex &index);
     int _daysToEvent=20;
     QVariant getColumnValue(const QModelIndex &index, int column);
     void setEventDataToRow(int event, int daysToEvent, const QModelIndex &index);
public slots:
     void dataToEventCalcChange(QModelIndex,QModelIndex);
};

#endif // SIZMODEL_H
