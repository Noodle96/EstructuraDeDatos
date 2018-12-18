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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionload_in_List;
    QAction *actionload_in_Hash;
    QAction *actionload_in_Set;
    QAction *action_Exit;
    QAction *action_About;
    QWidget *centralWidget;
    QLabel *labelTitle;
    QLineEdit *txtWord;
    QFrame *line;
    QFrame *line_2;
    QLabel *labelWithList;
    QLabel *labelWithHash;
    QLabel *labelWithSet;
    QLabel *labelTimeList;
    QLabel *labelTimeHash;
    QLabel *labelTimeSet;
    QLineEdit *txtTimeList;
    QLineEdit *txtTimeHash;
    QLineEdit *txtTimeSet;
    QPushButton *btnTraducir;
    QLabel *labelMessageList;
    QLabel *labelMessageHash;
    QLabel *labelMessageSet;
    QTextEdit *txtWithList;
    QTextEdit *txtWithHash;
    QTextEdit *txtWithSet;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(494, 349);
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        MainWindow->setFont(font);
        actionload_in_List = new QAction(MainWindow);
        actionload_in_List->setObjectName(QStringLiteral("actionload_in_List"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/listas.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        actionload_in_List->setIcon(icon);
        actionload_in_Hash = new QAction(MainWindow);
        actionload_in_Hash->setObjectName(QStringLiteral("actionload_in_Hash"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/Tabla_hash.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionload_in_Hash->setIcon(icon1);
        actionload_in_Set = new QAction(MainWindow);
        actionload_in_Set->setObjectName(QStringLiteral("actionload_in_Set"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/set.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionload_in_Set->setIcon(icon2);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/close.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon3);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/about.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelTitle = new QLabel(centralWidget);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setGeometry(QRect(150, 20, 221, 16));
        txtWord = new QLineEdit(centralWidget);
        txtWord->setObjectName(QStringLiteral("txtWord"));
        txtWord->setEnabled(true);
        txtWord->setGeometry(QRect(150, 50, 191, 23));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        txtWord->setFont(font1);
        txtWord->setClearButtonEnabled(false);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(150, 80, 20, 201));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(320, 80, 16, 201));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        labelWithList = new QLabel(centralWidget);
        labelWithList->setObjectName(QStringLiteral("labelWithList"));
        labelWithList->setGeometry(QRect(60, 80, 61, 16));
        labelWithHash = new QLabel(centralWidget);
        labelWithHash->setObjectName(QStringLiteral("labelWithHash"));
        labelWithHash->setGeometry(QRect(210, 80, 71, 16));
        labelWithSet = new QLabel(centralWidget);
        labelWithSet->setObjectName(QStringLiteral("labelWithSet"));
        labelWithSet->setGeometry(QRect(370, 80, 59, 15));
        labelTimeList = new QLabel(centralWidget);
        labelTimeList->setObjectName(QStringLiteral("labelTimeList"));
        labelTimeList->setGeometry(QRect(70, 210, 59, 15));
        labelTimeHash = new QLabel(centralWidget);
        labelTimeHash->setObjectName(QStringLiteral("labelTimeHash"));
        labelTimeHash->setGeometry(QRect(220, 210, 59, 15));
        labelTimeSet = new QLabel(centralWidget);
        labelTimeSet->setObjectName(QStringLiteral("labelTimeSet"));
        labelTimeSet->setGeometry(QRect(390, 210, 59, 16));
        txtTimeList = new QLineEdit(centralWidget);
        txtTimeList->setObjectName(QStringLiteral("txtTimeList"));
        txtTimeList->setGeometry(QRect(20, 230, 113, 23));
        txtTimeList->setFont(font1);
        txtTimeHash = new QLineEdit(centralWidget);
        txtTimeHash->setObjectName(QStringLiteral("txtTimeHash"));
        txtTimeHash->setGeometry(QRect(180, 230, 113, 23));
        txtTimeHash->setFont(font1);
        txtTimeSet = new QLineEdit(centralWidget);
        txtTimeSet->setObjectName(QStringLiteral("txtTimeSet"));
        txtTimeSet->setGeometry(QRect(350, 230, 113, 23));
        txtTimeSet->setFont(font1);
        btnTraducir = new QPushButton(centralWidget);
        btnTraducir->setObjectName(QStringLiteral("btnTraducir"));
        btnTraducir->setGeometry(QRect(350, 50, 80, 23));
        labelMessageList = new QLabel(centralWidget);
        labelMessageList->setObjectName(QStringLiteral("labelMessageList"));
        labelMessageList->setGeometry(QRect(20, 260, 131, 20));
        labelMessageList->setFont(font1);
        labelMessageHash = new QLabel(centralWidget);
        labelMessageHash->setObjectName(QStringLiteral("labelMessageHash"));
        labelMessageHash->setGeometry(QRect(180, 260, 131, 20));
        labelMessageHash->setFont(font1);
        labelMessageSet = new QLabel(centralWidget);
        labelMessageSet->setObjectName(QStringLiteral("labelMessageSet"));
        labelMessageSet->setGeometry(QRect(340, 260, 131, 20));
        labelMessageSet->setFont(font1);
        txtWithList = new QTextEdit(centralWidget);
        txtWithList->setObjectName(QStringLiteral("txtWithList"));
        txtWithList->setEnabled(true);
        txtWithList->setGeometry(QRect(10, 100, 141, 101));
        txtWithList->setFont(font1);
        txtWithHash = new QTextEdit(centralWidget);
        txtWithHash->setObjectName(QStringLiteral("txtWithHash"));
        txtWithHash->setEnabled(true);
        txtWithHash->setGeometry(QRect(170, 100, 151, 101));
        txtWithHash->setFont(font1);
        txtWithSet = new QTextEdit(centralWidget);
        txtWithSet->setObjectName(QStringLiteral("txtWithSet"));
        txtWithSet->setGeometry(QRect(340, 100, 141, 101));
        txtWithSet->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 494, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(actionload_in_List);
        menu_File->addAction(actionload_in_Hash);
        menu_File->addAction(actionload_in_Set);
        menu_File->addAction(action_Exit);
        menu_Help->addAction(action_About);
        mainToolBar->addAction(actionload_in_List);
        mainToolBar->addAction(actionload_in_Hash);
        mainToolBar->addAction(actionload_in_Set);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionload_in_List->setText(QApplication::translate("MainWindow", "load in &List", nullptr));
        actionload_in_Hash->setText(QApplication::translate("MainWindow", "load in &Hash", nullptr));
        actionload_in_Set->setText(QApplication::translate("MainWindow", "load in &Set", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        action_About->setText(QApplication::translate("MainWindow", "&About", nullptr));
        labelTitle->setText(QApplication::translate("MainWindow", "Diccionario del Ingles al Espa\303\261ol", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        txtWord->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        txtWord->setInputMask(QString());
        txtWord->setPlaceholderText(QString());
        labelWithList->setText(QApplication::translate("MainWindow", "With List", nullptr));
        labelWithHash->setText(QApplication::translate("MainWindow", "With Hash", nullptr));
        labelWithSet->setText(QApplication::translate("MainWindow", "With Set", nullptr));
        labelTimeList->setText(QApplication::translate("MainWindow", "time", nullptr));
        labelTimeHash->setText(QApplication::translate("MainWindow", "time", nullptr));
        labelTimeSet->setText(QApplication::translate("MainWindow", "time", nullptr));
        btnTraducir->setText(QApplication::translate("MainWindow", "Traducir", nullptr));
        labelMessageList->setText(QString());
        labelMessageHash->setText(QString());
        labelMessageSet->setText(QString());
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
