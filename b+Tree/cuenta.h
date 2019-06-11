#ifndef CUENTA_H
#define CUENTA_H

class Cuenta{
private:
    // char NumCuenta[10];
    int NumCuenta;
    char ciudad[15];
    int saldo;
public:
    Cuenta(int numcuenta = 0, const char * ciudad_ = "",int saldo=0.0):
        saldo(saldo){
            //strcpy(NumCuenta,numcuenta);
            NumCuenta = numcuenta;
            strcpy(ciudad,ciudad_);
        }
    ~Cuenta(){}
    void printCuenta(){
        std::cout << NumCuenta << " " << ciudad << " " << saldo << std::endl;
    }
    int getNumCuenta(){return NumCuenta;}
    const char * getCiudad(){return ciudad;}
    int getSaldo()const{return saldo;}

    void setNumCuenta(int nm){NumCuenta = nm;}
    void setCiudad(std::string ciu){strcpy(ciudad,ciu.c_str());}
    void setSaldo(int s){saldo = s;}
};

#endif //CUENTA_H
