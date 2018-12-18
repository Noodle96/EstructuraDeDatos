#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include "bst.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    bst<std::string> e;
    /*
    e.addIDP("monos");
    e.addIDP("africa");
    e.addIDP(15);
    e.addIDP(3);
    e.addIDP(8);
    e.addIDP(12);
    e.addIDP(20);
    e.addIDP(4);
    e.addIDP(11);
    e.addIDP(21);
    e.addIDP(5);
    e.addIDP(22);
    e.addIDP(23);
    e.addIDP(10);
    */
    std::string p1 = "modnos";
    std::string p2 = "monos";
    if(p1 == p2){std::cout <<"son iguales";}
    else{std::cout << "no son iguales";}



    std::cout << " CONVERSION A MINUSCULAS" << std::endl;
    char carac = 'a';

    std::cout << tolower(carac) << std::endl;


    return a.exec();
}


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<iostream>


void toLowerStr(std::string &p) {
    auto it = p.begin();
    for(  ;it != p.end() ; it++){
        (*it) = tolower(*it);
    }
}


#endif // FUNCTIONS_H
