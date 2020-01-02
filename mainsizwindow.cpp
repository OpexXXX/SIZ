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
                     QStringList() << "Дата"
                     << "Время"
                     <<"Рандомное число"
                     << "Сообщение"
                     << "ццц"
                     << "Время"
                     << "Рандомное число"
                     << "Сообщение"
                     << "ццц"
                     << "Время"
                     << "Рандомное число"
                     << "Сообщение"
                     << "ццц"
                     );
    sizTableModel = new QSqlTableModel(this);
    sizTypeTableModel= new QSqlTableModel(this);
    ObjectTableModel= new QSqlTableModel(this);
    PersonalTableModel= new QSqlTableModel(this);
    eventDateTableModel= new SizVerifiSqlModel(this);

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
    sizTypeTableModel->setHeaderData(0, Qt::Horizontal, tr("Наименование"));
    sizTypeTableModel->setHeaderData(1, Qt::Horizontal, tr("Испытывается"));
    sizTypeTableModel->setHeaderData(2, Qt::Horizontal, tr("Переодичность испытаний мес."));
    sizTypeTableModel->setHeaderData(3, Qt::Horizontal, tr("Переодичность осмотров мес."));
    sizTypeTableModel->setHeaderData(4, Qt::Horizontal, tr("Персональный"));




    ObjectTableModel->setTable(OBJECTTABLE);
    PersonalTableModel->setTable(PERSONALTABEL);
    QDate stopDate = QDate::currentDate(); // возвращаем текущую дату
    QDate startDate = stopDate.addDays(10); // возвращаем текущую дату


   // eventDateTableModel->setQuery("SELECT * FROM Siz WHERE endVerification BETWEEN '2014-01-02' AND '"+stopDate.toString("yyyy-MM-dd")+"'");
       int addDay = ui->spinBox->value();
      QString filterDate = QDate::currentDate().addDays(addDay).toString("yyyy-MM-dd");
      eventDateTableModel->setQuery(QString( "SELECT * FROM Siz WHERE endVerification BETWEEN '2014-01-01' AND '"+filterDate+"'"));
    sizTableModel->select();
    sizTypeTableModel->select();
    ObjectTableModel->select();
    PersonalTableModel->select();


    //Заполняем treeWidget
    QList<QString> listObject = db->getObject();
    QAbstractItemModel* model;
    model =  ui->treeWidget->model();
    QModelIndex id1 = model->index(0,0);


    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id1); //добавляем детей
        model->setData(model->index(i,0,id1),listObject[i]); //добавляем детей
    }

    listObject = db->getTypeSiz();
    QModelIndex id2 = model->index(1,0);


    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id2); //добавляем детей
        model->setData(model->index(i,0,id2),listObject[i]); //добавляем детей
    }

    listObject = db->getPersonal();
    QModelIndex id3 = model->index(2,0);


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
    //Персонал
    ui->personalTableView->setModel(PersonalTableModel);
    ui->personalTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->personalTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->personalTableView->resizeColumnsToContents();
    ui->personalTableView->horizontalHeader()->setStretchLastSection(true);

    //Объекты
    ui->objectTableView->setModel(ObjectTableModel);
    ui->objectTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->objectTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->objectTableView->resizeColumnsToContents();
    ui->objectTableView->horizontalHeader()->setStretchLastSection(true);
    //Типы СИЗ
    ui->typeSizTableView->setModel(sizTypeTableModel);
    ui->typeSizTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->typeSizTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->typeSizTableView->resizeColumnsToContents();
    ui->typeSizTableView->horizontalHeader()->setStretchLastSection(true);
    //СИЗ
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

    ui->listView->setModel(eventDateTableModel);
   ui->listView->setModelColumn(1);


   int addDay = ui->spinBox->value();

   QString filterDate = QDate::currentDate().addDays(addDay).toString("yyyy-MM-dd");
   eventDateTableModel->setQuery(QString( "SELECT * FROM Siz WHERE endVerification BETWEEN '2014-01-01' AND '"+filterDate+"'"));

  //  ui->listView->setItemDelegateForColumn(4,deid);

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

    if(indexes.count()>0)
    {


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
            sizTableModel->select();
        }

    }
}




void MainSizWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{



    if(item->parent()!=nullptr) {
        QString parrent = item->parent()->data(0,0).toString();

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

void MainSizWindow::on_treeWidget_itemChanged(QTreeWidgetItem *item, int column)
{


}

void MainSizWindow::on_treeWidget_itemActivated(QTreeWidgetItem *item, int column)
{

}

void MainSizWindow::on_spinBox_valueChanged(int arg1)
{

    int addDay = ui->spinBox->value();

    QString filterDate = QDate::currentDate().addDays(addDay).toString("yyyy-MM-dd");
    eventDateTableModel->setQuery(QString( "SELECT * FROM Siz WHERE endVerification BETWEEN '2014-01-01' AND '"+filterDate+"'"));

}

void MainSizWindow::on_pushButton_6_clicked()
{
     ObjectTableModel->insertRow(0);
}

void MainSizWindow::on_pushButton_4_clicked()
{
     PersonalTableModel->insertRow(0);
}
void MainSizWindow::on_pushButton_8_clicked()
{
      sizTypeTableModel->insertRow(0);
}

void MainSizWindow::on_pushButton_3_clicked()
{
    QModelIndexList indexes = ui->personalTableView->selectionModel()->selection().indexes();

    if(indexes.count()>0)
    {


        int ret = QMessageBox::warning(this, tr("Удаление записи"),"Удаление: "+
                                       indexes.at(0).data().toString(),
                                       QMessageBox::Yes
                                       | QMessageBox::Cancel
                                       );

        if(ret==QMessageBox::Yes)
        {
            PersonalTableModel->removeRows(indexes.at(0).row(),1);
            PersonalTableModel->select();
        }

    }
}

void MainSizWindow::on_pushButton_5_clicked()
{
    QModelIndexList indexes = ui->objectTableView->selectionModel()->selection().indexes();

    if(indexes.count()>0)
    {


        int ret = QMessageBox::warning(this, tr("Удаление записи"),"Удаление: "+
                                       indexes.at(0).data().toString(),
                                       QMessageBox::Yes
                                       | QMessageBox::Cancel
                                       );

        if(ret==QMessageBox::Yes)
        {
            ObjectTableModel->removeRows(indexes.at(0).row(),1);
            ObjectTableModel->select();
        }

    }
}

void MainSizWindow::on_tabWidget_currentChanged(int index)
{
    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(ui->tableView,db->getTypeSiz());
    ComboBoxItemDelegate* cbido = new ComboBoxItemDelegate(ui->tableView,db->getObject());
    ComboBoxItemDelegate* cbidp = new ComboBoxItemDelegate(ui->tableView,db->getPersonal());

    ui->tableView->setItemDelegateForColumn(5, cbid);
    ui->tableView->setItemDelegateForColumn(8, cbido);
    ui->tableView->setItemDelegateForColumn(9, cbidp);

    sizTableModel->select();
    sizTypeTableModel->select();
    ObjectTableModel->select();
    PersonalTableModel->select();
    eventDateTableModel->setQuery(eventDateTableModel->query().lastQuery());

    //Заполняем treeWidget
    QList<QString> listObject = db->getObject();
    QAbstractItemModel* model;
    model =  ui->treeWidget->model();
    QModelIndex id1 = model->index(0,0);


    int count = model->rowCount(id1);
    for (int i = count ; i>=0;i--)
    {
 model->removeRow(i,id1);
    }
    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id1); //добавляем детей
        model->setData(model->index(i,0,id1),listObject[i]); //добавляем детей
    }

    listObject = db->getTypeSiz();
    QModelIndex id2 = model->index(1,0);

    count = model->rowCount(id2);
    for (int i = count ; i>=0;i--)
    {
 model->removeRow(i,id2);
    }
    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id2); //добавляем детей
        model->setData(model->index(i,0,id2),listObject[i]); //добавляем детей
    }

    listObject = db->getPersonal();
    QModelIndex id3 = model->index(2,0);


     count = model->rowCount(id1);
    for (int i = count ; i>=0;i--)
    {
 model->removeRow(i,id3);
    }
    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id3); //добавляем детей
        model->setData(model->index(i,0,id3),listObject[i]); //добавляем детей
    }
}



void MainSizWindow::on_pushButton_7_clicked()
{
    QModelIndexList indexes = ui->typeSizTableView->selectionModel()->selection().indexes();

    if(indexes.count()>0)
    {


        int ret = QMessageBox::warning(this, tr("Удаление записи"),"Удаление: "+
                                       indexes.at(0).data().toString(),
                                       QMessageBox::Yes
                                       | QMessageBox::Cancel
                                       );

        if(ret==QMessageBox::Yes)
        {
            sizTypeTableModel->removeRows(indexes.at(0).row(),1);
            sizTypeTableModel->select();
        }

    }
}
