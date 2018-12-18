#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::on_btnGenerate_clicked()
{
    //TEST STATE
    /*
    for(int e = 0 ; e < 30 ; e+=2){
        //qDebug()<< e ;
        State s;
        qDebug() << s.getState().c_str();
    }
    */

    QString normalizado;
    std::string normalizadoStr;
    QString regularExpresion = this->ui->txtIn->text();
    //qDebug() << regularExpresion;
    NormalizarStr *ObjNormal  = new NormalizarStr(regularExpresion.toStdString());
    if(!ObjNormal->noCierres()){
        QMessageBox::information(this,"Aviso","la cadena empieza con cierres");
        return;
    }
    if( !ObjNormal->EqualLlaves() ){
        QMessageBox::information(this,"Aviso","No coinciden con las aperturas y cerradura");
        return;
    }

    ObjNormal->normalize();
    normalizadoStr = ObjNormal->getWord();
    normalizado = ObjNormal->getWord().c_str();
    qDebug() << normalizado;


    // PARCIALIZANDO EN PHRASES
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std:: cout << "normalizarInPhrases(normalizadoStr,listPhrases);" << std::endl;
    normalizarInPhrases(normalizadoStr,listPhrases); // la lista general sin ()
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "normalizeFontListPhrases(listPhrases);" << std::endl;
    normalizeFontListPhrases(listPhrases); //  A FONDO
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printListPhrasesGeneral(listPhrases);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    NFA<string,string> final;
    analizeListPhrases(listPhrases, listNFA, final); //LLENA A LA LISTA DE NFA'S
    listNFA.clear();
    listNFA.push_back(std::make_pair(final,'F'));
    final.fillClausulasEpsilon();
    final.printNFA();
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printListNFA();
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    printInDotNFA();
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //manipularemos final(test)
    //std::list<std::string> lo;
    //final.findData("S2","E",lo);
    //for(auto it = lo.begin() ; it != lo.end() ; it++){
    //    std::cout << (*it) << " ";
    //}
    //std::cout << "\n";

    /*
    std::cout << "TEST DE DESTINOmt" << std::endl;
    std::set<std::string> madre;
    madre.insert("S3");
    std::set<std::string> lo;
    final.destinoMT(madre,"a",lo);
    for(auto it = lo.begin() ; it != lo.end() ; it++){
        std::cout << (*it) << " ";
    }
    std::cout << "\n";

    //test de destinoCE
    std::set<std::string> le;
    final.destinoCE(lo,le);
    for(auto it = le.begin() ; it != le.end() ; it++){
        std::cout << (*it) << " ";
    }
    std::cout << "\n";
*/

    //ya formado la matriz compuesta
    final.makeMatrizCompuesta();
    final.printNFAMC();
    std::cout << "PrintG()" << std::endl;
    final.printG();


   final.fillToDFA();
   final.finiteAtomaton.showDFA();
   dfa = final.finiteAtomaton;
   printInDotDFA();


   /*
        OJO APARTIR DE ESTE MOMENTO
        QUE FINAL.FINITEAUTOMATON REPRESENTA NUESTRO AUTOMATA FINAL FINAL
        POR LO TANTO A ESTE LE MANSAREMOS A LA VISTA
    */

    delete ObjNormal;
}
