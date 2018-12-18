#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include <QFileDialog>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<list>
#include<set>
#include<unordered_map>
#include "word.h"
#include<ctime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void VisitarLline(std::string lline, std::string &ing, std::string &esp);

private slots:
    void on_actionload_in_List_triggered();
    void on_actionload_in_Hash_triggered();
    void on_actionload_in_Set_triggered();
    void on_action_Exit_triggered();

    void on_btnTraducir_clicked();

    void on_action_About_triggered();

private:
    Ui::MainWindow *ui;
    std::list<Word> *listWord;
    std::set<Word> *setWord;
    std::unordered_map<std::string, Word> *un_m;
};

#endif // MAINWINDOW_H
