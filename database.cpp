#include "database.h"


#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QSqlRecord>
#include <QTextCodec>
#include <QTextStream>


DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile(DATABASE_NAME).exists()){
        qDebug() << "Не удалось найти фаил базы данных";
        this->restoreDataBase();
    } else {
        qDebug() << "Удалось найти фаил базы данных, открываем";
        this->openDataBase();
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable()){
            return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы в базе данных
 * */
bool DataBase::createTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    TABLE_DATE      " DATE            NOT NULL,"
                    TABLE_TIME      " TIME            NOT NULL,"
                    TABLE_RANDOM    " INTEGER         NOT NULL,"
                    TABLE_MESSAGE   " VARCHAR(255)    NOT NULL"
                    " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

/* Метод для вставки записи в базу данных
 * */

QList<QString>  DataBase::getObject()
{
    QSqlQuery q("select * from Object");
    QList<QString> list;

    QSqlRecord rec = q.record();

    while (q.next()){


        list.append(q.value(rec.indexOf("name")).toString());
    }
    return list;
}
QList<QString>  DataBase::getTypeSiz()
{
    QSqlQuery q("select * from TypeSiz");
    QList<QString> list;

    QSqlRecord rec = q.record();

    while (q.next()){
        list.append(q.value(rec.indexOf("oneName")).toString());
    }
    return list;
}
QList<QString>  DataBase::getPersonal()
{
    QSqlQuery q("select * from Personal");
    QList<QString> list;

    QSqlRecord rec = q.record();

    while (q.next()){
        list.append(q.value(rec.indexOf("name")).toString());
    }
    return list;
}

int DataBase::getMounthInspection(QString name)
{
    QSqlQuery q("select periodicityInsp from TypeSiz WHERE oneName='"+name+"'");
    int result = -1;

    if(q.record().count()>0){
        QSqlRecord rec = q.record();
        while (q.next()){
            result = q.value(rec.indexOf("periodicityInsp")).toInt();
        }
        return result;
    }else {
        return result;
    }
}
int DataBase::getVerifi(QString name)
{
    QSqlQuery q("select verification from TypeSiz WHERE oneName='"+name+"'");
    int result = -1;

    if(q.record().count()>0){
        QSqlRecord rec = q.record();
        while (q.next()){
            result = q.value(rec.indexOf("verification")).toInt();
        }
        return result;
    }else {
        return result;
    }
}
int DataBase::getVerifiMounth(QString name)
{
    QSqlQuery q("select periodicityVer from TypeSiz WHERE oneName='"+name+"'");
    int result = -1;

    if(q.record().count()>0){
        QSqlRecord rec = q.record();
        while (q.next()){
            result = q.value(rec.indexOf("periodicityVer")).toInt();
        }
        return result;
    }else {
        return result;
    }
}


bool  DataBase::readSizFromDB()
{
    QSqlQuery q("select * from Siz");
    QSqlRecord rec = q.record();
    int nameCol = rec.indexOf("number"); // index of the field "name"
    return true;
}
void DataBase::expotrToCSV(QFile * file)
{
    QSqlQuery q("SELECT number, Siz.verification, endVerification, inspectionDate, TypeSiz.oneName, Object.name, personalDate, Personal.name, note, daysToEvent, TypeSiz.periodicityVer "
                "FROM Siz "
                "INNER JOIN  TypeSiz ON Siz.typeSiz = TypeSiz.id "
                "INNER JOIN  Object ON Siz.object = Object.id "
                "INNER JOIN  Personal ON Siz.personal = Personal.id ");
    QSqlRecord rec = q.record();
    QTextStream out(file);
    //out.setCodec("UTF-8");
    out.setCodec("CP1251");

    const int COLUMN_COUNT = 11;
    QStringList headers;

    headers <<"Номер"
           <<  "Дата испытания"
            << "Дата следующего испытания"
            <<"Дата осмотра"
           << "Тип СИЗ"
           <<"Объект"
          << "Выдан в пользование"
          << "Работник"
          << "Заметка"
          << "Дней до "
           << "Срок испытания";
    foreach (auto head, headers) out << head << ";";
    out << "\n";

    while (q.next()){
        QDate  nextInspDate =QDate::fromString(q.value(2).toString(),"yyyy-MM-dd"); //Дата следующего испытания
        QDate inspDate = nextInspDate.addMonths(q.value(11).toInt());

        for (int i=0;i<COLUMN_COUNT;i++)
        {
            if (i == 1) out <<  inspDate.toString("yyyy-MM-dd") << ";";
            else  out << q.value(i).toString() << ";";
        }
        out<< "\n";
    }
}
