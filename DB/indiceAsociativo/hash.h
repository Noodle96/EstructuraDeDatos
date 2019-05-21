#ifndef  HASH_H
#define HASH_H

#include<array>
#include<list>

#include"index.h"
#include"functionHash.h"

using  PAIR_STR_INT = std::pair<std::string,int>;
using ARRAY_INTERNO = std::array< PAIR_STR_INT ,NARRAY>;
using LISTDESBORDAMIENTO = std::list<ARRAY_INTERNO>;


class HashDS{
private:
    std::array< LISTDESBORDAMIENTO ,NHASH> hashIndicesV2;
public:
    HashDS(){}
    ~HashDS(){}
    void insertInHash(Index &i){
        //i.datosConstantes();
        ULI position = returnValueOfString(i.getIndex());
        //std::cout << i.getIndex() << " le corresponde el value hash  "<<position << std::endl;
        auto &it = hashIndicesV2[position];
        insertInListaDesbordamiento(it,i);

    }
    void insertInListaDesbordamiento(LISTDESBORDAMIENTO &l,Index &in){
        if(l.empty()){//esta vacia la lista en dicha posicion
            ARRAY_INTERNO arrayI; arrayI.fill(std::make_pair("**",-1));
            arrayI[0] = std::make_pair(in.getIndex(),in.getPosition());
            l.push_back(arrayI);return;
        }else{//no esta vacia " "
            for(auto it = l.begin() ; it != l.end() ; it++){//recorrer la lista  horizontal
                for(auto et = (*it).begin() ; et!= (*it).end() ; et++){//recorrer el array vertical
                    if( (*et).first == in.getIndex()  ){
                        return ; // repetidos no son aceptados
                    }else if((*et).first == "**"){//si hay campo => insertar alli
                        (*et) = std::make_pair(in.getIndex(),in.getPosition());
                        return;
                    }
                }
            }
        }
        //push_back en la lista nuevo array
        ARRAY_INTERNO arrayI; arrayI.fill(std::make_pair("**",-1));
        arrayI[0] = std::make_pair(in.getIndex(),in.getPosition());
        l.push_back(arrayI);return;
    }
    void printHashDS(){
        int posicion = 0;
        for(auto it = hashIndicesV2.begin(); it!=hashIndicesV2.end(); it++){//recorrer array vertic
            std::cout << "CAJON " << posicion << " : " << std::endl;
            for(auto et = (*it).begin() ; et != (*it).end() ; et++){//recorre cada lista de desbord
                for(auto ot = (*et).begin() ; ot != (*et).end(); ot++){//recorrer el arrayInterno
                    if(ot){
                        std::cout << (*ot).first << "->" << (*ot).second << "\n";//print el pair<str,int>
                    }
                }
                std::cout << "\n";
            }
            std::cout << "\n";
            posicion++;
        }
    }
    /*******************************************************************************************
    **                            //---FIND---///
    ** LA FUNCION FIND BUSCA POR CLAVE EN LA ESTRUCTURA DE DATOS HASH(PROPIA)
    *******************************************************************************************/
    bool findd(const char * numCuenta, int &dd){
        //std::cout << "FUNCION FIND: " << std::endl;
        ULI position = returnValueOfString(numCuenta);
        std::cout << numCuenta << " le corresponde el value hash  "<<position << std::endl;
        auto &it = hashIndicesV2[position];
        for(auto et = (it).begin() ; et != (it).end(); et++){//recorrer la lista
            for(auto ot =(*et).begin() ; ot != (*et).end(); ot++){ //recorr array del i de la lista
                if((*ot).first == numCuenta){
                    dd = (*ot).second;
                    return true;
                }
            }
        }
        return false;
    }

};


#endif //HASH_H
