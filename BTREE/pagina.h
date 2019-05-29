#ifndef PAGINA_H
#define PAGINA_H

#include<array>

template<typename T, int k = 5>
class Pagina{
private:
    std::array<T,k> m_keys;
    std::array<long int,k> m_dirRecord;
    std::array<long int,k> m_dirPaginaSon;
public:
    Pagina();
    ~Pagina(){}
    bool isFull();
    bool isEmpty();
    bool findElement(T ke,long int);
    void printPagina();
    void insertKey(T);
};
 #include "pagina.tpp"



#endif //PAGINA_H
