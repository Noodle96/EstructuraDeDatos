#include "functions.h"

void toLowerStr(std::string &p) {
    auto it = p.begin();
    for(  ;it != p.end() ; it++){
        (*it) = tolower(*it);
    }
}


std::string quitarSignos(std::string &p){
    std::string nueva;
    auto it = p.begin();
    //(*it)=='[' || (*it)==']' || (*it)=='(' || (*it)==')' || (*it)==',' || (*it)=='.' || (*it)=='#' || (*it)=='$' || (*it)=='=' || (*it)=='.'  || (*it)=='?'
    for(   ; it != p.end(); it++){
        if(  ((*it) >= 33 && (*it) <= 64) || ( (*it) >=91 && (*it) <=96 ) || ((*it)>=123 && (*it) <= 126) ){
            ;
        }else{nueva += (*it);}
    }
    return nueva;
}
