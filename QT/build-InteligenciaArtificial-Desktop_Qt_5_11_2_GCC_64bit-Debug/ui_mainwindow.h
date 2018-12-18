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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ActionOpenStopWords;
    QAction *ActionOpenPaper;
    QAction *ActionSave;
    QAction *ActionAboutAplication;
    QAction *ActionExit;
    QWidget *centralWidget;
    QPushButton *btnLoadFilePosition;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelWord;
    QLineEdit *txtWord;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPosition;
    QLineEdit *txtPosition;
    QLineEdit *txtGetFrecuency;
    QLineEdit *txtGetPositions;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelTitulo;
    QListWidget *listWidgetWords;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnGetFrecuency;
    QPushButton *btnGetPosicion;
    QLabel *labelMasFrecuentes;
    QLineEdit *txtMasRepetidas;
    QPushButton *btnGetMasRepetidas;
    QListWidget *listWidgetN;
    QLabel *labelNumberOfWords;
    QLineEdit *txtPalabrasTotales;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menu_Help;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(817, 386);
        ActionOpenStopWords = new QAction(MainWindow);
        ActionOpenStopWords->setObjectName(QStringLiteral("ActionOpenStopWords"));
        ActionOpenStopWords->setEnabled(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/rec/OpenImportant.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        ActionOpenStopWords->setIcon(icon);
        ActionOpenPaper = new QAction(MainWindow);
        ActionOpenPaper->setObjectName(QStringLiteral("ActionOpenPaper"));
        ActionOpenPaper->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/rec/openFile.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        ActionOpenPaper->setIcon(icon1);
        ActionSave = new QAction(MainWindow);
        ActionSave->setObjectName(QStringLiteral("ActionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/rec/save.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        ActionSave->setIcon(icon2);
        ActionAboutAplication = new QAction(MainWindow);
        ActionAboutAplication->setObjectName(QStringLiteral("ActionAboutAplication"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/rec/about.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        ActionAboutAplication->setIcon(icon3);
        ActionExit = new QAction(MainWindow);
        ActionExit->setObjectName(QStringLiteral("ActionExit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/rec/close.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        ActionExit->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnLoadFilePosition = new QPushButton(centralWidget);
        btnLoadFilePosition->setObjectName(QStringLiteral("btnLoadFilePosition"));
        btnLoadFilePosition->setGeometry(QRect(310, 100, 80, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(310, 70, 192, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelWord = new QLabel(layoutWidget);
        labelWord->setObjectName(QStringLiteral("labelWord"));

        horizontalLayout_2->addWidget(labelWord);

        txtWord = new QLineEdit(layoutWidget);
        txtWord->setObjectName(QStringLiteral("txtWord"));
        txtWord->setReadOnly(true);

        horizontalLayout_2->addWidget(txtWord);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(310, 40, 192, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelPosition = new QLabel(layoutWidget1);
        labelPosition->setObjectName(QStringLiteral("labelPosition"));

        horizontalLayout->addWidget(labelPosition);

        txtPosition = new QLineEdit(layoutWidget1);
        txtPosition->setObjectName(QStringLiteral("txtPosition"));

        horizontalLayout->addWidget(txtPosition);

        txtGetFrecuency = new QLineEdit(centralWidget);
        txtGetFrecuency->setObjectName(QStringLiteral("txtGetFrecuency"));
        txtGetFrecuency->setEnabled(true);
        txtGetFrecuency->setGeometry(QRect(150, 250, 141, 23));
        txtGetFrecuency->setAutoFillBackground(false);
        txtGetFrecuency->setInputMethodHints(Qt::ImhNone);
        txtGetFrecuency->setDragEnabled(false);
        txtGetFrecuency->setReadOnly(true);
        txtGetPositions = new QLineEdit(centralWidget);
        txtGetPositions->setObjectName(QStringLiteral("txtGetPositions"));
        txtGetPositions->setGeometry(QRect(150, 280, 141, 23));
        txtGetPositions->setReadOnly(true);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 20, 258, 215));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTitulo = new QLabel(layoutWidget2);
        labelTitulo->setObjectName(QStringLiteral("labelTitulo"));

        verticalLayout_2->addWidget(labelTitulo);

        listWidgetWords = new QListWidget(layoutWidget2);
        listWidgetWords->setObjectName(QStringLiteral("listWidgetWords"));

        verticalLayout_2->addWidget(listWidgetWords);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(40, 250, 98, 54));
        verticalLayout_3 = new QVBoxLayout(layoutWidget3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnGetFrecuency = new QPushButton(layoutWidget3);
        btnGetFrecuency->setObjectName(QStringLiteral("btnGetFrecuency"));

        verticalLayout_3->addWidget(btnGetFrecuency);

        btnGetPosicion = new QPushButton(layoutWidget3);
        btnGetPosicion->setObjectName(QStringLiteral("btnGetPosicion"));

        verticalLayout_3->addWidget(btnGetPosicion);

        labelMasFrecuentes = new QLabel(centralWidget);
        labelMasFrecuentes->setObjectName(QStringLiteral("labelMasFrecuentes"));
        labelMasFrecuentes->setGeometry(QRect(520, 20, 181, 20));
        txtMasRepetidas = new QLineEdit(centralWidget);
        txtMasRepetidas->setObjectName(QStringLiteral("txtMasRepetidas"));
        txtMasRepetidas->setGeometry(QRect(700, 20, 31, 23));
        txtMasRepetidas->setReadOnly(false);
        btnGetMasRepetidas = new QPushButton(centralWidget);
        btnGetMasRepetidas->setObjectName(QStringLiteral("btnGetMasRepetidas"));
        btnGetMasRepetidas->setGeometry(QRect(740, 20, 41, 23));
        listWidgetN = new QListWidget(centralWidget);
        listWidgetN->setObjectName(QStringLiteral("listWidgetN"));
        listWidgetN->setGeometry(QRect(520, 50, 256, 192));
        labelNumberOfWords = new QLabel(centralWidget);
        labelNumberOfWords->setObjectName(QStringLiteral("labelNumberOfWords"));
        labelNumberOfWords->setGeometry(QRect(310, 140, 111, 16));
        txtPalabrasTotales = new QLineEdit(centralWidget);
        txtPalabrasTotales->setObjectName(QStringLiteral("txtPalabrasTotales"));
        txtPalabrasTotales->setGeometry(QRect(310, 160, 113, 23));
        txtPalabrasTotales->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 817, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuArchivo->addAction(ActionOpenStopWords);
        menuArchivo->addAction(ActionOpenPaper);
        menuArchivo->addSeparator();
        menuArchivo->addSeparator();
        menuArchivo->addAction(ActionSave);
        menuArchivo->addAction(ActionExit);
        menu_Help->addAction(ActionAboutAplication);
        toolBar->addAction(ActionOpenStopWords);
        toolBar->addAction(ActionOpenPaper);
        toolBar->addAction(ActionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "What is the text about ?", nullptr));
        ActionOpenStopWords->setText(QApplication::translate("MainWindow", "&Open Stop Words", nullptr));
        ActionOpenPaper->setText(QApplication::translate("MainWindow", "&Open Paper", nullptr));
        ActionSave->setText(QApplication::translate("MainWindow", "&Save", nullptr));
        ActionAboutAplication->setText(QApplication::translate("MainWindow", "&About Aplication", nullptr));
        ActionExit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        btnLoadFilePosition->setText(QApplication::translate("MainWindow", "LoadFile", nullptr));
        labelWord->setText(QApplication::translate("MainWindow", "Word", nullptr));
        txtWord->setPlaceholderText(QApplication::translate("MainWindow", "        -------------------", nullptr));
        labelPosition->setText(QApplication::translate("MainWindow", "Position", nullptr));
        txtPosition->setPlaceholderText(QApplication::translate("MainWindow", "value position", nullptr));
        labelTitulo->setText(QApplication::translate("MainWindow", "Most Common Words of the Paper", nullptr));
        btnGetFrecuency->setText(QApplication::translate("MainWindow", "Get Frecuency", nullptr));
        btnGetPosicion->setText(QApplication::translate("MainWindow", "Get Posicions", nullptr));
        labelMasFrecuentes->setText(QApplication::translate("MainWindow", "The n Most Repeated Words", nullptr));
        btnGetMasRepetidas->setText(QApplication::translate("MainWindow", "Get", nullptr));
        labelNumberOfWords->setText(QApplication::translate("MainWindow", "Number of Words", nullptr));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
