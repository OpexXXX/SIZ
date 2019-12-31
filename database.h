#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>
#include "sizmodel.h"
/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "siz.db"

#define TABLE                   "TableExample"
#define TABLE_DATE              "Date"
#define TABLE_TIME              "Time"
#define TABLE_MESSAGE           "Message"
#define TABLE_RANDOM            "Random"

#define SIZTABLE                "Siz"
#define TYPESIZTABLE            "TypeSiz"
#define OBJECTTABLE             "Object"
#define PERSONALTABEL           "Personal"
#define EVENTTABLE              "eventDate"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
    /* Методы для непосредственной работы с классом
     * Подключение к базе данных и вставка записей в таблицу
     * */
    void connectToDataBase();
    bool inserIntoTable(const QVariantList &data);
    QList<QString> getObject();
     QList<QString> getTypeSiz();
     QList<QString>  getPersonal();
bool readSizFromDB();
private:
    // Сам объект базы данных, с которым будет производиться работа
    QSqlDatabase    db;
    /* Внутренние методы для работы с базой данных
     * */
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();



};

#endif // DATABASE_H
