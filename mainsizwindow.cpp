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
    reloadEvents();
    createUI();
    sizTableModel->setSort(5,Qt::AscendingOrder);
    sizTableModel->select();

    QItemSelectionModel *sm = ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(on_tableViewTriggerSelectionModel_currentRowChanged(QModelIndex,QModelIndex)));
    connect(ui->tableView->model(), SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)),
            this, SLOT(on_tableView_Data_Changed(QModelIndex,QModelIndex)));

    tmr = new QTimer();
    tmr->setInterval(1200000);

    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();
    updateTime();

    QFile file(":/new/STO/03-08-16.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    ui->plainTextEdit->setPlainText(file.readAll());

}
void MainSizWindow::Style()
{
    ui->listWidget->setStyleSheet("font: 14pt; selection-color: rgb(0, 0, 0); selection-background-color: rgb(232, 237, 240);");
    qApp->setStyleSheet("QWidget {  selection-color: rgb(0, 0, 0); selection-background-color: rgb(232, 237, 240,  100); }"
                        "QTableView{ font: 13pt  }");


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
    /* Инициализируем модель для представления данных
     * с заданием названий колонок
     * */
    sizTableModel = new MainTableModel(this,&eventArray);
    sizTypeTableModel= new QSqlTableModel(this);
    ObjectTableModel= new QSqlTableModel(this);
    PersonalTableModel= new QSqlTableModel(this);
    eventDateTableModel= new QSqlTableModel(this);

    QStringList headerList;

    headerList<< tr("п/п")
              << tr("Номер")
              <<tr("Изъято")
             <<tr("Испытанно")
            <<tr("Испытать")
           <<tr("Наименование")
          <<tr("Осмотренно")
         <<tr("Осмотренно")
        <<tr("Объект")
       << tr("Сотрудник")
       <<tr("Примечание")
      <<tr("Выдан в пользование");
    setupModel(SIZTABLE,sizTableModel,headerList);
    headerList.clear();

    headerList<<  tr("Наименование")
               <<tr("Испытывается")
              <<tr("Переодичность испытаний мес.")
             <<tr("Переодичность осмотров мес.")
            <<tr("Персональный");
    setupModel(TYPESIZTABLE,sizTypeTableModel,headerList);
    headerList.clear();

    setupModel(OBJECTTABLE,ObjectTableModel,headerList);

    setupModel(PERSONALTABEL,PersonalTableModel,headerList);

    sizTableModel->setSort(5,Qt::AscendingOrder);
    sizTableModel->select();
    sizTypeTableModel->select();
    ObjectTableModel->select();
    PersonalTableModel->select();
}
void MainSizWindow::setupModel(const QString &tableName, QSqlTableModel* model, const QStringList &headers)
{
    model->setTable(tableName);
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    if(headers.count()>0&&headers.count()<=model->columnCount()){

        for(int i = 0; i < headers.count(); i++){
            model->setHeaderData(i,Qt::Horizontal,headers[i]);
        }
    }
    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setSort(0,Qt::AscendingOrder);
}
void MainSizWindow::reloadEvents()
{
    eventArray.clear();
    ui->listWidget->clear();
    QSqlQuery q("select * from Siz ");

    QSqlRecord rec = q.record();



    //

    while (q.next()){

        bool ispit = false, oldOsmotr = false, badVerification=false;                                                             // ИСПЫТЫВАЕТСЯ??
        int periodOsmotra = 0, periodIspitania =0;                                                          //переодичность осмотра

        QString result ="";
        QString number = q.value(rec.indexOf("number")).toString();     //Номер

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

            QPair<int,QPair<int,QString> > res;
            res.first = QString::number(daysToNextVerification).toInt();
            res.second = QPair<int,QString> (index,result);
            eventArray.append(res);

        }else if ((!badVerification) && oldOsmotr ) {
            result+=QString("ОСМОТРЕТЬ \""+typeSiz+"\" №"+number+" просрочен на "+QString::number(daysToNextOsmotr*-1)+ " дней");

            QPair<int,QPair<int,QString> > res;
            res.first = QString::number(daysToNextOsmotr).toInt();
            res.second = QPair<int,QString> (index,result);
            eventArray.append(res);

        }else if ((daysToNextOsmotr<ui->spinBox->value())&&(daysToNextVerification> daysToNextOsmotr)&&ispit) {
            result+=QString(QString::number(daysToNextOsmotr)+" дней до осмотра \""+typeSiz+"\" №"+number);

            QPair<int,QPair<int,QString> > res;
            res.first = QString::number(daysToNextOsmotr).toInt();
            res.second = QPair<int,QString> (index,result);
            eventArray.append(res);

        }else if ((daysToNextOsmotr<ui->spinBox->value())&&daysToNextVerification< daysToNextOsmotr&&ispit) {
            result+=QString(QString::number(daysToNextVerification)+" дней до изъятия \""+typeSiz+"\" №"+number);

            QPair<int,QPair<int,QString> > res =  QPair<int,QPair<int,QString> >();
            res.first = QString::number(daysToNextVerification).toInt();
            res.second =  QPair<int,QString> (index,result);
            eventArray.append(res);

        }else if ((daysToNextOsmotr<ui->spinBox->value())&&(!ispit)) {
            result+=QString(QString::number(daysToNextOsmotr)+" дней до осмотра \""+typeSiz+"\" №"+number);

            QPair<int,QPair<int,QString> > res;
            res.first = QString::number(daysToNextOsmotr).toInt();
            res.second =QPair<int,QString> (index,result);
            eventArray.append(res);

        }



    }
    qSort(eventArray.begin(), eventArray.end(), [](QPair<int,QPair<int,QString> >  a, QPair<int,QPair<int,QString> >  b) { return a.first < b.first; } );
    // qSort(array.begin(), array.end(), [](QPair<int,QString> a, QPair<int,QString> b) { return a.first < b.first; } );
    for (int i=0;i<eventArray.count();i++) {
        ui->listWidget->addItem(QString(QString::number(i+1)+". "+eventArray[i].second.second));
    }
}

