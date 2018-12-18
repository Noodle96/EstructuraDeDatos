#include <iostream>
#include "avl.h"
using namespace std;




int main(){

    AVL<int> *a = new AVL<int>();
    a->getHead();
    std::cout << "Hola" << std::endl;
    // a->Add(300,a->getHeadA());
    // a->Add(100,a->getHeadA());
    // a->Add(500,a->getHeadA());
    // a->Add(400,a->getHeadA());
    // a->Add(350,a->getHeadA());
    // a->Add(600,a->getHeadA());
    for(int e = 1 ;   e < 1000 ; e++){
        a->Add(e,a->getHeadA());
    }


    a->printSVG();

    delete a;
    return 0;
}
