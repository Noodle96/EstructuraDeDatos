#ifndef WORD_H
#define WORD_H
#include <iostream>
#include<vector>
#include <string>

class Word{
private:
    std::string m_word;
    int m_frecuency;
    std::vector<std::streampos> m_pPosiciones;
public:
    Word(){}
    Word(std::string w):m_word(w){}
    void increaseFrecuency();
    void setWord(std::string we){m_word = we;}
    void setFrecuency(int f){m_frecuency = f;}
    void pushear_posicion(std::streampos pos){m_pPosiciones.push_back(pos);}
    void resetVec(){m_pPosiciones.clear();}
    std::string getPosicionesSring();


    std::string getWord(){return m_word;}
    int getFrecuency()const{return m_frecuency;}

    friend std::ostream& operator << (std::ostream &out, Word &p){

        out  << "\n\nPalabra: "<<  p.getWord()
             << "\nfrecuency: " << p.m_frecuency
             << "\nPosiciones: ";
        for(auto it = p.m_pPosiciones.begin() ; it != p.m_pPosiciones.end(); it++){
            out << (*it) << " ";
        }
        out << std::endl;
        return out;
    }

    friend bool operator >(Word &p1,Word &p2){
        return p1.getWord()>p2.getWord();
    }
    friend bool operator <(Word &p1,Word &p2){
        return p1.getWord()<p2.getWord();
    }
    friend bool operator !=(Word &p1,Word &p2){
        return p1.getWord()!=p2.getWord();
    }

    friend bool operator==(Word &p1, Word &p2){
        return p1.getWord()==p2.getWord();
    }



};

#endif // WORD_H