void MainSizWindow::createUI()
{ trayIcon = new QSystemTrayIcon(this);
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
    ui->tableView->setModel(sizTableModel);     // Устанавливаем модель на TableView
    // Разрешаем выделение строк
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(6);
    reloadDelegateMainTabView();
    ui->tableView->setSortingEnabled(true);

    sizTableModel->select(); // Делаем выборку данных из таблицы


    ui->selectedItemOsmotrButton->hide();
    ui->selectedItemLabel->setText("");
    ui->textBrowser->hide();

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
        if(parrent == "Сотрудники")
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

void MainSizWindow::on_spinBox_valueChanged(int arg1)
{
    reloadEvents();
}

void MainSizWindow::on_pushButton_4_clicked()//Перечни удалить запись
{
    QModelIndexList indexes = ui->tableView_2->selectionModel()->selection().indexes();
    if(indexes.count()>0)
    {
        int ret = QMessageBox::warning(this, tr("Удаление записи"),"Удаление: "+
                                       indexes.at(0).data().toString(),
                                       QMessageBox::Yes
                                       | QMessageBox::Cancel
                                       );
        if(ret==QMessageBox::Yes)
        {
            ui->tableView_2->model()->removeRows(indexes.at(0).row(),1);
            PersonalTableModel->select();
            ObjectTableModel->select();
            sizTypeTableModel->select();
        }

    }
}

void MainSizWindow::on_pushButton_3_clicked() //Перечни - добавить запись
{
    ui->tableView_2->model()->insertRow(0);

}

void MainSizWindow::on_tabWidget_currentChanged(int index)
{

    reloadEvents();
    reloadDelegateMainTabView();
    reloadTreeWidgetItems();

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
            QIcon  myicon =  QIcon(":/new/icon/153png.png");

            trayIcon->showMessage("Журнал СИЗ",
                                  trUtf8(message.toUtf8()),
                                  myicon
                                  );}
    }}
void MainSizWindow::on_pushButton_9_clicked()
{
    QString message;
    if(ui->listWidget->count()>0){
        for (int i=0;i<ui->listWidget->count()&&i<4;i++) {
            message+= ui->listWidget->item(i)->text()+"; \n";
        }

        int ret = QMessageBox::information(this, tr("Уведомление"), "QSystemTrayIcon::isSystemTrayAvailable()" + QSystemTrayIcon::isSystemTrayAvailable()?"Yes":"No"
                                                                                                                                                          ,
                                           QMessageBox::Ok

                                           );


        QIcon  myicon =  QIcon(":/new/icon/153png.png");
        trayIcon->showMessage("Журнал СИЗ",
                              trUtf8(message.toUtf8()),
                              myicon,ui->spinBox_2->value()
                              );}
}
void MainSizWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int indexRow = ui->listWidget->currentRow();

    QString sqlTableIndex = QString::number(eventArray[indexRow].second.first);
    QString filter =  "\"index\"="+ sqlTableIndex;
    sizTableModel->setFilter(filter);
    sizTableModel->select();
    if(sizTableModel->rowCount()>0) ui->tableView->selectRow(0);
    ui->tabWidget->setCurrentIndex(0);
    ui->tableView->setFocus();
}

