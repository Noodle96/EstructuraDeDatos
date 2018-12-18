#include<iostream>
#include<cstring>
using namespace std;

#include "Persona/persona.h"
#include "linked_list.h"



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






        // Nodo<float> *n1 = new Nodo<float>(1);
        // Nodo<float> *n2 = new Nodo<float>(2);
        // cout << "n1 == n2 " << ( (n1>n2) ? "Si": "No" ) << std::endl;

        // Persona p11,p12;
        // p11.setNumeroDocumento(1);
        // p12.setNumeroDocumento(1);
        // cout << "p1 == p2 " << ( (p11==p12) ? "Si": "No" ) << std::endl;
        // delete n1,n2;

        // LinkedList<int*> *ent = new LinkedList<int*>();
        // int *a = new int(4);
        // ent->AddR(a);
        // ent->printR(ent->getHead());
        // delete ent;




        // LinkedList<Persona> l14; //= new LinkedList<Persona*>();
        // for(int e = 0 ;e < 5 ; e++)
        //     l14.write();
        // l14.load();

        // delete l14;
        // Persona p;
        // std::cout << sizeof(p) << '\n';
        // p.pedir();
        // p.showData();
        // std::cout << sizeof(p) << '\n';


        // Persona p13(12,"Manuel","Ibañez","13-14-12");
        // // p3.showData();
        // // p3.pedir();
        // p13.setApellido("luka");
        // p13.showData();


        // LinkedList<Persona> *l13 = new LinkedList<Persona>();
            // Persona p1(1000,"Elias","Bravo","1-12-98");
            // Persona p2(500,"Jorge","Del Carpio","1-03-00");
            // Persona p3(200,"aa","Manzanitos","1-02-00");
            // Persona p4(100,"ab","Quispe","1-05-00");
            // Persona p5(100,"Jorge","Montana","1-03-99");
            // Persona p6(500,"Matheo","Montanes","1-03-01");
            // Persona p7(3,"Ernesto","Cuadros","12-12-12");
            // Persona p8(45,"Evelyn","Diaz","13-13-00");
            // Persona pnuevo(5000,"Evelyn2","Diaz2","13-13-002");


            // l13->AddR(p1);
            // l13->AddR(p2);
            // l13->AddR(p3);
            // l13->AddR(p4);
            // l13->AddR(p5);
            // l13->AddR(p6);
            // // l13->printR(l13->getHeadP());
            // l13->deleteR(200);
            // // l13->printR(l13->getHeadP());
            // // std::cout << (p1 == p2) << '\n';
            // // std::cout << p1 << p2 << std::endl;
            // cout << "p4 == p5 " << ( (p6==p2) ? "Si": "No" ) << std::endl;
            // Persona *p1 = new Persona(1000,"Elias","Bravo","1-12-98");
            // Persona *p2 = new Persona(1000,"Jorge","Del Carpio","1-03-00");
            //
            // cout << "p1 == p2 " << ( (p1==p2) ? "Si": "No" ) << std::endl;
            //
            // delete l13;
            // LinkedList<int> lint;
            // lint.AddR(3);
            // lint.AddR(1);
            // lint.AddR(7);
            // lint.AddR(5);
            // lint.printR(lint.getHead());
            // lint.modificarR(5,12);
            // lint.printR(lint.getHead());



