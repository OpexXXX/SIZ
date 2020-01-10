#include "mainsizwindow.h"

MainSizWindow::MainSizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSizWindow)
{
    ui->setupUi(this);
    db = new DataBase();
    db->connectToDataBase();
    setupModels();
    Style();
    createUI();
}
void MainSizWindow::Style()
{
    ui->listEventView->setStyleSheet("font: 14pt; selection-color: rgb(0, 0, 0); selection-background-color: rgb(232, 237, 240);");
    qApp->setStyleSheet("QWidget {  selection-color: rgb(0, 0, 0); selection-background-color: rgba(232, 237, 240,  100); }"
                        "mainTableView{ font: 13pt; selection-background-color: rgba(232, 237, 240,  100);  }");


}
void MainSizWindow::closeEvent(QCloseEvent * event)
{

    if(this->isVisible() ){
        event->ignore();
        this->hide();

        QIcon  myicon =  QIcon(":/new/icon/153png.png");
        trayIcon->showMessage("Журнал СИЗ",
                              trUtf8("Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              myicon,
                              2000);
    }
}
void MainSizWindow::hideEvent(QHideEvent *event)
{
    event->ignore();
    this->hide();
}
/* Метод, который обрабатывает нажатие на иконку приложения в трее
 * */
void MainSizWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:

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
    /* Инициализируем модели и прокси модели для представления данных
     * */
    sizProxyTableModel = new MainTableModel(this);
    mainSizModel = new sizModel(this);
    eventProxyTableModel = new EventViewModel(this);


    sizTypeTableModel= new QSqlTableModel(this);
    ObjectTableModel= new QSqlTableModel(this);
    PersonalTableModel= new QSqlTableModel(this);
   // eventDateTableModel= new EventList(this);

    QStringList headerList;
    headerList.clear();


    mainSizModel->setTable(SIZTABLE);
    mainSizModel->setRelation(MainSizModelHead::nameSiz,            QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_NAME));
    mainSizModel->setRelation(MainSizModelHead::bool_verification,  QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_VER));
    mainSizModel->setRelation(MainSizModelHead::verifiPediod,       QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_VERPERIOD));
    mainSizModel->setRelation(MainSizModelHead::inspectPediod,      QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_INSPEDIOD));
    mainSizModel->setRelation(MainSizModelHead::personalyty,        QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_PERSONALYTY));
    mainSizModel->setRelation(MainSizModelHead::object,             QSqlRelation(OBJECTTABLE, OBJECTTABLE_ID, OBJECTTABLE_NAME));
    mainSizModel->setRelation(MainSizModelHead::persona,            QSqlRelation(PERSONALTABEL, PERSONALTABEL_ID, PERSONALTABEL_NAME));

    sizProxyTableModel->setSourceModel(mainSizModel);
    eventProxyTableModel->setSourceModel(mainSizModel);

    sizTypeTableModel->setTable(TYPESIZTABLE);
    ObjectTableModel->setTable( OBJECTTABLE);
    PersonalTableModel->setTable(PERSONALTABEL);

    mainSizModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);



    mainSizModel->select();
    sizTypeTableModel->select();
    ObjectTableModel->select();
    PersonalTableModel->select();

    mainSizModel->updateAllEvents();
}
void MainSizWindow::setHeadersOnModel(const QStringList &headers, QSqlTableModel *model)
{
    if(headers.count()>0&&headers.count()<=model->columnCount()){

        for(int i = 0; i < headers.count(); i++){
            model->setHeaderData(i,Qt::Horizontal,headers[i]);
        }
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->setSort(0,Qt::AscendingOrder);
}



void MainSizWindow::createUI()
{
    trayIcon = new QSystemTrayIcon(this);
    QIcon  myicon =  QIcon(":/new/icon/153png.png");
    trayIcon->setIcon(myicon);
    trayIcon->setToolTip("Журнал СИЗ");
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
    connect(ui->buttonGroup, SIGNAL(buttonToggled(int, bool)),this,SLOT(on_radioButton_group_toggle(int, bool)));
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

    reloadTreeWidgetItems();

    //    //Типы СИЗ
    setModelOnTableView(sizTypeTableModel);

    //СИЗ

    ui->mainTableView->setModel(sizProxyTableModel);
    // Разрешаем выделение строк
    ui->mainTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->mainTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->mainTableView->resizeColumnsToContents();
    ui->mainTableView->resizeRowsToContents();
    ui->mainTableView->resizeColumnsToContents();
    ui->mainTableView->horizontalHeader()->setStretchLastSection(true);
    ui->mainTableView->hideColumn(0);
    ui->mainTableView->hideColumn(2);
    ui->mainTableView->hideColumn(10);
    ui->mainTableView->hideColumn(11);
    ui->mainTableView->hideColumn(12);
    ui->mainTableView->hideColumn(13);
    ui->mainTableView->hideColumn(14);
    ui->mainTableView->hideColumn(15);
    ui->mainTableView->hideColumn(16);
    ui->mainTableView->verticalHeader()->hide();
    setDelegateMainTabView();
    ui->mainTableView->setSortingEnabled(true);

    //   sizProxyTableModel->select(); // Делаем выборку данных из таблицы

    ui->listEventView->setModel(eventProxyTableModel);
ui->listEventView->setModelColumn(1);
    ui->selectedItemOsmotrButton->hide();
    ui->selectedItemLabel->setText("");
    ui->textBrowser->hide();

}
void MainSizWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{



    if(item->parent()!=nullptr) {
        QString parrent = item->parent()->data(0,0).toString();

        if(parrent == "Объекты")
        {
            /*  sizProxyTableModel->setFilter(QString( " object ='"+item->data(0,0).toString()+"'")
                                     );*/

        }
        if(parrent == "Сотрудники")
        {
            /* sizProxyTableModel->setFilter(QString( " personal ='"+item->data(0,0).toString()+"'")
                                     );
*/
        }
        if(parrent == "Типы СИЗ")
        {
            /*  sizProxyTableModel->setFilter(QString( " typeSiz ='"+item->data(0,0).toString()+"'")
                                     );*/

        }
        // sizProxyTableModel->select();
        ui->mainTableView->resizeColumnsToContents();
        ui->mainTableView->resizeRowsToContents();
        ui->mainTableView->resizeColumnsToContents();
    }
    else {
        //   sizProxyTableModel->setFilter("");
        //    sizProxyTableModel->select();
        ui->mainTableView->resizeColumnsToContents();
        ui->mainTableView->resizeRowsToContents();
        ui->mainTableView->resizeColumnsToContents();
    }


}

void MainSizWindow::on_tabWidget_currentChanged(int index)
{
    reloadTreeWidgetItems();
}
void MainSizWindow::updateTime()
{
   /* if( !this->hasFocus() ){
        QString message;
        if(ui->listWidget->count()>0){
            for (int i=0;i<ui->listWidget->count()&&i<4;i++) {
                message+= ui->listWidget->item(i)->text()+"; \n";
            }
            QIcon  myicon =  QIcon(":/new/icon/153png.png");

            trayIcon->showMessage("Журнал СИЗ",
                                  trUtf8(message.toUtf8()),
                                  myicon
                                  );}
    }*/
}

void MainSizWindow::on_pushButton_9_clicked()
{

}
void MainSizWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{


}
void MainSizWindow::on_radioButton_3_toggled(bool checked)
{

}
void MainSizWindow::setModelOnTableView(QSqlTableModel* model){
    ui->perechenTableView->setModel(model);
    ui->perechenTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->perechenTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->perechenTableView->resizeColumnsToContents();
    ui->perechenTableView->resizeRowsToContents();
    ui->perechenTableView->horizontalHeader()->setStretchLastSection(true);
}
void MainSizWindow::on_radioButton_group_toggle(int button,bool checked)
{
    if(checked){
        switch (button) {
        case -2:
            setModelOnTableView(sizTypeTableModel);
              ui->perechenTableView->showRow(0);
            break;
        case -3:
            setModelOnTableView(ObjectTableModel);
             ui->perechenTableView->hideRow(0);
            break;
        case -4:
            setModelOnTableView(PersonalTableModel);
             ui->perechenTableView->hideRow(0);
            break;
        default:
            break;
        }
    }

}
void MainSizWindow::on_mainTableView_Data_Changed(QModelIndex current,QModelIndex prevous)
{

}
void MainSizWindow::on_mainTableViewTriggerSelectionModel_currentRowChanged(QModelIndex current,QModelIndex prevous)
{


}
void MainSizWindow::on_selectedItemOsmotrButton_clicked()
{
    QModelIndexList listIndex = ui->mainTableView->selectionModel()->selectedRows();
    if(listIndex.count()>0){
        QModelIndex current = ui->mainTableView->selectionModel()->selectedRows()[0];

        QAbstractItemModel * model = sizProxyTableModel;
        QModelIndex osmotrIndex = model->index(current.row(), 7);
        sizProxyTableModel->setData(osmotrIndex,ui->selectedItemDateEdit->date().toString("yyyy-MM-dd"),Qt::EditRole);
        QModelIndexList listIndex = ui->mainTableView->selectionModel()->selectedRows();

        sizProxyTableModel->dataChanged(osmotrIndex,osmotrIndex);
    }
}
void MainSizWindow::on_pushButton_5_toggled(bool checked)
{
    if (checked) {
        ui->textBrowser->show();
    } else
    {
        ui->textBrowser->hide();
    }
}
void MainSizWindow::reloadTreeWidgetItems()
{
    ui->treeWidget->clear();
    QList<QString> listObject = db->getObject();
    addItemsTreeWidget(listObject,"Объекты");
    listObject = db->getTypeSiz();
    addItemsTreeWidget(listObject,"Типы СИЗ");
    listObject = db->getPersonal();
    addItemsTreeWidget(listObject,"Сотрудники");
}
void MainSizWindow::addItemsTreeWidget(QList<QString> listChild, QString nameTop)
{
    QFont topFont,childFont;
    topFont.setPixelSize(20);
    childFont.setPixelSize(16);
    QTreeWidgetItem * topLevel = new QTreeWidgetItem();
    topLevel->setText(0, nameTop);
    topLevel->setFont(0,topFont);
    ui->treeWidget->addTopLevelItem(topLevel);
    for(int i=0;i<listChild.count();++i){
        QTreeWidgetItem * item = new QTreeWidgetItem();
        item->setText(0,listChild.at(i));
        item->setFont(0,childFont);
        topLevel->addChild(item);
    }
}
void MainSizWindow::setDelegateMainTabView()
{
    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(ui->mainTableView,sizTypeTableModel);
    ComboBoxItemDelegate* cbido = new ComboBoxItemDelegate(ui->mainTableView,ObjectTableModel);
    ComboBoxItemDelegate* cbidp = new ComboBoxItemDelegate(ui->mainTableView,PersonalTableModel);
    DateEditItemDelegate* deid = new DateEditItemDelegate(ui->mainTableView);
    ui->mainTableView->setItemDelegateForColumn(MainSizModelHead::nameSiz,cbid);
    ui->mainTableView->setItemDelegateForColumn(MainSizModelHead::object, cbido);
    ui->mainTableView->setItemDelegateForColumn(MainSizModelHead::persona, cbidp);
    ui->mainTableView->setItemDelegateForColumn(MainSizModelHead::personalDate, deid);
    ui->mainTableView->setItemDelegateForColumn(MainSizModelHead::inspectionDate, deid);
    ui->mainTableView->setItemDelegateForColumn(MainSizModelHead::verificationDate, deid);
    ui->mainTableView->setItemDelegateForColumn( MainSizModelHead::personalDate  , deid);
}
void MainSizWindow::on_addRowMainTable_clicked()
{
    sizProxyTableModel->insertRow(0);
}
void MainSizWindow::on_deleteRowMainTable_clicked()
{
    QModelIndexList indexes = ui->mainTableView->selectionModel()->selection().indexes();

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
            //   sizProxyTableModel->removeRows(indexes.at(1).row(),1);
            //     sizProxyTableModel->select();
        }

    }
}

