#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

#include "redBlack.h"
int main(){

    RedBlack<int> rb;
    int v;
    srand(time(NULL));
    int al;
    for(int e =  1; e < 5; e++){
        al =  rand()% 100;
        // cout << e << endl;
        // cin >> v;
         rb.Add(al);
         std::cout << al << endl;
    }
    rb.printSVG();




    return 0;
}
