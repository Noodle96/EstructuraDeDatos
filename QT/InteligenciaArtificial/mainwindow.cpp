#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SWTree = new bst<std::string>();
    PPTree = new bst<Word>();
    this->ui->txtMasRepetidas->setEnabled(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete SWTree;
    delete PPTree;
}



void MainWindow::on_btnLoadFilePosition_clicked()
{
    std::fstream salida;
    std::string palabra;
    //sacar el numero de txtPosition
    int position = this->ui->txtPosition->text().toInt();
    //salida.open("/home/Nano/QT/InteligenciaArtificial/paper.txt", std::ios::in);
    if (filenameCurrent.empty()){
        QMessageBox::information(this,"Aviso","File Not Selected");
        return;
    }
    salida.open(filenameCurrent, std::ios::in);
    salida.seekg(position);
    salida >> palabra;
    salida.close();
    //mandarlo al txtWord
    palabra = quitarSignos(palabra);
    this->ui->txtWord->setText(palabra.c_str());

}

void MainWindow::on_btnGetFrecuency_clicked()
{
    QListWidgetItem *item = this->ui->listWidgetWords->currentItem();
    if(!this->ui->listWidgetWords->isItemSelected(item)){
        QMessageBox::information(this,"Aviso","Word Not Selected");
        return;
    }
    qDebug() << item->text();
    std::string word = item->text().toStdString();
    Word w;
    NodoBST<Word> **q;
    w.setWord(word);
    PPTree->findIDP(w,q); // son palabras que siempre las encuentrara
    int frec = (*q)->m_Dato.getFrecuency();
    //mandarle al txtGetFrecuency
    this->ui->txtGetFrecuency->setVisible(1);
    this->ui->txtGetFrecuency->setText(QString::number(frec));

}

void MainWindow::on_btnGetPosicion_clicked()
{
    QListWidgetItem *item = this->ui->listWidgetWords->currentItem();
    if(!this->ui->listWidgetWords->isItemSelected(item)){
        QMessageBox::information(this,"Aviso","Word Not Selected");
        return;
    }
    qDebug() << item->text();
    std::string word = item->text().toStdString(), salida;
    Word w;
    NodoBST<Word> **q;
    w.setWord(word);
    PPTree->findIDP(w,q); // son palabras que siempre las encuentrara
    salida = (*q)->m_Dato.getPosicionesSring();
    //mandarle al txtGetPosiciones
    this->ui->txtGetPositions->setVisible(1);
    this->ui->txtGetPositions->setText(salida.c_str());
}



/*
    ACTIONS
*/


void MainWindow::on_ActionOpenStopWords_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/home/Nano/QT/InteligenciaArtificial/", " Files (*.txt)");
    //QMessageBox::information(this,"filename del archivo seleccionado", filename); //All Files (*.*);; Music File(*.mp3)

    if( filename.toStdString().empty() ){
        QMessageBox::information(this,"Aviso"," File not Selected");
        return;
    }

    std::fstream sw;
    std::string w;
    int cont =0;
    //sw.open("/home/Nano/QT/InteligenciaArtificial/stopWords.txt", std::ios::in);
    sw.open(filename.toStdString(), std::ios::in);
    if (sw.good()){
        sw >> w;
        while(!sw.eof()){
            //std::cout << w << w.length()<< std::endl;
            SWTree->addIDP(w);
            sw >> w;
            cont++;
        }
        QMessageBox::information(this,"Aviso","File is opened Correctly !!!");
    }
    else{
        QMessageBox::information(this,"Aviso","File failed to open ");
    }
    sw.close();
    this->ui->ActionOpenPaper->setEnabled(1); // recien puedo abrir el paper.txt , porque primero es el stopWord y luego el paper.txt
    //std::cout << "Cantidad de Stop Words : " << cont << std::endl;
    //std::cout << " INFIJO: " << std::endl;
    //SWTree->printInfijo(SWTree->getHead());
}

