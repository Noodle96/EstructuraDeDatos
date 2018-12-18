
//begin to binomialheap.tpp



/*
    FUNCTIONS:
        void insertByOrder(T d);
        void printOnlyListBH();
        void removeByDato(T);
        void AsignarPadre(NodoBH<T>*&);
        void pushFront(NodoBH<T>*&);
        void insertar(T);
        void normalize();
        void merge(NodoBH<T>*&, NodoBH<T>*&, NodoBH<T>*&);
*/


/*
    Esta funcion mete  "d"  a la m_listBH ordenado respecto a el grado
*/
template<typename T>
void BinomialHeap<T>::insertByOrder(T d){
    NodoBH<T> *newnode = new NodoBH<T>(d);
    if( m_listBH.empty() ){
        m_listBH.push_front(newnode);
        return;
    }
    auto it = m_listBH.begin();
    for( ;  it != m_listBH.end(); it++){
        if( newnode->orderNBH <= (*it)->orderNBH   ){
            m_listBH.insert(it,newnode);
            return;
        }
    }
    m_listBH.push_back(newnode);
}



//inprime solo la lista BinomialHeap
template<typename T>
void BinomialHeap<T>::printOnlyListBH(){
    for(auto et = m_listBH.begin() ; et != m_listBH.end() ; et++){
        //std::cout << (*et)->m_datoNBH << " | " << (*et)->orderNBH << "     ";
        std::cout << *(*et) ;
    }
    std::cout << std::endl;
}




/*
    elimina un elemento de la lista
    Parametro T d
    Se crea un NodoBH<T>(d) y se elimina ese nodo
*/
template<typename T>
void BinomialHeap<T>::removeByDato(T d){
    for(auto it = m_listBH.begin() ; it != m_listBH.end() ; it++){
        if( (*it)->m_datoNBH == d ){
            m_listBH.remove(*it);
            return;
        }
    }
}



/*
    a cada nodobh de la list se le asigna un padre que sera pasado como Parametro
*/
template<typename T>
void BinomialHeap<T>::AsignarPadre(NodoBH<T>*&p){
    for(auto it = m_listBH.begin() ; it != m_listBH.end() ; it++){
        (*it)->m_fatherNBH = p;
    }
}




/*
    INSERTA AL INICIO DE UNA LISTA, SE LE PASA POR PARAMETRO EL NODO PUSHEAR
*/
template<typename T>
void BinomialHeap<T>::pushFront(NodoBH<T>*&p){
    m_listBH.push_front(p);
}





//MERGE
template<typename T>
void BinomialHeap<T>::merge(NodoBH<T>*&temp, NodoBH<T>*&tempN, NodoBH<T>*&tempCmp){
    //tempN se va de hijo
    if( temp->m_datoNBH <= tempN->m_datoNBH ){
        temp->m_ChildrenNBH.push_front(tempN);
        temp->orderNBH++;
        tempCmp = temp;
        removeByDato(tempN->m_datoNBH);
        //asignanado padre
        auto et = temp->m_ChildrenNBH.begin();
        for( ; et != temp->m_ChildrenNBH.end(); et++){
            (*et)->m_fatherNBH = temp;
        }
    }else{
        //temp de va de hijo
        tempN->m_ChildrenNBH.push_front(temp);
        tempN->orderNBH++;
        tempCmp = tempN;
        removeByDato(temp->m_datoNBH);
        //tempN->m_ChildrenNBH.AsignarPadre(tempN);
        auto et = tempN->m_ChildrenNBH.begin();
        for( ; et != tempN->m_ChildrenNBH.end(); et++){
            (*et)->m_fatherNBH = tempN;
        }
    }
}



/*
    LA FUNCION NORMALIZE VA A VERIFICAR QUE EL LA LISTA PRINCIPAL(m_listaBH)
    NO HAYAN ELEMENTOS CON EL MISMO GRADO
*/
template<typename T>
void BinomialHeap<T>::normalize(){
    //no hace nada en caso sea el unico elemento
    if(m_listBH.size() == 1 )return;
    //std::cout << "LLAMADO" <<  std::endl;
    class std::list<NodoBH<T>*>::iterator temp;
    temp = m_listBH.begin();
    //std::list< NodoBH<T>* >::iterator temp = m_listBH.begin();
    auto tempN =m_listBH.begin()++;
    auto tempCmp = m_listBH.begin();;
    //if( (*tempN) ){
        // std::cout << "existe tempN" << std::endl;

        //std::cout << (*tempN)->m_datoNBH <<std::endl;
    //}
    //std::cout<< (*m_listBH.end())->m_datoNBH;


    //std::cout << (*tempN)->m_datoNBH <<std::endl;
    //std::cout << (*tempCmp)->m_datoNBH <<std::endl;
    // for(auto et = m_listBH.begin() ; et != m_listBH.end() ; et++){
    while( tempN != m_listBH.end() && ( (*temp)->orderNBH == (*tempN)->orderNBH ) ){
        //std::cout << "Dato : "<<  (*temp)->m_datoNBH << " ";

        merge(*temp , *tempN , *tempCmp);

    }
    std::cout << "\n";
}




/*
    FUNCION EXTERNA:
    INSERTA A M_LISTABH <principal>
*/
template<typename T>
void BinomialHeap<T>::insertar(T d){
    //a medida que insertamos vamos seleccionando su minimo
    if(  d < m_Minimo->m_datoNBH  ){
        m_Minimo->m_datoNBH = d;
    }
    //insertamos simepre respecto al order
    insertByOrder(d);

    //una vez que se inserto verificamos que no haya dos elementos con el mismo grado en la lista
    normalize();


}








//end binomialheap.tpp
