#include<iostream>
#include"hardDisk.h"
//using namespace std;

int main(){
    HardDisk hd;
    //hd.test();
    int a; std::cin>>a;
    hd.generarAleatorios(a);
    //hd.printPistas();
    std::cout <<"FIFO : recorrido promedio del brazo por las pistas "<< hd.FIFO() <<"K" <<  std::endl;
    std::cout << "SSTF :  recorrido promedio del brazo por las pistas "  << hd.SSTF() << "K" << std::endl;
    std::cout << "SCAN: recorrido promedio del brazo por las pistas " << hd.SCAN()  << "K"<< std::endl;
    std::cout << "CSCAN : recorrido promedio del brazo por las pistas " << hd.CSCAN() << "K" << std::endl;

    return 0;
}
