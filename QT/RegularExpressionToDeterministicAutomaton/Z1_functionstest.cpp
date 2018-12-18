#include "functionsTest.h"

void concatenate( NFA<std::string,std::string> &nfa1,  NFA<std::string,std::string> &nfa2, NFA<std::string,std::string> &nfa3 ){
    //pasando los estados de nf1 a nf3
    for(auto it = nfa1.States.begin()  ; it != nfa1.States.end(); it++){
        nfa3.addState((*it).first );
    }
    //pasando los estados de nf2 a nf3
    for(auto it = nfa2.States.begin() ; it != nfa2.States.end(); it++){
        nfa3.addState((*it).first );
    }

    //psando el alfabeto de nf1 a nf3
    for(auto it = nfa1.Alphabets.begin() ; it != nfa1.Alphabets.end() ; it++){
        nfa3.addAlphabet((*it).first);
    }

    //pasando el alfabeto de nf2 a nf3
    for(auto it = nfa2.Alphabets.begin() ; it != nfa2.Alphabets.end() ; it++  ){
        nfa3.addAlphabet((*it).first);
    }

    //seteando el estado inicial del nf3(nuevo ya concatenado)
    nfa3.setInitialState(nfa1.InitialState);

    //agregando los estados finales a nf3
    for(auto it = nfa2.FinalStates.begin() ; it != nfa2.FinalStates.end() ; it++  ){
        nfa3.addFinalState((*it).first);
    }

    //recorriendo la matriz de transicion de nf1 y agregando a la nfa3
    //example [s0][a]={s1,s2,s3}
    for(auto it = nfa1.M.begin() ; it != nfa1.M.end() ; it++){
        // cout << (*it).first   => s0
        for(auto et = (*it).second.begin() ; et != (*it).second.end() ; et++){
            //cout << (*et).first    => a
            for(auto ot = (*et).second.begin() ; ot != (*et).second.end(); ot++){
                //cout << (*ot) << ", ";    =>    {s1,s2,s3}
                nfa3.FillMatrix((*it).first, (*et).first,  (*ot));
            }
        }
    }

    //recorriendo la matriz de transicion de nf2 y agregando a la nfa3
    //example [s0][a]={s1,s2,s3}
    for(auto it = nfa2.M.begin() ; it != nfa2.M.end() ; it++){
        // cout << (*it).first   => s0
        for(auto et = (*it).second.begin() ; et != (*it).second.end() ; et++){
            //cout << (*et).first    => a
            for(auto ot = (*et).second.begin() ; ot != (*et).second.end(); ot++){
                //cout << (*ot) << ", ";    =>    {s1,s2,s3}
                nfa3.FillMatrix((*it).first, (*et).first,  (*ot));
            }
        }
    }

    for(auto it = nfa1.FinalStates.begin() ; it != nfa1.FinalStates.end() ; it++){
        nfa3.FillMatrix((*it).first,"E", nfa2.InitialState);
    }

}





