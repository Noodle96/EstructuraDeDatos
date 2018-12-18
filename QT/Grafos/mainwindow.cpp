#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addVertice_clicked()
{
    QString input = this->ui->txtVertice->text();
    if(input.isEmpty()){
        QMessageBox::information(this,"aviso","Empty input");
        return;
    }
    std::string inputS = input.toStdString();

    grafo.addVertice(inputS);

    //grafo.print();
    //grafo.addArista("Arequipa","Cusco",80);


    grafo.PrintInDot();
    QImage image("/home/Nano/QT/Grafos/file.png");
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene = new QGraphicsScene(this);
    this->ui->graphicsView->setScene(scene);
    scene->addItem(item);

    //limpiando input
    this->ui->txtVertice->setText("");
    return;
}

void MainWindow::on_btnaddArista_clicked()
{
    std::string origen = this->ui->txtOrigen->text().toStdString();
    std::string destino = this->ui->txtDestino->text().toStdString();
    QString pesoQ = this->ui->peso->text();
    if(pesoQ.isEmpty()){
        QMessageBox::information(this,"Aviso","peso vacio");
        return;
    }
    int peso = pesoQ.toInt();
    if(origen.empty() || destino.empty()){
        QMessageBox::information(this,"Aviso","Imcompleto");
        return;
    }
    if( !grafo.addArista(origen,destino,peso) ){
        QMessageBox::information(this,"Aviso","Origen or destino no encotrados");
        return;
    }
    grafo.PrintInDot();
    QImage image("/home/Nano/QT/Grafos/file.png");
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene = new QGraphicsScene(this);
    this->ui->graphicsView->setScene(scene);
    scene->addItem(item);
    //limpiando
    this->ui->txtDestino->setText("");
    this->ui->txtOrigen->setText("");
    this->ui->peso->setText("");
}
