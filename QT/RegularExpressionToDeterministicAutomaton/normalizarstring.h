#ifndef NORMALIZARSTRING_H
#define NORMALIZARSTRING_H
#include<iostream>
#include<list>
#include<cctype>

class NormalizarStr{
private:
    std::string word;
public:
    NormalizarStr(std::string w){
        this->word = w;
    }
    ~NormalizarStr(){}

    void quitarEspaciosBlanco();
    void normalize();
    bool EqualLlaves();
    bool noCierres();



    std::string getWord(){return this->word;}

};


#endif // NORMALIZARSTRING_H
