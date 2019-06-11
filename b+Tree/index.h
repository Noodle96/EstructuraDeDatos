#ifndef INDEX_H
#define INDEX_H

#include<cstring>

class Index{
protected:
    int  m_index;
    int m_position;
    bool deleted;
public:
    Index(){
        deleted = false;
    }
    ~Index(){}
    int getIndex(){return m_index;}
    int getPosition()const{return m_position;}
    bool isDeleted(){return deleted;}
    void setIndex(int ind ){m_index = ind;}
    void setPos(int pos){m_position = pos;}
    void setDeleted(bool del){deleted = del;}

    void datosConstantes(){
        std::cout << m_index << " " << m_position << " " << deleted << std::endl;
    }
};

#endif // INDEX_H
