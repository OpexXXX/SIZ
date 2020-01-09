#include "sizmodel.h"



sizModel::sizModel(QObject *parent):QSqlRelationalTableModel (parent)
{


}
bool sizModel::setData(const QModelIndex &index,
                              const QVariant &value, int role)
{

int col = index.column();
    if (((col>=2 &&col<=5) || (col>=11 &&col<=14))&&role == Qt::EditRole) {

 QVariant d = QSqlRelationalTableModel::data(index);
 if(d!=value) chekRowForEvent(index);

    }
    return this->QSqlRelationalTableModel::setData(index,value,role);

}
int sizModel::chekRowForEvent(const QModelIndex &index)
{
   QVariant d =  data(sizModel::index(index.row(),2,index.parent()));
    qDebug()<<d;
     d =  data(sizModel::index(index.row(),3,index.parent()));
     qDebug()<<d;
      d =  data(sizModel::index(index.row(),4,index.parent()));
      qDebug()<<d;
}
