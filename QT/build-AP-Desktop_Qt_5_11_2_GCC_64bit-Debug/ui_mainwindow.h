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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_exit;
    QAction *actionDot;
    QWidget *centralWidget;
    QLineEdit *txtCadena;
    QPushButton *btnVerificar;
    QLabel *label;
    QLabel *labelNodo;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(723, 515);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        actionDot = new QAction(MainWindow);
        actionDot->setObjectName(QStringLiteral("actionDot"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        txtCadena = new QLineEdit(centralWidget);
        txtCadena->setObjectName(QStringLiteral("txtCadena"));
        txtCadena->setGeometry(QRect(20, 40, 201, 23));
        btnVerificar = new QPushButton(centralWidget);
        btnVerificar->setObjectName(QStringLiteral("btnVerificar"));
        btnVerificar->setGeometry(QRect(230, 40, 80, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 131, 16));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        labelNodo = new QLabel(centralWidget);
        labelNodo->setObjectName(QStringLiteral("labelNodo"));
        labelNodo->setGeometry(QRect(20, 94, 651, 351));
        labelNodo->setMouseTracking(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 723, 20));
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
        menu_File->addAction(action_exit);
        menu_File->addAction(actionDot);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_exit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        actionDot->setText(QApplication::translate("MainWindow", "Dot", nullptr));
        txtCadena->setPlaceholderText(QString());
        btnVerificar->setText(QApplication::translate("MainWindow", "Verificar", nullptr));
        label->setText(QApplication::translate("MainWindow", "Automata de PIla", nullptr));
        labelNodo->setText(QString());
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
