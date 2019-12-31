#include "mainsizwindow.h"
#include "ui_mainsizwindow.h"
#include "sizmodel.h"
#include <QSqlRecord>
#include "comboboxitemdelegate.h"
#include "checkboxitemdelegate.h"
#include "dateedititemdelegate.h"

#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QStandardItemModel>
MainSizWindow::MainSizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSizWindow)
{

    ui->setupUi(this);
    /* Первым делом необходимо создать объект, который будет использоваться для работы с данными нашей БД
        * и инициализировать подключение к базе данных
        * */

    db = new DataBase();
    db->connectToDataBase();

    /* После чего производим наполнение таблицы базы данных
        * контентом, который будет отображаться в TableView
        * */
    QVariantList data;



    setupModels();
    /* Инициализируем внешний вид таблицы с данными
        * */
    // this->createUI();
}

MainSizWindow::~MainSizWindow()
{
    delete ui;
}
/* Метод для инициализации модеи представления данных
 * */
void MainSizWindow::setupModels()
{
    /* Инициализируем модель для представления данных
     * с заданием названий колонок
     * */



    this->setupModel(SIZTABLE,
                     QStringList() << trUtf8("Дата")
                     << trUtf8("Время")
                     << trUtf8("Рандомное число")
                     << trUtf8("Сообщение")
                     << trUtf8("ццц")
                     << trUtf8("Время")
                     << trUtf8("Рандомное число")
                     << trUtf8("Сообщение")
                     << trUtf8("ццц")
                     << trUtf8("Время")
                     << trUtf8("Рандомное число")
                     << trUtf8("Сообщение")
                     << trUtf8("ццц")
                     );
    sizTableModel = new QSqlTableModel(this);
    sizTypeTableModel= new QSqlTableModel(this);
    ObjectTableModel= new QSqlTableModel(this);
    PersonalTableModel= new QSqlTableModel(this);
    eventDateTableModel= new QSqlTableModel(this);

    sizTableModel->setTable(SIZTABLE);
    sizTableModel->setHeaderData(0, Qt::Horizontal, tr("п/п"));
    sizTableModel->setHeaderData(1, Qt::Horizontal, tr("Номер"));
    sizTableModel->setHeaderData(2, Qt::Horizontal, tr("Изъято"));
    sizTableModel->setHeaderData(3, Qt::Horizontal, tr("Испытанно"));
    sizTableModel->setHeaderData(4, Qt::Horizontal, tr("Испытать"));
    sizTableModel->setHeaderData(5, Qt::Horizontal, tr("Наименование"));
    sizTableModel->setHeaderData(6, Qt::Horizontal, tr("Осмотренно"));
    sizTableModel->setHeaderData(7, Qt::Horizontal, tr("Осмотреть"));
    sizTableModel->setHeaderData(8, Qt::Horizontal, tr("Объект"));
    sizTableModel->setHeaderData(9, Qt::Horizontal, tr("Сотрудник"));

    sizTypeTableModel->setTable(TYPESIZTABLE);
    ObjectTableModel->setTable(OBJECTTABLE);
    PersonalTableModel->setTable(PERSONALTABEL);
    eventDateTableModel->setTable(EVENTTABLE);

    sizTableModel->select();
    sizTypeTableModel->select();
    ObjectTableModel->select();
    PersonalTableModel->select();
    eventDateTableModel->select();

    //Заполняем treeWidget
    QList<QString> listObject = db->getObject();
    QAbstractItemModel* model;
    model =  ui->treeWidget->model();
    QModelIndex id1 = model->index(0,0);
    qDebug()<<listObject<<listObject.length();

    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id1); //добавляем детей
        model->setData(model->index(i,0,id1),listObject[i]); //добавляем детей
    }

    listObject = db->getTypeSiz();
    QModelIndex id2 = model->index(1,0);
    qDebug()<<listObject<<listObject.length();

    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id2); //добавляем детей
        model->setData(model->index(i,0,id2),listObject[i]); //добавляем детей
    }

    listObject = db->getPersonal();
    QModelIndex id3 = model->index(2,0);
    qDebug()<<listObject<<listObject.length();

    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id3); //добавляем детей
        model->setData(model->index(i,0,id3),listObject[i]); //добавляем детей
    }

    db->readSizFromDB();

    this->createUI();



}
void MainSizWindow::setupModel(const QString &tableName, const QStringList &headers)
{
    /* Производим инициализацию модели представления данных
     * с установкой имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
     * */
    sizTableModel = new QSqlTableModel(this);
    sizTableModel->setTable(tableName);
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < sizTableModel->columnCount(); i++, j++){
        sizTableModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    sizTableModel->setSort(0,Qt::AscendingOrder);
}

