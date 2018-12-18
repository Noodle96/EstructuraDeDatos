#ifndef NFA_H
#define NFA_H

#include<iostream>
#include<map>
#include <list>
#include <set>
#include <queue>
#include<algorithm>

template< typename TS,typename TA>
class NFA{
public:
    std::map< TS , TS > States;
    std::map< TA , TA > Alphabets;
    TS InitialState;
    std::map< TS, std::map< TA, std::list<TS > > > M;
public:
    std::map< TS, TS > FinalStates;
    NFA(){;}
    ~NFA(){}

    //CLEAR ALL
    void clearAll(){
        this->States.clear();
        this->Alphabets.clear();
        this->FinalStates.clear();
        this->M.clear();
        InitialState="";
    }

    bool verify(std::string w){ //esta para areglar esto, no haremos un bucle porque la lista destino solo tiene un valor
        std::string iniS = InitialState;
        std::list<std::string> result;
        for(auto it = w.begin() ; it != w.end() ; it++){
            result = M[iniS][(*it)];
            if(result.empty())return false;
            iniS = *(result.begin());
        }
        //verificamos si iniS pertenece a los estados de aceptacion de  la maquina
        for(auto it = FinalStates.begin() ; it != FinalStates.end(); it++){
            if(iniS == (*it).first) return true;
        }
        return false;
    }


    TS getInitialState(){return  InitialState;}
    //STATES
    void addState( TS v){
        States.insert( std::make_pair(v,v)  );
    }


    //ALPHABET
    void addAlphabet(TA v){
        Alphabets.insert( std::make_pair(v,v) );
    }


    //INITIAL INSERT
    void setInitialState(TS v){
        InitialState = v;
    }


     // FINAL STATE
    void addFinalState(TS v){
        FinalStates.insert( std::make_pair(v,v) );
    }


     //FILLMATRIX
    void FillMatrix(TS st1,TA alp,TS st2){
        M[st1][alp].push_back(st2);
    }
    //IMPRIME LAS CARACTERISTICAS DE EL NFA
    void printNFA(){
        std::cout << "ESTADOS: " << std::endl;
        for(auto it = States.begin() ; it != States.end(); it++){
            std::cout << (*it).first << " ";
        }
        std::cout << "\n";

        std::cout << "Estado Inicial: " << InitialState << std::endl;
        std::cout << "ALFABETO: " << std::endl;
        for(auto it = Alphabets.begin() ; it !=  Alphabets.end() ; it++){
            std::cout << (*it).first << " ";
        }
        std::cout << "\n";
        std::cout << "ESTADOS DE ACEPTACION: " << std::endl;
        for(auto it = FinalStates.begin() ; it != FinalStates.end(); it++){
            std::cout << (*it).first << " ";
        }
        std::cout << "\n";
        std::cout << "MATRIZ DE TRANSICIONES: "  << std::endl;
        for(auto it = M.begin() ; it != M.end() ; it++){
            //std::cout << (*it).first << " ";
            for(auto et = (*it).second.begin() ; et != (*it).second.end() ; et++){
                //std::cout << (*et).first << " -> ";
                for(auto ot = (*et).second.begin() ; ot != (*et).second.end() ; ot++){
                    std::cout << (*it).first << " "<< (*et).first << " " << (*ot);
                }
                std::cout << "\n";
            }
        }
    }
};

#endif // NFA_H
