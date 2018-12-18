#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Iniciando la Maquina
    estados = new std::list<std::string>();
    alfabeto = new std::list<char>();
    estadosAceptacion = new std::list<std::string>();

    mModel = new QStandardItemModel(this);
    this->ui->tableViewTransiciones->setModel(mModel);


    // La MAQUINA (txt) siempre quedan read Only
    this->ui->txtEstados->setReadOnly(1);
    this->ui->txtAlfabetos->setReadOnly(1);
    this->ui->txtEstadosIniciales->setReadOnly(1);
    this->ui->txtEstadosAceptaciones->setReadOnly(1);


    // todos estos se enable(1) cuando empieza
    this->ui->txtEstado->setEnabled(0);
    this->ui->txtAlfabeto->setEnabled(0);
    this->ui->txtEstadoInicial->setEnabled(0);
    this->ui->txtEstadoAceptacion->setEnabled(0);

    this->ui->btnAddEstado->setEnabled(0);
    this->ui->btnAddAlfabeto->setEnabled(0);
    this->ui->btnAddEstadoInicial->setEnabled(0);
    this->ui->btnAddEstadoAceptacion->setEnabled(0);

    this->ui->okEstado->setEnabled(0);
    this->ui->okAlfabeto->setEnabled(0);
    this->ui->okEstadoInicial->setEnabled(0);
    this->ui->okEstadoAceptacion->setEnabled(0);


    this->ui->txtCadena->setEnabled(0);
    this->ui->btnVerificarCadena->setEnabled(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

//ACTIONS
//DOTED
void MainWindow::on_action_Dot_triggered()
{
    //QMessageBox::information(this,"Aviso","Doted");

    std::fstream entrada;

    entrada.open("/home/Nano/QT/AFND/archivo.dot", std::ios::out);
    entrada << "digraph A {" << std::endl;
     for(auto it = estados->begin() ; it != estados->end(); it++){
         for(auto et = alfabeto->begin() ; et != alfabeto->end(); et++){
             //temp = matriz[ getIndex((*it),estados)  ][getIndex( (*et),alfabeto )];
             //entrada << (*it) << " -> " << temp << "[label=\" " << (*et) << "\" ];" << std::endl;
             auto subt = Matriz[ getPositionEstado(*it) ][ getPositionAlfabeto(*et) ];
             auto mt = subt.begin();
             for( ;mt != subt.end() ; mt++){
                 entrada << (*it) << " -> " << (*mt) << "[label=\" " << (*et) << "\" ];" << std::endl;
             }

         }
    }
    entrada << "}" << std::endl;
    entrada.close();

    system("dot -Tpng /home/Nano/QT/AFND/archivo.dot -o /home/Nano/QT/AFND/archivo.png -Grankdir=LR");

    QPixmap pix("/home/Nano/QT/AFND/archivo.png");
    int w = this->ui->labelNodo->width();
    int h = this->ui->labelNodo->height();
    this->ui->labelNodo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio  ));
    return;

}

//INICIAR
void MainWindow::on_action_Iniciar_triggered()
{
    //QMessageBox::information(this,"Aviso","Iniciar Aplicacion");
    this->ui->txtEstado->setEnabled(1);
    this->ui->btnAddEstado->setEnabled(1);
    this->ui->okEstado->setEnabled(1);
}

//CLEAR
void MainWindow::on_action_Clear_triggered()
{
    QMessageBox::information(this,"Aviso","Clear");
}

//EXIT
void MainWindow::on_action_Exit_triggered()
{
    close();
}


//HELP
void MainWindow::on_action_Help_triggered()
{
    QMessageBox::information(this,"Aviso","This Aplication is supported by Team Queso");
}









//FUNTIONS

//ADD ESTADOS
void MainWindow::on_btnAddEstado_clicked()
{
    QString temp = this->ui->txtEstado->text();

    if( temp.isEmpty() ){
        QMessageBox::information(this,"Aviso","Estado Vacia");
        return;
    }


    //buscando si ya eata en la lista de estados
    std::list<std::string>::iterator itc;
    itc = std::find(estados->begin(), estados->end(), temp.toStdString() );
    if(itc != estados->end()){//found
        QMessageBox::information(this,"Aviso","Estado repetido");
        this->ui->txtEstado->setText("");//limpiado
        return;
    }


    else{//not found
        estados->push_back(temp.toStdString());
        this->ui->txtEstado->setText("");//limpiado


        //insertando automaticamente a la maquina
        QString cadena;
        auto it = estados->begin();
        for( ;  it != estados->end(); it++){
            cadena += (*it).c_str();
            cadena += " ";
        }
        this->ui->txtEstados->setText(cadena);
        return;
    }

}


