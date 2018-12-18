#include "mainwindow.h"
#include "ui_mainwindow.h"


//DADO LA LISTA DE FRASES TENEMOS QUE LLENARLOS A LA LISTA DE NFA(MAINWINDOW)
void MainWindow::analizeListPhrases(std::list< Phrase > &listP ,  std::list< std::pair< NFA<string,string>,char > > &listpair , NFA<string,string> &final  ){
    std::cout << "analizeListPhrases()" << std::endl;
    //NFA<std::string , std::string> NFAFinal;
    auto it = listP.begin();
    while( it != listP.end() ){
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////
         NFA<string,string> nfat;
         visitarAFondoCrearAutomataIt(nfat,(*it));
         listpair.push_back( std::make_pair(nfat,(*it).getOperador()) );
         nfat.clearAll();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //std::cout << (*it).getPhrase() << " " << (*it).getIsEstrella() << " " << (*it).getOperador() << std::endl;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////s
        it++;
    }

    //uniendo el final
    auto ot = (*listpair.begin()).first;
    auto et = listpair.begin();
    char operadorAct = (*et).second;
    et++;

    for( ; et != listpair.end() ; et++){
        if(operadorAct == '.'){
            concatenate( ot, (*et).first,final );
        }
        if(operadorAct=='|'){
            Union( ot, (*et).first,final );
        }
        ot = final;
        final.clearAll();
        operadorAct = (*et).second;
    }

    //IMPRIMIENDO EL FINAL
    //listNFA.clear();//Borrar esto
    //listNFA.push_back(std::make_pair(ot,'F'));
    //std::cout << "IMPRIMIENDO EL FINAL" << std::endl;
    //ot.printNFA();
    final = ot;
}

void MainWindow::visitarAFondoCrearAutomataIt(NFA<std::string, std::string > &nfat, Phrase &p ){
    //si el len de la frase es de tamaño 1
    if(p.getPhrase().length()==1){
        State state1;
        std::string d_state1 = state1.getState();
        State state2;
        std::string d_state2 = state2.getState();
        nfat.addState(d_state1);
        nfat.addState(d_state2);
        nfat.addAlphabet(p.getPhrase());
        nfat.setInitialState(d_state1);
        nfat.addFinalState(d_state2);
        nfat.FillMatrix( d_state1, p.getPhrase() ,d_state2 );
    }else{//el len de la frase es mayor a 1 , tiene que recorrer por la lista de sus hijos
        //aanalizeListPhrases(p.m_Children);
        std::list< std::pair< NFA<string,string>,char > > l;
        NFA<string,string> f;
        analizeListPhrases(p.m_Children,l,f);
        nfat =f;
    }

    if(p.getIsEstrella()){
        NFA<std::string,std::string> nfa2;
        estrella(nfat,nfa2);
        nfat = nfa2;
    }
}


/*
NFA<std::string, std::string> resul;
//std::cout << "Hola" << std::endl;
auto et = listNFA->begin();
auto ot = listNFA->begin();
ot++;
for( ;ot != listNFA->end() ; ot++){
    //Union((*et).first, (*ot).first, resul);
    estrella((*ot).first,resul);
}
listNFA->clear();  //borrar esto
listNFA->push_back(std::make_pair(resul,"algo")); //
resul.printNFA();
*/
