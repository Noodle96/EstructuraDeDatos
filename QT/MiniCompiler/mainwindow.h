#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<QMessageBox>
#include<QDebug>
#include<QFile>
#include<QTextStream>
#include "word.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadFilePalabrasReservadas();
    void loadFileOPeradoresSeparadores();
    void saveTextEditIntxt();

    std::string formatearSinEspacios(std::string w);
    void agregarInContainer(std::string  word, int linea);
    void visitarLLinea(std::string llinea, int numLinea);

    bool findInPReservadas(std::string w, int numLinea);
    bool findInOperadores(std::string w, int numLinea);
    void AddInVariables(std::string w, int numLinea);
    bool isNUmber(std::string);

private slots:
    void on_btnRun_clicked();

private:
    Ui::MainWindow *ui;
    std::unordered_map<std::string, std::string> pReservadas;
    std::unordered_map<std::string, std::string> pSeparadoresOperadores;
    std::list<Word> F;
    std::list<Word> Variables;
};

#endif // MAINWINDOW_H
