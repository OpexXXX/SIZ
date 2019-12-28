#include "mainsizwindow.h"
#include "ui_mainsizwindow.h"

MainSizWindow::MainSizWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSizWindow)
{
    ui->setupUi(this);
}

MainSizWindow::~MainSizWindow()
{
    delete ui;
}
