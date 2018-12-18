#include<iostream>
#include "matrizEsparsa.h"
using namespace std;
#define C 10
//typedef map< int, map<int, float> > TMatriz;

int main(){
    Matrix<int> m(C,C);
    for(int e = 0 ; e < C ; e++){
        m.Add(e,e,5);
    }
    fstream file;
    file.open("file.txt",ios::out);
    m.Print(file);
    file.close();

   	return 0;
}
