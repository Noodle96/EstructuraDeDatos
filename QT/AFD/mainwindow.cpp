#include<QStandardItemModel>
#include<QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    estados = new std::vector<char>();
    alfabeto =  new std::vector<char>();
    estadosAceptacion = new std::vector<char>();

    mModel = new QStandardItemModel(this);
    this->ui->tableViewTransiciones->setModel(mModel);

     //disable  => alfabeto,estadoInicial,Estados de aceptacion
    this->ui->txtEstado->setEnabled(0);
    this->ui->txtAlfabeto->setEnabled(0);
    this->ui->txtEstadoInicial->setEnabled(0);
    this->ui->txtEstadoAceptacion->setEnabled(0);

    this->ui->btnAddEstado->setEnabled(0);
    this->ui->btnAddAlfabeto->setEnabled(0);
    this->ui->btnAddEstadoInicial->setEnabled(0);
    this->ui->btnAddEstadoAceptacion->setEnabled(0);

    this->ui->btnLlenartransiciones->setEnabled(0);
    this->ui->btnVerificar->setEnabled(0);


    //okey
    this->ui->ok1->setEnabled(0);
    this->ui->ok2->setEnabled(0);
    this->ui->ok3->setEnabled(0);
    this->ui->ok4->setEnabled(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//LLENANDO LAS TRANSICIONES
void MainWindow::on_btnLlenartransiciones_clicked()
{
    mModel->setRowCount(estados->size()); // estados->size()
    mModel->setColumnCount(alfabeto->size()); // alfabeto->size()
   QStringList labelsEstados;
   QStringList labelsAlfabeto;
   //test << "los" << "monos" << "axules";
   auto it = estados->begin();
   for( ;it != estados->end() ;it++){
       labelsEstados << ( QChar(*it) );
   }
   auto et = alfabeto->begin();
   for( ;et != alfabeto->end() ; et++){
       labelsAlfabeto << QChar(*et);
   }
    mModel->setHorizontalHeaderLabels(labelsAlfabeto);
    mModel->setVerticalHeaderLabels(labelsEstados);

}





//impUT
//BTN ADD ESTADO
void MainWindow::on_btnAddEstado_clicked()
{   temp.clear();
    temp = this->ui->txtEstado->text().toStdString();
    if(temp.empty()){
        QMessageBox::information(this,"Aviso","cadena Vacia");
        return;
    }
    if( temp.size()>1){
        QMessageBox::information(this,"Aviso","Permitido solo un caracter");
        this->ui->txtEstado->setText("");//limpiado
        return;
    }
    //buscando si ya eata en la lista de estados
    std::vector<char>::iterator itc;
    itc = std::find(estados->begin(), estados->end(), temp[0]);
    if(itc != estados->end()){//found
        QMessageBox::information(this,"Aviso","Elemento repetido");
        this->ui->txtEstado->setText("");//limpiado
        return;
    }
    else{//not found
        estados->push_back(temp[0]);
        this->ui->txtEstado->setText("");//limpiado

        QString cadena;
        auto it = estados->begin();
        for( ;  it != estados->end(); it++){
            cadena += QChar(*it);
            cadena += " ";
        }
        this->ui->txtEstados->setText(cadena);
        return;
    }
}



//BRN ADD  ALFABETO
void MainWindow::on_btnAddAlfabeto_clicked()
{
     temp.clear();
     temp = this->ui->txtAlfabeto->text().toStdString();
     if(temp.empty()){
         QMessageBox::information(this,"Aviso","cadena Vacia");
         return;
     }
     if( temp.size()>1){
         QMessageBox::information(this,"Aviso","Permitido solo un caracter");
          this->ui->txtAlfabeto->setText("");//limpiado
         return;
     }
     //buscando si ya eata en la lista de estados
     std::vector<char>::iterator itc;
     itc = std::find(alfabeto->begin(), alfabeto->end(), temp[0]);
     if(itc != alfabeto->end()){//found
         QMessageBox::information(this,"Aviso","Elemento repetido");
         this->ui->txtAlfabeto->setText("");//limpiado
         return;
     }
     else{//not found
         alfabeto->push_back(temp[0]);
         this->ui->txtAlfabeto->setText("");//limpiado

         QString cadena;
         auto it = alfabeto->begin();
         for( ;  it != alfabeto->end(); it++){
             cadena += QChar(*it);
             cadena += " ";
         }
         this->ui->txtAlfabetos->setText(cadena);
         return;
     }
}




//BTN ADD ESTADO INICIAL
void MainWindow::on_btnAddEstadoInicial_clicked()
{
    temp.clear();
    temp = this->ui->txtEstadoInicial->text().toStdString();
    if(temp.empty()){
        QMessageBox::information(this,"Aviso","cadena Vacia");
        return;
    }
    if( temp.size()>1){
        QMessageBox::information(this,"Aviso","Permitido solo un caracter");
         this->ui->txtEstadoInicial->setText("");//limpiado
        return;
    }
    std::vector<char>::iterator itc;
    itc = std::find(estados->begin(), estados->end(), temp[0]);
    if(itc != estados->end()){//found
        EstadoInicial = temp[0];
        this->ui->txtEstadoInicial->setText("");
        this->ui->txtEstadoInicial2->setText(QChar(temp[0]));

        //bloquenado la fila de el estado Inicial y habilitando el de aceptacion
        on_ok3_clicked();
        return;
    }else{//not found
        QMessageBox::information(this,"Aviso","No Pertenece a los estados ");
         this->ui->txtEstadoInicial->setText("");
        return;
    }


}


//BTN ADD ESTADO DE ACEPTACION
void MainWindow::on_btnAddEstadoAceptacion_clicked()
{
    temp.clear();
    temp = this->ui->txtEstadoAceptacion->text().toStdString();
    if(temp.empty()){
        QMessageBox::information(this,"Aviso","cadena Vacia");
        return;
    }
    if( temp.size()>1){
        QMessageBox::information(this,"Aviso","Permitido solo un caracter");
         this->ui->txtEstadoAceptacion->setText("");//limpiado
        return;
    }
    std::vector<char>::iterator itc;
    itc = std::find(estados->begin(), estados->end(), temp[0]);
    if(itc != estados->end()){//found in Estados
        itc = std::find(estadosAceptacion->begin(), estadosAceptacion->end(), temp[0]);
        if(itc != estadosAceptacion->end()){//found en estadosAceptacion
            QMessageBox::information(this,"Aviso","Repetido");
            this->ui->txtEstadoAceptacion->setText("");
            return;
        }
        else{//not found in estadosAceptacion
            estadosAceptacion->push_back(temp[0]);
            this->ui->txtEstadoAceptacion->setText("");
            QString cadena;
            auto it = estadosAceptacion->begin();
            for( ;  it != estadosAceptacion->end(); it++){
                cadena += QChar(*it);
                cadena += " ";
            }
            this->ui->txtEstadosAceptaciones->setText(cadena);
            return;
        }
    }else{//not found in estados
        QMessageBox::information(this,"Aviso","No Pertenece a los estados ");
         this->ui->txtEstadoAceptacion->setText("");
        return;
    }
}




//ACTION
void MainWindow::on_actionIniciar_triggered()
{
    this->ui->txtEstado->setEnabled(1);
    this->ui->btnAddEstado->setEnabled(1);
    this->ui->ok1->setEnabled(1);
    return;

}

void MainWindow::on_action_Clear_triggered()
{
    //clear
}

void MainWindow::on_action_Exit_triggered()
{
    close();
}













//okey
void MainWindow::on_ok1_clicked()
{
    if(estados->empty()){
        QMessageBox::information(this,"Aviso","No perimitido estado vacio");
        return;
    }
    this->ui->txtAlfabeto->setEnabled(1);
    this->ui->btnAddAlfabeto->setEnabled(1);
    this->ui->ok2->setEnabled(1);

    //bloqueamos todo los estados
    this->ui->txtEstado->setEnabled(0);
    this->ui->btnAddEstado->setEnabled(0);
    this->ui->ok1->setEnabled(0);
}

void MainWindow::on_ok2_clicked()
{
    if(alfabeto->empty()){
        QMessageBox::information(this,"Aviso","No perimitido alfabeto vacio");
        return;
    }
    //posterior
    this->ui->txtEstadoInicial->setEnabled(1);
    this->ui->btnAddEstadoInicial->setEnabled(1);
    this->ui->ok3->setEnabled(0);

    //current
    this->ui->txtAlfabeto->setEnabled(0);
    this->ui->btnAddAlfabeto->setEnabled(0);
    this->ui->ok2->setEnabled(0);
}

void MainWindow::on_ok3_clicked()
{

    //current
    this->ui->txtEstadoInicial->setEnabled(0);
    this->ui->btnAddEstadoInicial->setEnabled(0);

    //posterior
    this->ui->txtEstadoAceptacion->setEnabled(1);
    this->ui->btnAddEstadoAceptacion->setEnabled(1);
    this->ui->ok4->setEnabled(1);

}

void MainWindow::on_ok4_clicked()
{
    //current
    this->ui->txtEstadoAceptacion->setEnabled(0);
    this->ui->btnAddEstadoAceptacion->setEnabled(0);
    this->ui->ok4->setEnabled(0);

    //Posterior
    this->ui->btnLlenartransiciones->setEnabled(1);
}




void MainWindow::on_btnFormarTransiciones_clicked()
{
    temp.clear();
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    std::vector<char> v1;
    std::vector<char>::iterator itc;

    for( int e = 0 ; e < rowCount ;e++){
        for(int j = 0 ; j < colCount ; j++){
            temp = getValueAl(e,j).toStdString();
            if(temp.empty()){
                QMessageBox::information(this,"Aviso","alguna posicion vacia");
                return;
            }
            if( temp.size()>1){
                QMessageBox::information(this,"Aviso","Permitido solo un caracter");
                 this->ui->txtEstadoAceptacion->setText("");//limpiado
                return;
            }
            itc = std::find(estados->begin(), estados->end(), temp[0]);
            if(itc != estados->end()){//found
                v1.push_back(temp[0]);
            }
            else{ //not found
                QMessageBox::information(this,"Aviso","Estado no encontrado");
                return;
            }

        }
        matriz.push_back(v1);
        v1.clear();
    }
    QMessageBox::information(this,"Aviso","TABLA DE TRANSICIONES CORRECTAMENTE!!");
    this->ui->tableViewTransiciones->setEnabled(0);

    //enabled(0) => llenar trans, formar trans
    this->ui->btnLlenartransiciones->setEnabled(0);
    this->ui->btnFormarTransiciones->setEnabled(0);

    //habilitando el verificar palabra
    this->ui->btnVerificar->setEnabled(1);


    for( int e = 0 ; e < rowCount ;e++){
        for(int j = 0 ; j < colCount ; j++){
            std::cout << matriz[e][j] << " ";
        }
        std::cout << std::endl;
    }

}


QString MainWindow::getValueAl(int ix,int jx){
    if(!mModel->item(ix,jx)){
        return "";
    }
    return mModel->item(ix,jx)->text();
}





//verificacion de la palabra
void MainWindow::on_btnVerificar_clicked()
{
    std::string palabra = this->ui->txtCadena->text().toStdString();
    std::vector<char>::iterator itc;
    auto et = palabra.begin();
    for( ; et != palabra.end(); et++){
        itc = std::find(alfabeto->begin(), alfabeto->end(), (*et));
        if(itc != alfabeto->end()){//found
            continue;
        }else{//not found
             QMessageBox::information(this,"Aviso","Existen estados que no pertenecen al conjunto de estados");
             return;
        }
    }
    //SI SALE DE ESTE CICLO ES PORQUE LA CADENA TIENEN LOS alfabetos de la maquina
    //funcion delta hat
    deltaHat(EstadoInicial,palabra);

}



void MainWindow::deltaHat(char q,std::string w){
    auto it = w.begin();
    char process;
    for( ; it != w.end() ; it++){
        process = matriz[   getIndex(q,estados) ][  getIndex((*it),alfabeto)  ];
        q = process;
    }

    std::vector<char>::iterator itc;
    itc = std::find(estadosAceptacion->begin() , estadosAceptacion->end(),process);
    if( itc != estadosAceptacion->end()){//found
        QMessageBox::information(this,"Aviso","Esta Cadena si pertenece a la Máquina");
        return;
    }else{
         QMessageBox::information(this,"Aviso","Esta Cadena No pertenece a la Máquina");
         return;
    }
}


void MainWindow::on_actionDot_triggered()
{
   std::fstream entrada;
   char temp;
   entrada.open("/home/Nano/QT/AFD/archivo.dot", std::ios::out);
   entrada << "digraph A {" << std::endl;
    for(auto it = estados->begin() ; it != estados->end(); it++){
        for(auto et = alfabeto->begin() ; et != alfabeto->end(); et++){
            temp = matriz[ getIndex((*it),estados)  ][getIndex( (*et),alfabeto )];
            entrada << (*it) << " -> " << temp << "[label=\" " << (*et) << "\" ];" << std::endl;
        }
   }
   entrada << "}" << std::endl;
   entrada.close();
   system("dot -Tpng /home/Nano/QT/AFD/archivo.dot -o /home/Nano/QT/AFD/archivo.png -Grankdir=LR");
   DialogDot *ventana = new DialogDot(this);
   ventana->setModal(true);
   ventana->show();


}































//end mainwindow.cpp
