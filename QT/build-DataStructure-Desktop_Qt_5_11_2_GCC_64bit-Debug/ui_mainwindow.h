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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "customview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Exit;
    QWidget *centralWidget;
    QListWidget *listWidgetEstructura;
    QPushButton *btnSeleccionar;
    QFrame *lineHorizontal1;
    QLineEdit *txtAdd;
    QLabel *labelNameDataStructure;
    QPushButton *btnAdd;
    QFrame *lineVertical1;
    QLabel *labelMensaje;
    QPushButton *btnClearAll;
    QLabel *labelAddnDatos;
    QPushButton *btnAddNDatos;
    QLineEdit *txtAddN;
    customview *graphicsViewStructure;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1148, 684);
        QFont font;
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        MainWindow->setFont(font);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        listWidgetEstructura = new QListWidget(centralWidget);
        listWidgetEstructura->setObjectName(QStringLiteral("listWidgetEstructura"));
        listWidgetEstructura->setGeometry(QRect(30, 30, 141, 181));
        btnSeleccionar = new QPushButton(centralWidget);
        btnSeleccionar->setObjectName(QStringLiteral("btnSeleccionar"));
        btnSeleccionar->setGeometry(QRect(110, 220, 61, 21));
        QFont font1;
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        btnSeleccionar->setFont(font1);
        btnSeleccionar->setCursor(QCursor(Qt::PointingHandCursor));
        btnSeleccionar->setMouseTracking(false);
        btnSeleccionar->setTabletTracking(false);
        lineHorizontal1 = new QFrame(centralWidget);
        lineHorizontal1->setObjectName(QStringLiteral("lineHorizontal1"));
        lineHorizontal1->setGeometry(QRect(30, 260, 141, 16));
        lineHorizontal1->setFrameShape(QFrame::HLine);
        lineHorizontal1->setFrameShadow(QFrame::Sunken);
        txtAdd = new QLineEdit(centralWidget);
        txtAdd->setObjectName(QStringLiteral("txtAdd"));
        txtAdd->setGeometry(QRect(40, 310, 131, 21));
        labelNameDataStructure = new QLabel(centralWidget);
        labelNameDataStructure->setObjectName(QStringLiteral("labelNameDataStructure"));
        labelNameDataStructure->setGeometry(QRect(60, 280, 81, 20));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(120, 340, 51, 23));
        lineVertical1 = new QFrame(centralWidget);
        lineVertical1->setObjectName(QStringLiteral("lineVertical1"));
        lineVertical1->setGeometry(QRect(190, 30, 20, 611));
        lineVertical1->setFrameShape(QFrame::VLine);
        lineVertical1->setFrameShadow(QFrame::Sunken);
        labelMensaje = new QLabel(centralWidget);
        labelMensaje->setObjectName(QStringLiteral("labelMensaje"));
        labelMensaje->setGeometry(QRect(40, 380, 121, 16));
        btnClearAll = new QPushButton(centralWidget);
        btnClearAll->setObjectName(QStringLiteral("btnClearAll"));
        btnClearAll->setGeometry(QRect(1030, 10, 80, 23));
        labelAddnDatos = new QLabel(centralWidget);
        labelAddnDatos->setObjectName(QStringLiteral("labelAddnDatos"));
        labelAddnDatos->setGeometry(QRect(70, 380, 81, 16));
        btnAddNDatos = new QPushButton(centralWidget);
        btnAddNDatos->setObjectName(QStringLiteral("btnAddNDatos"));
        btnAddNDatos->setGeometry(QRect(129, 430, 41, 23));
        txtAddN = new QLineEdit(centralWidget);
        txtAddN->setObjectName(QStringLiteral("txtAddN"));
        txtAddN->setGeometry(QRect(40, 400, 131, 23));
        graphicsViewStructure = new customview(centralWidget);
        graphicsViewStructure->setObjectName(QStringLiteral("graphicsViewStructure"));
        graphicsViewStructure->setGeometry(QRect(210, 40, 901, 571));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1148, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DataStructure", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        btnSeleccionar->setText(QApplication::translate("MainWindow", "Select", nullptr));
        labelNameDataStructure->setText(QApplication::translate("MainWindow", "name Struct", nullptr));
        btnAdd->setText(QApplication::translate("MainWindow", "Add", nullptr));
        labelMensaje->setText(QString());
        btnClearAll->setText(QApplication::translate("MainWindow", "ClearAll", nullptr));
        labelAddnDatos->setText(QApplication::translate("MainWindow", "Add N-Datos", nullptr));
        btnAddNDatos->setText(QApplication::translate("MainWindow", "Add", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