//ADD ALFABETO
void MainWindow::on_btnAddAlfabeto_clicked()
{
    QString temp = this->ui->txtAlfabeto->text();

    if( temp.isEmpty() ){
        QMessageBox::information(this,"Aviso","Alfabeto Vacio");
        return;
    }
    if( temp.toStdString().size() > 1 ){
        QMessageBox::information(this,"Aviso","Alfabeto muy grande");
        this->ui->txtAlfabeto->setText("");//limpiado
        return;
    }


    //buscando si ya eata en la lista de estados
    std::list<char>::iterator itc;
    itc = std::find(alfabeto->begin(), alfabeto->end(), temp.toStdString()[0] );
    if(itc != alfabeto->end()){//found
        QMessageBox::information(this,"Aviso","Alfabeto repetido");
        this->ui->txtAlfabeto->setText("");//limpiado
        return;
    }

    else{//not found
        alfabeto->push_back(temp.toStdString()[0]);
        this->ui->txtAlfabeto->setText("");//limpiado


        //insertando automaticamente a la maquina
        QString cadena;
        auto it = alfabeto->begin();
        for( ;  it != alfabeto->end(); it++){
            cadena += QChar((*it));
            cadena += " ";
        }
        this->ui->txtAlfabetos->setText(cadena);
        return;
    }
}


//ADD ESTADO INICIAL
void MainWindow::on_btnAddEstadoInicial_clicked()
{
    QString temp = this->ui->txtEstadoInicial->text();
    if( temp.isEmpty() ){
        QMessageBox::information(this,"Aviso","Estado Inicial Vacio");
        return;
    }
    //buscando si es que Pertenece a los estados
    std::list<std::string>::iterator itc;
    itc = std::find(estados->begin(), estados->end(), temp.toStdString());
    if( itc != estados->end() ){ //found
        estadoInicial = temp.toStdString();
        this->ui->txtEstadoInicial->setText("");

        //disable "line -estado inicial"
        this->ui->txtEstadoInicial->setEnabled(0);
        this->ui->btnAddEstadoInicial->setEnabled(0);

        //enable "line eatado de aceptacion"
        this->ui->txtEstadoAceptacion->setEnabled(1);
        this->ui->btnAddEstadoAceptacion->setEnabled(1);
        this->ui->okEstadoAceptacion->setEnabled(1);

        // mostrando en la Maquina
        this->ui->txtEstadosIniciales->setText(temp);
        return;
    }
    else{ //not found
        QMessageBox::information(this,"Aviso","Estado Inicial no pertence a la Maquina");
        this->ui->txtEstadoInicial->setText("");
        return;
    }
}


//ADD ESTADOS DE ACEPTACION
void MainWindow::on_btnAddEstadoAceptacion_clicked()
{
    QString temp = this->ui->txtEstadoAceptacion->text();

    if( temp.isEmpty() ){
        QMessageBox::information(this,"Aviso","Estado de Aceptacion  Vacio");
        return;
    }
    std::list<std::string>::iterator itc;
    itc = std::find(estados->begin(), estados->end() , temp.toStdString() );
    if( itc != estados->end()){ //found
        estadosAceptacion->push_back(temp.toStdString());
        this->ui->txtEstadoAceptacion->setText("");
        //insertando automaticamente a la maquina
        QString cadena;
        auto it = estadosAceptacion->begin();
        for( ;  it != estadosAceptacion->end(); it++){
            cadena += (*it).c_str();
            cadena += " ";
        }
        this->ui->txtEstadosAceptaciones->setText(cadena);
        return;

    }
    else{ // not found
        QMessageBox::information(this,"Aviso","Estado de Aceptacion  no pertenece a la maquina");
        this->ui->txtEstadoAceptacion->setText("");
        return;
    }
}



//OKEY'S
//OKEY ADD ESTADO
void MainWindow::on_okEstado_clicked()
{
    if(estados->empty()){
        QMessageBox::information(this,"Aviso","Ningun Estado en la Maquina");
        return;
    }
    //disable "line-estado"
    this->ui->txtEstado->setEnabled(0);
    this->ui->btnAddEstado->setEnabled(0);
    this->ui->okEstado->setEnabled(0);

    //enable "line-alfabeto"
    this->ui->txtAlfabeto->setEnabled(1);
    this->ui->btnAddAlfabeto->setEnabled(1);
    this->ui->okAlfabeto->setEnabled(1);
    return;
}


