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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Dot;
    QAction *action_Iniciar;
    QAction *action_Clear;
    QAction *action_Exit;
    QAction *action_Help;
    QWidget *centralWidget;
    QLabel *labelEstado;
    QLabel *labelAlfabeto;
    QLabel *labelEstadoInicial;
    QLabel *labelEstadoAceptacion;
    QLabel *labelInput;
    QLineEdit *txtEstado;
    QLineEdit *txtAlfabeto;
    QLineEdit *txtEstadoInicial;
    QLineEdit *txtEstadoAceptacion;
    QPushButton *btnAddEstado;
    QPushButton *btnAddAlfabeto;
    QPushButton *okEstado;
    QPushButton *okEstadoInicial;
    QPushButton *btnAddEstadoInicial;
    QPushButton *okAlfabeto;
    QPushButton *okEstadoAceptacion;
    QPushButton *btnAddEstadoAceptacion;
    QFrame *lineVertical1;
    QFrame *line;
    QLabel *labelEstados;
    QLabel *labelAlfabetos;
    QLabel *labelMaquina;
    QLineEdit *txtEstados;
    QLabel *labelEstadosAceptacion;
    QLineEdit *txtAlfabetos;
    QLineEdit *txtEstadosAceptaciones;
    QLineEdit *txtEstadosIniciales;
    QLabel *labelEstadosIniciales;
    QFrame *lineVertical2;
    QFrame *lineHorizontal2;
    QLabel *labelCadena;
    QLineEdit *txtCadena;
    QPushButton *btnVerificarCadena;
    QTableView *tableViewTransiciones;
    QLabel *labelTablaTran;
    QPushButton *btnLlenarTransiciones;
    QPushButton *btnOkeyLlenadoTransiciones;
    QLabel *labelNodo;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_About;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1355, 577);
        action_Dot = new QAction(MainWindow);
        action_Dot->setObjectName(QStringLiteral("action_Dot"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/dot.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Dot->setIcon(icon);
        action_Iniciar = new QAction(MainWindow);
        action_Iniciar->setObjectName(QStringLiteral("action_Iniciar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/iniciar.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Iniciar->setIcon(icon1);
        action_Clear = new QAction(MainWindow);
        action_Clear->setObjectName(QStringLiteral("action_Clear"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/clear.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Clear->setIcon(icon2);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Resources/close.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Exit->setIcon(icon3);
        action_Help = new QAction(MainWindow);
        action_Help->setObjectName(QStringLiteral("action_Help"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Resources/about.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_Help->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelEstado = new QLabel(centralWidget);
        labelEstado->setObjectName(QStringLiteral("labelEstado"));
        labelEstado->setGeometry(QRect(20, 50, 59, 15));
        labelAlfabeto = new QLabel(centralWidget);
        labelAlfabeto->setObjectName(QStringLiteral("labelAlfabeto"));
        labelAlfabeto->setGeometry(QRect(20, 80, 59, 15));
        labelEstadoInicial = new QLabel(centralWidget);
        labelEstadoInicial->setObjectName(QStringLiteral("labelEstadoInicial"));
        labelEstadoInicial->setGeometry(QRect(20, 110, 59, 15));
        labelEstadoAceptacion = new QLabel(centralWidget);
        labelEstadoAceptacion->setObjectName(QStringLiteral("labelEstadoAceptacion"));
        labelEstadoAceptacion->setGeometry(QRect(20, 140, 59, 15));
        labelInput = new QLabel(centralWidget);
        labelInput->setObjectName(QStringLiteral("labelInput"));
        labelInput->setGeometry(QRect(110, 20, 59, 15));
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(true);
        font.setWeight(75);
        font.setStrikeOut(false);
        labelInput->setFont(font);
        txtEstado = new QLineEdit(centralWidget);
        txtEstado->setObjectName(QStringLiteral("txtEstado"));
        txtEstado->setGeometry(QRect(80, 50, 71, 23));
        txtAlfabeto = new QLineEdit(centralWidget);
        txtAlfabeto->setObjectName(QStringLiteral("txtAlfabeto"));
        txtAlfabeto->setGeometry(QRect(80, 80, 71, 23));
        txtEstadoInicial = new QLineEdit(centralWidget);
        txtEstadoInicial->setObjectName(QStringLiteral("txtEstadoInicial"));
        txtEstadoInicial->setGeometry(QRect(80, 110, 71, 23));
        txtEstadoAceptacion = new QLineEdit(centralWidget);
        txtEstadoAceptacion->setObjectName(QStringLiteral("txtEstadoAceptacion"));
        txtEstadoAceptacion->setGeometry(QRect(80, 140, 71, 23));
        btnAddEstado = new QPushButton(centralWidget);
        btnAddEstado->setObjectName(QStringLiteral("btnAddEstado"));
        btnAddEstado->setGeometry(QRect(160, 50, 51, 23));
        btnAddAlfabeto = new QPushButton(centralWidget);
        btnAddAlfabeto->setObjectName(QStringLiteral("btnAddAlfabeto"));
        btnAddAlfabeto->setGeometry(QRect(160, 80, 51, 23));
        okEstado = new QPushButton(centralWidget);
        okEstado->setObjectName(QStringLiteral("okEstado"));
        okEstado->setGeometry(QRect(220, 50, 31, 23));
        okEstadoInicial = new QPushButton(centralWidget);
        okEstadoInicial->setObjectName(QStringLiteral("okEstadoInicial"));
        okEstadoInicial->setGeometry(QRect(220, 110, 31, 23));
        btnAddEstadoInicial = new QPushButton(centralWidget);
        btnAddEstadoInicial->setObjectName(QStringLiteral("btnAddEstadoInicial"));
        btnAddEstadoInicial->setGeometry(QRect(160, 110, 51, 23));
        okAlfabeto = new QPushButton(centralWidget);
        okAlfabeto->setObjectName(QStringLiteral("okAlfabeto"));
        okAlfabeto->setGeometry(QRect(220, 80, 31, 23));
        okEstadoAceptacion = new QPushButton(centralWidget);
        okEstadoAceptacion->setObjectName(QStringLiteral("okEstadoAceptacion"));
        okEstadoAceptacion->setGeometry(QRect(220, 140, 31, 23));
        btnAddEstadoAceptacion = new QPushButton(centralWidget);
        btnAddEstadoAceptacion->setObjectName(QStringLiteral("btnAddEstadoAceptacion"));
        btnAddEstadoAceptacion->setGeometry(QRect(160, 140, 51, 23));
        lineVertical1 = new QFrame(centralWidget);
        lineVertical1->setObjectName(QStringLiteral("lineVertical1"));
        lineVertical1->setGeometry(QRect(260, 10, 20, 481));
        lineVertical1->setFrameShape(QFrame::VLine);
        lineVertical1->setFrameShadow(QFrame::Sunken);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 190, 241, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        labelEstados = new QLabel(centralWidget);
        labelEstados->setObjectName(QStringLiteral("labelEstados"));
        labelEstados->setGeometry(QRect(21, 242, 48, 16));
        labelAlfabetos = new QLabel(centralWidget);
        labelAlfabetos->setObjectName(QStringLiteral("labelAlfabetos"));
        labelAlfabetos->setGeometry(QRect(21, 271, 60, 16));
        labelMaquina = new QLabel(centralWidget);
        labelMaquina->setObjectName(QStringLiteral("labelMaquina"));
        labelMaquina->setGeometry(QRect(87, 221, 58, 16));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        labelMaquina->setFont(font1);
        txtEstados = new QLineEdit(centralWidget);
        txtEstados->setObjectName(QStringLiteral("txtEstados"));
        txtEstados->setGeometry(QRect(87, 242, 161, 23));
        txtEstados->setReadOnly(false);
        labelEstadosAceptacion = new QLabel(centralWidget);
        labelEstadosAceptacion->setObjectName(QStringLiteral("labelEstadosAceptacion"));
        labelEstadosAceptacion->setGeometry(QRect(21, 329, 54, 16));
        txtAlfabetos = new QLineEdit(centralWidget);
        txtAlfabetos->setObjectName(QStringLiteral("txtAlfabetos"));
        txtAlfabetos->setGeometry(QRect(87, 271, 161, 23));
        txtEstadosAceptaciones = new QLineEdit(centralWidget);
        txtEstadosAceptaciones->setObjectName(QStringLiteral("txtEstadosAceptaciones"));
        txtEstadosAceptaciones->setGeometry(QRect(87, 329, 161, 23));
        txtEstadosIniciales = new QLineEdit(centralWidget);
        txtEstadosIniciales->setObjectName(QStringLiteral("txtEstadosIniciales"));
        txtEstadosIniciales->setGeometry(QRect(87, 300, 161, 23));
        labelEstadosIniciales = new QLabel(centralWidget);
        labelEstadosIniciales->setObjectName(QStringLiteral("labelEstadosIniciales"));
        labelEstadosIniciales->setGeometry(QRect(21, 300, 55, 16));
        lineVertical2 = new QFrame(centralWidget);
        lineVertical2->setObjectName(QStringLiteral("lineVertical2"));
        lineVertical2->setGeometry(QRect(940, 10, 16, 481));
        lineVertical2->setFrameShape(QFrame::VLine);
        lineVertical2->setFrameShadow(QFrame::Sunken);
        lineHorizontal2 = new QFrame(centralWidget);
        lineHorizontal2->setObjectName(QStringLiteral("lineHorizontal2"));
        lineHorizontal2->setGeometry(QRect(280, 410, 661, 21));
        lineHorizontal2->setFrameShape(QFrame::HLine);
        lineHorizontal2->setFrameShadow(QFrame::Sunken);
        labelCadena = new QLabel(centralWidget);
        labelCadena->setObjectName(QStringLiteral("labelCadena"));
        labelCadena->setGeometry(QRect(300, 450, 59, 15));
        txtCadena = new QLineEdit(centralWidget);
        txtCadena->setObjectName(QStringLiteral("txtCadena"));
        txtCadena->setGeometry(QRect(370, 450, 441, 23));
        btnVerificarCadena = new QPushButton(centralWidget);
        btnVerificarCadena->setObjectName(QStringLiteral("btnVerificarCadena"));
        btnVerificarCadena->setGeometry(QRect(830, 450, 80, 23));
        tableViewTransiciones = new QTableView(centralWidget);
        tableViewTransiciones->setObjectName(QStringLiteral("tableViewTransiciones"));
        tableViewTransiciones->setGeometry(QRect(960, 50, 381, 281));
        labelTablaTran = new QLabel(centralWidget);
        labelTablaTran->setObjectName(QStringLiteral("labelTablaTran"));
        labelTablaTran->setGeometry(QRect(1060, 20, 181, 16));
        labelTablaTran->setFont(font1);
        btnLlenarTransiciones = new QPushButton(centralWidget);
        btnLlenarTransiciones->setObjectName(QStringLiteral("btnLlenarTransiciones"));
        btnLlenarTransiciones->setGeometry(QRect(970, 340, 121, 23));
        btnOkeyLlenadoTransiciones = new QPushButton(centralWidget);
        btnOkeyLlenadoTransiciones->setObjectName(QStringLiteral("btnOkeyLlenadoTransiciones"));
        btnOkeyLlenadoTransiciones->setGeometry(QRect(1250, 340, 80, 23));
        labelNodo = new QLabel(centralWidget);
        labelNodo->setObjectName(QStringLiteral("labelNodo"));
        labelNodo->setGeometry(QRect(290, 25, 641, 381));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1355, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_About = new QMenu(menuBar);
        menu_About->setObjectName(QStringLiteral("menu_About"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_About->menuAction());
        menu_File->addAction(action_Dot);
        menu_File->addAction(action_Iniciar);
        menu_File->addAction(action_Clear);
        menu_File->addAction(action_Exit);
        menu_About->addAction(action_Help);
        mainToolBar->addAction(action_Dot);
        mainToolBar->addAction(action_Iniciar);
        mainToolBar->addAction(action_Clear);
        mainToolBar->addAction(action_Exit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Dot->setText(QApplication::translate("MainWindow", "&Dot", nullptr));
        action_Iniciar->setText(QApplication::translate("MainWindow", "&Iniciar", nullptr));
        action_Clear->setText(QApplication::translate("MainWindow", "&Clear", nullptr));
        action_Exit->setText(QApplication::translate("MainWindow", "&Exit", nullptr));
        action_Help->setText(QApplication::translate("MainWindow", "&Help", nullptr));
        labelEstado->setText(QApplication::translate("MainWindow", "Estado", nullptr));
        labelAlfabeto->setText(QApplication::translate("MainWindow", "Alfabeto", nullptr));
        labelEstadoInicial->setText(QApplication::translate("MainWindow", "Estado I", nullptr));
        labelEstadoAceptacion->setText(QApplication::translate("MainWindow", "Estado A", nullptr));
        labelInput->setText(QApplication::translate("MainWindow", "Input", nullptr));
        btnAddEstado->setText(QApplication::translate("MainWindow", "Add", nullptr));
        btnAddAlfabeto->setText(QApplication::translate("MainWindow", "Add", nullptr));
        okEstado->setText(QApplication::translate("MainWindow", "Ok", nullptr));
        okEstadoInicial->setText(QApplication::translate("MainWindow", "Ok", nullptr));
        btnAddEstadoInicial->setText(QApplication::translate("MainWindow", "Add", nullptr));
        okAlfabeto->setText(QApplication::translate("MainWindow", "Ok", nullptr));
        okEstadoAceptacion->setText(QApplication::translate("MainWindow", "OK", nullptr));
        btnAddEstadoAceptacion->setText(QApplication::translate("MainWindow", "Add", nullptr));
        labelEstados->setText(QApplication::translate("MainWindow", "Estados", nullptr));
        labelAlfabetos->setText(QApplication::translate("MainWindow", "Alfabeto's", nullptr));
        labelMaquina->setText(QApplication::translate("MainWindow", "Maquina", nullptr));
        labelEstadosAceptacion->setText(QApplication::translate("MainWindow", "Estado A", nullptr));
        labelEstadosIniciales->setText(QApplication::translate("MainWindow", "Estados I", nullptr));
        labelCadena->setText(QApplication::translate("MainWindow", "Cadena", nullptr));
        btnVerificarCadena->setText(QApplication::translate("MainWindow", "Verificar", nullptr));
        labelTablaTran->setText(QApplication::translate("MainWindow", "Input - Tabla de Transiciones", nullptr));
        btnLlenarTransiciones->setText(QApplication::translate("MainWindow", "Llenar Transiciones", nullptr));
        btnOkeyLlenadoTransiciones->setText(QApplication::translate("MainWindow", "Ok", nullptr));
        labelNodo->setText(QString());
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menu_About->setTitle(QApplication::translate("MainWindow", "&About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
