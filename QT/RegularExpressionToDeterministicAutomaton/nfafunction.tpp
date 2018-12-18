#include "NFA.h"





/*
*   DADO UN SET DE TS REGRESA A DONDE CONCURREN CON a SEGUN LA MATRZ DE TRANSICIONES
*/

template<typename TS, typename TA>
void NFA<TS,TA>::destinoMT(std::set<TS> &madre , TA  a, std::set<TS> &lo){
    if(madre.empty())return;//
    for(auto it = madre.begin() ; it != madre.end() ; it++){
        auto et = M.find((*it));
        if(et != M.end()){//found  => osea si esta s1, s2, s3, etc

            auto ot = (*et).second.find(a);
            if(ot != (*et).second.end() ){//found
                for(auto ut = (*ot).second.begin() ; ut != (*ot).second.end() ;ut++){
                    lo.insert((*ut));
                }
            }
            //DE TODAS MANERAS BUSCAR TAMBIEN CON a = "E"
            auto otP = (*et).second.find("E");
            if(otP != (*et).second.end()){ //found
                std::set<std::string> WE_Madre;
                for(auto utP = (*otP).second.begin() ; utP != (*otP).second.end() ;utP++){
                    //lo.insert((*utP));
                    //std::cout << "Paso por" << (*utP) << " ";
                    WE_Madre.insert((*utP));
                }
                destinoMT(WE_Madre,a,lo);
            }else{
                ;//return;
            }
        }
        else{
            ;//return ;// // no lo encontro a s1, s2, s3 , etc
        }

    }
}




/*
 *  DADO UN SET DE TS , RERGRESARA EL SET LOS QUE CONCURREN CON E
*/
template<typename TS, typename TA>
void NFA<TS,TA>::destinoCE(std::set<TS> &lo,std::set<TS> &le ){
    if(lo.empty())return;
    for(auto it = lo.begin() ; it != lo.end(); it++){
        auto et = ClausulasEpsilon.find((*it));
        for(auto ot = (*et).second.begin() ;ot != (*et).second.end() ;  ot++ ){
            le.insert((*ot));
        }
    }
}




/*
*   sadf
*/
template<typename TS, typename TA>
void NFA<TS,TA>::makeStateCompuesto( std::set<TS> &lo, std::set<TS> &le , StateCompuesto<TS,TA> &s){
    StateCompuesto<TS,TA> stt(lo,le);

    auto it = std::find(G.begin(), G.end() , stt);
    //std::cout << "imprimiendo it" << std::endl;
    //std::cout << *(*it).m_Lo.begin()  <<std::endl;
    for(auto ot = lo.begin() ; ot != lo.end() ; ot++){
        std::cout << (*ot) << " " ;
    }
    std::cout << "\n";
    for(auto ot = le.begin() ; ot != le.end() ; ot++){
        std::cout << (*ot) << " " ;
    }
    std::cout << "\n";


    if(  it != G.end()  ){//found
        std::cout << "found" << std::endl;
        s = (*it);
    }else{//not found
        std::cout << "Not found" << std::endl;
        //creando el stado compuesto
        StateCompuesto<TS,TA> stt(lo,le);
        State2 state;
        TS data = state.getState();
        stt.setStateData(data);
        s = stt;
        cola.push(stt);
        G.push_back(stt);


        //haciendo los estados terminales de finiteAutomaton
       //verificando que en lo y le estan los estados de aceptacion de
        //el  actual automata no determinista
        for(auto ut = FinalStates.begin() ; ut != FinalStates.end()  ; ut++){
            auto utp = std::find(lo.begin() , lo.end() , (*ut).first);
            if(utp != lo.end()){//found
                finiteAtomaton.addFinalState(data);
            }
        }
        for(auto ut = FinalStates.begin() ; ut != FinalStates.end()  ; ut++){
            auto utp = std::find(le.begin() , le.end() , (*ut).first);
            if(utp != le.end()){//found
                finiteAtomaton.addFinalState(data);
            }
        }


    }
}

//a*(b|d)


template<typename TS, typename TA>
void NFA<TS,TA>::makeMatrizCompuesta(){
    std::set<TS> InitialStateY; InitialStateY.insert(this->InitialState);
    std::set<TS> set1 = ClausulasEpsilon[InitialState];
    StateCompuesto<TS,TA> V;
    makeStateCompuesto(InitialStateY,set1,V);
    finiteAtomaton.setInitialState(V.state );
    while(!cola.empty()){
        V = cola.front(); cola.pop();
        for(auto it = Alphabets.begin() ; it != Alphabets.end() ; it++){
            std::cout << "hola" << std::endl;
            std::set<TS> lo;
            std::set<TS> le;
            destinoMT(V.getMadre(), (*it).first, lo );

            destinoCE(lo,le);

            std::cout << std::endl;
            StateCompuesto<TS,TA> ret;
            makeStateCompuesto(lo,le,ret);
            std::cout << "ret:" << std::endl;
            std::cout << ret.getState();
            FillMatrixCompuesta(V,(*it).first, ret);
        }
    }
}
