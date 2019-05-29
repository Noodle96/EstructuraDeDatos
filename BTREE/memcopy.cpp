#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    // int myvector[]={23,24,25,26,31,32,33,43,45,56,57,67,78,90};
    // std::vector<int> v1(myvector, myvector + sizeof(myvector)/sizeof(int));
    // for(auto it = v1.begin() ; it !=v1.end() ; it++){
    //     std::cout << (*it) << std::endl;
    // }
    // std::vector<int> v2(v1.begin(),v1.end());
    // std::cout << "\n";
    //
    // for(auto it = v2.begin() ; it !=v2.end() ; it++){
    //     std::cout << (*it) << std::endl;
    // }
    // std::cout << sizeof(int) << std::endl;
    // std::cout << sizeof(v2) << std::endl;

    // int v1[] = {0,1,2,3,4};
    // int v2[] = {400,300,2,1,0};
    // memcpy(v1, v2, 2*sizeof(int)); // copia los dos primeros elementos de v2 en v1
    // for(int e = 0 ; e < 5; e++){
    //     std::cout << v1[e] << std::endl;
    // }
    // std::cout << "\n";
    // for(int e = 0 ; e < 5; e++){
    //     std::cout << v2[e] << std::endl;
    // }

    std::vector<int> v3;
    v3.reserve(3);
    v3.push_back(10);
    v3.push_back(1450); //ignora este push
    for(auto e = 0 ; e < 3; e++){
        std::cout << v3[e] << std::endl;
    }
    std::cout << v3.size() << std::endl;

    return 0;
}
