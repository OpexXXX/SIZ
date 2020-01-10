#include "sizmodel.h"
#include "ViewModel/maintableviewmodel.h"


sizModel::sizModel(QObject *parent):QSqlRelationalTableModel (parent)
{
      connect(this, &sizModel::dataChanged,this,
             &sizModel::dataToEventCalcChange);

}


QVariant sizModel::getColumnValue(QModelIndex index, int column){
    QVariant d =  data(sizModel::index(index.row(),column,index.parent()));
    return d;
}
void sizModel::chekRowForEvent(QModelIndex index)
{

    bool ispitivaemiy = false,
            oldOsmotrEvent = false,
            badVerificationEvent=false;                                                             // ИСПЫТЫВАЕТСЯ??
    int periodOsmotra = 0,
            periodIspitania =0;                                                          //переодичность осмотра

    ispitivaemiy = getColumnValue(index,MainSizModelHead::bool_verification).toBool();
    periodOsmotra =  getColumnValue(index,MainSizModelHead::inspectPediod).toInt();
    periodIspitania = getColumnValue(index,MainSizModelHead::verifiPediod).toInt();

    QString  dateVer = getColumnValue(index,MainSizModelHead::endVerificationDate).toString();    //Дата истечения испытания
    QDate  endVerifiDate =QDate::fromString(dateVer,"yyyy-MM-dd");

    QString  dateOsm = getColumnValue(index,MainSizModelHead::inspectionDate).toString();    //Дата осмотра
    QDate  osmotrDate =QDate::fromString(dateOsm,"yyyy-MM-dd");

    QDate curr = QDate::currentDate();
    QDate nextOsmotr = osmotrDate.addMonths(periodOsmotra);                               //Дата следующего осмотра

    //Проверяем не просрочен ли осмотр
    long long daysToNextOsmotr = curr.daysTo(nextOsmotr);                           //Дней до следующего осмотра
    long long daysToNextVerification = curr.daysTo(endVerifiDate);                        //Дней до испытания

    oldOsmotrEvent = !(daysToNextOsmotr>0);            //Не просрочен ли осмотр?
    badVerificationEvent = (daysToNextVerification<0);  //Не просроченно ли испытание?

    if (badVerificationEvent) {
        //   result+=QString("ИЗЪЯТЬ \""+typeSiz+"\" №"+number+" просрочен на "+QString::number(daysToNextVerification*-1)+ " дней");
        setEventDataToRow(SizEvent::verificationExpired,daysToNextVerification,index);
return;
    }else if ((!badVerificationEvent) && oldOsmotrEvent ) {
        //  result+=QString("ОСМОТРЕТЬ \""+typeSiz+"\" №"+number+" просрочен на "+QString::number(daysToNextOsmotr*-1)+ " дней");
        setEventDataToRow(SizEvent::inspectionExpired,daysToNextOsmotr,index);
return;
    }else if ((daysToNextOsmotr<_daysToEvent)&&(daysToNextVerification> daysToNextOsmotr)&&ispitivaemiy) {
        setEventDataToRow(SizEvent::inspectionSoon,daysToNextOsmotr,index);
return;
    }else if ((daysToNextOsmotr<_daysToEvent)&&daysToNextVerification< daysToNextOsmotr&&ispitivaemiy) {
        //  result+=QString(QString::number(daysToNextVerification)+" дней до изъятия \""+typeSiz+"\" №"+number);
        setEventDataToRow(SizEvent::verificationSoon,daysToNextVerification,index);
return;
    }else if ((daysToNextOsmotr<_daysToEvent)&&(!ispitivaemiy)) {
        // result+=QString(QString::number(daysToNextOsmotr)+" дней до осмотра \""+typeSiz+"\" №"+number);
        setEventDataToRow(SizEvent::inspectionSoon,daysToNextOsmotr,index);
    } else{
        int vall = 0;

        if(ispitivaemiy) {vall = daysToNextOsmotr<daysToNextVerification?daysToNextOsmotr:daysToNextVerification;}
        else {
            vall = daysToNextOsmotr;
        }

        setEventDataToRow(SizEvent::noEvent,vall,index);

    }
}
void sizModel::setEventDataToRow(int event, int daysToEvent , QModelIndex index){
  QSqlTableModel::setData(sizModel::index(index.row(),MainSizModelHead::event,index.parent()),event,Qt::EditRole);
  QSqlTableModel::setData(sizModel::index(index.row(),MainSizModelHead::daysToEvent,index.parent()),daysToEvent,Qt::EditRole);
}
void sizModel::setTypeSizData(const QModelIndex &index)
{

    QVariant typeSiz =  QSqlTableModel ::data(sizModel::index(index.row(),5));

   QSqlTableModel::setData(sizModel::index(index.row(),MainSizModelHead::bool_verification),typeSiz,Qt::EditRole);
     QSqlTableModel::setData(sizModel::index(index.row(),MainSizModelHead::verifiPediod),typeSiz,Qt::EditRole);
     QSqlTableModel::setData(sizModel::index(index.row(),MainSizModelHead::inspectPediod),typeSiz,Qt::EditRole);
     QSqlTableModel::setData(sizModel::index(index.row(),MainSizModelHead::personalyty),typeSiz,Qt::EditRole);
    //dataChanged(sizModel::index(index.row(),MainSizModelHead::bool_verification),sizModel::index(index.row(),MainSizModelHead::personalyty));
}
void sizModel::updateAllEvents()
{
     //model->setEditStrategy(QSqlTableModel::OnRowChange);
  // EditStrategy strategy  =  this->editStrategy();
   this->setEditStrategy(EditStrategy::OnManualSubmit);
   //wbrn
   int count = this->rowCount();
   for (int i =0;i<count;i++) {
       chekRowForEvent(sizModel::index(i,0));
   }
 // qDebug()<< this->submitAll();


}

void sizModel::dataToEventCalcChange(QModelIndex current, QModelIndex prevous)
{

    if (current==prevous){
        int col = current.column();
        if ((col>=2 &&col<=5)) {
            qDebug()<<"MODEL EVENT "<<current;
                if (col == 5 )
                {
                    setTypeSizData(current);
                }
                    chekRowForEvent(current);
        }
    }
}

void sizModel::setDaysToEvents(int days){
    if(_daysToEvent!=days)
    {
        _daysToEvent=days;
        updateAllEvents();
    }
    _daysToEvent=days;
}