void Union(NFA<std::string,std::string> &nfa1,  NFA<std::string,std::string> &nfa2 , NFA<std::string,std::string> &nfa3){
    //pasando los estados de nfa1 a nfa3
    for(auto it = nfa1.States.begin(); it != nfa1.States.end() ; it++){
        nfa3.addState((*it).first);
    }

    //pasando los estados de nfa2 a nfa3
    for(auto it = nfa2.States.begin(); it != nfa2.States.end() ; it++){
        nfa3.addState((*it).first);
    }

    //agregando el alphabeto de nfa1 a nfa3
    for(auto it = nfa1.Alphabets.begin() ;  it != nfa1.Alphabets.end(); it++){
        nfa3.addAlphabet((*it).first);
    }

    //agregando el alphabeto de nfa2 a nfa3
    for(auto it = nfa2.Alphabets.begin() ;  it != nfa2.Alphabets.end(); it++){
        nfa3.addAlphabet((*it).first);
    }

    //pasando los estados de aceptacion de nfa1 a nfa3
    for(auto it = nfa1.FinalStates.begin() ; it != nfa1.FinalStates.end() ; it++){
        nfa3.addFinalState((*it).first);
    }

    //pasando los estados de aceptacion de nfa2 a nfa3
    for(auto it = nfa2.FinalStates.begin() ;  it != nfa2.FinalStates.end(); it++){
        nfa3.addFinalState((*it).first);
    }

    //creando el nuevo estado inicial
    State s;
    std::string data = s.getState();
    nfa3.setInitialState(data);
    nfa3.addState(data);


    //entrando a la matriz de transicion de nfa1 y pasarsela a nfa3
    //example [s0][a]={s1,s2,s3}
    for(auto it = nfa1.M.begin() ; it != nfa1.M.end(); it++){
        //cout << (*it).first // s0
        for(auto et = (*it).second.begin() ;et != (*it).second.end() ; et++){
            //cout << (*et).first // a
            for(auto ot = (*et).second.begin() ; ot != (*et).second.end() ; ot++){
                //cout << (*ot) // s1,s2,s3
                nfa3.FillMatrix((*it).first ,  (*et).first , (*ot) );
            }
        }
    }



    //entrando a la matriz de transicion de nfa2 y pasarsela a nfa3
    //example [s0][a]={s1,s2,s3}
    for(auto it = nfa2.M.begin() ; it != nfa2.M.end(); it++){
        //cout << (*it).first // s0
        for(auto et = (*it).second.begin() ;et != (*it).second.end() ; et++){
            //cout << (*et).first // a
            for(auto ot = (*et).second.begin() ; ot != (*et).second.end() ; ot++){
                //cout << (*ot) // s1,s2,s3
                nfa3.FillMatrix((*it).first ,  (*et).first , (*ot) );
            }
        }
    }


    //seteando las uevas transiciones de el nuevo estado hacia los antiguos estados iniciales de nfa1 y nfa2
    nfa3.FillMatrix( data, "E" ,nfa1.InitialState);
    nfa3.FillMatrix(data, "E", nfa2.InitialState);


}





void estrella(NFA<std::string,std::string> &nfa1,  NFA<std::string,std::string> &nfa2){
    //pasando los estados de nfa1 a nfa2
    for(auto it = nfa1.States.begin() ; it != nfa1.States.end(); it++){
        nfa2.addState((*it).first);
    }

    //agregando el alfabeto de nfa1 a nfa2
    for(auto it = nfa1.Alphabets.begin() ;it != nfa1.Alphabets.end() ; it++){
        nfa2.addAlphabet((*it).first);
    }

    //agregando los estados ade aceptacion de nfa1 a nfa2
    for(auto it = nfa1.FinalStates.begin() ; it != nfa1.FinalStates.end(); it++){
        nfa2.addFinalState((*it).first);
    }
     //seteando el nuevo estado inicial y final a la vez
    State s;
    std::string data = s.getState();
    nfa2.addState(data);
    nfa2.setInitialState(data);
    nfa2.addFinalState(data);


    //creando las nuevas transiciones de el nuevo estado inicial-final hacia el antiguo estado inicial
    nfa2.FillMatrix(data,"E",nfa1.InitialState);

    //entrando a la matriz de transicion de nfa y pasandosela a nfa2
    //[s3][b]={s1,s2,s4,s3}
    for(auto it = nfa1.M.begin() ; it != nfa1.M.end(); it++){
        //cout << (*it).first // s3
        for(auto et = (*it).second.begin() ; et != (*it).second.end() ; et++){
            //cout << (*et).first  //b
            for(auto ot = (*et).second.begin() ; ot != (*et).second.end(); ot++){
                //cout << (*ot) // s1,s2,ss4,s3
                nfa2.FillMatrix((*it).first , (*et).first, (*ot)  );
            }
        }
    }

    // de los estados finales ir con la transicion e hacia el antiguo estado incial

    for(auto it = nfa1.FinalStates.begin(); it != nfa1.FinalStates.end(); it++){
        nfa2.FillMatrix( (*it).first, "E", nfa1.InitialState );
    }


}






//end functionstest.cpp