/*
        START THE PROGRAM PLANTILLA DE PERSONAS
*/
    // LinkedList<Persona> *l14 = new LinkedList<Persona>();
    // // l14->start();
    // std::cout << l14->AddRegistro(p1) << '\n';
    // std::cout << l14->AddRegistro(p2) << '\n';
    // std::cout << l14->AddRegistro(p3) << '\n';
    // std::cout << l14->AddRegistro(p4) << '\n';
    // std::cout << l14->AddRegistro(p5) << '\n';
    // std::cout << l14->AddRegistro(p6) << '\n';
    // std::cout << l14->AddRegistro(p7) << '\n';
    // // std::cout << l14->deleteRegistro(p6) << '\n';
    // std::cout << l14->AddRegistro(p8) << '\n';
    // std::cout << l14->modificarR(p2,pnuevo) << '\n';
    //
    // l14->printR(l14->getHead());
    //
    // // functionSupport::Menu();
    // delete l14;






    // LinkedList<Persona> *lPersonal = new LinkedList<Persona>();
    // lPersonal->start(); //al inicio carga la informacion de file .dat a la estructura
    // int iop;
    // char btnAlternativo = 'N';
    // int iden_num;
    //
    //
    // do {
    //     functionSupport::clear();
    //     functionSupport::Menu();
    //     int cont = 0;
    //     bool ver = true;
    //     Persona p;
	// 	do{
	// 		cin.clear();
	// 		if(cont > 0) cin.ignore(1024, '\n');
	// 		// cout << cont << endl;
	// 		cin >> iop;
	// 		cont++;
	// 		if( !cin.fail() ){
	// 			ver = false;
	// 		}
    //     }while( ver );
    //
    //
    //     switch (iop) {
    //         case 1:
    //             do{
    //             //agregar Persona
    //             functionSupport::clear();
    //             p.pedir();
    //             if( lPersonal->AddRegistro(p) ){
    //                 std::cout << "\n\n\t\t\t\t\tSe Agrego Correctamente !!!" << '\n';
    //             }else{
    //                 std::cout << "\n\n\t\t\t\t\tNo se Agrego, Existe el identificador dado." << '\n';
    //             }
    //             std::cout << "\n\t\t\t\t\tDesea Agregar Otra Vez(S/N) " ; cin >> btnAlternativo;
    //
    //             }while(toupper(btnAlternativo) == 'S');
    //             break;
    //         case 2:
    //             //Eliminar persona
    //             functionSupport::clear();
    //             std::cout << "\n\n\t\t\t ELIMINAR PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //             p.reset();
    //             std::cout << "\n\n\t\t\tidentificador :  "; cin >> iden_num;p.setNumeroDocumento(iden_num);
    //             if( lPersonal->deleteRegistro(p) ){
    //                 std::cout << "\n\n\t\t\t\t\tSe Elimino Correctamente !!!" << '\n';
    //             }else{
    //                 std::cout << "\n\n\t\t\t\t\tNo Existe con el identificador dado." << '\n';
    //             }
    //             std::cout << "\n\t\t\t\t\tContinuar(S) " ; cin >> btnAlternativo;
    //             break;
    //         case 3:
    //             //buscar Persona
    //             functionSupport::clear();
    //             btnAlternativo = 'N';
    //             std::cout << "\n\n\t\t\t ENCONTRAR PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //             p.reset();
    //             std::cout << "\n\n\t\t\tidentificador :  "; cin >> iden_num;p.setNumeroDocumento(iden_num);
    //             Nodo<Persona> *r;
    //             r = lPersonal->findRegistro(p);
    //             // std::cout << (*r)->m_Dato << '\n';
    //             if(r){
    //                     std::cout << r->m_Dato << '\n';
    //
    //                     do{
    //                         std::cout << "\n\t\t\t\tMoveBegin(B)    MovePrevious(P)    MoveNext(N)    MoveLast(L)    Regresar(S)" << std::endl;
    //                         std::cout << "\n\n\t\t\t\t\t\t\tOpcion ";
    //                         cin >> btnAlternativo;
    //
    //                         switch (btnAlternativo) {
    //                             case 'B': case 'b':
    //                                 //moveBegin
    //                                 functionSupport::clear();
    //                                 std::cout << "\n\n\t\t\t DATOS DEL  PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //                                 r = lPersonal->moveBegin(r);
    //                                 std::cout << r->m_Dato << '\n';
    //                                 break;
    //                             case 'P':case 'p':
    //                                 //movePrevious
    //                                 functionSupport::clear();
    //                                 std::cout << "\n\n\t\t\t DATOS DEL  PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //                                 r = lPersonal->movePrevious(r);
    //                                 std::cout << r->m_Dato << '\n';
    //                                 break;
    //                             case 'N': case 'n':
    //                                 //moveNext
    //                                 functionSupport::clear();
    //                                 std::cout << "\n\n\t\t\t DATOS DEL  PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //                                 r = lPersonal->moveNext(r);
    //                                 std::cout << r->m_Dato << '\n';
    //                                 break;
    //                             case 'L':case'l':
    //                                 //moveLast
    //                                 functionSupport::clear();
    //                                 std::cout << "\n\n\t\t\t DATOS DEL  PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //                                 r = lPersonal->moveLast(r);
    //                                 std::cout << r->m_Dato << '\n';
    //                                 break;
    //                         }
    //
    //                     }while(toupper(btnAlternativo) != 'S');
    //
    //             }
    //             else{
    //                 std::cout << "\n\n\t\t\t\t\tNo Existe con el identificador dado." << '\n';
    //                 std::cout << "\n\t\t\t\t\tContinuar(S) " ; cin >> btnAlternativo;
    //             }
    //             break;
    //         case 4:
    //             //modificar Personal
    //             functionSupport::clear();
    //             std::cout << "\n\n\t\t\t MODIFICAR PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //             std::cout << "\n\n\t\t\t\t\tEstamos Trabajando en esto !!!" << '\n';
    //             std::cout << "\n\t\t\t\t\tContinuar(S) " ; cin >> btnAlternativo;
    //             break;
    //         case 5:
    //             //mostrar Personal
    //             functionSupport::clear();
    //             std::cout << "\n\n\t\t\t LISTA DEL PERSONAL DE LA EMPRESA SAC ... " << '\n';
    //             lPersonal->printR(lPersonal->getHead());
    //             std::cout << "\n\t\t\t\t\tContinuar(S) " ; cin >> btnAlternativo;
    //             break;
    //
    //     }//end switch
    //
    // } while(iop != 0);
    // functionSupport::clear();
    //
    // delete lPersonal;







    // LinkedList<int> lenteros;
    // lenteros.AddR(4);
    // lenteros.AddR(1);
    // lenteros.AddR(7);
    // lenteros.AddR(3);
    // // lenteros.printR(lenteros.getHead());
    // Nodo<int> *enco = lenteros.findRegistro(2);
    // Nodo<int> *a = lenteros.moveNext(enco);
    // std::cout << a->m_Dato << '\n';
    // a = lenteros.movePrevious(a);
    // cout << a->m_Dato << endl;
    // // lenteros.printR(lenteros.getHead());


    /*
        .DOT

        node [shape=record];
        rankdir=LR;
        edge [tailclip=false];
    */


    // fstream fileDot;
    // fileDot.open("dot.dot");
    //     fileDot << "digraph ll {" << std::endl;
    //         fileDot << "\tnode [shape=record];" << std::endl;
    //         fileDot << "\trankdir=LR;" << std::endl;
    //         fileDot << "\tedge [tailclip=false];" << std::endl;
    //     fileDot << "}" << std::endl;
    //
    // fileDot.close();


    LinkedList<int> *l15 = new LinkedList<int>();
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(15);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(30);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(50);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(10);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(1);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(44);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(104);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(204);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(3);
    l15->printGraphviz(l15->getCantNodos());
    l15->AddR(1000);
    l15->printGraphviz(l15->getCantNodos());




    // l15->printR(l15->getHead());
    l15->printGraphviz(l15->getCantNodos()); //l15->getCantNodos()
    delete l15;






    return 0;
}
