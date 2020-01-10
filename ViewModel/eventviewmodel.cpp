#include "eventviewmodel.h"

EventViewModel::EventViewModel(QObject *parent):QSortFilterProxyModel (parent)
{

}
QStringList EventViewModel::getRow(const QModelIndex &index)
{

  QString  number,
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
        daysToEvent;

  number =              data(EventViewModel::index(index.row(),MainSizModelHead::number,index.parent()),Qt::DisplayRole).toString();
  verificationDate=     data(EventViewModel::index(index.row(),MainSizModelHead::verificationDate,index.parent()),Qt::DisplayRole).toString();
  endVerificationDate=  data(EventViewModel::index(index.row(),MainSizModelHead::endVerificationDate,index.parent()),Qt::DisplayRole).toString();
  inspectionDate=       data(EventViewModel::index(index.row(),MainSizModelHead::inspectionDate,index.parent()),Qt::DisplayRole).toString();
  nameSiz=              data(EventViewModel::index(index.row(),MainSizModelHead::nameSiz,index.parent()),Qt::DisplayRole).toString();
  object=               data(EventViewModel::index(index.row(),MainSizModelHead::object,index.parent()),Qt::DisplayRole).toString();
  personalDate=         data(EventViewModel::index(index.row(),MainSizModelHead::personalDate,index.parent()),Qt::DisplayRole).toString();
  persona=              data(EventViewModel::index(index.row(),MainSizModelHead::persona,index.parent()),Qt::DisplayRole).toString();
  note=                 data(EventViewModel::index(index.row(),MainSizModelHead::note,index.parent()),Qt::DisplayRole).toString();
  bool_verification=    data(EventViewModel::index(index.row(),MainSizModelHead::bool_verification,index.parent()),Qt::DisplayRole).toString();
  verifiPediod=         data(EventViewModel::index(index.row(),MainSizModelHead::verifiPediod,index.parent()),Qt::DisplayRole).toString();
  inspectPediod=        data(EventViewModel::index(index.row(),MainSizModelHead::inspectPediod,index.parent()),Qt::DisplayRole).toString();
  personalyty=          data(EventViewModel::index(index.row(),MainSizModelHead::personalyty,index.parent()),Qt::DisplayRole).toString();
  event=                data(EventViewModel::index(index.row(),MainSizModelHead::event,index.parent()),Qt::DisplayRole).toString();
  daysToEvent=          data(EventViewModel::index(index.row(),MainSizModelHead::daysToEvent,index.parent()),Qt::DisplayRole).toString();

}

QString EventViewModel::getMessage(const QModelIndex &index) const
{

//    tooltip="Осмотреть через";
//    tooltip="Изъять на испытание через";
//    tooltip="Просрочен осмотр на ";
//    tooltip="Срок эксплуатации закончился";
//    tooltip="Срок испытания закончился";

  int event= data(EventViewModel::index(index.row(),MainSizModelHead::event,index.parent()),Qt::DisplayRole).toInt();
  QString nameSiz=  data(EventViewModel::index(index.row(),MainSizModelHead::nameSiz,index.parent()),Qt::DisplayRole).toString();
  QString number =  data(EventViewModel::index(index.row(),MainSizModelHead::number,index.parent()),Qt::DisplayRole).toString();
  QString object=   data(EventViewModel::index(index.row(),MainSizModelHead::object,index.parent()),Qt::DisplayRole).toString();
  QString daysToEvent= data(EventViewModel::index(index.row(),MainSizModelHead::daysToEvent,index.parent()),Qt::DisplayRole).toString();
  QString message;

  switch (event) {
  case SizEvent::inspectionSoon:
      message="осмотреть через";
      break;
  case SizEvent::verificationSoon:
      message="изъять на испытание через";
      break;
  case SizEvent::inspectionExpired:
      message="просрочен осмотр на ";
      break;
  case SizEvent::serviceLifeExpired:
      message="срок эксплуатации закончился";
      break;
  case SizEvent::verificationExpired:
      message="срок испытания закончился";
      break;
  default:
      message = "";
      break;
  }

  QString duration="";
  int days=daysToEvent.toInt();
  if (days<0) days*=(-1);
  int mounth=0;
  if(days>31){
      mounth=days/31;
      days=days%31;
      duration=QString::number(mounth)+"мес. "+ QString::number(days)+" дн.";
  }else{
      duration+=" "+QString::number(days)+" дн.";
  }
  QString result = QString("%1 №%2 %3 %4 %5").arg(nameSiz, number,object,message, duration );
  return result;

}

QColor EventViewModel::getColorForRow(int event) const
{
    QColor col = QColor(Qt::white);

    switch (event) {
    case SizEvent::inspectionSoon:
       // col=INSPECTION_SOON_COLOR;
        break;
    case SizEvent::verificationSoon:
       // col=VERIFICATION_SOON_COLOR;
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

QVariant EventViewModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::BackgroundRole) {
        int event= data(EventViewModel::index(index.row(),MainSizModelHead::event,index.parent()),Qt::DisplayRole).toInt();
        QColor color = getColorForRow(event);
        return QBrush(color);
    }

    QVariant value = QSortFilterProxyModel::data(index, role);
    //    if (role == Qt::FontRole) {
    //        QFont font;
    //        QSqlTableModel *source_model = qobject_cast<QSqlTableModel *>(sourceModel());
    //        QModelIndex indexSourse = mapToSource(index);
    //        for (int i =0;i<source_model->columnCount();i++) {
    //            if(source_model->isDirty(source_model->index(indexSourse.row(),i))&&((i>0)&&(i<11)))
    //            {
    //                font.setBold(true);
    //                break;
    //            }
    //        }
    //        return font;
    //    }

    //    if (role == Qt::BackgroundRole) {
    //        //  QModelIndex primaryKeyIndex = QIdentityProxyModel::index(index.row(), 0);
    //        //
    //        //  int id = data(primaryKeyIndex,0).toInt();
    //        QVariant c =  data(MainTableModel::index(index.row(),MainSizModelHead::event,index.parent()),Qt::DisplayRole);
    //        QColor color = getColorForRow(c.toInt());
    //        return QBrush(color);
    //    }
    QString result ="";
    if (role == Qt::DisplayRole&& index.column()==10){
        if (value.isValid()) {


            return getMessage(index);
            //
        }
    }
    return value;
}
bool EventViewModel :: filterAcceptsRow ( int sourceRow , const QModelIndex & sourceParent ) const
{
    QModelIndex event = sourceModel()->index(sourceRow, 15, sourceParent);
    int e = sourceModel()->data(event).toInt();
    return e!=0;
}

