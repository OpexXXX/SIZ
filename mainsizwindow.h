#ifndef MAINSIZWINDOW_H
#define MAINSIZWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTreeWidgetItem>
#include "siztablesqlmodel.h"
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
    void on_treeWidget_itemChanged(QTreeWidgetItem *item, int column);

    void on_treeWidget_itemActivated(QTreeWidgetItem *item, int column);

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

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
        SizVerifiSqlModel  *eventDateTableModel;
private:
    /* Также присутствуют два метода, которые формируют модель
     * и внешний вид TableView
     * */
    void setupModel(const QString &tableName, const QStringList &headers);
    void setupModels();
    void createUI();

};

#endif // MAINSIZWINDOW_H
