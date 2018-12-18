#include<iostream>

using namespace std;


#include "bst.h"


int main(){

    Bst<int> *ent = new Bst<int>();
    // ent->AddR(50,ent->getHeadA());
    // ent->AddR(40,ent->getHeadA());
    // ent->AddR(60,ent->getHeadA());
    ent->AddI(10);
    ent->AddI(7);
    ent->AddI(15);
    ent->AddI(3);
    ent->AddI(8);
    ent->AddI(12);
    ent->AddI(20);
    ent->AddI(4);
    ent->AddI(11);
    ent->AddI(5);
    ent->AddI(21);
    ent->AddI(22);
    ent->AddI(23);

    ent->printPorNiveles();
    // ent->printPorNivelesPares();
    ent->printPorNivelesAbajoArribaDI();

    //std::cout  << ent->eliminarHoja(23) << std::endl;








    //
    // std::cout << "infijo: " << '\n';
    // ent->printInfijo(ent->getHead());std::cout  << '\n';
    // std::cout << "altura" << ent->altura(ent->getHead()) << '\n';



    // RETORNA EL PADRE DE UN NODO
    // int opc; cout << "hijo: "; cin >> opc;
    // NodoBST<int> *temp = ent->getParent(opc);
    // if(temp)std::cout << temp->m_Dato << '\n';
    // else{std::cout << "vacia o es la raiz o data no encontrado" << '\n';}




    //RETORNA EL HERMANO DE UN NODO
    // int opch; cout << "hermano del? "; cin >> opch;
    // NodoBST<int> *temph = ent->getBrother(opch);
    // if(temph)std::cout << temph->m_Dato << '\n';
    // else{std::cout << "Null" << '\n';}




    //RETORNA EL TIO DE UN NODO
    // int opct; std::cout << "tio de ?  "; cin >> opct;
    // NodoBST<int>*tempt = ent->getUncle(opct);
    // if(tempt) std::cout << tempt->m_Dato << '\n';
    // else{std::cout << "Null" << '\n';}




    //RETORNA EL ABUELO DE UN  NODO
    // int opca; std::cout << "abuelo de ?  "; cin >> opca;
    // NodoBST<int> *tempa = ent->getGrandFather(opca);
    // if(tempa)std::cout << tempa->m_Dato << '\n';
    // else{std::cout << "Null" << '\n';}




    //NIVEL DE UN NODO
    // int dato_nodo; std::cout << "data_nodo: ";  cin >> dato_nodo;
    // std::cout << ent->nivelNodo(dato_nodo) << '\n';


    // std::cout << ent->findR(30,ent->getHead()) << '\n';
    // std::cout << ent->findR(50,ent->getHead()) << '\n';







    //IMPRIMIENDO POR NIVELES UN ARBOL




    delete ent;

    return 0;
}
