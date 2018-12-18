#ifndef PERSONA_H
#define PERSONA_H

class Persona{
private:
    int numeroDocumento;
    char nombre[10];
    char apellido[10];
    char fechaNacimiento[10];
public:
    //en los miembros string no pasar como variable en el constructor el mismo nombre.
    Persona(int num = 0, const char*name="\0", const char *apell="\0",const char *fecha="\0"){
        numeroDocumento=num;
        strcpy(nombre,name);
        strcpy(apellido,apell);
        strcpy(fechaNacimiento,fecha);
    }
    // Persona(const Persona &p){
    //     numeroDocumento = p.numeroDocumento;
    //     strcpy(nombre,p.nombre);
    //     strcpy(apellido,p.apellido);
    //     strcpy(fechaNacimiento,p.fechaNacimiento);
    // }
    ~Persona(){}

    void reset(){
        numeroDocumento=0;
        strcpy(nombre,"\0");
        strcpy(apellido,"\0");
        strcpy(fechaNacimiento,"\0");
    }
    void pedir(){
        std::cout << "\n\t\t\tINSERTE DATOS DEL NUEVO PERSONAL\n\n";
        std::cout << "\t\t\tnumero:  "; cin >> numeroDocumento;
        std::cout << "\t\t\tNombre:  "; cin >> nombre;
        std::cout << "\t\t\tApellido:  "; cin >> apellido;
        std::cout << "\t\t\tfecha:  "; cin >> fechaNacimiento;

    }

    /* SETS AND GETS */
    void setNumeroDocumento(int doc){numeroDocumento = doc;}
    void setNombre(const char *name){strcpy(nombre,name);}
    void setApellido(const char *apell){strcpy(apellido,apell);}
    void setFechaNacimiento(const char *fecha){strcpy(fechaNacimiento,fecha);}
    //
    int getNumeroDocumento(){return numeroDocumento;}
    const char *getNombre()const{return nombre;}
    const char *getApellido()const{return apellido;}
    const char *getFechaNacimiento()const{return fechaNacimiento;}


    friend bool operator >(Persona &p1,Persona &p2){
        return p1.getNumeroDocumento()>p2.getNumeroDocumento();
    }
    friend bool operator <(Persona &p1,Persona &p2){
        return p1.getNumeroDocumento()<p2.getNumeroDocumento();
    }
    friend bool operator !=(Persona &p1,Persona &p2){
        return p1.getNumeroDocumento()!=p2.getNumeroDocumento();
    }

    friend bool operator==(Persona &p1, Persona &p2){
        // std::cout << "entro a Persona &pm" << '\n';
        return p1.getNumeroDocumento()==p2.getNumeroDocumento();
    }

    // void operator=(Persona &p2){
    //     strcpy(nombre,p2.nombre);
    //     strcpy(apellido, p2.apellido);
    //     strcpy(fechaNacimiento , p2.fechaNacimiento);
    // }


    //
    // bool operator ==(Persona *&p2){
    //         // return this->numeroDocumento==p2->numeroDocumento;
    //     std::cout << "En == *" << '\n';
    //     Persona temp = *(this);
    //     Persona temp2 = *(p2);
    //     return (temp.numeroDocumento==temp2.numeroDocumento);
    //
    // }




    /*Sobrecarga de operadores*/
    // friend std::ostream& operator << (std::ostream &out, Persona *&p){
    //     out << "Doc: " << p->getNumeroDocumento()
    //         << "\nNombre: " << p->getNombre()
    //         << "\nApellido: " << p->getApellido()
    //         << "\nFechaNac: " << p->getFechaNacimiento()
    //         // << "entro a con *"
    //         << "\n";
    //     return out;
    // }
    friend std::ostream& operator << (std::ostream &out, Persona &p){
        out << "\n\n\t\t\tDoc: " << p.getNumeroDocumento()
            << "\n\t\t\tNombre: " << p.getNombre()
            << "\n\t\t\tApellido: " << p.getApellido()
            << "\n\t\t\tFechaNac: " << p.getFechaNacimiento()
            << "\n";
        return out;
    }
    void showData(){
        //cout << "Doc: " << numeroDocumento << "\nNombre: " << nombre << "\nApellido: " << apellido<< "\nFechaNac: " << fechaNacimiento <<"\n";
        cout << (*this) ;
    }
};


#endif // PERSONA_H
