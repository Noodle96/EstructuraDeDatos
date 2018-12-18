/*
    FUNCIONES IMPLEMENTADAS DE LINKEDLIST.H
    void push_front(T);
    bool isUnique();
    bool findByOrder(T d , NodoLL<T> **&p);
    bool insertByOrder(T d);
*/

template<typename T>
std::list< std::pair<T,T> > map_int;


//AGREGA T D AL INICIO
template<typename T>
void LinkedList<T>::push_front(T d){
    NodoLL<T>  *pNuevo   =  new NodoLL<T>(d);
    if ( !m_pHeadLL ){
        //std::cout << "entro  a push:front " << std::endl;
         m_pHeadLL = pNuevo;return;
    }
    //std::cout << "despues de  push:front " << std::endl;
    pNuevo->m_pSgteLL = m_pHeadLL;
    m_pHeadLL = pNuevo;
}


//PASO POR REFERENCIA EL NODO
template<typename T>
void LinkedList<T>::push_frontNode(NodoLL<T> *&p){
    if( !m_pHeadLL ){
        m_pHeadLL = p;
        //std::cout << "PUSH_FRONTNODEnODE" << std::endl;
        return;

    }
    //std::cout << "DESPUES DE PUSH_FRONTNODEnODE" << std::endl;
    p->m_pSgteLL = m_pHeadLL;
    m_pHeadLL = p;
}



//FIND DOBLE PUNTERO-> CONOCIDO
template<typename T>
bool LinkedList<T>::findR(T d, NodoLL<T>**&p){
    ;
}
template<typename T>
void LinkedList<T>::makeDotPrint(){
    std::fstream file;
    file.open("dot.dot", std::ios::out);
    file << "digraph ll {\n\n";
        file << "\tnode [shape=Mrecord, fontsize=16];" << std::endl;
        file << "\trankdir=TB;" << std::endl;
        //file <<"\t" << 1 << " [label=\"{    {  {<data> " << 197 <<  " }  | <grado> g }    |  <ref> /////       }      | <actual> * \"];\n";
        for(auto it = map_int<T>.begin() ; it != map_int<T>.end() ; it++){
            auto et = (*it);
            file  << "\t" << "node" << (et).first->m_dato <<"_"<< (et).first->m_order
                << " [label=\"{ { { <data>" << (et).first->m_dato << " } | <grado> "
                << (et).first->m_order << " } | "
                << "<ref> ///  } | <actual>  * \" ]; \n";

            file  << "\t" << "node" << (et).second->m_dato <<"_"<< (et).second->m_order
                << " [label=\"{ { { <data>" << (et).second->m_dato << " } | <grado> "
                << (et).second->m_order << " } | "
                << "<ref> ///  } | <actual>  * \" ]; \n";

            file << "\t"<<  "node" << (et).first->m_dato <<"_"<< (et).first->m_order << " -> "
                << "node" << (et).second->m_dato <<"_"<< (et).second->m_order << ";\n\n";
            //std::cout << *(et).first << " " << *(et).second << std::endl;
        }
    file << "\n}\n";
    file.close();
    system("dot -Tpng dot.dot -o dot.png");
}




template<typename T>
void LinkedList<T>::printReference(){
    if(!m_pHeadLL)return;
    NodoLL<T> * temp = m_pHeadLL;
    while(temp != 0 ){
        std::cout << *temp->m_datoLL;// << std::endl;
        temp = temp->m_pSgteLL;
    }
    //std::cout << *temp->m_datoLL << std::endl;
}



template<typename T>
void LinkedList<T>::printInGraphviz(){
    // std::fstream file;
    // file.open("dot.dot", std::ios::out);
    if(!m_pHeadLL)return;
    NodoLL<T> *temp = m_pHeadLL;
    int e = 0;
    while(e != 1){
        temp = temp->m_pSgteLL;
        map_int<T>.clear();
        InNodo(temp);
        // temp = temp->m_pSgteLL;
        e++;
    }
    makeDotPrint();
}





template<typename T>
void LinkedList<T>::print_map_global(){
    // std::pair<int,int>::iterator et;
    for(auto it = map_int<T>.begin() ; it != map_int<T>.end() ; it++){
        auto et = (*it);
        std::cout << *(et).first << " " << *(et).second << std::endl;
    }
}




