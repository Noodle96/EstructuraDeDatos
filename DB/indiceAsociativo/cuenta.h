#ifndef CUENTA_H
#define CUENTA_H

class Cuenta{
private:
    char NumCuenta[10];
    char ciudad[15];
    float saldo;
public:
    Cuenta(const char * numcuenta = "", const char * ciudad_ = "",float saldo=0.0):
        saldo(saldo){
            strcpy(NumCuenta,numcuenta);
            strcpy(ciudad,ciudad_);
        }
    ~Cuenta(){}
    void printCuenta(){
        std::cout << NumCuenta << " " << ciudad << " " << saldo << std::endl;
    }
    const char * getNumCuenta(){return NumCuenta;}
    const char * getCiudad(){return ciudad;}
    float getSaldo()const{return saldo;}
};

#endif //CUENTA_H
