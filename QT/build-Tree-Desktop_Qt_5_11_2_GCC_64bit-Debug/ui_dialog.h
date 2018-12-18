/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *labelEnglish;
    QLabel *labelSpanish;
    QLineEdit *txtWordEnglish;
    QLineEdit *txtWordSpanish;
    QPushButton *btnLoad;
    QPushButton *btnPrint;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnBegin;
    QPushButton *btnPrev;
    QPushButton *btnNext;
    QPushButton *btnLast;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAdd;
    QPushButton *btnFind;
    QPushButton *btnDelete;
    QPushButton *btnSalir;
    QPushButton *btnLoadEnteros;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(568, 369);
        labelEnglish = new QLabel(Dialog);
        labelEnglish->setObjectName(QStringLiteral("labelEnglish"));
        labelEnglish->setGeometry(QRect(50, 70, 59, 15));
        labelSpanish = new QLabel(Dialog);
        labelSpanish->setObjectName(QStringLiteral("labelSpanish"));
        labelSpanish->setGeometry(QRect(50, 110, 59, 15));
        txtWordEnglish = new QLineEdit(Dialog);
        txtWordEnglish->setObjectName(QStringLiteral("txtWordEnglish"));
        txtWordEnglish->setGeometry(QRect(110, 70, 113, 23));
        txtWordSpanish = new QLineEdit(Dialog);
        txtWordSpanish->setObjectName(QStringLiteral("txtWordSpanish"));
        txtWordSpanish->setGeometry(QRect(110, 110, 311, 23));
        btnLoad = new QPushButton(Dialog);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        btnLoad->setGeometry(QRect(460, 30, 80, 23));
        btnPrint = new QPushButton(Dialog);
        btnPrint->setObjectName(QStringLiteral("btnPrint"));
        btnPrint->setGeometry(QRect(210, 320, 80, 23));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 270, 340, 25));
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

        btnLast = new QPushButton(layoutWidget);
        btnLast->setObjectName(QStringLiteral("btnLast"));

        horizontalLayout->addWidget(btnLast);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(460, 70, 84, 114));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnAdd = new QPushButton(layoutWidget1);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));

        verticalLayout->addWidget(btnAdd);

        btnFind = new QPushButton(layoutWidget1);
        btnFind->setObjectName(QStringLiteral("btnFind"));

        verticalLayout->addWidget(btnFind);

        btnDelete = new QPushButton(layoutWidget1);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));

        verticalLayout->addWidget(btnDelete);


        verticalLayout_2->addLayout(verticalLayout);

        btnSalir = new QPushButton(layoutWidget1);
        btnSalir->setObjectName(QStringLiteral("btnSalir"));

        verticalLayout_2->addWidget(btnSalir);

        btnLoadEnteros = new QPushButton(Dialog);
        btnLoadEnteros->setObjectName(QStringLiteral("btnLoadEnteros"));
        btnLoadEnteros->setGeometry(QRect(20, 20, 80, 23));

        retranslateUi(Dialog);
        QObject::connect(btnSalir, SIGNAL(clicked()), Dialog, SLOT(close()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dictionary [English-Spanish]", nullptr));
        labelEnglish->setText(QApplication::translate("Dialog", "Ingles", nullptr));
        labelSpanish->setText(QApplication::translate("Dialog", "Espa\303\261ol", nullptr));
        txtWordEnglish->setText(QString());
        txtWordEnglish->setPlaceholderText(QApplication::translate("Dialog", "word English", nullptr));
        txtWordSpanish->setText(QString());
        txtWordSpanish->setPlaceholderText(QApplication::translate("Dialog", "word Spanish", nullptr));
        btnLoad->setText(QApplication::translate("Dialog", "Load File", nullptr));
        btnPrint->setText(QApplication::translate("Dialog", "Print", nullptr));
        btnBegin->setText(QApplication::translate("Dialog", "<<|", nullptr));
        btnPrev->setText(QApplication::translate("Dialog", "<<", nullptr));
        btnNext->setText(QApplication::translate("Dialog", ">>", nullptr));
        btnLast->setText(QApplication::translate("Dialog", "|>>", nullptr));
        btnAdd->setText(QApplication::translate("Dialog", "&Add", nullptr));
        btnFind->setText(QApplication::translate("Dialog", "&Find", nullptr));
        btnDelete->setText(QApplication::translate("Dialog", "&Delete", nullptr));
        btnSalir->setText(QApplication::translate("Dialog", "Salir", nullptr));
        btnLoadEnteros->setText(QApplication::translate("Dialog", "Load Enteros", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
