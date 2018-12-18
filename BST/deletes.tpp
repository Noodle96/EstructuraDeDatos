/*
    bool eliminarHoja(T d);
*/
template <typename T>
bool Bst<T>::eliminarHoja(T d){
    NodoBST<T> **q;
    if ( findI(d,q) ){
        if( isHoja(*q) ){
            delete *q;
            *q = 0;return true;
        }
        return 0;
    }
    return 0;
}