template<typename T>
void LinkedList<T>::InNodo(NodoLL<T>*&p){
    // std::fstream file;
    // file.open("dot.dot", std::ios::out);
    //
    // file << "digraph ll {\n\n";
    //     file << "\tnode [shape=Mrecord, fontsize=16];" << std::endl;
    //     //file <<"\t" << 1 << " [label=\"{    {  {<data> " << 197 <<  " }  | <grado> g }    |  <ref> /////       }      | <actual> * \"];\n";
    // file << "\n}\n";

    if(!p)return;
    std::cout << *p->m_datoLL;

    //std::cout << "test: " << p->m_datoLL->m_Children.isEmpty() << std::endl;
    NodoLL<T> *children = p->m_datoLL->m_Children.begin();
    if(children) {
        // std::cout <<  *p->m_datoLL << " CABEZA se conecta con " << *children->m_datoLL ;
        map_int<T>.push_back( std::make_pair(p->m_datoLL,  children->m_datoLL  )  );
    }
    //map_global.insert( std::make_pair(children->m_dato, push_back) );


    //map_int.insert( std::make_pair(4, 8)  );
    //std::cout << p->m_datoLL->m_Children;
    NodoLL<T> *temp = children;
    NodoLL<T> *tempN;
    while(temp){
        InNodo(temp);
        //std::cout << *temp->m_datoLL;
        tempN = temp->m_pSgteLL;
        if(tempN){
            // std::cout << *temp->m_datoLL << " se conecta con hermano " << *tempN->m_datoLL;
            map_int<T>.push_back( std::make_pair( temp->m_datoLL, tempN->m_datoLL) );
        }
        temp = temp->m_pSgteLL;
    }
    //std::cout << *children->m_datoLL;

    //file.close();
}






template<typename T>
void LinkedList<T>::print(){
    if(!m_pHeadLL)return;
    NodoLL<T> * temp = m_pHeadLL;
    while(temp != 0 ){
        std::cout << temp->m_datoLL << std::endl;
        temp = temp->m_pSgteLL;
    }
    //std::cout << temp->m_datoLL << std::endl;
}



//VERIFICA SI LA LISTA SOLO CONTIENE UN SOLO ELEMENTO
template<typename T>
bool LinkedList<T>::isUnique(){
    return m_pHeadLL->m_pSgteLL == 0;
}



template<typename T>
bool LinkedList<T>::findByOrder(T d , NodoLL<T> **&p){
    p = &(m_pHeadLL);
    /*
    while(*p){
        std::cout << (*p)->m_datoLL->m_dato << endl;
        p = &((*p)->m_pSgteLL);
    }
    */
    while(*p){
        if( d->m_order <= (*p)->m_datoLL->m_order )return true;
        p = &((*p)->m_pSgteLL);
    }
    return true;
    //siempre lo deja en la posiscion deseadad => return true, porque solo quiero posicion exacta donde se va areglar
}



template<typename T>
bool LinkedList<T>::insertByOrder(T d){
    NodoLL<T>* nuevo = new NodoLL<T>(d);
    NodoLL<T> **q;
    if ( findByOrder( d,q) ){
        NodoLL<T> *temp = *q;
        nuevo->m_pSgteLL = temp;
        *q = nuevo;
        return true;
    }
}






template<typename T>
//tesis: al momento de llamar a areglar , al menos no van a tener el mismo grado dos nodobh, pero si su dato
void LinkedList<T>::areglar(T d){
    if( (m_pHeadLL->m_datoLL->m_dato == d->m_dato) && (m_pHeadLL->m_datoLL->m_order == d->m_order) ){
        NodoLL<T> *temptemp = m_pHeadLL;
        m_pHeadLL = m_pHeadLL->m_pSgteLL;
        //temptemp->m_pSgteLL = 0;
        temptemp->m_pSgteLL = 0;
        delete temptemp;
        return;
     }
     NodoLL<T> * temp3 = m_pHeadLL;
     NodoLL<T> * temp4 = m_pHeadLL->m_pSgteLL;
     while(temp4 && (temp4->m_datoLL->m_dato != d->m_dato) && temp4->m_datoLL->m_order != d->m_order ){
         temp3 = temp4;
         temp4 = temp4->m_pSgteLL;
     }
     if(temp4){
        temp3->m_pSgteLL = temp4->m_pSgteLL;
        //temp4->m_pSgteLL = 0;
        delete temp4;
     }
     return;
}

template<typename T>
void LinkedList<T>::areglarWithNode(NodoLL<T> *&p){
    if(m_pHeadLL->m_datoLL->m_dato == p->m_datoLL->m_dato ){
        //NodoLL<T> *temptemp = m_pHeadLL;
        m_pHeadLL = m_pHeadLL->m_pSgteLL;
        //temptemp->m_pSgteLL = 0;
        p->m_pSgteLL = 0;
        return;
    }
    NodoLL<T> * temp3 = m_pHeadLL;
    NodoLL<T> * temp4 = m_pHeadLL->m_pSgteLL;
    while(temp4 && (temp4->m_datoLL->m_dato != p->m_datoLL->m_dato) ){
        temp3 = temp4;
        temp4 = temp4->m_pSgteLL;
    }
    if(temp4){
       temp3->m_pSgteLL = temp4->m_pSgteLL;
       temp4->m_pSgteLL = 0;
       p->m_pSgteLL = 0;
    }
    return;


}








//END LinkedList.H
