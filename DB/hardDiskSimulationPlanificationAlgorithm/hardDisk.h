#ifndef HARDDISK_H
#define HARDDISK_H
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<algoricathm>
#include<stack> 

#define LIMITEPISTAS 1024*10
#define  PISTA = unsigned short int;

class HardDisk{
private:
    std::list< unsigned short int> pistas;
    //unsigned short int first;
public:
    HardDisk(){}
    void generarAleatorios(int);
    void test();
    void printPistas();

    //planification algorithm HardDisk
    float FIFO();
    float SSTF();
    float SCAN();
    float CSCAN();
};



#endif //HARDDISK_H
