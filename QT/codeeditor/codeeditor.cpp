/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include<QPushButton>

#include "codeeditor.h"

//![constructor]

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{

    lineNumberArea = new LineNumberArea(this);
    m_btn = new QPushButton(this);
    m_btn->setText("Run");
    m_btn->setGeometry(1300,10,51,23);
    loadFileOPeradoresSeparadores();
    loadFilePalabrasReservadas();

    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    connect(m_btn,SIGNAL(clicked() ),this,SLOT(test()));
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}

//![constructor]

//![extraAreaWidth]

int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}

//![extraAreaWidth]

//![slotUpdateExtraAreaWidth]

void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

//![slotUpdateExtraAreaWidth]

//![slotUpdateRequest]

void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());

    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}

//![slotUpdateRequest]

//![resizeEvent]

void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

//![resizeEvent]

//![cursorPositionChanged]

void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;

    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;

        QColor lineColor = QColor(Qt::yellow).lighter(160);

        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }

    setExtraSelections(extraSelections);
}

//![cursorPositionChanged]

//![extraAreaPaintEvent_0]

void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);

//![extraAreaPaintEvent_0]

//![extraAreaPaintEvent_1]
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
//![extraAreaPaintEvent_1]

//![extraAreaPaintEvent_2]
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }

        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
//![extraAreaPaintEvent_2]

void CodeEditor::test(){ //btnrun=test()
    //QString texto =  this->toPlainText();
    //qDebug() << texto << endl;
    Variables.clear();
   //limpiar las pilas
    while(!swParen.empty()){
        swParen.pop();
    }
    while(!swLlaves.empty()){
        swLlaves.pop();
    }
    saveTextEditIntxt();
    //recorriendo las lineas y asignandoles su respectivo container
    int numLinea = 1;
    std::fstream salida;
    std::string temp;
    salida.open("/home/Nano/QT/codeeditor/testToStudy.txt",std::ios::in);
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
    std::cout << "TAMAÑO DE LAS VARIABLES"  << Variables.size() << std::endl;
    ConstruirNFA();
    nfaT.printNFA();




    //VALIDANDO QUE LOS PARENTESIS SE HALLAN APERTURADO Y CERRADO BIEN
    if(!swParen.empty()){
        Word d;
        d = swParen.top();
        QString error = "error de apertura o cerradura en la linea: " + QString::number(d.getLinea());
        QMessageBox::information(this,"aviso",error);
        return;
    }

    if(!swLlaves.empty()){
        Word d;
        d = swLlaves.top();
        QString error = "error de apertura o cerradura en la linea: " + QString::number(d.getLinea());
        QMessageBox::information(this,"aviso",error);
        return;
    }





    //ahora analizando la lista de variables segun el automata ya diseñado
    for(auto it = Variables.begin()  ; it != Variables.end()  ; it++){
        if( !nfaT.verify( (*it).getWord() ) ){
           std::cout << "error en la VARIABLE " <<  (*it).getWord() << " en la linea numero: " << (*it).getLinea() << std::endl;
           QString errorword = (*it).getWord().c_str();
           QString errorLinea = QString::number((*it).getLinea())  ;
           QString error = "Error en la variable: " + errorword + " en la linea: " + errorLinea;
           QMessageBox::information(this,"Aviso",error);
           return;
        }
    }
    //si llega hasta aca es porque no hay ningun problemas con las variables
    QMessageBox::information(this,"Aviso","Perfecto!!");
    return;
}












                                        //funciones propias
//LEIENDO LOS OPERADORES Y SEPARADORES DEL ARCHIVO AL HASH
void CodeEditor::loadFileOPeradoresSeparadores()
{
    std::fstream fileos;
    fileos.open("/home/Nano/QT/codeeditor/operadoresSeparadores.txt", std::ios::in);
    std::string w;
    while( getline(fileos, w) ){
        //std::cout << w << std:: endl;
        pSeparadoresOperadores.insert(std::make_pair(w,w));
    }
    fileos.close();
}

//LEIENDO LAS PALABRAS RESERVADAS DEL ARCHIVO AL HASH
void CodeEditor::loadFilePalabrasReservadas()
{
    std::fstream filePReser;
    filePReser.open("/home/Nano/QT/codeeditor/palabrasReservadas.txt", std::ios::in);
    std::string w;
    while( getline(filePReser, w) ){
        //std::cout << w << std:: endl;
        pReservadas.insert(std::make_pair(w,w));
    }
    filePReser.close();
}

