#ifndef FDA_H
#define FDA_H
//#include "state.h"
//#include "alphabet.h"
//#include<unordered_map>
#include<map>
#include<iostream>

template<typename TS ,typename TA>
class DFA{
private:
    std::map< TS , TS > States;
    TS InitialState;
public:
    std::map< TA , TA > Alphabets;
    std::map< TS, TS> FinalStates;
    std::map< TS, std::map<TA, TS > > M;
    DFA(){
        ;
    }
    TS getInitialState(){return InitialState;}
    //~DFA(){}
    //STATES
    void addState( TS v){
        States.insert( std::make_pair(v,v)  );
    }


    //ALPHABET
    void addAlphabet(TA v){
        Alphabets.insert( std::make_pair(v,v) );
    }


    //INITIAL INSERT
    void setInitialState(TS&v){
        InitialState = v;
    }


     // FINAL STATE
    void addFinalState(TS v){
        FinalStates.insert( std::make_pair(v,v) );
    }


     //FILLMATRIX
    void FillMatrix(TS ts1, TA alp, TS ts2){
        M[ts1][alp]=ts2;
    }


    // verifica si una cadena pertenece al automata
    bool verify();


    void showDFA(){
        std::cout << "MOSTRANDO LOS DATOS DE EL DFA" << std::endl;
        std::cout << "ESTADOS" << std::endl;
        for(auto it = States.begin() ;it != States.end() ; it++){
            std::cout << (*it).first  << " ";
        }
        std::cout << std::endl;

        std::cout << "ALPHABET" << std::endl;
        for(auto it = Alphabets.begin() ;it != Alphabets.end() ; it++){
            std::cout << (*it).first  << " ";
        }
        std::cout << std::endl;
        std::cout << "ESTADO INICIAL "   << std::endl;
        std::cout << InitialState << std::endl;

        std::cout << "ESTADOS DE ACEPTACION" << std::endl;
        for(auto it = FinalStates.begin() ;it != FinalStates.end() ; it++){
            std::cout << (*it).first  << " ";
        }
        std::cout << std::endl;


        std::cout << "MOSTRANDO LA MATRIZ DE TRANSCION DE EL DFA"  << std::endl;
        for(auto it = M.begin() ; it != M.end() ; it++){
            for(auto et =  it->second.begin() ; et != it->second.end() ; et++ ){
                std::cout << it->first << " " << et->first << " " << et->second << std::endl;
            }
            std::cout << std::endl;
        }

    }


};



#endif // FDA_H
