#ifndef MAINSIZWINDOW_H
#define MAINSIZWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTreeWidgetItem>

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

private slots:
    void on_treeWidget_itemSelectionChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
public:
    Ui::MainSizWindow *ui;
    /* В проекте используются объекты для взаимодействия с информацией в базе данных
         * и моделью представления таблицы базы данных
         * */
        DataBase        *db;
private:
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
