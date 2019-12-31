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
    inline  static QList<sizmodel*> allSiz; //Список всех СИЗ3


    QString number;     //Номер СИЗ
    uint typeSiz;           //Тип СИЗ
    bool veri;
    bool removed;           //Изъято
    QDate verification;     //Дата испытания
    QDate endVerification;  //Дата следующего испытания
    QVariantList eventDate; //Список осмотров
    uint indexOfTable;
    sizmodel(); //Конструктор

    inline static void refreshSiz(); //Обновить СИЗ из БД

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
