#ifndef MAINTABLEMODEL_H
#define MAINTABLEMODEL_H

#include <QSqlTableModel>
#include <QColor>
#include <QDate>
#include <QFont>
#include "database.h"

class MainTableModel : public QSqlTableModel
{
    Q_OBJECT

public:
    DataBase        *db;
    MainTableModel(QObject *parent = nullptr, DataBase        *db = nullptr);
    ~MainTableModel();
    QVariant data(const QModelIndex &item, int role) const;

};




#endif // MAINTABLEMODEL_H
