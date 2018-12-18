template<typename T>
void RedBlack<T>::Add(T d){
    cout << "Add: " << d << endl;
    //agregando iterartivamente
    bool repeat = false;
    NodoRB<T> *temp;
    NodoRB<T> *q;
    //NodoRB<T> *f;
    if(!m_pRoot){
        m_pRoot = new NodoRB<T>(d); //return
        temp = m_pRoot;
    }
    else{
        temp = m_pRoot;
        q = temp;
        //f = q;
        while(temp){
            //if (!temp){temp = new NodoRB<T>(d); temp->m_pFather=q;break;}
            if(temp->m_Dato == d){  repeat = true;  break;} //return
            //f = q;
            q = temp;
            temp = temp->m_pSon[ temp->m_Dato < d ];
        }
        if(!repeat){
            q->m_pSon[ q->m_Dato < d ] = new NodoRB<T>(d);
            q->m_pSon[q->m_Dato < d]->m_pFather = q;
        }
        temp = q->m_pSon[ q->m_Dato < d ];

    }


    if(!repeat){//verificar los casos
        insercion_caso1(temp);
    }
    else{
        //nothing to do
    }
}

//INSERCION CASO 1
template<typename T>
void RedBlack<T>::insercion_caso1(NodoRB<T> *&n){
    cout << "EntroCaso1" << endl;
	if (n->m_pFather == 0){
		n->color = BLACK;
    }
	else
		insercion_caso2(n);
}


//INSERCION CASO 2
template<typename T>
void RedBlack<T>::insercion_caso2(NodoRB<T> *&n){
    cout << "entro Caso 2" << endl;
	if (n->m_pFather->color == BLACK)
		return; /* Árbol válido. */
	else
		insercion_caso3(n);
}

//INSERCION CASO 3
template<typename T>
void RedBlack<T>::insercion_caso3(NodoRB<T> *&n){
	NodoRB<T> *t = tio(n), *a;

	if ((t != NULL) && (t->color == RED)) {
		n->m_pFather->color = BLACK;
		t->color = BLACK;
		a = abuelo(n);
		a->color = RED;
		insercion_caso1(a);
	} else {
		insercion_caso4(n);
        }
}


//INSERCION CASO 4
template<typename T>
void RedBlack<T>::insercion_caso4(NodoRB<T> *&n){
	NodoRB<T> *a = abuelo(n);

	if ((n == n->m_pFather->m_pSon[1]) && (n->m_pFather == a->m_pSon[0])) {
		rotar_izda(n->m_pFather);
		n=n->m_pSon[0];
	} else if ((n == n->m_pFather->m_pSon[0]) && (n->m_pFather == a->m_pSon[1])) {
		rotar_dcha(n->m_pFather);
		n=n->m_pSon[1];
	}
	insercion_caso5(n);
}



//INSERCION CASO5
template<typename T>
void RedBlack<T>::insercion_caso5(NodoRB<T> *&n){
	NodoRB<T> *a = abuelo(n);

	n->m_pFather->color = BLACK;
	a->color = RED;
	if ((n == n->m_pFather->m_pSon[0]) && (n->m_pFather == a->m_pSon[0])) {
		rotar_dcha(a);
	} else {
		/*
		 * En este caso, (n == n->padre->dcho) && (n->padre == a->dcho).
		 */
		rotar_izda(a);
	}
}







template<typename T>
void RedBlack<T>::rotar_izda(NodoRB<T> *&p){
    NodoRB<T> **aux=&m_pRoot;
    if(p->m_pFather!=NULL && p->m_pFather->m_pSon[1]==p)
        aux=&(p->m_pFather->m_pSon[1]);
    else if(p->m_pFather!=NULL && p->m_pFather->m_pSon[0]==p)
        aux=&(p->m_pFather->m_pSon[0]);

    *aux=p->m_pSon[1];
    (*aux)->m_pFather=p->m_pFather;
    p->m_pFather=*aux;
    p->m_pSon[1]=(*aux)->m_pSon[0];
    (*aux)->m_pSon[0]=p;

    if(p->m_pSon[1]!=NULL) p->m_pSon[1]->m_pFather=p;
}