//COPIANDO DEL TEXTEDIT AL ARCHIVO TEXTLANAGUAGE PARA APLICARLO EL TOKENIZADOR
void CodeEditor::saveTextEditIntxt(){
    QString path = "/home/Nano/QT/codeeditor/testToStudy.txt";
    QFile sfile(path);
    if(sfile.open(QFile::WriteOnly  | QFile::Text)){
        QTextStream out(&sfile);
        out << this->toPlainText();
        sfile.flush();
        sfile.close();
    }
}


// ////////////////////////////////////////////////////// BEGIN FUNCTIONS//////////////////////////////////////////////////////////////
//formatea la palabra sin los tabs
std::string CodeEditor::formatearSinEspacios(std::string w){
    std::string res="";
    for(auto it = w.begin() ;it != w.end() ; it++){
        if( (*it) != '\t' ){
            res += (*it);
        }
    }
    return res;
}

//AGREGA EN SU RESPECTIVO CONTAINER
void CodeEditor::agregarInContainer(std::string  word, int linea){
    if( isNUmber(word) ) return;
    if( findInPReservadas(word,linea) ) return;
    if( findInOperadores(word,linea)) return;
    AddInVariables(word,linea);return;
}



//VISITAR LA LINEA
void CodeEditor::visitarLLinea(std::string llinea, int numLinea){
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








//  /////////////////////////////////////////////////////////FIND//////////////////////////////////////////////////////////////


// BUSCA LA PALABRA PASADA POR PARAMETRO EN EL CONTAINER ADECUADO
bool CodeEditor::findInPReservadas(std::string w, int numLinea){
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
bool CodeEditor::findInOperadores(std::string w, int numLinea){
    if(w.empty())return false;
     w = formatearSinEspacios(w);
     auto it = pSeparadoresOperadores.find(w);
     if( it != pSeparadoresOperadores.end() ){ //found
         F.push_back( Word(w,"pSeparadorOperador",numLinea) );
         //AGREGANDO Y QUITANDO EN LA PILA RESPECTIVA
         if((*it).first == "{"){
             swLlaves.push( Word(w,"pSeparadorOperador",numLinea)  );
         }else if( (*it).first == "}"){
             swLlaves.pop();
         }else if(  (*it).first == "(" ) {
             swParen.push( Word(w,"pSeparadorOperador",numLinea) );
         }else if( (*it).first == ")" ){
             swParen.pop();
         }
         return true;
     }
     return false;
}

//verifica si la cadena es un  numero
bool CodeEditor::isNUmber(std::string w){
    for(auto it = w.begin() ; it != w.end() ; it++){
        if( !isdigit( (*it) ) ){
            return false;
        }
    }
    return true;
}



//SE LE ASIGNA COMO VARIABLE
void CodeEditor::AddInVariables(std::string w, int numLinea){
    if(w.empty())return;
    w = formatearSinEspacios(w);
    F.push_back( Word(w,"Variables", numLinea) );
    Variables.push_back(Word(w,"Variables", numLinea));

}



void CodeEditor::ConstruirNFA(){
    char minusculas[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char mayusculas[]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char numeros[]= {'0','1','2','3','4','5','6','7','8','9'};
    std::list<char> min(minusculas,minusculas+sizeof(minusculas)/sizeof(char));
    std::list<char> may(mayusculas,mayusculas+sizeof(mayusculas)/sizeof(char));
    std::list<char> num(numeros,numeros+sizeof(numeros)/sizeof(char));
    //llenando los estados
    nfaT.addState("s1");nfaT.addState("s2");
    //seteando el estado inicial
    nfaT.setInitialState("s1");
    //llenando el estado final
    nfaT.addFinalState("s2");
    //llenando el alfabeto
    for(auto it = min.begin() ; it != min.end() ; it++){
        nfaT.addAlphabet((*it));
    }
    for(auto it = may.begin() ; it != may.end() ; it++){
        nfaT.addAlphabet((*it));
    }
    for(auto it = num.begin() ; it != num.end() ; it++){
        nfaT.addAlphabet((*it));
    }
    //llenando la matriz de transicion
    std::string ei = nfaT.getInitialState();
    auto et = nfaT.FinalStates.begin(); //solo en este caso no hacemos un for , porque sabemos que la maquina solo tiene un estado de aceptacion
    std::string ea = (*et).first;
    for(auto it = min.begin() ; it != min.end(); it++){
        nfaT.FillMatrix(ei,(*it),ea);
    }


    for(auto it = min.begin() ; it != min.end(); it++){
        nfaT.FillMatrix(ea,(*it),ea);
    }
    for(auto it = may.begin() ; it != may.end(); it++){
        nfaT.FillMatrix(ea,(*it),ea);
    }
    for(auto it = num.begin() ; it != num.end(); it++){
        nfaT.FillMatrix(ea,(*it),ea);
    }
}

// //////////////////////////////////////////////////////////EDN FIND////////////////////////////////////////////////////////////
