
#ifndef ARISTA_VERTEX_H
#define ARISTA_VERTEX_H
#include<iostream>
#include<fstream>
#include<list>
#include<algorithm>
using namespace std;


template<typename V, typename E>
class Arista;


/*
    CADA VERTICE TENDRA SU DATO Y UNA LISTA DE Aristas(arcos)
 */

/////////////////////////////////CLASS VERTEX///////////////////////////////////

template<typename V, typename E>
class Vertex{
private:
    V m_datov;
    std::list< Arista<V,E> > m_aristas;
public:
    Vertex(){}
    Vertex(V dato):m_datov(dato){}

    /*
        Sobrecargando  operadores
     */

    bool operator == (const Vertex<V,E> &v){
        return m_datov == v.m_datov;
    }
    bool operator != (const Vertex<V,E> &v){
        return m_datov != v.m_datov;
    }


    friend std::ostream & operator << (ostream &o,const Vertex<V,E> &v){
        //o << v.m_datov << "  and " << &v.m_aristas << endl;
        //o << &(v.m_datov)  << " | " << v.m_datov;
        o << &v;
        return o;
    }

    //sets and gets
    void setDatoV(V ver){m_datov=ver;}
    V  getDatoV()const{return m_datov;}
    std::list< Arista<V,E> > &get_m_aristas(){return m_aristas;}

};

////////////////////////////////////////////////////////////////////////////////




/*
    CADA ARISTA TENDRA UN Valor y LA DIRECCION DE MEMORIA DEL VERTICE DESTINO
 */
////////////////////////////////////CLASS ARISTA///////////////////////////////

template<typename V, typename E>
class Arista{
private:
    E m_datoe;
    Vertex<V,E> *m_pDestino;
public:
    Arista(E dato_arista, Vertex<V,E> *p=0):m_datoe(dato_arista),m_pDestino(p){}

    //sets and gets
    E getDataE()const{return m_datoe;}
    // Vertex<V,E> *getDestino(){return m_pDestino;}
    Vertex<V,E> *getDestino(){return m_pDestino;}
    V getDataDestino(){return m_pDestino->getDatoV();}


    //bool operator ==(const Arista<V,E> &a){
    //    return m_pDestino = a.m_pDestino;
    //}
};


///////////////////////////////////////////////////////////////////////////////

#endif //ARISTA_VERTEX_H


































//
