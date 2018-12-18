#include "dialog.h"
#include <QApplication>
#include<iostream>
#include <fstream>
#include <string>
#include<list>
#include<set>
#include<algorithm>
using namespace std;

#include"bst.h"
#include "word.h"


void visitarLine(string line, string &ing, string &esp){
    auto it = line.begin();
    for( ;it != line.end() ; it++){
        if( (*it) != '#' ) ing+=(*it);
        else break;
    }
    it++;
    for( ; it != line.end(); it++){
        esp +=(*it);
    }
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    /*
    cout << "hola" << endl;
    Bst<int> *arbol = new Bst<int>();
    arbol->AddI(23);
    arbol->AddI(1);
    arbol->AddI(100);
    cout << arbol->altura(arbol->getHead()) << endl;
    cout << arbol->findR(100,arbol->getHead()) << endl;
    */
    Word w1("dog","perro"),w2;
    //cout << "ingles: " << w1.getIngles() << endl;
    //cout << "español: " << w1.getEspaniol() << endl;


    //testeando el vector infijo

    /*
    Bst<int> b;
    b.AddI(10);
    b.AddI(3);
    b.AddI(15);
    b.AddI(12);
    b.AddI(8);
    b.AddI(7);
    //b.printInfijo(b.getHead());
    vector< NodoBST<int>* > v;
    b.formarVectorInfijo(b.getHead(),v);
    auto it = v.begin();
    for( ; it != v.end(); it++ ){
        cout << (*it)->m_Dato << endl;
    }

    */




   // delete arbol;



    Bst<int> ints;
    ints.AddI(3);
    ints.AddI(10);
    ints.AddI(1);
    ints.AddI(7);
    ints.AddI(11);
    ints.AddI(77);
    ints.AddI(83);
    ints.AddI(96);
    //ints.printInfijo(ints.getHead()); cout << endl << endl;

    /*
   Iterator<int> *sub =ints.CreateIterator();
   for(sub->First(); !sub->IsDone(); sub->Next())
       {
           std::cout << sub->CurrentItem() << "\n";
       }

       */



    /*
    vector<int> *v = new vector<int>();
    v->push_back(4);
    v->push_back(5);
    v->push_back(13);
    v->push_back(17);
    v->push_back(20);

    Iterator<int> *sub =  new SubBst<int>(v);
    for(sub->First(); !sub->IsDone(); sub->Next())
        {
            std::cout << sub->CurrentItem() << "\n";
        }

*/



    /*
    QFile file("/home/Nano/QT/Tree/palabras.txt");
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            qDebug() << "could not open for read";
      QTextStream in(&file);
      QString line = in.readLine();
      while (!line.isNull()) {
          process_line(line.toStdString());
          //qDebug() << line << endl;
          line = in.readLine();
      }

    */




     cout << "test de archivosddd " << endl;
     fstream cartas;
     cartas.open("/home/Nano/QT/Tree/cartasClashRoyal.txt",ios::in);
     std::string esp="", ing ="";
     /*
     cartas >> esp;
     while(!cartas.eof()){
         cartas >> ing;
         cout << esp << ":" << ing << endl;
         cartas >> esp;
     }

     */

/*
     list< std::pair<string,string> > parejas;
     std::string line;
     while(getline(cartas,line)){
         visitarLine(line,ing,esp);
         //cout << ing << ":" << esp << endl;
         parejas.push_back(std::make_pair(ing,esp));
         ing.clear();
         esp.clear();
         line.clear();
     }

     //recorrer parejas

     cartas.close();
*/

     //RECORRIENDO EL PAIR DE PAREJAS
     //for(auto it = parejas.begin() ;it != parejas.end() ; it++){
         //cout << (*it).first << "->" << (*it).second << endl;
     //}

     list<int> listInt;
     set<int> setInt;
     int randT;
     for(int e = 0 ; e < 20 ; e++){
        randT = rand() % 10;
        listInt.push_back(randT);
        setInt.insert(randT);
     }

     //IMPRMIENDO LA LIST
     for(auto it =  listInt.begin() ; it != listInt.end(); it++){
         cout << (*it) << " " ;
     }
     cout << "\n\n";


     //IMPRIMIENDO EL SET
     for(auto it =  setInt.begin() ; it != setInt.end(); it++){
         cout << (*it) << " " ;
     }
     cout << "\n";

    auto it  = find(setInt.begin(),setInt.end() , 5);
    cout << (*it) << endl;
    it++;
    cout << (*it) << endl;

    return a.exec();
}

