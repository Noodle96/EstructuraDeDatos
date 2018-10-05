#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include<iostream>
#include <fstream>
#include<algorithm>
#include <vector>
#include<dialogdot.h>

namespace Ui {
class MainWindow;
}

class QStandardItemModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getValueAl(int,int);
    void deltaHat(char EstadoInicial,std::string word);
    int getIndex(char p, std::vector<char>*v){
        int cont = 0;
        for(auto it = v->begin() ; it != v->end(); it++){
            if( (*it)==p ){
                return cont;
            }
            cont++;
        }

    }

private slots:
    //actions
    void on_action_Exit_triggered();
    void on_actionDot_triggered();
    void on_actionIniciar_triggered();
    void on_action_Clear_triggered();


    //slots
    void on_btnLlenartransiciones_clicked();
    void on_btnAddEstado_clicked();
    void on_btnAddAlfabeto_clicked();
    void on_btnAddEstadoInicial_clicked();
    void on_btnAddEstadoAceptacion_clicked();


    //okeys
    void on_ok1_clicked();
    void on_ok2_clicked();
    void on_ok3_clicked();
    void on_ok4_clicked();

    void on_btnFormarTransiciones_clicked();

    void on_btnVerificar_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *mModel;
    //imput
    std::string temp;
    std::vector<char> *estados;
    std::vector<char> *alfabeto;
    char EstadoInicial;
    std::vector<char> *estadosAceptacion;
    std::vector< std::vector<char> > matriz;

};

#endif // MAINWINDOW_H
