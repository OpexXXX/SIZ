/********************************************************************************
** Form generated from reading UI file 'mainsizwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSIZWINDOW_H
#define UI_MAINSIZWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_2;
    QTableView *tableView_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QPlainTextEdit *plainTextEdit;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_9;
    QButtonGroup *buttonGroup;

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
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, -1, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_3->addWidget(pushButton_4);


        verticalLayout_3->addLayout(horizontalLayout_3);

        radioButton_3 = new QRadioButton(tab_3);
        buttonGroup = new QButtonGroup(MainSizWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setChecked(true);

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(tab_3);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        radioButton = new QRadioButton(tab_3);
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout_3->addWidget(radioButton);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_4->addWidget(label_2);

        verticalLayout_4->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_3);

        tableView_2 = new QTableView(tab_3);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        horizontalLayout_2->addWidget(tableView_2);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_5->addWidget(plainTextEdit);

        spinBox_2 = new QSpinBox(tab_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(20000);
        spinBox_2->setSingleStep(1000);
        spinBox_2->setValue(1000);

        verticalLayout_5->addWidget(spinBox_2);

        pushButton_9 = new QPushButton(tab_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout_5->addWidget(pushButton_9);


        verticalLayout_2->addLayout(verticalLayout_5);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);

        MainSizWindow->setCentralWidget(centralWidget);

        retranslateUi(MainSizWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainSizWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainSizWindow)
    {
        MainSizWindow->setWindowTitle(QApplication::translate("MainSizWindow", " \320\226\321\203\321\200\320\275\320\260\320\273 \320\241\320\230\320\227", nullptr));
        pushButton->setText(QApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_2->setText(QApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("MainSizWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainSizWindow", "\320\235\320\276\320\262\321\213\320\271 \320\264\320\276\321\207\320\265\321\200\320\275\320\270\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainSizWindow", "\320\242\320\270\320\277\321\213 \320\241\320\230\320\227", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainSizWindow", "\320\237\320\265\321\200\321\201\320\276\320\275\320\260\320\273", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainSizWindow", "\320\226\321\203\321\200\320\275\320\260\320\273", nullptr));
        label->setText(QApplication::translate("MainSizWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\264\320\275\320\265\320\271 \320\264\320\276 \320\275\320\260\320\277\320\276\320\274\320\270\320\275\320\260\320\275\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainSizWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
        pushButton_3->setText(QApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        pushButton_4->setText(QApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        radioButton_3->setText(QApplication::translate("MainSizWindow", "\320\222\320\270\320\264\321\213 \321\201\321\200\320\265\320\264\321\201\321\202\320\262 \320\267\320\260\321\211\320\270\321\202\321\213", nullptr));
        radioButton_2->setText(QApplication::translate("MainSizWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        radioButton->setText(QApplication::translate("MainSizWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainSizWindow", "\320\237\320\265\321\200\320\265\321\207\320\275\320\270", nullptr));
        plainTextEdit->setPlainText(QString());
        pushButton_9->setText(QApplication::translate("MainSizWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\203\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\320\265 [Test]", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainSizWindow", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSizWindow: public Ui_MainSizWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSIZWINDOW_H