void MainWindow::on_ActionOpenPaper_triggered()
{
     int cantPalabrasTotales = 0;
     QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/home/Nano/QT/InteligenciaArtificial/", "Files (*.txt)");
     if( filename.toStdString().empty() ){
         QMessageBox::information(this,"Aviso","File not Selected");
         return;
     }
     filenameCurrent = filename.toStdString();

    std::vector<std::string> stopWords;
    std::fstream pp;
    std::string word;
    int cont =0;
    //pp.open("/home/Nano/QT/InteligenciaArtificial/paper.txt", std::ios::in);
    pp.open(filename.toStdString(), std::ios::in);
    if(pp.good()){
        auto position = pp.tellg();
        Word WTemp;
        NodoBST<std::string> **q;
        NodoBST<Word> **qw;
        pp >> word;
        while(!pp.eof()){
            //std::cout << word << std::endl;
            //find in Stop Word Tree
            //toLowerStr(word);

            toLowerStr(word);
            //quitar de la palabras signos simples : example (IA)=> IA final.=>final  mangos,=>mangos [manos]=>manos
            word = quitarSignos(word);
            if(word.length() > 0){
                if( SWTree->findIDP(word,q) ){
                    //nothing to do
                    stopWords.push_back((*q)->m_Dato);
                }
                else{
                    WTemp.setWord(word);
                    if(  !PPTree->findIDP(WTemp,qw)  ){
                        //posicion
                        WTemp.pushear_posicion(position);
                        WTemp.setFrecuency(1);
                        PPTree->addIDP(WTemp);
                        cantPalabrasTotales++;
                        //std::cout << WTemp << std::endl;
                        this->ui->listWidgetWords->addItem(word.c_str());
                    }
                    else{
                        //posicion
                        (*qw)->m_Dato.pushear_posicion(position);
                        (*qw)->m_Dato.increaseFrecuency();
                    }
                }
            }
            position = pp.tellg();
            WTemp.resetVec();
            pp >> word;
            cont++;
            cantTotal = cantPalabrasTotales;
            this->ui->txtPalabrasTotales->setText(QString::number(cantPalabrasTotales));
        }
        QMessageBox::information(this,"Aviso","File is opened Correctly !!!!");
    }else{
         QMessageBox::information(this,"Aviso","File failed to open ");
    }
    pp.close();
   // std::cout << "Cantidad de Stop Words : " << cont << std::endl;

    //std::cout << " \n\nINFIJO SWTree: " << std::endl;
    //SWTree->printInfijo(   SWTree->getHead()   );

    std::cout << " \n\nINFIJO PPTree: " << std::endl;
    PPTree->printInfijo(   PPTree->getHead()   );


    //std::cout << "\n\nvector con stop Words" << std::endl;
    for(auto it = stopWords.begin()  ; it != stopWords.end()  ; it++){
     //   std::cout << (*it) << "  ";
    }
    std::cout << std::endl;
    this->ui->txtMasRepetidas->setEnabled(1);
}


void MainWindow::on_ActionSave_triggered()
{
    QMessageBox::information(this,"title","Save");
}

void MainWindow::on_ActionAboutAplication_triggered()
{
    QMessageBox::information(this,"title","This aplication is supported by Clash Royale");
}

void MainWindow::on_ActionExit_triggered()
{
    close();
    //QMessageBox::information(this,"title","Exit");
}







void MainWindow::on_btnGetMasRepetidas_clicked()
{
    this->ui->listWidgetN->clearFocus();
    if( this->ui->txtMasRepetidas->text().toStdString().empty() ){
        QMessageBox::information(this,"aviso","field empty");
        return;
    }
    int nMax = this->ui->txtMasRepetidas->text().toInt();

    Queue< NodoBST<Word>* > *treeQueue = new Queue< NodoBST<Word>* >();
    treeQueue->push(PPTree->getHead());
    while( !treeQueue->isEmpty() ){
        NodoBST<Word> *nodo = treeQueue->top();treeQueue->pop();

        //std::cout << nodo->m_Dato << ' ';
        visitar(nodo);

        if(nodo->m_pSon[0]) treeQueue->push(nodo->m_pSon[0]);
        if(nodo->m_pSon[1]) treeQueue->push(nodo->m_pSon[1]);
    }

    std::cout  << '\n';
    delete treeQueue;

    auto cont = 1;
    if(nMax > cantTotal){
        QMessageBox::information(this,"Aviso", "Excess");
        return;
    }else{
        for(auto it = rankeados.begin(); it != rankeados.end() && cont <=nMax ; it++  ){
            //std::cout << (*it)->m_Dato.getFrecuency() << std::endl;
            QString item = QString::number( (*it)->m_Dato.getFrecuency() );
            item += "   ";
            item += (*it)->m_Dato.getWord().c_str();
            this->ui->listWidgetN->addItem(item);cont++;
        }
    }
    this->ui->txtMasRepetidas->setEnabled(0);


}



//visitar Nodo
void MainWindow::visitar(NodoBST<Word> *l){
    //std::cout << l->m_Dato.getFrecuency() << std::endl;
    if(rankeados.empty()){
        rankeados.push_back(l);
        return;
    }
    auto it = rankeados.begin();
    for( ; it != rankeados.end() ; it++){
        if( (*it)->m_Dato.getFrecuency() <= l->m_Dato.getFrecuency() ){
            rankeados.insert(it,l);
            return;
        }
    }
    rankeados.push_back(l);return;

}
