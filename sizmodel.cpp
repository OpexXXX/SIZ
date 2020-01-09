#include "sizmodel.h"
#include "maintablemodel.h"


sizModel::sizModel(QObject *parent):QSqlRelationalTableModel (parent)
{
      connect(this, SIGNAL(dataChanged(QModelIndex,QModelIndex)),
             SLOT(dataToEventCalcChange(QModelIndex,QModelIndex)));

}

bool sizModel::setData(const QModelIndex &index,
                       const QVariant &value, int role)
{


    return this->QSqlRelationalTableModel::setData(index,value,role);
}
QVariant sizModel::getColumnValue(const QModelIndex &index, int column){
    QVariant d =  data(sizModel::index(index.row(),column));
    return d;
}
void sizModel::chekRowForEvent(const QModelIndex &index)
{
    QVariant d =  data(sizModel::index(index.row(),2,index.parent()));
    qDebug()<<d;
    d =  data(sizModel::index(index.row(),3,index.parent()));
    qDebug()<<d;
    d =  data(sizModel::index(index.row(),4,index.parent()));
    qDebug()<<d;

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
        setEventDataToRow(SizEvent::noEvent,0,index);
    }
}
void sizModel::setEventDataToRow(int event, int daysToEvent ,const QModelIndex &index){
    setData(sizModel::index(index.row(),MainSizModelHead::event),event,Qt::EditRole);
    setData(sizModel::index(index.row(),MainSizModelHead::daysToEvent),daysToEvent,Qt::EditRole);
}
void sizModel::setTypeSizData(const QModelIndex &index)
{

    int typeSiz = data(sizModel::index(index.row(),5)).toInt();

    setData(sizModel::index(index.row(),MainSizModelHead::bool_verification),typeSiz,Qt::EditRole);
    setData(sizModel::index(index.row(),MainSizModelHead::verifiPediod),typeSiz,Qt::EditRole);
    setData(sizModel::index(index.row(),MainSizModelHead::inspectPediod),typeSiz,Qt::EditRole);
    setData(sizModel::index(index.row(),MainSizModelHead::personalyty),typeSiz,Qt::EditRole);
    dataChanged(sizModel::index(index.row(),MainSizModelHead::bool_verification),sizModel::index(index.row(),MainSizModelHead::personalyty));
}

void sizModel::dataToEventCalcChange(QModelIndex current, QModelIndex prevous)
{
    qDebug()<<"MODEL EVENT";
    if (current==prevous){
        int col = current.column();
        if ((col>=2 &&col<=5)) {
                if (col == 5 )
                {
                    setTypeSizData(current);
                }
                    chekRowForEvent(current);
        }
    }
}
