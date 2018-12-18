#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include <string>
using namespace std;

class Persona{
private:
    int codigo;
    std::string nombre;
public:
    Persona():codigo(0), nombre(""){}
    Persona(int codigo, std::string nombre): codigo(codigo), nombre(nombre){}
    ~Persona(){}

    void setCodigo(int cod){codigo = cod;}
    void setNombre(std::string name){nombre = name;}
    int getCodigo(){return codigo;}
    std::string getNombre(){return nombre;}
    friend std::ostream& operator << (std::ostream &out, Persona &p){
           out << "\n\n\t\t\tDoc: " << p.getCodigo()
               << "\n\t\t\tNombre: " << p.getNombre()
               << "\n";
           return out;
       }
};

#endif // PERSONA_H
