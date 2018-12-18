#include<iostream>
using namespace std;
 #include "doubleLinkedList.h"


int main(){

    DoubleLinkedList<int> *dll1 = new DoubleLinkedList<int>();
    // std::cout << dll1->isEmpty() << '\n';
    // dll1->addFront(15);
    // dll1->addFront(25);
    // dll1->addLast(100);
    // dll1->addLast(150);
    // dll1->printI();
    // std::cout << dll1->isEmpty() << '\n';
    dll1->Add(100);
    dll1->Add(50);
    dll1->Add(300);
    dll1->printR(dll1->getHead());
    std::cout << dll1->Delete(100) << '\n';
    dll1->printR(dll1->getHead());

    delete dll1;


    return  0;
}
