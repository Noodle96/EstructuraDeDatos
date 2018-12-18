#include "mainwindow.h"
#include "ui_mainwindow.h"


//CONSTRUCTOR
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //INICIALIZANDO SET AND WORD AND HASH
    setWord = new std::set<Word>();
    listWord = new std::list<Word>();
    un_m = new std::unordered_map<std::string, Word>();
                               //<Key,Objeto,hash,pred,alloc>()

    setWord->clear();
    listWord->clear();
    un_m->clear();

    /*
    ui->txtWithList->setEnabled(0);
    ui->txtWithHash->setEnabled(0);
    ui->txtWithSet->setEnabled(0);
    ui->txtTimeList->setEnabled(0);
    ui->txtTimeHash->setEnabled(0);
    ui->txtTimeSet->setEnabled(0);
    */
}




//DESTRUCTOR
MainWindow::~MainWindow()
{
    delete ui;
    delete setWord;
    delete listWord;
}


//ESTA FUNCION LEE LA LLINEA Y ASIGNA A ING LA PALABRA EN INGLES Y A ESP LA PALABRA EN ESPAÑOL
void MainWindow::VisitarLline(std::string lline, std::string &ing, std::string &esp){
    auto it = lline.begin();
    for(; it != lline.end(); it++){
        if( (*it) != '#' ) ing+=(*it);
        else break;
    }
    it++;
    for( ; it != lline.end() ; it++){
        esp += (*it);
    }
}




//ACTION LOAD LIST
void MainWindow::on_actionload_in_List_triggered()
{
    //LIMPIEZA
    listWord->clear();
    this->ui->txtWithList->setText("");
    this->ui->txtTimeList->setText("");



    this->ui->labelMessageList->setText("");
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/home/Nano/QT/TimeDataStructure/", " Files (*.txt)");
    //QMessageBox::information(this,"filename del archivo seleccionado", filename); //All Files (*.*);; Music File(*.mp3)

    if( filename.toStdString().empty() ){
        QMessageBox::information(this,"Aviso"," File not Selected");
        return;
    }

    std::fstream dic;
    std::string ing="",esp="";
    std::string lline;

    dic.open(filename.toStdString(), std::ios::in);
    if (dic.good()){
        while( getline(dic,lline) ){
            //std::cout << lline << std::endl;
            VisitarLline(lline,ing,esp);
            //std::cout << ing << ":" << esp << std::endl;

            //auto it = std::find( listWord->begin() , listWord->end(), Word(ing) );

            //if(it != listWord->end() ){ //found
              //  (*it).concatenarWord(esp);
            //}else{//not found
                listWord->push_back( Word(ing,esp) );
            //}
            ing.clear(); esp.clear();lline.clear();
        }
        QMessageBox::information(this,"Aviso","File is opened Correctly !!!");
    }
    else{
        QMessageBox::information(this,"Aviso","File failed to open ");
    }
    dic.close();

    //IMPRIMIENDO LA LISTA EN UN ARCHIVO[TEST]

    //std::fstream entradaResult;
    //entradaResult.open("/home/Nano/QT/TimeDataStructure/resultDiccionary.txt",std::ios::out);
    /*
    for(auto it = listWord->begin() ; it != listWord->end() ; it++){
        std::cout << (*it).getWordIng() << "#" << (*it).getWordEsp() << std::endl ;
        //entradaResult << (*it).getWordIng() << "#" << (*it).getWordEsp() << std::endl;
    }
    */
}








//ACTION LOAD HASH
void MainWindow::on_actionload_in_Hash_triggered()
{
    //LIMPIEZA
    un_m->clear();
    this->ui->txtWithHash->setText("");
    this->ui->txtTimeHash->setText("");



    this->ui->labelMessageHash->setText("");
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/home/Nano/QT/TimeDataStructure/", " Files (*.txt)");
    //QMessageBox::information(this,"filename del archivo seleccionado", filename); //All Files (*.*);; Music File(*.mp3)

    if( filename.toStdString().empty() ){
        QMessageBox::information(this,"Aviso"," File not Selected");
        return;
    }
    std::fstream dic;
    std::string ing="",esp="";
    std::string lline;

    dic.open(filename.toStdString(), std::ios::in);
    if (dic.good()){
        while( getline(dic,lline) ){
            //std::cout << lline << std::endl;
            VisitarLline(lline,ing,esp);
            //std::cout << ing << ":" << esp << std::endl;
            un_m->insert(std::make_pair(ing,Word(ing,esp)));
            ing.clear(); esp.clear();lline.clear();
        }
        QMessageBox::information(this,"Aviso","File is opened Correctly !!!");
    }
    else{
        QMessageBox::information(this,"Aviso","File failed to open ");
    }
    dic.close();

    //IMPRIMIENDO LA TABLA HASH
    size_t  n = un_m->bucket_count();
    std::cout << "un_m has " << n << " buckets.\n";

    for (unsigned i=0; i<n; ++i) {
        std::cout << "bucket #" << i << " contains: ";
        for (auto it = un_m->begin(i); it!=un_m->end(i); ++it)
            std::cout << it->first << ":" << it->second.getWordEsp() << "  ";
        std::cout << "\n";
    }

    //SACANDO VALORES
    //std::cout << "SACANDO VALORES: " << std::endl;
    //std::cout << (*un_m)["dog"] << std::endl;

}


