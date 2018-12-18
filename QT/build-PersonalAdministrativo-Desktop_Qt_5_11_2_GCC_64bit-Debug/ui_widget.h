/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnSalir;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnBegin;
    QPushButton *btnPrev;
    QPushButton *btnNext;
    QPushButton *BtnLast;
    QLabel *labelCodigo;
    QLabel *labelNombre;
    QLineEdit *txtCodigo;
    QLineEdit *txtNombre;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAgregar;
    QPushButton *btnFind;
    QPushButton *btnDelete;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(752, 379);
        btnSalir = new QPushButton(Widget);
        btnSalir->setObjectName(QStringLiteral("btnSalir"));
        btnSalir->setGeometry(QRect(630, 320, 80, 23));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(180, 290, 340, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnBegin = new QPushButton(layoutWidget);
        btnBegin->setObjectName(QStringLiteral("btnBegin"));

        horizontalLayout->addWidget(btnBegin);

        btnPrev = new QPushButton(layoutWidget);
        btnPrev->setObjectName(QStringLiteral("btnPrev"));

        horizontalLayout->addWidget(btnPrev);

        btnNext = new QPushButton(layoutWidget);
        btnNext->setObjectName(QStringLiteral("btnNext"));

        horizontalLayout->addWidget(btnNext);

        BtnLast = new QPushButton(layoutWidget);
        BtnLast->setObjectName(QStringLiteral("BtnLast"));

        horizontalLayout->addWidget(BtnLast);

        labelCodigo = new QLabel(Widget);
        labelCodigo->setObjectName(QStringLiteral("labelCodigo"));
        labelCodigo->setGeometry(QRect(50, 80, 42, 23));
        labelNombre = new QLabel(Widget);
        labelNombre->setObjectName(QStringLiteral("labelNombre"));
        labelNombre->setGeometry(QRect(50, 110, 48, 23));
        txtCodigo = new QLineEdit(Widget);
        txtCodigo->setObjectName(QStringLiteral("txtCodigo"));
        txtCodigo->setGeometry(QRect(100, 80, 176, 23));
        txtNombre = new QLineEdit(Widget);
        txtNombre->setObjectName(QStringLiteral("txtNombre"));
        txtNombre->setGeometry(QRect(100, 110, 358, 23));
        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(620, 60, 82, 83));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnAgregar = new QPushButton(layoutWidget1);
        btnAgregar->setObjectName(QStringLiteral("btnAgregar"));

        verticalLayout->addWidget(btnAgregar);

        btnFind = new QPushButton(layoutWidget1);
        btnFind->setObjectName(QStringLiteral("btnFind"));
        btnFind->setCheckable(true);

        verticalLayout->addWidget(btnFind);

        btnDelete = new QPushButton(layoutWidget1);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        verticalLayout->addWidget(btnDelete);


        retranslateUi(Widget);
        QObject::connect(btnSalir, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        btnSalir->setText(QApplication::translate("Widget", "Salir", nullptr));
        btnBegin->setText(QApplication::translate("Widget", "<<\302\260", nullptr));
        btnPrev->setText(QApplication::translate("Widget", "<<", nullptr));
        btnNext->setText(QApplication::translate("Widget", ">>", nullptr));
        BtnLast->setText(QApplication::translate("Widget", "\302\260>>", nullptr));
        labelCodigo->setText(QApplication::translate("Widget", "Codigo", nullptr));
        labelNombre->setText(QApplication::translate("Widget", "Nombre", nullptr));
        btnAgregar->setText(QApplication::translate("Widget", "&Add", nullptr));
        btnFind->setText(QApplication::translate("Widget", "&Find", nullptr));
        btnDelete->setText(QApplication::translate("Widget", "&Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