//OKEY ADD ALFABETO
void MainWindow::on_okAlfabeto_clicked()
{
    if(alfabeto->empty()){
        QMessageBox::information(this,"Aviso","Ningun Alfabeto en la Maquina");
        return;
    }
    //disable "line-alfabeto"
    this->ui->txtAlfabeto->setEnabled(0);
    this->ui->btnAddAlfabeto->setEnabled(0);
    this->ui->okAlfabeto->setEnabled(0);

    //enable "line-estado Inicial"
    this->ui->txtEstadoInicial->setEnabled(1);
    this->ui->btnAddEstadoInicial->setEnabled(1);
    return;

}

//OKEY ESTADO ADD ESTADO INICIAL
void MainWindow::on_okEstadoInicial_clicked()
{
    //nothing to do
}


//OKEY ADD ESTADO DE ACEPTACION
void MainWindow::on_okEstadoAceptacion_clicked()
{
    if(estadosAceptacion->empty()){
        QMessageBox::information(this,"Aviso","Estados de Aceptacione vacio");
        return;
    }
    //disable "line- estados aceptaciones"
    this->ui->txtEstadoAceptacion->setEnabled(0);
    this->ui->btnAddEstadoAceptacion->setEnabled(0);
    this->ui->okEstadoAceptacion->setEnabled(0);
    return;
}



//LLENAR TRANSICIONES
void MainWindow::on_btnLlenarTransiciones_clicked()
{

    mModel->setRowCount(estados->size()); // estados->size()
    mModel->setColumnCount(alfabeto->size()); // alfabeto->size()

    QStringList labelsEstados;
    QStringList labelsAlfabeto;


    auto it = estados->begin();
    for( ;it != estados->end() ;it++){
        labelsEstados << (*it).c_str();
    }
    auto et = alfabeto->begin();
    for( ;et != alfabeto->end() ; et++){
        labelsAlfabeto << QChar((*et));
    }

    //labelsAlfabeto << "Atest" <<"Btest";
    //labelsEstados << "a1"  << "a2" << "a3" << "a4" << "a5";
    //std::cout << "despues 3" << std::endl;
    mModel->setHorizontalHeaderLabels(labelsAlfabeto);
    mModel->setVerticalHeaderLabels(labelsEstados);
    return;
}


//GETVALUE
QString MainWindow::getValueAl(int ix,int jx){
    if(!mModel->item(ix,jx)){
        std::cout << "!mModel->item(ix,jx) ("  <<ix << " , " << jx << " )" << std::endl;
        return "";
    }
    return mModel->item(ix,jx)->text();
}


//TRANSFORMAR UN STRING A UNA LIST
void MainWindow::transformToList(std::string w,std::vector<std::string> &lista){
    if(w.empty()){
        return;
    }
    auto it = w.begin();
    std::list< std::string >::iterator et;
    std::string part = "";
    for( ; it != w.end()  ; it++){
        if( (*it) != ' ' ){
            part += (*it);
        }
        else{
            et = std::find(estados->begin(), estados->end(),part);
            if (et != estados->end()){ //found
                lista.push_back(part);
                part.clear();
                part = "";
            }
            else{ //not found
                QMessageBox::information(this,"Aviso","Hay Estados que no pertenecen a la Maquina");
                part.clear();
                part = "";
            }

        }
    }
    et = std::find(estados->begin(), estados->end(),part);
    if (et != estados->end()){ //found
        lista.push_back(part);
        part.clear();
        part = "";
    }
    else{ //not found
        QMessageBox::information(this,"Aviso","Hay Estados que no pertenecen a la Maquina");
        part.clear();
        part = "";
    }

}


