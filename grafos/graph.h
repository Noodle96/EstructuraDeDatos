#ifndef GRAPH_H
#define GRAPH_H
#include"arista_vertex.h"


/*
    GRAPH REPRESENTA UN GRAFO DIRIGIDO EN DONDE SE REPRESENTARA CON UNA LISYA DE VERTICES{valor,lista de aristas}, CADA ARISTA{valor,dir_memoria verices destino}
 */

//////////////////////////////////CLASS GRAPH///////////////////////////////////
template<typename V, typename E>
using  li = list< Vertex<V,E> >;


#include<vector>
using  Matriz = std::vector< vector<int> >;

#include<climits>
#include<algorithm>


template<typename V, typename E>
class Graph{
private:
    std::list< Vertex<V,E> > m_lista;
public:
    Graph(){}

    std::list< Vertex<V,E> > *getList(){return &m_lista;}

    void addVertex(V&);
    void addArista(V,V,E);
    int getSizeListG()const{return m_lista.size();}

    int getIndex(Vertex<V,E>*&);
    int getIndexV(V);



    //print Graph

    void printGraph_List();
    void printGraph_PNG();
    void printGraph_PNG_Dijkstra();

    bool pertenece(V &v,  Vertex<V,E>  );
    Matriz formarMatrizAdyacencia();
    void printMatrizAdyacencia(Matriz &);






    //PARA dijkstra
    /*la funcion GetMi devuelve el menor valor de cadsa vertice mediante un heap*/
    int GetMin(vector<V>&,vector<bool>&);


    /*la funcion  copy  copia la fila de 'v' de la Matriz 'M' al vector 'd'*/

    void copy(Matriz &M ,V &v, vector<E>& d);



    /*algoritmo de dijstra que devolvera la ruta mas corta de un grafo G*/
    vector<E> dijkstra(Matriz G, V Origen);




};

////////////////////////////////////////////////////////////////////////////////


#include"dikjstra.tpp"
#include"graph.tpp"

#endif // GRAPH_H
