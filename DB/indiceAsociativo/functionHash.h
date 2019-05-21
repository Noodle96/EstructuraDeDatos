#ifndef FUNCTIONHASH_H
#define FUNCTIONHASH_H

#include<cmath>

#define NHASH 11
#define NARRAY 3
using ULI = unsigned long int;
//esta functionHash retorna un valor dentro del rango de NHASH
ULI returnValueOfString(std::string str){
    auto n = str.size()-1;
    ULI resul = 0;
    for(auto it = str.begin() ; it != str.end() ; it++){
        resul += (*it) * pow(31,n);
        //std::cout << (*it) << " " << n << std::endl;
        n--;
    }
    return resul%NHASH;
}





#endif // FUNCTIONHASH_H
