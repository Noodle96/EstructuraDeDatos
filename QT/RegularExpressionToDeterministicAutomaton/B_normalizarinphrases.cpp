#include "mainwindow.h"
#include "ui_mainwindow.h"

//INPUT => STRING(cadena)
//OUTPUT => LIST CON PHRASES(ver documentacion)
void MainWindow::normalizarInPhrases(std::string w, list< Phrase > &listP ){
    int contTest = 0;
    auto it = w.begin();
    std::string phrase="";
    while(it != w.end()  ){

        //CONTIENEN PARENTESIS
        if( (*it)== '(' ){
            it++;

            while( 1 ){
                if( (*it)==')' && contTest==0 )break;
                if(  (*it) == '(' ) contTest++;
                if( (*it)==')' ) contTest--;
                phrase += (*it);
                it++;
            }


            Phrase p(phrase);
            //auto ot = it; ot++;
            it++;
            if((*it) != '*'){ //here change ot
                p.setIsEstrella(0);
                if(it==w.end()) p.setOperador('F');
                else p.setOperador((*it));
            }else{
                p.setIsEstrella(1); it++; //here change ot
                if(it == w.end()) p.setOperador('F'); //here change ot
                else{p.setOperador((*it));} //here change ot
            }
            phrase.clear();
            listP.push_back(p);
        }


        //NO CONTIENEN PARENTESIS
        else{
            //std::cout << "OJO: "<<(*it) << std::endl;;
            if( isalpha((*it)) ){
                phrase += (*it);
            }
            Phrase p(phrase);
            it++;
            if( (*it) != '*' ){
                p.setIsEstrella(0);
                if(it==w.end()) p.setOperador('F');
                else p.setOperador((*it));
            }
            else{
                p.setIsEstrella(1); it++;
                if(it == w.end()) p.setOperador('F'); //here change ot
                else{p.setOperador((*it));} //here change ot
            }
            phrase.clear();
            listP.push_back(p);
        }//endelse
        if(it == w.end())break;
        it++;
    }//endWhile
}
