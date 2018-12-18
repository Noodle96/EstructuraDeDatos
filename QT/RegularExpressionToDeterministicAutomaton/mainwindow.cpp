#include "mainwindow.h"
#include "ui_mainwindow.h"
//(bab*|(bba*)(a(aa*ba)*bb*))
int State::dato = 0;
int State2::dato = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //dfa = new DFA<std::string, std::string>;
    //listNFA = new std::list< std::pair<   NFA<std::string, std::string>, char > >;
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete dfa;
    //delete listNFA;
}

//PRINTINDOT
void MainWindow::printInDotNFA(){
    std::cout << "printInDotNFA()-param listNFA" << std::endl;
    fstream file;
    file.open("/home/Nano/QT/RegularExpressionToDeterministicAutomaton/automata.dot", std::ios::out);
        file << "digraph {\n";
        file << "\trankdir=LR;\n";
        for(auto at = listNFA.begin() ; at != listNFA.end() ; at++){
            for(auto it = (*at).first.M.begin() ; it != (*at).first.M.end() ; it++){
               // std::cout << (*it).first << " "; // "s0"
                for(auto et = (*it).second.begin()  ; et != (*it).second.end() ;  et++){
                    //std::cout << (*et).first << " -> "; // "a"
                    for(auto ot = (*et).second.begin() ;ot != (*et).second.end(); ot++){
                        //std::cout << (*ot) << " "; // "s1" "s2"
                        file << "\t" << (*it).first << "->" << (*ot)  << "[label=\"" << (*et).first <<  "\"];\n";
                    }
                }

            }
            std::cout << "\n";
        }

        file << "\n}";
    file.close();
    system("dot -Tpng /home/Nano/QT/RegularExpressionToDeterministicAutomaton/automata.dot -o /home/Nano/QT/RegularExpressionToDeterministicAutomaton/automata.png");

    //QPixmap pix("/home/Nano/QT/RegularExpressionToDeterministicAutomaton/automata.png");
    //int w = this->ui->labelGrafoPng->width();
    //int h = this->ui->labelGrafoPng->height();
    //this->ui->labelGrafoPng->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio  ));





    //DESCOMENTARESTO EN CASO DE EMERGENCIA

    //QImage image("/home/Nano/QT/RegularExpressionToDeterministicAutomaton/automata.png");
    //item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    //scene = new QGraphicsScene(this);
    //this->ui->graphicsView2->setScene(scene);
    //scene->addItem(item);

}

void MainWindow::printInDotDFA(){
    // file << "\t" << (*it).first << "->" << (*ot)  << "[label=\"" << (*et).first <<  "\"];\n";
    std::cout << "printInDotDFA()" << std::endl;
    fstream file;
    file.open("/home/Nano/QT/RegularExpressionToDeterministicAutomaton/finiteautomaton.dot", std::ios::out);
        file << "digraph {\n";
        file << "\trankdir=LR;\n";

        //pintando el estado inicial
        file << "\t" << "INITIAL" << "[shape=point];\n";
        file << "INITIAL ->" << dfa.getInitialState() << ";\n";
        file << "\t" << dfa.getInitialState() << "[style=radial, color=yellow,weight=bold ];";
        for(auto it = dfa.FinalStates.begin() ; it != dfa.FinalStates.end() ; it++){
             file << "\t" << (*it).first << "[shape=doublecircle,style=filled, color=green];\n";
        }

        for(auto it = dfa.M.begin() ; it !=  dfa.M.end() ; it++){
            for(auto et = (*it).second.begin() ;et != (*it).second.end() ; et++){
                file << "\t" << (*it).first << "->" <<  (*et).second  << "[label=\"" << (*et).first << "\" ];\n";
            }
        }

    file << "\n}";
    file.close();
    system("dot -Tpng /home/Nano/QT/RegularExpressionToDeterministicAutomaton/finiteautomaton.dot -o /home/Nano/QT/RegularExpressionToDeterministicAutomaton/finiteAutomata.png");


    QImage image("/home/Nano/QT/RegularExpressionToDeterministicAutomaton/finiteAutomata.png");
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene = new QGraphicsScene(this);
    this->ui->graphicsView->setScene(scene);
    scene->addItem(item);



    QImage image2("/home/Nano/QT/RegularExpressionToDeterministicAutomaton/finiteAutomata.png");
    item = new QGraphicsPixmapItem(QPixmap::fromImage(image2));
    scene = new QGraphicsScene(this);
    this->ui->graphicsView2->setScene(scene);
    scene->addItem(item);
}













//IMPRIME LA LISTA(Mainwindow) DE NFA
void MainWindow::printListNFA(){
    std::cout << "FUNCION PRINT LIST NFA" << std::endl;
    for(auto it = listNFA.begin() ; it != listNFA.end() ; it++){
        (*it).first.printNFA();
        std::cout << "\n";

    }
}





//IMPRIME LA LISTA PRINCIPAL GUARDADA EN EL MAINWINDOW.H
void MainWindow::printListPhrasesGeneral(std::list<Phrase> &l){
    //std::cout << "printListPhrasesGeneral();" << std::endl;
    for(auto it = l.begin() ; it != l.end() ; it++){
         std::cout << "Phrase: "<< (*it).getPhrase() << "   IsEstrella: "  << (*it).getIsEstrella() << "   Operador: " << (*it).getOperador() << std::endl;
         printListPhrasesGeneral( (*it).m_Children );
    }
}




//ACTIONS
//CLEAR TODA LA ESTRUCTURA
void MainWindow::on_action_Clear_triggered()
{
    listPhrases.clear();
    listNFA.clear();

}



//EXIT THE PROGRAM
void MainWindow::on_action_Exit_triggered()
{
    close();
}

void MainWindow::on_action_About_triggered()
{
    QMessageBox::information(this,"Aviso","This Aplication is supported by La Pecera Loca , Amarillo=> estado Inicial, Verde=> estado aceptacion");
    return;
}



bool MainWindow::verifyPertenecia(std::string w){
    for(auto it = w.begin() ; it != w.end(); it++){
        std::string c(1,(*it));
        auto et = dfa.Alphabets.find(c );
        if(et != dfa.Alphabets.end()){ // find
            continue;
        }else{
            return false;
        }
    }
    return true;
}



//VERIFY
void MainWindow::on_btnVerifyAFND_clicked()
{
    //si es AFD
    std::string  input = this->ui->lineEditAFD->text().toStdString();
    //primero verificamos si la cadena esta vacia o no
    if(input.empty()){
        QMessageBox::information(this,"Aviso","Input vacia");
        return;
    }
    //segundo verificamos que todos los caracteres ingresados pertenecen al lenguaje
    if(!verifyPertenecia(input)){
        QMessageBox::information(this,"Aviso","Hay Caracteres que no pertenecen");
        return;
    }
    std::string IS = dfa.getInitialState();
    std::string temp="";
    for(auto it = input.begin() ; it != input.end(); it++){
        std::string c(1,(*it));
        std::string temp = dfa.M[IS][c];
        IS = temp;
    }
    //nos quedamos con IS en donde se guarda el ultimo estado
    // y l verificamos en la lista de  finalStates
    for(auto it = dfa.FinalStates.begin() ; it != dfa.FinalStates.end() ; it++){
        auto et = dfa.FinalStates.find(IS);
        if(et != dfa.FinalStates.end()){//found
            this->ui->lineEditRespuestaVerify->setText("True");
        }else{//not found
            this->ui->lineEditRespuestaVerify->setText("False");
        }
    }

}
