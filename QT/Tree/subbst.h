#ifndef SUBBST_H
#define SUBBST_H
#include<iostream>
#include<vector>
using namespace std;
#include "nodobst.h"
#include "iterator.h"

template <class T>
class SubBst : public Iterator<T> {
private:
     vector<T> *m_pList;
     unsigned int index;
public:
     SubBst(vector<T> *p): m_pList(p){}
    virtual ~SubBst(){}

     virtual void First(){
        index = 0;
     }

     virtual void Next(){
         if(index < (m_pList->size() -2) ) index++;
     }
     virtual void Prev(){
         if(index > 0) index--;
     }
     virtual void Last(){
         index = m_pList->size();
         index--;
         index--;
     }

     virtual bool IsDone() const{
         return (m_pList->size() <= index);
     }

     virtual T CurrentItem(){
         if(IsDone())
         {
             //throw IteratorOutOfBounds;
         }

         return m_pList->at(index);
      }


};

#endif // SUBBST_H
