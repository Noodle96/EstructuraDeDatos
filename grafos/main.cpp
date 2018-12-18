#include<iostream>
#include"graph.h"
using namespace std;

//template<typename V, typename E>
//int Vertex<V,E>::pos = 0;

int main(){


    Graph<int,int> g;
    std::string ene= "enero",
        feb = "febrero",
        mar = "marzo",
        ab = "abril",
        mayo = "mayo";

    int a = 89, b = 33, c = 56, d = 21;

    g.addVertex(a);
    g.addVertex(b);
    g.addVertex(c);

    Vertex<int , int> ht;
    cout << "INICAL" << &ht << endl << endl;
    std::cout << g.pertenece(a,ht) << '\n';
    cout << ht << endl;
    std::cout << g.pertenece(b,ht) << '\n';
    cout << ht << endl;
    std::cout << g.pertenece(d,ht) << '\n';
    cout << ht << endl;

    // g.addArista(ene,feb,10);
    // g.addArista(ene,mar,11);
    // g.addArista(feb,mar,12);
    // g.addArista(mar,ab,13);
    // g.addArista(mar,ene,14);
    // g.addArista(feb,ene,15);
    //
    //
    // g.printGraph_List();
    // std::list<int> enteros;
    // int a = 23;
    // cout << &a << endl;
    // enteros.push_back(a);
    // for(auto it = enteros.begin() ;  it != enteros.end(); it++){
    //     cout << &(*it) << endl;
    // }


    /*
        AGREGANDO VERTICES A NUESTRO GRAFO DIRIGIDO G
     */

    //int a  = 7, b = 11, c = 14;
    //int *pa = &a, *pb=&b, *pc = &c;
    //std::cout << "antes de crearla: "  << &a<< endl;
    //g->addVertex("monos");

    //g->addVertex(b);
    //g->addVertex(c);

    //std::cout << g->pertenece(a) << std::endl;



    /*
        UNA VEZ EXISTENTE DICHO VERTICES LO PODEMOS PONDERAR PONIENDOLE VALORES
        LLAMADAS ARISTAS, SI NO EXISTE DICHO VERTICE HABRA UNA EXEPCION
     */

    //g->addArista(a,b,1);
    //g->addArista(b,a,0);
    //g->addArista(b,c,1);
    //g->addArista(a,c,0);




    //g->printGraph_List();

//    Matriz m = g->formarMatrizAdyacencia();
  //  g->printMatrizAdyacencia(m);
    // g->addArista(4,2,30);
    // g->addArista(2,4,20);
    // g->addArista(4,3,1);
    // g->addArista(4,5,50);
    // g->addArista(3,5,20);
    // g->addArista(5,3,40);







    /*
        IMPRIME POR CONSOLA LOS VERTICES CON SUS RESPECTIVAS ARISTAS
     */



    // cout << "\n\tLista de vertices con con sus respectivos orignees" << endl;
    // g->printGraph_List();



    /*IMPRIME EL GRAFO CON ARISTAS RESPECTIVAS  EN GRAFO.PNG*/

    // g->printGraph_PNG();


    /*CREANDO  LA MATRIZ DE ADYACENCIA DE DICHO GRAFO*/
    // Matriz m = g->formarMatrizAdyacencia();

    /*IMPRIMIENDO LA LISTA DE ADYACENCIA*/
    // cout << "\n\n\t\tMatriz de adyacencina del grafo G" << endl;
    // g->printMatrizAdyacencia(m);



    //FORMANDO EL VECTOR CON LAS DISTANCIAS MINIMAS A CADA VERTICE.
    // vector<int> dis = g->dijkstra(m,1);

    // cout << "\t\nVector con el camino mas corto de un vertice inicial[0]" << endl << endl;
    // for(int e = 0 ; e < dis.size(); e++){
    // cout << dis[e] << " ";
    // }
    // cout << endl;

    // IMPRIMIENDO EL GRAFO APLICANDOLE dijkstra, un la ubicacion por defecto dijkstra.png
    // en esta imagen dirige del origen al origen destino directamente(sin ruta, aun por implementar)

    // g->printGraph_PNG_Dijkstra();






//    delete g;




    return 0;
}
