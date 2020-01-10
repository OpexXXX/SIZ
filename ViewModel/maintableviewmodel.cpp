#include "maintableviewmodel.h"

MainTableModel::MainTableModel(QObject *parent):QSortFilterProxyModel (parent)
{

}

MainTableModel::~MainTableModel(){

}
void MainTableModel::setHeaders()
{

     QStringList headerList;
        headerList<< tr("п/п")
                  << tr("Номер")
                  <<tr("Изъято")
                 <<tr("Испытанно")
                <<tr("Испытать")
               <<tr("Наименование")
              <<tr("Осмотренно")
             <<tr("Осмотренно")
            <<tr("Объект")
           << tr("Сотрудник")
           <<tr("Примечание")
          <<tr("Выдан в пользование");
    if(headerList.count()>0&&headerList.count()<=this->columnCount()){

        for(int i = 0; i < headerList.count(); i++){
            this->setHeaderData(i, Qt::Horizontal,headerList[i]);
        }
    }

}
QColor MainTableModel::getColorForRow(int event) const
{
    QColor col = QColor(Qt::white);

    switch (event) {
    case SizEvent::inspectionSoon:
        col=INSPECTION_SOON_COLOR;
        break;
    case SizEvent::verificationSoon:
        col=VERIFICATION_SOON_COLOR;
        break;
    case SizEvent::inspectionExpired:
        col=INSPECTION_EXPIRED_COLOR;
        break;
    case SizEvent::serviceLifeExpired:
        col=SERVICELIFE_EXPIRED_COLOR;
        break;
    case SizEvent::verificationExpired:
        col=VERIFICATION_EXPIRED_COLOR;
        break;
    default:
        col = QColor(Qt::white);
        break;
    }

    return col;
}

QString MainTableModel::getTooltipForRow(QModelIndex index) const

{
    QVariant e =  data(MainTableModel::index(index.row(),MainSizModelHead::event,index.parent()),Qt::DisplayRole);
    QVariant d =  data(MainTableModel::index(index.row(),MainSizModelHead::daysToEvent,index.parent()),Qt::DisplayRole);

    int days = d.toInt();
    if(days<0)days*=(-1);
    QString tooltip = "";

    switch (e.toInt()) {
    case SizEvent::inspectionSoon:
        tooltip="Осмотреть через";
        break;
    case SizEvent::verificationSoon:
        tooltip="Изъять на испытание через";
        break;
    case SizEvent::inspectionExpired:
        tooltip="Просрочен осмотр на ";
        break;
    case SizEvent::serviceLifeExpired:
        tooltip="Срок эксплуатации закончился";
        break;
    case SizEvent::verificationExpired:
        tooltip="Срок испытания закончился";
        break;
    default:
        tooltip = "";
        break;
    }
    int mounth=0;
    if(d>31){
        mounth=days/31;
        days=days%31;
        tooltip+=QString::number(mounth)+"мес. "+ QString::number(days)+" дн.";
    }else{

        tooltip+=" "+QString::number(days)+" дн.";
    }
    return tooltip;
}
QVariant MainTableModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSortFilterProxyModel::data(index, role);
    if (role == Qt::FontRole) {
        QFont font;
        QSqlTableModel *source_model = qobject_cast<QSqlTableModel *>(sourceModel());
        QModelIndex indexSourse = mapToSource(index);
        for (int i =0;i<source_model->columnCount();i++) {
            if(source_model->isDirty(source_model->index(indexSourse.row(),i))&&((i>0)&&(i<11)))
            {
                font.setBold(true);
                break;
            }
        }
        return font;
    }
    if (role == Qt::ToolTipRole) {
        // QModelIndex primaryKeyIndex = QIdentityProxyModel::index(index.row(), 0);
        // int id = data(primaryKeyIndex,0).toInt();
        QString tooltip = getTooltipForRow(index);
        return tooltip;
    }
    if (role == Qt::BackgroundRole) {
        //  QModelIndex primaryKeyIndex = QIdentityProxyModel::index(index.row(), 0);
        //
        //  int id = data(primaryKeyIndex,0).toInt();
        QVariant c =  data(MainTableModel::index(index.row(),MainSizModelHead::event,index.parent()),Qt::DisplayRole);
        QColor color = getColorForRow(c.toInt());
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


