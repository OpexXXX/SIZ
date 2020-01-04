#include "maintablemodel.h"



MainTableModel::MainTableModel(QObject *parent, QList<QPair<int,QPair<int,QString> > >  *eventArray, DataBase *db ):QSqlTableModel (parent)
{
    this->db = db;
    this->eventArray = eventArray;
}
MainTableModel::~MainTableModel(){}

QColor MainTableModel::calculateColorForRow(int index) const
{
    QColor col = QColor(Qt::white);
    for (int i = 0;i<eventArray->count() ;i++ ) {
        if(eventArray->at(i).second.first==index){
            if(eventArray->at(i).first<=0)
                col= QColor(239, 41, 41,120);
            else
                col= QColor(252, 175, 62,120);
            return col;
        }
    }
    return col;
}


QVariant MainTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlTableModel::data(index, role);

    if (role == Qt::BackgroundRole) {
        QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);

        int id = data(primaryKeyIndex,0).toInt();

        QColor color = calculateColorForRow(id);
        return QBrush(color);
    }
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
