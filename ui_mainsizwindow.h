/********************************************************************************
** Form generated from reading UI file 'mainsizwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSIZWINDOW_H
#define UI_MAINSIZWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSizWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTreeWidget *treeWidget;
    QTableView *tableView;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QSpinBox *spinBox;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_2;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QTableView *personalTableView;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QTableView *typeSizTableView;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QTableView *objectTableView;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_9;

    void setupUi(QMainWindow *MainSizWindow)
    {
        if (MainSizWindow->objectName().isEmpty())
            MainSizWindow->setObjectName(QString::fromUtf8("MainSizWindow"));
        MainSizWindow->resize(1331, 833);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainSizWindow->sizePolicy().hasHeightForWidth());
        MainSizWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/128.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainSizWindow->setWindowIcon(icon);
        MainSizWindow->setAnimated(true);
        MainSizWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MainSizWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_7->addLayout(horizontalLayout_4);

        treeWidget = new QTreeWidget(tab);
        treeWidget->headerItem()->setText(0, QString());
        QFont font;
        font.setPointSize(14);
        QFont font1;
        font1.setPointSize(13);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setFont(0, font1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setFont(0, font);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setFont(0, font);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);
        treeWidget->setProperty("showDropIndicator", QVariant(false));
        treeWidget->setIconSize(QSize(20, 20));
        treeWidget->setWordWrap(false);
        treeWidget->setHeaderHidden(true);
        treeWidget->header()->setVisible(false);

        verticalLayout_7->addWidget(treeWidget);


        horizontalLayout->addLayout(verticalLayout_7);

        tableView = new QTableView(tab);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        QPalette palette;
        QBrush brush(QColor(48, 140, 198, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        QBrush brush1(QColor(145, 145, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        tableView->setPalette(palette);
        tableView->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(tableView);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout = new QVBoxLayout(tab_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(tab_4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_9->addWidget(label);

        spinBox = new QSpinBox(tab_4);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(20);

        horizontalLayout_9->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_9);

        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_2 = new QHBoxLayout(tab_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolBox = new QToolBox(tab_3);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setLayoutDirection(Qt::LeftToRight);
        toolBox->setAutoFillBackground(false);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 1291, 673));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(page);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        personalTableView = new QTableView(page);
        personalTableView->setObjectName(QString::fromUtf8("personalTableView"));
        personalTableView->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(personalTableView);

        toolBox->addItem(page, QString::fromUtf8("\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 1291, 673));
        verticalLayout_5 = new QVBoxLayout(page_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_8 = new QPushButton(page_3);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_8->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(page_3);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_8->addWidget(pushButton_7);


        verticalLayout_5->addLayout(horizontalLayout_8);

        typeSizTableView = new QTableView(page_3);
        typeSizTableView->setObjectName(QString::fromUtf8("typeSizTableView"));

        verticalLayout_5->addWidget(typeSizTableView);

        toolBox->addItem(page_3, QString::fromUtf8("\320\222\320\270\320\264\321\213 \320\241\320\230\320\227"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 1291, 673));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_7->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_7->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout_7);

        objectTableView = new QTableView(page_2);
        objectTableView->setObjectName(QString::fromUtf8("objectTableView"));

        verticalLayout_4->addWidget(objectTableView);

        toolBox->addItem(page_2, QString::fromUtf8("\320\236\320\261\321\212\320\265\320\272\321\202\321\213"));

        horizontalLayout_2->addWidget(toolBox);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout_2->addWidget(pushButton_9);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);

        MainSizWindow->setCentralWidget(centralWidget);

        retranslateUi(MainSizWindow);

        tabWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainSizWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainSizWindow)
    {
        MainSizWindow->setWindowTitle(QCoreApplication::translate("MainSizWindow", " \320\226\321\203\321\200\320\275\320\260\320\273 \320\241\320\230\320\227", nullptr));
        pushButton->setText(QCoreApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainSizWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainSizWindow", "\320\235\320\276\320\262\321\213\320\271 \320\264\320\276\321\207\320\265\321\200\320\275\320\270\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainSizWindow", "\320\242\320\270\320\277\321\213 \320\241\320\230\320\227", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainSizWindow", "\320\237\320\265\321\200\321\201\320\276\320\275\320\260\320\273", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainSizWindow", "\320\226\321\203\321\200\320\275\320\260\320\273", nullptr));
        label->setText(QCoreApplication::translate("MainSizWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\264\320\275\320\265\320\271 \320\264\320\276 \320\275\320\260\320\277\320\276\320\274\320\270\320\275\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainSizWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainSizWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainSizWindow", "\320\222\320\270\320\264\321\213 \320\241\320\230\320\227", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainSizWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainSizWindow", "\320\237\320\265\321\200\320\265\321\207\320\275\320\270", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainSizWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\203\320\262\320\265\320\264\320\264\320\276\320\262\320\273\320\265\320\275\320\270\320\265 [Test]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainSizWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSizWindow: public Ui_MainSizWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSIZWINDOW_H
