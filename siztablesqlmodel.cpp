#include "siztablesqlmodel.h"

SizVerifiSqlModel::SizVerifiSqlModel(QObject *parent, DataBase *datB):QSqlQueryModel (parent)
{
    this->datB = datB;
}
SizVerifiSqlModel::~SizVerifiSqlModel(){}

QVariant SizVerifiSqlModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
    if (value.isValid() && role == Qt::DisplayRole) {


        if (index.column() == 1){
            bool ispit = false, oldOsmotr = false, badVerification=false;                                                             // ИСПЫТЫВАЕТСЯ??
            int periodOsmotra = 0, periodIspitania =0;                                                          //переодичность осмотра

            QString result ="";

            QVariant  tSiz = this->data( this->index(index.row(), 5),0);                 //Тип СИЗ
            QString typeSiz =tSiz.toString();

            ispit = this->datB->getVerifi(typeSiz);
            periodOsmotra = this->datB->getMounthInspection(typeSiz);
            periodIspitania = this->datB->getVerifiMounth(typeSiz);

            QVariant  dateIsp = this->data( this->index(index.row(), 4),0);                 //Дата истечения испытания
            QDate  endDate =QDate::fromString(dateIsp.toString(),"yyyy-MM-dd");             //Дата истечения испытания

            QVariant  dateOsm = this->data( this->index(index.row(), 7),0);                 //Дата осмотра
            QDate  osmotrDate =QDate::fromString(dateOsm.toString(),"yyyy-MM-dd");          //Дата осмотра

            QDate curr = QDate::currentDate();

            QDate nextOsmotr = osmotrDate.addMonths(periodOsmotra);                               //Дата следующего осмотра
            //Проверяем не просрочен ли осмотр

            long long daysToNextOsmotr = curr.daysTo(nextOsmotr);                           //Дней до следующего осмотра
            long long daysToNextVerification = curr.daysTo(endDate);                        //Дней до испытания

            oldOsmotr = !(daysToNextOsmotr>0);
            badVerification = (daysToNextOsmotr<0);





           result =  QString(QString::number(daysToNextOsmotr) + " следующий осмотр '"+typeSiz+"' №"+value.toString()+"; "+ QString::number(daysToNextVerification) + oldOsmotr+badVerification);



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
    if (role == Qt::FontRole && index.column() == 1)
    {
        QFont font;
        font.setPixelSize(16);
        return font;
    }
    return value;
}
