#include<iostream>
using namespace std;

#include "queue.h"

int main(){

    Queue<int> *cola = new Queue<int>();
    std::cout << "isEmpty: " << cola->isEmpty()<<  '\n';
    cola->push(34);
    cola->push(24);
    cola->push(100);
    std::cout << "isEmpty: " << cola->isEmpty()<<  '\n';
    cola->print();

    std::cout << "top: " <<cola->top() <<'\n';
    cola->pop();
    cola->print();

    std::cout << "top: " <<cola->top() <<'\n';
    cola->pop();
    cola->print();

    std::cout << "top: " <<cola->top() <<'\n';
    cola->pop();
    cola->print();


    std::cout << "top: " <<cola->top() <<'\n';
    cola->pop();
    cola->print();
    std::cout << "isEmpty: " << cola->isEmpty()<<  '\n';


    delete cola;

    return 0;
}
