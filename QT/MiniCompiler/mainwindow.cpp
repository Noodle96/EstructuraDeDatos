#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadFilePalabrasReservadas();
    loadFileOPeradoresSeparadores();
    this->ui->textEditLanguage->setAlignment(Qt::AlignLeft);
}

MainWindow::~MainWindow()
{

    delete ui;
}


// ///////////////////////////////////////////////PARTE DEL CONSTRUCTOR///////////////////////////////////////////////////////


//LEIENDO LOS OPERADORES Y SEPARADORES DEL ARCHIVO AL HASH
void MainWindow::loadFileOPeradoresSeparadores()
{
    std::fstream fileos;
    fileos.open("/home/Nano/QT/MiniCompiler/operadoresSeparadores.txt", std::ios::in);
    std::string w;
    while( getline(fileos, w) ){
        //std::cout << w << std:: endl;
        pSeparadoresOperadores.insert(std::make_pair(w,w));
    }
    fileos.close();
}



//LEIENDO LAS PALABRAS RESERVADAS DEL ARCHIVO AL HASH
void MainWindow::loadFilePalabrasReservadas()
{
    std::fstream filePReser;
    filePReser.open("/home/Nano/QT/MiniCompiler/palabrasReservadas.txt", std::ios::in);
    std::string w;
    while( getline(filePReser, w) ){
        //std::cout << w << std:: endl;
        pReservadas.insert(std::make_pair(w,w));
    }
    filePReser.close();
}


//COPIANDO DEL TEXTEDIT AL ARCHIVO TEXTLANAGUAGE PARA APLICARLO EL TOKENIZADOR
void MainWindow::saveTextEditIntxt(){
    QString path = "/home/Nano/QT/MiniCompiler/textLanguage.txt";
    QFile sfile(path);
    if(sfile.open(QFile::WriteOnly  | QFile::Text)){
        QTextStream out(&sfile);
        out << this->ui->textEditLanguage->toPlainText();
        sfile.flush();
        sfile.close();
    }
}


// /////////////////////////////////////////// END PARTE DEL CONSTRUCTOR///////////////////////////////////////////////////////



// //////////////////////////////////////////////////////////RUN//////////////////////////////////////////////////////////////


//BTN RUN
void MainWindow::on_btnRun_clicked()
{
    //paso 1 : guardar el texto en textLanguage.txt
    saveTextEditIntxt();

    //recorriendo las lineas y asignandoles su respectivo container
    int numLinea = 1;
    std::fstream salida;
    std::string temp;
    salida.open("/home/Nano/QT/MiniCompiler/textLanguage.txt",std::ios::in);
    while(getline(salida,temp)){
        //std::cout << temp << std::endl;
        visitarLLinea(temp,numLinea);
        numLinea++;
    }
    salida.close();
    std::cout << "SALIDA FINAL: " << std::endl;
    for(auto it = F.begin() ;it != F.end() ; it++){
        std::cout <<  (*it).getWord() << " " << (*it).getTipo()   << " " << (*it).getLinea() << std::endl;
    }

    std::cout << "Variables quedadas" << std::endl;
    for(auto it = Variables.begin() ; it != Variables.end() ; it++){
        std::cout <<  (*it).getWord() << " " << (*it).getTipo()   << " " << (*it).getLinea() << std::endl;
    }


    return;
}

// ////////////////////////////////////////////////////// END RUN//////////////////////////////////////////////////////////////








// ////////////////////////////////////////////////////// BEGIN FUNCTIONS//////////////////////////////////////////////////////////////

//formatea la palabra sin los tabs
std::string MainWindow::formatearSinEspacios(std::string w){
    std::string res="";
    for(auto it = w.begin() ;it != w.end() ; it++){
        if( (*it) != '\t' ){
            res += (*it);
        }
    }
    return res;
}



//AGREGA EN SU RESPECTIVO CONTAINER
void MainWindow::agregarInContainer(std::string  word, int linea){
    if( isNUmber(word) ) return;
    if( findInPReservadas(word,linea) ) return;
    if( findInOperadores(word,linea)) return;
    AddInVariables(word,linea);return;
}



//VISITAR LA LINEA
void MainWindow::visitarLLinea(std::string llinea, int numLinea){
    std::string word="";
    for(auto it = llinea.begin() ; it != llinea.end()  ; it++){
        if( (*it) != ' ' ){
            word+=(*it);
        }
        else{
            agregarInContainer(word,numLinea); // IN F
            word.clear();
        }
    }
    agregarInContainer(word,numLinea);
    word.clear();
}

// ////////////////////////////////////////////////////// END FUNCTIONS//////////////////////////////////////////////////////////////






// //////////////////////////////////////////////////////////FIND//////////////////////////////////////////////////////////////


// BUSCA LA PALABRA PASADA POR PARAMETRO EN EL CONTAINER ADECUADO
bool MainWindow::findInPReservadas(std::string w, int numLinea){
    if(w.empty())return false;
    //cout << "ANTES:"  << w;
    w = formatearSinEspacios(w);
    //cout << "DESPUES:" << w;
    auto it = pReservadas.find(w);
    if( it != pReservadas.end() ){ //found
        F.push_back( Word(w,"PReservada",numLinea) );
        return true;
    }
    return false;
}

// BUSCA LA PALABRA PASADA POR PARAMETRO EN EL CONTAINER ADECUADO : find in operaodores y separadores
bool MainWindow::findInOperadores(std::string w, int numLinea){
    if(w.empty())return false;
     w = formatearSinEspacios(w);
     auto it = pSeparadoresOperadores.find(w);
     if( it != pSeparadoresOperadores.end() ){ //found
         F.push_back( Word(w,"pSeparadorOperador",numLinea) );
         return true;
     }
     return false;
}

//verifica si la cadena es un  numero
bool MainWindow::isNUmber(std::string w){
    for(auto it = w.begin() ; it != w.end() ; it++){
        if( !isdigit( (*it) ) ){
            return false;
        }
    }
    return true;
}



//SE LE ASIGNA COMO VARIABLE
void MainWindow::AddInVariables(std::string w, int numLinea){
    if(w.empty())return;
    w = formatearSinEspacios(w);
    F.push_back( Word(w,"Variables", numLinea) );
    Variables.push_back(Word(w,"Variables", numLinea));

}


// //////////////////////////////////////////////////////////EDN FIND////////////////////////////////////////////////////////////
