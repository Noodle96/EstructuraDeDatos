#include "dialogdot.h"
#include "ui_dialogdot.h"

DialogDot::DialogDot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDot)
{
    ui->setupUi(this);
    QPixmap pix("/home/Nano/QT/AFD/archivo.png");
    int w = this->ui->labelNodo->width();
    int h = this->ui->labelNodo->height();
    this->ui->labelNodo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio  ));
}

DialogDot::~DialogDot()
{
    delete ui;
}
