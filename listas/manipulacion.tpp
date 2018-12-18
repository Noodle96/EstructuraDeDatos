/*
    FUNCIONES QUE MANUIPULARA DESDE LA BASE DE DATOS
*/

template <typename T>
void LinkedList<T>::start(){
    Persona p; bool a;
    load(p,a);
}
template <typename T>
bool LinkedList<T>::AddRegistro(T d){
    //bool here;
    //load(d,here);
    // printR(m_pHead);
    if( AddR(d) ){ // if( !here )
        write(d);
        return true;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::deleteRegistro(T d){
    //bool here;
    //load(d,here);
    if(deleteR(d)) { //if( here)
        ifstream salidaPri; ofstream entradaPri;
        salidaPri.open(functionSupport::nameAgenda()+dat, ios::in);
        entradaPri.open("temp_pri.dat", ios::out | ios::app);
        Persona p;
        while( salidaPri.read((char*) &p, sizeof(p))) {
            if(p!=d) entradaPri.write( (char*) &p,sizeof(p) );
        }
        remove((functionSupport::nameAgenda()+dat).c_str());
        rename("temp_pri.dat",(functionSupport::nameAgenda()+dat).c_str());
        return true;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::modificarRegistro(T d){
    ;
}

template <typename T>
Nodo<T>* LinkedList<T>::findRegistro(T d){
    Nodo<T>**q = 0;
    if(  findR(d,q)){
        // cout << (*q)->m_Dato;
        return *q;
    }
    return 0;
}











// end manipulacion.tpp
