#ifndef STATE2_H
#define STATE2_H

#include <iostream>


class State2{
private:
    //T dato;
    //int pos;
    static int dato;
public:
    State2(){
        this->dato++;
    }
    //State(T dato){
        //this->dato = dato;
        //this->pos = cont;
        //this->cont = this->cont + 1;
    //}
    ~State2(){}
    static int getDato(){return dato;}
    std::string getState(){
       std::string S("S");
       return S + std::to_string(dato);
    }
};




#endif // STATE2_H
