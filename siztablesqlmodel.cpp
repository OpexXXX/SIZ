#include "siztablesqlmodel.h"

SizVerifiSqlModel::SizVerifiSqlModel(QObject *parent):QSqlQueryModel (parent)
{

}
SizVerifiSqlModel::~SizVerifiSqlModel(){}






QVariant SizVerifiSqlModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);


    if (value.isValid() && role == Qt::DisplayRole) {
        if (index.column() == 1){
            QString result ="";

            QVariant  id11 = this->data( this->index(index.row(), 5),0); //Тип СИЗ
            QVariant  id1 = this->data( this->index(index.row(), 4),0); //Дата истечения испытания
            QDate  endDate =QDate::fromString(id1.toString(),"yyyy-MM-dd"); //Дата истечения испытания

            QDate curr = QDate::currentDate();

            long long days = curr.daysTo(endDate)+0;
            if(days>0){
                result =  QString::number(days) + QString(" дней до изъятия '"+id11.toString()+"' №"+value.toString());
            }else{
                result = "ПРОСРОЧЕН на " + QString::number(days*(-1)) + QString(" дней  '"+id11.toString()+"' №"+value.toString());
            }
            return result;

        }

    }
    if (role == Qt::TextColorRole && index.column() == 1)
    {
        QVariant  id1 = this->data( this->index(index.row(), 4),0); //Дата истечения испытания
        QDate  endDate =QDate::fromString(id1.toString(),"yyyy-MM-dd"); //Дата истечения испытания

        QDate curr = QDate::currentDate();

        long long days = curr.daysTo(endDate)+0;
        if(days<=10 &&days>0){
            return qVariantFromValue(QColor(Qt::magenta));}
        else if(days>10 ){
             return qVariantFromValue(QColor(Qt::black));
        }else{
            return qVariantFromValue(QColor(Qt::red));
        }
    }
    return value;
}
