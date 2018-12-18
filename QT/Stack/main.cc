#include<iostream>
using namespace std;

#include "stack.h"

int main(){


    Stack<int> *pila = new Stack<int>();
    std::cout << "isEmpty: "<< pila->isEmpty() << std::endl;
    pila->push(10);
    pila->push(34);
    pila->push(100);
    std::cout << "isEmpty: "<< pila->isEmpty() << std::endl;
    pila->print();

    std::cout << "\n" << '\n';
    std::cout << "top: " << pila->top() << '\n';
    pila->pop();
    pila->print();

    std::cout << "top: " << pila->top() << '\n';
    pila->pop();
    pila->print();

    std::cout << "top: " << pila->top() << '\n';
    pila->pop();
    pila->print();

    std::cout << "top: " << pila->top() << '\n';
    pila->pop() << '\n';
    pila->print();

    std::cout << "isEmpty: "<< pila->isEmpty() << endl;
    delete pila;
    return 0;
}
