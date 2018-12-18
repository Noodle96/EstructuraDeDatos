#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include<iostream>
#include<fstream>
#include<list>
using namespace std;
#include"functionsTest.h"
#include <QMainWindow>
#include <QDebug>
#include<QMessageBox>
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QtGui>
#include"state.h"
#include "normalizarstring.h"
//#include "DFA.h"
//#include "NFA.h"
#include "phrases.h"



namespace Ui {
class MainWindow;
}

/*
namespace std {

  //template <>
  template<typename T>
  struct hash<State<T>>
  {
    std::size_t operator()(const State<T>& k) const
    {
      using std::size_t;
      using std::hash;
      using std::string;

      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:

      return (    (  hash< State<T> >()(k.getDato())  )   );
    }
  };

}

*/

/*
namespace std {

  //template <>
  template<typename T>
  struct hash<Alphabet<T>>
  {
    std::size_t operator()(const Alphabet<T>& k) const
    {
      using std::size_t;
      using std::hash;
      using std::string;

      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:

      return ((hash<T>()(k.dato)));
    }
  };

}
*/


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void normalizarInPhrases(std::string, list< Phrase > &);
    void printListPhrasesGeneral(std::list<Phrase> &);

    void analizeListPhrases(std::list< Phrase > &, std::list< std::pair< NFA<string,string>,char > > &listpair, NFA<string,string> &final );
    void visitarAFondoCrearAutomataIt(NFA<std::string, std::string > &nfat, Phrase &p );



    bool verificarListPhraseUno(std::list<Phrase> &);
    void hacerLen1Todos(Phrase&);
    void normalizeFontListPhrases(std::list<Phrase>&);


    bool verifyPertenecia(std::string w);

    void printListNFA();
    void printInDotNFA();
    void printInDotDFA();
    ~MainWindow();

private slots:
    void on_btnGenerate_clicked();

    //ACTIONS
    void on_action_Clear_triggered();
    void on_action_Exit_triggered();
    void on_action_About_triggered();

    void on_btnVerifyAFND_clicked();

private:
    Ui::MainWindow *ui;
    std::list<  std::pair<  NFA<std::string, std::string>, char >  >  listNFA;
    std::list<Phrase> listPhrases;
    DFA<std::string, std::string> dfa;

    QGraphicsItem *item;
    QGraphicsScene *scene;

};

#endif // MAINWINDOW_H
