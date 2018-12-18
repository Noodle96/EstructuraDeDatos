#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include<fstream>
#include<QMessageBox>
#include <QMainWindow>
#include<QStandardItemModel>
#include<QTextStream>
#include <QDebug>
#include <list>
#include <vector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getPositionEstado(std::string);
    int getPositionAlfabeto(char);
    QString getValueAl(int,int);
    void transformToList(std::string, std::vector<std::string>&);
    bool verificarPertenencia(std::string);
    void deltaHat(std::list< std::string > &,std::string);
    bool interseccion(std::list< std::string > &);


private slots:

    //ACTIONS
    void on_action_Dot_triggered();
    void on_action_Iniciar_triggered();
    void on_action_Clear_triggered();
    void on_action_Exit_triggered();
    void on_action_Help_triggered();

    void on_btnAddEstado_clicked();
    void on_btnAddAlfabeto_clicked();
    void on_btnAddEstadoInicial_clicked();
    void on_btnAddEstadoAceptacion_clicked();


    void on_okEstado_clicked();
    void on_okAlfabeto_clicked();
    void on_okEstadoInicial_clicked();
    void on_okEstadoAceptacion_clicked();

    void on_btnLlenarTransiciones_clicked();
    void on_btnOkeyLlenadoTransiciones_clicked();

    void on_btnVerificarCadena_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *mModel;

    std::list<std::string> *estados;
    std::list<char> *alfabeto;
    std::list<std::string> *estadosAceptacion;
    std::string estadoInicial;

    std::vector< std::vector<  std::vector<std::string> >  > Matriz;


};

#endif // MAINWINDOW_H