template<typename T>
void RedBlack<T>::rotar_dcha(NodoRB<T> *&p){
    NodoRB<T> **aux=&m_pRoot;
    if(p->m_pFather!=NULL && p->m_pFather->m_pSon[1]==p)
        aux=&(p->m_pFather->m_pSon[1]);
    else if(p->m_pFather!=NULL && p->m_pFather->m_pSon[0]==p)
        aux=&(p->m_pFather->m_pSon[0]);

    *aux=p->m_pSon[0];
    (*aux)->m_pFather=p->m_pFather;
    p->m_pFather=*aux;
    p->m_pSon[0]=(*aux)->m_pSon[1];
    (*aux)->m_pSon[1]=p;

    if(p->m_pSon[0]!=NULL) p->m_pSon[0]->m_pFather=p;
}






template<typename T>
NodoRB<T> *RedBlack<T>::abuelo(NodoRB<T> *n){
	if ( (n != 0) && (n->m_pFather != 0)  )
		return n->m_pFather->m_pFather;
	else
		return 0;
}

template<typename T>
NodoRB<T> *RedBlack<T>::tio(NodoRB<T> *n){
	NodoRB<T> *a = abuelo(n);
	if (n->m_pFather == a->m_pSon[0])
		return a->m_pSon[1];
	else
		return a->m_pSon[0];
}





template<typename T>
void RedBlack<T>::print(){
    Queue< NodoRB<T>* > *treeQueue = new Queue< NodoRB<T>* >();
    treeQueue->push(m_pRoot);
    NodoRB<T> *nodo;
    while( !treeQueue->isEmpty() ){
         nodo = treeQueue->top();treeQueue->pop();
        std::cout << nodo->m_Dato << ' ';
        if(nodo->m_pSon[0]) treeQueue->push(nodo->m_pSon[0]);
        if(nodo->m_pSon[1]) treeQueue->push(nodo->m_pSon[1]);
    }
    std::cout  << '\n';
    delete treeQueue;
}

/*

digraph ll {
    node [shape=record];
    4[label="{ <data> 4 | <coef> 0 | { <left>  | <right>  }} "];
    2[label="{ <data> 2 | <coef> 0 | { <left>  | <right>  }} "];

    4:left:c -> 2;
}

*/



template<typename T>
void RedBlack<T>::printSVG(){
    Color clr;
    std::string nameColor;
    std::fstream file;
    Queue< NodoRB<T>* > *treeQueue = new Queue< NodoRB<T>* >();
    Queue< NodoRB<T>* > *temp = new Queue< NodoRB<T>* >();
    NodoRB<T> *nodo;
    file.open("redblack.dot", std::ios::out);
    file << "digraph ll {" << std::endl;
    file  << "\tnode [shape=record];" <<  std::endl;

    treeQueue->push(m_pRoot);
    while( !treeQueue->isEmpty() ){ //etiquetando nodos
         nodo = treeQueue->top();treeQueue->pop();

        //visitar NodoRB
        //std::cout << nodo->m_Dato << ' ';
        clr = nodo->color;
        if(clr == RED )nameColor = "red";
        if(clr == BLACK) nameColor = "grey26";


        // file << "\t"<< nodo->m_Dato << "[style=filled ,fillcolor=" << nameColor <<" label=\"{ <data> " << nodo->m_Dato
        //                      << " | <color> " << nodo->color
        //                      << " | { <left>  | <right>  }} \"];" << std::endl ;

        file << "\t"<< nodo->m_Dato << "[style=filled ,fillcolor=" << nameColor <<" label=\"{ <data> " << nodo->m_Dato
                             << "  | { <left>  | <right>  }} \"];" << std::endl ;

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
    system("dot -Tpng redblack.dot -o redblack.png");
}





//end RedBlack.tpp
