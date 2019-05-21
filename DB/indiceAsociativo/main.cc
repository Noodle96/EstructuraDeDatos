#include<iostream>
#include<list>
#include"database.h"


using namespace std;


int main(){
    Cuenta c1("C-124","Arequipa",750);
    Cuenta c2("C-567","Puno",130);
    Cuenta c3("C-239","Arequipa",170);
    Cuenta c4("C-967","Moquegua",890);
    Cuenta c5("C-865","Tacna",1050);
    Cuenta c6("C-725","Cusco",180);
    Cuenta c7("C-301","Cusco",870);
    std::list<Cuenta> lc;
    lc.push_back(c1);lc.push_back(c2);lc.push_back(c3);lc.push_back(c4);
    lc.push_back(c5);lc.push_back(c6); lc.push_back(c7);Database db;
    for(auto it = lc.begin() ; it != lc.end() ; it++){
        //db.insert(*it);
    }
    // Cuenta c8("C-905","Lima",1090); db.insert(c8);
    // Cuenta c9("C-1002","Lima",1090); db.insert(c9);
    // Cuenta c10("C-1001","Tacna",9200); db.insert(c10);
    // Cuenta c11("C-2001","Piura",5000); db.insert(c11);



    //db.printIndex();
    //db.printRelacionCuenta();


    //WITH UNORDERED_MAP:
        // db.hashearIndices();
        // db.printHashIndices();
        // db.SelectFromTTWhere("C-725");

    //WITH MYHASH
    db.hashearIndicesv2();
    std::cout << "\n\n";
    db.printHashArrayV2();
    //db.SelectFromTTWhereV2("C-239");



    //Bucket b1;
    // std::cout << b1.internalN.size() << std::endl;
    //std::cout << b1.next->internalN.size() << std::endl;
    //ULI a;
    //a = 23;
    //std::cout << a << std::endl;
    //std::cout << pow('a',2) << std::endl;
    //TEST PARA RETORNAR ULI DE EL STRING DADOS
    //std::cout << returnValueOfString("nomo") << std::endl;







    //Index i;
    //i.setIndex("moni");
    //i.setPos(10);
    //i.datosConstantes();
    //std::cout << i.getIndex() << std::endl;
    //std::cout << i.getPosition() << std::endl;
    //i.setIndex("elias");
    //i.setPos(45);
    //std::cout << i.getIndex() << std::endl;
    //std::cout << i.getPosition() << std::endl;

    //Index r;
    //std::cout << r.getIndex() << std::endl;
    //std::cout << r.getPosition() << std::endl;
    //std::cout << "eso es todo" << std::endl;
    //const char * cad = "alegria";
    //std::cout << cad << std::endl;

    //test CUENTA
    // Cuenta c1("c-123","Aqp",123);
    // c1.printCuenta();
    // std::cout << c1.getNumCuenta()<< std::endl;
    // std::cout << c1.getCiudad()<< std::endl;
    // std::cout << c1.getSaldo()<< std::endl;


    return 0;
}
