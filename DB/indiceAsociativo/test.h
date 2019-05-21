#ifndef TEST_H
#define TEST_H

#include <string>

class Test{
public:
    int a;
    int b;
    //string d;
    const char * str;
public:
    Test(int a_ = 0, int b_ = 0):a(a_), b(b_){}
    void setB(int b_){b=b_;}
    void setCadena(const  char * st){str = st;}
    void datosConstantes(){
        std::cout << a << "   " << b << " " <<  str
        <<std::endl;
        //<< d << std::endl;
    }
};


#endif // TEST_H
