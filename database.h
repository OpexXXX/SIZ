#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlRelation>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "siz.db"

#define TABLE                   "TableExample"
#define TABLE_DATE              "Date"
#define TABLE_TIME              "Time"
#define TABLE_MESSAGE           "Message"
#define TABLE_RANDOM            "Random"



#define SIZTABLE                        "Siz"
#define SIZTABLE_INDEX                  "index"
#define SIZTABLE_NUMBER                 "number"
#define SIZTABLE_VERIFICATION           "verification"
#define SIZTABLE_ENDVERIFICATION        "endVerification"
#define SIZTABLE_INSPECTION             "inspectionDate"
#define SIZTABLE_T_NAMETYPESIZ          "typeSiz"
#define SIZTABLE_OBJECT                 "object"
#define SIZTABLE_PERSONALDATE           "personalDate"
#define SIZTABLE_PERSONA                "personal"
#define SIZTABLE_NOTE                   "note"
#define SIZTABLE_REMOVED                "removed"
#define SIZTABLE_T_VER                  "tVerification"
#define SIZTABLE_T_VERPERIOD            "tPeriodicityVer"
#define SIZTABLE_T_INSPEDIOD            "tPeriodicityInsp"
#define SIZTABLE_T_PERSONALYTY          "tPersonaly"

#define TYPESIZTABLE                    "TypeSiz"
#define TYPESIZTABLE_ID                    "id"
#define TYPESIZTABLE_NAME               "oneName"
#define TYPESIZTABLE_VER                "verification"
#define TYPESIZTABLE_VERPERIOD          "periodicityVer"
#define TYPESIZTABLE_INSPEDIOD          "periodicityInsp"
#define TYPESIZTABLE_PERSONALYTY        "personaly"

/*CREATE TABLE "TypeSiz" (
    "id"	INTEGER,
    "oneName"	TEXT,
    "verification"	BOOL,
    "periodicityVer"	INTEGER,
    "periodicityInsp"	INTEGER,
    "personaly"	BOOL,
    PRIMARY KEY("id")*/
#define OBJECTTABLE             "Object"
#define OBJECTTABLE_ID             "id"
#define OBJECTTABLE_NAME             "name"

#define PERSONALTABEL           "Personal"
#define PERSONALTABEL_ID           "id"
#define PERSONALTABEL_NAME           "name"


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

    QList<QString> getObject();
    QList<QString> getTypeSiz();
    QList<QString>  getPersonal();

    int getMounthInspection(QString name);
    int getVerifi(QString name);
    int getVerifiMounth(QString name);

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
