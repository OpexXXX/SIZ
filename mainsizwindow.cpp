#include "mainsizwindow.h"
#include "ui_mainsizwindow.h"
#include <QSqlRecord>
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



 /*   this->setupModel(SIZTABLE,
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
              );*/
    sizTableModel = new QSqlTableModel(this);
    sizTableModel->setTable(SIZTABLE);
    sizTableModel->select();

        for (int i = 0; i < sizTableModel->rowCount(); ++i) {
            QString name = sizTableModel->record(i).value("number").toString();
            int salary = sizTableModel->record(i).value("verification").toInt();
            qDebug() << name << salary;
        }

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
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    sizTableModel->select(); // Делаем выборку данных из таблицы
}
