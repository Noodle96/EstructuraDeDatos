#include "word.h"

void Word::increaseFrecuency(){
    m_frecuency++;
}

std::string Word::getPosicionesSring(){
    auto it = m_pPosiciones.begin();
    std::string salida;
    for( ;it != m_pPosiciones.end() ; it++){
        salida += std::to_string((*it));
        salida += " , ";
    }
    return salida;
}
