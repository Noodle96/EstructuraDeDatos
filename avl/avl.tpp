
//begin avl.tpp

/*
    FUNCTIONS;
    void RotationSimple(NodoAVL<T>*&, Son);
*/
template< typename T>
void AVL<T>::RotationSimple(NodoAVL<T>*&p, Rotation s){
    NodoAVL<T> *q = p->m_pSon[s];
    p->m_pSon[s] = q->m_pSon[!s];
    q->m_pSon[!s] = p;
    p->FE = q->FE = 0;
    p = q;
}


template< typename T>
void AVL<T>::RotationDouble(NodoAVL<T>*&p, Rotation s){
    NodoAVL<T> *q = p->m_pSon[s];
    NodoAVL<T> *r = q->m_pSon[!s];

    p->m_pSon[s] = r->m_pSon[!s];
    q->m_pSon[!s] = r->m_pSon[s];

    r->m_pSon[s] = q;
    r->m_pSon[!s] = p;

    //ajustando factor de equilibrio;
    switch (r->FE) {
        case 0:
            p->FE = q->FE = r->FE = 0;
            break;
        case -1:
            p->FE = 0; q->FE = 1; r->FE = -1;
            break;
        case 1:
            p->FE = -1; q->FE = 0; r->FE = 1;
            break;
    }
    p = r;
}

bool up = true; //global
template<typename T>
void AVL<T>::Add(T d, NodoAVL<T> *&p){
    if (!p){ p = new NodoAVL<T>(d); up = true;return;}
    if(p->m_Dato ==d)return;
    Add(d, p->m_pSon[ p->m_Dato < d ]);
    if(up){
        if(d < p->m_Dato){
             p->FE--;
        }else{
            p->FE++;
        }
    }

    //ojo

    switch (p->FE) {
        case 0:return;
        case 2:
            if( p->m_pSon[1]->FE == 1  ){
                 RotationSimple(p,Rotation(Right));//RDD
                 std::cout << "There was RDD " << std::endl;
                 if(p->FE==0) up=false;
             }else{
                 RotationDouble(p,Rotation(Right)); //RDI
                 std::cout << "There was RDI " << std::endl;
                 if(p->FE==0)up=false;
             }
             break;
        case -2:
            if( p->m_pSon[0]->FE == -1 ){
                RotationSimple(p,Rotation(Left)); //RII
                std::cout << "There was RII " << std::endl;
                if(p->FE==0)up=false;
            }else{
                RotationDouble(p,Rotation(Left)); // RID
                std::cout << "There was RID " << std::endl;
                if(p->FE==0)up =false;
            }
            break;
    }


}


template<typename T>
void AVL<T>::printSVG(){
    std::fstream file;
    Queue< NodoAVL<T>* > *treeQueue = new Queue< NodoAVL<T>* >();
    Queue< NodoAVL<T>* > *temp = new Queue< NodoAVL<T>* >();
    NodoAVL<T> *nodo;
    file.open("arbol.dot", std::ios::out);
    file << "digraph ll {" << std::endl;
    file  << "\tnode [shape=record];" <<  std::endl;

    treeQueue->push(m_pRoot);
    while( !treeQueue->isEmpty() ){ //etiquetando nodos
         nodo = treeQueue->top();treeQueue->pop();

        //visitar NodoAVL
        //std::cout << nodo->m_Dato << ' ';
        file << "\t"<< nodo->m_Dato << "[label=\"{ <data> " << nodo->m_Dato
                             << " | <coef> " << nodo->FE
                             << " | { <left>  | <right>  }} \"];" << std::endl ;
        temp->push(nodo);
        //end visitar NodoAVL
        if(nodo->m_pSon[0]) treeQueue->push(nodo->m_pSon[0]);
        if(nodo->m_pSon[1]) treeQueue->push(nodo->m_pSon[1]);
    }
    std::cout  << '\n';

    //uniendo nodos // nodo3:left:c -> nodo6;
    while(!temp->isEmpty()){
        nodo = temp->top(); temp->pop();
        //visitar NodoAVL
        if(nodo->m_pSon[0]){
            file << "\n\t" << nodo->m_Dato << ":left:c -> " << nodo->m_pSon[0]->m_Dato << ";";
        }else{
            ;
        }
        if(nodo->m_pSon[1]){
            file << "\n\t" << nodo->m_Dato << ":right:c -> " << nodo->m_pSon[1]->m_Dato << ";";
        }else{
            ;
        }
        //end visitar NodoAVL
    }


    file << "\n}";
    file.close();
    delete temp;
    delete treeQueue;
    system("dot -Tsvg arbol.dot -o ARBOL.svg");
}


















//end avl.tpp
