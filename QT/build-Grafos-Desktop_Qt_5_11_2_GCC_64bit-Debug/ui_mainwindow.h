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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "customview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QLineEdit *txtVertice;
    QPushButton *addVertice;
    CustomView *graphicsView;
    QPushButton *btnaddArista;
    QLineEdit *txtOrigen;
    QLineEdit *txtDestino;
    QLineEdit *peso;
    QLabel *label1;
    QLabel *label2;
    QWidget *tabDikjstra;
    QLineEdit *mensaje;
    QPushButton *btnEliminar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(685, 469);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 671, 411));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        txtVertice = new QLineEdit(tab1);
        txtVertice->setObjectName(QStringLiteral("txtVertice"));
        txtVertice->setGeometry(QRect(470, 10, 101, 23));
        addVertice = new QPushButton(tab1);
        addVertice->setObjectName(QStringLiteral("addVertice"));
        addVertice->setGeometry(QRect(580, 10, 71, 23));
        graphicsView = new CustomView(tab1);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 50, 641, 311));
        btnaddArista = new QPushButton(tab1);
        btnaddArista->setObjectName(QStringLiteral("btnaddArista"));
        btnaddArista->setGeometry(QRect(290, 10, 61, 21));
        txtOrigen = new QLineEdit(tab1);
        txtOrigen->setObjectName(QStringLiteral("txtOrigen"));
        txtOrigen->setGeometry(QRect(10, 10, 91, 23));
        txtDestino = new QLineEdit(tab1);
        txtDestino->setObjectName(QStringLiteral("txtDestino"));
        txtDestino->setGeometry(QRect(120, 10, 91, 23));
        peso = new QLineEdit(tab1);
        peso->setObjectName(QStringLiteral("peso"));
        peso->setGeometry(QRect(230, 10, 51, 23));
        label1 = new QLabel(tab1);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(110, 10, 16, 16));
        label2 = new QLabel(tab1);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(220, 10, 16, 16));
        tabWidget->addTab(tab1, QString());
        tabDikjstra = new QWidget();
        tabDikjstra->setObjectName(QStringLiteral("tabDikjstra"));
        mensaje = new QLineEdit(tabDikjstra);
        mensaje->setObjectName(QStringLiteral("mensaje"));
        mensaje->setGeometry(QRect(140, 40, 113, 23));
        btnEliminar = new QPushButton(tabDikjstra);
        btnEliminar->setObjectName(QStringLiteral("btnEliminar"));
        btnEliminar->setGeometry(QRect(300, 40, 80, 23));
        tabWidget->addTab(tabDikjstra, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 685, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        addVertice->setText(QApplication::translate("MainWindow", "AddVertice", nullptr));
        btnaddArista->setText(QApplication::translate("MainWindow", "AddArista", nullptr));
        label1->setText(QApplication::translate("MainWindow", "-", nullptr));
        label2->setText(QApplication::translate("MainWindow", "-", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Insert", nullptr));
        btnEliminar->setText(QApplication::translate("MainWindow", "eliminar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDikjstra), QApplication::translate("MainWindow", "Dikjstra", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
