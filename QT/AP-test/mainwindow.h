#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPixmap>
#include <QMessageBox>
#include <iostream>
#include<fstream>
#include <stack>
#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void llenarMatriz();
    bool verificarPertenencia(std::string);
    bool deltaHat(std::string Eo,std::string w);
    ~MainWindow();

private slots:
    void on_btnVerificar_clicked();
    void on_action_exit_triggered();

    void on_actionDot_triggered();

private:
    Ui::MainWindow *ui;
    std::list<std::string> *estados;
    std::list<std::string> *estadosAceptacion;
    std::string estadoInicial;
    std::list<char> *alfabeto;
    std::list<std::string> *alfabetoPila;
    std::map< std::string, std::map< std::string, std::string > > *M;

    std::map< std::string, std::map< std::string, std::string > > t;

    std::stack<std::string> *pila;

};

#endif // MAINWINDOW_H
