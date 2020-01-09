#ifndef SIZMODEL_H
#define SIZMODEL_H
#include <QSqlRelationalTableModel>
#include <QDebug>
class sizModel : public QSqlRelationalTableModel
{
public:
      sizModel(QObject *parent = nullptr);
     int chekRowForEvent(const QModelIndex &index);
     bool setData(const QModelIndex &index,const QVariant &value, int role);
};

#endif // SIZMODEL_H
