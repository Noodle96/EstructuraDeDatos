#include<iostream>
using namespace std;

#include "linked_list.h"
#include "Persona/persona.h"


int main(){
    /*
        Verifica si esya vacia una lista
    */
    // LinkedList<int> *l1 = new LinkedList<int>();
    // l1->Add(3,l1->getHead());
    // std::cout << l1->isEmpty() << '\n';
    // l1->printR(l1->getHead());
    // delete l1;





    /*
        union de dos listas ENLAZADAS
    */
    // LinkedList<int> *l2 = new LinkedList<int>(),
    //                 *l3 = new LinkedList<int>(),
    //                 *l4 = new LinkedList<int>();
    //
    // l3->Add(1,l3->getHead());
    // l3->Add(2,l3->getHead());
    // l3->Add(3,l3->getHead());
    // l3->Add(4,l3->getHead());
    //
    // l4->Add(10,l4->getHead());
    // l4->Add(20,l4->getHead());
    // l4->Add(30,l4->getHead());
    // l4->Add(40,l4->getHead());
    //
    // // l3->print();
    // // l4->print();
    //
    // l2 = l3->Union(l4);
    // l2->print();
    //
    //
    // delete l2;
    // delete l3;
    // delete l4;




    // LinkedList<int>  A;
    // A.push_front(5);
    // A.push_front(65);
    // A.push_front(75);
    // A.Add(100, A.getHead());
    // A.print();




    // Nodo<int> *p = new Nodo<int>(4);
    // std::cout << p->m_Dato << std::endl;
    // std::cout << p->m_pSig << std::endl;
    // std::cout << "hola" << std::endl;






    // LinkedList<int> *l5 = new LinkedList<int>();
    // l5->Add(3, l5->getHead());
    // l5->Add(4, l5->getHead());
    // l5->Add(5, l5->getHead());
    // l5->Add(16, l5->getHead());
    // l5->print();
    //
    // std::cout << l5->find_iterativo(5) << std::endl;
    // std::cout << l5->find_iterativo(15) << std::endl;
    //
    // std::cout << l5->find_recursivo(4, l5->getHeadP()) << std::endl;
    // std::cout << l5->find_recursivo(14, l5->getHeadP()) << std::endl;
    // delete l5;






    /*
        AGREGAR ORDENADAMENTE
    */
    // LinkedList<int> *l6 = new LinkedList<int>();
    // l6->addOrdenadamente(9);
    // l6->addOrdenadamente(1);
    // l6->addOrdenadamente(8);
    // l6->addOrdenadamente(2);
    // l6->addOrdenadamente(7);
    // l6->addOrdenadamente(3);
    // l6->addOrdenadamente(6);
    // l6->addOrdenadamente(5);
    // l6->addOrdenadamente(5);
    // l6->addOrdenadamente(10);
    // l6->addOrdenadamente(4);
    // l6->print();
    //
    // l6->invertir();
    // l6->print();
    // l6->imprimirRecursivoAlReves(l6->getHead()); std::cout << '\n';
    //
    // delete l6;






    /*
        DE UN ARCHIVO DE NOMBRES  LO INSERTA A UNA LISTA ENLAZADA Y LOS IMPRIME AL REVES
    */
    // LinkedList<std::string> *l7 = new LinkedList<std::string>();
    // l7->insertaOfFile();
    // l7->print();
    // l7->imprimirRecursivoAlReves(l7->getHead()); std::cout << '\n';
    // delete l7;






    /*
        UNION E INTERSECCION DE DOS LISTAS
    */
    // LinkedList<int> *l10union = new LinkedList<int>();
    // LinkedList<int> *l11interseccion = new LinkedList<int>();
    // LinkedList<int> *l8 = new LinkedList<int>();
    // LinkedList<int> *l9 = new LinkedList<int>();
    // l8->Add(1,l8->getHead());
    // l8->Add(2,l8->getHead());
    // l8->Add(3,l8->getHead());
    // l8->Add(4,l8->getHead());
    // l8->Add(5,l8->getHead());
    // l8->Add(6,l8->getHead());
    // std::cout << "l1 =>   " ;l8->print();
    //
    // l9->Add(2,l9->getHead());
    // l9->Add(4,l9->getHead());
    // l9->Add(6,l9->getHead());
    // l9->Add(7,l9->getHead());
    // std::cout << "l2 =>   " ;l9->print();
    //
    // l11interseccion = l8->InterseccionL(l9);
    // std::cout << "Interseccion =>   ";l11interseccion->print();
    //
    // l10union = l8->UnionL(l9);
    // std::cout << "Union =>   ";l10union->print();
    //
    // delete l9;
    // delete l8;
    //
    // delete l10union;
    // delete l11interseccion;






    // LinkedList<int> *l12 = new LinkedList<int>();
    // l12->Add(1, l12->getHead());
    // l12->Add(10, l12->getHead());
    // l12->Add(100, l12->getHead());
    // Nodo<int> **p = &(l12->getHead());
    // std::cout<< l12->findR(10,p) << "\n";
    // l12->AddR(300);
    // l12->AddR(200);
    // l12->AddR(300);
    // l12->AddR(2);
    // l12->AddR(200);
    // l12->printR(l12->getHead());
    // delete l12;








    // Persona *p1 = new Persona();
    // p1->setNumeroDocumento(1a);
    // p1->setNombre("Jorge");
    // p1->setApellido("Leon");
    // p1->setFechaNacimiento("30/06/12");
    // std::cout << *p1;
    // delete p1;

    LinkedList<Persona*> *l13 = new LinkedList<Persona*>();
        Persona *p1 = new Persona(1000,"Elias","Bravo","1-12-98");
        Persona *p2 = new Persona(500,"Jorge","Del Carpio","1-03-00");
        Persona *p3 = new Persona(200,"aa","Manzanitos","1-02-00");
        Persona *p4 = new Persona(100,"ab","Quispe","1-05-00");
        Persona *p5 = new Persona(100,"Jorge","Montana","1-03-99");
        Persona *p6 = new Persona(500,"Matheo","Montanes","1-03-01");


        l13->AddR(p1);
        l13->AddR(p2);
        l13->AddR(p3);
        l13->AddR(p4);
        l13->AddR(p5);
        l13->AddR(p6);
        l13->printR(l13->getHeadP());
        // std::cout << (p1 == p2) << '\n';
        // std::cout << p1 << p2 << std::endl;
        cout << "p4 == p5 " << ( (p4==p5) ? "Si": "No" ) << std::endl;

        delete p1;
        delete p2;
        delete p3;
        delete p4;
        delete p5;
        delete p6;
        delete l13;






        // Nodo<float> *n1 = new Nodo<float>(1);
        // Nodo<float> *n2 = new Nodo<float>(2);
        // cout << "n1 == n2 " << ( (n1>n2) ? "Si": "No" ) << std::endl;

        // Persona p11,p12;
        // p11.setNumeroDocumento(1);
        // p12.setNumeroDocumento(1);
        // cout << "p1 == p2 " << ( (p11==p12) ? "Si": "No" ) << std::endl;
        // delete n1,n2;


    return 0;


}
