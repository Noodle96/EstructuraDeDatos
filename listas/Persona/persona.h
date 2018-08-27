#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
using namespace std;
class Persona{
private:
    int numeroDocumento;
    std::string nombre;
    std::string apellido;
    std::string fechaNacimiento;
public:
    //en los miembros string no pasar como variable en el constructor el mismo nombre.
    Persona(int doc = 0, std::string name = "", std::string apell="", std::string nac="00/00/00"){
        numeroDocumento = doc;
        nombre = name;
        apellido = apell;
        fechaNacimiento = nac;
    }
    ~Persona(){}

    /* SETS AND GETS */
    void setNumeroDocumento(int doc){numeroDocumento = doc;}
    void setNombre(std::string name){nombre = name;}
    void setApellido(std::string apell){apellido = apell;}
    void setFechaNacimiento(std::string fecha){fechaNacimiento = fecha;}

    int getNumeroDocumento(){return numeroDocumento;}
    std::string getNombre()const{return nombre;}
    std::string getApellido()const{return apellido;}
    std::string getFechaNacimiento()const{return fechaNacimiento;}


    bool operator >(Persona *);
    // bool operator <(Persona *&p1){
    //     return (numeroDocumento < p1->numeroDocumento);
    // }
    bool operator ==(Persona *);
    // bool operator !=(Persona *p1){
    //     return numeroDocumento!=p1->getNumeroDocumento();
    // }

    // friend bool operator== (const Persona &p1, const Persona &p2){
    //     return p1.numeroDocumento == p2.numeroDocumento;
    // }



    /*Sobrecarga de operadores*/
    friend std::ostream& operator << (std::ostream &out, Persona *&p){
        out << "Doc: " << p->getNumeroDocumento()
            << "\nNombre: " << p->getNombre()
            << "\nApellido: " << p->getApellido()
            << "\nFechaNac: " << p->getFechaNacimiento()
            << "\n";
        return out;
    }
//     friend bool operator==(Persona *&p1, Persona *&p2){
//         return p1->getNumeroDocumento()==p2->getNumeroDocumento();
//     }
};




#endif // PERSONA_H
