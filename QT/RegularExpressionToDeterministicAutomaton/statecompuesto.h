#ifndef STATECOMPUESTO_H
#define STATECOMPUESTO_H

#include"state2.h"
#include<set>

template<typename TS, typename TA>
class StateCompuesto{
public:
    std::set<TS> m_Lo;
    std::set<TS> m_Le;
public:
    TS state;
    StateCompuesto(std::set<TS>&lo,std::set<TS>&le){
        this->m_Lo = lo;
        this->m_Le = le;
    }
    StateCompuesto(){}

    //GETS
    std::set<TS> &getMadre(){return m_Lo;}
    TS getState()const{return state;}


    void setStateData(TS ts){state=ts;}
    friend bool operator ==(const StateCompuesto<TS,TA> &p1, const StateCompuesto<TS,TA> &p2 ){
            return ((p1.m_Lo == p2.m_Lo) && (p1.m_Le == p2.m_Le));
    }

    friend bool operator !=(const StateCompuesto<TS,TA> &p1, const StateCompuesto<TS,TA> &p2 ){
            return ((p1.m_Lo != p2.m_Lo) && (p1.m_Le != p2.m_Le));
    }

    friend bool operator >(const StateCompuesto<TS,TA> &p1, const StateCompuesto<TS,TA> &p2 ){
            return ((p1.m_Lo > p2.m_Lo) && (p1.m_Le > p2.m_Le));
    }
    friend bool operator <(const StateCompuesto<TS,TA> &p1, const StateCompuesto<TS,TA> &p2 ){
            return ((p1.m_Lo < p2.m_Lo) && (p1.m_Le < p2.m_Le));
    }
};

#endif // STATECOMPUESTO_H
