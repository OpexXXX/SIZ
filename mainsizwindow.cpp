#include "mainsizwindow.h"
#include <QTimer>

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
    messageTimer = new QTimer(this);
    connect(messageTimer, &QTimer::timeout, this, &MainSizWindow::updateTime);
    messageTimer->start(1000*60*20);
    updateTime();
}
void MainSizWindow::Style()
{
    ui->listEventView->setStyleSheet("font: 14pt; selection-color: rgb(0, 0, 0); selection-background-color: rgb(232, 237, 240);");
    qApp->setStyleSheet("QWidget {  selection-color: rgb(0, 0, 0); selection-background-color: rgba(212, 217, 250,  250); }"
                        "QTableView{ font: 13pt; selection-background-color: rgba(212, 217, 250,  250);  }");
}
void MainSizWindow::closeEvent(QCloseEvent * event)
{
    mainSizModel->submitAll();
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




    mainSizModel->setTable(SIZTABLE);
    mainSizModel->setRelation(MainSizModelHead::nameSiz,            QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_NAME));
    mainSizModel->setRelation(MainSizModelHead::bool_verification,  QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_VER));
    mainSizModel->setRelation(MainSizModelHead::verifiPediod,       QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_VERPERIOD));
    mainSizModel->setRelation(MainSizModelHead::inspectPediod,      QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_INSPEDIOD));
    mainSizModel->setRelation(MainSizModelHead::personalyty,        QSqlRelation(TYPESIZTABLE, TYPESIZTABLE_ID, TYPESIZTABLE_PERSONALYTY));
    mainSizModel->setRelation(MainSizModelHead::object,             QSqlRelation(OBJECTTABLE, OBJECTTABLE_ID, OBJECTTABLE_NAME));
    mainSizModel->setRelation(MainSizModelHead::persona,            QSqlRelation(PERSONALTABEL, PERSONALTABEL_ID, PERSONALTABEL_NAME));
    QStringList headers;
    headers<< tr("п/п")
           << tr("Номер")
           <<tr("Испытанно")
          <<tr("На испытание")
         <<tr("Осмотрено")
        <<tr("Наименование")
       <<tr("Объект")
      <<tr("Выдан в пользование")
     << tr("Сотрудник")
     <<tr("Примечание")
    <<tr("Осмотренно")
    <<tr("Изъято");
    setHeadersOnModel(headers,mainSizModel);

    sizProxyTableModel->setSourceModel(mainSizModel);
    eventProxyTableModel->setSourceModel(mainSizModel);

    eventProxyTableModel->sort(16);


    sizTypeTableModel->setTable(TYPESIZTABLE);
    ObjectTableModel->setTable( OBJECTTABLE);
    PersonalTableModel->setTable(PERSONALTABEL);

    mainSizModel->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);



    mainSizModel->select();
    sizTypeTableModel->select();
    ObjectTableModel->select();
    PersonalTableModel->select();
    mainSizModel->updateAllTypeSizData();
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

    QStringList headers;

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
    ui->mainTableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->mainTableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));
    QItemSelectionModel *sm = ui->mainTableView->selectionModel();
    connect(sm, SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this, SLOT(on_mainTableViewTriggerSelectionModel_currentRowChanged(QModelIndex,QModelIndex)));
    ui->listEventView->setModel(eventProxyTableModel);
    ui->listEventView->setModelColumn(10);
    ui->selectedItemOsmotrButton->hide();
    ui->selectedItemLabel->setText("");
    ui->textBrowser->hide();

}
void MainSizWindow::slotCustomMenuRequested(QPoint pos)
{
    /* Создаем объект контекстного меню */
    QMenu * menu = new QMenu(this);
    /* Создаём действия для контекстного меню */
    QAction * revertRow = new QAction(trUtf8("Отменить изменения в строке"), this);
    QAction * deleteRow = new QAction(trUtf8("Удалить"), this);
    /* Подключаем СЛОТы обработчики для действий контекстного меню */
    connect(revertRow, SIGNAL(triggered()), this, SLOT(slotRevertRecordRow()));     // Обработчик вызова диалога редактирования
    connect(deleteRow, SIGNAL(triggered()), this, SLOT(on_deleteRowMainTable_clicked())); // Обработчик удаления записи
    /* Устанавливаем действия в меню */
    menu->addAction(revertRow);
    menu->addAction(deleteRow);
    /* Вызываем контекстное меню */
    menu->popup(ui->mainTableView->viewport()->mapToGlobal(pos));
}

void MainSizWindow::slotRevertRecordRow(){
    int row = ui->mainTableView->selectionModel()->currentIndex().row();

    /* Проверяем, что строка была действительно выбрана
     * */
    QModelIndex selected = sizProxyTableModel->index(row,0);
    QModelIndex selectedSourse = sizProxyTableModel->mapToSource(selected);
    if(selectedSourse.isValid()){
        mainSizModel->revertRow(selectedSourse.row());
    }
}

void MainSizWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if(item->parent()!=nullptr) {
        QString parrent = item->parent()->data(0,0).toString();

        sizProxyTableModel->setFilterRegExp(QRegExp(item->text(0), Qt::CaseInsensitive,
                                                    QRegExp::FixedString));
        if(parrent == "Объекты")
        {
            sizProxyTableModel->setFilterKeyColumn(6);
        }
        if(parrent == "Сотрудники")
        {
            sizProxyTableModel->setFilterKeyColumn(8);
        }
        if(parrent == "Типы СИЗ")
        {
            sizProxyTableModel->setFilterKeyColumn(5);
        }
        // sizProxyTableModel->select();
        ui->mainTableView->resizeColumnsToContents();
        ui->mainTableView->resizeRowsToContents();
        ui->mainTableView->resizeColumnsToContents();
    }
    else {
        sizProxyTableModel->setFilterRegExp(QRegExp("", Qt::CaseInsensitive, QRegExp::FixedString));
        ui->mainTableView->resizeColumnsToContents();
        ui->mainTableView->resizeRowsToContents();
        ui->mainTableView->resizeColumnsToContents();
    }
}

void MainSizWindow::on_tabWidget_currentChanged(int index)
{
    // reloadTreeWidgetItems();
}
void MainSizWindow::updateTime()
{
    if( !this->hasFocus() ){
        QString message;
        if(eventProxyTableModel->rowCount()>0){
            for (int i=0;i<eventProxyTableModel->rowCount()&&i<4;i++) {
                message+= eventProxyTableModel->data(eventProxyTableModel->index(i,10),Qt::DisplayRole).toString()+"; \n";
            }
            QIcon  myicon =  QIcon(":/new/icon/153png.png");
            trayIcon->showMessage("Журнал СИЗ",
                                  trUtf8(message.toUtf8()),
                                  myicon
                                  );}
    }
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
    QModelIndex nS= sizProxyTableModel->index(current.row(),MainSizModelHead::nameSiz);
    QString nameSiz = sizProxyTableModel->data(nS,Qt::DisplayRole).toString();
    QModelIndex nu= sizProxyTableModel->index(current.row(),MainSizModelHead::number);
    QString number = sizProxyTableModel->data(nu,Qt::DisplayRole).toString();
    QModelIndex   bool_verification= sizProxyTableModel->index(current.row(),MainSizModelHead::bool_verification);
    bool verivication = sizProxyTableModel->data(bool_verification,Qt::DisplayRole).toBool();

    QModelIndex   inspectionD= sizProxyTableModel->index(current.row(),MainSizModelHead::inspectionDate);
    QString inspectionDa= sizProxyTableModel->data(inspectionD,Qt::DisplayRole).toString();
    QDate inspectionDate = QDate::fromString(inspectionDa,"dd.MM.yyyy");
    QModelIndex  verifiP= sizProxyTableModel->index(current.row(),MainSizModelHead::verifiPediod);
    int  verifiPediod= sizProxyTableModel->data(verifiP,Qt::DisplayRole).toInt();
    QModelIndex  inspectP= sizProxyTableModel->index(current.row(),MainSizModelHead::inspectPediod);
    int  inspectPediod= sizProxyTableModel->data(inspectP,Qt::DisplayRole).toInt();
    QModelIndex   ev= sizProxyTableModel->index(current.row(),MainSizModelHead::event);
    int  event= sizProxyTableModel->data(ev,Qt::DisplayRole).toInt();
    QModelIndex   daysToE= sizProxyTableModel->index(current.row(),MainSizModelHead::daysToEvent);
    int  daysToEvent= sizProxyTableModel->data(daysToE,Qt::DisplayRole).toInt();
    QDate nextOsmotr =inspectionDate.addMonths(inspectPediod);
    ui->selectedItemDateEdit->setDate(nextOsmotr);

    if(event == SizEvent::noEvent){
        ui->selectedItemDateEdit->show();
        ui->selectedItemOsmotrButton->hide();
        ui->selectedItemLabel->setText(QString("%1 \n осматривается раз в %2 мес. \n Следующий осмотр: ").arg(nameSiz,QString::number(inspectPediod)) );
    }
    if(event == SizEvent::inspectionSoon){
        ui->selectedItemDateEdit->show();
        ui->selectedItemOsmotrButton->show();
        ui->selectedItemLabel->setText(QString("Осмотр через %1 дн.\n %2 \n осматривается раз в %3 мес. \n Следующий осмотр: ").arg(QString::number(daysToEvent),nameSiz,QString::number(inspectPediod)) );
    }
    if(event == SizEvent::verificationSoon){
        ui->selectedItemDateEdit->hide();
        ui->selectedItemOsmotrButton->hide();
        ui->selectedItemLabel->setText(QString("На испытание через %1 дн.\n %2 \n осматривается раз в %3 мес. \n ").arg(QString::number(daysToEvent),nameSiz,QString::number(inspectPediod)) );
    }
    if(event == SizEvent::inspectionExpired){
        ui->selectedItemOsmotrButton->show();
        ui->selectedItemDateEdit->show();
        ui->selectedItemLabel->setText(QString("Просрочен осмотр на %1 дн.\n %2 \n осматривается раз в %3 мес. \n Следующий осмотр: ").arg(QString::number(daysToEvent),nameSiz,QString::number(inspectPediod)) );
    }
    if(event == SizEvent::verificationExpired){
        ui->selectedItemDateEdit->hide();
        ui->selectedItemOsmotrButton->hide();
        ui->selectedItemLabel->setText(QString("ИЗЪЯТЬ НА ИСПЫТАНИЕ %1 дн.\n %2 \n осматривается раз в %3 мес. \n Следующий осмотр: ").arg(QString::number(daysToEvent),nameSiz,QString::number(inspectPediod)) );
    }
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

        // sizProxyTableModel->dataChanged(osmotrIndex,osmotrIndex);
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
    ui->mainTableView->setItemDelegateForColumn(MainSizModelHead::endVerificationDate, deid);
    ui->mainTableView->setItemDelegateForColumn( MainSizModelHead::personalDate  , deid);
}
void MainSizWindow::on_addRowMainTable_clicked()
{
    // mainSizModel->submitAll();
    // mainSizModel->insertRow(1);

    sizProxyTableModel->insertRow(0);
    for (int i=0;i<sizProxyTableModel->rowCount();i++) {

        QModelIndex ind = sizProxyTableModel->index(i,5);
        if( sizProxyTableModel->data(ind,Qt::DisplayRole)=="") {
            QModelIndex nameSiz = sizProxyTableModel->index(i,MainSizModelHead::nameSiz);
            QModelIndex nameObj = sizProxyTableModel->index(i,MainSizModelHead::object);
            QModelIndex namePersona = sizProxyTableModel->index(i,MainSizModelHead::persona);

            sizProxyTableModel->setData(nameSiz,0);
            sizProxyTableModel->setData(nameObj,0);
            sizProxyTableModel->setData(namePersona,0);
            qDebug()<<ind;
            ui->mainTableView->selectRow(ind.row());
            return;
        }



    }
    sizProxyTableModel->setFilterFixedString("");
    for (int i=0;i<sizProxyTableModel->rowCount();i++) {

        QModelIndex ind = sizProxyTableModel->index(i,5);
        if( sizProxyTableModel->data(ind,Qt::DisplayRole)=="") {
            QModelIndex nameSiz = sizProxyTableModel->index(i,MainSizModelHead::nameSiz);
            QModelIndex nameObj = sizProxyTableModel->index(i,MainSizModelHead::object);
            QModelIndex namePersona = sizProxyTableModel->index(i,MainSizModelHead::persona);

            sizProxyTableModel->setData(nameSiz,0);
            sizProxyTableModel->setData(nameObj,0);
            sizProxyTableModel->setData(namePersona,0);
            qDebug()<<ind;
            ui->mainTableView->selectRow(ind.row());
            return;
        }



    }

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
            sizProxyTableModel->removeRows(indexes.at(1).row(),1);
            sizModel* mod =  (sizModel*) sizProxyTableModel->sourceModel();



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
    ui->listEventView->setStyleSheet("font: 14pt; selection-color: rgb(0, 0, 0); selection-background-color: rgb(232, 237, 240);");
    qApp->setStyleSheet("QWidget {  selection-color: rgb(0, 0, 0); selection-background-color: rgba(212, 217, 250,  250); }"
                        "QTableView{ font: 13pt; selection-background-color: rgba(212, 217, 250,  250);  }");


    QColor color = QColorDialog::getColor(Qt::yellow, this );
       if( color.isValid() )
       {
         qDebug() << "Color Choosen : " << color.name();
       }
}


void MainSizWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    //qDebug()<< current->text(0)<< current->parent();

}

void MainSizWindow::on_listEventView_doubleClicked(const QModelIndex &index)
{

    QModelIndex sourseIndex = eventProxyTableModel->mapToSource(index);
    QModelIndex mainTableIndex = sizProxyTableModel->mapFromSource(sourseIndex);
    qDebug()<<mainTableIndex.isValid();


    QModelIndex event = mainSizModel->index(sourseIndex.row(),MainSizModelHead::event);
    QString filter =mainSizModel->data(event,Qt::DisplayRole).toString();
    QRegExp reg;
    reg.setPattern("[12345]");
    sizProxyTableModel->setFilterRegExp(reg);
    sizProxyTableModel->setFilterKeyColumn(MainSizModelHead::event);
    mainTableIndex = sizProxyTableModel->mapFromSource(sourseIndex);
    ui->mainTableView->selectRow(mainTableIndex.row());
    ui->tabWidget->setCurrentIndex(0);


}

void MainSizWindow::on_pushButton_2_clicked()
{
    mainSizModel->submitAll();
}

void MainSizWindow::on_spinBox_valueChanged(int arg1)
{
    messageTimer->setInterval(arg1*60*1000);
}

void MainSizWindow::on_btn_export_csv_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
             tr("Сохранить таблицу СИЗ"), "",
             tr("Фаил CSV (*.csv);;All Files (*)"));
    if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Unable to open file"),
                    file.errorString());
                return;
            }

        db->expotrToCSV(&file);

    }

}
