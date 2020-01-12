#include "mainsizwindow.h"
#include <QApplication>
#include <QtSql>
#include <QTableView>
#include <QLockFile>
#include <QDir>
#include <QMessageBox>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QLockFile lockFile(QDir::temp().absoluteFilePath("lurity.lock"));
    if(!lockFile.tryLock(100)){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Приложение уже запущено.\n"
                       "Приложение свернуто в трее.");

        msgBox.exec();
        return 1;
    }

    MainSizWindow w;
    w.show();


    return a.exec();
}
