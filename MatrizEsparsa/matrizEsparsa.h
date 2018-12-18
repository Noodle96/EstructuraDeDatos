#ifndef  MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include<iostream>
#include<fstream>
using namespace std;

#include "NodoEsparza.h"

template<class T>
class Matrix{
private:
      NodoEs<T> ** m_filas;
      NodoEs<T> ** m_columnas;
      int fil;
      int col;
public:
     Matrix(int fil, int col){
         this->fil = fil;
         this->col = col;
     	 m_filas = new NodoEs<T>    *[fil];
         m_columnas = new NodoEs<T> *[col];
     }
     ~Matrix(){}

     bool find_fil(int f, int c, NodoEs<T> ** & p);
     bool find_col(int f, int c, NodoEs<T> ** & p);
     void Add(int f, int c, T D);
     void Print(ostream & os);

};
#include "matrizEsparsa.tpp"


#endif // MATRIZESPARSA_H
