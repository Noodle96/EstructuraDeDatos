#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"
#include<iostream>
using namespace std;
#include<list>
#include "persona.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget{
    Q_OBJECT
private:
    Ui::Widget *ui;
    list<Persona> lista;
    list<Persona>::iterator et;
public:
    explicit Widget(QWidget *parent = nullptr);
    void limpiar();
    void mostrar(Persona&p);
    ~Widget();
private slots:
    void on_btnAgregar_clicked();
    void on_btnBegin_clicked();
    void on_BtnLast_clicked();
    void on_btnPrev_clicked();
    void on_btnNext_clicked();
};

#endif // WIDGET_H
