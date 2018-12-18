#ifndef STDVECTORLIST_H
#define STDVECTORLIST_H
#include<iostream>
#include<vector>
using namespace std;

#include "iterator.h"

template<typename T>
class StdVectorListIterator;


template <class T>
class StdVectorList{
private:
    std::vector<T> m_vector;

public:
    StdVectorList(){}
    virtual ~StdVectorList(){}
    Iterator<T> *CreateIterator() const {
        return new StdVectorListIterator<T>(this);
    }

    unsigned int Count() const {
       return m_vector.size();
    }

    void Append(T item) {
       m_vector.push_back(item);
    }

    const T& Get(unsigned int index) const{
       return m_vector.at(index);
    }
};





template <class T>
class StdVectorListIterator : public Iterator<T> {
private:
    const StdVectorList<T> * m_pList;
    unsigned int m_index;

public:
    StdVectorListIterator(const StdVectorList<T> * list): m_pList(list),m_index(0){}
    virtual ~StdVectorListIterator(){}

    virtual void First(){
        m_index = 0;
    }

    virtual void Next(){
        m_index++;
    }

    virtual bool IsDone() const{
        return (m_pList->Count() <= m_index);
    }

    virtual T CurrentItem() const{
        if(IsDone())
        {
            return T();
        }
        return m_pList->Get(m_index);
    }
};







#endif // STDVECTORLIST_H
