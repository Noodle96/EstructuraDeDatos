#ifndef WORD_H
#define WORD_H

#include<iostream>
class Word{
private:
    std::string WordIng;
    std::string WordEsp;
public:
    Word(std::string WordIng="",std::string WordEsp=""){
        this->WordIng = WordIng;
        this->WordEsp = WordEsp;
    }

    ~Word(){}
    std::string getWordIng()const{return WordIng;}
    std::string getWordEsp()const{return WordEsp;}
    void setWordIng(std::string wi){WordIng = wi;}
    void setWordEsp(std::string we){WordEsp = we;}
    void concatenarWord(std::string espa){WordEsp += " , ";
                                          WordEsp += espa;}


    friend bool operator >(const Word &p1,const Word &p2){
        return p1.WordIng>p2.WordIng;
    }

    friend bool operator < ( const Word &p1,const Word &p2){
       return p1.WordIng<p2.WordIng;
    }
    friend bool operator !=(const Word &p1,const Word &p2){
       return p1.WordIng!=p2.WordIng;
    }

    friend bool operator==(const Word &p1, const Word &p2){
       // std::cout << "entro a Persona &pm" << '\n';
       return p1.WordIng==p2.WordIng;
    }
    friend std::ostream& operator << (std::ostream &out,const  Word &p){
            out <<  p.WordIng
                << "#" << p.WordEsp
                << "\n";
            return out;
    }
};

#endif // WORD_H
