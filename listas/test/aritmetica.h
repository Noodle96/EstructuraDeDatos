#ifndef ARITMETICA_H
#define ARITMETICA_H

class Aritmetica{
private:
    int x;
    int y;
    float z;
    float w;
public:
    Aritmetica(int x=0, int y =0, float z=0.0, float w=0.0):x(x), y(y),z(z),w(w){}
    void pedir(){
        std::cout << "x: "; cin >> x;
        std::cout << "y:"; cin >> y;
        std::cout << "z:"; cin>> z;
        std::cout << "w: " ; cin >> w;

    }
    void showData(){
        std::cout << "x: " << x << " y: " << y << " z: " << z << " w: " << w << std::endl;
    }
};


#endif // ARITMETICA_H
