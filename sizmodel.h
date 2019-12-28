#ifndef SIZMODEL_H
#define SIZMODEL_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>


class sizmodel
{

public:
    std::string number;     //Номер СИЗ
    uint typeSiz;           //Тип СИЗ
    bool veri;
    bool removed;           //Изъято
    QDate verification;     //Дата испытания
    QDate endVerification;  //Дата следующего испытания

    sizmodel();
    //Функции возвращающие значения
    QString getTypeNames();  //Имя во множественном лице
    QString getTypeName();  //Имя
    QString getTypeNameAbr();   //Сокращенное имя

    bool getVerification();     //Поверяется
    bool getPersonaly();        //Выдается персоняльно сотруднику

    uint getPeriodicityVer();   //Срок поверки в мес.
    uint getperiodicityInsp();  //периодичность осмотра в мес.

    QString getObjectName();    //Имя объекта на котором хранится СИЗ
    QString getPersonalName();  //Имя работника которому выдан СИЗ

};

#endif // SIZMODEL_H