void MainSizWindow::on_addRowPerechniTable_clicked()
{
    ui->perechenTableView->model()->insertRow(0);
}

void MainSizWindow::on_deleteRowPerechniTable_clicked()
{
    QModelIndexList indexes = ui->perechenTableView->selectionModel()->selection().indexes();
    if(indexes.count()>0)
    {
        int ret = QMessageBox::warning(this, tr("Удаление записи"),"Удаление: "+
                                       indexes.at(0).data().toString(),
                                       QMessageBox::Yes
                                       | QMessageBox::Cancel
                                       );
        if(ret==QMessageBox::Yes)
        {
            ui->perechenTableView->model()->removeRows(indexes.at(0).row(),1);
            PersonalTableModel->select();
            ObjectTableModel->select();
            sizTypeTableModel->select();
        }

    }
}

void MainSizWindow::on_daysOfEvent_valueChanged(int arg1)
{
   mainSizModel->setDaysToEvents(arg1);
}

void MainSizWindow::on_pushButton_clicked()
{
    QModelIndex index = ui->tableViewTemp->selectionModel()->currentIndex();
    if (index.isValid()) {
        //  EventSiz& organization = eventDateTableModel->getEvent(index);



        //               organization.setId(1452);
        //               organization.setType("gzdfgzgdzgzdfg");
        //               organization.setNumber("fesgrgsrhtshshs");

    //    eventDateTableModel->dataChanged(index,index);

    }
}
