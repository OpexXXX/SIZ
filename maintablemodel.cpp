#include "maintablemodel.h"

MainTableModel::MainTableModel(QObject *parent):QSortFilterProxyModel (parent)
{


}
MainTableModel::~MainTableModel(){}

QColor MainTableModel::calculateColorForRow(int index) const
{
    QColor col = QColor(Qt::white);
  /*  for (int i = 0;i<eventArray->count() ;i++ ) {
        if(eventArray->at(i).second.first==index){
            if(eventArray->at(i).first<=0)
                col= QColor(239, 41, 41,120);
            else
                col= QColor(252, 175, 62,120);
            return col;
        }
    }*/
    return col;
}
QString MainTableModel::getTooltipForRow(int index) const
{
    QString tooltip = "";
    /*for (int i = 0;i<eventArray->count() ;i++ ) {
        if(eventArray->at(i).second.first==index){
           tooltip= eventArray->at(i).second.second;
            return tooltip;
        }
    }*/
    return tooltip;
}
QVariant MainTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSortFilterProxyModel::data(index, role);

    if (role == Qt::ToolTipRole) {
       // QModelIndex primaryKeyIndex = QIdentityProxyModel::index(index.row(), 0);
       // int id = data(primaryKeyIndex,0).toInt();
        QString tooltip = getTooltipForRow(id);
        return tooltip;
    }
    if (role == Qt::BackgroundRole) {
      //  QModelIndex primaryKeyIndex = QIdentityProxyModel::index(index.row(), 0);
//
      //  int id = data(primaryKeyIndex,0).toInt();

        QColor color = calculateColorForRow(id);
        return QBrush(color);
    }
      QString result ="";
    if (role == Qt::DisplayRole){
        switch (index.column()) {
        case MainSizModelHead::verificationDate:         //Дата поверки
            if (value.isValid()) {


                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата
                result = Date.toString("dd.MM.yyyy");
                if (value.toString()==""){
                    return "-";}else{
                    return result;
                }

            }
            break;
        case MainSizModelHead::endVerificationDate:         //Дата
            if (value.isValid()) {


                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата

                result = Date.toString("dd.MM.yyyy");
                if (value.toString()==""){
                    return "-";}else{
                    return result;
                }

            }
            break;
        case MainSizModelHead::personalDate:         //Дата
            if (value.isValid()) {


                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата
                result = Date.toString("dd.MM.yyyy");
                if (value.toString()==""){
                    return "-";}else{
                    return result;
                }

            }
            break;
        case MainSizModelHead::inspectionDate:         //Дата
            if (value.isValid()) {


                QDate  Date =QDate::fromString(value.toString(),"yyyy-MM-dd"); //Дата
                result = Date.toString("dd.MM.yyyy");

                if (value.toString()==""){
                    return "-";}else{
                    return result;
                }
            }
            break;
        default:

            break;
        }

        //

    }
    return value;
}


