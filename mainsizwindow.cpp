#include "mainsizwindow.h"


MainSizWindow::MainSizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSizWindow)
{

    ui->setupUi(this);

    db = new DataBase();
    db->connectToDataBase();

    setupModels();
    createUI();
    Style();

    QItemSelectionModel *sm = ui->tableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(on_tableViewTriggerSelectionModel_currentRowChanged(QModelIndex,QModelIndex)));

    tmr = new QTimer();
    tmr->setInterval(1200000);

    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();
    updateTime();

    QFile file(":/new/STO/03-08-16.txt");
    file.open(QFile::ReadOnly | QFile::Text);
    ui->plainTextEdit->setPlainText(file.readAll());

    //    QFile file(":/new/STO/STO/_030816_.html");
    //    file.open(QFile::ReadOnly | QFile::Text);
    //    QTextStream stream(&file);
    //    ui->textEdit->setHtml(stream.readAll());
    /* Инициализируем внешний вид таблицы с данными
        * */
    // this->createUI();
}
void MainSizWindow::Style()
{
    ui->listWidget->setStyleSheet("font: 13pt; selection-color: rgb(0, 0, 0); selection-background-color: rgb(232, 237, 240);");
    qApp->setStyleSheet("QWidget {  selection-color: rgb(0, 0, 0); selection-background-color: rgb(232, 237, 240); }"
                        "QTableView{ font: 12pt  }");


}
void MainSizWindow::closeEvent(QCloseEvent * event)
{
    if(this->isVisible() ){
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Журнал СИЗ",
                              trUtf8("Приложение свернуто в трей. Для того чтобы, "
                                     "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              icon,
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
    sizTableModel = new MainTableModel(this,&eventArray);
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
    ui->tableView->setSortingEnabled(true);
    ObjectTableModel->setTable(OBJECTTABLE);
    PersonalTableModel->setTable(PERSONALTABEL);

    QDate stopDate = QDate::currentDate(); // возвращаем текущую дату
    QDate startDate = stopDate.addDays(10); // возвращаем текущую дату
    // eventDateTableModel->setQuery("SELECT * FROM Siz WHERE endVerification BETWEEN '2014-01-02' AND '"+stopDate.toString("yyyy-MM-dd")+"'");
    sizTableModel->select();
    sizTypeTableModel->select();
    ObjectTableModel->select();
    PersonalTableModel->select();
    //Заполняем treeWidget



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
    QList<QString> listObject = db->getObject();
    QAbstractItemModel* model;
    model =  ui->treeWidget->model();
    QModelIndex id1 = model->index(0,0);
    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id1); //добавляем детей
        model->setData(model->index(i,0,id1),listObject[i]); //добавляем детей
    }
    listObject.clear();
    listObject = db->getTypeSiz();
    QModelIndex id2 = model->index(1,0);


    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id2); //добавляем детей
        model->setData(model->index(i,0,id2),listObject[i]); //добавляем детей
    }
    listObject.clear();
    listObject = db->getPersonal();
    QModelIndex id3 = model->index(2,0);


    for (int i = 0 ; i<listObject.length();i++)
    {

        model->insertRow(i,id3); //добавляем детей
        model->setData(model->index(i,0,id3),listObject[i]); //добавляем детей
    }

    db->readSizFromDB();

    //    //Типы СИЗ
    ui->tableView_2->setModel(sizTypeTableModel);
    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->tableView_2->resizeColumnsToContents();
    ui->tableView_2->resizeRowsToContents();
    ui->tableView_2->horizontalHeader()->setStretchLastSection(true);

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

    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(ui->tableView,db->getTypeSiz());
    ComboBoxItemDelegate* cbido = new ComboBoxItemDelegate(ui->tableView,db->getObject());
    ComboBoxItemDelegate* cbidp = new ComboBoxItemDelegate(ui->tableView,db->getPersonal());
    // ComboBox only in column 2
    CheckBoxItemDelegate* chbib = new CheckBoxItemDelegate (ui->tableView);
    DateEditItemDelegate* deid = new DateEditItemDelegate(ui->tableView);

    //  ui->listView->setItemDelegateForColumn(4,deid);

    ui->tableView->setItemDelegateForColumn(2,chbib);
    ui->tableView->setItemDelegateForColumn(5, cbid);
    ui->tableView->setItemDelegateForColumn(6, chbib);
    ui->tableView->setItemDelegateForColumn(3, deid);
    ui->tableView->setItemDelegateForColumn(4, deid);
    ui->tableView->setItemDelegateForColumn(7, deid);
    ui->tableView->setItemDelegateForColumn(8, cbido);
    ui->tableView->setItemDelegateForColumn(9, cbidp);
    ui->tableView->setItemDelegateForColumn(11, deid);

    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(6);

    sizTableModel->select(); // Делаем выборку данных из таблицы
    sizTableModel->setEditStrategy(QSqlTableModel::OnFieldChange);
    reloadEvents();

    ui->selectedItemOsmotrButton->hide();
    ui->selectedItemLabel->setText("");


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
    ComboBoxItemDelegate* cbid = new ComboBoxItemDelegate(ui->tableView,db->getTypeSiz());
    ComboBoxItemDelegate* cbido = new ComboBoxItemDelegate(ui->tableView,db->getObject());
    ComboBoxItemDelegate* cbidp = new ComboBoxItemDelegate(ui->tableView,db->getPersonal());

    ui->tableView->setItemDelegateForColumn(5, cbid);
    ui->tableView->setItemDelegateForColumn(8, cbido);
    ui->tableView->setItemDelegateForColumn(9, cbidp);

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
                                  icon
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

        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);
        trayIcon->showMessage("Журнал СИЗ",
                              trUtf8(message.toUtf8()),
                              icon,ui->spinBox_2->value()
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
void MainSizWindow::on_radioButton_group_toggle(int button,bool checked)
{
    if(checked){
        switch (button) {
        case -2:
            ui->tableView_2->setModel(sizTypeTableModel);
            ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
            // Устанавливаем режим выделения лишь одно строки в таблице
            ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
            // Устанавливаем размер колонок по содержимому
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_2->resizeRowsToContents();
            ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
            break;
        case -3:
            ui->tableView_2->setModel(ObjectTableModel);
            ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
            // Устанавливаем режим выделения лишь одно строки в таблице
            ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
            // Устанавливаем размер колонок по содержимому
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_2->resizeRowsToContents();
            ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
            break;
        case -4:
            ui->tableView_2->setModel(PersonalTableModel);
            ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
            // Устанавливаем режим выделения лишь одно строки в таблице
            ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
            // Устанавливаем размер колонок по содержимому
            ui->tableView_2->resizeColumnsToContents();
            ui->tableView_2->resizeRowsToContents();
            ui->tableView_2->horizontalHeader()->setStretchLastSection(true);
            break;
        default:
            break;
        }
    }

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
