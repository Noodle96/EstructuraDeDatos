#include "normalizarstring.h"


/*
    FUNCTIONS:
        void quitarEspaciosBlanco();
        void normalize();
*/


/*
    Elimina los espacios en blanco  de la cadena
*/

void NormalizarStr::quitarEspaciosBlanco(){
    std::string tempWord ="";
    for(auto it = word.begin() ;  it != word.end() ; it++){
        if(   (*it) != ' ' ){
            tempWord += (*it);
        }
    }
    this->word = tempWord;
}


/*
    Cada entre dos a-z se le pone . para indicarle que es concatenacion
    example
    input => abc
    output => a.b.c
*/

void NormalizarStr::normalize(){
    std::string resul;
    quitarEspaciosBlanco();
    auto ot = word.begin();
    for(auto it = word.begin() ;  it != word.end() ; ++it){
        if( (  isalpha( (*it) ) || isdigit((*it)) || (*it)=='('  )&& it!=ot ){
            if( isalpha( (*ot) )||  isdigit((*it)) || (*ot)=='*' || (*ot)==')' ){
                resul += (".");
            }
        }
        ot = it;
        //std::cout << "test nomas: " << (*ot) << std::endl;
        resul += (*it);
        //std::cout << resul << std::endl;
    }
    this->word = resul;
}


//LA CADENA WORD TIENE QUE TENER EL MISMO NUMERO DE LLAVES DE APERTURA Y CERRADURA
bool NormalizarStr::EqualLlaves(){
    int contParentesis = 0;
    int contLLaves = 0;
    for(auto it = word.begin() ; it != word.end() ; it++){
        if( (*it)=='(' )contParentesis++;
        if((*it)==')' )contParentesis--;
        if(*it=='{')contLLaves++;
        if( (*it)=='}' )contLLaves--;
    }
    if(contParentesis==0 && contLLaves==0)return true;
    return false;
}


//LA CADENA NO EMPIEZA CON CIERRES
bool NormalizarStr::noCierres(){
    auto it = word.begin();
    if(  (*it)==']' || (*it)=='}' || (*it)==')' || (*it)=='.' || (*it)=='*' || (*it)=='|' ){
        return false;
    }return true;

}
