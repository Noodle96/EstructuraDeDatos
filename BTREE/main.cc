#include<iostream>
#include"pagina.h"
using namespace std;

int main(){
    Pagina<int,7> p1;
    p1.printPagina();
    std::cout << p1.isFull() << std::endl;
    std::cout << p1.isEmpty() << std::endl;

    return 0;
}
