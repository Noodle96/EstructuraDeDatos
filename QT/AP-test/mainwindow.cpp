#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    M = new std::map< std::string, std::map< std::string, std::string > >();
    estados = new std::list<std::string>();
    estadosAceptacion = new std::list<std::string>();
    alfabeto = new std::list<char>();
    alfabetoPila = new std::list<std::string>();
    pila = new std::stack<std::string>();
    llenarMatriz();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete estados;
    delete estadosAceptacion;
    delete alfabeto;
    delete alfabetoPila;
    delete pila;
    delete M;
}




void MainWindow::llenarMatriz(){
    //llenado de la matriz y los estados entre otros

    //LLENANDO LOS ESTADOS
    estados->push_back("s0");
    estados->push_back("s1");
    estados->push_back("s2");
    estados->push_back("s3");
    estados->push_back("s4");

    //LLENANDO LOS ESTADOS DE ACEPTACION
    estadosAceptacion->push_back("s4");
    estadoInicial = "s0";
    //@ representa el vacio
    //LLENANDO EL ALFABETO NORMAL
    alfabeto->push_back('@');
    alfabeto->push_back('x');
    alfabeto->push_back('y');


    //LLENANDO EL ALFABETO DE LA PILA
    //alfabetoPila->push_back("#");
    alfabetoPila->push_back("@");
    alfabetoPila->push_back("a");

    //EN EL LLENADO DE LA MATRIZ DE TRANSICION SE HARA LAS CONEXIONES

    //FORMANDO LOS LABELS "state/sacarPila/PonerPila"
    std::list<std::string> labels_columnas;
    std::string temp1 = "";
    std::string temp2 = "";
    std::string temp3 = "";
    for(auto it = alfabeto->begin() ;it != alfabeto->end() ; it++){
        temp1 = (*it);
        for(auto et = alfabetoPila->begin() ; et != alfabetoPila->end(); et++){
            temp2 = (*et);
            for(auto ot = alfabetoPila->begin() ; ot != alfabetoPila->end() ; ot++){
                temp3 = (*ot);
                labels_columnas.push_back(temp1 + temp2 + temp3);
            }
        }
    }
    //agregando el metodo para que la pila se quede vacia
    labels_columnas.push_back("@@#");
    labels_columnas.push_back("@#@");



    //imprimiendo la lista de labels
    for(auto it = labels_columnas.begin() ;  it != labels_columnas.end(); it++){
        std::cout << (*it) << " - ";
    }
    std::cout << "\n";



    t["s0"]["@@#"] = "s1";
    t["s1"]["x@a"] = "s1";
    t["s1"]["@@@"] = "s2";
    t["s2"]["y@@"]= "s3";
    t["s3"]["ya@"] = "s2";
    t["s2"]["@#@"] = "s4";



}







bool MainWindow::verificarPertenencia(std::string data){
    for(auto it = data.begin() ; it != data.end(); it++){
        auto itStr = std::find(alfabeto->begin() , alfabeto->end(),(*it));
        if( itStr != alfabeto->end()){//found
            continue;
        }else{//not found
            return 0;
        }

    }
    return true;
}







void MainWindow::on_btnVerificar_clicked()
{
    std::string data = this->ui->txtCadena->text().toStdString();
    if(data.empty()){
        QMessageBox::information(this,"Aviso","Cadena Vacia");
        return;
    }
    if(!verificarPertenencia(data)){
        QMessageBox::information(this,"Aviso","Hay alfabetos que no pertenecen al alfabeto");
        return;
    }
    //si entro hasta aqui es por que los alfabetos de la cadena mandada es correcta
    //std::cout << "puede ser" << std::endl;




    //imprimiendo el mapa completo
    for(auto it = t.begin()  ;it != t.end() ; it++){
        //std::cout << (*it).first  << " " << (*it).second<< std::endl;
        std::cout << (*it).first << " : " << std::endl;


        auto et = (*it).second.begin();
        for( ; et != (*it).second.end() ;  et++){
            std::cout << "\t" << (*et).first  << " " << (*et).second<< std::endl;
        }
        std::cout << "";
    }


    //funcion deltahat
    bool pertenece = deltaHat(estadoInicial,data);
    if(pertenece){
        QMessageBox::information(this, "Aviso","Si pertenece");
        return;
    }else{
        QMessageBox::information(this, "Aviso","No pertenece");
        return;
    }

}










