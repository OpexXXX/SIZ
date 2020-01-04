#include "maintablemodel.h"



MainTableModel::MainTableModel(QObject *parent, DataBase *db):QSqlTableModel (parent)
{
this->db = db;

}
MainTableModel::~MainTableModel(){}






QVariant MainTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);

if (role == Qt::DisplayRole){
    switch (index.column()) {
    case 3:         //Дата поверки
        if (value.isValid()) {

                QString result ="";
                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата
                result = Date.toString("dd.MM.yyyy");
                return result;

        }
        break;
    case 4:         //Дата поверки
        if (value.isValid()) {

                QString result ="";
                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата
                result = Date.toString("dd.MM.yyyy");
                return result;

        }
        break;
    case 7:         //Дата поверки
        if (value.isValid()) {

                QString result ="";
                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата
                result = Date.toString("dd.MM.yyyy");
                return result;

        }
        break;
    case 11:         //Дата поверки
        if (value.isValid()) {

                QString result ="";
                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата
                result = Date.toString("dd.MM.yyyy");
                return result;

        }
        break;
    default:

        break;
    }
}
    return value;
}
