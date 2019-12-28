#include "mainsizwindow.h"
#include <QApplication>
#include <QtSql>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainSizWindow w;
    w.show();


    return a.exec();
}