void MainSizWindow::on_radioButton_3_toggled(bool checked)
{

}
void MainSizWindow::setModelOnTableView(QSqlTableModel* model){
    ui->tableView_2->setModel(model);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->resizeRowsToContents();
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
}
void MainSizWindow::on_radioButton_group_toggle(int button,bool checked)
{
    if(checked){
        switch (button) {
        case -2:
          setModelOnTableView(sizTypeTableModel);
            break;
        case -3:
        setModelOnTableView(ObjectTableModel);
            break;
        case -4:
         setModelOnTableView(PersonalTableModel);
            break;
        default:
            break;
        }
    }

}
void MainSizWindow::on_tableView_Data_Changed(QModelIndex current,QModelIndex prevous)
{
    reloadEvents();
    on_tableViewTriggerSelectionModel_currentRowChanged(current,prevous);
}
void MainSizWindow::on_tableViewTriggerSelectionModel_currentRowChanged(QModelIndex current,QModelIndex prevous)
{
    if(current.row()>=0)
    {

        bool SizOk = true;
        QAbstractItemModel * model = sizTableModel;
        QModelIndex primaryKeyIndex = model->index(current.row(), 0);
        QModelIndex osmotrIndex = model->index(current.row(), 7);
        QModelIndex typeSiz = model->index(current.row(), 5);

        int id = model->data(primaryKeyIndex, Qt::DisplayRole).toInt();
        QString sDate = model->data(osmotrIndex, Qt::DisplayRole).toString();
        QDate dateOsmotr = QDate::fromString(model->data(osmotrIndex, Qt::DisplayRole).toString(),"dd.MM.yyyy");
        QString typeS = model->data(typeSiz, Qt::DisplayRole).toString();
        int mounthInspection  = db->getMounthInspection(typeS);
        int mounthVerification  = db->getVerifiMounth(typeS);

        QDate dateNextInspp = dateOsmotr.addMonths(mounthInspection);


        for (int i=0;i<eventArray.count();i++) {
            if(eventArray[i].second.first ==id)
            {


                ui->selectedItemOsmotrButton->show();
                ui->selectedItemLabel->show();


                ui->selectedItemDateEdit->setDate(dateNextInspp);
                ui->selectedItemLabel->setText(eventArray[i].second.second + "\n Осмотр раз в "+QString::number(mounthInspection)+" мес. \n Следующий осмотр:");
                SizOk = false;
                break;

            }
            else
            {
                ui->selectedItemOsmotrButton->hide();
            }

        }
        if(SizOk)
        {

            ui->selectedItemDateEdit->setDate(dateNextInspp);
            QString ispit = mounthVerification>0?"Испытания раз в "+QString::number(mounthVerification)+"мес. \n":"Не испытывается. \n";
            ui->selectedItemLabel->setText(ispit + "Осмотр раз в "+QString::number(mounthInspection)+" мес. \n Следующий осмотр:");
        }




    }


}
void MainSizWindow::on_selectedItemOsmotrButton_clicked()
{
    QModelIndexList listIndex = ui->tableView->selectionModel()->selectedRows();
    if(listIndex.count()>0){
        QModelIndex current = ui->tableView->selectionModel()->selectedRows()[0];

        QAbstractItemModel * model = sizTableModel;
        QModelIndex osmotrIndex = model->index(current.row(), 7);
        sizTableModel->setData(osmotrIndex,ui->selectedItemDateEdit->date().toString("yyyy-MM-dd"));
        QModelIndexList listIndex = ui->tableView->selectionModel()->selectedRows();
        reloadEvents();
        sizTableModel->select();
        ui->tableView->selectRow(current.row());
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
void MainSizWindow::reloadDelegateMainTabView()
{
    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(ui->tableView,db->getTypeSiz());
    ComboBoxItemDelegate* cbido = new ComboBoxItemDelegate(ui->tableView,db->getObject());
    ComboBoxItemDelegate* cbidp = new ComboBoxItemDelegate(ui->tableView,db->getPersonal());
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
    ui->tableView->setItemDelegateForColumn(11, deid);
}