//ACTION LOAD SET
void MainWindow::on_actionload_in_Set_triggered()
{
    //LIMPIEZA
    setWord->clear();
    this->ui->txtWithSet->setText("");
    this->ui->txtTimeSet->setText("");



    this->ui->labelMessageSet->setText("");
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/home/Nano/QT/TimeDataStructure/", " Files (*.txt)");
    //QMessageBox::information(this,"filename del archivo seleccionado", filename); //All Files (*.*);; Music File(*.mp3)

    if( filename.toStdString().empty() ){
        QMessageBox::information(this,"Aviso"," File not Selected");
        return;
    }


    std::fstream dic;
    std::string ing="",esp="";
    std::string lline;

    dic.open(filename.toStdString(), std::ios::in);
    if (dic.good()){
        while( getline(dic,lline) ){
            //std::cout << lline << std::endl;
            VisitarLline(lline,ing,esp);
            //std::cout << ing << ":" << esp << std::endl;
            setWord->insert( Word(ing,esp) );
            ing.clear(); esp.clear();lline.clear();
        }
        QMessageBox::information(this,"Aviso","File is opened Correctly !!!");
    }
    else{
        QMessageBox::information(this,"Aviso","File failed to open ");
    }
    dic.close();

    //IMPRIMIENDO LA LISTA
    /*
    for(auto it = setWord->begin() ; it != setWord->end() ; it++){
        std::cout << (*it);
    }
    */
}






//ACTION EXIT
void MainWindow::on_action_Exit_triggered()
{
    close();
}




//ACTION  ABOUT
void MainWindow::on_action_About_triggered()
{
    QMessageBox::information(this, "Aviso","This Aplication is suported by Clash Royale Team Queso");
    return;
}


//BUTTON TRADUCIR
void MainWindow::on_btnTraducir_clicked()
{
    clock_t t0, t1;
    //VERIFCANDO QUE EL TXTWORD NO ESTE VACIA
    std::string wordIngles = this->ui->txtWord->text().toStdString();
    if( wordIngles.empty() ){
        QMessageBox::information(this, "Aviso","Word Vacia");
        return;
    }
    this->ui->txtWord->setText("");
    this->ui->labelMessageList->setText("");

    //TRADUCIENDO LIST
    if(listWord->empty()){
        this->ui->labelMessageList->setText("Not Loaded Structure");
    }else{
        t0=clock();
        // Code to execute
        auto it = std::find(listWord->begin() , listWord->end(), Word(wordIngles));
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        //std::cout << "Execution Time: " << time << std::endl;
        //printf("%.16g milisegundos\n", time * 1000.0);
        if(it != listWord->end()){//found
            this->ui->txtWithList->setText( (*it).getWordEsp().c_str());
            this->ui->txtTimeList->setText(QString::number(time*1000));
        }else{//not found
            this->ui->labelMessageList->setText("word Not found");
        }
    }





    this->ui->labelMessageSet->setText("");
    //TRADUCIENDO SET
    if(setWord->empty()){
        this->ui->labelMessageSet->setText("Not Loaded Structure");
    }
    else{
        t0=clock();
        // Code to execute
        auto it = setWord->find(Word(wordIngles));
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        //std::cout << "Execution Time: " << time << std::endl;
        //printf("%.16g milisegundos\n", time * 1000.0);
        if(it != setWord->end()){//found
            this->ui->txtWithSet->setText( (*it).getWordEsp().c_str());
            this->ui->txtTimeSet->setText(QString::number(time*1000));
        }else{//not found
            this->ui->labelMessageSet->setText("word Not found");
        }
    }




    this->ui->labelMessageHash->setText("");
    //TRADUCIENDO HASH
    if(un_m->empty()){
        this->ui->labelMessageHash->setText("Not Loaded Structure");
    }else{
        t0=clock();
        // Code to execute
        auto it = un_m->find(wordIngles);
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        //std::cout << "Execution Time: " << time << std::endl;
        //printf("%.16g milisegundos\n", time * 1000.0);
        if(it != un_m->end()){//found
            this->ui->txtWithHash->setText((*it).second.getWordEsp().c_str());
            this->ui->txtTimeHash->setText(QString::number(time*1000));
        }else{ //not found
            this->ui->labelMessageHash->setText("word not found");
        }
    }
}

