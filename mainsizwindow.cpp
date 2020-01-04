#include "mainsizwindow.h"
#include "ui_mainsizwindow.h"

#include <QSqlRecord>
#include "comboboxitemdelegate.h"
#include "checkboxitemdelegate.h"
#include "dateedititemdelegate.h"

#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QStandardItemModel>
#include <QIcon>
MainSizWindow::MainSizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSizWindow)
{

    ui->setupUi(this);
    /* Первым делом необходимо создать объект, который будет использоваться для работы с данными нашей БД
        * и инициализировать подключение к базе данных
        * */
    /* Инициализируем иконку трея, устанавливаем иконку из набора системных иконок,
        * а также задаем всплывающую подсказку
        * */
       trayIcon = new QSystemTrayIcon(this);
      QIcon  myicon = *new QIcon(":/new/icon/icon.svg");
       trayIcon->setIcon(myicon);

       trayIcon->setToolTip("Tray Program" "\n"
                            "Работа со сворачиванием программы трей");
       /* После чего создаем контекстное меню из двух пунктов*/
           QMenu * menu = new QMenu(this);
           QAction * viewWindow = new QAction(trUtf8("Развернуть окно"), this);
           QAction * quitAction = new QAction(trUtf8("Выход"), this);

           /* подключаем сигналы нажатий на пункты меню к соответсвующим слотам.
            * Первый пункт меню разворачивает приложение из трея,
            * а второй пункт меню завершает приложение
            * */
           connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
           connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

           menu->addAction(viewWindow);
           menu->addAction(quitAction);

           /* Устанавливаем контекстное меню на иконку
            * и показываем иконку приложения в трее
            * */
           trayIcon->setContextMenu(menu);
           trayIcon->show();

           /* Также подключаем сигнал нажатия на иконку к обработчику
            * данного нажатия
            * */
           connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                   this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    db = new DataBase();
    db->connectToDataBase();

    /* После чего производим наполнение таблицы базы данных
        * контентом, который будет отображаться в TableView
        * */
    QVariantList data;



    setupModels();
    tmr = new QTimer();
    tmr->setInterval(1200000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();
    updateTime();
    ui->listWidget->setStyleSheet("font: 12pt;");
    /* Инициализируем внешний вид таблицы с данными
        * */
    // this->createUI();
}
void MainSizWindow::closeEvent(QCloseEvent * event)
{
    /* Если окно видимо и чекбокс отмечен, то завершение приложения
     * игнорируется, а окно просто скрывается, что сопровождается
     * соответствующим всплывающим сообщением
     */

        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Tray Program",
                              trUtf8("Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              icon,
                              2000);

}

/* Метод, который обрабатывает нажатие на иконку приложения в трее
 * */
void MainSizWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
        /* Событие игнорируется в том случае, если чекбокс не отмечен
         * */

            /* иначе, если окно видимо, то оно скрывается,
             * и наоборот, если скрыто, то разворачивается на экран
             * */
            if(!this->isVisible()){
                this->show();
            } else {
                this->hide();
            }

        break;
    default:
        break;
    }
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
    sizTableModel = new MainTableModel(this);
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
    sizTableModel->setHeaderData(7, Qt::Horizontal, tr("Осмотренно"));
    sizTableModel->setHeaderData(8, Qt::Horizontal, tr("Объект"));
    sizTableModel->setHeaderData(9, Qt::Horizontal, tr("Сотрудник"));
    sizTableModel->setHeaderData(10, Qt::Horizontal, tr("Примечание"));
    sizTableModel->setHeaderData(11, Qt::Horizontal, tr("Выдан в пользование"));
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
    QString filterDate = QDate::currentDate().addDays(-(addDay+90)).toString("yyyy-MM-dd");
    eventDateTableModel->setQuery(QString( "SELECT * FROM Siz WHERE inspectionDate BETWEEN '2014-01-01' AND '"+filterDate+"'"));
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
    sizTableModel = new MainTableModel(this);
    sizTableModel->setTable(tableName);
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < sizTableModel->columnCount(); i++, j++){
        sizTableModel->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    sizTableModel->setSort(0,Qt::AscendingOrder);
}
void MainSizWindow::reloadEvents()
{
    ui->listWidget->clear();
    QSqlQuery q("select * from Siz ");

    QSqlRecord rec = q.record();
    QList<QPair<int,QPair<int,QString> > >  array = *new   QList<QPair<int,QPair<int,QString> > >() ;


    //

    while (q.next()){

        bool ispit = false, oldOsmotr = false, badVerification=false;                                                             // ИСПЫТЫВАЕТСЯ??
        int periodOsmotra = 0, periodIspitania =0;                                                          //переодичность осмотра

        QString result ="";
        QString number = q.value(rec.indexOf("number")).toString();     //Номер
        if(number=="48993")
        {
            qDebug()<<1;
        }
        QVariant  tSiz = q.value(rec.indexOf("typeSiz"));                 //Тип СИЗ
        QString typeSiz =tSiz.toString();

        ispit = db->getVerifi(typeSiz);
        periodOsmotra = db->getMounthInspection(typeSiz);
        periodIspitania = db->getVerifiMounth(typeSiz);

        QVariant  dateIsp = q.value(rec.indexOf("endVerification"));                 //Дата истечения испытания
        QDate  endDate =QDate::fromString(dateIsp.toString(),"yyyy-MM-dd");             //Дата истечения испытания

        QVariant  dateOsm = q.value(rec.indexOf("inspectionDate"));                 //Дата осмотра
        QDate  osmotrDate =QDate::fromString(dateOsm.toString(),"yyyy-MM-dd");          //Дата осмотра

        QDate curr = QDate::currentDate();

        QDate nextOsmotr = osmotrDate.addMonths(periodOsmotra);                               //Дата следующего осмотра
        //Проверяем не просрочен ли осмотр

        long long daysToNextOsmotr = curr.daysTo(nextOsmotr);                           //Дней до следующего осмотра
        long long daysToNextVerification = curr.daysTo(endDate);                        //Дней до испытания

        int index =q.value(rec.indexOf("index")).toInt();

        oldOsmotr = !(daysToNextOsmotr>0);
        badVerification = (daysToNextVerification<0);


        if (badVerification) {

            result+=QString("ИЗЪЯТЬ \""+typeSiz+"\" №"+number+" просрочен на "+QString::number(daysToNextVerification*-1)+ " дней");

            QPair<int,QPair<int,QString> > res = *new QPair<int,QPair<int,QString> >();
            res.first = QString::number(daysToNextVerification).toInt();
            res.second = *new QPair<int,QString> (index,result);
            array.append(res);

        }else if ((!badVerification) && oldOsmotr ) {
            result+=QString("ОСМОТРЕТЬ \""+typeSiz+"\" №"+number+" просрочен на "+QString::number(daysToNextOsmotr*-1)+ " дней");

            QPair<int,QPair<int,QString> > res = *new QPair<int,QPair<int,QString> >();
            res.first = QString::number(daysToNextOsmotr).toInt();
            res.second = *new QPair<int,QString> (index,result);
            array.append(res);

        }else if ((daysToNextOsmotr<ui->spinBox->value())&&(daysToNextVerification> daysToNextOsmotr)&&ispit) {
            result+=QString(QString::number(daysToNextOsmotr)+" дней до осмотра \""+typeSiz+"\" №"+number);

            QPair<int,QPair<int,QString> > res = *new QPair<int,QPair<int,QString> >();
            res.first = QString::number(daysToNextOsmotr).toInt();
            res.second = *new QPair<int,QString> (index,result);
            array.append(res);

        }else if ((daysToNextOsmotr<ui->spinBox->value())&&daysToNextVerification< daysToNextOsmotr&&ispit) {
            result+=QString(QString::number(daysToNextVerification)+" дней до изъятия \""+typeSiz+"\" №"+number);

            QPair<int,QPair<int,QString> > res = *new QPair<int,QPair<int,QString> >();
            res.first = QString::number(daysToNextVerification).toInt();
            res.second = *new QPair<int,QString> (index,result);
            array.append(res);

        }else if ((daysToNextOsmotr<ui->spinBox->value())&&(!ispit)) {
            result+=QString(QString::number(daysToNextOsmotr)+" дней до осмотра \""+typeSiz+"\" №"+number);

            QPair<int,QPair<int,QString> > res = *new QPair<int,QPair<int,QString> >();
            res.first = QString::number(daysToNextOsmotr).toInt();
            res.second = *new QPair<int,QString> (index,result);
            array.append(res);

        }



    }
    qSort(array.begin(), array.end(), [](QPair<int,QPair<int,QString> >  a, QPair<int,QPair<int,QString> >  b) { return a.first < b.first; } );
    // qSort(array.begin(), array.end(), [](QPair<int,QString> a, QPair<int,QString> b) { return a.first < b.first; } );

    for (int i=0;i<array.count();i++) {

        ui->listWidget->addItem(QString(QString::number(i+1)+". "+array[i].second.second));


    }
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




    int addDay = ui->spinBox->value();

    QString filterDate = QDate::currentDate().addDays(-(addDay+90)).toString("yyyy-MM-dd");

    eventDateTableModel->setQuery(QString( "SELECT * FROM Siz WHERE inspectionDate BETWEEN '2014-01-01' AND '"+filterDate+"'"));

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

    sizTableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    sizTableModel->select(); // Делаем выборку данных из таблицы
    reloadEvents();


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

   reloadEvents();


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
    reloadEvents();

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


    count = model->rowCount(id3);
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

void MainSizWindow::on_listView_doubleClicked(const QModelIndex &index)
{



}

void MainSizWindow::on_tableView_viewportEntered()
{

}

void MainSizWindow::on_tableView_entered(const QModelIndex &index)
{

}

void MainSizWindow::on_tableView_activated(const QModelIndex &index)
{
    sizTableModel->select();
}

void MainSizWindow::on_tableView_clicked(const QModelIndex &index)
{

}

void MainSizWindow::on_tableView_pressed(const QModelIndex &index)
{

}
void MainSizWindow::updateTime()
{
   if( !this->hasFocus() ){
    QString message;
    reloadEvents();
    if(ui->listWidget->count()>0){
    for (int i=0;i<ui->listWidget->count()&&i<4;i++) {
        message+= ui->listWidget->item(i)->text()+"; \n";
    }
     QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    trayIcon->showMessage("Журнал СИЗ",
                          trUtf8(message.toUtf8()),
                          icon,
                          10000);}
}}
void MainSizWindow::on_pushButton_9_clicked()
{
    QString message;
    if(ui->listWidget->count()>0){
    for (int i=0;i<ui->listWidget->count()&&i<4;i++) {
        message+= ui->listWidget->item(i)->text()+"; \n";
    }
     QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
    trayIcon->showMessage("Журнал СИЗ",
                          trUtf8(message.toUtf8()),
                          icon,
                          10000);}
}
