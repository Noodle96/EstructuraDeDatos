#include "dialog.h"
#include "ui_dialog.h"
#include<string>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::limpiar(){
    this->ui->txtWordEnglish->setText("");
    this->ui->txtWordSpanish->setText("");
}
void Dialog::mostrar(Word p){
   //QString ingles = QString::fromUtf8(p.getEspaniol());
   this->ui->txtWordEnglish->setText(QString::fromUtf8(p.getIngles()));
   this->ui->txtWordSpanish->setText(QString::fromUtf8(p.getEspaniol()));
}


void Dialog::on_btnLoad_clicked()
{
    fstream ver;
    ver.open("/home/Nano/QT/Tree/palabras2.txt",ios:: in);
    char ing[20];
    char esp[100];
    int a = 0;
    Word w;
    while(!ver.eof()){
        ver.getline(ing,20, '#');
        ver.getline(esp,100,'@');
        cout << "Ingles: " <<  ing << " Esp: " << esp << endl;
        w.setIngles(ing);
        w.setEspaniol(esp);
        diccionaty.AddI(w);
        w.reset();
        a++;
    }
    iterator_dictionary = diccionaty.CreateIterator() ;

    /*
    for(int e =  0 ; e < 100; e++){
        diccionaty.AddI(e);
    }*/
}

void Dialog::on_btnPrint_clicked()
{
    diccionaty.printInfijo(diccionaty.getHead());
}

void Dialog::on_btnBegin_clicked()
{
    iterator_dictionary->First();
    mostrar(iterator_dictionary->CurrentItem());
     //std::cout << iterator_dictionary->CurrentItem() << "\n";

}

void Dialog::on_btnLast_clicked()
{
    iterator_dictionary->Last();
    mostrar(iterator_dictionary->CurrentItem());
    //std::cout << iterator_dictionary->CurrentItem() << "\n";

}

void Dialog::on_btnPrev_clicked()
{
    iterator_dictionary->Prev();
     mostrar(iterator_dictionary->CurrentItem());

}

void Dialog::on_btnNext_clicked()
{
    iterator_dictionary->Next();
     mostrar(iterator_dictionary->CurrentItem());
}





void Dialog::on_btnLoadEnteros_clicked()
{
    fstream ver;
    ver.open("/home/Nano/QT/Tree/numeros.txt",ios:: in);
    int ent;
    cout    << "Salida de enteros" << endl;
    ver >> ent;
    cout << ent << " ";
    while(!ver.eof()){
        enteros.AddI(ent);
        cout << ent << " ";
        ver >> ent;
    }
    iterator_enteros = enteros.CreateIterator();
}

void Dialog::on_btnFind_clicked()
{
    QString qtStrData = this->ui->txtWordEnglish->text();
    QByteArray inBytes;
    const char *name;
    //inBytes = qtStrData.toUtf8();
    //name = inBytes.constData();
    cout << "TEST: " << endl;
    char *pila= "monos azzules";
    name = qtStrData.toStdString().c_str();
    int cont = 0;
    while(*name != '\0'){
        cout << *pila << endl;
        pila++;
        cont++;
    }
    cout << cont << endl;



    Word w;
    w.setIngles(name);
    NodoBST<Word> **q;
    if( !diccionaty.findDP(w,q)){
        QMessageBox::information(this,"not found", "No se pudo encontrar esa palabra");
    }
    else{
        this->ui->txtWordSpanish->setText( QString::fromUtf8((*q)->m_Dato.getEspaniol()) );
    }


     //p.setNombre(this->ui->txtNombre->text().toStdString());
}
