#ifndef NFA_H
#define NFA_H
//#include "state.h"
//#include "alphabet.h"
//#include<unordered_map>
#include"DFA.h"
#include<iostream>
#include<map>
#include <list>
#include <set>
#include <queue>
#include<algorithm>
#include"statecompuesto.h"
template< typename TS,typename TA>
class NFA{
public:
    std::map< TS , TS > States;
    std::map< TA , TA > Alphabets;
    TS InitialState;
    std::map< TS, TS > FinalStates;
public:
    DFA<TS,TA> finiteAtomaton;
    std::list<   StateCompuesto<TS,TA>  > G;
    std::queue<StateCompuesto<TS,TA>> cola;
    std::map< StateCompuesto<TS,TA> ,std::map<   TA,StateCompuesto<TS,TA>    > > MCompuesta;
    std::map<TS,std::map<TA,TS>> MCompuestaT;

    std::map< TS, std::map< TA, std::list<TS > > > M;
    std::map<TS, std::set<TS>> ClausulasEpsilon;
    NFA(){;}
    ~NFA(){}


    void destinoMT(std::set<TS>& , TA, std::set<TS>&);
    void destinoCE(std::set<TS>&,std::set<TS>&);
    void makeStateCompuesto( std::set<TS> &lo, std::set<TS> &le , StateCompuesto<TS,TA> &s);
    void makeMatrizCompuesta();

    //CLEAR ALL
    void clearAll(){
        this->States.clear();
        this->Alphabets.clear();
        this->FinalStates.clear();
        this->M.clear();
        InitialState="";
    }

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
        //std::cout << "Recibido st1: " << st1 << "  y st2: " << st2 << std::endl;

        M[st1][alp].push_back(st2);
    }

    void FillMatrixCompuesta(StateCompuesto<TS,TA> &st1, TA alp, StateCompuesto<TS,TA> &st2){
        std::cout << "Llenando la matrixCompuesta con: " << std::endl;
        std::cout << st1.getState() << " y " << alp << " Y " << st2.getState() << std::endl;
        MCompuesta[st1][alp] = st2;
        MCompuestaT[st1.getState()][alp]=st2.getState();
        finiteAtomaton.FillMatrix(st1.getState(),alp,st2.getState());

    }

    //IMPRIME LA MATRIZCOMPUESTA
    //std::map< StateCompuesto<TS,TA> ,std::map<   TA,StateCompuesto<TS,TA>    > > MCompuesta;
    void printNFAMC(){
        std::cout << "IMPRIMIENDO LA MATRIZ COMOUESTA" << std::endl;
        for(auto it = MCompuestaT.begin() ;it != MCompuestaT.end()  ; it++){
            //std::cout << (*it).first.getState() << " ";
            for(auto et = (*it).second.begin() ; et != (*it).second.end() ;et++){
                std::cout << (*it).first << "->";
                std::cout << (*et).first << "-->";
                std::cout << (*et).second << std::endl;
            }
        }
    }
    void printG(){
        for(auto it = G.begin() ; it != G.end() ; it++){
           std::cout << (*it).getState() << " " ;
        }
        std::cout << std::endl;
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
            std::cout << (*it).first << " ";
            for(auto et = (*it).second.begin() ; et != (*it).second.end() ; et++){
                std::cout << (*et).first << " -> ";
                for(auto ot = (*et).second.begin() ; ot != (*et).second.end() ; ot++){
                    std::cout << (*ot) << " " ;
                }
                std::cout << "\n";
            }
        }

        std::cout << "\n";
        std::cout << "MATRIZ DE CLAUSULAS: "  << std::endl;
        for(auto it = ClausulasEpsilon.begin() ;  it != ClausulasEpsilon.end() ; it++){
            std::cout << (*it).first << " -> ";
            for(auto et = (*it).second.begin() ;  et != (*it).second.end() ; et++){
                std::cout << (*et) << " ";
            }
            std::cout << "\n";
        }


    }


    //ENCUENTRA TODOS LOS DESTINO DE Sn CON E
    bool findData(TS s, TA a ,std::set<TS> &lo){
        auto it = M.find(s);
        if(!(it != M.end())  ){return  false;}
        auto et = (*it).second.find(a);
        if(!(et !=  (*it).second.end() ) ) return false;
        if( (*et).second.empty() )return false; //lista vacia
        std::cout << "inside findData()" << std::endl;
        for(auto ot = (*et).second.begin() ; ot != (*et).second.end(); ot++){
            lo.insert((*ot));
            std::cout << "inside for()" << std::endl;
            findData((*ot),a,lo);
        }
        return true;

        //lo = (*et).second;
    }



    //LLENAR LAS CLAUSULAS_EPSIOLOS SEGUN M=> MATRIZ DE TRANSICION M
    void fillClausulasEpsilon(){
        std::cout << "fillClausulasEpsilon()" << std::endl;
        for(auto it = States.begin();  it != States.end() ; it++){
            std::cout << "hola" << std::endl;
            std::set<TS> lo;
            findData((*it).first,"E",lo);
            //lo.sort();
            //si esta vacio lo llena con vacio en la clausulaEpsilon
            if(lo.empty()){
                ClausulasEpsilon [(*it).first].insert("&");
            }
            for(auto et = lo.begin() ;  et != lo.end() ; et++){
                ClausulasEpsilon [(*it).first].insert((*et));
                //std::cout << (*et) << " ";
            }

            std::cout << "\n";
        }
    }





    void fillToDFA(){
        //llenando todos los estados
        for(auto it = G.begin() ; it != G.end() ; it++){
            finiteAtomaton.addState((*it).getState() );
        }
        //llenando todo el alfabeto
        for(auto it = Alphabets.begin() ;  it != Alphabets.end() ; it++){
            finiteAtomaton.addAlphabet((*it).first );
        }
        //finiteAtomaton.setInitialState(InitialState);

    }




};

#include "nfafunction.tpp"

#endif // NFA_H
