#include "mainwindow.h"
#include "ui_mainwindow.h"


/*
    ESTA FUNCION TOMA LA LISTA DE PHRASES EN DONDE CADA PHRASE PUEDE SER DE LEN > 1
    Y ES ALLI EN DONDE IREMOS HASTA SUS HIJOS PARA PONERLOS A LEN = 1
*/

void MainWindow::normalizeFontListPhrases(std::list<Phrase>  &l){
    auto it = l.begin();
    while(it != l.end() ){
        //entrar a sus hijos e ir añadiendo a la m_Childre hasta que todos sean de len 1
        if( (*it).getPhrase().length() != 1 ){
            hacerLen1Todos((*it));
        }
        it++;
    }
}


void MainWindow::hacerLen1Todos(Phrase &p){

    normalizarInPhrases(p.getPhrase(),p.m_Children);

    if(  verificarListPhraseUno(p.m_Children)  ){
        return;
    }
    //for(auto it = p.m_Children.begin() ; it != p.m_Children.end() ; it++){
    //    hacerLen1Todos( (*it) );
    //}
    normalizeFontListPhrases(p.m_Children);

}





bool  MainWindow::verificarListPhraseUno(std::list<Phrase> &l){
    //if(l.empty())return false;
    for(auto it = l.begin() ;it != l.end()  ; it++){
        if( (*it).getPhrase().length()  !=1)return  false;
    }
    return true;
}
