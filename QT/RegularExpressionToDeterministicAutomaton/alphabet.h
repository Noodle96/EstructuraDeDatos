#ifndef ALPHABET_H
#define ALPHABET_H
#include <iostream>
template<typename T>
class Alphabet{
private:
    T dato;
public:
    Alphabet(){}
    Alphabet(T dato){
        this->dato= dato;
    }
    ~Alphabet(){}
    T getDato()const{return dato;}
    bool operator ==(const Alphabet<T> &p2)const{
            return dato==p2.dato;
        }
    friend std::ostream& operator << (std::ostream &out, Alphabet &p){
            out << p.dato << " "
                << "\n";
            return out;
    }
};

#endif // ALPHABET_H
