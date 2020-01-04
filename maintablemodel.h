#ifndef MAINTABLEMODEL_H
#define MAINTABLEMODEL_H

#include <QSqlTableModel>
#include <QColor>
#include <QDate>
#include <QFont>
#include "database.h"
#include <QColor>
#include <QBrush>
class MainTableModel : public QSqlTableModel
{
    Q_OBJECT
private:
    QColor calculateColorForRow(int index) const;
    QString getTooltipForRow(int index) const;
public:
    DataBase        *db;
    MainTableModel(QObject *parent = nullptr,QList<QPair<int,QPair<int,QString> > >  *eventArray=nullptr, DataBase        *db = nullptr);
    ~MainTableModel();
    QVariant data(const QModelIndex &item, int role) const;
    QList<QPair<int,QPair<int,QString> > >  *eventArray;
};




#endif // MAINTABLEMODEL_H
