#ifndef SIZTABLESQLMODEL_H
#define SIZTABLESQLMODEL_H

#include <QSqlQueryModel>
#include <QColor>
#include <QDate>
#include <QFont>
class SizVerifiSqlModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    SizVerifiSqlModel(QObject *parent = nullptr);
    ~SizVerifiSqlModel();
    QVariant data(const QModelIndex &item, int role) const;
};
#endif // SIZTABLESQLMODEL_H
