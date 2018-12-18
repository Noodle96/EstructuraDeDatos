

// cout << "p1 == p2 " << ( (p11==p12) ? "Si": "No" ) << std::endl;
template <typename T>
int Bst<T>::altura(NodoBST<T>*p){
    if(!p)return 0;
    return 1 + fmax(  altura(p->m_pSon[0]),altura(p->m_pSon[1])  );
}
