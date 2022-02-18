/********************************************************************************
** Form generated from reading UI file 'mainsizwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSIZWINDOW_H
#define UI_MAINSIZWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
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
    QPushButton *btn_export_csv;
    QTreeWidget *treeWidget;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addRowMainTable;
    QPushButton *deleteRowMainTable;
    QPushButton *selectedItemOsmotrButton;
    QLabel *selectedItemLabel;
    QDateEdit *selectedItemDateEdit;
    QVBoxLayout *verticalLayout_8;
    QTableView *mainTableView;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout;
    QListView *listEventView;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addRowPerechniTable;
    QPushButton *deleteRowPerechniTable;
    QTableView *perechenTableView;
    QWidget *tab_2;
    QFormLayout *formLayout;
    QSpinBox *daysOfEvent;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
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

        verticalLayout_7->addLayout(horizontalLayout_4);

        btn_export_csv = new QPushButton(tab);
        btn_export_csv->setObjectName(QString::fromUtf8("btn_export_csv"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/csv.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_export_csv->setIcon(icon1);
        btn_export_csv->setIconSize(QSize(32, 32));

        verticalLayout_7->addWidget(btn_export_csv);

        treeWidget = new QTreeWidget(tab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy1);
        treeWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        treeWidget->setProperty("showDropIndicator", QVariant(false));
        treeWidget->setIconSize(QSize(20, 20));
        treeWidget->setWordWrap(false);
        treeWidget->setHeaderHidden(true);
        treeWidget->header()->setVisible(false);

        verticalLayout_7->addWidget(treeWidget);

        gridGroupBox = new QGroupBox(tab);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 1, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 10, -1, -1);
        addRowMainTable = new QPushButton(gridGroupBox);
        addRowMainTable->setObjectName(QString::fromUtf8("addRowMainTable"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addRowMainTable->setIcon(icon2);
        addRowMainTable->setIconSize(QSize(32, 32));
        addRowMainTable->setCheckable(false);
        addRowMainTable->setChecked(false);
        addRowMainTable->setAutoDefault(false);
        addRowMainTable->setFlat(false);

        horizontalLayout_5->addWidget(addRowMainTable);

        deleteRowMainTable = new QPushButton(gridGroupBox);
        deleteRowMainTable->setObjectName(QString::fromUtf8("deleteRowMainTable"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icon/remove-trash.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteRowMainTable->setIcon(icon3);
        deleteRowMainTable->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(deleteRowMainTable);


        gridLayout->addLayout(horizontalLayout_5, 6, 0, 1, 1);

        selectedItemOsmotrButton = new QPushButton(gridGroupBox);
        selectedItemOsmotrButton->setObjectName(QString::fromUtf8("selectedItemOsmotrButton"));

        gridLayout->addWidget(selectedItemOsmotrButton, 2, 0, 1, 1);

        selectedItemLabel = new QLabel(gridGroupBox);
        selectedItemLabel->setObjectName(QString::fromUtf8("selectedItemLabel"));
        selectedItemLabel->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectedItemLabel->sizePolicy().hasHeightForWidth());
        selectedItemLabel->setSizePolicy(sizePolicy2);
        selectedItemLabel->setMaximumSize(QSize(230, 16777215));
        selectedItemLabel->setWordWrap(true);

        gridLayout->addWidget(selectedItemLabel, 0, 0, 1, 1);

        selectedItemDateEdit = new QDateEdit(gridGroupBox);
        selectedItemDateEdit->setObjectName(QString::fromUtf8("selectedItemDateEdit"));
        selectedItemDateEdit->setMaximumDateTime(QDateTime(QDate(2030, 12, 31), QTime(23, 59, 59)));
        selectedItemDateEdit->setMinimumDate(QDate(2014, 1, 1));
        selectedItemDateEdit->setCalendarPopup(true);

        gridLayout->addWidget(selectedItemDateEdit, 1, 0, 1, 1);


        verticalLayout_7->addWidget(gridGroupBox);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, -1, 5, -1);
        mainTableView = new QTableView(tab);
        mainTableView->setObjectName(QString::fromUtf8("mainTableView"));
        QPalette palette;
        QBrush brush(QColor(48, 140, 198, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        QBrush brush1(QColor(145, 145, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        mainTableView->setPalette(palette);
        mainTableView->setStyleSheet(QString::fromUtf8(""));
        mainTableView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);

        verticalLayout_8->addWidget(mainTableView);

        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMaximumSize(QSize(16777215, 15));
        pushButton_5->setCheckable(true);
        pushButton_5->setChecked(false);

        verticalLayout_8->addWidget(pushButton_5);

        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setEnabled(true);

        verticalLayout_8->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout_8);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout = new QVBoxLayout(tab_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listEventView = new QListView(tab_4);
        listEventView->setObjectName(QString::fromUtf8("listEventView"));
        listEventView->setStyleSheet(QString::fromUtf8(""));
        listEventView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listEventView);

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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(-1, 0, -1, -1);
        addRowPerechniTable = new QPushButton(tab_3);
        addRowPerechniTable->setObjectName(QString::fromUtf8("addRowPerechniTable"));
        addRowPerechniTable->setIcon(icon2);
        addRowPerechniTable->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(addRowPerechniTable);

        deleteRowPerechniTable = new QPushButton(tab_3);
        deleteRowPerechniTable->setObjectName(QString::fromUtf8("deleteRowPerechniTable"));
        deleteRowPerechniTable->setIcon(icon3);
        deleteRowPerechniTable->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(deleteRowPerechniTable);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout_4->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout_3);

        perechenTableView = new QTableView(tab_3);
        perechenTableView->setObjectName(QString::fromUtf8("perechenTableView"));
        perechenTableView->verticalHeader()->setVisible(false);

        horizontalLayout_2->addWidget(perechenTableView);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        formLayout = new QFormLayout(tab_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        daysOfEvent = new QSpinBox(tab_2);
        daysOfEvent->setObjectName(QString::fromUtf8("daysOfEvent"));
        daysOfEvent->setValue(20);

        formLayout->setWidget(0, QFormLayout::LabelRole, daysOfEvent);

        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMaximumSize(QSize(250, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, label);

        spinBox = new QSpinBox(tab_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(360);
        spinBox->setSingleStep(10);

        formLayout->setWidget(2, QFormLayout::LabelRole, spinBox);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_4);

        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFrame(false);
        lineEdit->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(4, QFormLayout::LabelRole, pushButton);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, pushButton_3);

        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, pushButton_4);

        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        formLayout->setWidget(7, QFormLayout::LabelRole, pushButton_6);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFrame(false);
        lineEdit_2->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setFrame(false);
        lineEdit_3->setReadOnly(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setFrame(false);
        lineEdit_4->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_4);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);

        MainSizWindow->setCentralWidget(centralWidget);

        retranslateUi(MainSizWindow);

        tabWidget->setCurrentIndex(0);
        addRowMainTable->setDefault(false);


        QMetaObject::connectSlotsByName(MainSizWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainSizWindow)
    {
        MainSizWindow->setWindowTitle(QCoreApplication::translate("MainSizWindow", " \320\226\321\203\321\200\320\275\320\260\320\273 \320\241\320\230\320\227", nullptr));
        btn_export_csv->setText(QCoreApplication::translate("MainSizWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202 -> CSV", nullptr));
        gridGroupBox->setTitle(QCoreApplication::translate("MainSizWindow", "\320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        addRowMainTable->setText(QCoreApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 ", nullptr));
        deleteRowMainTable->setText(QCoreApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 ", nullptr));
        selectedItemOsmotrButton->setText(QCoreApplication::translate("MainSizWindow", "\320\236\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214", nullptr));
        selectedItemLabel->setText(QCoreApplication::translate("MainSizWindow", "123", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainSizWindow", "^^^^^^^^^^^^^^^^", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainSizWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<h2 style=\" margin-top:16px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600;\">\320\232\320\273\320\265\321\211\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265, \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\321\213 \321\202\320\276\320\272\320\260</span></h2>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style"
                        "=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600;\">\320\235\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\232\320\273\320\265\321\211\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\270\320\273\320\270 \320\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\321\213 \321\202\320\276\320\272\320\260 \320\277\321\200\320\265\320\264\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\321\213 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217 \321\202\320\276\320\272\320\260 \320\262 \321\215\320\273\320\265\320\272\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\321\205"
                        " \321\206\320\265\320\277\321\217\321\205 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265\320\274 \320\264\320\276 10 \320\272\320\222, \320\260 \321\202\320\260\320\272\320\266\320\265 \321\202\320\276\320\272\320\260, \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217 \320\270 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\320\270 \320\262 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260\321\205 \320\264\320\276 1 \320\272\320\222 \320\261\320\265\320\267 \320\275\320\260\321\200\321\203\321\210\320\265\320\275\320\270\321\217 \321\206\320\265\320\273\320\276\321\201\321\202\320\275\320\276\321\201\321\202\320\270 \321\206\320\265\320\277\320\265\320\271. \320\232\320\273\320\265\321\211\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 (\320"
                        "\270\320\275\320\264\320\270\320\272\320\260\321\202\320\276\321\200\321\213 \321\202\320\276\320\272\320\260) \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\321\217\321\216\321\202 \321\201\320\276\320\261\320\276\320\271 \321\202\321\200\320\260\320\275\321\201\321\204\320\276\321\200\320\274\320\260\321\202\320\276\321\200 \321\202\320\276\320\272\320\260 \321\201 \321\200\320\260\320\267\321\212\320\265\320\274\320\275\321\213\320\274 \320\274\320\260\320\263\320\275\320\270\321\202\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\276\320\274, \320\277\320\265\321\200\320\262\320\270\321\207\320\275\320\276\320\271 \320\276\320\261\320\274\320\276\321\202\320\272\320\276\320\271 \320\272\320\276\321\202\320\276\321\200\320\276\320\263\320\276 \321\217\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272 \321\201 \320\270\320\267\320\274\320\265\321\200\321\217\320\265\320\274\321\213\320\274 \321"
                        "\202\320\276\320\272\320\276\320\274, \320\260 \320\262\321\202\320\276\321\200\320\270\321\207\320\275\320\260\321\217 \320\276\320\261\320\274\320\276\321\202\320\272\320\260 \320\267\320\260\320\274\320\272\320\275\321\203\321\202\320\260 \320\275\320\260 \320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\270\320\261\320\276\321\200, \321\201\321\202\321\200\320\265\320\273\320\276\321\207\320\275\321\213\320\271 \320\270\320\273\320\270 \321\206\320\270\321\204\321\200\320\276\320\262\320\276\320\271.</span></p>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600;\">\320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\202\321\200\320\265\320\261\320\276\320\262\320\260\320\275\320\270\321\217</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom"
                        ":12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\232\320\273\320\265\321\211\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \321\215\320\272\321\201\320\277\320\273\321\203\320\260\321\202\320\270\321\200\321\203\321\216\321\202\321\201\321\217 \320\277\321\200\320\270 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\321\205 \320\272\320\273\320\270\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\204\320\260\320\272\321\202\320\276\321\200\320\260\321\205 \320\262\320\275\320\265\321\210\320\275\320\265\320\271 \321\201\321\200\320\265\320\264\321\213 (\320\2431.1):</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" "
                        "margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\276\320\272\321\200\321\203\320\266\320\260\321\216\321\211\320\265\320\263\320\276 \320\262\320\276\320\267\320\264\321\203\321\205\320\260: \320\276\321\202 \320\274\320\270\320\275\321\203\321\201 45 \302\260\320\241 \320\264\320\276 \320\277\320\273\321\216\321\201 45 \302\260\320\241;</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\262\320\273\320\260\320\266\320\275\320\276\321\201\321\202\321\214 \320\262\320\276\320\267\320\264\321\203\321\205\320\260: \320\264\320\276 98 % \320\277\321\200\320\270 25 \302\260\320\241;</li>\n"
"<li style=\" font-family:'Ubuntu'; fo"
                        "nt-size:11pt;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\260\321\202\320\274\320\276\321\201\321\204\320\265\321\200\320\275\320\276\320\265 \320\264\320\260\320\262\320\273\320\265\320\275\320\270\320\265: 70-106,7 \320\272\320\237\320\260 (537\342\200\223800 \320\274\320\274. \321\200\321\202. \321\201\321\202.).</li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272\320\273\320\265\321\211\320\270 \320\264\320\273\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\276\320\272 \320\262\321\213\321\210\320\265 1000 \320\222 \321\201\320\276\321\201\321\202"
                        "\320\276\321\217\321\202 \320\270\320\267 \321\200\320\260\320\261\320\276\321\207\320\265\320\271, \320\270\320\267\320\276\320\273\320\270\321\200\321\203\321\216\321\211\320\265\320\271 \321\207\320\260\321\201\321\202\320\265\320\271 \320\270 \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\270. \320\240\320\260\320\261\320\276\321\207\320\260\321\217 \321\207\320\260\321\201\321\202\321\214 \321\201\320\276\321\201\321\202\320\276\320\270\321\202 \320\270\320\267 \320\274\320\260\320\263\320\275\320\270\321\202\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\260, \320\276\320\261\320\274\320\276\321\202\320\272\320\270 \320\270 \321\201\321\212\320\265\320\274\320\275\320\276\320\263\320\276 \320\270\320\273\320\270 \320\262\321\201\321\202\321\200\320\276\320\265\320\275\320\275\320\276\320\263\320\276 \320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\263\320\276 \320\277\321\200\320\270\320\261\320\276\321\200\320\260, \320\262\321"
                        "\213\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\263\320\276 \320\262 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\276\320\273\321\217\321\206\320\270\320\276\320\275\320\275\320\276\320\274 \320\272\320\276\321\200\320\277\321\203\321\201\320\265. \320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \320\264\320\273\320\270\320\275\320\260 \320\270\320\267\320\276\320\273\320\270\321\200\321\203\321\216\321\211\320\265\320\271 \321\207\320\260\321\201\321\202\320\270 \342\200\223 380 \320\274\320\274, \320\260 \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\270 \342\200\223 130 \320\274\320\274. \320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272\320\273\320\265\321\211\320\270 \320\264\320\273\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\203\321\201\321\202\320\260\320"
                        "\275\320\276\320\262\320\276\320\272 \320\264\320\276 1000 \320\222 \321\201\320\276\321\201\321\202\320\276\321\217\321\202 \320\270\320\267 \321\200\320\260\320\261\320\276\321\207\320\265\320\271 \321\207\320\260\321\201\321\202\320\270 (\320\274\320\260\320\263\320\275\320\270\321\202\320\276\320\277\321\200\320\276\320\262\320\276\320\264, \320\276\320\261\320\274\320\276\321\202\320\272\320\260, \320\262\321\201\321\202\321\200\320\276\320\265\320\275\320\275\321\213\320\271 \320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\321\200\320\270\320\261\320\276\321\200) \320\270 \320\272\320\276\321\200\320\277\321\203\321\201\320\260, \321\217\320\262\320\273\321\217\321\216\321\211\320\265\320\263\320\276\321\201\321\217 \320\276\320\264\320\275\320\276\320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276 \320\270\320\267\320\276\320\273\320\270\321\200\321\203\321\216\321\211\320\265\320\271 \321\207\320\260\321\201\321\202\321\214\321"
                        "\216 \321\201 \321\203\320\277\320\276\321\200\320\276\320\274 \320\270 \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\276\320\271. \320\242\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\270 \320\274\320\265\321\202\321\200\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \320\277\321\200\320\270\320\262\320\265\320\264\320\265\320\275\321\213 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265 4.</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320"
                        "\242\320\260\320\261\320\273\320\270\321\206\320\260 4. \320\245\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271</span></p>\n"
"<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\">\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\342\204\226 \320\277/\320\277</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\245\320\260\321\200\320\260\320\272\321\202\320\265"
                        "\321\200\320\270\321\201\321\202\320\270\320\272\320\260,\302\240</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\265\320\264\320\270\320\275\320\270\321\206\320\260 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\321\217</span></p></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; marg"
                        "in-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">1.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\235\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\201\320\270\320\273\321\213 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\276\320\272\320\260, I\320\275\320\276\320\274, \320\220</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">30; 300; 3000</span></p></td>\n"
"<td></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">2.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\224\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\271 \321\201\320\270\320\273\321\213 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\263\320\276 \321\202\320\276\320\272\320\260 (\321\201\321\200\320\265\320\264\320\275\320\265\320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265), \320\276\321\202 \320\275\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\267\320\275\320\260\321\207\320\265\320\275"
                        "\320\270\321\217, %</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">10\342\200\246150</span></p></td>\n"
"<td></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">3.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\237\320\276\320\273\320\276\321\201\320\260 \320\277\321\200\320\276\320\277\321\203\321\201\320\272\320\260\320\275\320\270\321\217, \320\223\321\206</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:"
                        "'Ubuntu'; font-size:11pt;\">47,5\303\26752,5</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\237\321\200\320\270 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\274 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\265 \321\203\321\201\320\270\320\273\320\265\320\275\320\270\321\217 &gt; \342\200\2233 \320\264\320\221</span></p></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">4.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\235\320\276"
                        "\320\274\320\270\320\275\320\260\320\273\321\214\320\275\320\276\320\265 \320\262\321\213\321\205\320\276\320\264\320\275\320\276\320\265 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265, \320\222</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">0,3\302\26110%</span></p></td>\n"
"<td></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">5.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\270\320\274\320\277\320\265\320\264"
                        "\320\260\320\275\321\201 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\275\320\260 \320\262\321\213\321\205\320\276\320\264\320\265, \320\272\320\236\320\274</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">10</span></p></td>\n"
"<td></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">6.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\243\320\263\320\273\320\276\320\262\320\260\321\217 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214, %</span></p></td>\n"
"<td>\n"
"<p style=\""
                        " margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\26110</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">0,1I\320\275 \342\211\244 I \342\211\244 1,5I\320\275 \320\277\321\200\320\270 47\303\26753 \320\223\321\206</span></p></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">7.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320"
                        "\260\321\217 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214 \320\276\321\202 \320\262\320\273\320\270\321\217\320\275\320\270\321\217 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\320\260, %</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\2611,5\302\240</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\274\320\265\320\266\320\264\321\203 \320\272"
                        "\320\260\320\261\320\265\320\273\320\265\320\274 \320\270 \320\267\320\260\321\202\320\262\320\276\321\200\320\276\320\274 \320\272\320\273\320\265\321\211\320\265\320\271 \320\261\320\276\320\273\320\265\320\265 25 \320\274\320\274</span></p></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">8.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\242\320\276\320\272\320\276\320\262\320\260\321\217 \320\276\321\201\320\275\320\276\320\262\320\275\320\260\321\217 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214, %</span></p></td>\n"
"<td>\n"
"<p style=\" m"
                        "argin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\2611,5\302\240</span></p></td>\n"
"<td></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">9.</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\320\260\321\217 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214 \320\276\321\202 \320\262\320\273\320\270\321\217\320\275\320\270\321\217 \321\202\320\265"
                        "\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\321\213, %</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\2610,02\302\240</span></p></td>\n"
"<td></td></tr></table>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272\320\273\320\265\321\211\320\270 \320\276\320\261\320\265\321\201\320\277\320\265\321\207\320\270\320\262\320\260\321\216\321\202 \321\202\320\265\321\205\320\275\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320"
                        "\270 \320\262 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\270 \321\201 \321\202\320\260\320\261\320\273\320\270\321\206\320\265\320\271 4 \320\277\320\276 \320\270\321\201\321\202\320\265\321\207\320\265\320\275\320\270\320\270 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217 \321\200\320\260\320\261\320\276\321\207\320\265\320\263\320\276 \321\200\320\265\320\266\320\270\320\274\320\260 \320\275\320\265 \320\274\320\265\320\275\320\265\320\265 1 \320\274\320\270\320\275.</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320"
                        "\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272\320\273\320\265\321\211\320\270 \320\264\320\276\320\273\320\266\320\275\321\213 \320\270\320\274\320\265\321\202\321\214 \320\264\320\265\320\271\321\201\321\202\320\262\321\203\321\216\321\211\320\265\320\265 \321\201\320\262\320\270\320\264\320\265\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276 \320\276\320\261 \321\203\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\320\270 \321\202\320\270\320\277\320\260 \321\201\321\200\320\265\320\264\321\201\321\202\320\262 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\271 \320\270 \320\270\320\274\320\265\321\202\321\214 \320\275\320\276\320\274\320\265\321\200 \320\262 \320\223\320\276\321\201\321\203\320\264\320\260\321\200\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\274 \321\200\320\265\320\265\321\201\321\202\321\200\320\265 \321\201\321\200\320\265\320\264\321\201\321\202\320\262 \320\270\320\267\320\274\320\265\321"
                        "\200\320\265\320\275\320\270\320\271.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272\320\273\320\265\321\211\320\270 \320\264\320\276\320\273\320\266\320\275\321\213 \320\270\320\267\320\263\320\276\321\202\320\260\320\262\320\273\320\270\320\262\320\260\321\202\321\214\321\201\321\217 \320\262 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\270 \321\201 \321\202\321\200\320\265\320\261\320\276\320\262\320\260\320\275\320\270\321\217\320\274\320\270 \320\223\320\236\320\241\320\242 IEC 61010-2-032 \320\270 \320\223\320\236\320\241\320\242 22261.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; ma"
                        "rgin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\321\213\320\271 \321\202\320\276\320\272, \320\272\320\276\320\275\320\265\321\207\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\275\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\321\213\321\205 \320\276\320\261\320\273\320\260\321\201\321\202\320\265\320\271 \321\202\320\276\320\272\320\276\320\262, \320\275\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\321\213\320\271 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\320\270 \320\270 \320\272\320\276\320\275\320\265\321\207\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\320\265\320\271 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321"
                        "\202\320\276\320\262 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271, \320\277\321\200\320\265\320\264\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\213\321\205 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\320\270 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242 8476 (\320\234\320\255\320\232 51-3-84).</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\321\213\320\271 \321\202\320\276\320\272 \321\215\320\273\320\265\320\272\321\202\321\200"
                        "\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271, \320\277\321\200\320\265\320\264\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\275\321\213\321\205 \320\264\320\273\321\217 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217 \320\272\320\276\321\215\321\204\321\204\320\270\321\206\320\270\320\265\320\275\321\202\320\276\320\262 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\320\270 \320\277\320\276 \320\223\320\236\320\241\320\242 8039 (\320\234\320\255\320\232 51-5). \320\235\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\320\276\320\265 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \320\264"
                        "\320\276\320\273\320\266\320\275\320\276 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\276\320\262\320\260\321\202\321\214 \320\275\320\276\320\274\320\270\320\275\320\260\320\273\321\214\320\275\320\276\320\274\321\203 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\216 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217 \321\201\320\265\321\202\320\270.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\276\320\275\320\265\321\207\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\276\320\262 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\271 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320"
                        "\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242 8711 (\320\234\320\255\320\232 51-2-84), \320\223\320\236\320\241\320\242 8476, \320\223\320\236\320\241\320\242 8039.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\246\320\265\320\275\320\260 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \321\200\320\260\320\262\320\275\320\276\320\274\320\265\321\200\320\275\320\276\320\271 \321\210\320\272\320\260\320\273\321\213 \320\270 \320\274\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\206\320\265\320\275\320\260 \320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\275\320\265\321\200\320\260\320\262\320\275\320\276\320\274\320\265\321\200\320\275\320\276\320\271 \321\210\320\272\320\260\320\273\321\213 \321\215\320\273\320\265"
                        "\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242 8711, \320\223\320\236\320\241\320\242\302\2408476, \320\223\320\236\320\241\320\242 8039.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\265\320\264\320\265\320\273\321\213 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\320\274\321\213\321\205 \320\276\321\201\320\275\320\276\320\262\320\275\321\213\321\205 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\265\320\271 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320"
                        "\265\320\271, \321\201\320\277\320\276\321\201\320\276\320\261\321\213 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\265\320\264\320\265\320\273\320\276\320\262 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\320\274\321\213\321\205 \320\276\321\201\320\275\320\276\320\262\320\275\321\213\321\205 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\265\320\271 - \320\277\320\276 \320\223\320\236\320\241\320\242 8711, \320\223\320\236\320\241\320\242 8476, \320\223\320\236\320\241\320\242 8039.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\321\201\321\202\320\260\321\202\320\276\321\207\320\275\320\276\320\265 \320\276\321\202\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217 \321\215\320\273"
                        "\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \320\276\321\202 \320\275\321\203\320\273\320\265\320\262\320\276\320\271 \320\276\321\202\320\274\320\265\321\202\320\272\320\270 (\320\275\320\265\320\262\320\276\320\267\320\262\321\200\320\260\321\211\320\265\320\275\320\270\320\265 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217 \320\277\321\200\320\270\320\261\320\276\321\200\320\276\320\262 \320\272 \320\275\321\203\320\273\320\265\320\262\320\276\320\271 \320\276\321\202\320\274\320\265\321\202\320\272\320\265) \320\277\321\200\320\270 \320\277\320\273\320\260\320\262\320\275\320\276\320\274 \320\277\320\276\320\264\320\262\320\276\320\264\320\265 \321\203\320\272\320\260\320\267\320\260\321\202\320\265\320\273\321\217 \320\272 \321\215\321\202\320\276\320\271 \320\276\321\202\320\274\320\265\321\202\320\272\320\265 \320\276\321\202 \320"
                        "\275\320\260\320\270\320\261\320\276\320\273\320\265\320\265 \321\203\320\264\320\260\320\273\320\265\320\275\320\275\320\276\320\271 \320\276\321\202 \320\275\320\265\320\265 \320\276\321\202\320\274\320\265\321\202\320\272\320\270 \321\210\320\272\320\260\320\273\321\213, \320\262\321\200\320\265\320\274\321\217 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\270\321\217 \320\277\320\276\320\272\320\260\320\267\320\260\320\275\320\270\320\271 - \320\277\320\276 \320\223\320\236\320\241\320\242 8711, \320\223\320\236\320\241\320\242 8476, \320\223\320\236\320\241\320\242 8039.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\265\320\264\320\265\320\273\321\213 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\320\274\321\213\321\205 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273"
                        "\321\214\320\275\321\213\321\205 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\265\320\271 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271, \320\262\321\213\320\267\320\262\320\260\320\275\320\275\321\213\321\205 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217\320\274\320\270 \320\262\320\275\320\265\321\210\320\275\320\270\321\205 \320\262\320\273\320\270\321\217\321\216\321\211\320\270\321\205 \320\262\320\265\320\273\320\270\321\207\320\270\320\275 \320\276\321\202 \320\275\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271, \320\262 \320\277\321\200\320\265\320\264\320\265\320\273\320\260\321\205, \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\275\321\213\321\205"
                        " \321\200\320\260\320\261\320\276\321\207\320\270\320\274\320\270 \321\203\321\201\320\273\320\276\320\262\320\270\321\217\320\274\320\270 \320\277\321\200\320\270\320\274\320\265\320\275\320\265\320\275\320\270\321\217, \320\264\320\276\320\273\320\266\320\275\321\213 \321\203\321\201\321\202\320\260\320\275\320\260\320\262\320\273\320\270\320\262\320\260\321\202\321\214\321\201\321\217 \320\262 \320\262\320\270\320\264\320\265 \320\277\321\200\320\270\320\262\320\265\320\264\320\265\320\275\320\275\321\213\321\205 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\265\320\271. \320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\262\320\273\320\270\321\217\321\216\321\211\320\270\321\205 \320\262\320\265\320\273\320\270\321\207\320\270\320\275 \321\201\320\273\320\265\320\264\321\203\320\265\321\202 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\217\321\202\321\214"
                        " \320\262 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\270 \321\201 \320\223\320\236\320\241\320\242 22261, \320\223\320\236\320\241\320\242 8711, \320\223\320\236\320\241\320\242 8476 \320\270 \320\223\320\236\320\241\320\242 8039 \320\277\321\200\320\270 \320\270\321\201\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\270 \320\262\320\273\320\270\321\217\320\275\320\270\321\217 \321\200\321\217\320\264\320\276\320\274 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\275\320\276\320\263\320\276 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\320\260 \320\270 \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\320\260 \320\262 \320\263\320\265\320\276\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\271 \321\201\320\265\321\200\320\265\320\264\320\270\320\275\320\265"
                        " \320\276\320\272\320\275\320\260 \320\274\320\260\320\263\320\275\320\270\321\202\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\260. \320\240\320\260\320\261\320\276\321\207\320\270\320\265 \321\203\321\201\320\273\320\276\320\262\320\270\321\217 \320\277\321\200\320\270\320\274\320\265\320\275\320\265\320\275\320\270\321\217: \320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\320\260 \320\262 \320\276\320\272\320\275\320\265 \320\274\320\260\320\263\320\275\320\270\321\202\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\260 \342\200\223 \320\273\321\216\320\261\320\276\320\265; \320\262 \321\207\320\260\321\201\321\202\320\270 \320\272\320\273\320\270\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \320\270 \320\274\320\265\321\205\320\260\320\275\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \320\262\320\276\320\267\320\264\320\265\320\271\321\201"
                        "\321\202\320\262\320\270\320\271 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242 22261.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\265\320\264\320\265\320\273 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\320\274\320\276\320\271 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\271 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271, \320\262\321\213\320\267\320\262\320\260\320\275\320\275\320\276\320\271 \320\262\320\273\320\270\321\217\320\275\320\270\320\265\320\274 \321\200\321\217\320\264\320\276\320\274 \321\200\320"
                        "\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\275\320\276\320\263\320\276 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\320\260 \321\201 \321\202\320\276\320\272\320\276\320\274, \320\275\320\260\321\205\320\276\320\264\321\217\321\211\320\265\320\263\320\276\321\201\321\217 \320\275\320\260 \321\200\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\270 \320\275\320\265 \320\261\320\276\320\273\320\265\320\265 1 \320\274, \320\264\320\276\320\273\320\266\320\265\320\275 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\276\320\262\320\260\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217\320\274, \321\203\320\272\320\260\320\267\320\260\320\275\320\275\321\213\320\274 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265 5.</li></ul>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><spa"
                        "n style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\242\320\260\320\261\320\273\320\270\321\206\320\260 5. \320\237\321\200\320\265\320\264\320\265\320\273 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271</span></p>\n"
"<table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\">\n"
"<tr>\n"
"<td rowspan=\"2\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\232\320\273\320\260\321\201\321\201\321\213 \321\202\320\276\321\207\320\275\320\276\321\201\321\202\320\270 \320\272\320\273\320\265\321\211\320\265\320\271</span></p></td>\n"
"<td colspan=\"2\""
                        ">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\237\321\200\320\265\320\264\320\265\320\273 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\320\274\320\276\320\271 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\271 \320\277\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\320\270 \320\272\320\273\320\265\321\211\320\265\320\271, %</span></p></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\227\320\260\321\211\320\270\321\211\320\265\320\275\320\275\321\213\321\205 \320\276\321\202 \320\262\320\275\320\265\321\210\320\275\320\270\321\205 \320\274\320\260\320\263\320\275\320\270\321\202\320\275\321\213\321\205 "
                        "\320\277\320\276\320\273\320\265\320\271</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\235\320\265\320\267\320\260\321\211\320\270\321\211\320\265\320\275\320\275\321\213\321\205 \320\276\321\202 \320\262\320\275\320\265\321\210\320\275\320\270\321\205 \320\274\320\260\320\263\320\275\320\270\321\202\320\275\321\213\321\205 \320\277\320\276\320\273\320\265\320\271</span></p></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">1; 1,5</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\2610,5</span></p></td>\n"
"<td>\n"
"<p style=\" marg"
                        "in-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\2611,5</span></p></td></tr>\n"
"<tr>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">2,5; 4; 5</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\2611,5</span></p></td>\n"
"<td>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\302\2612,5</span></p></td></tr></table>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family"
                        ":'Ubuntu'; font-size:11pt;\">\320\237\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272 \321\201 \321\202\320\276\320\272\320\276\320\274, \320\262\320\273\320\270\321\217\320\275\320\270\320\265 \320\272\320\276\321\202\320\276\321\200\320\276\320\263\320\276 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202\321\201\321\217, \320\264\320\276\320\273\320\266\320\265\320\275 \320\261\321\213\321\202\321\214 \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275 \320\277\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\276 \320\277\320\276 \320\276\321\202\320\275\320\276\321\210\320\265\320\275\320\270\321\216 \320\272 \320\277\321\200\320\276\320\262\320\276\320\264\320\275\320\270\320\272\321\203 \321\201 \320\270\320\267\320\274\320\265\321\200\321\217\320\265\320\274\321\213\320\274 \321\202\320\276\320\272\320\276\320\274.</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin"
                        "-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\320\276\320\261\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \320\277\320\276\321\202\321\200\320\265\320\261\320\273\320\265\320\275\320\270\320\265 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242 8711, \320\223\320\236\320\241\320\242 8476, \320\223\320\236\320\241\320\242 8039.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\320\273\320\265\320\272\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\260\321\217"
                        " \320\277\321\200\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \320\270 \321\201\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 \320\270\320\267\320\276\320\273\321\217\321\206\320\270\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \320\264\320\276\320\273\320\266\320\275\321\213 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\276\320\262\320\260\321\202\321\214 \320\223\320\236\320\241\320\242 8711, \320\223\320\236\320\241\320\242\302\2408476, \320\223\320\236\320\241\320\242 8039 \321\201\320\276 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\274\320\270 \320\264\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217\320\274\320\270:</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" ma"
                        "rgin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\270\320\267\320\276\320\273\321\217\321\206\320\270\321\217 \320\274\320\265\320\266\320\264\321\203 \320\274\320\260\320\263\320\275\320\270\321\202\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\276\320\274 \320\270 \321\207\320\260\321\201\321\202\321\217\320\274\320\270 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271, \321\201 \320\272\320\276\321\202\320\276\321\200\321\213\320\274\320\270 \321\201\320\276\320\277\321\200\320\270\320\272\320\260\321\201\320\260\321\216\321\202\321\201\321\217 \321\200\321\203\320\272\320\270 \320\276\320\277\320\265\321\200\320\260\321\202\320\276\321\200\320\260 \320\277\321\200\320\270 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217\321\205, \320\260 \321\202\320\260"
                        "\320\272\320\266\320\265 \320\270\320\267\320\276\320\273\321\217\321\206\320\270\321\217 \320\274\320\265\320\266\320\264\321\203 \321\202\320\276\320\272\320\276\320\262\320\265\320\264\321\203\321\211\320\270\320\274\320\270 \321\207\320\260\321\201\321\202\321\217\320\274\320\270 \321\201\320\276\320\265\320\264\320\270\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\277\321\200\320\276\320\262\320\276\320\264\320\276\320\262 \321\206\320\265\320\277\320\270 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217 \320\270 \320\274\320\265\321\201\321\202\320\260\320\274\320\270, \320\272\320\276\321\202\320\276\321\200\321\213\321\205 \320\272\320\260\321\201\320\260\321\216\321\202\321\201\321\217 \321\200\321\203\320\272\320\270 \320\276\320\277\320\265\321\200\320\260\321\202\320\276\321\200\320\260 \320\277\321\200\320\270 \320\262\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\270 \321\206\320\265\320\277\320\270 \320\275\320\260\320\277"
                        "\321\200\321\217\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\270\320\261\320\276\321\200\320\276\320\262, \320\264\320\276\320\273\320\266\320\275\321\213 \320\262\321\213\320\264\320\265\321\200\320\266\320\270\320\262\320\260\321\202\321\214 \320\262 \321\202\320\265\321\207\320\265\320\275\320\270\320\270 5 \320\274\320\270\320\275 \320\261\320\265\320\267 \320\277\321\200\320\276\320\261\320\276\321\217 \320\270\320\273\320\270 \320\277\320\265\321\200\320\265\320\272\321\200\321\213\321\202\320\270\321\217 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\265 \320\270\321\201\320\277\321\213\321\202\320\260\321\202\320\265\320\273\321\214\320\275\320\276\320\263\320\276 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\321\217 \320\277\321\200\320\260\320\272\321\202\320\270\321\207\320\265\321\201\320\272\320\270 \321\201\320\270\320\275\321\203\321\201\320\276\320\270\320\264\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \321\202\320\276\320\272"
                        "\320\260 \321\207\320\260\321\201\321\202\320\276\321\202\320\276\320\271 50 \320\223\321\206 \320\277\321\200\320\270 \320\275\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\276\320\271 \321\202\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\265 \320\270 \320\262\320\273\320\260\320\266\320\275\320\276\321\201\321\202\320\270 \320\276\320\272\321\200\321\203\320\266\320\260\321\216\321\211\320\265\320\263\320\276 \320\262\320\276\320\267\320\264\321\203\321\205\320\260;</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\264\320\265\320\271\321\201\321\202\320\262\321\203\321\216\321\211\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \320\270\321\201\320\277\321\213\321\202\320\260\321\202\320\265\320\273\321\214\320\275\320\276\320\263\320\276 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320"
                        "\275\320\270\321\217 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242\302\2408711, \320\223\320\236\320\241\320\242 8476, \320\223\320\236\320\241\320\242 8039.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\242\320\265\320\277\320\273\320\276-, \321\205\320\276\320\273\320\276\320\264\320\276-, \320\262\320\273\320\260\320\263\320\276\320\277\321\200\320\276\321\207\320\275\320\276\321\201\321\202\321\214, \320\262\320\270\320\261\321\200\320\276- \320\270 \321\203\320\264\320\260\321\200\320\276\320\277\321\200\320\276\321\207\320\275\320\276\321\201\321\202\321\214, \320\260 \321\202\320\260\320\272\320\266\320\265 \320\277\321\200\320\276\321\207\320\275\320\276\321\201\321\202\321\214 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273"
                        "\320\265\321\211\320\265\320\271 \320\277\321\200\320\270 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\270 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242 22261.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\276\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \342\200\223 \320\277\320\276 \320\223\320\236\320\241\320\242 22261, \320\223\320\236\320\241\320\242 8711, \320\223\320\236\320\241\320\242 8476, \320\223\320\236\320\241\320\242 8039.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-"
                        "bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\321\200\320\265\320\264\320\275\320\265\320\265 \320\262\321\200\320\265\320\274\321\217 \320\275\320\260\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \320\275\320\260 \320\276\321\202\320\272\320\260\320\267 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 - \320\275\320\265 \320\274\320\265\320\275\320\265\320\265 44 000 \321\207.\302\240</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\260 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\272\320\273\320\265\321\211\320\270 \320\264\320\276"
                        "\320\273\320\266\320\275\320\260 \320\261\321\213\321\202\321\214 \320\275\320\260\320\275\320\265\321\201\320\265\320\275\320\260 \320\274\320\260\321\200\320\272\320\270\321\200\320\276\320\262\320\272\320\260 \320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\270\321\202\320\265\320\273\321\217 \321\201\320\276\320\263\320\273\320\260\321\201\320\275\320\276 \321\202\321\200\320\265\320\261\320\276\320\262\320\260\320\275\320\270\321\217\320\274 \320\277.\320\277.1.4.3, 1.4.4, \320\260 \321\202\320\260\320\272\320\266\320\265 \320\270\320\275\320\262\320\265\320\275\321\202\320\260\321\200\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200 \320\270 \320\276\321\202\320\274\320\265\321\202\320\272\320\260 \320\276\320\261 \321\215\320\272\321\201\320\277\320\273\321\203\320\260\321\202\320\260\321\206\320\270\320\276\320\275\320\275\321\213\321\205 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217\321\205 \321\201\320\276\320\263\320\273\320\260\321\201\320\275\320"
                        "\276 \320\277.1.7.1.</li></ul>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600;\">\320\234\320\265\321\202\320\276\320\264\321\213 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\320\271 (\320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\217)</span></h3>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">\320\222 \320\277\321\200\320\276\321\206\320\265\321\201\321\201\320\265 \321\215\320\272\321\201\320\277\320\273\321\203\320\260\321\202\320\260\321\206\320\270\320\270, \320\277\320\276\321\202\321\200\320\265\320\261\320\270\321\202\320\265\320\273\320\265\320\274, \320\277\321\200\320\276\320\262\320\276\320\264\321\217\321\202\321\201\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\270\321"
                        "\207\320\265\321\201\320\272\320\270\320\265 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271. \320\237\321\200\320\270 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217\321\205 \320\270\320\267\320\276\320\273\321\217\321\206\320\270\320\270 \320\272\320\273\320\265\321\211\320\265\320\271 \320\275\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265 \320\277\321\200\320\270\320\272\320\273\320\260\320\264\321\213\320\262\320\260\320\265\321\202\321\201\321\217 \320\274\320\265\320\266\320\264\321\203 \320\274\320\260\320\263\320\275\320\270\321\202\320\276\320\277\321\200\320\276\320\262\320\276\320\264\320\276\320\274 \320\270 \320\262\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\274\320\270 \321\215\320\273\320\265\320\272"
                        "\321\202\321\200\320\276\320\264\320\260\320\274\320\270, \320\275\320\260\320\273\320\276\320\266\320\265\320\275\320\275\321\213\320\274\320\270 \321\203 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\276\320\273\320\265\321\206 \321\201\320\276 \321\201\321\202\320\276\321\200\320\276\320\275\321\213 \320\270\320\267\320\276\320\273\320\270\321\200\321\203\321\216\321\211\320\265\320\271 \321\207\320\260\321\201\321\202\320\270 (\320\264\320\273\321\217 \320\272\320\273\320\265\321\211\320\265\320\271 \320\262\321\213\321\210\320\265 1000 \320\222) \320\270\320\273\320\270 \321\203 \320\276\321\201\320\275\320\276\320\262\320\260\320\275\320\270\321\217 \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\270 (\320\264\320\273\321\217 \320\272\320\273\320\265\321\211\320\265\320\271 \320\264\320\276 1000\302\240\320\222).</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-righ"
                        "t: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\320\273\320\265\320\272\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217 \321\201\320\273\320\265\320\264\321\203\320\265\321\202 \320\277\321\200\320\276\320\262\320\276\320\264\320\270\321\202\321\214 \320\262 \320\277\320\276\321\200\321\217\320\264\320\272\320\265, \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\274 \320\277.1.8.8 \320\275\320\260\321\201\321\202\320\276\321\217\321\211\320\265\320\263\320\276 \320\241\321\202\320\260\320\275\320\264\320\260\321\200\321\202\320\260 \320\277\320\276 \320\275\320\276\321\200\320\274\320\260\320\274 \320\270 \321\201 \320\277\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321"
                        "\214\321\216 \321\201\320\276\320\263\320\273\320\260\321\201\320\275\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217\320\274 8 \320\270 10.</li></ul>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600;\">\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\270 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265</span></h3>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\242\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270"
                        "\320\265 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \320\264\320\276\320\273\320\266\320\275\320\276 \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\321\214\321\201\321\217 \320\262 \321\203\320\277\320\260\320\272\320\276\320\262\320\260\320\275\320\275\320\276\320\274 \320\262\320\270\320\264\320\265 \321\202\320\276\320\273\321\214\320\272\320\276 \320\262 \320\267\320\260\320\272\321\200\321\213\321\202\320\276\320\274 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\265, \320\262 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\270\320\270 \321\201 \320\277\321\200\320\260\320\262\320\270\320\273\320\260\320\274\320\270 \320\277\320\265\321\200\320\265\320\262\320\276\320\267\320\276\320\272 \320\263\321\200\321\203\320\267\320\276\320\262, \320\264"
                        "\320\265\320\271\321\201\321\202\320\262\321\203\321\216\321\211\320\270\320\274\320\270 \320\275\320\260 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\265 \320\264\320\260\320\275\320\275\320\276\320\263\320\276 \320\262\320\270\320\264\320\260.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\243\321\201\320\273\320\276\320\262\320\270\321\217 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \320\270 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\262 \321\207\320\260\321\201\321\202\320\270 \320\262\320\276\320\267\320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217 \320\272\320\273\320\270\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\204\320\260\320\272\321\202\320\276\321\200\320\276"
                        "\320\262 \320\262\320\275\320\265\321\210\320\275\320\265\320\271 \321\201\321\200\320\265\320\264\321\213 \320\264\320\276\320\273\320\266\320\275\320\276 \321\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\276\320\262\320\260\321\202\321\214 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\320\270 1\302\240\320\277\320\276 \320\223\320\236\320\241\320\242 15150, \321\202\320\260\320\261\320\273\320\270\321\206\320\260 13. \320\222 \321\207\320\260\321\201\321\202\320\270 \320\262\320\276\320\267\320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217 \320\274\320\265\321\205\320\260\320\275\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \321\204\320\260\320\272\321\202\320\276\321\200\320\276\320\262 \321\203\321\201\320\273\320\276\320\262\320\270\321\217 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \320\264\320\276\320\273\320\266\320\275\321\213 \321"
                        "\201\320\276\320\276\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\320\265 \302\253\320\241\302\273 \320\277\320\276 \320\223\320\236\320\241\320\242\302\24023216.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\245\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \320\276\321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\262 \321\203\320\277\320\260\320\272\320\276\320\262\320\260\320\275\320\275\320\276\320\274 \320\262\320\270\320\264\320\265, \320\277\321\200\320\270 \320\276\321\202\321\201\321\203\321\202\321\201"
                        "\321\202\320\262\320\270\320\270 \320\262\320\276\320\267\320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217 \320\272\320\270\321\201\320\273\320\276\321\202, \321\211\320\265\320\273\320\276\321\207\320\265\320\271, \320\261\320\265\320\275\320\267\320\270\320\275\320\260 \320\270 \321\200\320\260\321\201\321\202\320\262\320\276\321\200\320\270\321\202\320\265\320\273\320\265\320\271.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\260 \320\261\320\276\320\272\320\276\320\262\321\203\321\216 \320\270 \321\202\320\276\321\200\321\206\320\265\320\262\321\203\321\216 \321\201\321\202\320\265\320\275\320\272\320\270 \321\217\321\211\320\270\320\272\320\260 \321\202\321\200\320\260\320\275\321\201\320\277\320\276\321\200\321\202\320\275\320\276\320\271 \321\202\320\260\321\200\321\213 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\320\270\320\267\320"
                        "\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \320\272\320\273\320\265\321\211\320\265\320\271 \320\264\320\276\320\273\320\266\320\275\321\213 \320\261\321\213\321\202\321\214 \320\275\320\260\320\275\320\265\321\201\320\265\320\275\321\213 \320\274\320\260\320\275\320\270\320\277\321\203\320\273\321\217\321\206\320\270\320\276\320\275\320\275\321\213\320\265 \320\267\320\275\320\260\320\272\320\270 \320\277\320\276 \320\223\320\236\320\241\320\242 14192 \302\253\320\245\321\200\321\203\320\277\320\272\320\276\320\265 \320\236\321\201\321\202\320\276\321\200\320\276\320\266\320\275\320\276\302\273, \302\253\320\221\320\265\321\200\320\265\321\207\321\214 \320\276\321\202 \320\262\320\273\320\260\320\263\320\270\302\273.</li></ul>\n"
"<h3 style=\" margin-top:14px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:600;\">\320\243\320\272\320\260\320\267\320\260\320\275"
                        "\320\270\321\217 \320\277\320\276 \321\215\320\272\321\201\320\277\320\273\321\203\320\260\321\202\320\260\321\206\320\270\320\270</span></h3>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\240\320\260\320\261\320\276\321\202\320\260\321\202\321\214 \321\201 \320\272\320\273\320\265\321\211\320\260\320\274\320\270 \320\262\321\213\321\210\320\265 1000 \320\222 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \320\262 \320\264\320\270\321\215\320\273\320\265\320\272\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\321\205 \320\277\320\265\321\200\321\207\320\260\321\202\320\272\320\260\321\205.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right"
                        ":0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\270 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217\321\205 \320\272\320\273\320\265\321\211\320\270 \321\201\320\273\320\265\320\264\321\203\320\265\321\202 \320\264\320\265\321\200\320\266\320\260\321\202\321\214 \320\275\320\260 \320\262\320\265\321\201\321\203, \320\275\320\265 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\321\202\321\201\321\217 \320\275\320\260\320\272\320\273\320\276\320\275\321\217\321\202\321\214\321\201\321\217 \320\272 \320\277\321\200\320\270\320\261\320\276\321\200\321\203 \320\264\320\273\321\217 \320\276\321\202\321\201\321\207\320\265\321\202\320\260 \320\277\320\276\320\272\320\260\320\267\320\260\320\275\320\270\320\271.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\321\200\320\270 \321\200\320\260\320\261\320\276\321\202\320\265"
                        " \321\201 \320\272\320\273\320\265\321\211\320\260\320\274\320\270 \320\262 \321\215\320\273\320\265\320\272\321\202\321\200\320\276\321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260\321\205 \320\262\321\213\321\210\320\265 1000 \320\222 \320\275\320\265 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\321\202\321\201\321\217 \320\277\321\200\320\270\320\274\320\265\320\275\321\217\321\202\321\214 \320\262\321\213\320\275\320\276\321\201\320\275\321\213\320\265 \320\277\321\200\320\270\320\261\320\276\321\200\321\213, \320\260 \321\202\320\260\320\272\320\266\320\265 \320\277\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\260\321\202\321\214 \320\277\321\200\320\265\320\264\320\265\320\273\321\213 \320\270\320\267\320\274\320\265\321\200\320\265\320\275\320\270\321\217, \320\275\320\265 \321\201\320\275\320\270\320\274\320\260\321\217 \320\272\320\273\320\265\321\211\320\265\320\271 \321\201 \321\202\320\276\320\272\320\276\320\262\320\265\320\264\321\203\321\211"
                        "\320\270\321\205 \321\207\320\260\321\201\321\202\320\265\320\271.</li>\n"
"<li style=\" font-family:'Ubuntu'; font-size:11pt;\" style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\235\320\265 \320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\321\202\321\201\321\217 \321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214 \321\201 \320\272\320\273\320\265\321\211\320\260\320\274\320\270 \320\264\320\276 1000 \320\222, \320\275\320\260\321\205\320\276\320\264\321\217\321\201\321\214 \320\275\320\260 \320\276\320\277\320\276\321\200\320\265 \320\222\320\233, \320\265\321\201\320\273\320\270 \320\272\320\273\320\265\321\211\320\270 \321\201\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276 \320\275\320\265 \320\277\321\200\320\265\320\264\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\321\213 \320\264\320\273\321\217 \321\215\321\202\320\276\320\271 \321\206\320\265\320\273\320\270"
                        ".</li></ul></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainSizWindow", "\320\226\321\203\321\200\320\275\320\260\320\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainSizWindow", "\320\241\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainSizWindow", "\320\222\320\270\320\264\321\213 \321\201\321\200\320\265\320\264\321\201\321\202\320\262 \320\267\320\260\321\211\320\270\321\202\321\213", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainSizWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        radioButton->setText(QCoreApplication::translate("MainSizWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        addRowPerechniTable->setText(QCoreApplication::translate("MainSizWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteRowPerechniTable->setText(QCoreApplication::translate("MainSizWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainSizWindow", "\320\237\320\265\321\200\320\265\321\207\320\275\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainSizWindow", "\320\264\320\275\320\265\320\271 \320\264\320\276 \321\201\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainSizWindow", "\320\274\320\270\320\275\321\203\321\202 \320\274\320\265\320\266\320\264\321\203 \320\276\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\321\217\320\274\320\270", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainSizWindow", "\320\237\321\200\320\270\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270 \321\201 \320\270\321\201\321\202\320\265\320\272\321\210\320\270\320\274 \320\276\321\201\320\274\320\276\321\202\321\200\320\276\320\274", nullptr));
        pushButton->setText(QCoreApplication::translate("MainSizWindow", "...", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainSizWindow", "...", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainSizWindow", "...", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainSizWindow", "...", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainSizWindow", "\320\237\321\200\320\270\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270 \321\201 \320\270\321\201\321\202\320\265\320\272\321\210\320\270\320\274 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\320\265\320\274", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("MainSizWindow", "\320\237\321\200\320\270\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270 \321\201  \320\270\321\201\321\202\320\265\320\272\320\260\321\216\321\211\320\270\320\274 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\320\265\320\274", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainSizWindow", "\320\237\321\200\320\270\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270 \321\201  \320\270\321\201\321\202\320\265\320\272\320\260\321\216\321\211\320\270\320\274 \320\276\321\201\320\274\320\276\321\202\321\200\320\276\320\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainSizWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSizWindow: public Ui_MainSizWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSIZWINDOW_H