//FUNCION DELTAHAT
bool MainWindow::
deltaHat(std::string Eot,std::string w){
    //esta pareja va a contener la frase y el estado a donde llega
    //M[s0][a@@] = s1;
    //test: frase : a@@
    //      llega : s1
    std::list< std::pair<std::string, std::string> > par;
    //par.push_back(std::make_pair("hola","hola"));


    auto itW = w.begin();
    //for(;itW != w.end(); itW++){
    while( itW != w.end() ){
        std::cout << "Estamos en " << (*itW) <<std::endl;


            for(auto it = t.begin() ;it != t.end() ; it++){//recorriendo el map completo
                if( (*it).first == Eot ){ //recorriendo los estados, hacia abajo
                    auto et = (*it).second.begin();
                    for( ; et != (*it).second.end() ;  et++){
                        par.push_back(std::make_pair((*et).first,(*et).second));
                    }
                }
                //else // nothig to do
            }



            //si par esta vacio significa que no hay para donde moverse lo que significa que dicha cadena no pertenece
            if(par.empty()){std::cout << "par esta vacio, por lo tanto no hay forma de moverse EN " << Eot << std::endl;return false;}

            //y cuando hay una sola pareja  =>  no nos fijamos en la pila y POR LO TANTO, sacamos y metemos nomas
            if(par.size() == 1){
                auto iterador = par.begin();
                if( (*iterador).first[0] == (*itW) ) {itW++;}//continuar = true

                //sacar de  la pila
                if( (*iterador).first[1] == '@'  ) {}
                else{
                    if( pila->top() == "#" )return false;
                    pila->pop();
                }


                //poner en la pila
                if( (*iterador).first[2] == '@'  ){}
                else{ std::string s(1,(*iterador).first[2]);  pila->push(s); }

                Eot = (*iterador).second;
                par.clear();
            }


            // y cuando hay varias parejas => tenemos que fijarnos en la pila
            if(par.size() > 1){
                std::list< std::pair<std::string, std::string> > pt; //par_temporal con los que coinciden con (*itW)
                std::list< std::pair<std::string, std::string> > pt_vacio; // par_temporal con los que no coinciden con (*itW)
                for(auto iterator = par.begin() ;iterator != par.end() ; iterator++){
                    if( (*iterator).first[0] == (*itW) ){
                        pt.push_back( std::make_pair( (*iterator).first, (*iterator).second ) );
                    }
                    else{
                        pt_vacio.push_back( std::make_pair( (*iterator).first, (*iterator).second ) );
                    }
                }
                par.clear();


                if(pt.size() > 0 ){
                    itW++; // avanza por que es igual al (*itW)
                    //Si hay elemento es pt, significa que hay tripletes que tienen en el first al (*itW), por lo tanto se ignora los vacios
                    pt_vacio.clear();

                    std::string topeTempPila = pila->top();
                    auto ptIt = pt.begin();
                    auto tripleteElegido = ptIt;
                    for(;  ptIt != pt.end(); ptIt++){
                        std::string s (1, (*ptIt).first[1] );
                        if ( s == topeTempPila ){
                            tripleteElegido = ptIt;
                            break;
                        }
                    }

                    //sacarPila
                    if( (*tripleteElegido).first[1] == '@'){}
                    else{
                        if( pila->top() == "#" )return false;
                        pila->pop();
                    }

                    //ponerPila
                    if( (*tripleteElegido).first[2] == '@' ){}
                    else{ std::string s (1, (*tripleteElegido).first[2] );pila->push(s);}

                    Eot = (*tripleteElegido).second;
                    pt.clear();

                }
                //si pasa aca, es porque en el first no tienen al (*itW)
                else{
                    for(auto it = pt_vacio.begin() ; it != pt_vacio.end() ; it++){ // habilitar este for cuando el automata va a varias direcciones con muchas @
                            if( (*it).first[0] == '@' ){ //buscamos un vacio
                                //sacamos en la pila
                                if((*it).first[1] == '@'){}//no saco nada
                                else{
                                    if( pila->top() == "#" )return false;
                                    pila->pop();
                                }

                                //ponemos en la pila
                                if( (*it).first[2] == '@' ){}//no pongo nada
                                else{std::string s(1,(*it).first[2]); pila->push(s);}
                                Eot = (*it).second;
                                break;
                            }
                        //}
                    }
                    //ahorra nos fijamos en la pila
               }
            }//end par.size() > 1
    }//w.end()


    std::cout << "fuera del while" << std::endl;
    ///////////////////////////////////////////////////////////////////////////////////////


    //ultimo ciclo cerrado
    for(auto it = t.begin() ;it != t.end() ; it++){//recorriendo el map completo
        if( (*it).first == Eot ){ //recorriendo los estados, hacia abajo
            auto et = (*it).second.begin();
            for( ; et != (*it).second.end() ;  et++){
                par.push_back(std::make_pair((*et).first,(*et).second));
            }
        }
        //else // nothig to do
    }
    std::cout << "fuera del par.push_back" << std::endl;
    for(auto itl = par.begin() ; itl != par.end() ; itl++){ // habilitar este for cuando el automata va a varias direcciones con muchas @
            if( (*itl).first[0] == '@' ){ //buscamos un vacio
                if(pila->top() == "#"){
                    //sacamos en la pila
                    if((*itl).first[1] == '@'){}//no saco nada
                    else{pila->pop();}

                    //ponemos en la pila
                    if( (*itl).first[2] == '@' ){}//no pongo nada
                    else{std::string s(1,(*itl).first[2]); pila->push(s);}
                    Eot = (*itl).second;
                }
                break;
            }
        //}
    }



    ///////////////////////////////////////////////////////////////////////////////////////

    std::cout << "pila final: " << std::endl;
    while(!pila->empty()){
        std::cout << pila->top() << std::endl;
        pila->pop();

    }

     //vaciando la pila al final
    while(!pila->empty() ){
        pila->pop();
    }


    std::cout << "estado final que quedo: " << Eot << std::endl;
    auto it = std::find( estadosAceptacion->begin() , estadosAceptacion->end() , Eot);
    if( it != estadosAceptacion->end()){ //found
       // QMessageBox::information(this,"Aviso","Si pertenece");
        return true;

    }else{//not found
        //QMessageBox::information(this,"Aviso","Ni pertenece");
        return false;
    }

}





void MainWindow::on_action_exit_triggered(){
    close();
}

void MainWindow::on_actionDot_triggered()
{
    //entrada << (*it) << " -> " << (*mt) << "[label=\" " << (*et) << "\" ];" << std::endl;
    std::fstream entrada;
    entrada.open("/home/Nano/QT/AP/archivo.dot", std::ios::out);
    entrada << "digraph A {" << std::endl;
    for(auto it = t.begin() ; it != t.end() ; it++){
        auto et = (*it).second.begin();
        for( ; et != (*it).second.end() ; et++){
            entrada << "\t" << (*it).first << "->" << (*et).second <<  "[label=\""<< (*et).first << "\"]; " <<  std::endl;
        }
    }
    entrada << "}" << std::endl;
    entrada.close();

    system("dot -Tpng /home/Nano/QT/AP/archivo.dot -o /home/Nano/QT/AP/archivo.png -Grankdir=LR");

    QPixmap pix("/home/Nano/QT/AP/archivo.png");
    int w = this->ui->labelNodo->width();
    int h = this->ui->labelNodo->height();
    this->ui->labelNodo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio  ));

    std::cout << w << "   "  << h << std::endl;
    //this->ui->labelNodo->setPixmap(pix);
    return;
}
