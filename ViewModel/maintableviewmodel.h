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
    personalyty,
    event,
    daysToEvent
};
enum SizEvent{
    noEvent=0,
    verificationExpired,
    inspectionExpired,
    verificationSoon,
    inspectionSoon,
    serviceLifeExpired
};

#define VERIFICATION_EXPIRED_COLOR  QColor( 255,0,0,120)
#define INSPECTION_EXPIRED_COLOR    QColor( 255,99,71,120)
#define VERIFICATION_SOON_COLOR     QColor(0,206,209,120)
#define INSPECTION_SOON_COLOR       QColor(50,205,50,120)
#define SERVICELIFE_EXPIRED_COLOR   QColor( 255,0,0,120)

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
