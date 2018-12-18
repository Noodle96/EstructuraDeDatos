#ifndef WORD_H
#define WORD_H
#include <iostream>
#include<cstring>
class Word{
private:
    char ingles[20];
    char espaniol[50];
public:
    Word(const char *ing = "\0", const char *esp = "\0"){
        strcpy(ingles,ing);
        strcpy(espaniol,esp);
    }
    ~Word(){}

    //set and gets
    void setIngles(const char *ing){strcpy(ingles,ing);}
    void setEspaniol(const char *esp){strcpy(espaniol,esp);}

    const char *getIngles()const{return ingles;}
    const char  *getEspaniol()const{return espaniol;}

    void reset(){
        strcpy(ingles,"\0");
        strcpy(espaniol,"\0");
    }

    friend bool operator >(Word &p1,Word &p2){
         return p1.getIngles()>p2.getIngles();
    }

    friend bool operator <(Word &p1,Word &p2){
       return p1.getIngles()<p2.getIngles();
    }
    friend bool operator !=(Word &p1,Word &p2){
       return strcmp( p1.getIngles(),p2.getIngles() ) != 0;
    }

    friend bool operator==(Word &p1, Word &p2){
       // std::cout << "entro a Persona &pm" << '\n';
       return strcmp( p1.getIngles(),p2.getIngles() ) == 0;
    }
    friend std::ostream& operator << (std::ostream &out, Word &p){
            out << "\tIngles: " << p.getIngles()
                << "\n\tEspaniol: " << p.getEspaniol()
                << "\n";
            return out;
    }


};



#endif // WORD_H
