/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "customview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Clear;
    QAction *action_Exit;
    QAction *action_About;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *btnGenerate;
    QLineEdit *txtIn;
    CustomView *graphicsView;
    QWidget *tab_2;
    QLineEdit *lineEditAFD;
    QPushButton *btnVerifyAFND;
    CustomView *graphicsView2;
    QLineEdit *lineEditRespuestaVerify;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_About;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1349, 725);
        action_Clear = new QAction(MainWindow);
        action_Clear->setObjectName(QStringLiteral("action_Clear"));
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1331, 691));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        btnGenerate = new QPushButton(tab);
        btnGenerate->setObjectName(QStringLiteral("btnGenerate"));
        btnGenerate->setGeometry(QRect(1230, 30, 80, 23));
        txtIn = new QLineEdit(tab);
        txtIn->setObjectName(QStringLiteral("txtIn"));
        txtIn->setGeometry(QRect(20, 30, 941, 23));
        graphicsView = new CustomView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 60, 1291, 591));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        lineEditAFD = new QLineEdit(tab_2);
        lineEditAFD->setObjectName(QStringLiteral("lineEditAFD"));
        lineEditAFD->setGeometry(QRect(20, 30, 701, 23));
        btnVerifyAFND = new QPushButton(tab_2);
        btnVerifyAFND->setObjectName(QStringLiteral("btnVerifyAFND"));
        btnVerifyAFND->setGeometry(QRect(1210, 30, 80, 23));
        graphicsView2 = new CustomView(tab_2);
        graphicsView2->setObjectName(QStringLiteral("graphicsView2"));
        graphicsView2->setGeometry(QRect(20, 60, 1281, 561));
        lineEditRespuestaVerify = new QLineEdit(tab_2);
        lineEditRespuestaVerify->setObjectName(QStringLiteral("lineEditRespuestaVerify"));
        lineEditRespuestaVerify->setGeometry(QRect(760, 30, 401, 23));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1349, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_About = new QMenu(menuBar);
        menu_About->setObjectName(QStringLiteral("menu_About"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_About->menuAction());
        menu_File->addAction(action_Clear);
        menu_File->addAction(action_Exit);
        menu_About->addAction(action_About);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Clear->setText(QApplication::translate("MainWindow", "&Clear", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        action_About->setText(QApplication::translate("MainWindow", "&About", nullptr));
        btnGenerate->setText(QApplication::translate("MainWindow", "Generar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "inputNFA", nullptr));
        btnVerifyAFND->setText(QApplication::translate("MainWindow", "verify", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Verify", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menu_About->setTitle(QApplication::translate("MainWindow", "&About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
