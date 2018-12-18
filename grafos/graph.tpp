
////////////////////////////////////ADD_VERTEX//////////////////////////////////


/*
    Al insertar una vertice estaremos agregando el valor del VERTICE
    y por defecto y obvio sin arcos de adyacencia
 */
template<typename V , typename E>
void Graph<V,E>::addVertex(V &v0){
    Vertex<V,E> vertexT(v0);
    //cout << vertexT << endl;
    m_lista.push_back( vertexT);
}

////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////PERTENECE////////////////////////////////////

/*
    Esta funcion indica la  pertenencia es decir
    para verificar que un objeto esta dentro de una lista de objetos, en nuestro caso el objeto sera Vertex y la lista de objetos sera la lista de vertex(miembro grafo)

 */
template<typename V, typename E>
bool Graph<V,E>::pertenece(V &v, Vertex<V,E> iter){
    //cout << "conetenido de v del iterator: " << *v << endl;
    // std::list< Vertex<V,E> >::iterator it;
    auto itera = find(m_lista.begin(), m_lista.end(),v);
    // cout << "it " << it << std::endl;
    //cout << "(*it) " << *it << std::endl;

    if( itera != m_lista.end()){
        iter = (*itera);
        cout << iter << " !! " ;
        return true;//encontro
    }else{
        iter = 0;
        cout << iter << " !! " ;
        return false; //no encontro
    }
}

////////////////////////////////////////////////////////////////////////////////




////////////////////////////////////ADD_ARISTA//////////////////////////////////
// _List_iterator< Vertex<V,E> > g; es el tipo que retornaria


template<typename V, typename E>
void Graph<V,E>::addArista(V v0, V v1, E e){
    bool p_ = false, q_ = false;

    // auto m_ar = get_m_aristas();
    //auto p = find(m_lista.begin(), m_lista.end(), v0);
    //cout << "Dentro de add arista p: "<< *p << endl;
    Vertex<V,E> et0;
    //cout << "1- "<<&(et0) << " ";
    if(pertenece(v0,et0)) p_ = true;
    //cout << "2- " << &(et0) << " ";

    //auto q = find(m_lista.begin(), m_lista.end(), v1);
    //cout << "Dentro de add arista q: " << *q << endl;
    Vertex<V,E> et1;
    //cout << "1- "<< &(et1) << endl;
    if(pertenece(v1,et1)) q_ = true;
    //cout << "2- " << &(et1) << endl;

    /*solo verificaremos que el vertice inicial como el final existan para que se pueda agregar la arista*/
    //cout << p_ << q_ << endl;
    try{
        if(p_ && q_){
            // (*p).m_aristas.push_back( Arista<V,E>(e,&(*q)));
            et0.get_m_aristas().push_back( Arista<V,E>(e, &et1 ));

            // cout << "exito" << endl;
        }
        else
            throw  "EXCEPCION: no existe alguna arista entrante";
    } catch(const char *msg){
        cerr << msg << endl;
        exit(1);
    }

}

////////////////////////////////////////////////////////////////////////////////




/////////////////////////////PRINTGRAPH_LIST////////////////////////////////////

/*
    Imprimira por consola solo el valor de los vertices
 */

