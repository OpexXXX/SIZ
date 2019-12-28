#ifndef MAINSIZWINDOW_H
#define MAINSIZWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
/* Подключаем заголовочный файл для работы с информацией, которая помещена в базу данных */
#include "database.h"

namespace Ui {
class MainSizWindow;
}

class MainSizWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSizWindow(QWidget *parent = nullptr);
    ~MainSizWindow();

private:
    Ui::MainSizWindow *ui;
    /* В проекте используются объекты для взаимодействия с информацией в базе данных
         * и моделью представления таблицы базы данных
         * */
        DataBase        *db;
        QSqlTableModel  *sizTableModel;
        QSqlTableModel  *sizTypeTableModel;
        QSqlTableModel  *ObjectTableModel;
        QSqlTableModel  *PersonalTableModel;
        QSqlTableModel  *eventDateTableModel;
private:
    /* Также присутствуют два метода, которые формируют модель
     * и внешний вид TableView
     * */
    void setupModel(const QString &tableName, const QStringList &headers);
    void setupModels();
    void createUI();

};

#endif // MAINSIZWINDOW_H
