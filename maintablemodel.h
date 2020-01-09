#ifndef MAINTABLEMODEL_H
#define MAINTABLEMODEL_H

#include <QSqlTableModel>
#include<QSortFilterProxyModel>
#include <QColor>
#include <QDate>
#include <QFont>
#include "database.h"
#include <QColor>
#include <QBrush>
enum MainSizModelHead
{ id=0,
    number,
    verificationDate,
    endVerificationDate,
    inspectionDate,
    nameSiz,
    object,
    personalDate,
    persona,
    note,
    bool_removed,
    bool_verification,
    verifiPediod,
    inspectPediod,
    personalyty
};

class MainTableModel : public QSortFilterProxyModel
{
    Q_OBJECT
private:
    QColor calculateColorForRow(int index) const;
    QString getTooltipForRow(int index) const;
public:
    DataBase        *db;
    MainTableModel(QObject *parent = nullptr);
    ~MainTableModel();
    QVariant data(const QModelIndex &item, int role) const;

};




#endif // MAINTABLEMODEL_H
