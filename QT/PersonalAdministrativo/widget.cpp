#include "widget.h"
#include<string>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::limpiar(){
    this->ui->txtCodigo->setText("");
    this->ui->txtNombre->setText("");
}

void Widget::on_btnAgregar_clicked()
{
    Persona p;
    p.setCodigo(this->ui->txtCodigo->text().toInt());
    p.setNombre(this->ui->txtNombre->text().toStdString());
    lista.push_back(p);
    limpiar();
}

void Widget::mostrar(Persona &p){
   this->ui->txtCodigo->setText(QString::number(p.getCodigo()));
   this->ui->txtNombre->setText(p.getNombre().c_str());
}

void Widget::on_btnBegin_clicked()
{
    et = this->lista.begin();
    mostrar(*et);
    cout << (*et) << endl;
   // std::cout << (*et).getCodigo()<< std::endl;
   // std::cout << (*et).getNombre()<< std::endl;
}

void Widget::on_BtnLast_clicked()
{
    et = this->lista.end();
    mostrar(*et);
    cout << (*et) << endl;
}

void Widget::on_btnPrev_clicked()
{
    et--;
    mostrar(*et);
}

void Widget::on_btnNext_clicked()
{
    et++;
    mostrar(*et);
}