//LLENAR LA MATRIZ DE LA INTERFAZ
void MainWindow::on_btnOkeyLlenadoTransiciones_clicked()
{
    QString temp;
    Matriz.clear();
    std::vector<std::string> v0;
    std::vector< std::vector< std::string > > v1;
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    std::list<std::string>::iterator itc;
    qDebug() << rowCount << endl;
    qDebug() << colCount << endl;



    for( int e = 0 ; e < rowCount ;e++){
        for(int j = 0 ; j < colCount ; j++){
            temp = getValueAl(e,j);
            transformToList(temp.toStdString(),v0);
            v1.push_back(v0);
            v0.clear();
        }
        Matriz.push_back(v1);
        v1.clear();
    }

    //QMessageBox::information(this,"Aviso","TABLA DE TRANSICIONES CORRECTAMENTE!!");
    //this->ui->tableViewTransiciones->setEnabled(0);
    this->ui->btnLlenarTransiciones->setEnabled(0);
    //this->ui->btnFormarTransiciones->setEnabled(0);

    //habilitando el verificar palabra
    this->ui->txtCadena->setEnabled(1);
    this->ui->btnVerificarCadena->setEnabled(1);


    for( int e = 0 ; e < rowCount ;e++){
        for(int j = 0 ; j < colCount ; j++){
            auto it = Matriz[e][j].begin();
            for( ; it !=  Matriz[e][j].end() ;it++){
                std::cout << (*it) << "*";
            }
            std::cout << "--";
        }
        std::cout << std::endl;
    }

    //mModel->setHorizontalHeaderItem(1,new QStandardItem(" w x y z"));
   // mModel->setItem(0,0, new QStandardItem("Hola"));

}

//GETINDEX : DEVUELVE LA POSICION EN DONDE ESTA DICHA ESTADO P ALFABETO
int MainWindow::getPositionEstado(std::string w){
    int pos = 0;
    for(auto it = estados->begin(); it != estados->end(); it++){
        if((*it) == w)return pos;
        pos++;
    }
    return pos;

}

int MainWindow::getPositionAlfabeto(char c){
    int pos = 0;
    for ( auto it = alfabeto->begin() ; it != alfabeto->end() ; it++){
        if ( (*it) == c ) return pos;
        pos++;
    }
    return pos;
}


//VERIFICA SI LA CADENA  DE ENTRADA PARA VERIFICAR ESTA CON EL ALFABETO CORRECTO
bool MainWindow::verificarPertenencia(std::string w){
    auto it = w.begin();
    std::list<char>::iterator et;
    for ( ;  it != w.end() ;it++){
        et = std::find(alfabeto->begin(), alfabeto->end(),(*it));
        if(et != alfabeto->end()){//found
            continue;
        }else{ //not found
            return false;
        }
    }
    return  true;
}

void MainWindow::deltaHat(std::list< std::string >&T, std::string w){
    std::list< std::string > F;
    std::vector< std::string > inside;
    //recorrer la cadena w
    for( auto it = w.begin() ;  it != w .end(); it++ ){


        //recorrer lo estados origenes por la cadena (*it)
        for( auto et = T.begin() ;  et != T.end();  et++){
            inside = Matriz[ getPositionEstado(*et)    ][ getPositionAlfabeto(*it) ];

            //recorremos Matriz[][](lista)
            for( auto j = inside.begin() ;j != inside.end() ; j++ ){
                F.push_back(*j);
            }

        }
        T = F; F.clear();
    }
}


//VERIFICAR CADENA
void MainWindow::on_btnVerificarCadena_clicked()
{
    //Asumiendo por el momento que los alfabetos son de un caracter => 1,0,a,b,etc
    std::string cadena = this->ui->txtCadena->text().toStdString();
    if( !verificarPertenencia(cadena) ){
        QMessageBox::information(this,"Aviso","La Cadena no reconoce la Máquina");
        return;
    }

    //std::cout << "getPosition: " << getPositionEstado("s1") << std::endl ;
    //std::cout << "getPosition: " << getPositionAlfabeto('a') << std::endl ;
    //std::cout << "getPosition: " << getPositionAlfabeto('b') << std::endl ;

    std::list< std::string > T;
    T.push_back(estadoInicial);
    deltaHat(T,cadena);

    //imprimir EFR
    std::cout << "Estados Finales Resultante(EFR)" << std::endl;
    for(auto it = T.begin() ; it != T.end();it++){
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;



    /*
        Aceptara de la cadena si :
            la interseccion de EFR con los estados de aceptacion sea nulo, es decir:
            al menos hay un elemento en comun entre EFR y los estados de aceptacion

    */
    if(  interseccion(T)  ){
        QMessageBox::information(this,"Aviso","Esta cadena SI pertenece a la maquina");
        return;
    }else{
        QMessageBox::information(this,"Aviso","Esta cadena NO pertenece a la maquina");
        return;
    }


}

//INTERSECCION
bool MainWindow::interseccion(std::list< std::string > &T){
    for(auto it = T.begin() ; it != T.end() ;it++){
        for(auto et = estadosAceptacion->begin() ;et != estadosAceptacion->end() ; et++) {
            if((*it) == (*et))return true;
        }
    }
    return false;
}
