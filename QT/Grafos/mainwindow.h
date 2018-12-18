#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "grafo.h"

#include <QMainWindow>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QtGui>
#include<QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addVertice_clicked();
    void on_btnaddArista_clicked();

private:
    Ui::MainWindow *ui;
    Grafo<std::string, int> grafo;
    QGraphicsItem *item;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
