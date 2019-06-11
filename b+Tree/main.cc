                                 #include"Sequential.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include<list>
#include"index.h"
#include"cuenta.h"

int str_to_int(string number){
    stringstream geek(number);
    int num=0;
    geek>>num;
    return num;
}

void CargarFileWithRegisters(){
    // fstream file;
    // file.open("registrosTest.txt",ios::in);
    // string line ="";
    // std::string clave,ciudad,sueldo;
    // while(!file.eof()){
    //
    //     // getline(file,line);
    //     std::cout << clave << std::endl;
    //     std::cout << clave << std::endl;
    //     std::cout << sueldo << std::endl;
    // }
    // file.close();
}




using namespace std;

class Database{
private:
    SeqBPlusTree tree;
public:
    void insertD(Cuenta &cn){
        fstream entradaRelCuen;
        entradaRelCuen.open("relacionCuenta.dat",std::ios::out | std::ios::app | std::ios::binary);
        entradaRelCuen.write((char*)&cn, sizeof(cn)); //llena la tabla relacionCuenta
        entradaRelCuen.seekp(0, ios::end); // pone el cursor al final del archivo.
        int l = entradaRelCuen.tellp() / sizeof(cn); // la posicion actual
        entradaRelCuen.close();
        //![0]

        //insertando el index en el file Index
        //![1]
        Index i;
        i.setIndex(cn.getNumCuenta());
        i.setPos(l);
        fstream entradaIndex;
        entradaIndex.open("index.dat", std::ios::out | ios::app | ios::binary);
        entradaIndex.write( (char*)&i, sizeof(i) );//llena tabla index
        entradaIndex.close();
        //![1]
    }
    void printIndex(){
        fstream salidaIndex;
        salidaIndex.open("index.dat",std::ios::in|ios::binary);
        Index e;
        while( salidaIndex.read( (char*) &e, sizeof(e)) )  {
            // std::cout << "hola2" << std::endl;
            //std::cout << e.getIndex() << e.getPosition() << std::endl;
           e.datosConstantes();
          //(std:cout << e.getIndex() << std::endl;
           // std::cout << "hola3" << std::endl;
        }
        salidaIndex.close();
    }
    void printRelacionCuenta(){
        fstream salidaRelC;
        salidaRelC.open("relacionCuenta.dat",std::ios::in | std::ios::binary);
        Cuenta c;
        while( salidaRelC.read( (char*)&c ,sizeof(c)) ){
            c.printCuenta();
        }
        salidaRelC.close();
    }
    void CargarIndexToTree(){
        fstream salidaIndice;
        salidaIndice.open("index.dat",std::ios::in | std::ios::binary);
        Index e;
        while( salidaIndice.read( (char*)&e,sizeof(e)  ) ){
            // hashIndices.insert(std::make_pair(e.getIndex(),e.getPosition()));
            //e.datosConstantes();
            tree.insert(e.getIndex(),e.getPosition());
        }
        salidaIndice.close();
    }
    int findInTree(int key){
        return tree.search(key);
    }

    void selectFrom(int key){
        int DD = tree.search(key);
        if(  DD != -1 ){ //si lo encontro
            DD--;
            fstream salida_pri;
            Cuenta Ctst, Ctst2;
            salida_pri.open("relacionCuenta.dat",ios::in | ios::binary);
			salida_pri.seekg(sizeof(Ctst) * DD, ios::beg ); // te lleva a ese registro
			salida_pri.read( (char*) &Ctst2 , sizeof(Ctst2));
            Ctst2.printCuenta();
            salida_pri.close();
        }else{//no lo encontro
            std::cout << "registro no encontrado." << std::endl;
        }
    }
    void printInDot(){
        begin();
        tree.print();
        end();
        graph();
    }
};


int main(){
    Database db1;
    //here load file con registrs para agregarlos
    // Cuenta c1(124,"Apq",23);
    // Cuenta c2(121,"Puno",234);
    // c1.printCuenta();
    // c2.printCuenta();
    // db1.insertD(c1);
    // db1.insertD(c2);

    //std::cout << "printIndex" << std::endl;
    //db1.printIndex();

    //std::cout << "printRelaciones" << std::endl;
    //db1.printRelacionCuenta();

    ////////////////////////////////////////////////////////////////////////////////////////////////
                                    //cargar registros staticamente
    std:list<std::string> three;
    fstream file;
    file.open("50k.csv",ios::in);
    string line ="",temp;
    std::string clave,ciudad,sueldo;
    Cuenta Ct;
    getline(file,line);
    while(!file.eof()){

        // std::cout << clave << std::endl;
        // std::cout << clave << std::endl;
        // std::cout << sueldo << std::endl;
        for(auto it = line.begin() ; it != line.end(); it++){
            if((*it) != ','){
                temp += (*it);
            }else{
                three.push_back(temp);temp.clear();
            }
        }
        three.push_back(temp);temp.clear();temp.clear();
        auto it = three.begin();
        Ct.setNumCuenta( str_to_int((*it)) );
        it++;;
        Ct.setCiudad((*it));
        it++;
        Ct.setSaldo( str_to_int((*it)) ) ;
        db1.insertD(Ct);
        //std::cout << endl;
        three.clear();
        getline(file,line);
    }
    file.close();
    ////////////////////////////////////////////////////////////////////////////////////////////////



    db1.CargarIndexToTree();
    // std::cout << db1.findInTree(121) << std::endl;
    //db1.selectFrom(127);

    std::cout << "printIndex" << std::endl;
    db1.printIndex();

    std::cout << "printRelaciones" << std::endl;
    db1.printRelacionCuenta();
    int  hhk; cin >> hhk;
    db1.selectFrom(hhk);
    // db1.printInDot();




    return  0;
}
