#include "pagina.h"
template<typename T,int K>
Pagina<T,K>::Pagina(){
    if(sizeof(T)==4){
        for(auto e = 0 ; e < K; e++){
            this->m_keys[e] = -1;
        }
    }

}

template<typename T,int K>
void Pagina<T,K>::printPagina(){
    std::cout << "Printing the m_keys" << std::endl;
    //std::cout << m_keys.size() << std::endl;
    for(auto e = 0 ; e < m_keys.size(); e++){
        std::cout << m_keys[e] << " ";
    }
    std::cout << "\n";

}

template<typename T, int K>
bool Pagina<T,K>::isFull(){
    //para el caso de los int
    for(auto e = 0  ; e < K; e++){
        if(this->m_keys[e]==-1)return false;
    }
    return true;
}

template<typename T, int K>
bool Pagina<T,K>::isEmpty(){
    return (this->m_keys[0]==-1);
}

template<typename T,int K>
bool Pagina<T,K>::findElement(T ke,long int pos){
    if(isEmpty()){
        pos = 0;return false;
    }
    

}
