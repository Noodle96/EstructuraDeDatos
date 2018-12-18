#ifndef PHRASES_H
#define PHRASES_H

#include<iostream>
#include<list>

class Phrase{
private:
    std::string phrase;
    bool isEstrella;
    char operador;
public:
    std::list<Phrase> m_Children;
    Phrase(std::string pr){
        this->phrase = pr;
    }
    ~Phrase(){}
    bool isEmptyChildre(){return m_Children.empty();}
    std::string &getPhrase(){return phrase;}
    bool getIsEstrella(){return isEstrella;}
    char getOperador(){return operador;}

    void setPhrase(std::string pr){phrase = pr;}
    void setIsEstrella(bool isEst){isEstrella=isEst;}
    void setOperador(char oper){operador = oper;}
};

#endif // PHRASES_H
