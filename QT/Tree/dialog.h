#ifndef DIALOG_H
#define DIALOG_H
#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
#include <QDialog>
#include "bst.h"
#include "word.h"
#include "iterator.h"
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void limpiar();
    void mostrar(Word p);
    ~Dialog();

private slots:
    void on_btnLoad_clicked();

    void on_btnPrint_clicked();

    void on_btnBegin_clicked();

    void on_btnLast_clicked();

    void on_btnPrev_clicked();

    void on_btnNext_clicked();

    void on_btnLoadEnteros_clicked();

    void on_btnFind_clicked();

private:
    Ui::Dialog *ui;
    Bst<Word> diccionaty;
    Bst<int> enteros;
    Iterator<Word> *iterator_dictionary;
    Iterator<int> *iterator_enteros;


};

#endif // DIALOG_H
