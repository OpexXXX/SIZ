#ifndef MAINSIZWINDOW_H
#define MAINSIZWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTreeWidgetItem>
#include <QSystemTrayIcon>
#include <QTimer>
#include <QListWidgetItem>
#include <QSqlRecord>
#include <QMenu>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QStandardItemModel>
#include <QSqlRelationalTableModel>
#include <QIcon>
#include <QCloseEvent>
#include <QHideEvent>
#include "database.h"
#include "maintablemodel.h"
#include "ui_mainsizwindow.h"
#include "comboboxitemdelegate.h"
#include "checkboxitemdelegate.h"
#include "dateedititemdelegate.h"
#include "eventmodel.h"
#include <QSortFilterProxyModel>

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
    void hideEvent(QHideEvent *event);
private slots:
    /* Слот, который будет принимать сигнал от события
       * нажатия на иконку приложения в трее
       */
    void updateTime();
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void on_tabWidget_currentChanged(int index);
    void on_mainTableViewTriggerSelectionModel_currentRowChanged(QModelIndex current, QModelIndex prevous);
    void on_mainTableView_Data_Changed(QModelIndex current, QModelIndex prevous);
    void on_pushButton_9_clicked();
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_radioButton_group_toggle(int button,bool checked);
    void on_radioButton_3_toggled(bool checked);
    void on_selectedItemOsmotrButton_clicked();
    void on_pushButton_5_toggled(bool checked);
    void on_addRowMainTable_clicked();
    void on_deleteRowMainTable_clicked();
    void on_addRowPerechniTable_clicked();
    void on_deleteRowPerechniTable_clicked();
    void on_daysOfEvent_valueChanged(int arg1);
    void on_pushButton_clicked();

public:
    Ui::MainSizWindow *ui;
    /* В проекте используются объекты для взаимодействия с информацией в базе данных
         * и моделью представления таблицы базы данных
         * */
    DataBase        *db;
    QList<QPair<int,QPair<int,QString> > >  eventArray;
private:
    QSortFilterProxyModel *sizFilterProxyModel;
    MainTableModel *sizProxyTableModel;
    QSqlRelationalTableModel *mainSizModel;



    QSqlTableModel  *sizTypeTableModel;
    QSqlTableModel  *ObjectTableModel;
    QSqlTableModel  *PersonalTableModel;
    EventList  *eventDateTableModel;
/*oneName"	TEXT,
    "verification"	BOOL,
    "periodicityVer"	INTEGER,
    "periodicityInsp"	INTEGER,
    "personaly"	BOOL,*/
    /* Объявляем объект будущей иконки приложения для трея */
    QSystemTrayIcon         * trayIcon;
    QTimer *tmr;
private:
    /* Также присутствуют два метода, которые формируют модель
     * и внешний вид TableView
     * */
    void reloadTreeWidgetItems();
    void addItemsTreeWidget(QList<QString> listChild, QString nameTop);
    void reloadDelegateMainTabView();
    void setModelOnTableView(QSqlTableModel* model);
    void Style();
    void reloadEvents();
    void setupModel(const QString &tableName,  QSqlTableModel *model,const QStringList &headers);
    void setupModels();
    void createUI();
};

#endif // MAINSIZWINDOW_H
