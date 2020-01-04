#ifndef MAINSIZWINDOW_H
#define MAINSIZWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTreeWidgetItem>
#include <QSystemTrayIcon>
#include <QTimer>
#include "siztablesqlmodel.h"
#include <QListWidgetItem>
#include "maintablemodel.h"
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
protected:
    /* Виртуальная функция родительского класса в нашем классе
     * переопределяется для изменения поведения приложения,
     *  чтобы оно сворачивалось в трей, когда мы этого хотим
     */
    void closeEvent(QCloseEvent * event);

private slots:
    /* Слот, который будет принимать сигнал от события
       * нажатия на иконку приложения в трее
       */

    void updateTime();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
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

    void on_tableView_viewportEntered();

    void on_tableView_entered(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_pressed(const QModelIndex &index);

    void on_pushButton_9_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

public:
    Ui::MainSizWindow *ui;
    /* В проекте используются объекты для взаимодействия с информацией в базе данных
         * и моделью представления таблицы базы данных
         * */
        DataBase        *db;
        QList<QPair<int,QPair<int,QString> > >  eventArray;
private:
        MainTableModel *sizTableModel;
        QSqlTableModel  *sizTypeTableModel;
        QSqlTableModel  *ObjectTableModel;
        QSqlTableModel  *PersonalTableModel;
        SizVerifiSqlModel  *eventDateTableModel;
        /* Объявляем объект будущей иконки приложения для трея */
           QSystemTrayIcon         * trayIcon;

           QTimer *tmr;
private:
    /* Также присутствуют два метода, которые формируют модель
     * и внешний вид TableView
     * */
    void Style();
    void reloadEvents();
    void setupModel(const QString &tableName, const QStringList &headers);
    void setupModels();
    void createUI();

};

#endif // MAINSIZWINDOW_H
