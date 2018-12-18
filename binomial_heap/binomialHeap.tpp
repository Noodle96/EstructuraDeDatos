/*
    ->Desarrollo de las funciones del BinomialHeap

    void normalizarBinomialHeap();
    bool insert(T);
    void merge( NodoLL< NodoBH<T>* >  *&temp, NodoLL< NodoBH<T>* >  *&tempN, NodoLL< NodoBH<T>* >  *&ptrCmp ){
    bool isUniqueBH();
    void printList();
    T getMin();

*/

template<typename T>
bool BinomialHeap<T>::isUniqueBH(){
    return m_listaBH.isUnique();
}

template<typename T>
void BinomialHeap<T>::merge( NodoLL< NodoBH<T>* >  *&temp, NodoLL< NodoBH<T>* >  *&tempN, NodoLL< NodoBH<T>* >  *&ptrCmp ){
    if( temp->m_datoLL->m_dato <= tempN->m_datoLL->m_dato ){ // temp es menor o  igual a tempN
        temp->m_datoLL->m_Children.push_front(tempN->m_datoLL);
        //temp->m_datoLL->m_Children.push_frontNode(tempN);
        temp->m_datoLL->m_order++;
        ptrCmp = temp;
        //m_listaBH.areglarWithNode(tempN);
        m_listaBH.areglar(tempN->m_datoLL);
        //tempN->m_pSgteLL = 0;

    }else{
        //significa que  temp->m_dato > tempN->m_dato
        tempN->m_datoLL->m_Children.push_front(temp->m_datoLL);
        //tempN->m_datoLL->m_Children.push_frontNode(temp);
        tempN->m_datoLL->m_order++;
        ptrCmp = tempN;
        //m_listaBH.areglarWithNode(temp);
        m_listaBH.areglar(temp->m_datoLL);
        //temp->m_pSgteLL =0;
    }
}


template<typename T>
void BinomialHeap<T>::normalizarBinomialHeap(){
    // si solo hay un elemento en l0a lista , no hace nada
    if (m_listaBH.isUnique()  ) return;
    //NodoLL< NodoBH<T>* > *temp = m_listaBH.begin();
    auto *temp = m_listaBH.begin();
    auto *tempNext = temp->m_pSgteLL;
    auto *ptrCmp = m_listaBH.begin();
    while(  tempNext && (temp->m_datoLL->m_order == tempNext->m_datoLL->m_order ) ){
        //std::cout << temp->m_datoLL->m_dato << std::endl;
        //temp = temp->m_pSgteLL;
        merge(temp,tempNext, ptrCmp);
        temp = ptrCmp;
        //cout << "1" << std::endl;
        tempNext = temp->m_pSgteLL;
        //cout << "2" << std::endl;
    }

    return;

}



template<typename T>
bool BinomialHeap<T>::insert(T dato){
    NodoBH<T> *newnode = new NodoBH<T>(dato);
    //capturando el minimo
    if( newnode->m_dato < m_pMin->m_dato ) m_pMin = newnode;
    //NodoBH<T> *newnode = new NodoBH<T>(dato,4);
    //m_listaBH.push_front(newnode);
    m_listaBH.insertByOrder(newnode);
    //NORMALIZAR BINOMIAL HEAP
    normalizarBinomialHeap();
    //findByOrder(14,p);
    //bool LinkedList<T>::findByOrder(T d , NodoLL<T> **&p){
    //NodoLL< NodoBH<T>* > **q;
    //m_listaBH.findByOrder(newnode,q);
    //std::cout << "\n";
}




template<typename T>
void BinomialHeap<T>::printList(){
    m_listaBH.printReference();
}


template<typename T>
T BinomialHeap<T>::getMin(){
    return m_pMin->m_dato;
}



// l1 [label="{ { <data>1 }|  <ref> OBx001201201 \n\n\n} | <actual> OA"];

// template<typename T>
// void BinomialHeap<T>::printGraphviz(){
//     std::fstream file;
//     file.open("dot.dot", std::ios::out);
//         file << "digraph ll {\n\n";
//             file << "\tnode [shape=Mrecord, fontsize=16];" << std::endl;
//             file <<"\t" << 1 << " [label=\"{    {  {<data> " << 197 <<  " }  | <grado> g }    |  <ref> /////       }      | <actual> * \"];\n";
//         file << "\n}\n";
//     file.close();
//     system("dot -Tpng dot.dot -o dot.png");
// }




template<typename T>
void BinomialHeap<T>::printInGraphviz(){
    m_listaBH.printInGraphviz();
    std::cout << "\n PRINT MAP GLOBSL\n";
    m_listaBH.print_map_global();
}









// end  BinomialHeap
