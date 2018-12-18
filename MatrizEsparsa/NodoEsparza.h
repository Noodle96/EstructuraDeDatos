#ifndef NODOESPARSA_H
#define NODOESPARSA_H

template<class T>
class NodoEs{
public:
	T           m_Dato;
	NodoEs<T> * m_pSigFil;
    NodoEs<T> * m_pSigCol;
    int         m_Fil;
    int         m_Col;
public:
	NodoEs(int x, int y, T D){
		m_Dato = D;
		m_Fil = x;
		m_Col = y;
	    m_pSigFil = m_pSigCol =0;
	}
};
#endif // NODOESPARSA_H
