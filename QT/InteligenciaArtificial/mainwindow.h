#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<fstream>
#include <QDebug>
#include <list>
#include <QFileDialog>
#include <QMessageBox>
#include "bst.h"
#include "word.h"
#include "functions.h"
#include "linkedlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void visitar(NodoBST<Word> *l);

private slots:

    void on_btnLoadFilePosition_clicked();

    void on_btnGetFrecuency_clicked();

    void on_btnGetPosicion_clicked();

    void on_ActionOpenStopWords_triggered();

    void on_ActionOpenPaper_triggered();

    void on_ActionSave_triggered();

    void on_ActionAboutAplication_triggered();

    void on_ActionExit_triggered();

    void on_btnGetMasRepetidas_clicked();

private:
    int cantTotal;
    Ui::MainWindow *ui;
    bst<std::string> *SWTree;
    bst<Word> *PPTree;
    std::string filenameCurrent;
    std::list< NodoBST<Word>* > rankeados;

};

#endif // MAINWINDOW_H