template<typename V, typename E>
void Graph<V,E>::printGraph_List(){
    auto it = m_lista.begin();
    for( ; it != m_lista.end();  it++){
        // std::cout << ((*it).getDatoV()) << ": ";
        std::cout << &(*it) << " |--> ";

        for(auto et = (*it).get_m_aristas().begin(); et != (*it).get_m_aristas().end() ; et++){
            //cout << ((*et).getDataDestino()) << " ";
            //cout << (*et).getDataDestino() << " | " <<  (*et).getDataE() <<" | "<< (*et).getDestino() << "  ";
            cout << "dentro2" << endl;
            cout << &(*et) << "  ,  " ;
        }
        cout << std::endl;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////




//////////////////////////////////PRINTGRAPH_PNG////////////////////////////////

/*
    Imprimia el grafo dentro de la carpeta actual llamada grafo.png
 */
/*       Example
                digraph A {
                1 -> 2 [label= 10, style=dashed];
                1 -> 3 [label=9];
                2 -> 4 [label=6];
                2 -> 3 [label=20,style=dashed];
                3 -> 5 [label=40];
                3 -> 4 [label=30, style=dashed];
                4 -> 5 [label=1000];
                1 [style=bold];
                4 [style=bold];
                --<>--
                --<system("dot -Tpdf binomial.dot -o binomial.pdf")>--
                --< dot name.dot -o grafo1.png -Tpng -Grankdir=LR
>--
}
*/
template<typename V,typename E>
void Graph<V,E>::printGraph_PNG(){
    ofstream file("grafo.dot");
    file << "digraph A {" << std::endl;

    for(auto it = m_lista.begin() ; it != m_lista.end();  it++){
        // Un Vertice:
        //      (*it).getDatoV(); // datoVertice
        //      (*it).get_m_aristas() // dato lista de aristas



        /*

            Example:
                1: 2 4 3
                2: 4
                3: 2 4
                4: 2

            1->2[dato arista]
            1->4 " "
            1->3 " "
            2->4 " "
            3->2 " "
            3->4 " "
            4->2 " "
         */

        for(auto et = (*it).get_m_aristas().begin(); et != (*it).get_m_aristas().end() ; et++){
            file << (*it).getDatoV() << "->" << (*et).getDataDestino() << "[label = " << (*et).getDataE() << "]" << endl;
        }
    }
    file << "}";
    file.close();
    //interpretando lenguaje dot
    system("dot grafo.dot -o grafo.png -Tpng -Grankdir=LR");
}
////////////////////////////////////////////////////////////////////////////////




//////////FOMANDO UNA MATRIZ DE ADYACENCIA APARTOR DE EL GRAFO//////////////////


template<typename V,typename E>
int Graph<V,E>::getIndex(Vertex<V,E> *&v){
    auto cont = 0;
    for(auto it = m_lista.begin() ; it != m_lista.end() ; it++){
        if(*v == (*it)) return cont;
        else cont++;
    }
    return cont;
}

template<typename V,typename E>
int Graph<V,E>::getIndexV(V v){
    auto cont =  0;
    for(auto it = m_lista.begin() ;  it != m_lista.end() ; it++){
        if( ((*it).getDatoV()) != (v))
            cont++;
        else return cont;
    }
    return cont;

}


///////////////////////////////////////////////////////////////////////////////




//////////////////////FORMANDO LA MATRIZ DE ADYACENCIA//////////////////////////
/*
    Esta matriz nos servira para por ejemplo hacer funcionar dijkstra
 */
template<typename V, typename E>
Matriz Graph<V,E>::formarMatrizAdyacencia(){
    int len = getSizeListG();
    Matriz m_adyac;
    /* formando la matriz */
    /*dandole el tamaño nxn a la matriz y todos con el INT_MAX*/
    m_adyac.resize(len);
    for(int e = 0 ; e < len ; e++){
        m_adyac[e].resize(len,100); // INT_MAX
    }



    Vertex<V,E> *temp;
    int j;
    auto e = 0;
    for(auto it = m_lista.begin() ; it != m_lista.end(); it++,e++){

        for(auto et = (*it).get_m_aristas().begin(); et != (*it).get_m_aristas().end(); et++){
            //(*et).getDataE();
            temp = (*et).getDestino();
            j = getIndex(temp);

            //(*et).getDataE();
            m_adyac[e][j] = (*et).getDataE();
        }

    }
    return m_adyac;
}

///////////////////////////////////////////////////////////////////////////////




//////////////////////////IMPRIME MATRIZ DE ADYACENCIA//////////////////////////

/*
    IMPRIME UNA MATRIZ DE ADYACENCIA(matriz cuadrada)
 */
template<typename V, typename E>
void Graph<V,E>::printMatrizAdyacencia(Matriz &m){
    auto len = m.size();
    // cout << "size: " << len << endl;
    // cout << "size: " << m[0].size() << endl;
    for(auto e =  0 ; e < len ; e++){
        for(auto j = 0 ; j < len; j++){
                cout <<  m[e][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

///////////////////////////////////////////////////////////////////////////////









///IMPRIMIENDO EL GRAFO G APLICANDOLE DIJKSTRA EN LA UBICACION dijkstra.png/////
template<typename V,typename E>
void Graph<V,E>::printGraph_PNG_Dijkstra(){

    Matriz m_ady = formarMatrizAdyacencia();
    //por defecto le daremos que inicie en el primer vertice con valor 1
    vector<E> vec_dis = dijkstra(m_ady,1);
    ofstream file("dijkstra.dot");
    file << "digraph A {" << std::endl;
    auto it =  m_lista.begin();
    auto et = it;it++;
    for( auto e = 1; it != m_lista.end();  it++, e++){

            file << (*et).getDatoV() << "->" << (*it).getDatoV() << "[label = " << vec_dis[e] << "]" << endl;

    }
    file << "}";
    file.close();
    //interpretando lenguaje dot
    system("dot dijkstra.dot -o dijkstra.png -Tpng -Grankdir=LR");

}




////////////////////////////////////////////////////////////////////////////////

//
