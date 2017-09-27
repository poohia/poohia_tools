/********************************************************************************
** Form generated from reading UI file 'viewobject.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWOBJECT_H
#define UI_VIEWOBJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewObject
{
public:
    QAction *actionConfigurator;
    QAction *actionVerify_Update;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QPushButton *pushButton;
    QLineEdit *lineEditPathIcon;
    QLineEdit *lineEditPathSoftware;
    QPushButton *pushButtonAddSoftware;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *lineEditNameSoftware;
    QLabel *label_5;
    QLabel *label_3;
    QComboBox *comboBoxAllSoftware;
    QPushButton *pushButtonRemoveSoftware;
    QLabel *labelSoftwareIcon;
    QWidget *Dir;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QLabel *label_9;
    QLineEdit *lineEditNameDirs;
    QLabel *label_8;
    QComboBox *comboBoxAllDirs;
    QLabel *label_7;
    QLineEdit *lineEditPathDir;
    QPushButton *pushButtonAddDir;
    QPushButton *pushButtonRemoveDir;
    QPushButton *pushButton_5;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QPushButton *pushButtonRemoveUrl;
    QLabel *label_10;
    QLineEdit *lineEditUrls;
    QComboBox *comboBoxAllUrls;
    QPushButton *pushButtonAddUrls;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEditNameUrl;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEditNameService;
    QPushButton *pushButtonAddService;
    QPushButton *pushButtonRemoveService;
    QComboBox *comboBoxAllService;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ViewObject)
    {
        if (ViewObject->objectName().isEmpty())
            ViewObject->setObjectName(QStringLiteral("ViewObject"));
        ViewObject->resize(691, 207);
        ViewObject->setMinimumSize(QSize(691, 207));
        ViewObject->setMaximumSize(QSize(691, 207));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ViewObject->setWindowIcon(icon);
        ViewObject->setAnimated(true);
        actionConfigurator = new QAction(ViewObject);
        actionConfigurator->setObjectName(QStringLiteral("actionConfigurator"));
        actionConfigurator->setEnabled(false);
        actionVerify_Update = new QAction(ViewObject);
        actionVerify_Update->setObjectName(QStringLiteral("actionVerify_Update"));
        centralWidget = new QWidget(ViewObject);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setProperty("tabBarAutoHide", QVariant(true));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 3, 0, 1, 1);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_4->addWidget(pushButton, 2, 3, 1, 1);

        lineEditPathIcon = new QLineEdit(tab_2);
        lineEditPathIcon->setObjectName(QStringLiteral("lineEditPathIcon"));

        gridLayout_4->addWidget(lineEditPathIcon, 3, 1, 1, 1);

        lineEditPathSoftware = new QLineEdit(tab_2);
        lineEditPathSoftware->setObjectName(QStringLiteral("lineEditPathSoftware"));

        gridLayout_4->addWidget(lineEditPathSoftware, 2, 1, 1, 1);

        pushButtonAddSoftware = new QPushButton(tab_2);
        pushButtonAddSoftware->setObjectName(QStringLiteral("pushButtonAddSoftware"));

        gridLayout_4->addWidget(pushButtonAddSoftware, 4, 1, 1, 1);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_4->addWidget(pushButton_2, 3, 3, 1, 1);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 1, 0, 1, 1);

        lineEditNameSoftware = new QLineEdit(tab_2);
        lineEditNameSoftware->setObjectName(QStringLiteral("lineEditNameSoftware"));

        gridLayout_4->addWidget(lineEditNameSoftware, 1, 1, 1, 1);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 2, 0, 1, 1);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        comboBoxAllSoftware = new QComboBox(tab_2);
        comboBoxAllSoftware->setObjectName(QStringLiteral("comboBoxAllSoftware"));

        gridLayout_4->addWidget(comboBoxAllSoftware, 0, 1, 1, 1);

        pushButtonRemoveSoftware = new QPushButton(tab_2);
        pushButtonRemoveSoftware->setObjectName(QStringLiteral("pushButtonRemoveSoftware"));
        pushButtonRemoveSoftware->setEnabled(false);

        gridLayout_4->addWidget(pushButtonRemoveSoftware, 4, 3, 1, 1);

        labelSoftwareIcon = new QLabel(tab_2);
        labelSoftwareIcon->setObjectName(QStringLiteral("labelSoftwareIcon"));

        gridLayout_4->addWidget(labelSoftwareIcon, 3, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/defaultsoftware.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_2, icon1, QString());
        Dir = new QWidget();
        Dir->setObjectName(QStringLiteral("Dir"));
        gridLayout_7 = new QGridLayout(Dir);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_9 = new QLabel(Dir);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_6->addWidget(label_9, 2, 0, 1, 1);

        lineEditNameDirs = new QLineEdit(Dir);
        lineEditNameDirs->setObjectName(QStringLiteral("lineEditNameDirs"));

        gridLayout_6->addWidget(lineEditNameDirs, 1, 1, 1, 1);

        label_8 = new QLabel(Dir);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_6->addWidget(label_8, 1, 0, 1, 1);

        comboBoxAllDirs = new QComboBox(Dir);
        comboBoxAllDirs->setObjectName(QStringLiteral("comboBoxAllDirs"));

        gridLayout_6->addWidget(comboBoxAllDirs, 0, 1, 1, 1);

        label_7 = new QLabel(Dir);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 0, 0, 1, 1);

        lineEditPathDir = new QLineEdit(Dir);
        lineEditPathDir->setObjectName(QStringLiteral("lineEditPathDir"));

        gridLayout_6->addWidget(lineEditPathDir, 2, 1, 1, 1);

        pushButtonAddDir = new QPushButton(Dir);
        pushButtonAddDir->setObjectName(QStringLiteral("pushButtonAddDir"));

        gridLayout_6->addWidget(pushButtonAddDir, 3, 1, 1, 1);

        pushButtonRemoveDir = new QPushButton(Dir);
        pushButtonRemoveDir->setObjectName(QStringLiteral("pushButtonRemoveDir"));

        gridLayout_6->addWidget(pushButtonRemoveDir, 3, 2, 1, 1);

        pushButton_5 = new QPushButton(Dir);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_6->addWidget(pushButton_5, 2, 2, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);

        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/dossier.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(Dir, icon2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        pushButtonRemoveUrl = new QPushButton(tab_3);
        pushButtonRemoveUrl->setObjectName(QStringLiteral("pushButtonRemoveUrl"));

        gridLayout_8->addWidget(pushButtonRemoveUrl, 3, 2, 1, 1);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_8->addWidget(label_10, 0, 0, 1, 1);

        lineEditUrls = new QLineEdit(tab_3);
        lineEditUrls->setObjectName(QStringLiteral("lineEditUrls"));

        gridLayout_8->addWidget(lineEditUrls, 2, 1, 1, 1);

        comboBoxAllUrls = new QComboBox(tab_3);
        comboBoxAllUrls->setObjectName(QStringLiteral("comboBoxAllUrls"));

        gridLayout_8->addWidget(comboBoxAllUrls, 0, 1, 1, 1);

        pushButtonAddUrls = new QPushButton(tab_3);
        pushButtonAddUrls->setObjectName(QStringLiteral("pushButtonAddUrls"));

        gridLayout_8->addWidget(pushButtonAddUrls, 3, 1, 1, 1);

        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_8->addWidget(label_11, 2, 0, 1, 1);

        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_8->addWidget(label_12, 1, 0, 1, 1);

        lineEditNameUrl = new QLineEdit(tab_3);
        lineEditNameUrl->setObjectName(QStringLiteral("lineEditNameUrl"));

        gridLayout_8->addWidget(lineEditNameUrl, 1, 1, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);

        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/internet.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab_3, icon3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEditNameService = new QLineEdit(tab);
        lineEditNameService->setObjectName(QStringLiteral("lineEditNameService"));

        gridLayout_2->addWidget(lineEditNameService, 0, 1, 1, 1);

        pushButtonAddService = new QPushButton(tab);
        pushButtonAddService->setObjectName(QStringLiteral("pushButtonAddService"));

        gridLayout_2->addWidget(pushButtonAddService, 0, 2, 1, 1);

        pushButtonRemoveService = new QPushButton(tab);
        pushButtonRemoveService->setObjectName(QStringLiteral("pushButtonRemoveService"));

        gridLayout_2->addWidget(pushButtonRemoveService, 1, 2, 1, 1);

        comboBoxAllService = new QComboBox(tab);
        comboBoxAllService->setObjectName(QStringLiteral("comboBoxAllService"));

        gridLayout_2->addWidget(comboBoxAllService, 1, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/service.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tab, icon4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        ViewObject->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ViewObject);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ViewObject->setStatusBar(statusBar);

        retranslateUi(ViewObject);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ViewObject);
    } // setupUi

    void retranslateUi(QMainWindow *ViewObject)
    {
        ViewObject->setWindowTitle(QString());
        actionConfigurator->setText(QApplication::translate("ViewObject", "Configurator", 0));
        actionVerify_Update->setText(QApplication::translate("ViewObject", "Verify Update", 0));
        label_6->setText(QApplication::translate("ViewObject", "Icon : ", 0));
        pushButton->setText(QApplication::translate("ViewObject", "...", 0));
        pushButtonAddSoftware->setText(QApplication::translate("ViewObject", "Add", 0));
        pushButton_2->setText(QApplication::translate("ViewObject", "...", 0));
        label_4->setText(QApplication::translate("ViewObject", "Name : ", 0));
        label_5->setText(QApplication::translate("ViewObject", "Path : ", 0));
        label_3->setText(QApplication::translate("ViewObject", "Current softwares : ", 0));
        pushButtonRemoveSoftware->setText(QApplication::translate("ViewObject", "Remove", 0));
        labelSoftwareIcon->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ViewObject", "Softwares", 0));
        label_9->setText(QApplication::translate("ViewObject", "Path : ", 0));
        label_8->setText(QApplication::translate("ViewObject", "Name : ", 0));
        label_7->setText(QApplication::translate("ViewObject", "Current dirs : ", 0));
        pushButtonAddDir->setText(QApplication::translate("ViewObject", "Add", 0));
        pushButtonRemoveDir->setText(QApplication::translate("ViewObject", "Remove", 0));
        pushButton_5->setText(QApplication::translate("ViewObject", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(Dir), QApplication::translate("ViewObject", "Dir", 0));
        pushButtonRemoveUrl->setText(QApplication::translate("ViewObject", "Remove", 0));
        label_10->setText(QApplication::translate("ViewObject", "Current urls :", 0));
        pushButtonAddUrls->setText(QApplication::translate("ViewObject", "Add", 0));
        label_11->setText(QApplication::translate("ViewObject", "Url : ", 0));
        label_12->setText(QApplication::translate("ViewObject", "Name : ", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ViewObject", "Web", 0));
        label_2->setText(QApplication::translate("ViewObject", "Services : ", 0));
        label->setText(QApplication::translate("ViewObject", "Name of service :", 0));
        pushButtonAddService->setText(QApplication::translate("ViewObject", "Add", 0));
        pushButtonRemoveService->setText(QApplication::translate("ViewObject", "Remove", 0));
        comboBoxAllService->clear();
        comboBoxAllService->insertItems(0, QStringList()
         << QString()
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ViewObject", "Services", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewObject: public Ui_ViewObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWOBJECT_H
