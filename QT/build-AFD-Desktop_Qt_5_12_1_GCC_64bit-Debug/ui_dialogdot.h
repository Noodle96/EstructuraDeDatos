/********************************************************************************
** Form generated from reading UI file 'dialogdot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDOT_H
#define UI_DIALOGDOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogDot
{
public:
    QLabel *labelNodo;

    void setupUi(QDialog *DialogDot)
    {
        if (DialogDot->objectName().isEmpty())
            DialogDot->setObjectName(QString::fromUtf8("DialogDot"));
        DialogDot->resize(400, 300);
        labelNodo = new QLabel(DialogDot);
        labelNodo->setObjectName(QString::fromUtf8("labelNodo"));
        labelNodo->setGeometry(QRect(30, 10, 351, 271));

        retranslateUi(DialogDot);

        QMetaObject::connectSlotsByName(DialogDot);
    } // setupUi

    void retranslateUi(QDialog *DialogDot)
    {
        DialogDot->setWindowTitle(QApplication::translate("DialogDot", "Dialog", nullptr));
        labelNodo->setText(QApplication::translate("DialogDot", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDot: public Ui_DialogDot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDOT_H
