#ifndef SIZTABLESQLMODEL_H
#define SIZTABLESQLMODEL_H

#include <QSqlQueryModel>
#include <QColor>
#include <QDate>
#include <QFont>
#include "database.h"

class SizVerifiSqlModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    DataBase *datB;
    SizVerifiSqlModel(QObject *parent = nullptr, DataBase *datB=nullptr);
    ~SizVerifiSqlModel();
    QVariant data(const QModelIndex &item, int role) const;
};
#endif // SIZTABLESQLMODEL_H
