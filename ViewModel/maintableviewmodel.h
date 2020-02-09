#ifndef MAINTABLEMODEL_H
#define MAINTABLEMODEL_H

#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QColor>
#include <QDate>
#include <QFont>
#include "database.h"
#include <QColor>
#include <QBrush>
#include "define.h"
#include <QColorDialog>


class MainTableModel : public QSortFilterProxyModel
{
    Q_OBJECT
private:
    QColor getColorForRow(int event) const;
    QString getTooltipForRow(QModelIndex index) const;
    void setHeaders();
public:
    DataBase        *db;
    MainTableModel(QObject *parent = nullptr);
    ~MainTableModel();
    QVariant data(const QModelIndex &item, int role) const;
};




#endif // MAINTABLEMODEL_H
