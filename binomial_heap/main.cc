#include <iostream>
using namespace std;

#include "binomialHeap.h"

int main(){

    BinomialHeap<int> bh;
    /*
    bh.insert(2312);
    //std::cout << bh.isUniqueBH() << std::endl;
    bh.insert(22);
    //std::cout << bh.isUniqueBH() << std::endl;
    bh.insert(24);
    bh.insert(123);
    bh.insert(345);
    */

    srand (time(NULL));
    int iSecret = 0;
    for(int e = 1  ; e <= 10; e++){
        iSecret = rand() % 100 + 1;
        //std::cout << "insert: " <<  iSecret << std::endl;
        //bh.insert(iSecret);
        bh.insert(e);
    }
    std::cout << "\n Linked List  de Nodos Binomial heap" << std::endl;
    bh.printList();


    std::cout << "GETMIN: " << bh.getMin() << std::endl;
    //std::cout << "\n Linked List  de Nodos Binomial heap con printGraphviz" << std::endl;
    //bh.printInGraphviz();
    //std::cout << "Minimo del heap Olog(1)" << std::endl;
    //std::cout << bh.getMin() << std::endl;
    //bh.printGraphviz();






    //std::cout  <<  ll.isUnique() << std::endl;

    //NodoLL<int> *tempRe = ll.begin();
    //NodoLL<int> *tempNor = ll.begin();

    /*
    while(tempRe){
        std::cout << tempRe->m_datoLL << endl;
        tempRe = tempRe->m_pSgteLL;
    }

    std::cout << "____________________" << std::endl;
    ll.print();
    */






    // LinkedList< NodoBH<int>* > ll;
    // for(int e = 0 ;e < 5 ; e++){
    //     //NodoBH<int> *temp = new NodoBH<int>(e*10);
    //     int val; cin>> val;
    //     NodoBH<int> * tempbh = new NodoBH<int>(val);
    //     NodoLL< NodoBH<int>* > *templl = new NodoLL< NodoBH<int>* >(tempbh);
    //     ll.push_frontNode(templl);
    // }
    // ll.printReference();
    // std::cout << "areglando" <<  std::endl;
    // int av; cin >> av;
    // NodoBH<int> * tempbh = new NodoBH<int>(av);
    // NodoLL< NodoBH<int>* > *templl = new NodoLL< NodoBH<int>* >(tempbh);
    //
    // ll.areglarWithNode(templl);
    // std::cout << "areglado" <<  std::endl;
    // ll.printReference();


    return 0;
}
