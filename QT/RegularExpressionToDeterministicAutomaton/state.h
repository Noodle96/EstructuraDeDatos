#ifndef STATE_H
#define STATE_H

#include<iostream>
class State{
private:
    //T dato;
    //int pos;
    static int dato;
public:
    State(){
        this->dato++;
    }
    //State(T dato){
        //this->dato = dato;
        //this->pos = cont;
        //this->cont = this->cont + 1;
    //}
    ~State(){}
    static int getDato(){return dato;}
    std::string getState(){
       std::string S("S");
       return S + std::to_string(dato);
    }
};

#endif // STATE_H
