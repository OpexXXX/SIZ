#include "database.h"
#include "sizmodel.h"

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include <QSqlRecord>

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
bool DataBase::inserIntoTable(const QVariantList &data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT INTO " TABLE " ( " TABLE_DATE ", "
                                             TABLE_TIME ", "
                                             TABLE_RANDOM ", "
                                             TABLE_MESSAGE " ) "
                  "VALUES (:Date, :Time, :Random, :Message )");
    query.bindValue(":Date",        data[0].toDate().toString("dd.MM.yyyy"));
    query.bindValue(":Time",        data[1].toTime().toString("hh:mm"));
    query.bindValue(":Random",      data[2].toInt());
    query.bindValue(":Message",     data[3].toString());


    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}
QList<QString>  DataBase::getObject()
{
    QSqlQuery q("select * from Object");
    QList<QString> list = *new QList<QString> ();

    QSqlRecord rec = q.record();
    qDebug() << "Читаем данные из Object ";
    while (q.next()){


        list.append(q.value(rec.indexOf("name")).toString());
                  }
    return list;
}
QList<QString>  DataBase::getTypeSiz()
{
    QSqlQuery q("select * from TypeSiz");
    QList<QString> list = *new QList<QString> ();

    QSqlRecord rec = q.record();
    qDebug() << "Читаем данные из TypeSiz ";
    while (q.next()){
        list.append(q.value(rec.indexOf("oneName")).toString());
                  }
    return list;
}
QList<QString>  DataBase::getPersonal()
{
    QSqlQuery q("select * from Personal");
    QList<QString> list = *new QList<QString> ();

    QSqlRecord rec = q.record();
    qDebug() << "Читаем данные из Personal";
    while (q.next()){
        list.append(q.value(rec.indexOf("name")).toString());
                  }
    return list;
}
bool  DataBase::readSizFromDB()
{
    QSqlQuery q("select * from Siz");
    QSqlRecord rec = q.record();
    qDebug() << "Читаем данные из SizTable";
    int nameCol = rec.indexOf("number"); // index of the field "name"


    while (q.next()){

        sizmodel* siz = new sizmodel();
        siz->number =           q.value(rec.indexOf("number")).toString();
        siz->typeSiz=           q.value(rec.indexOf("typeSiz")).toUInt();         //Тип СИЗ
        siz->removed=           q.value(rec.indexOf("removed")).toBool();          //Изъято
        siz->verification=      q.value(rec.indexOf("verification")).toDate();    //Дата испытания
        siz->endVerification=   q.value(rec.indexOf("endVerification")).toDate();  //Дата следующего испытания

        sizmodel::allSiz.append(siz);
    }
    return true;
}
