#ifndef WORD_H
#define WORD_H
#include<iostream>
class Word{
private:
    std::string word;
    std::string tipo;
    int linea;
public:
    Word(std::string word, std::string tipo, int linea){
        this->word = word;
        this->tipo = tipo;
        this->linea = linea;
    }
    ~Word(){}
    std::string getWord()const{return this->word;}
    std::string getTipo()const{return this->tipo;}
    int getLinea()const{return linea;}
};


#endif // WORD_H
