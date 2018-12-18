#ifndef FUNCTIONS_H
#define FUNCTIONS_H
template <typename T>
bool isHoja(NodoBST<T>*p){
    return ( ( p->m_pSon[0] && !p->m_pSon[1] ) ||  ( !p->m_pSon[0] && p->m_pSon[1] )  );
}


#endif // FUNCTIONS_H
