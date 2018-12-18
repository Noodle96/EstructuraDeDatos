#include<iostream>
#include"binomialheap.h"
using namespace std;


int main(){
    srand (time(NULL));
    // NodoBH<int> g(45);
    // cout << g << endl;

    BinomialHeap<int> bh;

    NodoBH<int> *padre = new NodoBH<int>(1000);
    // bh.insertByOrder(23,3);
    // bh.insertByOrder(2,0);
    // bh.insertByOrder(84,2);
    // bh.insertByOrder(30,5);
    // bh.insertByOrder(23,0);
    // bh.insertByOrder(21,3);
    // bh.printOnlyListBH();
    // //int val ; cin>>val;
    // //bh.removeByDato(val);
    //
    // //bh.AsignarPadre(padre);
    //
    // bh.pushFront(padre);
    // bh.AsignarPadre(padre);
    // bh.printOnlyListBH();

    int Isecret ;
    for(int e = 0 ; e < 2;e++){
        Isecret = rand() % 100 + 1;
        bh.insertar(e);
    }
    //bh.printOnlyListBH();



    return 0;
}