void MainSizWindow::createUI()
{
    ui->tableView->setModel(sizTableModel);     // Устанавливаем модель на TableView
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();

    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(ui->tableView,db->getTypeSiz());

    ComboBoxItemDelegate* cbido = new ComboBoxItemDelegate(ui->tableView,db->getObject());
     ComboBoxItemDelegate* cbidp = new ComboBoxItemDelegate(ui->tableView,db->getPersonal());
    // ComboBox only in column 2
    CheckBoxItemDelegate* chbib = new CheckBoxItemDelegate (ui->tableView);
    DateEditItemDelegate* deid = new DateEditItemDelegate(ui->tableView);

    ui->tableView->setItemDelegateForColumn(2,chbib);
    ui->tableView->setItemDelegateForColumn(5, cbid);
    ui->tableView->setItemDelegateForColumn(6, chbib);
    ui->tableView->setItemDelegateForColumn(3, deid);
    ui->tableView->setItemDelegateForColumn(4, deid);
    ui->tableView->setItemDelegateForColumn(7, deid);
    ui->tableView->setItemDelegateForColumn(8, cbido);
    ui->tableView->setItemDelegateForColumn(9, cbidp);

    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(6);


    sizTableModel->select(); // Делаем выборку данных из таблицы
}

void MainSizWindow::on_treeWidget_itemSelectionChanged()
{

}

void MainSizWindow::on_pushButton_clicked()
{
    sizTableModel->insertRow(0);
}

void MainSizWindow::on_pushButton_2_clicked()
{

    QModelIndexList indexes = ui->tableView->selectionModel()->selection().indexes();
    qDebug()<<indexes.count();
    if(indexes.count()>0)
    {
        for (int i = 0; i<indexes.count();i++) {

            qDebug()<<indexes.at(i).data();

        }

        int ret = QMessageBox::warning(this, tr("Удаление записи"),"Удаление: \n"+
                                       indexes.at(5).data().toString() +
                                       "\n №"+indexes.at(1).data().toString()+
                                       "\n"+indexes.at(8).data().toString(),
                                       QMessageBox::Yes
                                       | QMessageBox::Cancel
                                       );

        if(ret==QMessageBox::Yes)
        {
            sizTableModel->removeRows(indexes.at(1).row(),1);
        }

    }
}




void MainSizWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{

    qDebug()<<item->data(0,0).toString();

    if(item->parent()!=nullptr) {
        QString parrent = item->parent()->data(0,0).toString();
        qDebug()<<parrent;
        if(parrent == "Объекты")
        {
            sizTableModel->setFilter(QString( " object ='"+item->data(0,0).toString()+"'")
                                     );
            sizTableModel->select();
        }
        if(parrent == "Персонал")
        {
            sizTableModel->setFilter(QString( " personal ='"+item->data(0,0).toString()+"'")
                                     );
            sizTableModel->select();
        }
        if(parrent == "Типы СИЗ")
        {
            sizTableModel->setFilter(QString( " typeSiz ='"+item->data(0,0).toString()+"'")
                                     );
            sizTableModel->select();
        }


    }
    else {
        sizTableModel->setFilter("");
        sizTableModel->select();
    }





}
